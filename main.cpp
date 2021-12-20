#include <limits>
#include <array>

template<class T>
void print(T var) {
    std::cout << var << std::endl;
}

class Logger {
public:
    std::string name;

    Logger(std::string name)
            : name(name) {
        std::cout << name << " is constructed\n";
    }

    ~Logger() {
        std::cout << name << " is destructed\n";
    }
};

int main() {

    int * int_ptr = new int{};
    print(*int_ptr);
    std::vector<double> * vec_double = new std::vector<double>{{12, 13}};
    print(vec_double->at(1));

    delete int_ptr;
    delete vec_double;

    try {
        new int{100000000};
    } catch (std::bad_alloc e) {
        print(e.what());
    }

    int * int_array_ptr = new int[4]{1, 2, 3, 4};
    print(int_array_ptr[3]);
    delete[] int_array_ptr;


    return 0;
}
