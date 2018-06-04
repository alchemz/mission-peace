bool isOperator(char c){
	switch(x){
		case '+':
		case '-':
		case '/':
		case '*':
			return true;
	}
	return false;
}

string preToPost(string pre_exp){
	stack<string> st;
	int len=pre_exp.size();
	for(size_t i=len-1; i>=0; i--){ //read from reverse order
		if(isOperator(pre_exp[i])){ //is operatorm 取出两个operand, 一个operator
			string op1=st.top(); st.pop();
			string op2=st.top(); st.pop();
			string temp = op1+op2+pre_exp[i];
			st.push(temp);
		}
		else{
			st.push(string(1, pre_exp[i]));//is operand, push into stack
		}
	}
	return s.top();
}
/*
eg *+AB-CD
Read the Prefix expression in reverse order (from right to left)
从最后一位开始读
如果是operand, 
压入栈, D
压入栈, C
如果是operator
取出栈顶, op1=C, op2=D
temp = C+D+'-'
压入栈temp
同理压入栈A+B+'+'
最后一次, 
op1=AB+, op2=CD-
temp=AB+CD-*
*/