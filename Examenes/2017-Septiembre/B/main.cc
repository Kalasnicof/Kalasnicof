#include "bar.h"
#include <iostream>

template<typename T>
void transformprint(const T& t, const Foo<T>& foo){
    std::cout<<foo.transform(t)<<std::endl;
}

int main(int argc, char** argv) {
    Bar bar(3);
    transformprint<int>(3, bar);
    transformprint<std::string>(std::string("la"), bar);
}
