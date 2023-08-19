int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k){
    int dp[n];
    int i;
    int j;
    for (i = 0; i<n; i++){
        dp[i] = 10000000;
    }
    dp[src] = 0;
    int temp [n];
    for (i = 0; i<k+1; i++){
        memcpy(temp, dp, sizeof(dp));
        for (j = 0; j < flightsSize; j++){
            int dest = flights[j][1];
            int from = flights[j][0];
            int price = flights[j][2];
            if (temp[dest] > dp[from] + price) temp[dest] = dp[from] + price;
        }
        memcpy(dp, temp, sizeof(temp));
    }
    if (dp[dst] >= 10000000) return -1;
    return dp[dst];
}
