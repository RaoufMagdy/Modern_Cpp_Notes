#include <iostream>
#include <memory>



//weak_ptr<T>:
// - Points to an object of type T in the HEAP.
// - Does not participate in owning relationship.
// - Alywas created from a "shared_ptr<T>".
// - Doesn't increment or decrement reference use_count().
// - Used to prevent strong reference cycles which could prevent objects from being deleted. <==== Important.




class B;

class A{
private:
    std::shared_ptr<B> b_ptr; // <=== mamke it weak to break the strong circular reference.
    //std::weak_ptr<B> b_ptr;     // <=== The only change that happens in the code
public:
    void set_B(std::shared_ptr<B> &b)
    {
        b_ptr = b;
    }

    A()
    {
        std::cout<<"A_Constructor"<<std::endl;
    }

    ~A()
    {
        std::cout<<"A_Destructor"<<std::endl;
    }


};

class B{
private:
    //std::shared_ptr<A> a_ptr; // <=== mamke it weak to break the strong circular reference.
    std::weak_ptr<A> a_ptr;     // <=== The only change that happens in the code
public:
    void set_A(std::shared_ptr<A> &a)
    {
        a_ptr = a;
    }

    B()
    {
        std::cout<<"B_Constructor"<<std::endl;
    }

    ~B()
    {
        std::cout<<"B_Destructor"<<std::endl;
    }


};



int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    //a->set_B(b);
    //b->set_A(a);

    // When we run we notice that the destructors of both classes were not called
    // That's because they are still located in the heap as both classes were pointing to each other
    // using a shared pointer and they both still have use_count() == 1 so they won't be destroyed until use_count() == 0.
    // Memory leak takes place in this case.
    // This problem is called "Strong Circular Reference".

    //=============================== weak_ptr =================================//

    a->set_B(b);
    b->set_A(a);



    // Now the problem is solved because the weap_ptr has no effect on the use_count(), so the shared pointer is deleted from
    // the HEAP automatically.

    return 0;
}



