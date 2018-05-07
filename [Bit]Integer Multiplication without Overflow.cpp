/*
 一个32bit最后两位分别表示0.5 和0.25， 前面的30位依次顺移，分别表示2^29~2^0，
 问怎么实现这种数据type的乘法，怎么解决overflow的问题
*/

#include<bits/stdc++.h>
using namespace std;
 
// Function for multiplication
int multiply(int n, int m)
{  
    int ans = 0, count = 0;
    while (m)
    {
        // check for set bit and left 
        // shift n, count times
        if (m % 2 == 1)              
            ans += n << count;
 
        // increment of place value (count)
        count++;
        m /= 2;
    }
    return ans;
}
 
// Driver code
int main()
{
    int n = 20 , m = 13;
    cout << multiply(n, m);
    return 0;
}

//假设我有两个64位整数这样声明：
uint64_t a = xxx, b = yyy; 
//检测：
x = a * b;
if (a != 0 && x / a != b) {
    // overflow handling
}
//计算进位相当牵连。一种方法是将两个操作数拆分为半字，然后将long multiplication应用于半字：

uint64_t hi(uint64_t x) {
    return x >> 32;
}

uint64_t lo(uint64_t x) {
    return ((1L << 32) - 1) & x;
}

void multiply(uint64_t a, uint64_t b) {
    // actually uint32_t would do, but the casting is annoying
    uint64_t s0, s1, s2, s3; 

    uint64_t x = lo(a) * lo(b);
    s0 = lo(x);

    x = hi(a) * lo(b) + hi(x);
    s1 = lo(x);
    s2 = hi(x);

    x = s1 + lo(a) * hi(b);
    s1 = lo(x);

    x = s2 + hi(a) * hi(b) + hi(x);
    s2 = lo(x);
    s3 = hi(x);

    uint64_t result = s1 << 32 | s0;
    uint64_t carry = s3 << 32 | s2;
}
//https://codeday.me/bug/20171124/100202.html