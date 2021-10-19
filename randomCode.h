#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "checkUser.h"


class randomCode :public check_user_pass
{
public:

	randomCode();
	void generate_passcode();
	void firstpasscode();
	void secondpasscode();
	char int_to_char(int cha);
	void write_passcode();
	void close_passcode();
	std::string encoding_asciinum(int num);
	int calcu_asciinum(int i);
	int tempchar;
	std::string f_finished_passcode;
	std::string s_finished_passcode;
	std::fstream ofs_write;

private:

	std::vector<std::string> f_vector;
	std::vector<int> s_vector;
	std::vector<int> output;
	std::vector<int> afterResize;
	int counter_asciinum;


};