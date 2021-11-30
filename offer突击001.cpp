#include <iostream>
#include <stdio.h>
using namespace std;
class Solution {
public:
    int divide(int a, int b) {
        int sign=1;
        if((a>0&&b<0)||(a<0&&b>0)){
            sign =-1;
        }
        a=abs(a);
        b=abs(b);
        int n=0;
        while(a>=b){
            a-=b;
            n++;
        }
        return sign * n;
    }
};

int main() {
    Solution s1;
    int a=100,b=3;
    int solu=s1.divide(a,b);
    cout<<solu<<endl;
    return 0;
}
