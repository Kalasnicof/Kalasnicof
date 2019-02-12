#include "bar.h"
#include <iostream>

int main(int argc, char** argv) {
    Foo* foos[5];
    foos[0]=new Foo();
    for(int i=1;i<5;i++){
        std::cout<<i<<" "<<std::endl;
        foos[i]=new Bar(foos[i-1]);
    }
    for (Foo* f : foos)
        std::cout<<f->value()<<" ";
        std::cout<<std::endl;
    for (Foo* f : foos)
        delete f;
}
