#ifndef CLASS_H
#define CLASS_H
#include "header.h"
class Input
{
public:
	int input;
	int take_input();
};
class decimal: public Input
{
public:
	int convert_dec2oct(int dec);
	int convert_dec2bin(int dec);
	string convert_dec2hex(int dec);
	decimal operator+(decimal &numd1);
	decimal operator-(decimal &numd1);
	decimal operator*(decimal &numd1);
	decimal operator/(decimal &numd1);
	int dec;
};
class octa: public Input
{
public:
	int convert_oct2dec(int oct);
	int oct;
};
class hexa :public Input
{
public:
	string take_input();
	int convert_hex2dec(string s);
 	string s;
};
class binary: public Input
{
public:
	int convert_bin2dec(int bin);
	int bin;
};
#endif