#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief
 * 输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
 * @param nums
 * @param numsSize
 */
void moveZeroes(int* nums, int numsSize)
{
	// Double Pointers
	int j = 0;	// 下一个非零元素的下标
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != 0) {
			nums[j++] = nums[i];
		}
	}

	for (int k = j; k < numsSize; k++) {
		nums[k] = 0;
	}
}
