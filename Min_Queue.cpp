#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct min_queue{
  const long long int INF = 1e18;
  stack< pair<long long int, long long int> > add_stack, remove_stack;
  long long int minimum(){
      if(add_stack.empty() && remove_stack.empty())
        return INF;

      if(add_stack.empty() || remove_stack.empty())  // both cannot be empty at the same time except at empty queue
        return add_stack.empty() ? remove_stack.top().second : add_stack.top().second;

      return min(add_stack.top().second, remove_stack.top().second);
  }

  void push(long long int element){
      int minimum = add_stack.empty() ? element : min(add_stack.top().second, element);
      add_stack.push({element, minimum});
  }

  long long pop(){
      if(remove_stack.empty())
          while(!add_stack.empty()){
            long long int element = add_stack.top().first;
            add_stack.pop();
            long long int minimum = remove_stack.empty() ? element : min(element, remove_stack.top().second);
            remove_stack.push({element, minimum});
          }
      int removed_element = remove_stack.top().first;
      remove_stack.pop();
      return removed_element;
  }
};
