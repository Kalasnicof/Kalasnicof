#include "bar.h"
#include <iostream>

int main(int argc, char** argv) {
    Bar<int> ibar(new Foo<int>(42));
    std::cout<<ibar.tolo()<<std::endl;
    Bar<float> fbar(new Foo<float>(4.8f));
    std::cout<<fbar.tolo()<<std::endl;
    Bar<double> dbar(new Foo<int>(1024));
    std::cout<<dbar.tolo()<<std::endl;
}
