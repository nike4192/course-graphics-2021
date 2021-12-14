#ifndef OBJECT_3D_H
#define OBJECT_3D_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Object3D
{
public:
	Object3D() {};

	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

	glm::mat4 matrix;

	void updateMatrix();

	std::vector<Object3D> children;
};

#endif