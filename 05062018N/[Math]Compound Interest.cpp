#include<stdio.h>
#include<math.h>
 
void main()
{
    float p,r,t,ci;
    printf("Enter Principle, Rate and Time: ");
    scanf("%f%f%f",&p,&r,&t);
    ci=p*pow((1+r/100),t);
    
    printf("Bank Loans Compound Interest = %f%",ci);
}
Compound Interest = Principle * (1 + Rate / 100)^time
//https://www.thecrazyprogrammer.com/2013/02/c-program-to-calculate-compound-interest.html