#pragma once
#include "VertexBufferClass.h"
#include "VertexBufferLayoutClass.h"


class VertexArray
{
public:
	// ID reference for the Vertex Array Object
	GLuint ID;
	// Constructor that generates a VertexArray ID
	VertexArray();

	// Links a VertexBuffer to the VertexArray using a certain layout
	void LinkVertexBuffer( VertexBuffer& vb, const VertexBufferLayout& layout);
	// Binds the VertexArray
	void Bind();
	// Unbinds the VertexArray
	void Unbind();
	// Deletes the VertexArray
	void Delete();
};
