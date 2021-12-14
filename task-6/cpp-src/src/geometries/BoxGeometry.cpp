
#include "BoxGeometry.h"

BoxGeometry::BoxGeometry(float width = 1, float height = 1, float depth = 1, int widthSegments = 1, int heightSegments = 1, int depthSegments = 1)
{
	float xOffset = - width / 2;
	float yOffset = - height / 2;
	float zOffset = - depth / 2;

	float x, y, z;

	for (int i = 0; i <= widthSegments; i++)
	{
		x = width * i / widthSegments + xOffset;
		for (int j = 0; j <= heightSegments; j++)
		{
			y = height * j / heightSegments + yOffset;
			for (int k = 0; k <= depthSegments; k++)
			{
				z = depth * k / depthSegments + zOffset;

				vertices.push_back(glm::vec3(x, y, z));
			}
		}
	}
};
