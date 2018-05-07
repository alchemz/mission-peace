class Caculator {  
public:  
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {  
        unordered_map<string, int> eval;                // construct the map from evalvars to evalints  
        for (int i = 0; i < evalvars.size(); ++i) {  
            eval[evalvars[i]] = evalints[i];  
        }  
        auto resmp = helper(expression, eval);          // solve the problem  
        vector<string> res;                             // construct the results  
        for (auto param : resmp) {  
            if (param.second == 0) {                    // skip zero coefficient  
                continue;  
            }  
            res.push_back(to_string(param.second));  
            for (auto p : param.first) {  
                res.back() += "*" + p;  
            }  
        }  
        return res;  
    }  
private:  
    struct cmp {  
        bool operator()(vector<string> x, vector<string> y) {   // sort terms by degree  
            if (x.size() == y.size()) {  
                return x < y;  
            }  
            else {  
                return x.size() > y.size();  
            }  
        }  
    };  
    map<vector<string>, int, cmp> helper(string &expr, unordered_map<string, int> &eval) {  
        map<vector<string>, int, cmp> local = {{{}, 1}}, global;  
        string sub = "";  
        int sign = 1, n = expr.size();  
        for (int i = 0; i <= n; ++i) {  
            if (i < n && expr[i] == ' ') {          // skip space  
                continue;    
            }  
            if (i < n && isalnum(expr[i])) {        // number and alphabet, add to sub expression  
                sub += expr[i];  
            }  
            else if (i < n && expr[i] == '(') {     // parenthesis  
                ++i;  
                for (int p = 1; ; ++i) {            // get the sub expression in parenthesis  
                    if (expr[i] == '(') {  
                        ++p;  
                    }  
                    else if (expr[i] == ')') {  
                        --p;  
                    }  
                    if (p == 0) {  
                        break;  
                    }  
                    sub += expr[i];  
                }  
            }  
            else {                                  // '+', '-', '*' or i == n  
                if (sub.size() == n) {              // the whole expression is a number or variable  
                    if (eval.count(sub)) {  
                        return {{{}, eval[sub]}};   // variable is found in eval list   
                    }  
                    if (isdigit(sub[0])) {  
                        return {{{}, stoi(sub)}};   // number  
                    }  
                    return {{{sub}, 1}};            // variable  
                }  
                map<vector<string>, int, cmp> mult, submp = helper(sub, eval);  
                for (auto l : local) {              // multiply local with sub  
                    for (auto r : submp) {  
                        auto k = l.first;  
                        k.insert(k.end(), r.first.begin(), r.first.end());  
                        sort(k.begin(), k.end());  
                        mult[k] += l.second * r.second;  
                    }  
                }  
                local = move(mult);  
                if (i == n || expr[i] != '*') {     // '+' or '-'  
                    for (auto& t : local) {         // add local to global  
                        global[t.first] += sign * t.second;  
                    }  
                    sign = i < n && expr[i] == '-' ? -1 : 1;  
                    local = {{{}, 1}};              // reset local  
                }  
                sub = "";                           // reset sub  
            }  
        }  
        return global;  
    }  
};  
//https://blog.csdn.net/magicbean2/article/details/79641804