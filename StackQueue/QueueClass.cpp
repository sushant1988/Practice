/*Implement Circular Queue Class operations*/

#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;

template<class T>
class Queue {
    T *queMem;
    int front;
    int rear;
    int queSize;
    int elements;

    public:
        Queue(int size = 10) {
            queMem = new T[size];
            front = -1;
            rear = -1;
            queSize = size;
            elements = 0;
        }
        ~Queue() {
            delete [] queMem;
        }

        bool Push(const T& item) {
            if(elements <= queSize ) {
                if ((front == -1) && (rear == -1)) front = 0;
                elements++;
                rear++;
                queMem[rear] = item;
                if (rear == (queSize -1)) rear = -1;
                return true;
            }
            cout<<"Queue is Full, try Resize";
            return false;
        }

        bool Pop() {
            if(elements > 0) {
                elements--;
                front++;
                if (front == queSize) front = 0;
                return true;
            } else {
                front = -1;
            }

            cout<<"Queue is empty, try Resize";
            return false;
        }

        bool IsEmpty()
        {
            return (elements == 0);
        }

        T& Peek() {
            if(elements > 0) return queMem[front];

            cout<<"Queue is Empty"<<endl;
            throw;
        }

        void Display() {
            for(int i=0; i<queSize; i++) {
                cout<<queMem[i]<<" ";
            }
            cout<<endl;
        }
};


int main() {
    Queue<int> que(2);
    que.Push(2);
    que.Push(10);
    cout<<"Queue Peek: "<<que.Peek()<<endl;
    que.Pop();
    cout<<"Queue Peek: "<<que.Peek()<<endl;
    que.Push(15);
    cout<<"Queue Peek: "<<que.Peek()<<endl;
    que.Pop();
    cout<<"Queue Peek: "<<que.Peek()<<endl;
}