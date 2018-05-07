#include <iostream>
#include <algorithm>
using namespace std;

void reverseWords(string &s) {
    int size=s.size();
    if(size==0||s.empty())
    {
        return;
    }
    reverse(s.begin(),s.end());
    int storeIdx=0;
    for(int i=0;i<size;++i)
    {
        if(s[i]!=' ')
        {
            if(storeIdx!=0)
            {
                s[storeIdx++]=' ';
            }
            int next_=i;
            while(next_<size&&s[next_]!=' ')
            {
                s[storeIdx++]=s[next_++];
            }
            reverse(s.begin()+storeIdx-(next_-i),s.begin()+storeIdx);//reverse each words
            i=next_;
        }
    }
    s.resize(storeIdx);
}
int main() {
    string s="the sky is blue";
    reverseWords(s);
    cout<<s;
    return 0;
}

/*
先reverse整个string, 然后reverse每个单词。
index表示当前储存到的位置

https://leetcode.com/problems/reverse-words-in-a-string/description/
*/
