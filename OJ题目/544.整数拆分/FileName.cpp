#include <stdio.h>
#include <math.h>

int integerBreak_dp(int N) {
    int dp[51] = { 0 }; 
    dp[2] = 1; 

    for (int i = 3; i <= N; i++) {
        for (int j = 1; j < i; j++) {
           
            int current = (j > dp[j]) ? j : dp[j];
            current *= (i - j);
            if (current > dp[i]) {
                dp[i] = current;
            }
        }
    }
    return dp[N];
}

int main() {
    int N;
    scanf("%d", &N);
    int maxProduct = integerBreak_dp(N);
    printf("%d\n", maxProduct);

    return 0;
}