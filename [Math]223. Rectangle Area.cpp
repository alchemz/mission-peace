#include<bits/stdc++.h>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int sum = (C - A) * (D - B) + (H - F) * (G - E);
    if (E >= C || F >= D || B >= H || A >= G) return sum;
    return sum - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F)));
}

int main()
{
    int A=-3, B=0;
    int C=3, D=4;
    int E=0, F=-1;
    int G=9, H=2;
    cout<<computeArea(A, B, C, D, E, F, G, H);
 
    return 0;
}
