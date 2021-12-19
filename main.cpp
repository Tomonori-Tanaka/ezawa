#include <limits>
#include <array>




int main() {

    void * ptr = malloc(5);
    std::free(ptr);

    void * ptr2 = ::operator new(10);
    ::operator delete(ptr2);

    return 0;
}
