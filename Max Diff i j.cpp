/*
Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
*/
int maxDiff(int arr[], int n){
	int maxDiff=INT_MIN;
	int i, j;
	for(i=0; i<n; i++){
		for(j=n-1; j>i; j--){
			if(arr[j]>arr[i]&&maxDiff<(j-i))
				maxDiff=j-i;
		}
	}
	return maxDiff;
}

//time: O(n^2)

int maxDiff(int arr[], int n){
	int maxDiff;
	int i, j;
	vector<int> l_min;
	vector<int> r_max;
	l_min[0]=arr[0];
	for(i=1; i<n; i++){
		l_min[i]=min(arr[i], l_min[i-1]);
	}

	r_max[n-1]=arr[n-1];
	for(j=n-2; j>=0; j--){
		r_max[j]=max(arr[j], r_max[j+1]);
	}

	i=0, j=0, maxDiff=INT_MIN;
	while(j<n && i<n){
		if(l_min[i]<r_max[j]){
			maxDiff=max(maxDiff, j-i);
			j++;
		}else{
			i++;
		}
	}
	return maxDiff;
}