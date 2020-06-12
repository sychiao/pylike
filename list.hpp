#include <vector>
#include <iostream>

using namespace std;

template<typename T>
struct pydeque{
  vector<T> container;
  
  pydeque(){}
  pydeque(initializer_list<T> lst):container(lst){}

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

  void pop(){
    this->container.pop_back();
  }

  int len(){
     return this->container.size();
  }

  void popleft(){
    auto& v = this->container;
    v.erase(v.begin());
  }

  T operator[](int idx){
    return this->get_item(idx);
  }
};


template<typename T>
int len(T v){
  return v.len();
}


