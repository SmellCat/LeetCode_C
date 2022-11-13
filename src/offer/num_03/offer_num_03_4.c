#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
#include "CuTest.h"

typedef struct
{
	int val;
	UT_hash_handle hh;
} Dict;


int findRepeatNumber(int* nums, int numsSize)
{
	Dict* dict = NULL;

	for (int i = 0; i < numsSize; i++) {
		Dict* tmp;
		HASH_FIND_INT(dict, &nums[i], tmp);
		if (tmp) {
			return nums[i];
		}
		Dict* cur = (Dict*)malloc(sizeof(Dict));
		cur->val = nums[i];
		HASH_ADD_INT(dict, val, cur);
	}

	return -1;
}

void TestCase_001(CuTest* tc) {}

void TestCase_002(CuTest* ct) {}

CuSuite* GetSuite()
{
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestCase_001);
	SUITE_ADD_TEST(suite, TestCase_002);
	return suite;
}

void RunAllTestCases()
{
	CuString* output = CuStringNew();
	CuSuite* suite = GetSuite();
	CuSuiteRun(suite);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main(int argc, char const* argv[])
{
	/* code */
	RunAllTestCases();
	return 0;
}
