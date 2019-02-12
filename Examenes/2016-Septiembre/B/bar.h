#include "foo.h"

class Bar : public Foo {
    Foo* foo;
public:
    Bar(Foo* f) : foo(f) { }
    int value() const override{
        if(foo == nullptr)
            return 0;
        else return foo->value()+1;
    }
};
