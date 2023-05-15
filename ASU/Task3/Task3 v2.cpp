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
string solve(string circuit);
string last_to_lower(string text);
vector<string> strtoken(string text);
bool not_float(string str);

int main()
{
    // ask user to input circuit description and voltage
    string user_input, resistance;
    double voltage, current;
    cout << "Circuit description: ";
    getline(cin, user_input);
    cout << "Voltage applied: ";
    cin >> voltage;
    resistance = solve(last_to_lower(user_input));
    current = voltage / stod(resistance);
    cout << "Total Resistance: " << resistance << endl; // prints resistance
    cout << "Current Intensity: " << current;           // prints current
}

string solve(string txt)
{
    for (int i = 0; i < txt.length(); i++)
    {
        int index;
        char type;
        char c = txt[i];
        if (isalpha(c) != 0 && c != 'e') // finds the first letter before letter "e"
        {
            index = i;
            type = c;
        }
        else if (c == 'e')
        {
            string aux = txt.substr(index + 2, i - index - 3);
            vector<string> connection = strtoken(aux); // stores circuit in a vector
            double total_res = 0;
            if (type == 'S')
            {
                for (int j{}; j < connection.size(); j++) // adds elements of vector if series
                {
                    total_res += stod(connection[j]);
                }
            }
            else if (type == 'P')
            {
                double rec_total_res = 0;
                for (int k{}; k < connection.size(); k++)
                {
                    rec_total_res += 1 / stod(connection[k]); // adds reciprocal of elements of vector if parallel
                }
                total_res = 1 / rec_total_res;
            }
            else
            {
                cout << "Wrong Circuit Description"; // if wrong description
                exit(0);
            }
            txt = txt.replace(index, i + 1 - index, to_string(total_res));
            if (not_float(txt))
            {
                txt = solve(txt);
                break;
            }
        }
    }
    return txt;
}

string last_to_lower(string text) // function converts letter E to lower (e) to match with other functions
{
    int length = text.length();
    string txt = text.substr(0, length - 1);
    txt += (char)(text[length - 1] + 32);
    return txt;
}

vector<string> strtoken(string text)
{
    int first_space = 0;
    vector<string> result;
    text += ' ';
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            result.push_back(text.substr(first_space, i - first_space));
            first_space = i + 1;
        }
    }
    return result;
}

bool not_float(string str) // function avoids any error due to misuse of stof func.
{
    try
    {
        stof(str);
        return false;
    }
    catch (...)
    {
        return true;
    }
}
