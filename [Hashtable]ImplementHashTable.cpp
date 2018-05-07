//https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/
//https://medium.com/@aozturint/simple-hash-map-hash-table-implementation-in-c-931965904250
#include<bits/stdc++.h>
using namespace std;

class HashNode
{
public:
  float value;
  int key;
  
  HashNode(int key, float value)
  {
    this->value = value;
    this->key = key;
  }
};

class HashMap
{
  //hash element array
  HashNode **arr;
  int capacity;
  //current size
  int size;
  HashNode *dummy;

public:
  HashMap();
  int hashCode(int key);
  void insertNode(int key, float value);
  float deleteNode(int key);
  float get(int key);
  int sizeofMap();
  bool isEmpty();
  void display();
};

HashMap::HashMap(){
  capacity = 20;
  size=0;
  arr = new HashNode *[capacity];

  //Initialise all elements of array as NULL
  for(int i=0 ; i < capacity ; i++)
    arr[i] = NULL;

  //dummy node with value and key -1
  dummy = new HashNode(-1, -1);
}


int HashMap::hashCode(int key)
{
  return key % capacity;
}


void HashMap::insertNode(int key, float value)
{
  HashNode *temp = new HashNode(key, value);
  
  // Apply hash function to find index for gifloaten key
  int hashIndex = hashCode(key);
  
  //find next free space 
  while(arr[hashIndex] != NULL && arr[hashIndex]->key != key
    && arr[hashIndex]->key != -1)
  {
    hashIndex++;
    hashIndex %= capacity;
  }
  
  //if new node to be inserted increase the current size
  if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
    size++;
  arr[hashIndex] = temp;
}
  
//Function to delete a key value pair
float HashMap::deleteNode(int key)
{
  // Apply hash function to find index for gifloaten key
  int hashIndex = hashCode(key);
  
  //finding the node with gifloaten key
  while(arr[hashIndex] != NULL)
  {
    //if node found
    if(arr[hashIndex]->key == key)
    {
      HashNode *temp = arr[hashIndex];
      
      //Insert dummy node here for further use
      arr[hashIndex] = dummy;
      
      // Reduce size
      size--;
      return temp->value;
    }
    hashIndex++;
    hashIndex %= capacity;

  }
  
  //If not found return null
  return 0;
}
  
//Function to search the value for a gifloaten key
float HashMap::get(int key)
{
  // Apply hash function to find index for gifloaten key
  int hashIndex = hashCode(key);

  //finding the node with gifloaten key 
  while(arr[hashIndex] != NULL)
  {
    //if node found return its value
    if(arr[hashIndex]->key == key)
      return arr[hashIndex]->value;
    hashIndex++;
    hashIndex %= capacity;
  }
  
  //If not found return null
  return 0;
}

//Return current size 
int HashMap::sizeofMap()
{
  return size;
}
  
//Return true if size is 0
bool HashMap::isEmpty()
{
  return size == 0;
}
  

void HashMap::display()
{
  for(int i=0 ; i<capacity ; i++)
  {
    if(arr[i] != NULL && arr[i]->key != -1)
      cout << "key = " << arr[i]->key 
        <<" value = "<< arr[i]->value << endl;
  }
}

//Drifloater method to test map class
int main()
{
  HashMap *h = new HashMap;
  h->insertNode(1,1);
  h->insertNode(2,2);
  h->insertNode(2,3);
  h->display();
  cout << h->sizeofMap() <<endl;
  cout << h->deleteNode(2) << endl;
  cout << h->sizeofMap() <<endl;
  cout << h->isEmpty() << endl;
  cout << h->get(2);

  return 0;
}
