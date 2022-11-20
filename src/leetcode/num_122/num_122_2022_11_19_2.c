#include <stdio.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize)
{
	if (pricesSize <= 1) {
		return 0;
	}

	int* profits = (int*)malloc(sizeof(int) * (pricesSize + 1));
	memset(profits, 0, sizeof(int) * (pricesSize + 1));
	profits[1] = prices[0];

	for (int j = 2; j < pricesSize + 1; j++) {
		int profit;
		int max = 0;

		// 1) 最后一天不卖
		profit = profits[j - 1];
		if (profit > max) {
			max = profit;
		}

		// 2) 最后一天卖

		for (int i = 1; i <= j - 1; i++) {
			profit = profits[i] + prices[j - 1] - prices[i - 1];
			if (profit > max) {
				max = profit;
			}
		}

		profits[j] = max;
	}

	return profits[pricesSize];
}