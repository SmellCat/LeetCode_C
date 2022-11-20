

int maxProfit(int* prices, int pricesSize)
{
	if (pricesSize <= 1) {
		return 0;
	}
	int profit;
	int max = 0;
	// 1) 最后一天不卖
	// [7,1,5,3,6,4] => [7,1,5,3,6]
	profit = maxProfit(prices, pricesSize - 1);
	if (profit > max) {
		max = profit;
	}
	// 2) 最后一天卖

	for (int i = 1; i <= pricesSize - 1; i++) {
		profit = maxProfit(prices, i) + prices[pricesSize - 1] - prices[i - 1];
		if (profit > max) {
			max = profit;
		}
	}

	return max;
}