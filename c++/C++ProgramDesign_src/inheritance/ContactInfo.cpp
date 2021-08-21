class ContactInfo
{
	public:
		ContactInfo();
		string getName();
		string getEmail();
		InternPhone& getPhone(PhoneType type);
		void setName(string newName);
		void setEmail(string newEmail);
		void setPhone(InternPhone& newPhone, PhoneType type);
	private:
		string name;
		string email;
		InternPhone homePhone;
		InternPhone officePhone;
		InternPhone cellPhone;
		InternPhone faxPhone;
};
ContactInfo::ContactInfo()
{
	name ="";
	email = "";
}
string ContactInfo:: getName()
// 功能描述：获取name数据成员
// 后置条件：返回name数据成员的值
{
	return name;
}
string ContactInfo:: getEmail()
// 功能描述：获取email数据成员
// 后置条件：返回email数据成员的值
{
		return email;
}
InternPhone& ContactInfo:: getPhone(PhoneType type)
{
	switch (type) {
		case  HOME:
			return homePhone;
		case  OFFICE:
			return officePhone;
		case  CELL:
			return cellPhone;
		case  FAX:
			return faxPhone;
	}
}
void ContactInfo:: setName(string newName)
// 功能描述：设置name数据成员
// 前置条件：newNam已赋值
// 后置条件：name数据成员设置为newNam
{
	name = newName;
}
void ContactInfo:: setEmail(string newEmail)
// 功能描述：设置email数据成员
// 前置条件：newEmail已赋值
// 后置条件：email数据成员设置为newEmail
{
   email = newEmail;
}
void ContactInfo:: setPhone(InternPhone& newPhone, PhoneType type)
// 功能描述：设置电话号码数据成员
// 前置条件：newPhone,type已赋值
// 后置条件：根据type类别，电话号码数据成员设置为newPhone
{
	switch (type) {
		case  HOME: 
			homePhone = newPhone; 
			break;
		case  OFFICE: 
			officePhone = newPhone;
			break;
		case  CELL:
			cellPhone = newPhone;
			break;
		case  FAX:
			faxPhone = newPhone;
			break;
	}
}
int main()
{
	ContactInfo myContactBook[50];
	string name, email, countryCode, areaCode;
	string homeNumber, officeNumber, cellNumber, faxNumber;
	InternPhone newPhone;
     string response = "yes";
     int count= 0;
     int i;
     while(count < 50 && response == "yes") {
         cout << "Please input the contact info:  name  email  countryCode Areacode
                        homeNumber officeNumber cellNumber faxNumber" <<endl;
         cin >> name >> email >> countryCode >> areaCode >> homeNumber >> officeNumber
              	>> cellNumber >> faxNumber;
         myContactBook[count].setName(name);
         myContactBook[count].setEmail(email);
         newPhone.setCountryCode(countryCode);
         newPhone.setAreaCode(areaCode);
	    newPhone.setNumber(homeNumber);
	    newPhone.setPhoneType(HOME);
         myContactBook[count].setPhone(newPhone, HOME);
         newPhone.setCountryCode(countryCode);
         newPhone.setAreaCode(areaCode);
	    newPhone.setNumber(officeNumber);
	    newPhone.setPhoneType(OFFICE);
         myContactBook[count].setPhone(newPhone, OFFICE);
         newPhone.setCountryCode(countryCode);
         newPhone.setAreaCode(areaCode);
	    newPhone.setNumber(cellNumber);
	    newPhone.setPhoneType(CELL);
         myContactBook[count].setPhone(newPhone, CELL);
         newPhone.setCountryCode(countryCode);
         newPhone.setAreaCode(areaCode);
	    newPhone.setNumber(faxNumber);
	    newPhone.setPhoneType(FAX);
         myContactBook[count].setPhone(newPhone, FAX);
		count++;
		cout << "Countinue( yes or  no)?" ;
		cin >> response;
	 }
	 cout << "The contact book " <<endl;
	 for(i = 0; i < count; i++) {
		 cout << "姓名：" + myContactBook[i].getName() << endl;
		 cout << "Email："+ myContactBook[i].getEmail() << endl;
		 newPhone = myContactBook[i].getPhone(HOME);
	      newPhone.write();
		 newPhone = myContactBook[i].getPhone(OFFICE);
	      newPhone.write();
		 newPhone = myContactBook[i].getPhone(CELL);
	      newPhone.write();
		 newPhone = myContactBook[i].getPhone(FAX);
	      newPhone.write();
	 }
	 return 0;
}
