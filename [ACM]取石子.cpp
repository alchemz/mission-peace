/*
两堆石子(m,n)，两个人A和B，每次只能取(0,k)或者(k,0)或者(k,k)，
其中k<=min(m,n)。求问如果A先取，A有没有必胜策略。
*/
//===============> 取一堆石子
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


//===============> 取两堆石子
#include <stdio.h>  
#include <math.h>  
int main()  
{  
    int a,b,i,k,m,n;  
    double eqa = (1+sqrt(5.0))/2.0;  
    while( scanf("%d%d",&a,&b)!=EOF && (a||b) )  
    {  
        // 当a>b时，交换a,b的值，当然你也可以用一个中间变量来交换a,b值  
        if( a > b )  
        {  
            a^=b;  
            b^=a;  
            a^=b;  
        }  
        k=b-a;  
        if( int(k*eqa)==a )  printf("0\n");  
        else  
        {  
            printf("1\n");  
            for(i=1; i<=a; ++i)  
            {  
                n=a-i,m=b-i;  
                if( int(k*eqa) == n )  
                    printf("%d %d\n",n,m);  
            }  
            for(i=b; i>=0; --i)  
            {  
                n=a,m=i;  
                if( n > m )  
                {  
                    n^=m;  
                    m^=n;  
                    n^=m;  
                }  
                k=m-n;  
                if( int(k*eqa) == n )  
                    printf("%d %d\n",n,m);  
            }  
        }  
    }  
    return 0;  
}  