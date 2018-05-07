#include<bits/stdc++.h>
using namespace std;

pair<string, double>& find(const string& C, unordered_map<string, pair<string, double>>& parents) {        
        if (C != parents[C].first) {
            const auto& p = find(parents[C].first, parents);
            parents[C].first = p.first;
            parents[C].second *= p.second;
        }        
        return parents[C];
}
vector<double> calcEquation(const vector<pair<string, string>>& equations, vector<double>& values, const vector<pair<string, string>>& queries) {
        
        // parents["A"] = {"B", 2.0} -> A = 2.0 * B
        // parents["B"] = {"C", 3.0} -> B = 3.0 * C
        unordered_map<string, pair<string, double>> parents;
 
        for (unsigned i = 0; i < equations.size(); ++i) {
            const string& A = equations[i].first;
            const string& B = equations[i].second;
            const double k = values[i];
            // Neighter is in the forrest
            if (!parents.count(A) && !parents.count(B)) {
                parents[A] = {B, k};
                parents[B] = {B, 1.0};
            } else if (!parents.count(A)) {
                parents[A] = {B, k};
            } else if (!parents.count(B)) {
                parents[B] = {A, 1.0 / k};
            } else {
                auto& rA = find(A, parents); 
                auto& rB = find(B, parents);
                if (rA != rB) {
                    rA.first = rB.first;
                    rA.second *= (k * rB.second);
                }
            }
        }
        
        vector<double> ans;
        for (const auto& pair : queries) {
            const string& X = pair.first;
            const string& Y = pair.second;
            if (!parents.count(X) || !parents.count(Y)) {
                ans.push_back(-1.0);
                continue;
            }
            auto& rX = find(X, parents); // {rX, X / rX}
            auto& rY = find(Y, parents); // {rY, Y / rY}
            if (rX.first != rY.first)
                ans.push_back(-1.0);
            else // X / Y = (X / rX / (Y / rY))
                ans.push_back(rX.second / rY.second);
        }
        return ans;
}



int main(){
    vector<pair<string, string>> equations= { {"a", "b"}, {"b", "c"} };
    vector<double> values={2.0, 3.0};
    vector<pair<string, string>> queries={ {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
    vector<double> ans=calcEquation(equations, values, queries);
    for(vector<double>::iterator i=ans.begin(); i!=ans.end(); i++)
        cout<<*i<<" ";
    return 0;
}
    
