#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateTXT(char* fname) // створення файлу з введених рядків
{
    ofstream fout(fname); // відкрили файл для запису
    char ch; // відповідь користувача – чи продовжувати введення
    string s; // введений користувачем рядок
    do
    {
        cin.get(); // очищуємо буфер клавіатури – щоб не було символу
        cin.sync(); // "кінець рядка", який залишився після вводу числа
        cout << "enter line: "; getline(cin, s); // ввели рядок
        fout << s << endl; // записали його у файл
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}
void PrintTXT(char* fname) // виведення файлу на екран
{
    ifstream fin(fname); // відкрили файл для зчитування
    string s; // прочитаний рядок
    while (getline(fin, s)) // поки можна прочитати рядок
    {
        cout << s << endl; // виводимо його на екран
    }
    cout << endl;
}
int ProcessTXT1(char* fname)
{
    ifstream fin(fname);
    string s;

    int maxLen = 0;

    while (getline(fin, s))
    {
        int currentLen = 0;

        for (wchar_t c : s)
        {
            if (iswalnum(c))
            {
                currentLen++;
            }
            else
            {
                if (currentLen > maxLen)
                {
                    maxLen = currentLen;
                }
                currentLen = 0;
            }
        }

        if (currentLen > maxLen)
        {
            maxLen = currentLen;
        }
    }

    return maxLen;
}
int main()
{
    char fname[100];
    cout << "enter file name: ";
    cin >> fname;
    CreateTXT(fname);
    PrintTXT(fname);
    cout << "Maximum Length: " << ProcessTXT1(fname) << endl;
    return 0;
}
