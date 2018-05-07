class Solution {
public:
    bool isMatch(string s, string p) {
        int sz1 = s.size(), sz2 = p.size();
        vector<vector<bool>> A(sz1 + 1, vector<bool>(sz2 + 1, false));
        A[0][0] = true;
        for (int i = 0; i <= sz1; ++i) {
            for (int j = 1; j <= sz2; ++j) {
                if (p[j - 1] == '*') {
                    for (int k = 0; k <= i; ++k) {
                        if (A[k][j - 1]) {
                            A[i][j] = true;
                            break;
                        }
                    }
                }
                else if (i > 0 and p[j - 1] == '?') {
                    A[i][j] = A[i - 1][j - 1];
                }
                else if (i > 0 and s[i - 1] == p[j - 1]) {
                    A[i][j] = A[i - 1][j - 1];
                }
            }
        }
        return A[sz1][sz2];
    }
};

//https://github.com/yuanhui-yang/LeetCode/blob/master/Algorithms/wildcard-matching.cpp
int main(void) {
    Solution solution;
    string s, p;
    bool answer, result;

    s = "";
    p = "*";
    result = solution.isMatch(s, p);
    cout << boolalpha << result << '\n';
    
    return 0;
 }
