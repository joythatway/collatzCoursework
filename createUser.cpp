#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "createUser.h"

createUser::createUser()
{
	createUser::username = "noname";
	createUser::password = "nopassword";
	createUser::pass = "";
	createUser::allpass = new std::string;
}

bool createUser::check_username(std::string uname)
{
	std::string username_from_user;
	std::string password_from_user;
	std::string all;
	std::string oneline;
	std::string username;
	std::string password;
	std::ifstream ofs_check_username;
	ofs_check_username.open("./UserPass.txt",std::ios::in);
	if (ofs_check_username.is_open())
	{
		while (getline(ofs_check_username, all, '\n'))
		{
			oneline = all;
			username = "";
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
			if (uname == username)
				return false;
		}
	}
}
void createUser::encoding(std::string user,std::string paswd)
{
	username = user;
	password = paswd;
	int tempnum = 0;
	int fortimes = 0;
	std::cout << user << " and " <<paswd<< std::endl;
	offset = 0;
	counter = 0;
	for (auto chr : password)
	{		
		tempnum=charTransferInt(chr);//将每个字符char转换为Ascii码		
		tempnum = tempnum + offset;		
		collatz(tempnum);//传入Ascii码，计算出到1的步骤counter				
		pass = std::to_string(counter);//将最终加密数字转为string类型
		*allpass = *allpass + pass;//将每个加密后的字符串联为一个长字符串
		offset = counter;		
		std::cout << *allpass << std::endl;
	}
	save_txt();		
}
std::string createUser::encoding(std::string paswod)
{
	auto lamda_int2char = [](char a)->int {return a; };//!!!!!!!lamda
	password = paswod;
	std::string finished_password;
	int tempnum = 0;
	int fortimes = 0;
	//std::cout << " encoding pwd : " << paswod << std::endl;
	offset = 0;
	counter = 0;
	for (auto chr : password)
	{
		tempnum = lamda_int2char(chr);//!!!!!!!!lamda
		//tempnum = charTransferInt(chr);//将每个字符char转换为Ascii码		
		tempnum = tempnum + offset;
		//传入Ascii码，计算出到1的步骤counter				
		pass = std::to_string(collatz(tempnum));//将最终加密数字转为string类型
		finished_password = finished_password + pass;//将每个加密后的字符串联为一个长字符串
		offset = counter;
	}
	return finished_password;
}
int createUser::charTransferInt(char cha)
{
	return cha;
}
int createUser::calcu(int i)
{
	if (i == 1)
		return i;
	if (i % 2 == 0)
		return i / 2;
	else
		return 3 * i + 1;
}
int createUser::collatz(int singlecha)
{
	counter = 0;
	while (singlecha !=1)
	{
		singlecha = calcu(singlecha);
		counter++;
	}
	return counter;
}
void createUser::save_txt()
{
	std::map<std::string, std::string>createMap;
	std::fstream ofs_write;
	ofs_write.open("./UserPass.txt", std::ios::app);
	if (ofs_write)
	{
		createMap.insert(std::pair<std::string, std::string>(username, *allpass));
		std::map<std::string, std::string>::iterator iter;
		for (iter = createMap.begin(); iter != createMap.end(); iter++) {
				ofs_write << iter->first << ' ' << iter->second << std::endl;
		}
		ofs_write.close();
		std::cout << "finished writing ..." << std::endl;
	}
	else 
	{
		std::cout << "open file error !" << std::endl;
	}
}