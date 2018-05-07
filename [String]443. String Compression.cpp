class Solution {
public:
    int compress(vector<char>& chars){
        //corner case
        if(chars.size()<2) return chars.size();
        //find dups
        char c=chars[0];
        int ret=1, count=1;
        for(int i=1; i<chars.size(); i++){
            if(c==chars[i]) count++;
            else{
                    if(count>1){
                        string s=to_string(count);
                        for(auto ch:s)
                        {
                            chars[ret++]=ch;
                        }
                    }
                //find next, i=1
                c=chars[i], count=1;
                chars[ret++]=c;
                }
        }
        //check again
        if(count>1){
            string s=to_string(count);
            for(auto ch:s){
                chars[ret++]=ch;
            }
        }
        //resize
        chars.resize(ret);
        return ret;
        }
};

/*
压缩字符串 in place
输入："a","a","b","b","c","c","c"
输出： a2b2c3, 6

https://leetcode.com/problems/string-compression/description/
*/