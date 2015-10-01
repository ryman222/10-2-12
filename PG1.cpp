//RYAN M CIRESE
//This program takes in a number from the user
//and converts it from BASE10 to BASE12 and prints
//out the result. (9/2014)
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include "PG1.h"
using namespace std;

string s = "";
string temp = "";
string utemp = "";
string zero = "0";
int rem = 0;

int main(int argc, char **argv){
    cout << "Enter an integer to convert: ";
	string user;
	getline(cin, user);        

	//Convert
	convert(user, rem);

	//Remove leading 0's
	clean(s);

	cout << "" << endl;
	cout << "BASE 12: " + s << endl;
	cout << "" << endl;
	
	system ("pause");

	return 0;
}

void convert(string &user, int &rem){
	if(user != zero){
		int l = user.length();								
		rem = user[0] - '0';		//Grab first remainder
		if(l == 1){					//Run if user is only 1 digit
			rem = rem%12;		
			utemp = "0";
		}
		if(l > 1){
			for(int i = 1; i < l; i++){
				rem = (rem*10)+(user[i] - '0');					//Bring down the next digit
				utemp = utemp + to_string((long long)rem/12);	//Get Quotient
				rem = rem%12; 									//Store remainder
			}
		}
		if(rem == 10){temp = "A";}	//Convert 10 to an A
		if(rem == 11){temp = "B";}  //Convert 11 to a B
		if(rem != 10 && rem != 11){temp = to_string((long long)rem);}
		s.insert(0, temp);	//Insert the remainder to the front of the string
		user = utemp;										
		utemp = "";											

		convert(user, rem);											//Run again
	}
}

void clean(string &s){ //Recursive method that removes leading zeroes from the final output
	int temp = s[0] - '0'; //Get first number from string
	if(temp == 0){ //Run if(first number is zero)
		s = s.substr(1);

		clean(s);
	}
}



