#include <limits>
#include <array>

    template<class T>
    void print(T var) {
        std::cout << var << std::endl;
    }

template<class Container>
struct back_inserter {
    back_inserter(Container &c)
            : c(c) {}

    using difference_type = void;
    using value_type = void;
    using reference = void;
    using pointer = void;
    using iterator_category = std::output_iterator_tag;

    back_inserter &operator*() { return *this; }

    back_inserter &operator++() { return *this; }

    back_inserter &operator++(int) { return *this; }

    void operator=(const typename Container::value_type &value) {
        c.push_back(value);
    }

    Container &c;
};

template<typename T>
struct cin_iterator {
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using reference = T &;
    using pointer = T *;
    using iterator_category = std::input_iterator_tag;

    cin_iterator(bool fail = false)
            : fail(fail) { ++*this; }

    reference operator*() {
        return value;
    }

    cin_iterator &operator++() {
        if (!fail) {
            std::cin >> value;
            fail = std::cin.fail();
        }
        return *this;
    }

    cin_iterator operator++(int) {
        auto old = *this;
        ++*this;
        return old;
    }

    bool fail{};
    value_type value{};
};

template<class T>
bool operator==(cin_iterator<T> const &l, cin_iterator<T> const &r) {
    return l.fail == r.fail;
}

template<class T>
bool operator!=(cin_iterator<T> const &l, cin_iterator<T> const &r) {
    return !(l == r);
}

template<class T>
struct iota_iterator {
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using reference = T &;
    using pointer = T *;
    using iterator_category = std::forward_iterator_tag;

    T value;

    iota_iterator(T value = 0)
            : value(value) {}

    reference operator*()

    noexcept {
        return value;
    }

    using c_t = const T;

    c_t &operator*() const

    noexcept {
        return value;
    }

    iota_iterator &operator++()

    noexcept {
        ++value;
        return *this;
    }

    iota_iterator operator++(int)

    noexcept {
        auto temp = *this;
        ++*this;
        return temp;
    }

    bool operator==(iota_iterator const &i) const

    noexcept {
        return (value == i.value);
    }

    bool operator!=(iota_iterator const &i) const

    noexcept {
        return !(*this == i);
    }

    void print() const {
        std::cout << value << std::endl;
    }

};

template<class T>
struct forward_link_list {
    T value;
    forward_link_list *next;
};

template<typename T>
struct iterator_forward {
    forward_link_list<T> *ptr;

    T &operator*()

    noexcept {
        return ptr->value;
    }

    iterator_forward &operator++()

    noexcept {
        ptr = ptr->next;
        return *this;
    }

};


int main() {

    forward_link_list<int> list3{3, nullptr};
    forward_link_list<int> list2{2, &list3};
    forward_link_list<int> list1{1, &list2};
    forward_link_list<int> list0{0, &list1};

    iterator_forward<int> iter_for{&list0};

    std::vector<int> v1 = {1, 2, 3, 4};
    auto iter_v1 = std::begin(v1);
    auto iter_v2 = std::end(v1);
    std::advance(iter_v1, 2);
    print(*iter_v1);
    auto iter_v3 = std::next(iter_v1);
    auto iter_v4 = std::prev(iter_v3);
    print(*iter_v4);


    return 0;
}
