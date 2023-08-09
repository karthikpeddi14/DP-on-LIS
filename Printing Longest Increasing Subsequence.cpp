vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) 
{
	vector<int> hash(n);
	vector<int> dp(n,1);
	int max_index = 0;

	for(int i=0 ; i<n ; i++)
	{
		hash[i] = i;
		for(int j=0 ; j<i ; j++)
		{
			if(arr[j] < arr[i] && dp[i]<1+dp[j]) 
			{
				dp[i] = 1+dp[j];
				hash[i] = j;
			}
		}
		if(dp[max_index]<dp[i]) max_index = i;
	}

	vector<int> ans(dp[max_index],0);
	int a=dp[max_index]-1;
	while(max_index!=hash[max_index])
	{
		ans[a] = arr[max_index];
		max_index = hash[max_index];
		a--;
	}
	ans[0] = arr[max_index];
	return ans;
	
}
