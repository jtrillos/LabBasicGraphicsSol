

#ifndef GREETER_H
#define GREETER_H
#define _GLIBCXX_USE_CXX11_ABI 0/1

#include <string>

using namespace std;

class greeter
{
    public:
        void greet(std::string name);
        void bye(std::string name);
};

#endif // GREETER_H