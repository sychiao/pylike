#include "list.hpp"
#include "range.hpp"

#define in :

auto SumOfKSubArray(auto arr,auto n,auto k){
    auto Sum = 0;
    auto first_i = *range(k).begin();
    auto S = pydeque<decltype(first_i)>();
    auto G = pydeque<decltype(first_i)>();
    for(auto i in range(k)){
        while(len(S) > 0 and arr[S[-1]] >= arr[i])
            S.pop();
        while(len(G) > 0 and arr[G[-1]] <= arr[i])
            G.pop();
        G.append(i);
        S.append(i);
    }
    for(auto i in range(k, n)){
        while(len(S) > 0 and S[0] <= i-k)
            S.popleft();
        while(len(G) > 0 and G[0] <= i-k)
            G.popleft();
        while(len(S) > 0 and arr[S[-1]] >= arr[i])
            S.pop();
        while(len(G) > 0 and arr[G[-1]] >= arr[i])
            G.pop();
        G.append(i);
        S.append(i);}
    Sum += arr[S[0]] + arr[G[0]];
    return Sum;
}

int main(){
  const int ci = 0;
  std::cout << SumOfKSubArray(pydeque({1,2,3,4,5,6}), 3, 2);
}


