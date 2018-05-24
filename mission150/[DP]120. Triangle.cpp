/*
bottom-up approach
初始化为最后一层，minSum: {4,1,8,3}
从倒数第二层开始加起，layer(n-2):{6,5,7}
min(4,1)-->1 + t[2][0]=7, 
*/
int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    vector<int> minSum(triangle.back());
    for(int layer=n-2; layer>=0; layer--){
        for(int i=0; i<=layer; i++){
            minSum[i] = min(minSum[i], minSum[i+1]) + triangle[layer][i];        
        }
    }
    return minSum[0];
}
int main()
{
  vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
  cout<<minimumTotal(triangle);
}