#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout("new_students.txt", ios::out); //if the file exists - overwrites
                                                //if we replace "ios::out" with "ios::app", the old content of the file
                                                //will be kept and the new records will appear at the end
    if(!fout)
    {
        cerr << "The file cannot be open!\n";
        return 1;
    }
    int fn;
    char name[40];
    double grade;

    while (cin >> fn)
    {
        cin >> name >> grade;
        fout << fn << " " << name << " " << grade << endl;
    }
    return 0;
}
