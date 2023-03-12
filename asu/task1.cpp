//      Computer Progamming [CSE 131s]
//               Task_1
//  Name: Ahmed Hussein AbdelKarim Raslan
//             ID: 2100714
//              Section: 7
//              Spring 2023
/*----------------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
float para(int x, int y, int z);
float ser(int x, int y, int z);

int main()
{
    string txt;
    getline(cin, txt);
    double vol;
    double req;
    cin >> vol;
    char method = txt[0];
    cout << txt << endl;
    txt = txt.substr(2, txt.length());

    float r1 = stof(txt);
    txt = txt.substr(txt.find(' ') + 1, txt.length());

    float r2 = stof(txt);
    txt = txt.substr(txt.find(' ') + 1, txt.length());

    float r3 = stof(txt);

    if (method == 'S')
        req = ser(r1, r2, r3);
    else if (method == 'P')
        req = para(r1, r2, r3);

    cout << vol / req;
}
float para(int x, int y, int z)
{
    return pow((pow(x, -1) + pow(y, -1) + pow(z, -1)), -1);
}
float ser(int x, int y, int z)
{
    return x + y + z;
}