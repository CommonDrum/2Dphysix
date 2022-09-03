#pragma once
#include "glm/glm.hpp"






namespace Test 
{
	struct Vertex {
		glm::vec3 coordinates;
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
	};

	//allocate memory
	// fill with numbers
	int* CreateArrayToSort(int size)
	{
		int* list = new int[size];

		for (int i = 0; i < size; i++)
		{
			list[i] = i;
		}
		return list;
	}

	Vertex* CreateQuad(float x, float y, float width)
	{
	
		Vertex quad[4];

		quad[0].coordinates = glm::vec3(x, 0, 0);
		quad[1].coordinates = glm::vec3(x + width, 0, 0);
		quad[2].coordinates = glm::vec3(x + width, y, 0);
		quad[3].coordinates = glm::vec3(x, y, 0);

		return quad;
	}

	//allocate memory
	Vertex* CreateVertexBufferQuad(int count, int* list)
	{
		Vertex* VBdata = new Vertex[count * 4];

		float xPosition = -10.0f;
		float width = (200 - (xPosition * 2)) / count;
		
		

		for (int i = 0; i < count; i++)
		{
			memcpy(&VBdata[i], CreateQuad(xPosition, list[i], width), sizeof(Vertex) * 4);
			width += width;

		}
		return VBdata;
		
	}

	int * CreateIndexBufferQuad(int count)
	{
		int* IB = new int[count*4];

		int baseQuadIndecies[] = { 0,1,2,3,2,0 };

		for (int i = 0; i < count * 6; i++)
		{
			IB[i] = baseQuadIndecies[i % 6] + (4 * i);
		}

		return IB;
	}
}