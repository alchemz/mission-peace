//mutex example: phone booth with door handle
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m;
int i=0;
void makeACallFromPhoneBooth(){
	m.lock(); 
	cout<<"Man "<<i<<": Hello, my dear"<<endl;
	i++;
	m.unlock();
}

int main(){
	thread man1(makeACallFromPhoneBooth);
	thread man2(makeACallFromPhoneBooth);
	thread man3(makeACallFromPhoneBooth);

	man1.join();
	man2.join();
	man3.join();

	return 0;
}