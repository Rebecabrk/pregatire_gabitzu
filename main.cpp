#include <iostream>
#include <fstream>

ifstream fin("date.txt");

using namespace std;

struct ELEV
{
    int cod;
    char nume[51];
    float media;
} e, clasa[30];

int main()
{
    int n;
    fin >> n;
    fin.getline();
    for (int i = 1; i <= n; i++)
    {
        fin >> clasa[i].cod;
        fin >> clasa[i].nume;
        fin >> clasa[i].media;
    }
    fin.close();
    for (int i = 1; i <= n; i++)
    {
        cout << clasa[i].cod << " " << clasa[i].nume << " " << clasa[i].media << endl;
    }

    return 0;
}
