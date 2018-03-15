#include <vector>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int i, j;

void head(char mas[])
{
	int len, third, s1_len, s2_len, s3_len, maks;
	len = strlen(mas);
	third = len / 3;
	s1_len = third;
	for (int i = s1_len; i < len; i++)
	{
		if (mas[s1_len] != ' ') s1_len++;
		else break;
	}
	s2_len = third;
	for (int i = s1_len + s2_len; i < len; i++)
	{
		if (mas[s1_len + s2_len] != ' ') s2_len++;
		else break;
	}
	s3_len = len - (s1_len + s2_len);
	vector<char>str1(s1_len);
	vector<char>str2(s2_len);
	vector<char>str3(s3_len);
	for (int i = 0; i < s1_len; i++)
	{
		str1[i] = mas[i];
	}
	for (int i = s1_len + 1; i < s1_len + s2_len; i++)
	{
		str2[i - (s1_len + 1)] = mas[i];
	}
	for (int i = s1_len + s2_len + 1; i < len; i++)
	{
		str3[i - (s1_len + s2_len + 1)] = mas[i];
	}
	maks = s1_len;
	if (s2_len > maks)maks = s2_len;
	if (s3_len > maks)maks = s3_len;
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	setlocale(LC_ALL, ".866");
	cout << " Ú";
	for (int i = 0; i <= maks + 1; i++)cout << "Ä";
	cout << "¿\n";
	cout << " ³ "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s1_len; i++) cout << str1[i];
	if (s1_len < maks)
	{
		for (int i = 0; i < maks - s1_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " ³\n";
	cout << " ³ "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s2_len; i++) cout << str2[i];
	if (s2_len < maks)
	{
		for (int i = 0; i < maks - s2_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " ³\n";
	cout << " ³ "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s3_len; i++) cout << str3[i];
	if (s3_len < maks)
	{
		for (int i = 0; i < maks - s3_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " ³\n";
	cout << " À";
	for (int i = 0; i <= maks + 1; i++)cout << "Ä";
	cout << "Ù\n";
	SetConsoleTextAttribute(hConsole, 15);
	setlocale(LC_ALL, ".1251");
}

void yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

void green()
{
	SetConsoleTextAttribute(hConsole, 11);
}

void oSymb(char*str, int r)
{
	unsigned char words[30];
	int n = 0, kon=0, ws=0;
	while (kon<r)
	{
		while (str[kon] != ' '&&str[kon] != ',')
		{
			if(kon!=r)
			kon++;
			else break;
		}
		for (int i = n; i < kon; i++)
		{
			words[ws] = str[i];
			ws++;
		}
		words[ws] = '\0';
		if (kon - n != 1)
		{
			red();
			if (isupper(words[0]))
			{
				//words[0] = tolower(words[0]);
				if (tolower(words[0]) == words[ws - 1])
					cout << words << endl;
			}
			else
			{
				if (words[0] == words[ws - 1])
					cout << words << endl;
			}
		}
		n = kon+1;
		if (str[kon] != ' '||str[kon] != ',')kon++;
		ws = 0;
	}
	white();
}

void rSymb(char*str, int r)
{
	int c = 0;
	while (c<r)
	{
		for (int i = c; i < r; i++)
		{
			if (str[i] != '<')c++;
			else
			{
				c = i;
				break;
			}
		}
		if ((str[c + 1] == '/'&&str[c + 2] == 'i') || (str[c + 1] == '/'&&str[c + 2] == 'I'))
		{
			str[c + 1] = '#';
			for (int i = c + 2; i < r + 1; i++)
			{
				str[i] = str[i+1];
			}
		}
		c++;
	}	
	/*cout << str << endl;*/
	c = 0;
	while (c<r)
	{
		for (int i = c; i < r; i++)
		{
			if (str[i] != '<')c++;
			else
			{
				c = i;
				break;
			}
		}
		if ((str[c + 1] == 'i'&&str[c + 2] == '>') || (str[c + 1] == 'I'&&str[c + 2] == '>'))
		{
			int b = strlen(str);
			for (int i = b + 1; i > c; i--)
			{
				str[i+1] = str[i];
			}
			str[c + 1] = '/';
		}
		c++;
	}
	cout << str << endl;
}

int Dx(char*str)
{
	int r = 0;
	char c;
	for (int i = 0; i < strlen(str); i++)
	{
		c = str[i];
		r = r * 2 + atoi(&c);
	}
	return r;
}

bool pr(char*str)
{
	bool pr = true;	
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] < 48 || str[i] > 49)
		{
			pr = false;
			break;
		}
	}
	return pr;
}
