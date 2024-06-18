#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <QWidget>
#include <QRegularExpression>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class Parser;
}
QT_END_NAMESPACE

class Parser : public QWidget
{
    Q_OBJECT

public:
    Parser(QWidget *parent = nullptr);
    ~Parser();

    void getRecursos();

private:
    Ui::Parser *uiWidgetParser;
    QNetworkAccessManager* networkManager;

    QString strHtmlStorage;
    QString strFilePath;

    int intCssListPos;
    QStringList* strListCssList;

    int intJsListPos;
    QStringList* strListJsList;

    int intImgListPos;
    QStringList* strListImgList;

    QImage imgWidgetImage;

    int intCssFilesDownloaded;
    int intJsFilesDownloaded;

private slots:
    void slotDescargarHtml();
    void slotDescargarArchivos();
    void slotHtmlDescargado(QNetworkReply* reply);

    void slotDescargarCSS();
    void slotDescargarJS();
    void slotDescargarIMG();

    void slotCssDescargado(QNetworkReply* reply);
    void slotJsDescargado(QNetworkReply* reply);
    void slotImgDescargado(QNetworkReply* reply);

    void slotDialogImgDisco();
    void slotDialogDireccion();
    void slotImagenObtenida(QString);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void signalHtmlDescargado();

    void signalIniciarDescargaCss();
    void signalCssDescargado();

    void signalIniciarDescargaJs();
    void signalJsDescargado();

    void signalIniciarDescargaImg();
    void signalImgDescargado();
};

#endif // HTMLPARSER_H
