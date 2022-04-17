#include<iostream>
#include<iomanip>
#include"time.h"

using namespace std;

Time::Time() : hour(22), minute(58), second(58) {}

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

Time::Time(const Time& timeCopy) {
    this->hour = timeCopy.hour;
    this->minute = timeCopy.minute;
    this->second = timeCopy.second;
}

void Time::changeTime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void Time::print()
{
    cout << setw(2) << setfill('0') << hour << ":"
        << setw(2) << setfill('0') << minute << ":"
        << setw(2) << setfill('0') << second << "\n";
}

Time& operator --(Time& temp) {
    int flag = 1, c;

    while (flag == 1)
    {
        cout << "Что уменьшить?" << endl;
        cout << "1 - часы" << endl;
        cout << "2 - минуты" << endl;
        cout << "3 - секунды" << endl;
        cout << "0 - выход" << endl;
        cout << "--> ";
        cin >> c;

        switch (c)
        {
        case 1:
            system("cls");
            if (temp.hour == 0) {
                temp.hour = 23;
                cout << "\n";
                break;
            }
            temp.hour -= 1;
            break;
            cout << "\n";
        case 2:
            system("cls");
            if (temp.minute == 0) {
                temp.minute = 59;
                cout << "\n";
                break;
            }

            temp.minute -= 1;
            break;
            cout << "\n";
        case 3:
            system("cls");
            if (temp.second == 0) {
                temp.second = 59;
                cout << "\n";
                break;
            }
            temp.second -= 1;
            cout << "\n";
            break;
        case 0: //0 - Выход
            system("cls");
            cout << "\n";
            flag = 0;
            break;
        default:
            system("cls");
            cout << "\n";
            flag = 0;
            break;
        }
    }

    return temp;
}
Time& operator ++(Time& temp) {

    int flag = 1, c;

    while (flag == 1)
    {
        cout << "Что увеличить?" << endl;

        cout << "1 - часы" << endl;
        cout << "2 - минуты" << endl;
        cout << "3 - секунды" << endl;
        cout << "0 - выход" << endl;
        cout << "--> ";
        cin >> c;

        switch (c)
        {
        case 1:
            system("cls");
            if (temp.hour == 24) {
                temp.hour = 1;
                cout << "\n";
                break;
            }
            temp.hour += 1;
            break;
            cout << "\n";
        case 2:
            system("cls");
            if (temp.minute == 59) {
                if (temp.hour == 24) {
                    temp.hour = 1;
                    temp.minute = 0;
                    cout << "\n";
                    break;
                }
                else {
                    temp.hour += 1;
                    temp.minute = 0;
                    break;
                }
            }

            temp.minute += 1;
            break;
            cout << "\n";
        case 3:
            system("cls");
            if (temp.second == 59) {
                if (temp.minute == 59) {
                    if (temp.hour == 24) {
                        temp.hour = 1;
                        temp.minute = 0;
                        temp.second = 0;
                        cout << "\n";
                        break;
                    }
                    else {
                        temp.hour += 1;                        
                        temp.minute = 0;
                        temp.second = 0;
                        break;
                    }
                }
                else {
                    temp.minute += 1;
                    temp.second = 0;
                    break;
                }
            }
            temp.second += 1;
            cout << "\n";
            break;
        case 0: //0 - Выход
            system("cls");
            cout << "\n";
            flag = 0;
            break;
        default:
            system("cls");
            cout << "\n";
            flag = 0;
            break;
        }
    }

    return temp;
}

Time& Time::operator --(int) {
    Time temp(*this);
    int flag = 1, c;

        while (flag == 1) {

            cout << "Что уменьшить?" << endl;

            cout << "1 - часы" << endl;
            cout << "2 - минуты" << endl;
            cout << "3 - секунды" << endl;
            cout << "0 - выход" << endl;
            cout << "--> ";
            cin >> c;

            switch (c)
            {
            case 1:
                system("cls");
                if (this->hour == 0) {
                    this->hour = 23;
                    cout << "\n";
                    break;
                }
                this->hour -= 1;
                break;
                cout << "\n";
            case 2:
                system("cls");
                if (this->minute == 0) {
                    this->minute = 59;
                    cout << "\n";
                    break;
                }

                this->minute -= 1;
                break;
                cout << "\n";
            case 3:
                system("cls");
                if (this->second == 0) {
                    this->second = 59;
                    cout << "\n";
                    break;
                }
                this->second -= 1;
                cout << "\n";
                break;
            case 0: //0 - Выход
                system("cls");
                cout << "\n";
                flag = 0;
                break;
            default:
                system("cls");
                cout << "\n";
                flag = 0;
                break;
            }
        }

    return temp;
}

Time& Time::operator ++(int) {
    Time temp(*this);

    int flag = 1, c;

    while (flag == 1)
    {
        cout << "Что увеличить?" << endl;

        cout << "1 - часы" << endl;
        cout << "2 - минуты" << endl;
        cout << "3 - секунды" << endl;
        cout << "0 - выход" << endl;
        cout << "--> ";
        cin >> c;

        switch (c)
        {
        case 1:
            system("cls");
            if (this->hour == 24) {
                this->hour = 1;
                cout << "\n";
                break;
            }
            this->hour += 1;
            break;
            cout << "\n";
        case 2:
            system("cls");
            if (this->minute == 59) {
                if (this->hour == 24) {
                    this->hour = 1;
                    this->minute = 0;
                    cout << "\n";
                    break;
                }
                else {
                    this->hour += 1;
                    this->minute = 0;
                    break;
                }
            }

            this->minute += 1;
            break;
            cout << "\n";
        case 3:
            system("cls");
            if (this->second == 59) {
                if (this->minute == 59) {
                    if (this->hour == 24) {
                        this->hour = 1;
                        this->minute = 0;
                        this->second = 0;
                        cout << "\n";
                        break;
                    }
                    else {
                        this->hour += 1;
                        this->minute = 0;
                        this->second = 0;
                        break;
                    }
                }
                else {
                    this->minute += 1;
                    this->second = 0;
                    break;
                }
            }
            this->second += 1;
            cout << "\n";
            break;
        case 0: //0 - Выход
            system("cls");
            cout << "\n";
            flag = 0;
            break;
        default:
            system("cls");
            cout << "\n";
            flag = 0;
            break;
        }
    }

    return temp;
}