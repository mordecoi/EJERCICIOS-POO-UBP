#include "htmlparser.h"
#include "ui_htmlparser.h"
#include <QMessageBox>

Parser::Parser(QWidget *parent)
    : QWidget(parent)
    , uiWidgetParser(new Ui::Parser)
    , intCssFilesDownloaded(0)
    , intJsFilesDownloaded(0)
{
    uiWidgetParser->setupUi(this);

    connect(uiWidgetParser->pbBuscar, SIGNAL(clicked(bool)), this, SLOT(slotDescargarHtml()));
    connect(this, SIGNAL(signalHtmlDescargado()), this, SLOT(slotDescargarArchivos()));
    connect(uiWidgetParser->pbDibujar, SIGNAL(clicked(bool)), this, SLOT(slotDialogImgDisco()));
    connect(uiWidgetParser->pbEstablecer, SIGNAL(clicked(bool)), this, SLOT(slotDialogDireccion()));
}

Parser::~Parser()
{
    delete uiWidgetParser;
}

void Parser::getRecursos() {
    qDebug() << "Consiguiendo Recursos...";
    qDebug() << "HTML es Vacio?" << strHtmlStorage.isEmpty();

    strListCssList = new QStringList();

    QRegularExpression cssRegex("<link\\s+.*?href=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator cssMatches = cssRegex.globalMatch(strHtmlStorage);
    while(cssMatches.hasNext()) {
        qDebug() << "Adentro de CSS";
        QRegularExpressionMatch match = cssMatches.next();
        QString cssURL = match.captured(1);
        strListCssList->push_back(cssURL);
    }

    qDebug() << "CSS obtenido";

    strListJsList = new QStringList();

    QRegularExpression jsRegex("<script\\s+.*?src=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator jsMatches = jsRegex.globalMatch(strHtmlStorage);
    while(jsMatches.hasNext()) {
        qDebug() << "Adentro de JS";
        QRegularExpressionMatch match = jsMatches.next();
        QString jsURL = match.captured(1);
        strListJsList->push_back(jsURL);
    }

    qDebug() << "JS obtenido";

    strListImgList = new QStringList();

    QRegularExpression imgRegex("<img\\s+.*?src=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator imgMatches = imgRegex.globalMatch(strHtmlStorage);
    while(imgMatches.hasNext()) {
        qDebug() << "Adentro de IMG";
        QRegularExpressionMatch match = imgMatches.next();
        QString imgURL = match.captured(1);
        strListImgList->push_back(imgURL);
    }

    qDebug() << "IMG obtenido";
    qDebug() << "Todos los Recursos Conseguidos...";
    QMessageBox::information(this, "Conseguido", "Todos los recursos obtenidos.");
}

void Parser::slotDescargarHtml() {
    if (!(uiWidgetParser->leURL->text().isEmpty()) && !(uiWidgetParser->leGuardado->text().isEmpty())) {
        qDebug() << "Descargando HTML...";

        strFilePath = uiWidgetParser->leGuardado->text();
        strFilePath += "/";
        qDebug() << "Direccion de Guardado:" << strFilePath;

        networkManager = new QNetworkAccessManager(this);
        connect(networkManager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slotHtmlDescargado(QNetworkReply * )));
        QNetworkRequest request(QUrl(uiWidgetParser->leURL->text()));
        networkManager->get(request);
    } else if(uiWidgetParser->leURL->text().isEmpty()){
        qDebug() << "Falta la URL a analizar. Vuelva a Intentar";
        QMessageBox::warning(this, "Error", "Falta la URL. Vuelve a intentar.");
    } else {
        qDebug() << "Falta el Directorio de Guardado. Vuelva a Intentar";
        QMessageBox::warning(this, "Error", "Falta el Directorio de Guardado. Vuelve a intentar.");
    }
}

void Parser::slotDescargarArchivos() {
    getRecursos();

    qDebug() << "A punto de ponerme a descargar todos los Recursos...";
    QMessageBox::information(this, "Iniciando", "Empezando la descarga de Recursos");

    intCssListPos = 0;
    connect(this, SIGNAL(signalIniciarDescargaCss()), this, SLOT(slotDescargarCSS()));
    emit signalIniciarDescargaCss();

    intJsListPos = 0;
    connect(this, SIGNAL(signalIniciarDescargaJs()), this, SLOT(slotDescargarJS()));
    emit signalIniciarDescargaJs();

    intImgListPos = 0;
    connect(this, SIGNAL(signalIniciarDescargaImg()), this, SLOT(slotDescargarIMG()));
    emit signalIniciarDescargaImg();

    qDebug() << "Finalizado!";
    QMessageBox::information(this, "Finalizado", "Descarga de archivos finalizada");
}

void Parser::slotHtmlDescargado(QNetworkReply* reply) {
    qDebug() << "Guardando HTML y Emitiendo SIGNAL...";
    strHtmlStorage = reply->readAll();

    QString fileName = "/txt.html";
    QFile file(strFilePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado el Archivo HTML";
        QMessageBox::information(this, "Archivo HTML creado", "Se ha creado el Archivo " + fileName + ".");
    }
    file.write(strHtmlStorage.toUtf8());

    uiWidgetParser->teHTML->setText(strHtmlStorage);
    emit signalHtmlDescargado();
}

void Parser::slotDescargarCSS() {
    if (strListCssList->isEmpty() || intCssListPos == strListCssList->size()) {
        if (intCssFilesDownloaded == strListCssList->size()) {
            QMessageBox::information(this, "Archivos CSS creados", "Se han creado todos los archivos CSS.");
        }
        return;
    } else {
        networkManager = new QNetworkAccessManager();
        connect(networkManager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slotCssDescargado(QNetworkReply *)));

        qDebug() << "Descargando CSS... Estoy en la Posicion" << intCssListPos << "| Size de Lista es:" << strListCssList->size();
        qDebug() << "URL en la Posicion Actual:" << strListCssList->at(intCssListPos);
        QNetworkRequest request(QUrl(strListCssList->at(intCssListPos)));
        networkManager->get(request);
    }
}

void Parser::slotDescargarJS() {
    if (strListJsList->isEmpty() || intJsListPos == strListJsList->size()) {
        if (intJsFilesDownloaded == strListJsList->size()) {
            QMessageBox::information(this, "Archivos JS creados", "Se han creado todos los archivos JS.");
        }
        return;
    } else {
        networkManager = new QNetworkAccessManager();
        connect(networkManager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slotJsDescargado(QNetworkReply *)));

        qDebug() << "Descargando JS... Estoy en la Posicion" << intJsListPos << "| Size de Lista es:" << strListJsList->size();
        qDebug() << "URL en la Posicion Actual:" << strListJsList->at(intJsListPos);
        QNetworkRequest request(QUrl(strListJsList->at(intJsListPos)));
        networkManager->get(request);
    }
}

void Parser::slotDescargarIMG() {
    if (strListImgList->isEmpty() || intImgListPos == strListImgList->size()) {
        QMessageBox::information(this, "Archivos IMG creados", "Se han creado todos los archivos IMG.");
        return;
    } else {
        networkManager = new QNetworkAccessManager();
        connect(networkManager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slotImgDescargado(QNetworkReply *)));

        qDebug() << "Descargando IMG... Estoy en la Posicion" << intImgListPos << "| Size de Lista es:" << strListImgList->size();
        qDebug() << "URL en la Posicion Actual:" << strListImgList->at(intImgListPos);
        QNetworkRequest request(QUrl(strListImgList->at(intImgListPos)));
        networkManager->get(request);
    }
}

void Parser::slotCssDescargado(QNetworkReply* reply) {
    qDebug() << "Guardando CSS y Emitiendo SIGNAL...";

    QString fileName = "/css" + QString::number(intCssListPos) + ".css";
    QFile file(strFilePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado el Archivo CSS";
        QMessageBox::information(this, "Archivo CSS creado", "Se ha creado el Archivo " + fileName + ".");
    }
    file.write(reply->readAll());

    intCssFilesDownloaded++;

    intCssListPos++;
    emit signalIniciarDescargaCss();
}

void Parser::slotJsDescargado(QNetworkReply* reply) {
    qDebug() << "Guardando JS y Emitiendo SIGNAL...";

    QString fileName = "/js" + QString::number(intJsListPos) + ".js";
    QFile file(strFilePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado el Archivo JS";
        QMessageBox::information(this, "Archivo JS creado", "Se ha creado el Archivo " + fileName + ".");
    }
    file.write(reply->readAll());

    intJsFilesDownloaded++;

    intJsListPos++;
    emit signalIniciarDescargaJs();
}

void Parser::slotImgDescargado(QNetworkReply* reply) {
    qDebug() << "Guardando IMG y Emitiendo SIGNAL...";

    QString fileName = "/img" + QString::number(intImgListPos) + ".jpg";
    QFile file(strFilePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado el Archivo IMG";
        QMessageBox::information(this, "Archivo IMG creado", "Se ha creado el Archivo " + fileName + ".");
    }
    file.write(reply->readAll());

    intImgListPos++;
    emit signalIniciarDescargaImg();
}

void Parser::slotDialogImgDisco() {
    QString imgPath = QFileDialog::getOpenFileName(this, "Buscar Imagen", "", "Imagenes (*.png *.xpm *.jpg)");
    slotImagenObtenida(imgPath);
}

void Parser::slotDialogDireccion() {
    QString direccionPath = QFileDialog::getExistingDirectory(this, "Buscar Directorio");
    uiWidgetParser->leGuardado->setText(direccionPath);
}

void Parser::slotImagenObtenida(QString imgPath) {
    imgWidgetImage.load(imgPath);
    update();
}

void Parser::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect target(720, 50, 320, 240);
    QRect source(0, 0, 320, 240);
    painter.drawImage(target, imgWidgetImage, source);
}
