// Dynamic and Logarithm approach find probability of
// at least k heads
#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
 
// dp[i] is going to store Log ( i !) in base 2
double dp[MAX];
 
double probability(int k, int n)
{
    double ans = 0; // Initialize result
 
    // Iterate from k heads to n heads
    for (int i=k; i <= n; ++i)
    {
        double res = dp[n] - dp[i] - dp[n-i] - n;
        ans += pow(2.0, res);
    }
 
    return ans;
}
 
void precompute()
{
    // Preprocess all the logarithm value on base 2
    for (int i=2; i < MAX; ++i)
        dp[i] = log2(i) + dp[i-1];
}
 
// Drive code
int main()
{
    precompute();
 
    // Probability of getting 2 head out of 3 coins
    cout << probability(2, 3) << "\n";
 
    // Probability of getting 3 head out of 6 coins
    cout << probability(3, 6) << "\n";
 
    // Probability of getting 500 head out of 10000 coins
    cout << probability(500, 1000);
 
    return 0;
}
