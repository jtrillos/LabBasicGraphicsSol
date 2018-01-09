# Exercise 0: Example Session

In your text editor of choice create a new file main.cpp in a folder test_app with the folowing content:
```
    #include <iostream>
    using namespace std;
    int main(int argc, char** argv) {
        for (int i = 0; i < 10; i++) {
            cout << i << endl;
        }
		return 0; 
	}
```
Open a terminal and navigate to the folder test_app. Compile your code with g++ main.cpp -o test_app -g. Running your code should now be possible with ./test_app.