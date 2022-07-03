#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CuTest.h"

#define MAX_CNT 100001
int findRepeatNumber(int* nums, int numsSize)
{
    int ret = -1;
    int integers[MAX_CNT];
    memset(integers, 0, sizeof(int) * MAX_CNT);
    for (int i = 0; i < numsSize; i++) { 
        integers[nums[i]]++;
        if (integers[nums[i]] > 1) {
            ret = nums[i];
            break;
        }
    }

    return ret;
}

void TestCase001(CuTest *tc)
{
    int nums[7] = {2, 3, 1, 0, 2, 5, 3};
    int numsSize = 7;
    int ret = findRepeatNumber(nums, numsSize);
    CuAssertIntEquals(tc, 2, ret);
}
int main(int argc, char const *argv[])
{
    /* code */
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestCase001);
    CuSuiteRun(suite);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    return 0;
}
