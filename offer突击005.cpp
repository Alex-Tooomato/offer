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
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> states(n);
        for (int i=0;i<n;i++){
            states[i]=0;
            int m=words[i].size();
            for(int j=0;j<m;j++){
//                states[i]|=(1<<(words[i].at(j)-'a'));//用|=保证即使出现重复也不会记录
                states[i]|=(1<<(words[i][j]-'a'));//用|=保证即使出现重复也不会记录
            }
        }
        int ans=0;
        for (int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((states[i]&states[j])==0){
                    int tmp=words[i].size()*words[j].size();
                    ans=max(ans,tmp);
                }
            }
        }
        return ans;

    }
};
