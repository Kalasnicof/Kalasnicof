#include <iostream>

template<typename T>
class Foo {
protected:
    T t;
public:
    Foo(const T& t) : t(t) { }
    T meta() const { return t; }
};
