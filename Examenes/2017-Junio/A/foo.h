#include <iostream>

class Foo {
protected:
    int t;
public:
    Foo(int t) : t(t) { }
    void sil() { (this->t)+=1; }
    virtual void output () const{
        std::cout<<(this->t)<< std::endl;
    }
};
