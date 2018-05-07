#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
	int value, weight;
};

int PickBestPack(const vector<Item> &items, int k, 
            int avail_capacity, vector<vector<int>> *AllPlan_ptr){
	if(k<0){
		return 0;//no item can be chosen
	}

	vector<vector<int>> &AllPlan = *AllPlan_ptr;
	if(AllPlan[k][avail_capacity]==-1){
		int withoutItem = PickBestPack(items, k-1, avail_capacity, AllPlan_ptr);
		int withItem = 
		avail_capacity< items[k].weight ? 0:items[k].value + 
		PickBestPack(items, k-1, avail_capacity-items[k].weight, AllPlan_ptr);

	    AllPlan[k][avail_capacity] = max(withoutItem, withItem);
	}
}

int BestPack(const vector<Item> &items, int capacity){
	vector<vector<int>> AllPlan(items.size(), vector<int>(capacity+1, -1));
	return PickBestPack(items, items.size()-1, capacity, &AllPlan);
}


int main(){
    Item i1={60, 5};
    Item i2={50, 4};
    Item i3={70, 4};
    Item i4={30, 2};
    vector<Item> items={i1, i2, i3, i4};

    cout<<BestPack(items, 5);
    return 0;
}