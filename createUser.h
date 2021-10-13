#pragma once
#include <iostream>


class createUser
{
public:
	createUser();
	int charTransferInt(char cha);
	int calcu(int i);
	void collatz(int singlecha);
	void encode(std::string user,std::string paswd);
	bool save_txt();

private:
	std::string username;
	std::string password;
	std::string pass;
	std::string* allpass;
	int offset = 0;
	int counter = 0;
	


	

protected:
};