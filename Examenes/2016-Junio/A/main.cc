#include "foo.h"
#include "bar.h"
#include <iostream>

int main(int argc, char** argv) {
    Foo<int> ifoo(1);
    ifoo.mar(2); ifoo.mar(3);
    std::cout<<ifoo.sil()<<std::endl;

    Foo<double> ffoo(0.1);
    ffoo.mar(0.2); ffoo.mar(0.3);
    std::cout<<ffoo.sil()<<std::endl;

    Foo<Bar> bfoo(Bar(1,10));
    bfoo.mar(Bar(2,10));
    bfoo.mar(Bar(3,10));
    std::cout<<bfoo.sil()<<std::endl;
}
