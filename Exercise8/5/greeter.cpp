
#define _GLIBCXX_USE_CXX11_ABI 0/1

#include "greeter.h"
#include <iostream>
#include <string>

using namespace std;

void greeter::greet(std::string name)
{
    cout << "hello world" << endl;
}

void greeter::bye(std::string name)
{
	cout << "bye world" << endl;
}
