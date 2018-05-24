/*
palindrome partition
需要三个部分
main function, 
helper function
bool isPalindrome

logic:
遍历字符串，判断substr(0, i)是palindrome, 
如果是，recursive call dfs() on the rest of string, subtr(i+1, length)
当遍历到end of string, 加入当前的partition到res中

中间当检测到aa时候，发现是回文串，那么对于剩下的bc当做一个新串来检测
*/

vector<vector<string>> partition(string s){
	vector<vector<string>> res;
	if(s.empty())	return res;
	vector<string> out;
	helper(0, s, out, res);
}

void helper(int index, string& s, vector<string>&out, vector<vector<string>>&res){
	if(index==s.size()){
		res.push_back(out);
		return;
	}

	for(size_t i=index; i<s.size(); i++){
		if(isPalindrome(s, index, i)){
			out.push_back(s.substr(index, i-index+1));
			helper(i+1, out, res);
			out.pop_back();
		}
	}
}
bool isPalindrome(const string& s, int start, int end){
	while(start <= end){
		if(s[start++] != s[end--])
			return false;
	}
	return true;
}