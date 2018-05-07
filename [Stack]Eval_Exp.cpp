int Eval(const string& exp){
	stack<int> res;
	stringstream ss(exp);
	string token;
	const char delimiter='.';

	while(getline(ss, token, delimiter)){
		if(token=='+'||token=='-'||token=='*'||token=='/'){
			const int y = res.top();
			res.pop();
			const int x = res.top();
			res.pop();
			switch(token.front()){
				case '+':
					exp.emplace(x+y);
					break;
				case '-':
					exp.emplace(x-y);
					break;
				case '*':
					exp.emplace(x*y);
					break;
				case '/':
					exp.emplace(x/y);
					break;
			}
		}else{
			exp.emplace(stoi(token));
		}
	}
	return exp.top();
}