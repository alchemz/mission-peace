class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int counter=n;
        vector<int> range(n);
        for(int i=0; i<n; i++)  range[i]=i;
        for(auto a: edges){
            int x=find(range, a.first), y=find(range, a.second);
            if(x!=y){
                counter--;
                range[y]=x;
            }
        }
        return counter;
    }
    
    int find(vector<int>& range, int i){
        while(range[i]!=i)  i=range[i];
        return i;
    }
};

/*
初始状态是，range[i]表示节点i属于group i，每个节点都是单独的区间
遍历所有的edge, 对于一条边的两个点，起始时在range中值不相同，将counter减一，
表示减少一个连通区域。并且更新其中一个节点的range值
这样，相同连通区域的节点range值都是一样的。
不同连通区域，range值不一样。
*/