#include <iostream>
using namespace std;
enum ZoneType {EST, CST, MST, PST, EDT, CDT, MDT, PDT};
class Time {
public:
    void set(int hours, int minutes, int seconds );
    Time(int initHrs, int initMins, int initSecs );
    Time();
private:
    int hrs;
    int mins;
    int secs;
};
class ExtTime : public Time{
public:
void set  (int  hours,  int  minutes, int seconds, 
ZoneType timeZone );
ExtTime(int  initHrs, int  initMins, int initSecs, 
ZoneType initZone );
private:
ZoneType zone;
};
Time::Time(int initHrs, int initMins, int initSecs )
{
    hrs = initHrs;
    mins = initMins;
    secs = initSecs;
    cout << "Constructor with parameters in Time class..." << endl;
}
Time::Time()
{
    hrs = 0;
    mins = 0;
    secs = 0;
cout << "Default constructor in Time class..." << endl;
}
void Time::set(int hours, int minutes, int seconds )
{
hrs = hours;
mins = minutes;
secs = seconds;
}
ExtTime::ExtTime(int initHrs, int initMins, int initSecs, ZoneType initZone ) :
	Time(initHrs, initMins, initSecs)
{
zone = initZone;
cout << "Constructor with parameters in ExtTime class..." << endl;
}
ExtTime::ExtTime()
{
zone = EST;
cout << "Default constructor in ExtTime class..." << endl;
}
void ExtTime::set(int hours, int minutes, int seconds, 
ZoneType timeZone )
{
 	hrs = hours;
    mins = minutes;
    secs = seconds;
    zone = timeZone;
}
int main()
{
    ExtTime time1(5, 30, 0, CDT);
    ExtTime time2;
 	return 0;
}
