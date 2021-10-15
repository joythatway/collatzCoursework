#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "createUser.h"

class check_user_pass :public createUser
{
private:
	std::string c_username;
	std::string c_password;
	std::ifstream cpwd;
	std::map<std::string, std::string> m_pwd;


public:
	void check(std::string,std::string);
	void open_file();
	void close_file();
	check_user_pass();
	//使用父类中的collatz函数等
};