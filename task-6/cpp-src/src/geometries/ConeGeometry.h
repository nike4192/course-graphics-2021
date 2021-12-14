#ifndef CONE_GEOMETRY_H
#define CONE_GEOMETRY_H

#define _USE_MATH_DEFINES

#include <math.h>
#include "CylinderGeometry.h"

// https://github.com/mrdoob/three.js/blob/master/src/geometries/ConeGeometry.js
class ConeGeometry : public CylinderGeometry
{
public:
	ConeGeometry(float radius, float height, int radialSegments, int heightSegments, bool openEnded, float thetaStart, float thetaLength)
	: CylinderGeometry(0, radius, height, radialSegments, heightSegments, openEnded, thetaStart, thetaLength) {};
};

#endif
