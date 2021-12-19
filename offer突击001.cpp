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
//        if(a>0)a=-a;
//        if(b>0)b=-b;
        unsigned int n=0;
//        while(a<=b){
//            int value=b;
//            // 如果不用 unsigned 的话，那么当 a = -2147483648, b = 1 的时候，k 会越界
//            unsigned int k=1;
//            // 0xc0000000 是十进制 -2^30 的十六进制的表示
//            // 判断 value >= 0xc0000000 的原因：保证 value + value 不会溢出
//            // 可以这样判断的原因是：0xc0000000 是最小值 -2^31 的一半，
//            // 而 a 的值不可能比 -2^31 还要小，所以 value 不可能比 0xc0000000 小
//
//            while(value>=0xc0000000&&a<=value+value){
//                value+=value;
//                k+=k;
//            }
//            a-=value;
//            n+=k;
//        }

//按位运算，较小复杂度
unsigned int ua=abs(a);
unsigned int ub=abs(b);
for(int i=31;i>=0;i--){
    if((ua>>i)>=ub){//a>=b<<i;防止b越界，于是改成a>>i>=b
        ua=ua-(ub<<i);
        n+=1<<i;
    }
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
