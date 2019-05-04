/*Implement Stacks and queues operations*/

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>

using namespace std;

//create Queue using stacks
template <class T>
class QueueStack {
    private:
        stack<T> oldStack;
        stack<T> newStack;

        void stack_shift() {
            if(oldStack.empty()) {
                while(!newStack.empty()) {
                    oldStack.push(newStack.top());
                    newStack.pop();
                }
            }
        }
    public:
        void push(const T& item) {
            newStack.push(item);
        }

        T& peek() {
            stack_shift();
            if(!oldStack.empty()) return oldStack.top();
            throw;
        }

        void pop() {
            stack_shift();
            if(!oldStack.empty()) {
                oldStack.pop();
            } else throw;
        }
};

// Sort the stack using another stack
vector<int> SortStack(vector<int> stack1)
{
    vector<int> stack2;
    while(!stack1.empty())
    {
        int temp = stack1.back();
        stack1.pop_back();
        while(!stack2.empty() && stack2.back() < temp)
        {
            stack1.push_back(stack2.back());
            stack2.pop_back();
        }
        stack2.push_back(temp);
    }
    return stack2;
}

int main()
{
    int a[] = {8,2,7,5,3,1,6,4,9};
    vector<int> stack(a, a+9);

  /*  for(int i =0; i<9; i++)
    {
        int value = rand()% 10 + 1;
        stack.push_back(value);
    }*/
    vector<int> v = SortStack(stack);

    for(int i = 0; i< v.size(); i++)
        cout<<v[i]<<endl;
/*
    QueueStack<int> Q;
    Q.push(5);
    Q.push(1);
    Q.push(6);
    Q.push(2);

    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.peek()<<endl;
    Q.push(7);
*/
return 0;
}
