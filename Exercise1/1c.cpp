#include <iostream>
#include <ctime>

using namespace std;

int main( int argc, char** argv) {
    string name;
    int day, month, year, currentYear, currentMonth, currentDay, age;
    //The user insert the birth date
    cout << "Insert your name:";
    cin >> name;
    cout << "Insert your birth year (yyyy): ";
    cin >> year;
    cout << "Insert your birth month (mm): ";
    cin >> month;
    cout << "Insert your birth day (dd): ";
    cin >> day;
    //The user insert the current year and month
    cout << "Insert the current year (yyyy): ";
    cin >> currentYear;
    cout << "Insert the current month (mm): ";
    cin >> currentMonth;
    cout << "Insert the current day (dd): ";
    cin >> currentDay;
    /*I calculate the age by knowing if the current month - month is greater than 0
    as the same time the current day - day is greater than 0, if it is greater then
    calculate the age, else age - 1*/
    if((currentMonth - month)>0 && (currentDay - day)>0){
        age = currentYear - year;
    }else {
        age = (currentYear - year)-1;
    }

    //Finally, I print the results
    cout << "\nHello " << name << " you have " << age << " years old." << endl;
}
