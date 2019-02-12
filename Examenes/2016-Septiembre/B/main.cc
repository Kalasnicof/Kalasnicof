#include "bar.h"
#include <iostream>

int main(int argc, char** argv) {
    Foo* f = new Bar(nullptr);
    std::cout<<f->value()<<std::endl;
    f = new Bar(new Bar(nullptr));
    std::cout<<f->value()<<std::endl;
    f = new Bar(new Foo());
    std::cout<<f->value()<<std::endl;

}
