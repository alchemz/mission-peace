#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginW, string endW, vector<string>& wordList){
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if(!dict.count(endW)) return 0;
    
    queue<string> q;
    q.push(beginW);
    
    int l=beginW.length();
    int step=0;
    
    while(!q.empty()){
        ++step;
        for(int size=q.size(); size>0; size--){
            string w=q.front();
            q.pop();
            for(int i=0; i<l; i++){
                char ch=w[i];
                for(int j='a'; j<='z'; j++){
                    w[i]=j;
                    if(w==endW) return step+1;
                    if(!dict.count(w)) continue;
                    dict.erase(w);
                    q.push(w);
                }
                w[i]=ch;
            }
        }
    }
    return 0;
}

int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());        
        if (!dict.count(endWord)) return 0;
        
        int l = beginWord.length();
        
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
                
        int step = 0;
        
        while (!q1.empty() && !q2.empty()) {
            ++step;
            
            // Always expend the smaller queue first
            if (q1.size() > q2.size())
                std::swap(q1, q2);
                        
            unordered_set<string> q;
            
            for (string w : q1) {
                for (int i = 0; i < l; i++) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (!dict.count(w)) continue;                        
                        dict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            
            std::swap(q, q1);
        }
        
        return 0;
}

int main(){
    string b="hit";
    string e="cog";
    const char* s[]={"hot","dot","dog","lot","log","cog"};
    vector<string> vec(s, s+sizeof(s)/sizeof(s[0]));
    cout<<"The number of path is: "<<ladderLength(b, e, vec);
    return 0;
}
    
