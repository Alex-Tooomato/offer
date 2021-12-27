# offer突击001

1. 首先应想到用减法代替除法。

   b被a减了多少次，除数就是多少，最后一个正数或0就是余数。

   除法得出的正负与除数和被除数的符号有关，可以提前确定，接着将两数都取正值

2. 考虑到int越界的问题，有符号数int的范围-2147483648到2147483647

   考虑到负数的正值可能会越界，但正数的负值不会，因此将取abs改成正值取反

3. 每次都减去被除数可能导致超时，可以减去被除数的两倍，如果小于0则回退继续减被除数

4. 用按位运算，减小复杂度(除数乘2)

```c++
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
```



# offer突击002

### 要点

1. 「**加法**」系列题目都不难，其实就是 **「列竖式」模拟法**。

「列竖式」模拟法就是模仿十进制数加法的计算过程。

### 十进制加法

我们先回顾一下十进制加法的计算过程，红点表示进位：

<img src="https://pic.leetcode-cn.com/1634376064-AtRiWA-%E5%8A%A0%E6%B3%95.001.jpeg" alt="加法.001.jpeg" style="zoom: 50%;" />

**使用「竖式」计算十进制的加法的方式：**

1. 两个「**加数**」的右端对齐；
2. 从最右侧开始，依次计算对应的两位数字的和。如果和大于等于 10，则把和的个位数字计入结果，并向前面进位。
3. 依次向左计算对应位置两位数字的和，如果有进位需要加上进位。如果和大于等于 10，仍然把和的个位数字计入结果，并向前面进位。
4. 当两个「加数」的每个位置都计算完成，如果最后仍有进位，需要把进位数字保留到计算结果中。

### 二进制加法

二进制加法的计算也可以采用类似的方法，与十进制不同的是，**二进制的进位规则是「逢二进一」**，即当求和结果 >= 2>=2 时，需要向前进位。

- 红点表示进位。

<img src="https://pic.leetcode-cn.com/1634377045-ydzKJa-%E5%8A%A0%E6%B3%95.002.jpeg" alt="加法.002.jpeg" style="zoom:50%;" />

```c++
string ans;
reverse(a.begin(), a.end());
reverse(b.begin(), b.end());

int n = max(a.size(), b.size()), carry = 0;
for (size_t i = 0; i < n; ++i) {
    carry += i < a.size() ? (a.at(i) == '1') : 0;
    carry += i < b.size() ? (b.at(i) == '1') : 0;
    ans.push_back((carry % 2) ? '1' : '0');
    carry /= 2;
}

if (carry) {
    ans.push_back('1');
}
reverse(ans.begin(), ans.end());

return ans;
```

# offer突击003

方法一：Brian Kernighan 算法
最直观的做法是对从$0$ 到 $n$ 的每个整数直接计算「一比特数」。每个int 型的数都可以用 32 位二进制数表示，只要遍历其二进制表示的每一位即可得到 $1$的数目。

利用Brian Kernighan 算法，可以在一定程度上进一步提升计算速度。Brian Kernighan 算法的原理是：对于任意整数 x，令 $x=x\&(x-1)$，该运算将 x 的二进制表示的最后一个 1 变成 0。因此，对 x 重复该操作，直到 x 变成 0，则操作次数即为 x 的「一比特数」。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200526103654580.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzY4ODQ4Mw==,size_16,color_FFFFFF,t_70#pic_center)

方法二：动态规划——最高有效位
方法1有很多重复运算， 比如i=2^n的1的个数为1，且此1为最高位。设此时的i为highbit，比它小的数加上这个highbit所产生的数的bit为1的位数只是在之前的基础上+1，即bit[i]=bit[i-highbit]+1;

1. 根据 i & (i-1) 计算i的二进制形式中1的个数
2. i & (i-1) 能将整数i的二进制形式最右边的1变为0，那么 整数i的二进制中1的个数比整数i&(i-1)的二进制中1的个数多1.



方法三：动态规划——最低有效位

1. 如果正整数i是一个偶数，那么i相当于将i/2左移一位的结果，也就是说偶数i和i/2的二进制形式中的1的个数是相同的
2. 如果i是奇数，则i相当于将i/2左移一位之后再将最右边一位设为1的结果，因此奇数i的二进制形式中1的个数比i/2的1的个数多1
3. 比方说3的二进制为11，有2个1；偶数6的二进制为110，有2个1；奇数7的二进制为111，有3个1，所以我们可以根据3的二进制中1的个数来直接求出6和7的二进制形式中1的个数。

方法四：动态规划——最低设置位

定义正整数 x 的「最低设置位」为 x 的二进制表示中的最低的 1 所在位。例如，1010 的二进制表示是$ 1010_{(2)}$
其最低设置位为 2，对应的二进制表示是 $10_{(2)}$

设y=x&(x-1)，则y为让x的最低设置位从1变成0之后的数，显然 $0 \le y<x$，$\textit{bits}[x]=\textit{bits}[y]+1$。因此对任意正整数 x，都有 $\textit{bits}[x]=\textit{bits}[x~\&~(x-1)]+1$

遍历从$ 1$ 到$ n$的每个正整数 $i$，计算的值。最终得到的数组$ \textit{bits}$即为答案。

# offer突击004

方法一：散列表unordered_map。用unordered_map遍历数组中每个数，并记录个数，然后取出其中计数为1的数。

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
	unordered_map<int,int> freq;
        for(int num : nums){
            ++freq[num];
        }
        for(auto [num,ooc]:freq){
            if(ooc==1){
               ans=num; 
                break;
            }
        }
        return ans;
};

```

方法二：由于数组里的数的数量除了1就是3，则若用二进制表示，每一位相加结果模3即为所要寻找的数对应位的值(0或1)。

```c++
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
```

# offer突击005

**解题思路**
使用二进制的思想，使用states[i]来存储words[i]对应的二进制值，words[i] [j] - 'a' 代表对应哪个位，最后用&的思想，相与为0说明两者没有相同字符

```c++
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
```

 # offer突击006

**解题思路**

双指针法：在使用双指针求解问题时，要求的数组往往是有序的，为什么需要有序呢？因为需要保证移动一个指针，答案的大小是落在目标范围内的。每次移动需要缩小搜索范围。

```c++
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
```

# offer突击007

解题思路

双指针法：三元的加法暴力解法是三种for循环，复杂度为$ O(n^3)$ ，但如果确定了三元中的某个值，只需要计算另外两个值，则又回到了题006的解法。若要使用双指针，则仍需要对原序列进行排序。

```c++
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
```
