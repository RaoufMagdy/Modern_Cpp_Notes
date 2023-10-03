#include <iostream>



/*
 *
 * In the program, Aggregation helps to represent HAS-A relation between the objects of 2 individual classes.
 * Aggregation is more restrictive compared to the association.
 * Aggregation helps in making your program code more readable and understandable to represent the relation.
 * Using a pointer variable, you can refer to the object of one class in the container class object.
 *
 */




class Address{
public:
    std::string addressLine, city, state;
    Address(std::string addressLine, std::string city, std::string state)
    {
        this->addressLine = addressLine;
        this->city = city;
        this->state = state;
    }
};


class Employee{
private:
        Address* address;  //Employee HAS-A Address

public:
       int id;
       std::string name;
       Employee(int id, std::string name, Address* address)
       {
           this->id = id;
           this->name = name;
           this->address = address;
       }

       void display()
       {
    	 std::cout<<id <<" "<<name<< " "<<address->addressLine<< " "<< address->city<< " "<<address->state<<std::endl;
       }
};


int main(void)
{
    Address a1= Address("C-146, Sec-15","Noida","UP");
    Employee e1 = Employee(101,"Nakul",&a1);
    e1.display();

   return 0;
}








