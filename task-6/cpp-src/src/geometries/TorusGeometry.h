#ifndef TORUS_GEOMETRY_H
#define TORUS_GEOMETRY_H

#define _USE_MATH_DEFINES

#include <math.h>
#include "BufferGeometry.h"

// https://en.wikipedia.org/wiki/Torus
// https://github.com/mrdoob/three.js/blob/master/src/geometries/TorusGeometry.js
class TorusGeometry : public BufferGeometry
{
public:
	TorusGeometry(float radius, float tube, int radialSegments, int tubularSegments, float arc);
};

#endif
