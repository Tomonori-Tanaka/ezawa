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

    void *ptr = ::operator new(sizeof(Logger));
    Logger *logger_ptr = new(ptr) Logger{"Alice"};
    logger_ptr->~Logger();
    ::operator delete(ptr);


    return 0;
}
