
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void print(vector<string> array){
    for (int i=0; i<array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

}

map<string,int> seperate(string in){
    map<string, int> string_count;

    string token;
    while (in != token){
        int delimiter_pos = in.find_first_of(" ");
        if (delimiter_pos > in.find_first_of("\r")){
            delimiter_pos = in.find_first_of("\r");
        }
        if (delimiter_pos > in.find_first_of("\n")){
            delimiter_pos = in.find_first_of("\n");
        }
        token = in.substr(0, delimiter_pos);
        if (token != "")   {
            //check this word is stored in string_count or not.
            auto it = string_count.find(token);
            if (it != string_count.end()){
                //is already exist, then count++
                (*it).second++;
            }
            else{ // a new word, count = 1.
                string_count[token] = 1 ;//string_count.insert(pair<string, int>(token, 1));
            }
        }
        in = in.substr(delimiter_pos + 1);
    }
    return string_count;
}

void print_map(map<string, int> m){
    cout << endl << "The map size: " << m.size() << endl;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++){
        cout << (*it).first << ": " << (*it).second << " times." << endl;
    }
    cout << endl;
}

int main()
{
    string str;
    cout << "Please enter a sentence: ";
    getline(cin, str);

    map<string,int> string_map = seperate(str);
    print_map (string_map);
    cout << endl;

    cout << "Map: O(logn);" << endl;
    cout << "UnorderedMap: O(n)" << endl;
    cout << "Map allows to iterate over the elements in a sorted way, but unordered_map does not." << endl;
    return 0;
}
