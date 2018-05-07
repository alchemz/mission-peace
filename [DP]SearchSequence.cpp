struct HashTuple{
	size_t operator()(const tuple<int, int, int>& t) const{
		return hash<int>()(get<0>(t) ^ get<1>(t) * 1021 ^ get<2>(t) *1048573);
	}
};

bool IsPatternAtXY(const vector<vector<int>> &gird,
					int x, int y, const vector<int> &pattern, int offset,
					unordered_set<tuple<int, int, int>, HashTuple> *previous_attempt){
	if(pattern.size() == offset){
		return true;
	}
	if(x<0 || x>=grid.size() || y<0 || y>=grid[x].size()
		||previous_attempt->find({x,y, offset}) != previous_attempt->cend()){
		return false;
	}

	if(grid[x][y]==pattern[offset]&&
		(IsPatternAtXY(grid, x-1, y, pattern, offset+1, previous_attempt)||
		IsPatternAtXY(grid, x+1, y, pattern, offset+1, previous_attempt)||
		IsPatternAtXY(grid, x, y-1, pattern, offset+1, previous_attempt)||
		IsPatternAtXY(grid, x, y+1, pattern, offset+1, previous_attempt))){
			return true;
		}
		previous_attempt->emplace(x, y, offset);
		return false;
}

bool IsPattern(const vector<vector<int>>& grid,
				const vector<int>& pattern){
	unordered_set<tuple<int, int, int>, HashTuple> previous_attempt;
	for(int i=0; i<grid.size(); i++){
		for(int j=0; j<grid[i].size(); j++){
			if(IsPatternAtXY(grid, i, j, pattern, 0, &previous_attempt)){
				return true;
			}
		}
	}

	return false;
}