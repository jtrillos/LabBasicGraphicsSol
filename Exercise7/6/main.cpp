
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

string toLowerCase(string str){
    string lowStr("");
    for (string::iterator it = str.begin(); it != str.end(); ++it){
        char character = *it;
        lowStr += tolower(character);
    }
    return lowStr;
}


void print_map(map<string, string> m){
    cout << setw(12) << "        name: "<< " contact" << endl;
    for (map<string, string>::iterator it = m.begin(); it != m.end(); it++){
        cout << setw(12) << (*it).first << ":  " << (*it).second << endl;
    }
    cout << endl;
}

//printing vector<pair>
void print_vec(vector<pair<string, string>> vv){
    cout << setw(15) << "        contact: "<< "name" << endl;
    for (int i = 0; i != vv.size(); ++i) {
        cout << setw(15) << vv[i].first << ": " << vv[i].second << endl;
    }
}

int main()
{
    //string into lower case
    string test="Standard Template Library STL uses C++ templates to abstract away MANY differences of datatype implementations while not introducing ANY overhead!";
    cout << "Test: " << test << endl;
    string lower=toLowerCase(test);
    cout << "With tolowerCase: " << lower << endl;

    map<string, string> telephoneDic;
    //adding entries into telephone directory
    telephoneDic[toLowerCase("Max")] = "0157/123456";
    telephoneDic[toLowerCase("Stefan")] = "0228/3734342";
    telephoneDic[toLowerCase("Anne")] = "0228/7629431";
    telephoneDic[toLowerCase("Office")] = "0228/272930";
    telephoneDic[toLowerCase("Bank")] = "0228/2223332";
    cout << endl << "The telephone directory is "<<endl;
    print_map(telephoneDic);

    //Query the directory
    while (true){
        cout << endl << "Input some name: (input \"exit\" to finish)" << endl;
        string queryName;
        cin >> queryName;
        if (queryName == "exit"){
            break;
        }else{
            if (telephoneDic.find(queryName) != telephoneDic.end()){
                cout << "The telephone number of " << queryName << " is "
                    << telephoneDic.find(queryName)->second << endl;
            }else{
                string phoneNo;
                cout << "Please input the phone number for " << queryName << endl;
                cin >> phoneNo;
                telephoneDic[toLowerCase(queryName)] = phoneNo;
            }
        }
    }
    //creation of vector pairs
    cout << endl;
    vector<pair<string, string>> telephoneDic_vec;
    //Adding entries to vector pairs
    for (map<string, string>::iterator it = telephoneDic.begin(); it != telephoneDic.end(); ++it){
        telephoneDic_vec.push_back(make_pair((*it).second, (*it).first));
    }
    print_vec(telephoneDic_vec);

    //Sorting the vector
    sort(telephoneDic_vec.begin(), telephoneDic_vec.end());
    cout << endl << "After sorting:" << endl;
    print_vec(telephoneDic_vec);

    //Reversing the previous vector (reverse)
    reverse(telephoneDic_vec.begin(), telephoneDic_vec.end());
    cout << endl << "After reversing: " << endl;
    print_vec(telephoneDic_vec);

    return 0;
}
