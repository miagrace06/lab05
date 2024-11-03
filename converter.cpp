#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>// for pow() function ONLY
#include <string> 
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 2 functions below.
int bin2d(string binstring){
	if (binstring.empty()) {
		return -1;
	}
	int decimalValue = 0;
	for (int i = 0; i <binstring.length(); i++) {
		if (binstring[i] != '0' && binstring[i] != '1'){
			return -1;
		}
		decimalValue = decimalValue * 2 + (binstring[i] - '0');
	}
	return decimalValue;
}

string dec2bh(string sdec, char bh) {
	int decimalValue = stoi(sdec);

	if (decimalValue < 0) {
		return "";
	}
	if (bh == 'b') {
		string binaryValue = "";
		if (decimalValue == 0) {
			return "0";
		}
		while (decimalValue > 0) {
			binaryValue = to_string(decimalValue % 2) + binaryValue;
			decimalValue /= 2;
		}
		return binaryValue;
	} else if (bh == 'h') {
		string hexValue = "";
		const char hexDigits[] = "0123456789ABCDEF";
		if (decimalValue == 0) {
			return "0";
		}
		while (decimalValue > 0) {
			hexValue = hexDigits[decimalValue % 16] + hexValue;
			decimalValue /= 16;
		}
		return hexValue;
	}
	return "";
}
int main ( int argc, char *argv[] ) {
	if (argc != 3) {
		cout << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
		exit(1);
	}
	string option = argv[1];
	string value = argv[2];

	if (option == "d2b") {
		int decimalvalue = stoi(value);
		string binaryValue = dec2bh(value, 'b');
		cout << "The value in binary is: " << binaryValue << endl;
	} else if (option == "d2h") {
		int decimalValue = stoi(value);
		string hexValue = dec2bh(value, 'h');
		cout << "The value in hexadecimal is: " << hexValue << endl;
	} else if (option == "b2d") {
		if (value.empty()) {
			return -1;
			exit(1);
		}
		int decimalValue = bin2d(value);
		if (decimalValue == -1) {
			cout << "Binary value contains non-binary digits." <<endl;
			exit(1);
		}
		cout << "The value in decimal is: " << decimalValue << endl;
	} else {
		cout << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
		exit (1);
	}
	return 0;
}
    // MISSING CODE HERE (you can remove these comments)
    // Check to see if the command-line arguments are being used correctly
    // Perform the conversion by calling the appropriate function
    // What happens next?!!?
// MISSING FUNCTION DEFINITIONS HERE 
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!
// (you can remove these comments)
