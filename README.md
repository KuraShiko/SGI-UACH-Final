# SGI-UACH-Final
Este repositorio contiene el proyecto final para la materia de Administración del Proceso del Software de la Facultad de Ingeniería.

## 📁 Archivos del proyecto

* `SGI'Final.cpp`: Contiene el código fuente del programa escrito en C++. Incluye la lógica principal, el menú interactivo, las validaciones de entrada y el sistema de navegación por páginas.
* `inventario.txt`: Es un archivo de texto que funciona como base de datos inicial para realizar pruebas. Permite que el sistema cargue información desde su primera ejecución sin necesidad de registrar productos manualmente uno por uno, aunque si se compila el codigo principal por su cuenta este mismo creara el archivo con un inventario vacio.

## 🚀 Funcionalidades del sistema

Esta es una aplicación de consola diseñada para administrar y controlar el inventario de un negocio. Cuenta con las siguientes características:

* **Registro de productos:** Permite agregar nuevos artículos. Si el usuario ingresa espacios en el nombre, el sistema los sustituye automáticamente por guiones bajos (`_`) para asegurar la correcta lectura y escritura en el archivo de texto. Además, el sistema valida que no se ingresen productos duplicados.
* **Visualización paginada:** Muestra el inventario completo dividiendo la lista en bloques de 5 productos para mantener la interfaz limpia y facilitar la lectura. Incluye opciones de navegación para avanzar a la siguiente página, regresar a la anterior o volver al menú principal.
* **Modificación de existencias:** Permite actualizar la cantidad de artículos disponibles mediante la búsqueda exacta por ID.
* **Persistencia de datos:** Toda la información y los cambios realizados se guardan automáticamente en el archivo `inventario.txt` antes de cerrar la aplicación, garantizando la integridad de los registros.

## ⚙️ Instrucciones de ejecución

Para probar el sistema, es necesario contar con un compilador de C++ (como MinGW) o un entorno de desarrollo compatible.

1. Descargar los archivos `SGI-Final.cpp` e `inventario.txt` y ubicarlos exactamente en el mismo directorio.
2. Compilar el archivo de código fuente.
3. Ejecutar el programa resultante; el sistema detectará el archivo de texto y cargará el inventario de prueba automáticamente.
