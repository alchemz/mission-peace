#include<bits/stdc++.h>
using namespace std;
string alienOrder(vector<string>& words) {  
       unordered_map<char, set<char>> outbound;  
       unordered_map<char, set<char>> inbound;  
    set<char> no_pre;  
      
    string s = "";  
    for(unsigned i =0; i< words.size(); i++) {  
      string t = words[i];  
      no_pre.insert(t.begin(), t.end());  
      for(unsigned j = 0; j< min(s.size(), t.size()); j++) {  
        if(t[j] != s[j]) {  
          inbound[t[j]].insert(s[j]);  
          outbound[s[j]].insert(t[j]);  
          break;  
        }  
      }  
      s = t;  
    }  
      
   // get the nodes which has 0 inbound edge  
    int char_count = no_pre.size();  
    for(auto p : inbound) {  
      no_pre.erase(p.first);  
    }  
      
    string result = "";  
    while(no_pre.size() >0) {  
      auto it = no_pre.begin();  
      char c = *it;  
      no_pre.erase(c);  
      result+=c;  
        
      for(char su : outbound[c]) {  
        inbound[su].erase(c);  
        if(inbound[su].size() == 0) {  
          no_pre.insert(su);  
        }  
      }  
        
    }   
       return (int)result.size() == char_count? result : "";  
}  

int main()
{
  vector<string> v={"wrt","wrf","er","ett","rftt"};
  cout<<alienOrder(v);
  return 0;
}
