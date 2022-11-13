/**
 * @file num_136_2.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-11-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

/**
 * @brief
 *  1) A^A = 0
 *  2) A^0 = A
 *  3) A^B = B^A
 * @param nums
 * @param numsSize
 * @return int
 */
int singleNumber(int* nums, int numsSize)
{
	int res = nums[0];
	for (int i = 1; i < numsSize; i++) {
		res ^= nums[i];
	}

	return res;
}