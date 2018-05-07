/*
Edit words
insert, delete, substitude
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ComputeDistance(const string& A, int A_idx, const string& B, int B_idx, vector<vector<int>>* distance_ptr){
	vector<vector<int>>& distance=*distance_ptr;
	if(A_idx <0){
		return B_idx+1;
	}
	else if(B_idx<0){
		return A_idx+1;
	}
	if(distance[A_idx][B_idx]==-1){
		if(A[A_idx]==B[B_idx]){
			distance[A_idx][B_idx]=ComputeDistance(A, A_idx-1, B, B_idx-1, distance_ptr);
		}else{
			int substitude_last = ComputeDistance(A, A_idx-1, B, B_idx-1, distance_ptr);

			int add_last = ComputeDistance(A, A_idx-1, B, B_idx, distance_ptr);

			int delete_last = ComputeDistance(A, A_idx, B, B_idx-1, distance_ptr);

			distance[A_idx][B_idx]= 1+ min({substitude_last, add_last, delete_last});
		}
	}

	return distance[A_idx][B_idx];
}

int WordDistance(const string& A, const string& B){
	int m=A.size(), n=B.size();
	vector<vector<int>> distance(m, vector<int>(n, -1));
	return ComputeDistance(A, m-1, B, n-1, &distance);
}

int main(){
    const string s1="Saturday", s2="Sundays";
    cout<<WordDistance(s1, s2);
    
    return 0;
}