#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>// for pow() function ONLY
#include <string> 
using namespace std;
//Converts a binary string to a decimal integer 
int bin2d(string binstring){
	//Check if the input string is empty 
	if (binstring.empty()) {
		return -1; //Return -1 to indicate an error 
	}
	int decimalValue = 0;//Variable to store the resulting decimal value 
	//Loop through each character in the binary string 
	for (int i = 0; i <binstring.length(); i++) {
		//Check if the character is not a valid binary digit 
		if (binstring[i] != '0' && binstring[i] != '1'){
			return -1; //Return -1 to indicate an error 
		}
		//Calculate the decimal value based on the binary digit 
		decimalValue = decimalValue * 2 + (binstring[i] - '0');
	}
	return decimalValue; //Return the converted decimal value 
}
//Converts a decimal string to either binary or hexadecimal representation 
string dec2bh(string sdec, char bh) {
	//Convert the decimal string to an integer 
	int decimalValue = stoi(sdec);

	//Check if the decimal value is negative 
	if (decimalValue < 0) {
		return "";//Return an empty string for negative values 
	}
	//If the user wants the binary representation 
	if (bh == 'b') {
		string binaryValue = ""; //Variable to store the binary result 
		//Special case for zero 
		if (decimalValue == 0) {
			return "0";
		}
		//Convert decimal to binary 
		while (decimalValue > 0) {
			binaryValue = to_string(decimalValue % 2) + binaryValue; //prepend the remainder
			decimalValue /= 2; //Divide by 2 to get the next bit
		}
		return binaryValue; //Return the binary representation 
	//if the user wants the hexadecimal representation 	
	} else if (bh == 'h') {
		string hexValue = ""; //Variable to store the hex result 
		const char hexDigits[] = "0123456789ABCDEF";//Hexadecimal digits 
		//Special case for zero 
		if (decimalValue == 0) {
			return "0";
		}
		//Convert decimal to hexadecimal
		while (decimalValue > 0) {
			hexValue = hexDigits[decimalValue % 16] + hexValue;//prepend the hex digit
			decimalValue /= 16;//divide by 16 to get the next hex digit 
		}
		return hexValue; // Return the hexadecimal representation 
	}
	return "";//Return an empty string if no valid option is provided 
}
int main ( int argc, char *argv[] ) {
	//check if the correct number of command-line arguments are provided 
	if (argc != 3) {
		cout << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;//Print usage message
		exit(1);//exit with error code 
	}
	string option = argv[1]; //store the conversion option
	string value = argv[2]; //store the value to be converted 
	//Handle conversion from decimal to binary
	if (option == "d2b") {
		int decimalvalue = stoi(value);//convert the string value to an integer
		string binaryValue = dec2bh(value, 'b');//call the conversion function
		cout << "The value in binary is: " << binaryValue << endl; //Output the result
	//Handle conversion from decimal to hexadecimal
	} else if (option == "d2h") {
		int decimalValue = stoi(value); //conver the sting value to an integer
		string hexValue = dec2bh(value, 'h');//call the conversion function
		cout << "The value in hexadecimal is: " << hexValue << endl;//output the result
	//Handle conversion from binary to decimal
	} else if (option == "b2d") {
		if (value.empty()) {
			exit(1);//Exit if the binary value is empty 
		}
		int decimalValue = bin2d(value); //call the conversion function 
		if (decimalValue == -1) {
			exit(1); //Exit if there was an error in conversion 
		}
		cout << "The value in decimal is: " << decimalValue << endl; //Output the result
	//handle invalid options
	} else {
		cout << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
		exit (1);
	}
	return 0; //Indicate successful program termination
}
   
