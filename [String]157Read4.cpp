http://www.cnblogs.com/grandyang/p/5174322.html
int read4(char *buf);

class Solution{
public:
	int read(char *buf, int n){
		int res=0;
		for(int i=0; i<=n; i++){
			int curr=read4(buf+res);
			if(curr==0) break;
			res+=cur;
		}
		return min(res, n);
	}
};
