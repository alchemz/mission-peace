/*
efficient compute binomial coefficient
(n,k)=(n-1, k) + (n-1, k-1)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ComputeXChooseY(int x, int y, vector<vector<int>> *choose_ptr){
	if(y==0 || x==y){
		return 1;
	}
	vector<vector<int>> &x_choose_y=*choose_ptr;
	if(x_choose_y[x][y]==0){ //not visited
		int base1=ComputeXChooseY(x-1, y, choose_ptr);
		int base2=ComputeXChooseY(x-1, y-1, choose_ptr);

		x_choose_y[x][y]=base1+base2;
	}

	return x_choose_y[x][y];
}

int BinomialCoefficient(int n, int k){
	vector<vector<int>> x_choose_y(n+1, vector<int>(k+1, 0));

	return ComputeXChooseY(n, k, &x_choose_y);
}

int main(){
    int m=5, n=5;
    cout<<BinomialCoefficient(5,2);
    
    return 0;
}
//time:O(nk) space O(nk)