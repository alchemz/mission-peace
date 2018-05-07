bool matchedParatheses(const string &s){
	stack<char> left_chars;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='(' || s[i]=='['|| s[i]=='{'){
			left_chars.emplace(s[i]);
		}else{
			if(left_chars.empty()){
				return false;
			}
			if((s[i]==')' && left_chars.top()!='(')||
				(s[i]==']' && left_chars.top()!='[')||
				(s[i]=='}' && left_chars.top()!='}')){
				return false;//mismatched
			}
			left_chars.pop();
		}
	}
	return left_chars.empty();
}