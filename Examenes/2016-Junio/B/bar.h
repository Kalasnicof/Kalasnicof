#include "foo.h"

class Bar : public Foo {
    Foo* foo;
public:
    Bar(Foo* f) : foo(f) { }
    int value() const override
    { return foo->value()+1; }
};
