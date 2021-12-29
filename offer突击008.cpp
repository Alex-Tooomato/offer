//
// Created by pc on 2021/12/29.
//

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //二分法
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT32_MAX;
        int n=sizeof(nums);
        if(n==0){
            return 0;
        }
        vector<int> sums(n+1);
        for(int i=1;i<n+1;i++){
            sums[i]+=sums[i-1]+nums[i-1];
        }
        for(int i=1;i<=n;i++){
            int s=target+sums[i-1];
            auto bound= lower_bound(sums.begin(),sums.end(),target);
            if(bound!=sums.end()){
                ans=min(ans,static_cast<int>((bound-sums.begin())-(i-1)));
            }
        }
        return ans==INT32_MAX?0:ans;
    }
    //滑动窗口
    int minSubArrayLen2(int target, vector<int>& nums) {

        int n=nums.size();
        if(n==0){
            return 0;
        }
        int ans=INT32_MAX;
        int start=0,end=0;
        int sum=0;
        while(end<n){
            sum+=nums[end];
            while(sum>=target){
                ans=min(ans,end-start+1);
                sum-=nums[start];
                start++;
            }
            end++;
        }
        return ans==INT32_MAX?0:ans;
    }
};
int main(){
    int target=7;
    vector<int> nums={2,3,1,2,4,3};
    Solution su;
    int ans=su.minSubArrayLen2(target,nums);
    cout<<ans<<endl;
    return 0;
}