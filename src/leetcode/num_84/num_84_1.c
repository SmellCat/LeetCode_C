#include <stdio.h>
#include <limits.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

int largestRectangleArea(int* heights, int heightsSize)
{
	int max = INT_MIN;
	for (int i = 0; i < heightsSize; i++) {
		int height = heights[i];
		for (int j = i; j < heightsSize; j++) {
			height = MIN(height, heights[j]);
			int width = j - i + 1;
			max = MAX(max, height * width);
		}
	}

	return max;
}