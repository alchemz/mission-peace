// CPP code to implement ternary operator
#include <bits/stdc++.h>
 
// Function to implement ternary operator without 
// conditional statements
int ternaryOperator(int a, int b, int c) 
{
    // If a is true, we return (1 * b) + (!1 * c) i.e. b
    // If a is false, we return (!1 * b) + (1 * c) i.e. c
    return ((!!a) * b + (!a) * c);
}
 
// Driver code
int main()
{
    int a = 1, b = 10, c = 20;
     
    // Function call to output b or c depending on a
    std::cout << ternaryOperator(a, b, c) << '\n';
 
    a = 0;
     
    // Function call to output b or c depending on a
    std::cout << ternaryOperator(a, b, c);
     
    return 0;
}
