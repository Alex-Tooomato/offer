//
// Created by pc on 2021/12/27.
//

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3)
            return ans;
        std::sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++){
            //去重
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]==-nums[i]){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    //去重
                    while(left<right&&(nums[left]==nums[++left]));
                    while(left<right&&(nums[right]==nums[--right]));
                } else if(nums[left]+nums[right]>-nums[i]){
                    right--;
                } else{
                    left ++;
                }
            }
        }
        return ans;
    }
};