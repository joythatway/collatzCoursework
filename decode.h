#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "checkUser.h"
#include "randomCode.h"

class decode:public randomCode
{
public:
	decode();
	~decode();
	void decodeSentence(const std::string sentence);
	int anticollatz(int offset);
	int anticalcu(int x);

	std::map<int, int>counter_map;
	void read_map();
	void readfile();
	void decrypt();
	void slicedecode();
	void arraydecode();
	void forloopdecode();
	void baolidecode();
	void pojie();
	void encode();
	int calc(int a);
	int Collatz(int b);
	void digui(char all_the_words[], std::string sequence, int n, int k);
	char all_the_words[13] = { 'A','a','d','e','f','i','l','n','o','r','s','t',' ' };// all in 13 cha
	std::string enn = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	int num[100];
	int offset;
	int tempnum;
	std::fstream ofs_recur;
	std::fstream ofs_read;


private:
	std::string sentc;
	int counter;
	int nextcounter;
	std::vector<char> result;
	bool flag;
	

};