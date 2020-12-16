#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Automat.h"

using namespace std;

int main() {
    locale::global(locale(""));
    try {
        ifstream file;
        string f, substr, s;
        cout << "Введите путь к файлу: ";
        cin >> f;
        file.open(f);
        if (!file)
            throw exception("Ошибка при открытии файла\n");
        cin.get();
        cout << "Введите подстроку: ";
        getline(cin, substr);
        cout << endl;
        Automat t(substr);
        int str = 0;
        while (!file.eof())
        {
            t.reset();
            getline(file, s);
            for (size_t i = 0; i < s.length(); i++) {
                if (t.next(s[i])) {
                    cout << "Строка - " << str << " | " << "Колонка - " << i + 1 - substr.length() << endl;
                }
            }
            str++;
        }
        file.close();
    }
    catch (exception e) {
        cout << "Ошибка: " << e.what();
    }
    system("pause");
    return 0;
}