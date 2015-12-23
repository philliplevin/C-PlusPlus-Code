#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Code
{
   public:
   Code();  // Default constructor - loads and uses morse code
   Code(vector<string> codewords);  // constructor loading customized code
   string encode(vector<char> message);  // encodes a message consisting of A-Z
   string decode(vector<string> message);  // decodes a message 

   private:
   vector<string> codewords; // this is a codeword vector parallel to A-Z
   vector<char> alpha; // this is the vector A-Z
   vector<char>  alphacode(); // function builds the vector alpha - A B C etc.
   vector<string>  morsecode(); // function the vector codewords containing  morse code
   string encode(char x); //returns the codeword for the character x
   char decode(string c); //returns the character for the codeword c.
   vector<string> code;

};

int main ()
{
	cout << "Enter a 0 to input a message in English, or enter a 1 to input a message in morse code." << endl;
	int userinput;
	cin >> userinput;
	
	cout << "Enter your message." << endl;
	cin.clear();
	cin.ignore(10000,'\n');
	
	if(userinput == 0)
	{
		vector<char> usermessage;
		char x;
  
  		cin.get(x);
		while(x != '.')
		{	
			usermessage.push_back(x);
	  		cin.get(x);
		}
		usermessage.push_back('.');

		Code alphamessage;
		cout << "The encoded message is: " << alphamessage.encode(usermessage) << endl;
	}
	else if(userinput == 1)
	{
	   	vector<string> morsecode;	
		string input;
		cin >> input;
	
		while(input != "x")
		{	
			morsecode.push_back(input);
			cin >> input;
		}
		morsecode.push_back("x");
	
		Code codemessage;
		cout << "The decoded message is: " << codemessage.decode(morsecode) << endl;
	}
	
}

Code::Code()
{
   alphacode();
   morsecode();
}

Code::Code(vector<string> codewords)
{
   this-> code = codewords;  
}

vector<string>Code::morsecode()
{ 	
	// This function returns a vector containing the morse code
 	vector<string> temp(28);
 	temp[0] =".-";
 	temp[1] ="-...";
	 temp[2] ="-.-.";
 	temp[3] ="-..";
 	temp[4] =".";
 	temp[5] ="..-.";
 	temp[6] ="--.";
 	temp[7] ="....";
 	temp[8] ="..";
 	temp[9] =".---";
 	temp[10] ="-.-";
 	temp[11] =".-..";
 	temp[12] ="--";
 	temp[13] ="-.";
 	temp[14] ="---";
 	temp[15] =".--.";
 	temp[16] ="--.--";
	 temp[17] =".-.";
 	temp[18] ="...";
 	temp[19] ="-";
 	temp[20] ="..-";
 	temp[21] ="...-";
 	temp[22] =".--";
 	temp[23] ="-..-";
 	temp[24] ="-.--";
 	temp[25] ="--..";
 	temp[26] =".......";
 	temp[27] ="x";
 	this->codewords = temp;
 	return codewords;
}

vector<char>Code::alphacode()
{// This returns a vector containing the alphabet a-z and " "
 vector<char> temp;
 for (char c='A'; c<='Z'; c++)
     	 temp.push_back(c);
	 temp.push_back(' ');
	 temp.push_back('.');
 	 this->alpha = temp;
 	 return alpha;
}

string Code::decode(vector< string> message)
{
	string alphaword;
	char alphaletter;
	
	for (int i = 0; i < message.size(); i++)
	{
		alphaletter = decode(message[i]);
		alphaword = alphaword + alphaletter;
	}

	return alphaword;
}

char Code::decode(string c)
{	
	for (int j = 0; j < codewords.size(); j++)
	{
		if (c == codewords[j])
		{
			return alpha[j];
		}	
	}
	
	cout << "No letter found in decode function for: " << c << endl;
}

string Code::encode(vector<char> message)
{
	string morseletter;
	string morseword;
	
	for (int i = 0; i < message.size(); i++)
	{
		morseletter = this->encode(message[i]);
		morseword = morseword + morseletter + " "; 
		
	}
	
	return morseword; 
}

string Code::encode(char x)
{
	for (int i = 0; i < codewords.size(); i++)
	{
		if (x == alpha[i])
		{
			return codewords[i];
		}
	}
	
	cout << "No letter found in the encode function for: " << x << endl;	
}

