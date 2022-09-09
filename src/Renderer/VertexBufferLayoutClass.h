#pragma once
#include <glad/glad.h>
#include <vector>
#include <iostream>

//Elements from which layuouts are built
struct VBelement
{
	unsigned int type;
	unsigned int count;
	bool normalized;


	// Get the size of type
	static unsigned int get_size(unsigned int type) {

		switch (type)
		{
		case GL_UNSIGNED_BYTE: return 1;
		case GL_UNSIGNED_INT: return 4;
		case GL_FLOAT: return 4;


		default:

			std::cout << "Invalid layout type";			
			return 0;
		}


	}
	
};


//Class to easily store and reuse Vertex Buffer layouts
//Mostly used with Vertex Array class
class VertexBufferLayout
{
private:
	std::vector<VBelement> m_Elements;
	unsigned int m_Stride = 0;

public:
	

	
	// Create templates for different datatype addition
	template <typename T> void Push(unsigned int count);




	// Good practice to access elements of the class
	inline const  std::vector<VBelement> get_elements() const { return m_Elements; }
	inline unsigned int get_stride() const { return m_Stride; }


};


