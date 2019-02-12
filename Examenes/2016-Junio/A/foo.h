

template<typename T>
class Foo {
    T t;
    int n;
public:
    Foo(const T& _t) : t(_t),n(1) { }
    void mar(const T& t2) { ++n; t=t+t2; }
    T sil() const { return t/n; }
};
