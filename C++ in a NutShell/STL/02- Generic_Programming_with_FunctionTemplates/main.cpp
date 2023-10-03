#include <iostream>



// Template functions do not generate any code unless they are used



class A
{
private:
    int X;
public:
    A(int y)
    {
        X = y;
    }

    ~A()
    {

    }

    A operator + (A const& a) const
    {
        return (this->X + a.X);
    }

    bool operator > (A const& a)
	{
    	return (this->X > a.X);
	}

    friend std::ostream& operator << (std::ostream& os, const A& obj){
        os << obj.X ;
        return os;
    }
};


template<typename T>
T max(T a, T b)
{
	//note that we have to overload the operator ">" in order to be able to use the template function for
	//user defined types.
	return ( (a>b) ? a : b );
}

template <typename T>
T ADD(T a, T b)
{
	//note that we have to overload the operator ">" in order to be able to use the template function for
	//user defined types.
	return (a+b);
}


int main()
{
    A m(15), n(20);

    std::cout<<(n>m)<<std::endl;

    std::cout<<ADD(m,n);

    return 0;
}





