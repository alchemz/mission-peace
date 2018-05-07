#include<bits/stdc++.h>
using namespace std;

bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        
        unordered_map<string, unordered_set<string>> similar_words;
        for (const auto& pair : pairs) {            
            similar_words[pair.first].insert(pair.second);
            similar_words[pair.second].insert(pair.first);
        }
        
        for (unsigned i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            if (!similar_words[words1[i]].count(words2[i])) return false;
        }
        
        return true;
}

int main(){
    vector<string> w1={"great"};
    vector<string> w2={"fine"};
    vector<pair<string,string>> pairs={{"great", "fine"},{"acting","drama"}};
    if(areSentencesSimilar(w1, w2, pairs))
        cout<<"matched";
    return 0;
}
    
