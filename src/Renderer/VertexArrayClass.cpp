#include "VertexArrayClass.h"


// Constructor that generates a VertexArray ID
VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
}

// Links a VertexBuffer to the VertexArray using a certain layout
void VertexArray::LinkVertexBuffer( VertexBuffer& vb, const VertexBufferLayout& layout)
{
	vb.Bind();
	const auto& elements = layout.get_elements();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++ )
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.get_stride(), (void*) offset);

		offset += element.count * element.get_size(element.type);
	}

	vb.Unbind();
}



// Binds the VertexArray
void VertexArray::Bind()
{
	glBindVertexArray(ID);
}

// Unbinds the VertexArray
void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

// Deletes the VertexArray
void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &ID);
}