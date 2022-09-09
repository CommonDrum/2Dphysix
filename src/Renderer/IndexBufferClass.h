#pragma once
#include<glad/glad.h>

class IndexBuffer
{
private:
	int m_Size;

public:
	// ID reference of Elements Buffer Object
	GLuint ID;
	
	// Constructor that generates a Elements Buffer Object and links it to indices
	IndexBuffer(GLsizeiptr size);

	// Binds the ElementBuffer
	void Bind();
	// Unbinds the ElementBuffer
	void Unbind();
	// Deletes the ElementBuffer
	void Delete();
	//Get the size ;)
	int GetCount();
};
