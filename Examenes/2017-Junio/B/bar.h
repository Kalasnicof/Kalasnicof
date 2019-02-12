#include "foo.h"

template<typename T>
class Bar {
    Foo<T>* foo;
public:
    Bar(Foo<T>* foo) : foo(foo) { }
    T tolo() const { return foo->meta(); }
};
