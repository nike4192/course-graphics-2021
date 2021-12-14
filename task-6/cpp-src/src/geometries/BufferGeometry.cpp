
#include <iostream>
#include "BufferGeometry.h"
#include "glm/gtx/string_cast.hpp"

void BufferGeometry::computeFaceNormals()
{
	float a, b, c;
	glm::vec3 p1, p2, p3, n;

	normals.resize(indices.size());

	for (int i = 0; i < indices.size(); i += 3)
	{
		a = indices[i];
		b = indices[i + 1];
		c = indices[i + 2];

		p1 = vertices[a];
		p2 = vertices[b];
		p3 = vertices[c];

		n = glm::normalize(glm::cross(p3 - p2, p1 - p2));

		normals[i] = n;
		normals[i + 1] = n;
		normals[i + 2] = n;
	}
};

float* BufferGeometry::fillBuffer(float buffer[])
{
    for (int i = 0; i < indices.size(); i++)
    {
        int index = indices[i];

        glm::vec3 vertex = vertices[index];
        glm::vec3 normal = normals[i];
        glm::vec2 tex = uv[index];

        buffer[8 * i    ] = vertex.x;
        buffer[8 * i + 1] = vertex.y;
        buffer[8 * i + 2] = vertex.z;

        buffer[8 * i + 3] = normal.x;
        buffer[8 * i + 4] = normal.y;
        buffer[8 * i + 5] = normal.z;

        buffer[8 * i + 6] = tex.x;
        buffer[8 * i + 7] = tex.y;
    }

    return buffer;
};