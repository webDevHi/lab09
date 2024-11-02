//AI prompt: pleasecreate a test file using Google's testing framework to test my following code
// 'ipnutted code
#include "myString.h"
#include <gtest/gtest.h>

class MyStringTest : public ::testing::Test {
protected:
    MyString* str1;
    MyString* str2;

    void SetUp() override {
        str1 = new MyString("Hello");
        str2 = new MyString("World");
    }

    void TearDown() override {
        delete str1;
        delete str2;
    }
};

TEST_F(MyStringTest, ConstructorFromCStr) {
    MyString emptyStr("");
    EXPECT_EQ(emptyStr.getLength(), 0);
    EXPECT_EQ(strcmp(emptyStr.charArray, ""), 0);
}

TEST_F(MyStringTest, ConstructorFromNull) {
    MyString nullStr(nullptr);
    EXPECT_EQ(nullStr.getLength(), 0);
    EXPECT_EQ(strcmp(nullStr.charArray, ""), 0);
}

TEST_F(MyStringTest, CopyConstructor) {
    MyString copyStr(*str1);
    EXPECT_EQ(copyStr.getLength(), str1->getLength());
    EXPECT_EQ(strcmp(copyStr.charArray, str1->charArray), 0);
}

TEST_F(MyStringTest, AssignmentOperator) {
    MyString assignedStr("Temp");
    assignedStr = *str1;
    EXPECT_EQ(assignedStr.getLength(), str1->getLength());
    EXPECT_EQ(strcmp(assignedStr.charArray, str1->charArray), 0);
}

TEST_F(MyStringTest, Concatenation) {
    MyString result = *str1 + *str2;
    EXPECT_EQ(result.getLength(), 10);
    EXPECT_EQ(strcmp(result.charArray, "HelloWorld"), 0);
}

TEST_F(MyStringTest, EqualityOperator) {
    MyString sameStr("Hello");
    MyString differentStr("World");
    EXPECT_TRUE(*str1 == sameStr);
    EXPECT_FALSE(*str1 == differentStr);
}

TEST_F(MyStringTest, InequalityOperator) {
    MyString sameStr("Hello");
    MyString differentStr("World");
    EXPECT_FALSE(*str1 != sameStr);
    EXPECT_TRUE(*str1 != differentStr);
}

TEST_F(MyStringTest, LessThanOperator) {
    EXPECT_TRUE(*str1 < *str2);
    EXPECT_FALSE(*str2 < *str1);
}

TEST_F(MyStringTest, GreaterThanOperator) {
    EXPECT_TRUE(*str2 > *str1);
    EXPECT_FALSE(*str1 > *str2);
}

TEST_F(MyStringTest, Substring) {
    MyString subStr = str1->substr(1, 3);
    EXPECT_EQ(subStr.getLength(), 3);
    EXPECT_EQ(strcmp(subStr.charArray, "ell"), 0);
}

TEST_F(MyStringTest, SubstringOutOfBounds) {
    MyString subStr = str1->substr(10, 5);
    EXPECT_EQ(subStr.getLength(), 0);
    EXPECT_EQ(strcmp(subStr.charArray, ""), 0);
}

TEST_F(MyStringTest, SubstringWithNegativeStart) {
    MyString subStr = str1->substr(-1, 5);
    EXPECT_EQ(subStr.getLength(), 0);
    EXPECT_EQ(strcmp(subStr.charArray, ""), 0);
}

TEST_F(MyStringTest, GetLength) {
    EXPECT_EQ(str1->getLength(), 5);
    EXPECT_EQ(str2->getLength(), 5);
}

TEST_F(MyStringTest, ToString) {
    EXPECT_EQ(str1->toString(), "Hello");
    EXPECT_EQ(str2->toString(), "World");
}

TEST_F(MyStringTest, StreamOutput) {
    std::ostringstream oss;
    oss << *str1;
    EXPECT_EQ(oss.str(), "Hello");
}

TEST_F(MyStringTest, MemoryManagement) {
    MyString original("Memory");
    MyString copy = original;
    EXPECT_EQ(copy.getLength(), original.getLength());
    EXPECT_EQ(strcmp(copy.charArray, original.charArray), 0);
    copy = "Test";
    EXPECT_NE(strcmp(copy.charArray, original.charArray), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
