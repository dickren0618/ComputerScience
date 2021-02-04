#include <iostream>
#include<string>
using namespace std;
inline void test(const char* title, bool value)
{
    cout << title << "returns " << (value ? "true" : "false") << endl;
}
void main()
{
    cout << "Hello World!\n";
    string s1 = "DEF";
    cout << "s1 is " << s1 << endl;
    string s2;
    cout << "Please enter s2: ";
    getline(cin,s2,'\n');//getline 比 cin 好的地方在于空格可输入,第三个参数是指结束标识符;
    cout << "length of s2: " << s2.length() << endl;

    test("s1 <= \"ABC\"", s1 <= "ABC");
    test("\"DEF\"<=s1 ", "DEF" <= s1);

    s2 += s1;
    cout << "s2=s2+s1:" << s2 << endl;
    cout << "Length of s2:" << s2.length() << endl;

}

//
