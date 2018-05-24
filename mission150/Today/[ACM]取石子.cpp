#include <stdio.h>  
#include <math.h>  
int main()  
{  
    int a,b,k;  
    double eqa = (1+sqrt(5.0))/2.0;  
    while( scanf("%d%d",&a,&b)!=EOF )  
    {  
        // 当a>b时，交换a,b的值，当然你也可以用一个中间变量来交换a,b值  
        if( a > b )  
        {  
            a^=b;  
            b^=a;  
            a^=b;  
        }  
        k=b-a;  
        if( int( k*eqa )==a )  printf("0\n");  
        else    printf("1\n");  
    }  
    return 0;  
}  