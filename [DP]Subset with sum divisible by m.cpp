// C++ program to check if there is a subset
// with sum divisible by m.
#include <bits/stdc++.h>
using namespace std;

bool modularSum(vector<int> arr, int n, int m)
{
	if (n > m) return true;

    vector<bool> DP(m, false);

	for (int i=0; i<n; i++){
		if (DP[0])
			return true;

		vector<bool> temp(m, false);

		for (int j=0; j<m; j++){
			if (DP[j] == true){
				if (DP[(j+arr[i]) % m] == false){
					temp[(j+arr[i]) % m] = true;
				}
			}
		}

		for (int j=0; j<m; j++){
			if (temp[j]){
				DP[j] = true;
			}
		}
		DP[arr[i]%m] = true;
	}

	return DP[0];
}


int main()
{
	vector<int>arr = {1, 7};
	int n =arr.size();
	int m = 5;

	modularSum(arr, n, m) ? cout << "YES\n" :
							cout << "NO\n";

	return 0;
}
