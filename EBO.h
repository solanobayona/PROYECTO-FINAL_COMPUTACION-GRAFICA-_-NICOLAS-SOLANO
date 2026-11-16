#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

class EBO
{
public:
	// Referencia de ID del Objeto de Búfer de Elementos
	GLuint ID;
	// Constructor que genera un Objeto de Búfer de Elementos y lo vincula a los índices
	EBO(GLuint* indices, GLsizeiptr size);

	// Vincula el EBO
	void Bind();
	// Desvincula el EBO
	void Unbind();
	// Elimina el EBO
	void Delete();
};

#endif