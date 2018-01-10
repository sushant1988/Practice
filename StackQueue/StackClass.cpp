/*Implement Stacks Class operations*/

#include<iostream>
#include<stdlib.h>

using namespace std;

template <class T>
class Stack {
    private:
        T *stMem;
        int stSize;
        int topIndex;
    public:
        Stack(int = 10);
        ~Stack();
        void ReSize(int newsize);
        T& Top();
        bool Push(const T&);
        bool Pop();
        bool IsEmpty();
};

template <class T>
Stack<T>::Stack(int size)
{
    stMem = new T[size];
    stSize = size;
    topIndex = -1;
}

template <class T>
Stack<T>::~Stack()
{
    delete [] stMem;
}

template <class T>
T& Stack<T>::Top()
{
    if (topIndex >= 0) return stMem[topIndex];

    cout<<"Stack is empty"<<endl;
    throw;
}

template <class T>
bool Stack<T>::Push(const T& item)
{
    if (topIndex < (stSize - 1)) {
        stMem[++topIndex] = item;
        return true;
    }
    cout<<"Stack is Full, Try ReSize()"<<endl;
    return false;
}

template <class T>
bool Stack<T>::Pop()
{
    if (topIndex > -1) {
        topIndex--;
        return true;
    }

    cout<<"Stack Is Empty, No Element To Pop"<<endl;
    return false;
}

template <class T>
bool Stack<T>::IsEmpty()
{
    return (topIndex < 0);
}

template <class T>
void Stack<T>::ReSize(int newSize)
{
    T* stMemTmp = new T[newSize];
    memcpy(stMemTmp, stMem, sizeof(T)*stSize);
    stSize = newSize;
    delete [] stMem;
    stMem = stMemTmp;
}


int main()
{
    Stack<int> st(2);
    st.Push(12);
    st.Push(1);
    st.Push(2);
    st.ReSize(3);
//    st.Push(2);
    cout<<st.Top()<<endl;

    return 0;
}