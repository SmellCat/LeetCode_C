#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isHappy(int n)
{
	n = 12345;
	for (int i = 1; i < 1000000000; i *= 10) {
		printf("%d\n", n / i % 10);
	}
	return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	printf("%d\n", INT_MAX);
	printf("%d\n", INT_MAX / 1000000000 % 10);
	isHappy(19);
	return 0;
}
