#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
    vector<vector<string>> arr;
    int n = 0;
    vector<string> shape = {"Rectangle", "Triangle", "Ellipse", "Line"};
    bool retype = false;
    while(1)
    {
        fstream data;
        string filename;
        cout << "Enter file name: ";
        cin >> filename;
        data.open(filename, ios::in);
        if (!data.is_open())
        {
            cout << "File does not exist!!! Please re-enter another file name!!!" << endl;
            retype = true;
        }
        else
        {
            while(!data.eof())
            {   
                arr.resize(n+1);
                arr.at(n).resize(4);
                string str = "";
                data >> str;
                if (str[0] = '[')
                {
                    for (int i = 0; i < 4; i++)
                        for (int j = 0; j < 3; j++)
                            data >> arr.at(n).at(i);
                }
                else
                {
                    cout << "The file have wrong data format!!!";
                    retype = true;
                    break;
                }
                n++;
            }
        }  
        if (!retype)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << arr.at(i).at(j) << " ";
        cout << endl;
    }
    return 0;
}