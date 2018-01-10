//============================================================================
// Name        : HelloWorldC++.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

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

A(const A*)
{
	cout<<"Copy Constructor"<<endl;
}

A* operator =(const A*)
{
	cout<<"Assignment Operator"<<endl;
	return this;
}
~A()
	{
		cout<<"Destructor of A"<<endl;
	}
};

template<class T>
class Guard
{
	const T *a;
public:
Guard(const T* t)
	{
		a = t;
		cout<<"Class A has been initialized"<<endl;
	}


~Guard()
{
	if(a != NULL)
		delete a;
	cout<<"Deleted Class A"<<endl;
}

};



int main() {
	A *a = new A();
	A b(*a);
	b=a;
	b.print();
	Guard<A> *g = new Guard<A>(a);

	cout<<"HI"<<endl;
	delete g;
	//A *a = new A();
	//a->print();
	//delete a;
	return 0;
}
