

#define _GLIBCXX_USE_CXX11_ABI 0/1

#include "interpreter.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

bool flag = false;
std::string name = "";

void interpreter::execute(std::string line){

	std::istringstream buf(line);
    std::istream_iterator<std::string> beg(buf), end;

    std::vector<std::string> tokens(beg, end);

    for(int i = 0; i<tokens.size(); i++){
    	if (i == 0){
    		std::cout << "Command: " << tokens[i] << endl << "Parameters:" << endl;
    	}else {
    		std::cout << tokens[i] << endl;
    	}
    }
    if(tokens[0]=="bye"){
    	if(name != ""){
    		std::cout << "bye, " << name << endl;
    	}else {
    		std::cout << "bye world" << endl;
    	}
    	flag = true;
    }else if(tokens[0]=="name"){
    	name = tokens[1];
    }else if(tokens[0]=="hello"){
    	if(name != ""){
    		std::cout << "hello, " << name << endl;
    	}else {
    		std::cout << "hello world" << endl;
    	}
    }
}

bool interpreter::is_done(){
    return flag;
}
