#include <iostream>
#include <string>

using namespace std;

int isfeet(string);

class Distance
{
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0)
    {  }
    Distance(int ft, float inch) : feet(ft), inches(inch)
    {  }
    void showdist() const
     
        cout << feet << "\' - " << inches << '\x22';
    }
    void getdist();
};

void Distance::getdist()
{
    string str;
    while (true)
    {
        cout << "Введите количество футов: ";
        cin.unsetf(ios::skipws);
        cin >> str;                    ///// SOS!!!
        if (isfeet(str))
        {
            cin.ignore(10, '\n');
            feet = atoi(str.c_str());
            break;
        }
        cin.ignore(10, '\n');
        cout << "Футы должны быть целым числом <1000\n";
    }
    while (true)
    {
        cout << "Введите дюймы: ";
        cin.unsetf(ios::skipws);
        cin >> inches;
        if (inches < 0.0 || inches >= 12.0)
        {
            cout << "Дюймы должны быть >0.0 и меньше <12.0!!!\n";
            cin.clear(ios::failbit);
        }
        if (cin.good())
        {
            cin.ignore(10, '\n');
            break;
        }
        cin.clear();
        cin.ignore(10, '\n');
        cout << "Неверно введены дюймы!!!\n";
    }
}

int isfeet(string s)
{
    int len = s.size();
    if (len == 0 || len >= 5)
        return 0;
    for (int j = 0; j < len; j++)
        if ((s[j] < '0' || s[j] > '9') && s[j] != '-')
            return 0;
    double d = atof(s.c_str());
    if (d < -999.0 || d > 999.0)
        return 0;
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    char answ;
    Distance d;
    do
    {
        d.getdist();
        cout << "\nd = "; d.showdist();
        cout << "\nПродолжить (y/n)??? "; cin >> answ;
        cin.ignore(10, '\n');
    } while (answ != 'n');
    cout << endl;
    return 0;
}