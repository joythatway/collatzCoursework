#include <iostream>
#include <random>
#include <vector>
#include <string>
//#include <ranges>
#include <fstream>
#include <sstream>
#include <iterator>
#include <time.h>
#include <stdlib.h>
#include "randomCode.h"


randomCode::randomCode()//cons
{
	f_finished_passcode = "";
	s_finished_passcode = "";
	counter_asciinum = 0;
	ofs_write.open("./passwordtest.txt", std::ios::out);
	srand((int)time(0));
}

void randomCode::generate_passcode()
{
	std::cout << "generate_passcode()" << std::endl;
	counter_asciinum = 0;
	firstpasscode();
	counter_asciinum = 0;
	secondpasscode();
	close_passcode();
}
void randomCode::firstpasscode()//first 10000 passcode
{
	//a--z:97-122
	int temprandom;
	std::string string_one;
	std::string string_two;
	std::string string_three;
	int counter = 0;
	int times = 1;
	int cishu = 0;
	int length = 0;
	int ch[10];
	for (int i = 0; i < 10; i++)
	{
		ch[i]= (rand() % (122 - 97 + 1)) + 97;// creat arrays to store 10 lowercase ascii dec;
		//std::cout << ch[i] << std::endl;//check the 10 lowercase characters
	}
	for (cishu = 1; cishu <= 100; cishu++)//第一个100，第二个100，第三个100......
	{
		//std::cout << cishu << std::endl;
		for (counter = 1; counter<=100; counter++)//100里的1-100
		{
			//std::cout << counter << std::endl;
			// here to generate random passcode
			string_one = "";
			string_two = "";
			f_finished_passcode = "";
			for (length = 1; length <= cishu; length++)//length
			{
				//tempchar=(rand() % (122 - 97 + 1)) + 97;
				tempchar= (rand() % 9);
				//string_one=std::to_string(ch[tempchar]);
				string_two.append(encoding_asciinum(ch[tempchar]));//!!

			}
			
			counter_asciinum = 0;
			std::cout << string_two << std::endl;//!!
			//std::cin.get();
			//f_finished_passcode = encoding(string_two);//encoding ...//19/10/2021::no need this step, the function is updated now;
			f_finished_passcode.append(string_two);//!!
			//std::cout <<"encoding :"<< f_finished_passcode << std::endl;
			write_passcode();//!!

		}

		std::cout << "------------------------" <<cishu << std::endl;
		//std::cin.get();
	}
	

}
void randomCode::secondpasscode()//second 10000 passcode 32-126 printable
{
	int counter = 0;
	int temprandom=0;
	int length = 0;
	int x = 1;
	int i = 0;
	int y = 0;
	int iv = 0;
	std::string string_one;
	std::string string_two;
	std::string string_three;
	std::string str;
	std::stringstream ss;
	std::vector<int>::iterator itr;
	/*for (int i = 32; i <= 126; i++)
	{
		s_vector.push_back(i);
	}
	std::random_shuffle(s_vector.begin(), s_vector.end());*/
	
	
	for (i = 1; i <= 100; i++)//1-100, 101-200, 201-300 ...几百
	{
		std::cout << "------------------ " <<"the " << i << "  hunders" << std::endl;
		for (y = 1; y <= 100; y++)//1,2,3...---101,102,103...---201,202,203...
		{
			//std::random_shuffle(s_vector.begin(), s_vector.end());
			string_two = "";
			str = "";
			s_finished_passcode = "";
			for (iv = 0; iv <= 255; iv++)
			{
				s_vector.push_back(iv);
			}
			std::random_shuffle(s_vector.begin(), s_vector.end());
			s_vector.resize(i);// use i
			//for (x = 1; x <= i; x++)//length 1--2--3 ...
			//{
				/*std::vector<int>::const_iterator First = s_vector.begin();
				std::vector<int>::const_iterator End = s_vector.begin()+x;
				s_vector.assign(First, End);*/
				/*for (int iv = 32; iv <= 126; iv++)
				{
					s_vector.push_back(iv);
				}
				std::random_shuffle(s_vector.begin(), s_vector.end());*/
				//s_vector.resize(x);//??????
				/*copy(s_vector.begin(), s_vector.end(), std::ostream_iterator<int>(ss, ""));
				str = ss.str();
				string_two = string_two + str;
				std::cout << string_two << std::endl;*/
				for (auto abc : s_vector)
			    {
					//std::cout << abc << " ";//just print every value in vector
					//std::cout << encoding_asciinum(abc);//print result number after encoding
					
					//s_finished_passcode = s_finished_passcode + encoding_asciinum(abc);//write result into string value
					s_finished_passcode.append(encoding_asciinum(abc));
			    }
				counter_asciinum = 0;
				if (ofs_write)
				{
					ofs_write << s_finished_passcode << std::endl;//write encrypted passcode into file
					//ofs_write.close();
					std::cout << "finished writing second passcode ..." << std::endl;
				}
				s_vector.clear();
			//}

			

			std::cout << "------------------ " << y << " " << std::endl;
		}
		
	}
	

	
	


}

char randomCode::int_to_char(int cha)
{
	char output=cha;
	return output;
}

void randomCode::write_passcode()
{
	/*std::fstream ofs_write;
	ofs_write.open("./passwordtest.txt", std::ios::app);*/

	if (ofs_write)
	{
		ofs_write << f_finished_passcode<< std::endl;
		//ofs_write.close();
		//std::cout << "finished writing ..." << std::endl;
	}
	else
	{
		std::cout << "open file error !" << std::endl;
	}

}
void randomCode::close_passcode()
{
	if (ofs_write.is_open())
	{
		ofs_write.close();
		//std::cout << "close the file !" << std::endl;
	}
	else {
		//std::cout << "the file has already close !" << std::endl;
	}
}

int randomCode::calcu_asciinum(int i)
{
	if (i == 1)
		return i;

	if (i == 0)
		return 1;

	if (i % 2 == 0)
		return i / 2;
	else
		return 3 * i + 1;
}
std::string randomCode::encoding_asciinum(int num)
{
	int tempnum = 0;
	std::string finished_passcode;
	tempnum=num + counter_asciinum;
	
	while ( tempnum!= 1)
	{
		tempnum = calcu_asciinum(tempnum);
		counter_asciinum++;
	}
	finished_passcode = std::to_string(counter_asciinum);
	return finished_passcode;
}
