/*
	Simulate Cyclic Redundancy Check (CRC) error detection algorithm for noisy channel.
	Written by Anshul Verma (19/78065)
*/

#include <iostream>
#include <string>
using namespace std;

/*****************************************
	Helper functions
******************************************/
/* To remove leading spaces in a string */
string removeLeading0s(string str)
{
	int i;
	for(i=0; i < str.length(); ++i)
		if(str[i] == '1') break;
	return str.substr(i);
}
/* To check if each bit in string is zero */
bool isZero(string str)
{
	str = removeLeading0s(str);
	if(str.length() <= 0)
		return true;
	else 
		return false;
}
/* To check if input string has any errors or illegal characters */
bool checkInput(string str)
{
	str = removeLeading0s(str);
	if(isZero(str))
	{
		cout << "\nInput Error!\nEntered bits are only zero.\n" << endl;
		return false;
	}
	for(int i = 0; i < str.length(); ++i)
	{
		if(str[i] != '1' && str[i] != '0')
		{
			cout << "\nInput Error!\nEntered bits contain characters other than 0 or 1.\n" << endl;
			return false;
		}
	}	
	return true;
}

/**********************************************
	Modulo 2 division function
***********************************************/
string division(string dividend, string divisor)
{
	string remainder = "";
	for(int i=0; i <= dividend.length() - divisor.length(); )
	{
		/* Taking XOR, bit by bit */
		for(int j=0; j < divisor.length(); ++j)
			dividend[i+j] = (dividend[i+j] == divisor[j]) ? '0' : '1';
		
		/* To find the index for next iter*/
		while(i < dividend.length() && dividend[i] != '1')
			++i;
	}
	/* 
		Calculating remainder i.e. last n-1 digits of encoded string, n: length of gen
	*/
	remainder = dividend.substr(dividend.length() - divisor.length());
	return remainder;
}

/**************************
	CRC function
***************************/
void CRC(string encoded, string gen)
{
	int i;
	/* Checking for error by again performing modulo 2 division */
	cout << "\nApplying Cyclic Redundancy Check...." << endl;
	string rem = division(encoded, gen);
	if(!isZero(rem))
		cout << "\nError detected!\nRemainder: " << removeLeading0s(rem);
	else 
		cout << "\nNo error!\nRemainder is 0.";
}

/***************************
	Main Function
****************************/
int main()
{
	/* Creating Variables */
	int i;
	string msg, gen, rem, temp, encoded;
	
	/* Taking Input and performing checks on Input*/
	cout << "\nEnter the frame: ";
	cin >> msg;
	if(!checkInput(msg))
		return 1;
	cout << "Enter the generator: ";
	cin >> gen;
	if(!checkInput(gen))
		return 1;
	if(gen[gen.length()-1] != '1')
	{
		cout << "\nInput Error!\nLast bit in generator is not 1.\n" << endl;
		return 1;
	}
	if(msg.length() < gen.length())
	{
		cout << "\nInput Error!\nLength of frame is smaller than length of generator.\n" << endl;
		return 1;
	}
	
	/* Cleaning input */
	msg = removeLeading0s(msg);
	gen = removeLeading0s(gen);
	
	/*
		Appending zero bits to the low-order end
of the message
	*/
	temp = msg;
	for(i=0; i < gen.length() - 1; ++i)
		temp += "0";
	
	/* 
		Performing modulo 2 division to find remainder and printing it
	*/
	rem = division(temp, gen);
	cout << "\nRemainder: " << removeLeading0s(rem) << endl;
	
	/* Calculating encoded msg */
	encoded = msg + rem.substr(1);
	cout << "Transmitted frame: " << encoded << endl;
	
	/* Adding Error */
	char ch;
	cout << "\nWant to add errors ? (Y/N): ";
	cin >> ch;
	if(ch == 'y' || ch == 'Y')
	{
		int n;
		cout << "\nEnter the index of bit to add the error: ";
		cin >> n;
		encoded[n-1] = (encoded[n-1] == '0') ? '1' : '0';
		cout << "\nTransmitted frame with error: " << encoded << endl;
		
		/* Checking error by CRC */
		CRC(encoded, gen);
	}
	cout << endl << endl;
	return 0;
}