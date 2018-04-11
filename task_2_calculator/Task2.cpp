#include "class.h"
int main()
{
	int in_choice,out_choice,number,del;
	vector<string> history;
	string a,b;
	decimal numd,numd1,numd2;
	binary numb;
	hexa numh;
	octa numo;
	while(1){
		print_menu();
		cin>>in_choice;
		try{
			switch(in_choice){
				case 1: 
					cout<<"Enter input type number: "<<endl;	
					print_type();
					cin>>in_choice;
					switch(in_choice){
						case 1: 
						numd.dec=numd.take_input();
						a = to_string(numd.dec) + " in decimal";
						number = numd.dec;
						break;
						case 2: 
						numb.bin = numb.take_input();
						a = to_string(numb.bin) + "in binary";
						number = numb.convert_bin2dec(numb.bin);
						break;
						case 3: 
						numh.s = numh.take_input();
						a = numh.s + " in Hexadecimal";
						number = numh.convert_hex2dec(numh.s);
						break;
						case 4: 
						numo.oct = numo.take_input();
						a = to_string(numo.oct) + " in octadecimal";
						number = numo.convert_oct2dec(numo.oct);
						break;

						default: throw -99;
					}
					cout<<"Select output type number: "<<endl;
					print_type();
					cin>>out_choice;
					switch(out_choice){
						case 1: cout<<"Number in decimal: "<<number<<endl;
						a= "Converted "+a+" to "+to_string(number)+" in decimal";
						break;
						case 2: cout<<"Number in binary: "<<numd.convert_dec2bin(number)<<endl;
						a="Converted "+a+" to "+to_string(number)+" in binary";
						break;
						case 3: cout<<"Number in Hexadecimal: "<<numd.convert_dec2hex(number)<<endl;
						a="Converted "+a+" to "+to_string(number)+" in hexadecimal";
						break;
						case 4: cout<<"Number in octadecimal: "<<numd.convert_dec2oct(number)<<endl;
						a="Converted "+a+" to "+to_string(number)+" in octadecimal";
						break;
						default: throw -99;
					}
					history.push_back(a);
					break;
				case 2:
					oper_menu();
					cin>>out_choice;
					cout<<"Enter first number format"<<endl;
					print_type();
					cin>>in_choice;
					switch(in_choice){
					case 1: numd1.dec = numd1.take_input();
					a=to_string(numd1.dec)+" in decimal";
					break;
					case 2: numb.bin = numb.take_input();
					a=to_string(numb.bin)+" in binary";
					numd1.dec = numb.convert_bin2dec(numb.bin);
					break;
					case 3: numh.s = numh.take_input();
					a=numh.s+" in hexadecimal";
					numd1.dec = numh.convert_hex2dec(numh.s);
					break;
					case 4: numo.oct = numo.take_input();
					a=numo.oct + " in octadecimal";
					numd1.dec = numo.convert_oct2dec(numo.oct);
					break;
					default: throw -99;
					}
					cout<<"Enter second number format"<<endl;
					print_type();
					cin>>in_choice;
					switch(in_choice){
					case 1: numd2.dec = numd2.take_input();
					b=to_string(numd1.dec)+" in decimal";
					break;
					case 2: numb.bin = numb.take_input();
					b=to_string(numb.bin)+" in binary";
					numd2.dec = numb.convert_bin2dec(numb.bin);
					break;
					case 3: numh.s = numh.take_input();
					b=to_string(numb.bin)+" in binary";
					numd2.dec = numh.convert_hex2dec(numh.s);
					break;	
					case 4: numo.oct = numo.take_input();
					b=to_string(numo.oct)+" in octadecimal";
					numd2.dec = numo.convert_oct2dec(numo.oct);
					break;
					}
					a=a+" + "+b;
					switch(out_choice){
						case 1:cout<<"Sum = "<<(numd1+numd2).dec<<endl;
						a=a+" = "+to_string((numd1+numd2).dec);
						break;
						case 2:cout<<"Difference = "<<(numd1-numd2).dec<<endl;
						a=a+" = "+to_string((numd1-numd2).dec);
						break;
						case 3:cout<<"Product = "<<(numd1*numd2).dec<<endl;
						a=a+" = "+to_string((numd1*numd2).dec);
						break;
						case 4:cout<<"quotient = "<<(numd1/numd2).dec<<endl;
						a=a+" = "+to_string((numd1/numd2).dec);
						break;
					}
					history.push_back(a);			
				break;
				case 3: 
				for(int i=0;i<history.size();i++){
					cout<<history[i]<<endl;
				}
				if(history.size()>0){
					cout<<"Specify the entry to be deleted. Press 0 to go back"<<endl;
					cin>>del;
					if(del==0)
						break;
					else if(del<=history.size() && del>0)
						history.erase(history.begin()+del-1);
					else throw -99;
				}
				else cout<<"No history to display"<<endl;
				break;
				case 4: exit(0);
				default: throw -99;
			}

		}
		catch(int x){
			cout<<"Invalid Choice."<<endl;
			exit(1);
		}
	}
	return 0;

}

void print_menu()
{
	cout<<endl<<"select the option number:"<<endl;
	cout<<"1.conversions"<<endl<<"2.arithmatic operations"<<endl<<"3.History"<<endl<<"4.Quit"<<endl;
}
void print_type()
{
	cout<<"1.Decimal"<<endl<<"2.Binary"<<endl<<"3.Hexadecimal"<<endl<<"4.octadecimal"<<endl;
}
void oper_menu()
{
	cout<<"Enter arithmatic operation number:"<<endl;
	cout<<"1.Addition"<<endl<<"2.Subtraction"<<endl<<"3.Multiplication"<<endl<<"4.Division"<<endl;
}
string to_string(int a)
{
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}