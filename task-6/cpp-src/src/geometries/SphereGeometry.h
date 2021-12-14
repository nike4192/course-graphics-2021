#ifndef SPHERE_GEOMETRY_H
#define SPHERE_GEOMETRY_H

#define _USE_MATH_DEFINES

#include <math.h>
#include "BufferGeometry.h"

// https://threejs.org/docs/?q=cone#api/en/geometries/SphereGeometry
class SphereGeometry : public BufferGeometry
{
public:
	SphereGeometry(float radius, int widthSegments, int heightSegments, float phiStart, float phiLength, float thetaStart, float thetaLength);
};

#endif
