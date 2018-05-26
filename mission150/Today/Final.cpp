#include<bits/stdc++.h>

template<class Object>
class ObjectPool{
public:
	ObjectPool():maxSize(128), minSize(4){};

	static Object* get_object(){
		if(myObjects.empty()){
			std::cout<<"creating new object"<<std::endl;
			return new Object();
		}
		std::cout<<"returning existing one"<<std::endl;
		Object* obj = myObjects.top();
		myObjects.pop();
		return obj;
	}

	static void release_object(Object* obj){
		std::cout<<"releasing object to pool"<<std::endl;
		myObjects.push(obj);
	}

	static void release_all(){
		std::cout<<"remove all - size: "<<myObjects.size()<<std::endl;
		while(!myObjects.empty()){
			Object* tmp = myObjects.top();
			myObjects.pop();
			delete tmp;
		}
	}

	void set_size_limit(size_t _maxSize, size_t _minSize){
		minSize=(_minSize>0)? _minSize:4;
		maxSize=(_maxSize>0)? _maxSize:256;
		for(size_t i=0; i<_minSize; i++){
			release_object(new Object());
		}
	}

	~ObjectPool(){release_all();}

private:
	size_t minSize;
	size_t maxSize;
	size_t defaultSize;
	static std::stack<Object*> myObjects;
};
template<class Object>
std::stack<Object*> ObjectPool<Object>::myObjects;


class Object{
public:
	Object(){
		static int count=0;
		std::cout<<"constructor: "<<++count<<std::endl;
	}

	static Object* create_instance(){
		return myObjectPool.get_object();
	}

	void release_instance(){
		myObjectPool.release_object(this);
	}

	static void release_all(){
		myObjectPool.release_all();
	}

	static ObjectPool<Object> myObjectPool;
	std::string m_obj;
};
ObjectPool<Object>Object::myObjectPool;

int main(){
    ObjectPool<Object> myObjPool;
    myObjPool.set_size_limit(5,2);
    
    auto words={"Hello", "World","Weekend"};
	Object* newObj1 = Object::create_instance();
	newObj1->m_obj = words[0];
	newObj1->release_instance();

	Object* newObj2 = Object::create_instance();
	newObj2->m_obj= words[1];
	assert(newObj1==newObj2);
	newObj2->release_instance();
	
	//ObjectPool<Object>::release_all();
	return 0;
}