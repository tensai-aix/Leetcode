// interesting,most important is to write out the func
// 这题给了我个冲击，主要是动态规划并不一定得是O(n)
#include <climits>
#include <math.h>

int numSquares(int n) {
    int f[n + 1];
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        int minn = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
            minn = fmin(minn, f[i - j * j]);
        }
        f[i] = minn + 1;
    }
    return f[n];
}
