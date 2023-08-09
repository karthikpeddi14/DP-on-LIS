#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> ans = {INT_MIN};
    for(int i=0 ; i<n ; i++)
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
    return ans.size()-1;
}
