#include <limits>
#include <array>

template <class T>
void print_size(){
    std::cout << sizeof(T) << std::endl;
}



int main() {
    print_size<int *>();
    print_size<double *>();
    print_size<int **>();
    print_size<std::uintptr_t>();

    int data {};
    std::cout << &data << std::endl;
    print_size<int>();


    return 0;
}
