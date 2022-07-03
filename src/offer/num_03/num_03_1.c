#include <stdio.h>

int findRepeatNumber(int* nums, int numsSize){
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return nums[i];
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    int numsSize = 7;
    int nums[7] = {2, 3, 1, 0, 2, 5, 3};
    findRepeatNumber(nums, numsSize);
    return 0;
}
