#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"



// Coordenadas de los vértices
GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Esquina inferior izquierda
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Esquina inferior derecha
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Esquina superior
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Izquierda interior
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Derecha interior
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Abajo interior
};

// Índices para el orden de los vértices
GLuint indices[] =
{
	0, 3, 5, // Triángulo inferior izquierdo
	3, 2, 4, // Triángulo inferior derecho
	5, 4, 1 // Triángulo superior
};



int main()
{
	// Inicializar GLFW
	glfwInit();

	// Decirle a GLFW qué versión de OpenGL estamos usando 
	// En este caso estamos usando OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Decirle a GLFW que estamos usando el perfil CORE
	// Lo que significa que solo tenemos las funciones modernas
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Crear un objeto GLFWwindow de 800 por 800 píxeles, nombrándolo "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	// Comprobación de errores si la ventana falla al crearse
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introducir la ventana en el contexto actual
	glfwMakeContextCurrent(window);

	// Cargar GLAD para que configure OpenGL
	gladLoadGL();
	// Especificar el área de visualización (viewport) de OpenGL en la ventana
	// En este caso, el viewport va desde x = 0, y = 0, hasta x = 800, y = 800
	glViewport(0, 0, 800, 800);



	// Genera el objeto Shader usando los shaders default.vert y default.frag
	Shader shaderProgram("default.vert", "default.frag");



	// Genera el Objeto de Arreglo de Vértices y lo vincula
	VAO VAO1;
	VAO1.Bind();

	// Genera el Objeto de Búfer de Vértices y lo vincula a los vértices
	VBO VBO1(vertices, sizeof(vertices));
	// Genera el Objeto de Búfer de Elementos y lo vincula a los índices
	EBO EBO1(indices, sizeof(indices));

	// Vincula el VBO al VAO
	VAO1.LinkVBO(VBO1, 0);
	// Desvincula todo para evitar modificarlos por accidente
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();



	// Bucle principal (while)
	while (!glfwWindowShouldClose(window))
	{
		// Especificar el color del fondo
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Limpiar el búfer posterior y asignarle el nuevo color
		glClear(GL_COLOR_BUFFER_BIT);
		// Decirle a OpenGL qué Programa de Shaders queremos usar
		shaderProgram.Activate();
		// Vincular el VAO para que OpenGL sepa que debe usarlo
		VAO1.Bind();
		// Dibujar primitivas, número de índices, tipo de datos de los índices, desplazamiento de índices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Intercambiar el búfer posterior con el búfer frontal
		glfwSwapBuffers(window);
		// Atender todos los eventos de GLFW
		glfwPollEvents();
	}



	// Eliminar todos los objetos que hemos creado
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	// Eliminar la ventana antes de terminar el programa
	glfwDestroyWindow(window);
	// Terminar GLFW antes de terminar el programa
	glfwTerminate();
	return 0;
}