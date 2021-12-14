
#include "TorusGeometry.h"

TorusGeometry::TorusGeometry(
	float radius = 1, float tube = 0.4,
	int radialSegments = 8, int tubularSegments = 6,
	float arc = 2 * M_PI)
{
    for (int i = 0; i <= radialSegments; ++i)
    {
        float phi = i * arc / radialSegments;

        for (int j = 0; j <= tubularSegments; ++j)
        {
            float theta = j * 2 * M_PI / tubularSegments;

            float x = (radius + tube * cos(theta)) * cos(phi);
            float y = (radius + tube * cos(theta)) * sin(phi);
            float z = tube * sin(theta);

            vertices.push_back(glm::vec3(x, y, z));
        }
    }

    for (int i = 1; i <= radialSegments; i++)
    {
        for (int j = 1; j <= tubularSegments; j++)
        {
            int a = (tubularSegments + 1) * i + (j - 1);
            int b = (tubularSegments + 1) * i + j;
            int d = (tubularSegments + 1) * (i - 1) + j;
            int c = (tubularSegments + 1) * (i - 1) + (j - 1);

            // a - c
            // | \ |
            // b - d

            indices.push_back(a);
            indices.push_back(b);
            indices.push_back(d);

            indices.push_back(a);
            indices.push_back(d);
            indices.push_back(c);
        }
    }
};
