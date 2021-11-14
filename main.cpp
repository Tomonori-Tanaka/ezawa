#include <limits>
#include <array>

template<class T>
void print(T x) {
    std::cout << x << std::endl;
}

template<class To, class From>
To bit_cast(From const &from) {
    To to;
    memcpy(&to, &from, sizeof(To));
    return to;
}


template<class T>
void print_raw_address(T ptr) {
    print(bit_cast<std::uintptr_t>(ptr));
}

void *memcpy(void *dest, void const *src, std::size_t n) {
    auto d = static_cast<std::byte *>(dest);
    auto s = static_cast<std::byte const *>(src);
    /*
    auto last = s + n;
    while (s != last){
        *d = *s;
        ++d;
        ++s;
    }
    */
    for (std::size_t i = 0; i != n; ++i){
        // *(d + i) = *(s + i)
        d[i] = s[i];
    }

    return dest;
}

int main() {


    int data[4] = {0, 1, 2, 3};
    int *data0 = data;
    print(*data0);
    print_raw_address(data0);
    int *data2 = data0 + 2;
    print(*data2);
    print_raw_address(data2);
    int *data1 = data2 - 1;
    print(*data1);
    print_raw_address(data1);

    return 0;
}
