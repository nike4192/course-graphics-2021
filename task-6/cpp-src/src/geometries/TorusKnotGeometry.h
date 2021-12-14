#ifndef TORUS_KNOT_GEOMETRY_H
#define TORUS_KNOT_GEOMETRY_H

#include "BufferGeometry.h"

// https://en.wikipedia.org/wiki/Torus_knot
// https://github.com/mrdoob/three.js/blob/master/src/geometries/TorusKnotGeometry.js
class TorusKnotGeometry : public BufferGeometry
{
public:
	TorusKnotGeometry(float radius, float tube, float tubularSegments, float radialSegments, float p, float q);
};

#endif
