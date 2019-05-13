#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

bool isinarr(int x, int arr[], int n)
{
    for(int i=0;i<n;++i)
        if (x==arr[i])
            return true;
    return false;
}

int main()
{
    srand(time(NULL));
    string *lista=NULL;
    int *circle=NULL;
    int n=0;
    string line;
    ifstream file;
    file.open("UsersData.txt",ios::in);
    if(file.is_open())
    {
        while(getline(file,line))
            ++n;
        file.clear();
        file.seekg(0, ios::beg);
        cout << n << '\n';
        lista = new string[n];
        circle = new int[n];
        for(int i=0;i<n;++i)
            circle[i]=-1;
        for(int i=0;getline(file,line);i++)
            lista[i] = line;
        file.close();
    }
    else cout << "Unable to open the file";
    for(int i=0;i<n;++i)
    {
        int k;
        do  k=rand()%n;
        while( isinarr(k, circle, n));
        circle[i]=k;
        cout << k << '\n';
    }
    ofstream finish;
    finish.open ("CircleOfLife.txt");
    for(int i=0;i<n;++i)
    {
        finish << circle[i] << '\n';
    }
    delete[] lista;
    return 0;
}
