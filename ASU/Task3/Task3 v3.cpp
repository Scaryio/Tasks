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
    
    string test = "S P 4.7 4.7 e 4.7 4.7 E";
    cout <<ser(test)<< endl;
}
double ser(string txt)
{
    double ser_sum = 0;
    txt = txt.substr(2);
    string aux;
    
    while(txt.find('S')!=string::npos)
    {
    aux = txt.substr(txt.find('S'),txt.find('e')- txt.find('S') + 1) ;
    txt.replace(txt.find(aux) , aux.size() , to_string(ser(aux)));
    }
    while(txt.find('S')!=string::npos){
    aux = txt.substr(txt.find('P'),txt.find('e')- txt.find('P') + 1) ;
    txt.replace(txt.find(aux) , aux.size() , to_string(para(aux)));
    }
    
    while(isdigit(txt[0])){
        ser_sum += stod(txt);
        txt = txt.substr(txt.find(" ") + 1);
    }
    return ser_sum;
}

double para(string txt)
{
    double para_sum = 0;
    double rec = 0;
    txt = txt.substr(2);
    string aux;
    
    while(txt.find('S')!=string::npos)
    {
    aux = txt.substr(txt.find('S'),txt.find('e')- txt.find('S') + 1) ;
    txt.replace(txt.find(aux) , aux.size() , to_string(ser(aux)));
    }
    while(txt.find('S')!=string::npos){
    aux = txt.substr(txt.find('P'),txt.find('e')- txt.find('P') + 1) ;
    txt.replace(txt.find(aux) , aux.size() , to_string(para(aux)));
    }
    
    while(isdigit(txt[0])){
        rec +=(1.0 /stod(txt));
        txt = txt.substr(txt.find(" ")+ 1);
    }
    para_sum = 1.0/rec;
    return para_sum;
}
