
#include "MyStack.h"
#include <sstream>

MyStack::MyStack(void)
{
}


MyStack::~MyStack(void)
{
}

void MyStack::push(int data) {
	this->_v.push_back(data);
}

int MyStack::pop() {
	int ret = _v.back();
	_v.pop_back();
	return ret;
}

std::string MyStack::toString() {
	std::string ret = "";
	std::stringstream sm;
	for (int i=0; i<_v.size(); i++) {
		sm << _v[i] << " ";
	}
	return sm.str();
}