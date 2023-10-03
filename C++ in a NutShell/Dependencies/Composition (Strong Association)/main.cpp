#include <iostream>


/*

  Composition Example : Consider the example of a Car and an engine that is very specific to that car
  (meaning it cannot be used in any other car). This type of relationship between Car and SpecificEngine
  class is called Composition. An object of the Car class cannot exist without an object of SpecificEngine
  class and object of SpecificEngine has no significance without Car class.
  To put in simple words Car class solely "owns" the SpecificEngine class.

*/

/*

class Engine{
public:
	Engine()
	{
		std::cout<<"Specific Engine for CarA"<<std::endl;
	}

	~Engine(){std::cout<<"Engine Destructor"<<std::endl;}
};


class CarA{
private:
	Engine CarEngine;
public:
	CarA()
	{
		std::cout<<"Starting Engine"<<std::endl;
	}

	~CarA(){std::cout<<"Car Destructor"<<std::endl;}
};


int main(void)
{
	CarA car;


	return 0;
}

*/

//Another Example:

class A {
public:
    int data;

    // Data member is initialized using the default constructor.
    A() {
        data = 0;
    }

    A(int a) {
        std::cout << "Constructor of Class A is invoked" << std::endl;
        data = a;
    }
};

class B {
private:
    int b;
    A obj2;

public:
    // Constructor of class B.
    B(int a) : obj2(a) {
        b = a;
    }

    // Printing values of data members.
    void printData() {
    	std::cout << "Data of class B object is " << b << std::endl;
    	std::cout << "Data of class A object in class B is " << obj2.data;
    }
};

int main() {

    B obj1(25); // Object of class B.
    obj1.printData();
    return 0;
}

