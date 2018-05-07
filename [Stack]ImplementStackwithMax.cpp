#include<stack>
#include<iostream>
#include<stdexcept>
using namespace std;

class Stack{
public:
	bool Empty() const {return element_with_cached_max_.empty();}

	int Max() const{
		if(Empty())
			throw length_error("Max(): empty stack");
		return element_with_cached_max_.top().max;
	}

	int Pop(){
		if(Empty()){
			throw length_error("Pop: empty stack");
		}
		int pop_element = element_with_cached_max_.top().element;
		element_with_cached_max_.pop();
		return pop_element;
	}

	void Push(int x){
		element_with_cached_max_.emplace(ElementWithCachedMax{x, max(x, Empty() ? x: Max())});
	}
private:
	struct ElementWithCachedMax{
		int element, max;
	};

	stack<ElementWithCachedMax> element_with_cached_max_;
};

int main(){
    Stack element_;
    element_.Push(1);
    element_.Pop();
    element_.Pop();
    return 0;
}