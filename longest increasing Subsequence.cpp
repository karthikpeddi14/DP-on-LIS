// recur and memo
class Solution {
public:
    int f(vector<int>&nums, int index, int PrevIndex,vector<vector<int>>& dp)
    {
        if(index==nums.size()) return 0;
        if(dp[index][PrevIndex+1]!=-1) return dp[index][PrevIndex+1];

        int notTake = f(nums,index+1,PrevIndex,dp);
        int take = 0;
        if(PrevIndex==-1 || nums[PrevIndex]<nums[index]) take = 1+f(nums,index+1,index,dp);

        return dp[index][PrevIndex+1] = max(take,notTake);
    }    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp);
    }
};
// recur and memo

// tabulation
class Solution {
public:   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int ind=n-1; ind>=0 ; ind--)
        {
            for(int prev=ind-1; prev>=-1; prev--)
            {
                int notTake = dp[ind+1][prev+1];
                int take = 0;
                if(prev==-1 ||nums[prev]<nums[ind]) take = 1+dp[ind+1][ind+1];
                dp[ind][prev+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
};
// tabulation

// space opti
class Solution {
public:   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1,0), cur(n+1,0);

        for(int ind=n-1; ind>=0 ; ind--)
        {
            for(int prev=ind-1; prev>=-1; prev--)
            {
                int notTake = next[prev+1];
                int take = 0;
                if(prev==-1 ||nums[prev]<nums[ind]) take = 1+next[ind+1];
                cur[prev+1] = max(take,notTake);
            }
            next= cur;
        }
        return next[0];
    }
};
// space opti
