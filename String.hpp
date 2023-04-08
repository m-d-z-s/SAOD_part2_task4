#ifndef TASK4_STRING_HPP
#define TASK4_STRING_HPP

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String {
    char *text;
public:
    String() { text = new char[1]{0}; }

    String(const String &string) {
        text = new char[strlen(string.text) + 1];
        strcpy_s(text, strlen(string.text) + 1, string.text);
    }

    String(const char *pointerOfString) {
        if (pointerOfString) {
            text = new char[strlen(pointerOfString) + 1];
            strcpy_s(text, strlen(pointerOfString) + 1, pointerOfString);
        } else
            text = new char[1]{0};
    }

    ~String() { delete[]text; }


    operator const char *() const { return text; }

    const String &operator=(const String &string) {
        if (&string == this) return *this;
        delete[]text;

        text = new char[strlen(string.text) + 1];
        strcpy_s(text, strlen(string.text) + 1, string.text);
        return *this;
    }

    String operator+(const char *string) const {
        char *concatenatedString = new char[strlen(text) + strlen(string) + 1];
        char *p = concatenatedString;
        strcpy_s(concatenatedString, strlen(text) + 1, text);
        p += strlen(text);

        while (*string) {
            *p++ = *string++;
        }
        return String(concatenatedString);
    }


    String& operator +=(const char *string) {
        char* newContainer = new char[strlen(text) + strlen(string) + 1];
        char* p = newContainer;
        cout << strlen(text) + strlen(string) + 1 << endl;
        strcpy_s(newContainer, strlen(text) + 1, text);
        p += strlen(text);

        while (*string) {
            *p++ = *string++;
        }

        delete[]text;
        text = new char[strlen(newContainer) + 1];
        strcpy_s(text, strlen(newContainer) + 1, newContainer);
        return *this;
    }
};

#endif //TASK4_STRING_HPP
