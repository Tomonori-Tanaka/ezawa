#include <limits>
#include <array>

struct Object {
    int data_member{};

    void member_function() {
        std::cout << data_member << std::endl;
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
    (*object_ptr).member_function();
    std::invoke(data_ptr, object_ptr) = 8;
    (*object_ptr).member_function();


    return 0;
}
