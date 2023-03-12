  //-----Matrix oprations-----//


#include <iostream>
using namespace std;

// declerations
int **getArray(int x);
//oid prnt1(int **arr, int size);
void adding(int **arr1, int **arr2, int x);
void subtarr(int **arr1, int **arr2, int x);
void multis(int **arr1, int **arr2, int x);
int main()
{
    int **arr1;
    int **arr2;
    int size;
    cout << "Enter arrays Size " << endl;
    string op;
    cin >> size;
    cout << "Enter 1st Mat " << endl;
    arr1 = getArray(size);
    cout << "Enter 2nd Mat " << endl;
    arr2 = getArray(size);

    cout << "Operation ?\n + - * / det\n";
    cin >> op;
if (op == "+"){
    adding(arr1, arr2, size);

}
else if (op == "-"){
    subtarr(arr1, arr2, size); 

}
else if (op == "*"){
    multis(arr1, arr2, size);

}
else if (op == "/"){

}
else if (op == "det"){

}


    return 0;
}

// setter
int **getArray(int x)
{
    int **arr = new int *[x];
    for (int i = 0; i < x; i++)
    {
        arr[i] = new int[x];
        for (int j = 0; j < x; j++)
        {
            cin >> arr[i][j];
        }
    }
    return arr;
}

// adding fnc
void adding(int **arr1, int **arr2, int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << arr1[i][j] + arr2[i][j] << " ";
        }
        cout << endl;
    }
}

// subtracing fnc
void subtarr(int **arr1, int **arr2, int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << arr1[i][j] - arr2[i][j] << " ";
        }
        cout << endl;
    }
}


//multiplying fnc
void multis(int **arr1, int **arr2, int x)
{
    int res[x][x];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            res[i][j] = 0; // initializing a zero matrix
        }
    } 
// filling the matrix
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < x; k++)
            {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    //printing result
    for (int i = 0; i < x; i++)
    {

        for (int j = 0; j < x; j++)
        {

            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}
