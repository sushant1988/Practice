#include <gtest\gtest.h>
#include "MyStack.h"

// Death Test:  Verify a statement will cause process to exit with certain exit code and error message

void function1() {

	std::cerr << "Bad thing happened";
	std::exit(1);  // exit(0) is not a death
}

void function2() {
	std::cerr << "Bad thing happend again.";
	std::exit(22);
}

TEST(tutorial_DeathTest, simpletest) {   // Convention: test case name should end with "DeathTest"
										 // DeathTests usually need to be run before other test
	int x = 90;

	// Reasons of death:  
	//    1. Process exited with non-zero code 
	//    2. Process was killed by a signal

	EXPECT_DEATH(function1(), "Bad thing happened");

	EXPECT_EXIT(function2(), ::testing::ExitedWithCode(22), ""); // "" means I don't care about cerr message

	//EXPECT_EXIT(function2(), ::testing::KilledBySignal(SIGKILL), ".*");  // Not on Windows
}