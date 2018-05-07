#include<bits/stdc++.h>
using namespace std;

class GasStation {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasLeft =0, sum=0, start=0;
        for(unsigned i=0; i< gas.size(); i++){
            gasLeft += gas[i]- cost[i];
            sum += gas[i]-cost[i];
            
            if(sum<0){
                start = i+1;
                sum =0;
            }
        }
        if(gasLeft <0) return -1;
        else return start;
    }
};

int main(){
  GasStation gs;
  vector<int> gas={16};
  vector<int> cost={17};
  cout<<gs.canCompleteCircuit(gas, cost);
  return 0;
}