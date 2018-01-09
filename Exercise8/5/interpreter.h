

#ifndef INTERPRETER_H
#define INTERPRETER_H
#define _GLIBCXX_USE_CXX11_ABI 0/1

#include <string>

class interpreter
{
    public:
        void execute(std::string line);
        bool is_done();
};

#endif // INTERPRETER_H