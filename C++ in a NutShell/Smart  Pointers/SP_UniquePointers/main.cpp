#include <iostream>
#include <memory>


// unique_ptr<T>
// - Points to an object of type T on the HEAP.
// - It is unique - there can only be one unique_ptr<T> pointing to th ibject on the heap.
// - Owns what it points to.
// - Can not be assigned or copied.
// - Can be moved.
// - When the unique pointer is destroyed, the "pointee" is automatically destroyed.
// - Normal pointers won't be destoyed automatically (we have to use "delete") if the were pointing to a user defined class data type.

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


int main(void)
{
	// Test *Nptr;
	// Nptr = new Test(500); //you will notice that it won't be destroyed from the heap automatically.
	// it can be destroyed if it was initialized like: Nptr = A(500); where A is an object of class Test.
	//delete Nptr; // to delete Nptr in the heap.

	std::unique_ptr<Test> ptr1 { new Test{100} };
	std::unique_ptr<Test> ptr2 = std::make_unique<Test>(1000);

	std::unique_ptr<Test> ptr3;

	// ptr3 = ptr1; //invalid as unique_ptr can't be copied.

	ptr3 = std::move(ptr1); //valid as unique_ptr can be moved. and ptr1 is now empty (nullptr).

	return 0;
}


