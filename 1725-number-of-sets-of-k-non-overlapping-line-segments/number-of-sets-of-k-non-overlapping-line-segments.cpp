class Solution {
public:
    int numberOfSets(int n, int k) {
        int MOD=1e9+7;
        vector<int> dp(n), prefix(n+1);
        for(int i =0; i<n; i++){
            dp[i]=1;
            prefix[i+1]=(prefix[i]+dp[i]) % MOD;
        }
        for(int i=1;i<=k;i++){
            dp[0]=0;
            for(int j =1; j<n; j++){
                dp[j] = (dp[j-1] +prefix[j]) % MOD;
            }
            for(int j=0; j<n; j++){
                prefix[j+1]=(prefix[j] +dp[j]) %MOD;
            }
        }
        return dp[n-1];
    }
};