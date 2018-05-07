#include <iostream>
using namespace std;

int divide_numbers(int a, int b){
    if(b==0)
    {
        throw 1;
    }
            
    return a/b;
}

int main(){
    int a, b;
    a=1;
    b=0;
    try{
        cout<<divide_numbers(a,b);
    }
    catch(int& code){
        cout<<"Error code: "<<code;
    }
        
    return 0;
}
