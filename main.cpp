#include <iostream>
#include <any>
#include <memory>
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
inline void putnumber(int num)
{
	cout << "student_num :" <<num<< endl;
}
void function1()//14/10/2021-14:43--14:45
{
	string uName;
	string pwd;
	bool tempbool;
	//createUser* crtUser = new createUser;
	shared_ptr<createUser> crtUser = make_shared<createUser>();
	print("please create your username:");
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
		cout << "please create your password:" << endl;
		cin >> pwd;
		crtUser->encoding(uName, pwd);//!!!poly
	}
	
}

void function2()//check-username-password
{
	//check_user_pass* check_pwd = new check_user_pass;
	shared_ptr<check_user_pass> check_pwd = make_shared<check_user_pass>();
	string check_username;
	string check_password;
	int i = 3;
	//bool exit = check_pwd->open_file();
	//if (!exit)
	//	return;
	cout<<"please input your username:" << endl;
	cin >> check_username;
	//if (!check_pwd->check(check_username))
		//return;
	
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
	}else if(check_username!=check_pwd->txt_username||check_username!="")
	{
		std::cout << "failure: no this username" << std::endl;
	}
	if (i < 0)
		std::cout << "you run out of all chance !!" << std::endl;
}
void function3()//generate passcode
{
	//randomCode* generater = new randomCode;
	shared_ptr<randomCode> generater = make_shared<randomCode>();
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
	//decode* dc = new decode;
	shared_ptr<decode> dc = make_shared<decode>();
	//dc->decodeSentence(sentence);

	//dc->readfile();
	dc->digui(all_the_words,"",13,35);//recursion
	//dc->baolidecode();
	//dc->pojie();
	//dc->arraydecode();//!!!
	//dc->forloopdecode();
	//dc->decrypt();
	//dc->slicedecode();
}

int main()
{
	int function_number;
	int* pt;
	int** pt2pt;
	pt = &function_number;
	pt2pt = &pt;

	void (*func[6])() = { NULL,function1,function2,function3,function4};

	while (1)
	{
		int stnum = 190627429;
		putnumber(stnum);
		print("please type number to choose function>>>");
		print("1.register your account");
		print("2.log in");
		print("3.Generate password strength analysis file");
		print("4.Analys password strength analysis file");
		print("5.Exit");

		cin >> **pt2pt;
		if (cin.fail() == 1) {
			print("do not use words");
			return 0;
		}
			
		auto lamdaPrint = []() {cout << "please input valid number !" << endl; };
		/*
		if (**pt2pt > 5 || **pt2pt < 1) {
			//print("please input valid number !");
			lamdaPrint();
		}
		else*/
		if (**pt2pt == 5) {
			//func[**pt2pt]();
			return 0;
		}else if(**pt2pt<5&&**pt2pt>=1)
		{
			func[**pt2pt]();
		}
		else if (**pt2pt > 'a' && **pt2pt<'z' && **pt2pt>'A' && **pt2pt < 'Z')
		{
			lamdaPrint();
		}
		else {
			lamdaPrint();

		}
		cin.get();
		cin.get();
		system("cls");
	}
}