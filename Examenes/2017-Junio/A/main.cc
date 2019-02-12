#include "bar.h"

int main(int argc, char** argv) {
    Foo* foo = new Foo(1);
    foo->sil();
    foo->sil();
    foo->output();

    Bar* bar = new Bar(2);
    bar->sil();
    bar->sil();
    bar->output();

    Foo* foobar = new Bar(3);
    foobar->sil();
    foobar->sil();
    foobar->output();
}
