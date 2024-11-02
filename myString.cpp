#include "myString.h"

MyString::MyString(const char* str) {
    length = std::strlen(str);
    charArray =  new char[length + 1];

        for (int i = 0; i <= length; i++) {
            charArray[i] = str[i];
     };
}