#include <gtest\gtest.h>
#include "MyStack.h"

class MyStackTest : public ::testing::Test {
protected:                    // Either public or protected.  Cannot be private.
	virtual void SetUp() {   // Capital 'U'
		st.push(34);
		st.push(28);
		st.push(56);
	}
	virtual void TearDown() {
	}

	MyStackTest() {
		std::cout << "MyStackTest is constructed." << std::endl;
		st.push(22);
	}
	~MyStackTest() {
		std::cout << "Destructing MyStackTest." << std::endl;
	}

	MyStack st;
};


// Test with fixture
TEST_F(MyStackTest, DISABLED_testPop) {  // First argument must be test fixture class name
	int val = st.pop();    // Member of test fixture is accessible here
	EXPECT_EQ(56, val);

	EXPECT_EQ(54, val) << "This value must be 56";

	EXPECT_EQ(54, val) << "This value cannot be different from " << val;

	EXPECT_EQ(54, val) << "Let's see what is inside st: " << st;
}

/* 
	Question:  Should I use constructor/destructor or SetUp()/TearDown()?

	1. As a guideline, constructor should do minimum thing to put the object in a 
		valid state and destructor should do the reverse of constructor.
	2. If a function is virtual, put it in Setup()/TearDown()
	3. If exception might be thrown, put the code in TearDown(), not in destructor.
	4. Put gtest assertions in TearDown(), not in destructor
*/
