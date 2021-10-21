#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "decode.h"


decode::decode()
{
	//decode that english sentence
	counter = 0;
	flag = false;
	sentc = "";
	//ofs_recur.open("./recursion.txt", std::ios::out);
}
decode::~decode()
{
	//if (ofs_recur.is_open())
	//{
	//	ofs_recur.close();
	//	//std::cout << "close the file !" << std::endl;
	//}
}

void decode::decodeSentence(const std::string sentence)
{
	sentc = sentence;
	//27322810313331033910211452912207344136146925461033281533271031012815108114101
	//a-z and A-Z and space and ,.!? in english sentence
	//a-z:97--122
	//A-Z:65--90
	//?:63  !:33  ,:44  .:46  space:32
	//all in [32-122]

	// the process of offset

	counter = 1;//
	char cha;
	int result = 0;
	std::string encoding_result;
	std::string str;
	std::cout << "please input one character :" << std::endl;
	std::cin >> cha;
	str.push_back(cha);
	encoding_result = encoding(str);//!!!poly
	std::cout << "your input words is :" << cha << " and encoding code is :" << encoding_result << std::endl;

	result = anticollatz(std::stoi(encoding_result));//string transfer to int
	std::cout << " the anticollatz's result is :" << result << std::endl;

}
int decode::anticollatz(int counter)
{
	int x = 1;
	while (counter != 0)
	{
		x = anticalcu(x);
		counter--;
	}
	return x;
}
int decode::anticalcu(int x)
{
	
	if ((x - 4) % 6 == 0)
	{
		return (x-1)/3;
	}
	else {
		return x * 2;
	}
	
	int mod6 = ((x - 4) % 6);
	int odd = (x - 1) / 3;
	



		
}

void decode::baolidecode()
{
	/*char all_the_words[59] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'!', ':', ';', '?', ',', '.',' '};// all in 58 cha

	for (int n = 25; n < 77; n++)
	{
		digui(n);
	}
*/	
	
	//27322810313331033910211452912207344136146925461033281533271031012815108114101
	std::string english = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	std::string tempstring;
	char cha;

	while (flag != true)
	{
		for (int a = 32; a < 123; a++)
		{
			tempstring = encoding_asciinum(a);
			

			//std::string s("xyzblahblah");
			//std::string t("xyz");
			std::cout << tempstring << std::endl;
			sentc = sentc + tempstring;
			if (english.compare(0, sentc.length(), sentc) == 0)
			{
				result.push_back(int_to_char(a));
				

				//sentc = sentc + tempstring;
				std::cout << "------------------------- " << sentc << std::endl;
				std::cout << "----------------------------- " << int_to_char(a);
				//std::cout << result << std::endl;
				
			}
			else if (english == sentc)
			{
				//print all result
				flag = true;
			}
			else 
			{
				flag = false;
				//std::string teeemp=
				sentc=sentc.substr(0,sentc.length()-tempstring.length());
			}
			counter_asciinum = 0;
		}
	}


	/*
	char sencha[41];
	std::string generatstring;
	for (int a1 = 32; a1 < 123; a1++) {
		sencha[0] = int_to_char(a1);
		generatstring.push_back(sencha[0]);
		for (int a2 = 32; a2 < 123; a2++) {
			sencha[1] = int_to_char(a2);
			generatstring.push_back(sencha[1]);
			for (int a3 = 32; a3 < 123; a3++) {
				sencha[2] = int_to_char(a3);
				generatstring.push_back(sencha[2]);
				for (int a4 = 32; a4 < 123; a4++) {
					sencha[3] = int_to_char(a4);
					generatstring.push_back(sencha[3]);
					for (int a5 = 32; a5 < 123; a5++) {
						sencha[4] = int_to_char(a5);
						generatstring.push_back(sencha[4]);
						for (int a6 = 32; a6 < 123; a6++) {
							sencha[5] = int_to_char(a6);
							generatstring.push_back(sencha[5]);
							for (int a7 = 32; a7 < 123; a7++) {
								sencha[6] = int_to_char(a7);
								generatstring.push_back(sencha[6]);
								for (int a8 = 32; a8 < 123; a8++) {
									sencha[7] = int_to_char(a8);
									generatstring.push_back(sencha[7]);
									for (int a9 = 32; a9 < 123; a9++) {
										sencha[8] = int_to_char(a9);
										generatstring.push_back(sencha[8]);
										for (int a10 = 32; a10 < 123; a10++) {
											sencha[9] = int_to_char(a10);
											generatstring.push_back(sencha[9]);
											for (int a11 = 32; a11 < 123; a11++) {
												sencha[10] = int_to_char(a11);
												generatstring.push_back(sencha[10]);
												for (int a12 = 32; a12 < 123; a12++) {
													sencha[11] = int_to_char(a12);
													generatstring.push_back(sencha[11]);
													for (int a13 = 32; a13 < 123; a13++) {
														sencha[12] = int_to_char(a13);
														generatstring.push_back(sencha[12]);
														for (int a14 = 32; a14 < 123; a14++) {
															sencha[13] = int_to_char(a14);
															generatstring.push_back(sencha[13]);
															for (int a15 = 32; a15 < 123; a15++) {
																sencha[14] = int_to_char(a15);
																generatstring.push_back(sencha[14]);
																for (int a16 = 32; a16 < 123; a16++) {
																	sencha[15] = int_to_char(a16);
																	generatstring.push_back(sencha[15]);
																	for (int a17 = 32; a17 < 123; a17++) {
																		sencha[16] = int_to_char(a17);
																		generatstring.push_back(sencha[16]);
																		for (int a18 = 32; a18 < 123; a18++) {
																			sencha[17] = int_to_char(a18);
																			generatstring.push_back(sencha[17]);
																			for (int a19 = 32; a19 < 123; a19++) {
																				sencha[18] = int_to_char(a19);
																				generatstring.push_back(sencha[18]);
																				for (int a20 = 32; a20 < 123; a20++) {
																					sencha[19] = int_to_char(a20);
																					generatstring.push_back(sencha[19]);
																					for (int a21 = 32; a21 < 123; a21++) {
																						sencha[20] = int_to_char(a21);
																						generatstring.push_back(sencha[20]);
																						for (int a22 = 32; a22 < 123; a22++) {
																							sencha[21] = int_to_char(a22);
																							generatstring.push_back(sencha[21]);
																							for (int a23 = 32; a23 < 123; a23++) {
																								sencha[22] = int_to_char(a23);
																								generatstring.push_back(sencha[22]);
																								for (int a24 = 32; a24 < 123; a24++) {
																									sencha[23] = int_to_char(a24);
																									generatstring.push_back(sencha[23]);
																									for (int a25 = 32; a25 < 123; a25++) {
																										sencha[24] = int_to_char(a25);
																										generatstring.push_back(sencha[24]);
																										for (int a26 = 32; a26 < 123; a26++) {
																											sencha[25] = int_to_char(a26);
																											generatstring.push_back(sencha[25]);
																											for (int a27 = 32; a27 < 123; a27++) {
																												sencha[26] = int_to_char(a27);
																												generatstring.push_back(sencha[26]);
																												for (int a28 = 32; a28 < 123; a28++) {
																													sencha[27] = int_to_char(a28);
																													generatstring.push_back(sencha[27]);
																													for (int a29 = 32; a29 < 123; a29++) {
																														sencha[28] = int_to_char(a29);
																														generatstring.push_back(sencha[28]);
																														for (int a30 = 32; a30 < 123; a30++) {
																															sencha[29] = int_to_char(a30);
																															generatstring.push_back(sencha[29]);
																															for (int a31 = 32; a31 < 123; a31++) {
																																sencha[30] = int_to_char(a31);
																																generatstring.push_back(sencha[30]);
																																for (int a32 = 32; a32 < 123; a32++) {
																																	sencha[31] = int_to_char(a32);
																																	generatstring.push_back(sencha[31]);
																																	for (int a33 = 32; a33 < 123; a33++) {
																																		sencha[32] = int_to_char(a33);
																																		generatstring.push_back(sencha[32]);
																																		for (int a34 = 32; a34 < 123; a34++) {
																																			sencha[33] = int_to_char(a34);
																																			generatstring.push_back(sencha[33]);
																																			for (int a35 = 32; a35 < 123; a35++) {
																																				sencha[34] = int_to_char(a35);
																																				generatstring.push_back(sencha[34]);
																																				for (int a36 = 32; a36 < 123; a36++) {
																																					sencha[35] = int_to_char(a36);
																																					generatstring.push_back(sencha[35]);
																																					for (int a37 = 32; a37 < 123; a37++) {
																																						sencha[36] = int_to_char(a37);
																																						generatstring.push_back(sencha[36]);
																																						for (int a38 = 32; a38 < 123; a38++) {
																																							sencha[37] = int_to_char(a38);
																																							generatstring.push_back(sencha[37]);
																																							for (int a39 = 32; a39 < 123; a39++) {
																																								sencha[38] = int_to_char(a39);
																																								generatstring.push_back(sencha[38]);
																																								for (int a40 = 32; a40 < 123; a40++) {
																																									sencha[39] = int_to_char(a40);
																																									generatstring.push_back(sencha[39]);
																																									for (int a41 = 32; a41 < 123; a41++) {
																																										sencha[40] = int_to_char(a41);
																																										generatstring.push_back(sencha[40]);
																																										generatstring = encoding(generatstring);
																																										std::cout << generatstring << std::endl;
																																										if (generatstring == english)
																																										{
																																											for (int icha = 0; icha < 41; icha++) {
																																												std::cout << sencha[icha];
																																											}
																																										}
																																										else {
																																											generatstring.pop_back();
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}

									}
								}
							}
						}

					}
				}
			}
		}
	}
	*/

 }
 void decode::forloopdecode()
 {
	 std::string english = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	 char sencha[41];
	 std::vector<int>::iterator itr;
	 std::string generatstring;
	 for (int a1 = 32; a1 < 123; a1++) {
		 sencha[0] = int_to_char(a1);
		 generatstring.push_back(sencha[0]);
		 for (int a2 = 32; a2 < 123; a2++) {
			 sencha[1] = int_to_char(a2);
			 generatstring.push_back(sencha[1]);
			 for (int a3 = 32; a3 < 123; a3++) {
				 sencha[2] = int_to_char(a3);
				 generatstring.push_back(sencha[2]);
				 for (int a4 = 32; a4 < 123; a4++) {
					 sencha[3] = int_to_char(a4);
					 generatstring.push_back(sencha[3]);
					 for (int a5 = 32; a5 < 123; a5++) {
						 sencha[4] = int_to_char(a5);
						 generatstring.push_back(sencha[4]);
						 for (int a6 = 32; a6 < 123; a6++) {
							 sencha[5] = int_to_char(a6);
							 generatstring.push_back(sencha[5]);
							 for (int a7 = 32; a7 < 123; a7++) {
								 sencha[6] = int_to_char(a7);
								 generatstring.push_back(sencha[6]);
								 for (int a8 = 32; a8 < 123; a8++) {
									 sencha[7] = int_to_char(a8);
									 generatstring.push_back(sencha[7]);
									 for (int a9 = 32; a9 < 123; a9++) {
										 sencha[8] = int_to_char(a9);
										 generatstring.push_back(sencha[8]);
										 for (int a10 = 32; a10 < 123; a10++) {
											 sencha[9] = int_to_char(a10);
											 generatstring.push_back(sencha[9]);
											 for (int a11 = 32; a11 < 123; a11++) {
												 sencha[10] = int_to_char(a11);
												 generatstring.push_back(sencha[10]);
												 for (int a12 = 32; a12 < 123; a12++) {
													 sencha[11] = int_to_char(a12);
													 generatstring.push_back(sencha[11]);
													 for (int a13 = 32; a13 < 123; a13++) {
														 sencha[12] = int_to_char(a13);
														 generatstring.push_back(sencha[12]);
														 for (int a14 = 32; a14 < 123; a14++) {
															 sencha[13] = int_to_char(a14);
															 generatstring.push_back(sencha[13]);
															 for (int a15 = 32; a15 < 123; a15++) {
																 sencha[14] = int_to_char(a15);
																 generatstring.push_back(sencha[14]);
																 for (int a16 = 32; a16 < 123; a16++) {
																	 sencha[15] = int_to_char(a16);
																	 generatstring.push_back(sencha[15]);
																	 for (int a17 = 32; a17 < 123; a17++) {
																		 sencha[16] = int_to_char(a17);
																		 generatstring.push_back(sencha[16]);
																		 for (int a18 = 32; a18 < 123; a18++) {
																			 sencha[17] = int_to_char(a18);
																			 generatstring.push_back(sencha[17]);
																			 for (int a19 = 32; a19 < 123; a19++) {
																				 sencha[18] = int_to_char(a19);
																				 generatstring.push_back(sencha[18]);
																				 for (int a20 = 32; a20 < 123; a20++) {
																					 sencha[19] = int_to_char(a20);
																					 generatstring.push_back(sencha[19]);
																					 for (int a21 = 32; a21 < 123; a21++) {
																						 sencha[20] = int_to_char(a21);
																						 generatstring.push_back(sencha[20]);
																						 for (int a22 = 32; a22 < 123; a22++) {
																							 sencha[21] = int_to_char(a22);
																							 generatstring.push_back(sencha[21]);
																							 for (int a23 = 32; a23 < 123; a23++) {
																								 sencha[22] = int_to_char(a23);
																								 generatstring.push_back(sencha[22]);
																								 for (int a24 = 32; a24 < 123; a24++) {
																									 sencha[23] = int_to_char(a24);
																									 generatstring.push_back(sencha[23]);
																									 for (int a25 = 32; a25 < 123; a25++) {
																										 sencha[24] = int_to_char(a25);
																										 generatstring.push_back(sencha[24]);
																										 for (int a26 = 32; a26 < 123; a26++) {
																											 sencha[25] = int_to_char(a26);
																											 generatstring.push_back(sencha[25]);
																											 for (int a27 = 32; a27 < 123; a27++) {
																												 sencha[26] = int_to_char(a27);
																												 generatstring.push_back(sencha[26]);
																												 for (int a28 = 32; a28 < 123; a28++) {
																													 sencha[27] = int_to_char(a28);
																													 generatstring.push_back(sencha[27]);
																													 for (int a29 = 32; a29 < 123; a29++) {
																														 sencha[28] = int_to_char(a29);
																														 generatstring.push_back(sencha[28]);
																														 for (int a30 = 32; a30 < 123; a30++) {
																															 sencha[29] = int_to_char(a30);
																															 generatstring.push_back(sencha[29]);
																															 for (int a31 = 32; a31 < 123; a31++) {
																																 sencha[30] = int_to_char(a31);
																																 generatstring.push_back(sencha[30]);
																																 for (int a32 = 32; a32 < 123; a32++) {
																																	 sencha[31] = int_to_char(a32);
																																	 generatstring.push_back(sencha[31]);
																																	 for (int a33 = 32; a33 < 123; a33++) {
																																		 sencha[32] = int_to_char(a33);
																																		 generatstring.push_back(sencha[32]);
																																		 for (int a34 = 32; a34 < 123; a34++) {
																																			 sencha[33] = int_to_char(a34);
																																			 generatstring.push_back(sencha[33]);
																																			 for (int a35 = 32; a35 < 123; a35++) {
																																				 sencha[34] = int_to_char(a35);
																																				 generatstring.push_back(sencha[34]);
																																				 for (int a36 = 32; a36 < 123; a36++) {
																																					 sencha[35] = int_to_char(a36);
																																					 generatstring.push_back(sencha[35]);
																																					 for (int a37 = 32; a37 < 123; a37++) {
																																						 sencha[36] = int_to_char(a37);
																																						 generatstring.push_back(sencha[36]);
																																						 for (int a38 = 32; a38 < 123; a38++) {
																																							 sencha[37] = int_to_char(a38);
																																							 generatstring.push_back(sencha[37]);
																																							 for (int a39 = 32; a39 < 123; a39++) {
																																								 sencha[38] = int_to_char(a39);
																																								 generatstring.push_back(sencha[38]);
																																								 for (int a40 = 32; a40 < 123; a40++) {
																																									 sencha[39] = int_to_char(a40);
																																									 generatstring.push_back(sencha[39]);
																																									 for (int a41 = 32; a41 < 123; a41++) {
																																										 sencha[40] = int_to_char(a41);
																																										 generatstring.push_back(sencha[40]);
																																										 generatstring = encoding(generatstring);
																																										 std::cout << generatstring << std::endl;
																																										 if (generatstring == english)
																																										 {
																																											 for (int icha = 0; icha < 41; icha++) {
																																												 std::cout << sencha[icha];
																																											 }
																																										 }
																																										 else {
																																											 generatstring.pop_back();
																																											 for (int icha = 0; icha < 41; icha++) {
																																												 sencha[icha] = 0;
																																												 
																																											 }
																																										 }
																																									 }
																																								 }
																																							 }
																																						 }
																																					 }
																																				 }
																																			 }
																																		 }
																																	 }
																																 }
																															 }
																														 }
																													 }
																												 }
																											 }
																										 }
																									 }
																								 }
																							 }
																						 }
																					 }
																				 }
																			 }
																		 }
																	 }
																 }
															 }
														 }
													 }
												 }
											 }
										 }

									 }
								 }
							 }
						 }

					 }
				 }
			 }
		 }
	 }
	 

 }

void decode::digui(char all_the_words[],std::string sequence, int n, int k)
{
	//k=length
	if (k == 0) {
		std::cout << sequence << std::endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		std::string newSequence;
		newSequence = sequence + all_the_words[i];
		if (enn == encoding(newSequence))
		{
			std::cout << newSequence << std::endl;
			//ofs_recur << newSequence << std::endl;
			return;
		}
		//newSequence.push_back(all_the_words[i]);
		digui(all_the_words,newSequence, n, k - 1);
	}
}

void decode::pojie()
{
	std::string english = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	std::string tempstring="";
	sentc = "";
	char cha;
	int size;
	int flagnum = 0;
	offset = 0;
	counter = 0;
	int numi = 0;
	//std::vector<char>::iterator r = result.end();

	char all_the_words[59] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'!', ':', ';', '?', ',', '.','\t' };// all in 58 cha
	while (flag != true)
	{
		//for (int cishu = 0; cishu < 1; cishu++)
		//{
			flagnum = 91;
			for (int a = 32; a <=122; a++)
			{
				
				english = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
				//tempstring = encoding_asciinum(a);
				//tempnum = charTransferInt(chr);//将每个字符char转换为Ascii码		
				//tempnum = tempnum + offset;
				//传入Ascii码，计算出到1的步骤counter	
				//int i = charTransferInt(all_the_words[a]);
				nextcounter=Collatz(a+offset);//将最终加密数字转为string类型
				//finished_password = finished_password + pass;//将每个加密后的字符串联为一个长字符串
				//offset = counter;
				tempstring = tempstring + std::to_string(nextcounter);
				//size = tempstring.size();
				sentc = sentc + tempstring;
				size = sentc.size();
				english.resize(size);
				flagnum--;
				std::cout << sentc << std::endl;
				if (sentc==english)
				{
					offset = nextcounter;
					result.push_back(int_to_char(a));
					num[numi] = nextcounter;
					numi++;
					//sentc = sentc + tempstring;
					std::cout << "------------------------- " << sentc << std::endl;
					std::cout << "---------------------------- " << int_to_char(a) << std::endl;
					flagnum=91;
					//cishu = 0;
					//std::cout << result << std::endl;
					//break;
				}
				else if (english == sentc)
				{
					//print all result
					flag = true;
				}
				else if (flagnum == 0) {
					std::string deletechar;
					num[numi]=NULL;
					deletechar = num[numi];
					numi--;
					if(!result.empty())
						result.pop_back();
					
					sentc = sentc.substr(0, sentc.length() - deletechar.length());
				}
				else
				{
					flag = false;
					sentc = sentc.substr(0, sentc.length() - tempstring.length());
					tempstring.clear();
				}
				//flagnum--;
				//counter_asciinum = 0;
			}
		//}
		
	}
}
void decode::encode()
{

}
int decode::calc(int i)
{
	if (i == 1)
		return i;

	if (i % 2 == 0)
		return i / 2;
	else
		return 3 * i + 1;
}
int decode::Collatz(int singlecha)
{
	counter = 0;
	while (singlecha != 1)
	{
		singlecha = calc(singlecha);
		counter++;
	}
	return counter;
}

void decode::arraydecode()
{
	
	std::string tempstring = "";
	sentc = "";
	char cha;
	int size;
	int flagnum = 0;
	offset = 0;
	counter = 0;
	int numi = 0;
	std::string english = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	char arraynum[35][100];
	while (flag != true)
	{
		for (int i = 0; i < 35; i++)
		{
			for (int a = 32; a <= 122; a++)
			{
				english = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
				
				nextcounter = Collatz(a + offset);//将最终加密数字转为string类型
				//finished_password = finished_password + pass;//将每个加密后的字符串联为一个长字符串
				//offset = counter;
				tempstring = tempstring + std::to_string(nextcounter);
				//size = tempstring.size();
				sentc = sentc + tempstring;
				size = sentc.size();
				english.resize(size);
				flagnum--;
				std::cout << sentc << std::endl;
				if (sentc== english)
				{
					offset = nextcounter;
				
					arraynum[i][a-32] = nextcounter;
					//sentc = sentc + tempstring;
					std::cout << "------------------------- " << sentc << std::endl;
					std::cout << "---------------------------- " << int_to_char(a) << std::endl;
					flagnum = 91;
					//english.erase(0,size);
					
					//cishu = 0;
					//std::cout << result << std::endl;
					//break;
				}
				else if (english == sentc)
				{
					//print all result
					flag = true;
				}
				else if (flagnum == 0) 
				{
					std::string deletechar;
					deletechar = arraynum[i][a - 32];
					arraynum[i][a - 32] = 0;
					i--;
					sentc = sentc.substr(0, sentc.length() - deletechar.length());
					//tempstring.clear();
				}
				else
				{
					flag = false;
					sentc = sentc.substr(0, sentc.length() - tempstring.length());
					tempstring.clear();
				}
				//flagnum--;
				//counter_asciinum = 0;
			}
				//}
		}
		

	}
}