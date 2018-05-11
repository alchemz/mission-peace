/*
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

规律是: 
首位两行相邻两个元素的index之差跟行数是相关的，为 2*nRows - 2

之字型中间每个红色元素的位置为 j + 2*nRows-2 - 2*i, 其中，j为前一个黑色元素的列数，i为当前行数。
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <=1) return s;
        string res="";
        int size=2*numRows-2;
        
        for(int i=0; i<numRows; i++){
            for(int j=i; j<s.size(); j+=size){
                res += s[j];
                int tmp = j+size-2*i;
                if(i!=0 && i!= numRows -1 && tmp<s.size())
                    res += s[tmp];
            }
        }
        
        return res;
    }
};