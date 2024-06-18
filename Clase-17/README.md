Ejercicio 25: Login Independiente y Gestión de Usuarios

Objetivo:
Construir un proyecto independiente con un componente de login que no dependa de otras clases GUI.
Implementar un QLabel como botón en el login para registrar un nuevo usuario.
Al presionar el QLabel de registro, abrir una ventana para dar de alta un nuevo usuario utilizando SQLite con AdminDB como singleton.
Mostrar una ventana adicional al ingresar correctamente, donde se visualicen todos los usuarios cargados en la base de datos utilizando QTreeWidget.
Permitir la edición de los usuarios directamente desde la ventana de visualización, similar a una planilla tipo Excel.


Recomendaciones para la Construcción de las Clases:
Independencia del Login:

Asegurarse de que el componente de login sea autónomo y no dependa de otras partes de la interfaz de usuario.
Registro de Nuevo Usuario:

Implementar una funcionalidad clara para registrar nuevos usuarios al presionar el QLabel que actúa como botón.
Utilización de SQLite con AdminDB:

Hacer uso de SQLite para el almacenamiento de usuarios, gestionado a través de la clase AdminDB implementada como singleton para asegurar una única instancia global.
Visualización de Usuarios con QTreeWidget:

Mostrar todos los usuarios cargados en la base de datos utilizando QTreeWidget, permitiendo una visualización organizada y jerárquica.
Edición de Usuarios en QTreeWidget:

Agregar capacidades de edición directa en la ventana de visualización de usuarios, similar a la manipulación de una planilla de Excel.


Notas Finales:
Asegúrate de seguir las mejores prácticas y recomendaciones discutidas durante las clases para construir las clases y componentes de manera eficiente y efectiva.
Organiza el código en carpetas separadas (ejercicio25, por ejemplo) dentro del repositorio de GitHub, incluyendo únicamente los archivos necesarios para compilar y ejecutar el proyecto.
Excluye archivos generados automáticamente por Qt y otros artefactos no esenciales para la ejecución del proyecto.
