#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include "checkUser.h"
#include "createUser.h"


check_user_pass::check_user_pass()//construction function
{
	c_username = "";
	c_password = "";

}
void check_user_pass::open_file()
{
	cpwd.open("./UserPass.txt",std::ios::in);
	if (cpwd)
		std::cout << "open successed !" << std::endl;
	else
		std::cout << "open faild !" << std::endl;
}
void check_user_pass::close_file()
{
	if (cpwd)
	{
		cpwd.close();
		std::cout << "close the file !" << std::endl;
	}else
		std::cout << "the file has already close !" << std::endl;
}

//std::vector<std::string> split(const std::string& str, const std::string& delim) {
//	std::vector<std::string> res;
//	if ("" == str) return res;
//	//�Ƚ�Ҫ�и���ַ�����string����ת��Ϊchar*����
//	char* strs = new char[str.length() + 1];
//	std::strcpy(strs, str.c_str());
//
//	char* d = new char[delim.length() + 1];
//	strcpy(d, delim.c_str());
//
//	char* p = strtok(strs, d);
//	while (p) {
//		std::string s = p;  //�ָ�õ����ַ���ת��Ϊstring����
//		res.push_back(s); //����������
//		p = strtok(NULL, d);
//	}
//	return res;
//}

void check_user_pass::check(std::string user, std::string pwd)
{
	open_file();
	//m_pwd;

	while (!cpwd.eof())
	{
		std::string temp;
		cpwd >> temp;
		std::vector<std::string> tempstr;// = split(temp, " ");
		std::string key_user = tempstr[0].c_str();
		std::string value_pass = tempstr[1].c_str();

		m_pwd.insert(make_pair(key_user, value_pass));
	}
	std::map<std::string, std::string> ::iterator itr;
	for (itr = m_pwd.begin(); itr != m_pwd.end(); itr++)
	{
		std::cout << itr->second << std::endl;
	}
	
	



	close_file();
}