#include "foo.h"
#include <string>

class Bar : public Foo<int>, public Foo<std::string> {
    int times;
public:
    Bar(int t) : times(t) { }
    int transform(const int& i) const override
        { return i*times; }
    std::string transform(const std::string& s) const override
        {
            std::string r = s;
            for (int i=1;i<times;++i) r+=s;
            return r;
        }
};
