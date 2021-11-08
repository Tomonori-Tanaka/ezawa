#include <limits>
#include <array>

struct Object {
    int data_member{};

    void member_function() {
        std::cout << data_member << std::endl;
    }

    void f1(int) {
        std::cout << 1 << std::endl;
    }

    void f2(int, int) {
        std::cout << 2 << std::endl;
    }
};

int main() {

    Object object;
    int Object::*data_ptr = &Object::data_member;
    void (Object::*member_function_ptr)() = &Object::member_function;

    object.*data_ptr = 123;
    (object.*member_function_ptr)();
    std::invoke(data_ptr, object) = 456;
    (object.*member_function_ptr)();

    Object *object_ptr = &object;
    (*object_ptr).data_member = 7;
    object_ptr->*data_ptr = 9;
    (*object_ptr).member_function();
    std::invoke(data_ptr, object_ptr) = 8;
    (*object_ptr).member_function();

    (object_ptr->*&Object::f1)(1);
    std::invoke(&Object::f1, object_ptr, 1);
    std::invoke(&Object::f2, object_ptr, 3, 3);


    return 0;
}
