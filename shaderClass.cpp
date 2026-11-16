#include"shaderClass.h"

// Lee un archivo de texto y devuelve una cadena con todo el contenido del archivo de texto
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

// Constructor que construye el Programa de Shaders a partir de 2 shaders diferentes
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	// Leer vertexFile y fragmentFile y almacenar las cadenas
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	// Convertir las cadenas de código fuente de los shaders en arreglos de caracteres
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Crear el Objeto de Shader de Vértices y obtener su referencia
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Adjuntar el código fuente del Shader de Vértices al Objeto de Shader de Vértices
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	// Compilar el Shader de Vértices a código de máquina
	glCompileShader(vertexShader);

	// Crear el Objeto de Shader de Fragmentos y obtener su referencia
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Adjuntar el código fuente del Shader de Fragmentos al Objeto de Shader de Fragmentos
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	// Compilar el Shader de Fragmentos a código de máquina
	glCompileShader(fragmentShader);

	// Crear el Objeto del Programa de Shaders y obtener su referencia
	ID = glCreateProgram();
	// Adjuntar los Shaders de Vértices y Fragmentos al Programa de Shaders
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	// Finalizar/Vincular todos los shaders juntos en el Programa de Shaders
	glLinkProgram(ID);

	// Eliminar los objetos de Shader de Vértices y Fragmentos que ya no son útiles
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

// Activa el Programa de Shaders
void Shader::Activate()
{
	glUseProgram(ID);
}

// Elimina el Programa de Shaders
void Shader::Delete()
{
	glDeleteProgram(ID);
}