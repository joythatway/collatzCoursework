#include <iostream>
#include <any>
#include "createUser.h"
#include "checkUser.h"
#include "randomCode.h"
#include "decode.h"

using namespace std;
template<typename T>
void print(T value)
{
	std::cout << value << std::endl;
}
void function1()//14/10/2021-14:43--14:45
{
	string uName;
	string pwd;
	bool tempbool;
	createUser* crtUser = new createUser;
	print("please input your username:");
	cin >> uName;
	//check the username if it exist
	tempbool = crtUser->check_username(uName);
	if (tempbool==false)
	{
		//std::cout << "please use other name ..." << endl;
		print("please use other name");
	}
	else 
	{
		cout << "please input your password:" << endl;
		cin >> pwd;
		crtUser->encoding(uName, pwd);//!!!poly
	}
	
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
	char all_the_words[13] = { 'A','a','d','e','f','i','l','n','o','r','s','t',' ' };// all in 13 cha
	const string sentence = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	decode* dc = new decode;
	//dc->decodeSentence(sentence);

	//dc->digui(all_the_words,"",13,35);
	//dc->baolidecode();
	//dc->pojie();
	//dc->arraydecode();//!!!
	//dc->forloopdecode();
	dc->decrypt();
}
int main()
{
	int function_number;
	int* pt;
	int** pt2pt;
	pt = &function_number;
	pt2pt = &pt;

	//void (*func[4])() = { function1,function2,function3,function4 };

	/*cout << "please type number to choose function>>>" << endl;
	cout << "1.register your account" << endl;
	cout << "2.log in" << endl;
	cout << "3.Generate password strength analysis file" << endl;
	cout << "4.Analys password strength analysis file" << endl;*/

	print("please type number to choose function>>>");
	print("1.register your account");
	print("2.log in");
	print("3.Generate password strength analysis file");
	print("4.Analys password strength analysis file");

	//cin >> function_number;
	cin >> **pt2pt;
	cout << "**pt2pt is :";
	print(**pt2pt);
	/*
	if (function_number > 4 || function_number < 1) {
		print("please input valid number !");
	}
	else {
		func[function_number]();
	}
	*/	
	
		
	
	switch (**pt2pt) //function_number
	{
	case 1:function1(); break;
	case 2:function2(); break;
	case 3:function3(); break;
	case 4:function4(); break;
	default:
		print("please input valid number !");

	}
	

}