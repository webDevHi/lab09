#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

class MyString {

public: 
    char* charArray;
    size_t length;
    
    MyString(const char* str);

    ~MyString();

    MyString(const MyString& other);

    std::string toString() const;

    size_t getLength() const;

    MyString substr(int start, int n = SIZE_MAX) const;

    MyString operator+(const MyString& other) const;

    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr);

    };

#endif // MYSTRING_H