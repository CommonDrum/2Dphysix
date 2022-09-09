#include "VertexBufferClass.h"

// Constructor that generates a dynamic Vertex Buffer Object and links it to vertices
VertexBuffer::VertexBuffer(GLsizeiptr allocate_size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, allocate_size, nullptr, GL_DYNAMIC_DRAW);
}

// Binds the VertexBuffer
void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbinds the VertexBuffer
void VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Deletes the VertexBuffer
void VertexBuffer::Delete()
{
	glDeleteBuffers(1, &ID);
}