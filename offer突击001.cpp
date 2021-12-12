#include <iostream>
#include <stdio.h>
using namespace std;
class Solution {
public:
    int divide(int a, int b) {
        //越界考虑
        //32位最大值：2^31-1=2147483647;
        //32位最小值：-2^31 =-2147483648;
        //-2147483648/(-1)=2147483648>2147483647;
        if(a==INT32_MIN&&b==-1)
            return INT32_MAX;
        int sign=(a>0)^(b>0)?-1:1;
        //考虑到负数的正值可能会越界，但正数的负值不会，因此将取abs改成正值取反
        if(a>0)a=-a;
        if(b>0)b=-b;
        unsigned int n=0;
        while(a<=b){
            a-=b;
            n++;
        }
        return sign == 1 ? n : -n;
    }
};

int main() {
    Solution s1;
    int a=100,b=3;
    int solu=s1.divide(a,b);
    cout<<solu<<endl;
    return 0;
}
