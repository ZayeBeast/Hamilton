#include <iostream>
#include <fstream>
#include <cstdlib>

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
