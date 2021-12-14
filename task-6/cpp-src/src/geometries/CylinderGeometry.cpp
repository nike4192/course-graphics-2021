
#include "CylinderGeometry.h"

CylinderGeometry::CylinderGeometry(
	float radiusTop = 1, float radiusBottom = 1,
	float height = 1,
	float radialSegments = 8, float heightSegments = 1,
	bool openEnded = false,
	float thetaStart = 0, float thetaLength = 2 * M_PI)
{
    for (int i = 0; i <= radialSegments; ++i)
    {
        float theta = i * thetaLength / radialSegments + thetaStart;

        for (int j = 0; j <= heightSegments; ++j)
        {
            float t = (float)j / heightSegments;

            float r = glm::mix(radiusTop, radiusBottom, t);
            float x = r * cos(theta);
            float y = height * (0.5 - t);
            float z = r * sin(theta);
            
            vertices.push_back(glm::vec3(x, y, z));
        }
    }

    if (openEnded == false)
    {
        vertices.push_back(glm::vec3(0, -(float)height / 2, 0));
        vertices.push_back(glm::vec3(0,  (float)height / 2, 0));
    }

    for (int i = 1; i <= radialSegments; i++)
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

            if (j > 1 || radiusTop > 0)
            {
                indices.push_back(a);
                indices.push_back(d);
                indices.push_back(c);
            }

            if (j < heightSegments - 1 || radiusBottom > 0)
            {
                indices.push_back(a);
                indices.push_back(b);
                indices.push_back(d);
            }
        }

        if (openEnded == false)
        {
            if (radiusTop > 0)
            {            
                int a = (heightSegments + 1) * i;
                int b = (heightSegments + 1) * (i - 1);
                int c = vertices.size() - 1;

                //   c
                //  / \
                // a - b

                indices.push_back(a);
                indices.push_back(b);
                indices.push_back(c);
            }

            if (radiusBottom > 0)
            {
                int d = (heightSegments + 1) * i + heightSegments;
                int e = (heightSegments + 1) * (i - 1) + heightSegments;
                int f = vertices.size() - 2;

                //   f
                //  / \
                // e - d

                indices.push_back(e);
                indices.push_back(d);
                indices.push_back(f);
            }
        }
    }
};
