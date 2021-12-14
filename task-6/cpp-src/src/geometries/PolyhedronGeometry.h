#ifndef POLYHEFRON_GEOMETRY_H
#define POLYHEFRON_GEOMETRY_H

#define _USE_MATH_DEFINES

#include <math.h>
#include "BufferGeometry.h"

// https://github.com/mrdoob/three.js/blob/master/src/geometries/PolyhedronGeometry.js
class PolyhedronGeometry : public BufferGeometry
{
public:
	PolyhedronGeometry() {};
	void applyVertices(float radius, int detail);
};

#endif
