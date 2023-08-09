// tabulation
class Solution {
public:   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=0;
        for(int i=0 ; i<n ; i++)
        {
            int sub_max= 0;
            for(int j=0 ; j<i ; j++)
            {
                if(nums[j]<nums[i]) sub_max = max(sub_max,dp[j]);
            }
            dp[i] += sub_max;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
// tabulation
