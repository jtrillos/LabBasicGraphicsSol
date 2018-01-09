

#define _GLIBCXX_USE_CXX11_ABI 0/1

#include <iostream>
#include <string>
#include "greeter.h"
#include "interpreter.h"

using namespace std;

int main(int argc, char** argv){
	interpreter inter;
	cout << "hello world" << endl;
	cout << "bye world" << endl;

	greeter gre;
	gre.greet("");
	cout << "=================" << endl;
	gre.bye("");
	cout << "=================" << endl;

	std::string line;
	bool flag = false;

	while(!flag){
		std::cout << "Please, enter a line: ";
  		std::getline (std::cin,line);
  		inter.execute(line); 
  		flag = inter.is_done();
	}
	return 0;
}