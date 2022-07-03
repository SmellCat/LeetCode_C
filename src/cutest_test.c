#include <stdio.h>
#include "CuTest.h"
// #include "CuTest.c"

void test_add(CuTest *tc)
{
    CuAssert(tc, "\r\vtest not pass", 1+ 1 == 1);
}

int main(int argc, char const *argv[])
{
    /* code */
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_add);
    CuSuiteRun(suite);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    return 0;
}
