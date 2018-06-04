template<typename T>
T myMax(T x, T y){
	return (x>y)? x:y;
}

int main(){
	cout<<myMax<int>(3,7)<<endl;
}
//how does generic work: pass data type as a parameter 