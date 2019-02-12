#include <iostream>

class Bar {
    int n, d;
public:
    Bar(int _n, int _d) : n(_n), d(_d) { }
    Bar operator+(const Bar& bas) const {
        return Bar(n*bas.d + bas.n*d, d*bas.d);
    }
    Bar operator/(int i) const {
        return Bar(n,d*i);
    }
    friend std::ostream& operator<<(std::ostream& os, const Bar& tolo){
        os<<tolo.n<<"/"<<tolo.d; return os;
    }
};
