#include <iostream>

class DivisionByZero {
	// Note the following:
	// ===> Constructors may fail.
	// ===> Constructors do not return any value.
	// ===> Throw an exception in the constructor if you can not initialize an object.
	// ===> When an exception is called a destructor is called automatically.
	// ===> DO NOT THROW AN EXCEPTION FROM A "DESTRUCTOR" AS IT WILL NOT BE REACHED.
};
class NegativeValue  {
	// Note the following:
	// ===> Constructors may fail.
	// ===> Constructors do not return any value.
	// ===> Throw an exception in the constructor if you can not initialize an object.
	// ===> When an exception is called a destructor is called automatically.
	// ===> DO NOT THROW AN EXCEPTION FROM A "DESTRUCTOR" AS IT WILL NOT BE REACHED.
};


double GpM(double miles, double gallons)
{

    if (miles == 0)
    {
    	// throw 0;
        throw DivisionByZero();
    }
    if(miles < 0.0 || gallons < 0.0)
    {
       // throw std::string{"Neither Miles nor Gallons can be negative!"};
    	throw NegativeValue();
    }
    if(miles > 10000000 || gallons > 2000)
	{
    	throw 1.1f; //<--- float type
	}

    return (static_cast<double>(gallons / miles));
}


int main() {

   double miles;
   double gallons;


   double gpm;

   std::cout<<"Enter the value of gallons: "<<std::endl;
   std::cin>>gallons;
   std::cout<<"Enter the value of miles: "<<std::endl;
   std::cin>>miles;



   try{
       gpm = GpM(miles,gallons);
       std::cerr<<"Gallons Per Miles = "<<gpm<<std::endl;
   }


  // catch(int& ex)
  // {
  //     std::cerr<<"Miles can't be a Zero value"<<"\n";
  // }


  // catch(std::string& ex)
  // {
  //      std::cerr<<ex<<std::endl;
  // }





   // ======> In Exception handling, the best practice is to throw an object not a primitive type
   // ======> Throw an object by value, catch it by reference or const reference


   catch(DivisionByZero& ex)
   {
	   std::cerr<<"Miles can't be a Zero value"<<"\n";
   }
/*
   catch(NegativeValue& ex)
   {
   	   std::cerr<<"Neither Miles nor Gallons can be negative!"<<"\n";
   }
*/
   /*
   catch(...) //must be the last catch statement
   {
       std::cerr<<"\n"<<"Unknown Error"<<std::endl;
   }
*/
    return 0;
}























