/*
时间复杂度: O(n^2)
空间复杂度:O(1)
int maxProfit(vector<int>& prices) {
    int days = prices.size();
    int maxP = 0;
    for(int i=0; i<days; i++){
        int curP=0;
        for(int j=i+1; j<days; j++){
            if(prices[j]>prices[i]){
                curP = prices[j] - prices[i];
            }
            maxP = max(maxP, curP);
        }

    }
    return maxP;
}
*/
/*
改良后，时间复杂度为O(n), 空间复杂度为O(n)
int maxProfit(vector<int>& prices) {
    int days = prices.size();
    if(days<1)  return 0;
    vector<int> maxProfits(days);
    vector<int> minPrices(days);
    minPrices[0] = prices[0];
    maxProfits[0] = 0;
    for(int i=1; i<days; i++){
        minPrices[i] = min(minPrices[i-1], prices[i]);
        maxProfits[i]= max(maxProfits[i-1], prices[i]-minPrices[i]);

    }
    return maxProfits[days-1];
}
*/
/*
再改良一次，可以不用数组，只用两个变量记录当前最低价和最高利润
时间复杂度为O(n), 空间复杂度为O(1)
*/
class Solution {
public:
   int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if(days < 1)    return 0;
        int maxProfits = 0;
        int minPrices = prices[0];
        for(int i=1; i<days; i++){
            minPrices = min(minPrices, prices[i]);
            maxProfits= max(maxProfits, prices[i]-minPrices);

        }
        return maxProfits;
    } 
};