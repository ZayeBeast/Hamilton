#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
string decision;
int main()
{
    cout << "co chcesz zrobiæ";
    cin >> decision;
    if (decision == "HamiltonA");
        HamiltonA()
    else if decision == "HamiltonB";
            HamiltonB;
        else cout << "try again";
}

HamiltonA()
{
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
}
HamiltonB()
{
using namespace std;
int n=0;
int main()
{
    system("echo %cd%");
    int *numbers=NULL;
    string *people=NULL,*gamelist=NULL;
    string message,line;
    ifstream file;
    file.open ("UsersData.txt");
    if (file.is_open())
    {
        while(getline(file,line))
            ++n;
        people = new string[n];
        file.clear();
        file.seekg(0);
        for(int i=0;getline(file,line);++i)
            people[i] = line; //koniec operowania na danych z tego pliku
        gamelist = new string[n];
        file.clear();
        file.seekg(0);
        for(int i=0;getline(file,line);++i)
            {
            cout << line << '\n';
            gamelist[i] = line;
            }
    }
    ifstream nextfile;
    nextfile.open ("CircleOfLife.txt");
    if (nextfile.is_open())
    {
        numbers = new int[n];
        for(int i=0;i<n;++i)
            nextfile >> numbers[i];
    }
    getline(cin, message);
    cout << message;
    if (message == "display")
        for(int i=0;i<n;++i)
            cout << gamelist[numbers[i]] << '\n';
    else {
        for(int i=0;i<n;++i)
            if (message == gamelist[i])
            {
                for(;i<n;++i)
                {
                    i = i%n;
                    gamelist[i]=gamelist[i+1];
                }
                --n;
                cout << n;
                cout << "Deleted from the circle" << '\n';
                for(int k=0;k<n;++k)
                cout << gamelist[numbers[k]] << '\n';
            }
    }
    return 0;
}
}
