#ifndef CONICAL_SPIRAL_GEOMETRY_H
#define CONICAL_SPIRAL_GEOMETRY_H

#define _USE_MATH_DEFINES

#include <math.h>
#include "BufferGeometry.h"

// https://github.com/mrdoob/three.js/blob/master/src/geometries/SphereGeometry.js
class ConicalSpiralGeometry : public BufferGeometry
{
public:
	ConicalSpiralGeometry(float radius,float tube, float height, float radialSegments, float tubularSegments, float m);
};

#endif
