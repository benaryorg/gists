#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
#include <list>

#define BUF_SIZE 4096 //Should be longer than the longest word, else the word will get split.

using namespace std;

list<string> get_words_from_file(char *filename)
{
	ifstream file(filename);
	list<string> words;

	char str[BUF_SIZE]={};
	int i,j;

	while(file.good())
	{
		file.read(str+strlen(str),BUF_SIZE-1-strlen(str));
		for(i=j=0;i<BUF_SIZE-1;i++)
		{
			if(!isgraph(str[i]))
			{
				str[i]=0;
				if(strlen(str+j))
				{
					words.push_back(string(str+j));
				}
				j=i+1;
			}
		}
		if(!j)
		{
			words.push_back(string(str));
			*str=0;
		}
		memcpy(str,str+j,BUF_SIZE-j);
		memset(str+BUF_SIZE-j,0,j);
	}

	file.close();

	return words;
}
