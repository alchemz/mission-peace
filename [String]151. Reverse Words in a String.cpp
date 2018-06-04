/*
1. 从字符串的后面往前读，首先解决最后面的空格问题
2. 插入第一个词以后，新插入词之前加上空格
3. 空格之后，加上这个词
*/
class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int right=s.size();
        for(int i=right-1; i>=0; i--){
            //从后往前，先解决空格
            if(s[i]==' ')
                right=i;
            else if(i==0 || s[i-1]==' '){
                if(!res.empty()) //插入第一个词后，每个后面跟一个空格
                    res.append(" ");
                res.append(s.substr(i, right-i));//空格之后，加上这个词。
            }
        }
        s=res;
    }
};

/*
"the sky",
right=7, i=6, y
right=7, i=5, k
right=7, i=4, s, s[i-1]=' ', res.append(s.substr(4, 3)), [4][5][6]三个字符"sky"
right=7. i=3, ' ', right=3
right=3, i=2, e
right=3, i=1, h
right=3, i=0, !res.empty(), res.append(" ");
res.append(s.subtr(0,3)), [0][1][2], 三个字符"the"

res="sky the"
right记录有效字符出现的右边第一个index, i表示右边开始有效字符出现的最后一个index
*/