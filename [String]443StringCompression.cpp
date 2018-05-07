#include<bits/stdc++.h>
using namespace std;

class StringCompress{
public:
    int compress(vector<char>& chars){
        //check null array
        if(chars.size()==0) return 0;
        
        //compare the first, next element
        char c=chars[0];
        int ret=1, count=1;
        for(unsigned i=1; i<chars.size(); i++){
            if(chars[i]==c) count++;
            else{
                if(count>1){
                    string s=to_string(count);
                    for(auto ch:s){
                        chars[ret++]=ch;
                    }
                }
                c = chars[i], count=1;
                chars[ret++]=c;
            }
        }
        if(count>1){
            string s=to_string(count);
            for(auto ch: s){
                chars[ret++]=ch;
            }
        }
        chars.resize(ret);
        cout<<chars.data()<<endl;
        return ret;
    }
};

int main()
{
    char arr[]={'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    vector<char> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    StringCompress c;
    cout<<c.compress(v);
    return 0;
}
