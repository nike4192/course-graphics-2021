
#include "SphereGeometry.h"

SphereGeometry::SphereGeometry(
	float radius = 1,
	int widthSegments = 32, int heightSegments = 16,
	float phiStart = 0, float phiLength = 2 * M_PI,
	float thetaStart = 0, float thetaLength = M_PI)
{
    float phi, theta, u, v;
    for (int i = 0; i <= widthSegments; i++)
    {
        u = (float)i / widthSegments;
        phi = u * phiLength + phiStart;

        for (int j = 0; j <= heightSegments; j++)
        {   
            // Spherical coordinate system
            v = (float)j / heightSegments;
            theta = v * thetaLength + thetaStart;

            float x = radius * sin(theta) * cos(phi);
            float z = radius * sin(theta) * sin(phi);
            float y = radius * cos(theta);
            
            vertices.push_back(glm::vec3(x, y, z));
            uv.push_back(glm::vec2(u, v));
        }

    }

    float thetaEnd = thetaStart + thetaLength;

    for (int i = 1; i <= widthSegments; i++)
    {
        for (int j = 1; j <= heightSegments; j++)
	    {
            int a = (heightSegments + 1) * i + (j - 1);
            int b = (heightSegments + 1) * i + j;
            int d = (heightSegments + 1) * (i - 1) + j;
            int c = (heightSegments + 1) * (i - 1) + (j - 1);

            // a - c
            // | \ |
            // b - d

            if (j > 1 || thetaStart > 0)
            {
                indices.push_back(a);
                indices.push_back(d);
                indices.push_back(c);
            }
            
            if (j < heightSegments || thetaEnd < M_PI)
            {
                indices.push_back(a);
                indices.push_back(b);
                indices.push_back(d);
            }
	    }
    }
};
