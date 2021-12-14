#ifndef CYLINDER_GEOMETRY_H
#define CYLINDER_GEOMETRY_H

#define _USE_MATH_DEFINES

#include <math.h>
#include "BufferGeometry.h"

// https://github.com/mrdoob/three.js/blob/master/src/geometries/CylinderGeometry.js
class CylinderGeometry : public BufferGeometry
{
public:
	CylinderGeometry(float radiusTop, float radiusBottom, float height, float radialSegments, float heightSegments, bool openEnded, float thetaStart, float thetaLength);
};

#endif
