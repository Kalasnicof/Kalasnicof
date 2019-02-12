#include <iostream>

template<typename T>
class Foo {
public:
    Foo() { }
    virtual T transform(const T& t) const = 0;
};
