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
	while (true) {
		bool isOk = true;
		for (int i = 0; i + 1 < numsSize; i++) {
			if (nums[i] == 0 && nums[i + 1] != 0) {
				isOk = false;
				for (int k = i; k < numsSize - 1; k++) {
					nums[k] = nums[k + 1];
				}
				nums[numsSize - 1] = 0;
			}
		}

		if (isOk) {
			break;
		}
	}
}

void moveZeroes_memcpy(int* nums, int numsSize)
{
	while (true) {
		bool isOk = true;
		for (int i = 0; i + 1 < numsSize; i++) {
			if (nums[i] == 0 && nums[i + 1] != 0) {
				isOk = false;
				memcpy(nums[i], nums[i + 1], sizeof(int) * (numsSize - i - 1));
				nums[numsSize - 1] = 0;
			}
		}
		if (isOk) {
			break;
		}
	}
}
