//https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
#include <bits/stdc++.h>

using namespace std;
/*
cde, abc
只能通过删除的修改方法，使两个string变成一样
logic: 创造一个size 26的数组，代表26个字母出现的频率
string a: cde
string b: abc
1. ch=c, 'c'-'a'=2, [2]: +1, 代表有一个c
2. ch=d, 'd'-'a'=3, [3]：+1, 代表有一个d
3. ch=e, 'e'-'a'=4, [4]: +1, 代表有一个e
4. ch=a, 'a'-'a'=0, [0]: -1, 代表有一个a
5, ch=b, 'b'-'a'=1, [1], -1, 代表有一个b
6, ch=c, 'c'-'a'=2, [2], [2]原本已经记录了一个c, 1+(-1)=0
除了已经抵消的相同的c, 其他剩下的频率相加就是一共需要修改的次数, 1+1+abs(-1)+abs(-1)
*/
int make_anagrams(string a, string b){
    vector<int> freq(26, 0);
    int count=0;
    for(auto ch: a) ++freq[ch-'a'];
    for(auto ch: b) --freq[ch-'a'];
    for(auto val: freq) count +=abs(val);
    return count;
}

int main()
{
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);
    cout<<make_anagrams(a, b);
    return 0;
}
