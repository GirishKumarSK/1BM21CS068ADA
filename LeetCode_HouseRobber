int rob(int* nums, int numsSize) {
    int n = numsSize;
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    int f[n + 1];
    f[0] = 0;
    f[1] = nums[0];
    
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] > (f[i - 2] + nums[i - 1]) ? f[i - 1] : (f[i - 2] + nums[i - 1]);
    }
    
    return f[n];
}
