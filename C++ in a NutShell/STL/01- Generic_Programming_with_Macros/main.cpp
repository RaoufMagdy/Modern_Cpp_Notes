#include <iostream>


#define MAX(a,b) ( (a>b) ? a : b )

// Note that the best practice when using macros is to wrap up all the arguments in: ()
// so that we can include them in our code safely, specially in mathematical operations.
// Ex:
#define MIN(a,b) ( ( (a)>(b) ? (b) : (a) ) )

//Notice:
#define Square(a) a*a
#define SQUARE(a) ( (a)*(a) )


int main(void)
{
	int X{100};

	std::cout<<MAX(5, 10)<<std::endl;
	std::cout<<MAX(15.5687, 10.56977)<<std::endl;
	std::cout<<MAX('A','a')<<std::endl;
	std::cout<<"\n";
	std::cout<<MIN(5, 10)<<std::endl;
	std::cout<<MIN(15.5687, 10.56977)<<std::endl;
	std::cout<<MIN('A','a')<<std::endl;
	std::cout<<"\n";
	std::cout<<"\n";
	std::cout<<X/Square(5)<<std::endl; // not safe
	std::cout<<X/SQUARE(5)<<std::endl; // safe
	// that's due to the blind substitution

	return 0;
}



