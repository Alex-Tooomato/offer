//
// Created by skyyw on 2021/12/26.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        //for(类型名 变量 ：需要遍历的数组)；遍历数组中对应变量
        for (int num: nums) {
            ++freq[num];
        }
        int ans = 0;
//        for (auto [num, occ]: freq) {
for(unordered_map<int, int>::iterator it=freq.begin();it!=freq.end();it++){
            if (it->second==1) {
                ans = it->first;
                break;
            }
        }
        return ans;

    }
    int singleNumber2(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int total=0;
            for(int num:nums){
                total+=((num>>i)&1);
            }
            if(total%3){
                ans|=1<<i;
            }
    }
        return ans;
    }
};
