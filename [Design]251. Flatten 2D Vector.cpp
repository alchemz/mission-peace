class Vector2D {
private:
    vector<vector<int>>::iterator x, end;
    int i=0;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        x=vec2d.begin();
        end=vec2d.end();
    }

    int next() {
        return (*x)[i++];
    }

    bool hasNext() {
        while(x!=end && i==(*x).size()){
            ++x;
            i=0;
        }
        return x!=end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

 /*
sol: http://www.cnblogs.com/grandyang/p/5209621.html
lc: https://leetcode.com/problems/flatten-2d-vector/description/
 */