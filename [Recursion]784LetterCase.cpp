#include<bits/stdc++.h>
using namespace std;

void dfs(string& S, unsigned i, vector<string>& ans){
    if(i==S.length()){
        ans.push_back(S);
        return;
    }
    dfs(S, i+1, ans);
    if(!isalpha(S[i])) return;
    S[i] ^=(1<<5);
    dfs(S, i+1, ans);
    S[i] ^=(1<<5);
}
    
vector<string> letterCasePermutation(string S){
    vector<string> ans;
    dfs(S, 0, ans);
    return ans;
}

int main(){
    string S="a1b2";
    vector<string> ans=letterCasePermutation(S);
    for(vector<string>::iterator i=ans.begin(); i!=ans.end(); ++i)
        cout<<*i<<" ";
    return 0;
}
