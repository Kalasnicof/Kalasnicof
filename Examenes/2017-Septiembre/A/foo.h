#include <iostream>

class Foo {
protected:
    int t;
public:
    Foo(int t) : t(t) { }
    virtual void sil() { (this->t)+=1; }
    void output () const{
        std::cout<<(this->t)<< std::endl;
    }
};
