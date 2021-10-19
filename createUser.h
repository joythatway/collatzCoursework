#pragma once
#include <iostream>


class createUser
{
public:
	createUser();
	int charTransferInt(char cha);
	int calcu(int i);
	int collatz(int singlecha);
	void encode(std::string user,std::string paswd);
	std::string encoding(std::string paswod);
	void save_txt();
	bool check_username(std::string uname);

private:
	std::string username;
	std::string password;
	std::string pass;
	std::string* allpass;
	int offset = 0;
	int counter = 0;
	


	

protected:
};