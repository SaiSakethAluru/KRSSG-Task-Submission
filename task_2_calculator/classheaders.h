#ifndef CLASS_H
#define CLASS_H
#include "header.h"
class Input
{
public:
	int input;
	int take_input()
	{
	cout<<"Give input : ";
	cin>>input;
	return input;
	}
};
class decimal: public Input
{
public:
	int convert_dec2oct(int dec)
	{
   		int rem, i = 1, octa = 0;
   		int temp = dec;
    	while (temp){
	    	rem = temp % 8;
	    	temp /= 8;
	    	octa += rem * i;
	    	i *= 10;
   		}
    	return octa;
	}
	int convert_dec2bin(int dec)
	{
		int rem,i=1,bin=0;
		int a = dec;
		while(a){
			rem = a%2;
			a/= 2;
			bin+=rem*i;
			i*=10;
		}
		return bin;
	}
	string convert_dec2hex(int dec)
	{
		char hex[100];
		int quotient=dec,temp,i=0;
		while(quotient){
			temp = quotient%16;
			if(temp<10)
				temp+=48;
			else	temp+=55;		
			hex[i++]=temp;
			quotient/=16;
		}
		hex[i]='\0';
		char c;
        for(int j=0;j<i/2;j++){
        	c=hex[j];
            hex[j]=hex[i-j-1];
            hex[i-j-1]=c;
        }
        return hex;
	}
	decimal operator+(decimal &numd1)
	{
		decimal res;
		res.dec = this->dec + numd1.dec;
		return res;
	}
	decimal operator-(decimal &numd1)
	{
		decimal res;
		res.dec = this->dec - numd1.dec;
		return res;
	}
	decimal operator*(decimal &numd1)
	{
		decimal res;
		res.dec = this->dec * numd1.dec;
		return res;	
	}
	decimal operator/(decimal &numd1)
	{
		decimal res;
		res.dec = this->dec / numd1.dec;
		return res;
	}
	
	int dec;
};
class octa: public Input
{
public:
	int convert_oct2dec(int oct)
	{
		int temp=oct,res=0,x=1;
		while(temp){
			res+=(temp%10)*x;
			temp/=10;
			x*=8;
		}
		return res;
	}
	int oct;
};
class hexa :public Input
{
public:
	string take_input(){
		string s;
		cout<<"Give input: ";
		cin>>s;
		return s;
	}
	int convert_hex2dec(string s)
	{
			stringstream ss;		  
    		ss << hex << s;
    		unsigned n;
    		ss >> n;
    		return n;
	}
 	string s;
};
class binary: public Input
{
public:
	int convert_bin2dec(int bin)
	{
		int temp=bin,res=0,x=1;
		while(temp){
			res+=(temp%10)*x;
			temp/=10;
			x*=2;
		}
		return res;
	}
	int bin;
};
#endif