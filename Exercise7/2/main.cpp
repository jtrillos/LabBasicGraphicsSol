
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string in){
    string temp;
    vector<string> strings;
    while (in!=temp){
        int pos = in.find_first_of(" ");
        if (pos > in.find_first_of("\r")){
            pos = in.find_first_of("\r");
        }
        if (pos > in.find_first_of("\n")){
            pos = in.find_first_of("\n");
        }
        temp = in.substr(0, pos);
        if (temp != "") {
            strings.push_back(temp);
        }
        in = in.substr(pos+1);
    }
    return strings;
}

vector<int> counts(vector<string> array){
    vector<int> counts;
    int temp;
    for (int i=0; i<array.size(); i++) {
        temp= count (array.begin(), array.end(), array[i]); //fist iterator, last iterator, value
        cout << array[i] << " : " << temp  << " times.\n";
        counts.push_back(temp);
    }
    return counts;
}

void print(vector<string> array){
    for (int i=0; i<array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

}

void testHistogram(){
    vector<string> strings;
    std::ifstream t("C:/Users/JaimeMTrillos/Dropbox/LabGraphics/LabGraphics2017/Exercise7/2/test.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    string tok = buffer.str();

    strings = split(tok);
    cout << "sorting the strings:" << endl;
    sort (strings.begin(), strings.end());
    print (strings);
    cout << endl;

    cout << "unique the strings:" << endl;
    vector<string> uniques = strings;
    unique (uniques.begin(), uniques.end());
    print (uniques);
    cout << endl;

    cout << "counting the words:" << endl;
    vector<int> counts_uniques = counts(uniques);
    cout<<endl;

}

int main()
{
    string str;
    cout << "Please enter a sentence: ";
    getline(cin, str);

    vector<string> strings;
    stringstream buffer(str); // Turn the string into a stream.
    string tok = buffer.str();
    strings = split(tok);
    cout << endl << "array of the string:" << endl;
    print (strings);
    cout << endl;

    cout << "sorting the strings:" << endl;
    sort (strings.begin(), strings.end());
    print (strings);
    cout << endl;

    cout << "unique the strings:" << endl;
    vector<string> uniques = strings;
    auto last = unique (uniques.begin(), uniques.end());
    uniques.erase (last, uniques.end());
    print (uniques);
    cout << endl;

    cout << "counting the sorted strings:" << endl;
    vector<int> counts_strings = counts(strings);
    cout << endl;

    cout << "counting the unique strings:" << endl;
    vector<int> counts_uniques = counts(uniques);
    cout << endl;

    testHistogram();
    return 0;
}
