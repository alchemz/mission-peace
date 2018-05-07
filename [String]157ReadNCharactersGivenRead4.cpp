// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res=0;
        for(int i=0; i<=n; i++){
            int cur = read4(buf+res);
            if(cur==0) break;
            res += cur;
        }
        return min(res, n);//返回准确的当前剩余的字符数
    }
};

//http://www.cnblogs.com/grandyang/p/5174322.html
//https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/description/
