#include <iostream>
#include "String.hpp"

void Test(String str) {}

int main() {
    String firstString = "Hi";
    cout << "firstString: "<< firstString << endl;
    cout << strlen(firstString) << endl;
    Test(firstString);
    cout << "firstString: "<< firstString << endl;
    cout << strlen(firstString) << endl;

    String t;
    t = firstString;
    cout << "firstString: "<< firstString << endl;
    cout << strlen(firstString) << endl;

    cout << "+ " << endl;
    String secondString = "Kotik";
    String newString = firstString + secondString;
    cout << "newString: "<< newString << endl;
    cout << "firstString: "<< firstString << endl;
    cout << "secondString: "<< secondString << endl;

    cout << "+= " << endl;
    String newFirstString = "Hello";
    char *newSecondString = "World";
    newFirstString += newSecondString;
    cout << "newFirstString: "<< newFirstString << endl;
    return 0;
}
