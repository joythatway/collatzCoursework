#include <iostream>
#include <map>
#include <fstream>
#include <istream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include "checkUser.h"
#include "createUser.h"


check_user_pass::check_user_pass()//construction function
{
	c_username = "";
	c_password = "";

}
bool check_user_pass::open_file()
{
	cpwd.open("./UserPass.txt",std::ios::in);
	if (cpwd.is_open()) {
		//std::cout << "open file successed !" << std::endl;
		return true;
	}else {
		std::cout << "open faild,file may lost !" << std::endl;
		return false;
	}
		
	
}
void check_user_pass::close_file()
{
	if (cpwd.is_open())
	{
		cpwd.close();
		//std::cout << "close the file !" << std::endl;
	}
	else {
		//std::cout << "the file has already close !" << std::endl;
	}
}


void check_user_pass::check(std::string user, std::string pwd)
{
	open_file();
	//m_pwd;
	//调用collatz函数计算加密后的密码，并赋给c_password;
	input_username = user;
	input_password = encoding(pwd);

	std::string username_from_user;
	std::string password_from_user;
	std::string all;
	std::string oneline;
	std::string username;
	std::string password;
	char delim = ' ';
	int getline_counter = 0;
	//using getoneline = std::istream& getline(std::istream & is, std::string & all, char space = ' ');
	//std::istream& getline(std::istream& is,std::string &all, char space=' ');
	//std::cout <<  << std::endl;
	if (cpwd.is_open())
	{
		while (getline(cpwd, all,'\n'))
		{
			//std::cout << all << std::endl;
			getline_counter++;
			//std::cout << getline_counter<<std::endl;
			oneline = all;
			//std::cout << "oneline is :" << oneline << std::endl;

			username = "";
			password = "";
			for (auto& split : oneline)
			{
				if (split == ' ')
				{
					password = password + (&split+1);
					break;
					//std::cout << password << std::endl;
				}
				else
				{
					username = username + split;
				}
			}
			/*//!!!
			for (auto& split1 : oneline)
			{
				if (split1 == ' ')
				{
					break;
					//std::cout << password << std::endl;
				}
				username = username + split1;
			}*/
			//std::cout << "username is :"<<username << std::endl;
			//std::cout << "password is :"<<password << std::endl;

			/*if (user != username)
			{
				std::cout << "no username exist !" << std::endl;
			}
			else if (user == username)
			{
				for (int i = 0; i < changce; i++)
				{
					if (pwd == password)
					{
						std::cout << "success !" << std::endl;
					}
					else if (pwd != password)
					{
						std::cout << "failed ！" << std::endl;
						i++;
					}
				
				}
			}*/

			if (username == user)
			{
				txt_username = username;
				txt_password = password;
				break;
			}
			/*else if (username != user)
			{
				txt_username ="";
				txt_password = "";
				std::cout << "not match !" << std::endl;
			}*/
		}
		
	}

	close_file();
}