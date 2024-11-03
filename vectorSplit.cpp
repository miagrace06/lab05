#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
using namespace std;

vector<string> split(string target, string delimiter){
	vector<string> result; //Vector to store the resulting substrings 
	
	//If the delimiter is empty, return the entire target as a single substring
	if (delimiter.empty()){
		result.push_back(target);
		return result;
	}	
	//Find the position of the first occurrence of the delimiter in the target string 
	int position = target.find(delimiter);
	//Loop until no more occurrences of the delimiter are found 
	while (position != -1) {
		//Extract the substring from the start of the target to the position of the delimiter
		string token = target.substr(0, position);
		//If the token is not empty, add it to the result
		if (!token.empty()) {
			result.push_back(token);
		}
		//Erase the processed part of the target string 
		target.erase( 0, position + delimiter.length());
		//Find the next occurrence of the delimiter
		position = target.find(delimiter);
	}
	//If there's any remaining part of the target string after the last delimiter, add it to the result
	if (!target.empty()) {
		result.push_back(target);
	}
	return result; //Return the vecotr of substrings 
}



int main() {
	
    string target, delimiter; //variables to store user input for the target string and delimiter 

    //Prompt the user to enter the string to split
    cout << "Enter string to split:" << endl;
    getline(cin, target); //Read the entire line including spaces
    //Prompt the user to enter the delimiter string 
    cout << "Enter delimiter string:" << endl;
    getline(cin, delimiter); //Read the delimiter
    //Call the splt function to get the substrings 
    vector<string> substrings = split(target, delimiter);
    //Check if both target and delimiter are empty 
    if (target.empty() && delimiter.empty()) {
	    cout << "No substrings." << endl; //Inform the user if both are empty 
    } else {
	    cout<< "The substrings are: ";
	    //Loop through the substrings vector to print each substring 
	    for (size_t i = 0; i < substrings.size(); i++) {
		    cout << "\"" << substrings[i] << "\""; //print the substring with quotes 
		    if ( i < substrings.size() - 1) {
			    cout << ", "; //Add a comma if it's not the last substring
			}
		}
    cout << endl; //print a newline after all substrings are displayed
    }
    return 0;
}
