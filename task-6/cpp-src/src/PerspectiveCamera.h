#ifndef PERSPECTIVE_CAMERA_H
#define PERSPECTIVE_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Object3D.h"

const float MIN_FOV = 10;
const float MAX_FOV = 100;

class PerspectiveCamera : public Object3D
{
public:
	PerspectiveCamera(float fov, float aspect, float near, float far);
	void updateProjectionMatrix();
	
	void setFov(float fov) { this->fov = glm::clamp(fov, MIN_FOV, MAX_FOV); };
	void setAspect(float aspect) { this->aspect = aspect; };
	void setNear(float near) { this->near = near; };
	void setFar(float far) { this->far = far; };

	const float getFov() { return fov; }
	const float getAspect() { return aspect; }
	const float getNear() { return near; }
	const float getFar() { return far; }

	const glm::mat4 getProjectionMatrix() { return projectionMatrix; }

private:
	glm::mat4 projectionMatrix;
	float fov;
	float aspect;
	float near;
	float far;
};

#endif