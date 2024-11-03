#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
using namespace std;

// FUNCTION DECLARATION: YOU MUST DEFINE AND USE THIS (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use function split() below.
vector<string> split(string target, string delimiter){
	vector<string> result;

	if (delimiter.empty()){
		result.push_back(target);
		return result;
	}	

	int position = target.find(delimiter);
	while (position != -1) {
		string token = target.substr(0, position);
		if (!token.empty()) {
			result.push_back(token);
		}
		target.erase( 0, position + delimiter.length());
		position = target.find(delimiter);
	}
	if (!target.empty()) {
		result.push_back(target);
	}
	return result;
}



int main() {

    // MISSING CODE HERE (you can remove these comments)
    // Get target string from user, get delimiter string from user
    // Call function split()
    // What happens next?!!?
    string target, delimiter;

    cout << "Enter string to split:" << endl;
    getline(cin, target);

    cout << "Enter delimiter string:" << endl;
    getline(cin, delimiter);

    vector<string> substrings = split(target, delimiter);
    if (substrings.empty() && target.empty()) {
	    cout << "No substrings." << endl;
    } else {
	    cout<< "The substrings are: ";
	    for (size_t i = 0; i < substrings.size(); i++) {
		    cout << "\"" << substrings[i] << "\"";
		    if ( i < substrings.size() - 1) {
			    cout << ", ";
	    }
    }
    cout << endl;
    }
    return 0;
}
