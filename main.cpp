#include <iostream>
#include "createUser.h"
#include "checkUser.h"
#include "randomCode.h"
#include "decode.h"

using namespace std;

void function1()//14/10/2021-14:43--14:45
{
	string uName;
	string pwd;
	createUser* crtUser = new createUser;
	cout << "please input your username:" << endl;
	cin >> uName;
	//check the username if it exist

	cout << "please input your password:" << endl;
	cin >> pwd;
	crtUser->encode(uName, pwd);

}

void function2()//check-username-password
{
	check_user_pass* check_pwd = new check_user_pass;
	string check_username;
	string check_password;
	int i = 3;
	
	cout<<"please input your username:" << endl;
	cin >> check_username;
	cout << "please input password:" << endl;
	cin >> check_password;
	//写一个入口函数，传递用户名和密码开始处理
	check_pwd->check(check_username, check_password);//match username and password from txt to txt_user_password;

	check_password = check_pwd->encoding(check_password);

	if (check_username == check_pwd->txt_username)
	{
		for (i = 3; i >= 0; i--)
		{
			if (check_password==check_pwd->txt_password)
			{
				std::cout << "success !" << std::endl;
				break;
			}
			else if (check_pwd->txt_password != check_password&&i!=0)
			{
				std::cout << "not match pwd, ";
				std::cout << "you have " << i << " opportunitiy, ";
				std::cout << "please reinput your password :";
				cin >> check_password;
				check_password = check_pwd->encoding(check_password);
			}
		}
	}else
	{
		std::cout << "failure" << std::endl;
	}

	if (i < 0)
		std::cout << "you run out of all chance !!" << std::endl;
}
void function3()//generate passcode
{
	randomCode* generater = new randomCode;
	char chioce;
	cout << "please input y or n if you want to generate passcode.." << endl;
	cin >> chioce;
	switch (chioce)
	{
	case 'y':generater->generate_passcode(); break;
	case 'n':break;
	default:cout << "please use y and n " << endl;
		break;
	}
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