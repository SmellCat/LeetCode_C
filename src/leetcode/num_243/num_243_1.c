#include <stdio.h>
#include <string.h>
int shortestDistance(char** wordsDict,
					 int wordsDictSize,
					 char* word1,
					 char* word2)
{
	int word1Index = -1;
	int word2Index = -1;
	int i = 0;
	int j = wordsDictSize - 1;
	int res = wordsDictSize + 1;
	while (i < j) {
		if (strcmp(wordsDict[i], word1) == 0) {
			word1Index = i;
		}
		else if (strcmp(wordsDict[i], word2) == 0) {
			word2Index = i;
		}

		if (strcmp(wordsDict[j], word1) == 0) {
			word1Index = j;
		}
		else if (strcmp(wordsDict[j], word2) == 0) {
			word2Index = j;
		}
		if (word1Index != -1 && word2Index != -1) {
			int cur = word1Index > word2Index ? word1Index - word2Index :
												word2Index - word1Index;
			res = res > cur ? cur : res;
		}
		i++;
		j--;
	}

	return res;
}