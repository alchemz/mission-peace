class Vector2D {
private:
    vector<vector<int>>::iterator x, end;
    int y=0;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        x=vec2d.begin();
        end=vec2d.end();
    }

    int next() {
        return (*x)[y++];
    }

    bool hasNext() {
        while(x!=end && y==(*x).size()){
            ++x;
            y=0;
        }
        return x!=end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
