#include "myString.h"

MyString::MyString(const char* str) {
    if (str) {
        length = 0;
        while (str[length] != '\0') {
            length++;
        }
        charArray = new char[length + 1];
        for (size_t i = 0; i <= length; i++) {
            charArray[i] = str[i];
        }
    } else {
        length = 0;
        charArray = new char[1];
        charArray[0] = '\0';
    }
}

MyString::~MyString() {
    delete[] charArray;
}

MyString::MyString(const MyString& other) {
    length = other.length;
    charArray = new char[length + 1];
    for (size_t i = 0; i <= length; i++) {
        charArray[i] = other.charArray[i];
    }
}

MyString& MyString::operator=(const MyString& other)  noexcept {
    if (this != &other) {
        delete[] charArray;
        length = other.length;
        charArray = new char[length + 1];
        for (size_t i = 0; i <= length; i++) {
            charArray[i] = other.charArray[i];
        }
    }
    return *this;
}

std::string MyString::toString() const {
    std::string result;
    for (size_t i = 0; i < length; i++) {
        result += charArray[i];
    }
    return result;
}

size_t MyString::getLength() const {
    return length;
}

MyString MyString::substr(size_t start, size_t n) const {
    if (start >= length || start < 0) {
        return MyString("");
    }
    size_t newLength = (n == SIZE_MAX) ? (length - start) : std::min(n, length - start);
    char* subStr = new char[newLength + 1];
    for (size_t i = 0; i < newLength; i++) {
        subStr[i] = charArray[start + i];
    }
    subStr[newLength] = '\0';
    MyString result(subStr);
    delete[] subStr;
    return result;
}

MyString MyString::operator+(const MyString& other) const {
    size_t newLength = length + other.length;
    char* newData = new char[newLength + 1];
    for (size_t i = 0; i < length; i++) {
        newData[i] = charArray[i];
    }
    for (size_t j = 0; j <= other.length; j++) {
        newData[length + j] = other.charArray[j];
    }
    MyString result(newData);
    delete[] newData;
    return result;
}

bool MyString::operator==(const MyString& other) const {
    size_t minLength = length < other.length ? length : other.length;
    for (size_t i = 0; i < minLength; i++) {
        if (charArray[i] != other.charArray[i]) {
            return false;
        }
    }
    return length == other.length;
}

bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

bool MyString::operator<(const MyString& other) const {
    size_t minLength = length < other.length ? length : other.length;
    for (size_t i = 0; i < minLength; i++) {
        if (charArray[i] != other.charArray[i]) {
            return charArray[i] < other.charArray[i];
        }
    }
    return length < other.length;
}

bool MyString::operator<=(const MyString& other) const {
    return *this < other || *this == other;
}

bool MyString::operator>(const MyString& other) const {
    return !(*this <= other);
}

bool MyString::operator>=(const MyString& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
    return os << myStr.charArray;
}
