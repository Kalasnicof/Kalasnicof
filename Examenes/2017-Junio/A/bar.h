#include "foo.h"

class Bar : public Foo {

public:
    Bar(int t) : Foo(2*t) { }
    void sil() { (this->t)*=2; }
    void output() const override {
        std::cout<<"|"<<(this->t)<<"|"<<std::endl;
    }
};
