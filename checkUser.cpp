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
bool check_user_pass::check(std::string user)
{
	open_file();
	
	input_username = user;

	std::string username_from_user;
	std::string password_from_user;
	std::string all;
	std::string oneline;
	std::string username;
	std::string password;
	char delim = ' ';
	int getline_counter = 0;

	if (cpwd.is_open())
	{
		while (getline(cpwd, all, '\n'))
		{
			getline_counter++;
			oneline = all;

			username = "";
			password = "";
			for (auto& split : oneline)
			{
				if (split == ' ')
				{
					break;
				}
				else
				{
					username = username + split;
				}
			}

			if (username != user)
			{
				std::cout << "no this username" << std::endl;
				return false;
				
			}
		}
	}
	close_file();
}
bool check_user_pass::open_file()
{
	cpwd.open("./UserPass.txt",std::ios::in);
	try {
		if (!cpwd.is_open()) {
			//std::cout << "open file successed !" << std::endl;
			throw - 1;
		}
	}
	catch (int err){

		std::cout << "can not open, file may lost !" << std::endl;
		return false;
	}

	return true;
	
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
	//调用collatz函数计算加密后的密码，并赋给c_password;
	input_username = user;
	input_password = encoding(pwd);//

	std::string username_from_user;
	std::string password_from_user;
	std::string all;
	std::string oneline;
	std::string username;
	std::string password;
	char delim = ' ';
	int getline_counter = 0;
	
	if (cpwd.is_open())
	{
		while (getline(cpwd, all,'\n'))
		{
			getline_counter++;
			oneline = all;

			username = "";
			password = "";
			for (auto& split : oneline)
			{
				if (split == ' ')
				{
					password = password + (&split+1);
					break;
				}
				else
				{
					username = username + split;
				}
			}
	
			if (username == user)
			{
				txt_username = username;
				txt_password = password;
				break;
			}
		}
	}
	close_file();
}