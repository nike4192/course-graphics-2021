
#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(float fov=50, float aspect=1, float near=0.1, float far=2000)
: fov(fov), aspect(aspect), near(near), far(far)
{
	updateProjectionMatrix();
}

void PerspectiveCamera::updateProjectionMatrix()
{
	projectionMatrix = glm::perspective(glm::radians(fov), aspect, near, far);
}