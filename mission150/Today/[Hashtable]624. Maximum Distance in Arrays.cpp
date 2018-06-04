class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res=0, start=arrays[0][0], end=arrays[0].back();
        for(size_t i=1; i<arrays.size(); i++){
            res=max(res,max(abs(arrays[i].back()-start),
                           abs(end-arrays[i][0])));
            start=min(start, arrays[i][0]);
            end=max(end, arrays[i].back());
        }
        return res;
    }
};

/*
注意每个level的array都是sorted
用start记录每层最小的数
用end记录每层最大的数
取不同层首位的差值abs(arrays[i].back()-start)
abs(arrays[i][0]-end)
取其中大的值记录下来。更新res
*/