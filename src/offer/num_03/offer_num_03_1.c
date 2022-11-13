#include <stdio.h>
#include "CuTest.h"


int findRepeatNumber(int *nums, int numsSize)
{
	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[ i ] == nums[ j ]) {
				return nums[ i ];
			}
		}
	}
	return 0;
}
void TestCase_001(CuTest *tc)
{
	int numsSize = 7;
	int nums[ 7 ] = {2, 3, 1, 0, 2, 5, 3};
	int ret = findRepeatNumber(nums, numsSize);
	CuAssertIntEquals(tc, 2, ret);
}

void TestCase_002(CuTest *tc) {}

CuSuite *GetSuite( )
{
	CuSuite *suite = CuSuiteNew( );
	SUITE_ADD_TEST(suite, TestCase_001);
	SUITE_ADD_TEST(suite, TestCase_002);
	return suite;
}

void RunAllTestCases( )
{
	CuString *output = CuStringNew( );
	CuSuite	*suite = GetSuite( );
	CuSuiteRun(suite);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main(int argc, char const *argv[])
{
	/* code */
	RunAllTestCases( );
	return 0;
}
