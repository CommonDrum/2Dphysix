#pragma once
#include "VertexBufferLayoutClass.h"
#include <vector>
#include <array>
#include <stdlib.h>
#include <time.h>


struct Vec3
{
	float x, y, z;
};

struct Vertex
{
	Vec3 coordinates = { 0,0,0 };
	Vec3 colors = { 1.0f,1.0f,1.0f };

};

static std::array<Vertex,4> GenQuad(float x, float y, float width)
{
	Vertex v1;
	v1.coordinates = { x,0,0 };
	Vertex v2;
	v2.coordinates = { x + width,0,0 };
	Vertex v3;
	v3.coordinates = { x + width,y,0 };
	Vertex v4;
	v4.coordinates = { x, y, 0 };


	return { v1,v2,v3,v4 };
}

/*
* ArraySorting class is used to create and manipulate
* Vertex and Index buffers to visualize sorting of an array.
* 
* 
* 
*/

class ArraySorting
{
public:
	ArraySorting(int count);

	void CreateVertices();
	void CreateIndicies();
	void RandomizeArray(float* arr,int size);
	void UpdateVertices();
	void QuadSwap(int index1, int index2);


	void* getVertices();
	void* getIndicies();
	 int getIBsize();
	 int getVBsize();
	 VertexBufferLayout* getLayout();



private:
	void p_floatSwap(int index1, int index2);
	std::vector<Vertex> p_vertices;
	std::vector<int> p_indicies;
	std::vector<float> p_array;
	VertexBufferLayout* p_layout = new VertexBufferLayout;

	float p_padding = 100.0f;
	int p_count;
	int p_iterator = 0;
	


};

