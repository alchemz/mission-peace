#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string res="";
    //get hours
    int h1 = (int)s[0] - '0';
    int h2 = (int)s[1] - '0';
    int hh = h1*10 + h2%10;
    //AM
    if(s[8]=='A'){
        if(hh==12){
            res="00";
            for(int i=2; i<=7; i++){
                res +=(s[i]);
            }
        }
        else{
            for(int i=0; i<=7; i++){
                res +=(s[i]);
            }
        }
    }
    //PM
    else{
       if(hh==12){
           res="12";
           for(int i=2; i<=7; i++){
               res +=(s[i]);
           }
       }
        else{
            hh= hh+12;
            res=to_string(hh);
            for(int i=2; i<=7; i++){
               res+=(s[i]);
            }
        }
    } 
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
