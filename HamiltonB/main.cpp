#include <iostream>
#include <fstream>

using namespace std;
int n=0;
int main()
{
    string *people=NULL;
    string message,line;
    ifstream file;
    file.open ("UsersData.txt");
    if (file.is_open())
        while(getline(file,line))
            ++n;
        people = new string[n];
        file.clear();
        file.seekg(0);
        for(int i=0;getline(file,line);++i)
            people[i] = line;
        cin >> message;
        if (message == "display")
            for(int i=0;i<n;++i)
                cout << people[i] << '\n';
        else {for(int i=0;i<n;++i)
                if (message==people[i])
                    for(;i<n;++i)
                    {
                        people[i]=people[i-1];
                        --n;
                    }
                        for(int i=0;i<n;i++)
                        cout << people[i] << '\n';
            }


    return 0;
}
