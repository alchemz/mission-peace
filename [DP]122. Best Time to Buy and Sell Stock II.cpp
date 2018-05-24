/*
时间复杂度: O(n)
空间复杂度: O(1)

int maxProfit(vector<int>& prices) {
    int maxP = 0;
    int days = prices.size();
    if(days < 1)    return 0;
    for(int i=1; i<days; i++){
        if(prices[i]-prices[i-1]>0){
            maxP += prices[i]-prices[i-1];
        }else{
            continue;
        }
    }
    return maxP;
}
*/
/*
也可以写成下面的形式，买进的标准是，只要赚钱，profit>0
size_t could be any of unsigned char, unsigned short, unsigned int, unsigned long or unsigned long long
size_t用来specify the size of something, especially compare in the loop
*/
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int maxP=0;
        const size_t days=prices.size();
        if(days<1)  return 0;
        for(size_t i=1; i<days; i++){
            maxP += max(prices[i] - prices[i-1], 0);
        }
        return maxP;
    }
};