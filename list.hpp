#include <vector>
#include <iostream>

using namespace std;

template<typename T>
struct pydeque{
  vector<T> container;

  pydeque(){}

  void append(T ele){
     this->container.push_back(ele);
  }

  T get_item(int idx){
     if(idx >= 0){
       return this->container[idx];
     }else{
       return this->container[this->container.size()+idx];
     }
  }

  T pop(){
    return this->container.pop_back();
  }

  int len(){
     return this->container.size();
  }

  T popleft(){
    return this->container.pop_front();
  }
};

template<typename T>
int len(T v){
  return v.len();
}


