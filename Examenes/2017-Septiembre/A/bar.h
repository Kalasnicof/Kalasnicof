#include "foo.h"

class Bar : public Foo {

public:
    Bar(int t) : Foo(2*t) { }
    void sil() override { (this->t)*=2; }
    void output() const {
        std::cout<<"|"<<(this->t)<<"|"<<std::endl;
    }
};
