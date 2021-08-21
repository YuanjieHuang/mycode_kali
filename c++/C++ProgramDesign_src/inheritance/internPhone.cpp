// ***************************************************************
// internPhone.cpp
// 演示电话号码与国际电话号码间的继承关系
// ***************************************************************
#include <iostream>
#include <string>
using namespace std;
enum PhoneType {HOME, OFFICE, CELL, FAX};
class Phone {
public:
	Phone();
	Phone( string, string, PhoneType);
	void setAreaCode(string);
	void setNumber(string);
	void setPhoneType(PhoneType);
	string getAreaCode();
	string getNumber();
	PhoneType getPhoneType();
	void write();
protected:
	string areaCode;
	string number;
	PhoneType type;
};
Phone::Phone()
{
	areaCode ="";
	number = "";
	type= HOME; 
}
Phone::Phone(string newAreaCode, string newNumber, PhoneType newType)
{
	areaCode = newAreaCode;
	number = newNumber;
	type= newType; 
}
void Phone::setAreaCode(string newAreaCode)
// 功能：设置areaCode数据成员
// 前置条件：newAreaCode已赋值
// 后置条件：areaCode数据成员设置为newAreaCode
{
	areaCode = newAreaCode;
}
void Phone::setNumber(string newNumber)
// 功能：设置number数据成员
// 前置条件：newNumber已赋值
// 后置条件：number数据成员设置为newNumber
{ 
	number = newNumber;
}
void Phone::setPhoneType(PhoneType newType)
// 功能：设置type数据成员
// 前置条件：newType已赋值
// 后置条件：type数据成员设置为newType
{
	type= newType;
}
string Phone::getAreaCode()
// 功能：获取areaCode数据成员
// 后置条件：返回areaCode数据成员
{
	return 	areaCode;
}
string Phone::getNumber()
// 功能：获取number数据成员
// 后置条件：返回number数据成员
{
	return number;
}
PhoneType Phone::getPhoneType()
// 功能：获取type数据成员
// 后置条件：返回type数据成员
{
	return type;
}
void Phone::write()
// 功能：输出Phone类对象
// 后置条件：输出各数据成员
{
	string  phoneType;
	switch (type) {
		case  HOME: 
			phoneType = "Home"; 
			break;
		case  OFFICE: 
			phoneType = "Office"; 
			break;
		case  CELL: 
			phoneType = "Cell"; 
			break;
		case  FAX: 
			phoneType = "Fax"; 
			break;
	}
	cout << "The " + phoneType + "number: " << areaCode << "-" << number <<endl;
}
// 使用继承，可以派生出代表国际号码的类InternPhone
class InternPhone: public Phone {
public:
	InternPhone();
	InternPhone(string, string, string, PhoneType);
	void setCountryCode(string);
	string  getCountryCode();
	void write();
protected:
	string countryCode;
};
InternPhone::InternPhone()
{
	countryCode = "";
}
InternPhone::InternPhone(string newCountryCode, string newAreaCode, string 
newNumber, PhoneType newType): 
Phone(newAreaCode, newNumber, newType)
{
	countryCode = newCountryCode;
}
void InternPhone:: setCountryCode(string newCountryCode) 
// 功能：设置countryCode数据成员
// 前置条件：newCountryCode已赋值
// 后置条件：countryCode数据成员设置为newCountryCode
{
    countryCode = newCountryCode;
}
string InternPhone:: getCountryCode() 
// 功能：获取countryCode数据成员
// 后置条件：返回countryCode数据成员得值
{
    return countryCode;
}
void InternPhone::write()
// 功能：输出数据成员的值
// 后置条件：输出数据成员
{
	string  phoneType;
	switch (type) {
		case  HOME:
			phoneType = "Home ";
			break;
		case  OFFICE: 
			phoneType = "Office "; 
			break;
		case  CELL: 
			phoneType = "Cell "; 
			break;
		case  FAX: 
			phoneType = "Fax "; 
			break;
	}
	cout << phoneType + ": " << countryCode << "-" <<areaCode << "-" << number <<endl;
}
int main()
{
	Phone myPhone("20", "84114993", OFFICE);
	InternPhone myFriendPhone("20", "20", "76543", OFFICE);
	InternPhone mySisterPhone;
	cout << "My phone number: " <<endl;
	myPhone.write();
	myPhone.setNumber("84112788");
	cout << "My phone number changed:" <<endl;
	myPhone.write();
	cout << "My friend number: " <<endl;
	myFriendPhone.write();
	myFriendPhone.setNumber("332244");
	cout << "My friend number changed:" <<endl;
	myFriendPhone.write();
	cout << "My sister number: " <<endl;
	mySisterPhone.write();
	return 0;
}
