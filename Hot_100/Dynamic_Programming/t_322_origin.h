#include <climits>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {  
    return (*(int *)a - *(int *)b);  
}
int coinChange(int* coins, int coinsSize, int amount) {
    int money[amount + 1];
    qsort(coins,coinsSize,sizeof(int),compare);
    money[0] = 0;
    int minn;
    for(int i = 1;i <= amount;i++){
        minn = INT_MAX;
        for(int j = 0;j < coinsSize;j++){
            if(coins[j] > i) break;
            minn = fmin(minn,money[i - coins[j]]);
        }
        money[i] = minn == INT_MAX ? INT_MAX : minn + 1;
    }
    return money[amount] == INT_MAX ? -1 : money[amount];
}