class StringIterator {
public:
    StringIterator(string compressedString) {
        s = compressedString;
        n = s.size();
        i = 0;
        cnt = 0;
        c = ' ';
    }
    
    char next() {
        if (hasNext()) {
            --cnt;
            return c;
        }
        return ' ';
    }
    
    bool hasNext() {
        if (cnt > 0) return true;
        if (i >= n) return false;
        c = s[i++];
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            cnt = cnt * 10 + s[i++] - '0';
        }
        return true;
    }

private:
    string s;
    int n, i, cnt;
    char c;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
