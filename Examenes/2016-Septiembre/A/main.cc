#include "bar.h"
#include <iostream>

int main(int argc, char** argv) {
    Bar bar;
    bar.mar(3); bar.mar(2);
    std::cout<<bar.sil()<<std::endl;

    Foo<double> ffoo(0.3);
    ffoo.mar(3.1); ffoo.mar(1.6);
    std::cout<<ffoo.sil()<<std::endl;

    Foo<const char*> cfoo("ba");
    cfoo.mar("tm"); cfoo.mar("an");
    std::cout<<cfoo.sil()<<std::endl;

}
