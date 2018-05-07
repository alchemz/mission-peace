#include<bits/stdc++.h>
using namespace std;

vector<char> compress(vector<char>& chars){
  if(chars.size()==0) return {};
  if(chars.size()==1){
    chars.resize(2);
    chars[1]='1';
    return chars;
  }
  
  char c= chars[0];
  int ret=1, count=1;
  for(unsigned int i=1; i<chars.size(); i++){
    if(c==chars[i]) count++;
    else{
        if(count>=1){
        string s = to_string(count);
        for(auto ch: s){
          chars[ret++] = ch;
        }
      }
      c=chars[i], count=1;
      chars[ret++]=c;
    }
  }
  if(count>=1){
    string s=to_string(count);
    for(auto ch: s)
      chars[ret++]=ch;
  }
  
  chars.resize(ret);
  return chars;
}

int main(){
  vector<char> test={'r'};
  compress(test);
  for(unsigned int i=0; i<test.size(); i++)
    cout<<test[i];
  return 0;
}
