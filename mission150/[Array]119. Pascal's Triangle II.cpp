/*
https://leetcode.com/problems/pascals-triangle-ii/description/
杨辉三角
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle(rowIndex+1);
        for(int i=0; i<rowIndex+1; i++){
            triangle[i].resize(i+1);
            triangle[i][0]=1;
            triangle[i][i]=1;
            for(int j=1; j<i; j++){
                triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
            }
        }
        return triangle[rowIndex];
    }
};
//上面的可以简化成下面的一维数组
/*不断更新这个一维数组*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> triangle(rowIndex+1,0);
        triangle[0]=1;
        for(int i=1; i<rowIndex+1; i++){
            for(int j=i; j>=1; j--){
                triangle[j] +=triangle[j-1];
            }
        }
        return triangle;
    }
};