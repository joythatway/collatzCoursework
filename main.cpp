#include <iostream>
#include "createUser.h"
#include "checkUser.h"
#include "randomCode.h"
#include "decode.h"

using namespace std;

void function1()
{
	string uName;
	string pwd;
	createUser* crtUser = new createUser;
	cout << "please input your username:" << endl;
	cin >> uName;
	cout << "please input your password:" << endl;
	cin >> pwd;
	crtUser->encode(uName, pwd);

}

void function2()
{

}
void function3()
{

}
void function4()
{

}
int main()
{
	int function_number;
	cout << "please type number to choose function>>>" << endl;
	cout << "1.register your account" << endl;
	cout << "2.log in" << endl;
	cout << "3.Generate password strength analysis file" << endl;
	cout << "4.Analys password strength analysis file" << endl;
	cin >> function_number;
	switch (function_number) 
	{
	case 1:function1(); break;
	case 2:function2(); break;
	case 3:function3(); break;
	case 4:function4(); break;
	default:
		cout << "please input valid number !" << endl;

	}






}