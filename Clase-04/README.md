Ejercicio 8: Función Genérica para Descripción de Objetos
Objetivo: Crear una función genérica que imprima por consola una descripción de cualquier objeto.

Implementación:

Utilizar un proyecto Empty qmake.
La función debe ser capaz de imprimir mensajes como "Persona con nombre Lucrecia" o "Poste con altura de 8 metros y 15 cm de diámetro".
Probar la función en main con objetos de las clases Persona y Poste.
Todo el código se incluirá en el archivo main.cpp.
Ejercicio 9: Función Genérica para Ordenar y Mostrar
Objetivo: Crear una función genérica que imprima por consola los valores de un array ordenados.

Implementación:

Utilizar un proyecto Empty qmake.
Definir la función genérica con el prototipo template <class T> void imprimir(T *v, int cantidad, bool mayor_a_menor).
Utilizar el método de ordenamiento por inserción.
Probar la función en main con arrays de tipo int y float, ordenándolos de mayor a menor y viceversa.
Ejercicio 10: Clase Jugador y Uso de std::vector
Objetivo: Crear la clase Jugador con atributos y métodos básicos, e insertar objetos en un std::vector.

Implementación:

Definir la clase Jugador con atributos int velocidad, int fuerza y std::string nombre.
Incluir constructor, métodos setter y getter, y destructor.
En main, crear un std::vector<Jugador> e insertar 10 jugadores distintos.
Publicar los datos de cada jugador utilizando std::cout.
Ejercicio 11: Creación y Visualización de Objetos Qt
Objetivo: Crear objetos de diferentes clases Qt y mostrarlos en la función main.

Implementación:

Utilizar un proyecto Empty qmake.
Crear objetos de las clases QLabel, QWidget, QPushButton y QLineEdit.
Invocar el método show() para cada objeto y notar que se muestran independientemente.
Ejercicio 12: Carga de Imagen en QLabel y Cierre Automático
Objetivo: Cargar una imagen de alta resolución en un QLabel y manejar su visualización en Qt.

Implementación:

Utilizar un proyecto Empty qmake.
Crear un objeto QLabel y cargar una imagen desde un archivo JPG en el disco duro.
Mostrar el QLabel maximizado sin deformar la imagen.
Cerrar la aplicación automáticamente después de 3 segundos.
Notas Adicionales:
Cada ejercicio tiene su propia carpeta (ejercicio01, ejercicio02, etc.) con todos los archivos necesarios para compilar y ejecutar el programa.
El archivo .pro.user y la carpeta build se excluyen del repositorio para mantener limpio el historial y evitar archivos innecesarios.
Envía la URL del repositorio a cesarosimani@gmail.com después de completar todos los ejercicios.
