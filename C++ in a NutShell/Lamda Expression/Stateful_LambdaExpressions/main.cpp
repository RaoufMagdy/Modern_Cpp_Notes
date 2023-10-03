#include <iostream>
#include <vector>
#include <string>



//[captured_variables] () -> return_type { /* Code */ };
//         |
//     Defines what information/variables should be captured.


// Data (variables) can be either captured by value or by reference
// Note that if we want to capture that variable by value and modify it inside the lambda we need to write the keyword "mutable"
// Ex: [x] () mutable {x += 100; std::cout<<x<<std::endl;}();



int main(void)
{

	int x = 100;

	//capture by value:
	[x] () mutable {x+=100; std::cout<<x<<std::endl;}(); //outputs 200 as this is a copy of x
	std::cout<<x<<std::endl; //outputs 100

	[&x] () {x+=100; std::cout<<x<<std::endl;}(); //outputs 200
	std::cout<<x<<std::endl; //outputs 200

	// Default Captures:
	//    [=] --> Default capture by value.
	//    [&] --> Default capture by reference.
	// [this] --> Default capture this object by reference.

	// Using default and explicit captures:
	//   [=, &x] --> Default capture by value but capture "x" by reference.
	//    [&, y] --> Default capture by reference but capture "y" by value.
	// [this, z] --> Default capture "this" object by reference but capture "z" by value.

	return 0;
}



