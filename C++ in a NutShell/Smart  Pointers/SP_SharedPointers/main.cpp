#include  <iostream>
#include <memory>



// shared_ptr<T>
// - Points to an object of type T in the HEAP.
// - It is not unique, there can be many shared pointers pointing to the same object in the HEAP.
// - Establishes shared ownership relationship.
// - Can be assigned and copied.
// - Can be moved.
// - Doesn't support managing arrays by default.
// - When the use count is zero, the managed object in heap gets destroyed.


class Test{
private:
	int a;
public:
	Test()
	{
		a = 0;
		std::cout<<"Value = "<<a<<std::endl;
	}

	Test(int b)
	{
		a = b;
		std::cout<<"Value = "<<a<<std::endl;
	}

	~Test(){std::cout<<"Value = "<<a<<" Destroyed"<<std::endl;}
};



int main()
{
	//use_count() ==> returns the number of shared pointer objects
	// that are currently referring to the heap object.

	std::shared_ptr<Test> p1{ new Test(1000) };
	std::shared_ptr<Test> p2 = std::make_shared<Test>(500);
	std::shared_ptr<Test> p3; //p3 is initialized to null this way.

	p3 = p2;

	if(!p2) //if p2 is a nullptr
		std::cout<<"Destroyed AF!"<<std::endl; //won't be printed as p2 is still present.

	std::cout<<"Num of use_counts = "<<p2.use_count()<<std::endl;

	return 0;
}













