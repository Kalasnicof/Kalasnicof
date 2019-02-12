#include "foo.h"

class Bar : public Foo<int> {

public:
    Bar() : Foo<int>(0) { }
};
