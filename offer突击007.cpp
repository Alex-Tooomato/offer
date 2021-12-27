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
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]==-nums[i]){
                    ans.push_back({nums[i],nums[left],nums[right]});
                } else if(nums[left]+nums[right]>-nums[i]){
                    right--;
                } else{
                    left --;
                }
            }
        }
        return ans;
    }
};