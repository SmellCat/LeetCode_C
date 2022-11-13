/**
 * @file num_136_1.c
 * @author your name (you@domain.com)
 * @brief
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * @version 0.1
 * @date 2022-11-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
	for (int i = 0; i < numsSize; i++) {
		int count = 0;
		for (int j = 0; j < numsSize; j++) {
			if (nums[j] == nums[i]) {
				count++;
			}
		}
		if (count == 1) {
			return nums[i];
		}
	}
}