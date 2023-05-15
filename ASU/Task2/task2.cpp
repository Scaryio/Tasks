      /*      Computer Progamming [CSE 131s]    */
     /*                Task_2                  */
    /*  Name: Ahmed Hussein AbdelKarim Raslan */
   /*            ID: 2100714                 */
  /*            Section: 7                  */
 /*             Spring 2023                */
/*----------------------------------------*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double ser(string txt);
double para(string txt); // Functions declarations
int main()
{
    string txt;
    cout << "Circuit description: ";
    getline(cin >> ws, txt); // User input for circuit description
    double vol;
    double req;
    cout << "Voltage applied: ";
    cin >> vol; // User input for supply voltage

    if (toupper(txt[0]) == 'S') // if the resistances are series
    {
        req = ser(txt);
    }
    else if (toupper(txt[0]) == 'P') // if the resistances are parallel
    {
        req = para(txt);
    }
    else
    {
        cout << "Wrong Circuit Description." << endl; // In case the user inputs a wrong method of connection.
        return 1;
    }
    cout << "Total resistances: " << req << endl;
    cout << "Circuit current = " << vol / req << endl;
    return 0;
}

double ser(string txt) // Function to calculate series resistances
{
    double rs = 0;
    txt = txt.substr(2, txt.length());
    while (txt[0] != 'E')
    {
        rs += stod(txt);
        txt = txt.substr(txt.find(" ") + 1, txt.size());
    }
    return rs;
}
double para(string txt) // Function to calculate parallel resistances
{
    double rp = 0;
    txt = txt.substr(2, txt.length());

    while (txt[0] != 'E')
    {
        rp += pow(stod(txt), -1);
        txt = txt.substr(txt.find(" ") + 1, txt.size());
    }
    return pow(rp, -1);
}