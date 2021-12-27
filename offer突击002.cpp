//
// Created by skyyw on 2021/11/30.
//
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0;
        int n=max(a.size(),b.size());
        for(int i=0;i<n;i++){
            carry+=i<a.size()?(a.at(i)=='1'):0;
            carry+=i<b.size()?(b.at(i)=='1'):0;
            res.push_back((carry%2)?'1':'0');
            carry/=2;
        }
        if(carry){
            res.push_back('1');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
int main()
{
    Solution su;
    string a="11";
    string b="01";
    cout<<a.size()<<endl;
    string ans=su.addBinary(a,b);
    cout<<"ans="<<ans<<endl;
    return 0;
};


