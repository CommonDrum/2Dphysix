#pragma once
#include <glad/glad.h>
#include "VertexArrayClass.h"
#include "IndexBufferClass.h"
#include "ShaderClass.h"
#include "glm/glm.hpp"




class Renderer
{
private:
	VertexArray* VA;
	IndexBuffer* IB;
	VertexBuffer* VB;
	Shader* p_Shader;
	

public:
	Renderer(Shader* shader);
	~Renderer();
	
	// Utilities
	void Clear();
	void Draw(int count);

	// Data provided from outside of the class
	void SetVBLayout(const VertexBufferLayout& layout);
	void SetShader(Shader* shader);
	//void SetVertexArray();
	void SetIndexBuffer(int size, void* data);
	void SetVertexBuffer(int size, void* data);
};
