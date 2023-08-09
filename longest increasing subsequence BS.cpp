#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> ans = {arr[0]};
    for(int i=1 ; i<n ; i++)
    {
        int start = 0;
        int end = ans.size()-1;
        int mid;
        while(start<=end)
        {
            mid = (start+end)>>1;
            if(arr[i]<=ans[mid]) end = mid-1;
            else start = mid+1;
        }
        if(start>=ans.size()) ans.push_back(arr[i]);
        else ans[start] = arr[i];
    }
    return ans.size();
}
