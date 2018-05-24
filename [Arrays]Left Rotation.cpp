/*
https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
*/
#include <bits/stdc++.h>

using namespace std;

// void leftRotationOne(vector<int>&arr, int length){
//     int tmp = arr[0];
//     int i;
//     for(i=0; i<length-1; i++){
//         arr[i]=arr[i+1];
//     }
//     arr[i]=tmp;
// }
// void leftRotation(vector<int>&arr, int length, int numRotations){
//     for(int i=0; i<numRotations; i++){
//         leftRotationOne(arr, length);
//     }
// }

vector<int> leftRotation(vector<int> arr, int n, int k){
    vector<int> b(n);
    for(size_t i=0; i<n; i++){
        b[i] = arr[(i+k)%n];
    }
    return b;
}
int main()
{
    int n;
    int k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int> b(n);
    b=leftRotation(a, n, k);
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }
    return 0;
}

