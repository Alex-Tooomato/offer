//
// Created by skyyw on 2021/12/24.
//

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int coutsOnes(int x){
        int ones=0;
        while(x>0){
            x=x&(x-1);
            ones++;
        }
        return ones;
    }
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        for(int i=0;i<=n;i++){
            bits[i]= coutsOnes(i);
        }
        return bits;
    }
    //动态规划，最高有效位
    vector<int> countBits2(int n) {
    vector<int> bits(n+1);
    bits[0]=0;
    bits[1]=1;
    int bigbits=0;
    for(int i=1;i<=n;i++){
        if((i&(i-1))==0){
            bigbits=i;
        }
        bits[i]=bits[i-bigbits]+1;
    }
    return bits;
    }
    //动态规划，最低有效位
    vector<int> countBits3(int n){
        vector<int> bits(n+1);
        bits[0]=0;
        bits[1]=1;
        for(int i=1;i<=n;i++){
            bits[i]=bits[i>>1]+(i%2);
        }
        return bits;
    }

};
int main()
{
    Solution su;
    int n=10;
//    vector<int> ans=su.countBits(n);
vector<int> s=su.countBits2(n);
for(int i=0;i<=n;i++){
    cout<<s[i]<<endl;
}

    return 0;
};
