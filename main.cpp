#include <limits>
#include <array>


struct Object {
    std::string name;

    Object(std::string const & name)
        : name(name)
    { std::cout << name << "is constructed" << std::endl;}

    ~Object()
    { std::cout << name << "is destructed" << std::endl;}

};

void f() {
    Object obj("f");
    throw 0;
    std::cout << "aaa";
}

void g() {
    Object obj("g");
    f();
}

int main() {

    Object object("main");

    try {
        g();
    } catch(int e) {
        std::cout << "caught" << std::endl;
    }

    return 0;
}
