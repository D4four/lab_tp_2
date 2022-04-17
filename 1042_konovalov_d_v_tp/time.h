#pragma once


class Time
{
private:
    int hour;
    int minute;
    int second;
public:

    Time();
    explicit Time(int h, int m, int s);
    Time(const Time& timeCopy);

    void changeTime(int h, int m, int s);  
    void print(); 

    friend Time& operator --(Time& temp); 
    friend Time& operator ++(Time& temp);  
    Time& operator --(int);
    Time& operator ++(int);

};