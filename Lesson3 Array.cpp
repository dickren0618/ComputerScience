#include <iostream>
using namespace std;
void main()
{
    const char key[] = { 'a','b','c','d'};
    char c;
    int ques = 0, numques = 4, numcorrect = 0;
    cout << "Enter the " << numques << " question tests" << endl;
    while (cin.get(c))
    {
        if (c != '\n')
            if (c == key[ques])
            {
                numcorrect++;
                cout << " ";
            }
            else
                cout << "*";
        else
        {
            cout << "Score" << float(numcorrect) / numques * 100 << "%";
            ques = 0;
            numcorrect = 0;
            cout << endl;
            continue;
        }
        ques++;
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单


