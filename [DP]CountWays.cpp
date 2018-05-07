/*
Given a 2D array, count the number of ways starting top left to bottom right
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int CountWays(int m, int n){
	vector<vector<int>> T(m, vector<int>(n,0));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
		    if(i==0){
		        T[i][j]=1;
		    }
		    else if(j==0){
		        T[i][j]=1;
		    }
		    else{
		        T[i][j]= T[i-1][j]+T[i][j-1];
		    }
		}
	}

	return T[m-1][n-1];
}

int ComputerNumberOfWays(int x, int y, vector<vector<int>> *T_ptr){
    if(x==0 && y==0){
        return 1;
    }
    
    vector<vector<int>> &T = *T_ptr;
    if(T[x][y]==0){
        int ways_top =
        x==0 ? 0:ComputerNumberOfWays(x-1, y, T_ptr);
        
        int ways_left =
        y==0 ? 0:ComputerNumberOfWays(x, y-1, T_ptr);
        
        T[x][y]= ways_left + ways_top;
    }
    
    return T[x][y];
}
int NumberOfWays(int m, int n){
    vector<vector<int>> T(m, vector<int>(n, 0));
    
    return ComputerNumberOfWays(m-1, n-1, &T);
}


int main(){
    int m=5, n=5;
    cout<<CountWays(5,5);
    
    return 0;
}