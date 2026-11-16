#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include"VBO.h"

class VAO
{
public:
	// Referencia de ID para el Objeto de Arreglo de Vértices
	GLuint ID;
	// Constructor que genera un ID de VAO
	VAO();

	// Vincula un VBO al VAO usando un diseño (layout) determinado
	void LinkVBO(VBO& VBO, GLuint layout);
	// Vincula el VAO
	void Bind();
	// Desvincula el VAO
	void Unbind();
	// Elimina el VAO
	void Delete();
};
#endif