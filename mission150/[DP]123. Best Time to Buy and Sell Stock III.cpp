/*
时间复杂度为O(n^3)，time limit exceeded
*/
//     int maxProfit(vector<int>& prices){
//         size_t k =2;
//         size_t days=prices.size();
//         if(k==0 || days==0) return 0;

//         vector<vector<int>> T(k+1, vector<int>(days, 0));
//         for(size_t i=1; i<T.size(); i++){
//             for(size_t j=1; j<T[0].size(); j++){
//                 int maxVal=0;
//                 for(size_t m=0; m<j; m++){
//                     maxVal = max(maxVal, prices[j]-prices[m] + T[i-1][m]); //daym和dayj差价+上个tran在daym的利润
//                 }
//                 T[i][j] = max(T[i][j-1], maxVal);
//             }
//         }

//         return T[k][days-1];
//     }
//改良后：时间复杂度为O(n^2)
/*
Tushar
将(prices[j]-prices[m] + T[i-1][m]), 简化成 prices[j]+maxDiff. maxDiff = T[i-1][j]-prices[j]
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t k=2;
        size_t days=prices.size();
        if(k==0 || days==0) return 0;
        
        vector<vector<int>> T(k+1, vector<int>(days,0));
        for(size_t i=1; i<T.size(); i++){
            int maxDiff = -prices[0];
            for(size_t j=1; j<T[0].size(); j++){
                T[i][j]=max(T[i][j-1], prices[j]+maxDiff);
                maxDiff = max(maxDiff, T[i-1][j]-prices[j]);
            }
        }
        return T[k][days-1];
    }

};

