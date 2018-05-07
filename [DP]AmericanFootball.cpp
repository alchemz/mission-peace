/*
American football game
safety: 2 pts
filed goal: 3 pts
touchdown: 7 pts

Write a program that takes a final score, and returns the number of combo
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int NumComb(int score, const vector<int> &plays){
	int size_ = plays.size();
	vector<vector<int>> all_comb(size_, vector<int>(score+1, 0));

	for(int i=0; i<size_; i++){
		all_comb[i][0]=1;//0分
		for(int j=1; j<=score; j++){
			int without_play= 
			i>=1 ? all_comb[i-1][j]:0; //above
			
			int with_play = 
			j>=plays[i] ? all_comb[i][j-plays[i]]:0;//left
			
			all_comb[i][j]=without_play + with_play;
		}
	}

	return all_comb.back().back();//all_comb[size_-1][score]
}

int main(){
    vector<int> plays={2,3,7};
    cout<<NumComb(12, plays);
    
    return 0;
}
//time: O(sn) space:O(sn)