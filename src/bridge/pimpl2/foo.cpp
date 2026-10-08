#include <iostream>
#include "foo.h"

class Foo::impl{
    public:
    void greet()
    {
        std::cout << "greetings" << std::endl;
    }
}; 

Foo::Foo()
{ 
}

void Foo::greet(){
    p_impl->greet();
}