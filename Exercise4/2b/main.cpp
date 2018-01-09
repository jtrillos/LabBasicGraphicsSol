#include <iostream>

using namespace std;

class A {
public:
    int counter;
    A(int a = 1) {
        counter = a;
        cout << "construct A: " << counter << endl;
    }
    ~A() {
        cout << "destruct A: " << counter << endl;
    }
    void use() {
        if( -- counter > 0 ) {
            cout << counter << " times left" << endl;
        }
    }
};


int main(int argc, char** argv) {
    A a1(4), a2(2);
    a1.use();
    {
        A a3;
        a3.use();
        a1.use();
        a3.use();
    }
    a1.use();
    return 0;
}
