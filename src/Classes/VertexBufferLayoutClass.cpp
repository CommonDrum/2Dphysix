#include "VertexBufferLayoutClass.h"

template <typename T> void VertexBufferLayout::Push(unsigned int count)
{
    //issue an error for undefined type
}

template <> void VertexBufferLayout::Push<float>( unsigned int count)
{
    m_Elements.push_back({GL_FLOAT,count,false });
    m_Stride += sizeof(GLfloat) * count;
}
template <> void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({ GL_UNSIGNED_INT,count,false });
    m_Stride += sizeof(GLuint) * count;
}
template <> void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({ GL_UNSIGNED_BYTE,count,false });
    m_Stride += sizeof(GLbyte) * count;
}
