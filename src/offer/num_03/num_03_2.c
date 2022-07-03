#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"

int compare(const void *a, const void *b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    return aa > bb ? 1 : (aa < bb ? -1 : 0);
}
int findRepeatNumber(int* nums, int numsSize){
    int ret = -1;
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i-1] == nums[i]) {
            ret = nums[i-1];
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

CuSuite* GetAllSuite()
{
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCase001);
    return suite;
}


void RunAllTests(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    // CuSuiteAddSuite(suite, GetAllSuite());
    SUITE_ADD_TEST(suite, TestCase001);
    CuSuiteRun(suite);
    // CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main(int argc, char const *argv[])
{
    /* code */
    RunAllTests();
    return 0;
}
