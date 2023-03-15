      /*      Computer Progamming [CSE 131s]    */
     /*                Task_1                  */
    /*  Name: Ahmed Hussein AbdelKarim Raslan */
   /*            ID: 2100714                 */ 
  /*            Section: 7                  */ 
 /*             Spring 2023                */
/*----------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

//Declearing func. to caluclate R.equivalent.
float para(int x, int y, int z);
float ser(int x, int y, int z);

int main()
{
    string txt;
    cout << "Circuit description: ";
    getline(cin, txt);//Inputs the circuit description.
    int vol;
    double req;
    cout << "Voltage applied: ";
    cin >> vol; // Inputs the applied voltage
    char method = txt[0]; //checks the type of connection "S" for Series or "P" for parallel

    float r1 = stof(txt.substr(2, 1)); //takes 1st number in txt as 1st resistance

    float r2 = stof(txt.substr(4, 1)); //takes 2nd number in txt as 2nd resistance

    float r3 = stof(txt.substr(6, 1)); //takes 3rd number in txt as 3rd resistance

    if (method == 'S')
        req = ser(r1, r2, r3);
    else if (method == 'P')
        req = para(r1, r2, r3);
    cout << "Total resistances: " << req << endl;
    cout << "Circuit current = " << vol / req << endl;
}

float para(int x, int y, int z) //Function to calculate parallel resistances
{
    return pow((pow(x, -1) + pow(y, -1) + pow(z, -1)), -1);
}
float ser(int x, int y, int z)//Function to calculate series resistances
{
    return x + y + z;
}
