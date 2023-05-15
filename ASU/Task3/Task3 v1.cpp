/*      Computer Progamming [CSE 131s]    */
/*                Task_3                  */
/*  Name: Ahmed Hussein AbdelKarim Raslan */
/*            ID: 2100714                 */
/*            Section: 7                  */
/*             Spring 2023                */
/*----------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

// functions declaration

double ser(string txt);
double para(string txt);

int main()
{
    string test = "S S 4.7 4.7 e 4.7 4.7 E";
    cout << ser(test.substr(2)) << endl;
}
double ser(string txt)
{
    double ser_sum = 0;
    int pos;
    for (int i = 0; i < txt.size(); i++)
    {
        if (isalpha(txt[i]))
        {
            pos = i;
            break;
        }
    }
    string aux;
    if(txt.find('e')!=string::npos){
    aux = txt.substr(pos + 2, txt.find('e') - 2 );
    }
    if (txt[pos] == 'S')
    {
        txt.replace(txt.find(aux), aux.size() + 4, to_string(ser(aux)));
    }
    else if (txt[pos] == 'P')
    {
        txt.replace(txt.find(aux), aux.size() + 4, to_string(para(aux)));
    }
    else if (isalpha(txt[pos]))
    {
        cout << "Wrong Circuit Description" << endl;
        exit(0);
    }
while (isdigit(txt[0]))
    {
        ser_sum += (1.0 / stod(txt));
        txt = txt.substr(2);
    }


    return ser_sum;

}

double para(string txt)
{
    double ser_para;
    while (isdigit(txt[0]))
    {
        ser_para += (1.0 / stod(txt));
        txt = txt.substr(2);
    }
    string aux;
    int pos;
    for (int i = txt.find('e'); i > 0; i--)
    {
        if (isalpha(txt[i]))
        {
            pos = i;
            break;
        }
    }
    aux = txt.substr(pos + 2, txt.find('e') - pos - 2);
    if (txt[pos] == 'S')
    {
        txt.replace(txt.find(aux), aux.size(), to_string(ser(aux)));
    }
    else if (txt[pos] == 'P')
    {
        txt.replace(txt.find(aux), aux.size(), to_string(para(aux)));
    }
    else if (isalpha(txt[pos]))
    {
        exit(0);
    }

    return 1.0 / ser_para;
}