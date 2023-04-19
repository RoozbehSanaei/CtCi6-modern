#include <iostream>

void foo(int a) {
    std::cout << "foo: " << a << std::endl;
}

void bar(int b) {
    std::cout << "bar: " << b << ", "  << std::endl;
}

int main() {
    int params[3] = { 5, 6, 7 };
    void (*funcs[])(void*) = { (void(*)(void*))foo, (void(*)(void*))bar };

    for (int i = 0; i < 3; i++) {
        funcs[i](params[i]);
    }

    return 0;
}