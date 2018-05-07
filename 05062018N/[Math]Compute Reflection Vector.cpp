/*Given a vector i and a normal vector n, compute the reflection vector.
Formula:
R = i - 2(i· n)n;
i· n is the dot product

*/
int dotProduct(const vector<int> &A, const vector<int> &B)
{
 
    int product = 0;
 
    // Loop for calculate cot product
    for (int i = 0; i < n; i++)
        product = product + vect_A[i] * vect_B[i];
    return product;
}
 
 void reflectV(vector<int> &out, vector<int> &i, vector<int> &n){
 	i_dot_n = dotProduct(i, n);
 	out = i - 2*(i_dot_n)*n;
 }
 /*向量点积(Dot Product),向量叉积(Cross Product)
 https://blog.csdn.net/fox64194167/article/details/8147460
 */