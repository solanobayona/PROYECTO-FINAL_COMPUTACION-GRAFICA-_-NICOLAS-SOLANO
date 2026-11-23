__Escena 3D Nocturna en OpenGL

Nombre: Cristian Nicolás Solano Bayona
Código: 6000809
Programa: Ingeniería en Multimedia — Universidad Militar Nueva Granada
Entorno y herramientas: Desarrollado en C++ en Visual Studio utilizando OpenGL 3.3 Core Profile, GLFW, GLAD, GLM, nlohmann/json y stb_image, siguiendo la base del tutorial de OpenGL por Victor Gordan (https://youtu.be/45MIykWJ-C4) y los temas trabajados en clase.

__ 1. Descripción del Proyecto
      Aplicación gráfica 3D interactiva desarrollada en C++ y OpenGL 3.3 en Visual Studio. Plantea una escena nocturna con un dragón de minecraft en formato glTF que recorre y se orienta siguiendo una trayectoria circular construida con cuatro curvas cúbicas de Bézier encadenadas sobre un piso con textura de piedra (piedra.jpg) repetida en mosaico.

__ 2. Qué se Ve al Ejecutar el Programa
      Al correr la aplicación se observa una escena de noche con fondo azul oscuro, una luna cuadrada emisiva en el cielo, un piso cuadrado con la textura piedra.jpg repetida en mosaico estilo bloque y el modelo 3D del dragón desplazándose en círculo. Junto al dragón avanza un cubo guía pequeño y morado que marca la trayectoria y proyecta iluminación morada sobre la escena, mientras la cámara permite recorrer y observar el entorno.

__ 3. Luces Utilizadas
      - Luz ambiental y direccional azul (luna): aporta el tono nocturno frío general y una iluminación difusa suave desde la posición de la luna hacia la escena.
      - Luz puntual morada (cubo guía): se ubica en la posición actual de la curva de Bézier junto al dragón, ilumina con atenuación por distancia y genera brillo especular en las superficies cercanas.
      - Modo emisivo (isEmissive): permite que tanto la luna como el cubo guía morado muestren su color luminoso propio sin depender de la iluminación externa.

__ 4. Arquitectura del Software y Clases
      El código está organizado en módulos y clases para separar responsabilidades:

- Main.cpp
      Inicializa GLFW y GLAD, configura el entorno de trabajo en Visual Studio/OpenGL 3.3, define y evalúa las cuatro curvas cúbicas de Bézier (posición y tangente), crea las geometrías del cubo y del suelo repetido, carga piedra.jpg y ejecuta el bucle de renderizado.

- Camera (Camera.h / Camera.cpp)
      Administra la posición y orientación de la cámara, construye las matrices de vista y proyección con GLM (cameraMatrix) y procesa los controles de movimiento, rotación y paneo.

- Shader y shaders GLSL (shaderClass.h / shaderClass.cpp, default.vert, default.frag, light.vert, light.frag)
      La clase Shader lee, compila y enlaza los programas de shaders. default.vert pasa posiciones y normales a espacio de mundo y proyecta a pantalla; default.frag calcula la iluminación nocturna y puntual; light.vert y light.frag quedan como shaders auxiliares de apoyo.

- Model (Model.h / Model.cpp)
      Carga el archivo .gltf y su buffer binario, lee accessors y bufferViews, recorre la jerarquía de nodos acumulando matrices de transformación y carga las texturas del modelo.

- Mesh (Mesh.h / Mesh.cpp)
      Agrupa los vértices, índices y texturas de cada malla, configura sus atributos y envía matrices y uniforms al shader antes de dibujar.

- VAO, VBO y EBO (VAO.h / VAO.cpp, VBO.h / VBO.cpp, EBO.h / EBO.cpp)
      Clases auxiliares que encapsulan la creación, vinculación y liberación del Vertex Array Object, Vertex Buffer Object y Element Buffer Object en OpenGL.

- Texture y stb.cpp (Texture.h / Texture.cpp, stb.cpp)
      La clase Texture carga imágenes con stb_image, configura filtros y repetición en mosaico (GL_REPEAT) y maneja las unidades de textura; stb.cpp centraliza la implementación de stb_image.

__ 5. Controles
      - Teclado: W, A, S, D para desplazarse, Espacio y Control izquierdo para subir o bajar, Shift izquierdo para acelerar el movimiento y ESC para cerrar la ventana.
      - Mouse: clic izquierdo arrastrado para rotar la cámara y clic derecho arrastrado para desplazarla lateral o verticalmente.

__ 6. Decisiones Técnicas y Estado del Proyecto
      - Implementado: matrices de cámara, traslación y rotación de objetos, carga de modelo glTF, iluminación nocturna y puntual, curvas cúbicas de Bézier, repetición de textura en el suelo y controles de teclado/mouse.
      - Modelo glTF adicional: se intentó integrar un segundo modelo glTF, pero presentaba fallos de carga que afectaban la estabilidad y el renderizado del dragón, por lo que se optó por mantener únicamente el modelo del dragón.
      - Interfaz / flujo de trabajo: el desarrollo se mantuvo fiel al tutorial y la base trabajada desde el inicio de clase.
