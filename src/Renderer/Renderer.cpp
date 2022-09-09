#include "Renderer.h"

// How vertex looks like and its layout will be set
// outside of the renderer
// So here I need how many vertives i want 
// how big is the Index buffer
// and where is the data for both

// Initialize all buffers (know size)

// Send data (have data)

// Draw and Clear (NONE)


// Now the size of the index buffer and Vertex buffer
// Send Index and Vertex buffers to the GPU

Renderer::Renderer(Shader* shader)
{
	// Keep track of the shader
	p_Shader = shader;

	// Generates Vertex Array Object and binds it
	// All buffers are now dynamic and are managed
	// by the Renderer class
	VA = new VertexArray();
	IB = new IndexBuffer(100000 * 4);
	VB = new VertexBuffer(100000 * 4);
	VA->Bind();
	
}

Renderer::~Renderer()
{
	// Cleanup
	VA->Delete();
	VB->Delete();
	IB->Delete();
	p_Shader->Delete();
}






// Utilities
void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(int count)
{
	VA->Bind();
	IB->Bind();
	p_Shader->Activate();

	// Draw primitives, number of indices, datatype of indices, index of indices
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}

// Data provided from outside of the class
void Renderer::SetShader(Shader* shader)
{
	p_Shader = shader;
}

void Renderer::SetVertexBuffer(int size, void* data)
{
	VB->Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}


void Renderer::SetVBLayout(const VertexBufferLayout& layout)
{
	VA->LinkVertexBuffer(*VB, layout);
}


void Renderer::SetIndexBuffer(int size, void* data)
{
	IB->Bind();
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, data);
}