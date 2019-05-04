//============================================================================
// Name        : HelloWorldC++.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include "SmartPointer.h"

using namespace std;

template<class T>
class SmartPointer {

private:
		T* objectPtr;
		int refCount;
public:
	SmartPointer(T* ptr):
	objectPtr(ptr),refCount(1)
	{
		cout<<"SmartPointer Initilized"<<endl;
	}
	SmartPointer(const SmartPointer<T>& sptr):
	objectPtr(sptr->Get()),refCount(sptr->GetRefCount())
	{
		refCount++;
		cout<<"copy SmartPointer Initilized"<<endl;
	}

	T* Get() { return objectPtr; }

	int GetRefCount() { return refCount; }

	~SmartPointer()
	{
		// TODO Auto-generated destructor stub
			refCount--;

			if(refCount == 0)
			{
				delete objectPtr;
				objectPtr = NULL;
			}
	}
};



class A
{
	int size;
public :
	A():size(10)
	{
		cout<<"Constructor of A"<<endl;
	}
int getA() const
	{
		return size;
	}
void print() const
	{
		cout<<"This is A"<<endl;
	}

A(const A&)
{
	cout<<"Copy Constructor"<<endl;
	size = 10;
}

A& operator =(const A&)
{
	cout<<"Assignment Operator"<<endl;
	return *this;
}
~A()
	{
		cout<<"Destructor of A"<<endl;
	}
};

int main()
{
	A* a = new A();
	SmartPointer<A> sptr(a);
	sptr.Get()->print();

//	A b(a);
//	b = a;
//	b.print();
//	Guard<A> *g = new Guard<A>(a);

//	cout<<"HI"<<endl;
//	delete g;
	//A *a = new A();
	//a->print();
//	delete a;
	return 0;
}



