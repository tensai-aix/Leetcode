int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int min = 0;
    int cur = 1;
    int tmp;
    while(cur < pricesSize){
        if(prices[cur] < prices[min]) min = cur;
        else{
            tmp = prices[cur] - prices[min];
            if(tmp > profit) profit = tmp;
        }
        cur++;
    }
    return profit;
}