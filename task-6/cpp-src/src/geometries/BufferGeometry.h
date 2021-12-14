#ifndef BUFFER_GEOMETRY_H
#define BUFFER_GEOMETRY_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class BufferGeometry
{
public:
	BufferGeometry() {};

	void computeFaceNormals();
	float* fillBuffer(float buffer[]);

	std::vector<int> indices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uv;
};

#endif
