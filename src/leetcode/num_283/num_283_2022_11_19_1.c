#include <stdio.h>
#include <stdbool.h>

/**
 * @brief
 * 输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
 * @param nums
 * @param numsSize
 */
void moveZeroes(int* nums, int numsSize)
{
	while (true) {
		bool isOk = true;
		for (int i = 0; i < numsSize; i++) {
			if (nums[i] == 0 && nums[i + 1] != 0) {
				isOk = false;
				int t = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = t;
			}
		}

		if (isOk) {
			break;
		}
	}
}