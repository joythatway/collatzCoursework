#include <iostream>
#include <string>
#include <fstream>
#include "createUser.h"

createUser::createUser()
{
	createUser::username = "noname";
	createUser::password = "nopassword";
	createUser::pass = "";
	createUser::allpass = new std::string;

	std::cout << username << " and " << password << std::endl;
}

void createUser::encode(std::string user,std::string paswd)
{
	username = user;
	password = paswd;
	int tempnum;
	int fortimes = 0;
	std::cout << user << " and " <<paswd<< std::endl;

	for (auto chr : password)
	{
		offset = 0;
		counter = 0;
		tempnum=charTransferInt(chr);//��ÿ���ַ�charת��ΪAscii��
		collatz(tempnum);//����Ascii�룬�������1�Ĳ���counter
		if (fortimes== 0)
		{
			offset = 0;	
		}
		else 
		{
			offset = offset + counter;//collatz�ó��Ĳ����ӵ��ַ���offset��
		}
		tempnum = tempnum + offset;//Ascii���offset�õ����ռ�������
		
		pass = std::to_string(tempnum);//�����ռ�������תΪstring����
		*allpass = *allpass + pass;//��ÿ�����ܺ���ַ�����Ϊһ�����ַ���
		fortimes++;
		std::cout << *allpass << std::endl;
	}
	
	if (save_txt())
		std::cout << "complete encode." << std::endl;
	else
		std::cout << "encode error..." << std::endl;
	
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
	{
		return i / 2;
	}
	else
	{
		return 3 * i + 1;
	}
}
void createUser::collatz(int singlecha)
{
	while (singlecha !=1)
	{
		singlecha = calcu(singlecha);
		counter++;
	}
	
}
bool createUser::save_txt()
{
	//��username and allpassд���ļ�txt
	std::fstream ofs_write;
	ofs_write.open("./UserPass.txt", std::ios::app);
	ofs_write << username << " " << *allpass << '\n';

	ofs_write.close();



	return true;
}