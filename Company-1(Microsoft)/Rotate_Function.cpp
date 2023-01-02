#include<bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
        int sum=0;int curr=0;int ans;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            curr=curr+nums[i]*i;
        }
        ans=curr;
        for(int i=nums.size()-1;i>0;i--)
        {
            curr=curr+sum-(nums.size()*nums[i]);
            ans=max(ans,curr);
        }
        return ans;
}

int main()
{
    vector<int> n={4,3,2,6};
    cout<<maxRotateFunction(n);
}