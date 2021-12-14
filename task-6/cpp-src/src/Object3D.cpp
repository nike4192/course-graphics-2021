
#include "Object3D.h"

void Object3D::updateMatrix()
{
	glm::mat4 ViewTranslate = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 ViewRotateX = glm::rotate(ViewTranslate, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 ViewRotateY = glm::rotate(ViewRotateX, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 View = glm::rotate(ViewRotateY, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), scale);

	matrix = View * Model;
}
