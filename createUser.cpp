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

	std::cout << username << " and " << password << std::endl;
}

bool createUser::check_username()
{
	//std::ifstream ofs_check_username;
	//ofs_check_username.open("./UserPass.txt");

	return true;
}
void createUser::encode(std::string user,std::string paswd)
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
		
		tempnum=charTransferInt(chr);//��ÿ���ַ�charת��ΪAscii��
		//newcastle computing 15:00--14/10/2021
		tempnum = tempnum + offset;
		//end
		collatz(tempnum);//����Ascii�룬�������1�Ĳ���counter
		/*
		if (fortimes== 0)
		{
			offset = 0;	
		}
		else 
		{
			offset = offset + counter;//collatz�ó��Ĳ����ӵ��ַ���offset��
		}*/

		//tempnum = tempnum + offset;//Ascii���offset�õ����ռ�������
		

		pass = std::to_string(counter);//�����ռ�������תΪstring����
		*allpass = *allpass + pass;//��ÿ�����ܺ���ַ�����Ϊһ�����ַ���
		offset = counter;
		//fortimes++;
		std::cout << *allpass << std::endl;
	}
	save_txt();
	//if (save_txt())
	//	std::cout << "complete encode." << std::endl;
	//else
	//	std::cout << "encode error..." << std::endl;
	
}
int createUser::charTransferInt(char cha)
{
	return cha;
	/*
	if (cha >= 48 && cha <= 57)//cha������
	{
		cha = cha - '0';
		return cha;
	}
	else
	{
		return cha;
	}
	*/
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
void createUser::collatz(int singlecha)
{
	counter = 0;
	while (singlecha !=1)
	{
		singlecha = calcu(singlecha);
		counter++;
	}
}
void createUser::save_txt()
{
	std::map<std::string, std::string>createMap;

	//��username and allpassд���ļ�txt
	std::fstream ofs_write;
	
	ofs_write.open("./UserPass.txt", std::ios::app);

	if (ofs_write)
	{
		//ofs_write << username << " " << *allpass << '\n';
			
		createMap.insert(std::pair<std::string, std::string>(username, *allpass));
		std::map<std::string, std::string>::iterator iter;
		for (iter = createMap.begin(); iter != createMap.end(); iter++) {
				ofs_write << iter->first << ' ' << iter->second << std::endl;
			//std::cout << iter->first << ' ' << iter->second << endl;
		}
	
		ofs_write.close();
		std::cout << "finished writing ..." << std::endl;
	}
	else 
	{
		std::cout << "open file error !" << std::endl;
	}
	//return true;
}