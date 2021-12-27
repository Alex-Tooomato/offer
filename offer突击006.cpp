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
    vector<int> twoSum(vector<int>& numbers, int target) {
       int left=0;
       int right = numbers.size()-1;
       while(left<right){
           int sum=numbers[left]+numbers[right];
           if(sum==target){
               return {left,right};
           }else if(sum > target){
               right--;
           } else{
               left++;
           }
       }
        return{};

    }
};