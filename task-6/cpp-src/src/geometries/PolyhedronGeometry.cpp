
#include <iostream>
#include "PolyhedronGeometry.h"

void PolyhedronGeometry::applyVertices(float radius, int detail)
{
	std::cout << "vertices.size(): " << vertices.size() << std::endl;

	for (int i = 0; i < vertices.size(); i++)
	{
		glm::vec3 vertex = vertices[i];

		vertices[i] = glm::normalize(vertex) * radius;
	}

	std::cout << "PolyhedronGeometry" << std::endl;
};
