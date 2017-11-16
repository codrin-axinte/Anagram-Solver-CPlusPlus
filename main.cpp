#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string value, char token);
string GetAnagram(unsigned maxLength);
void FindSolution(string anagram, string word);

string solution;

int main() {
	string anagram = GetAnagram(6);
	cout << "Please wait! Cracking..." << endl;
	ifstream infile("db.csv");
	string line;	
	while (infile >> line) {		
		string word = split(line, ',').at(0);
		if (word.length() > anagram.length()) continue;
		FindSolution(anagram, word);		
	}
	if (solution == "") 
		std::cout << "No solution was found!" << endl;	
	else 
		std::cout << "Best solution: " << solution << endl;
		
	system("pause");

	return 0;
}


void FindSolution(string anagram, string word) {
	bool valid = true;
	map<unsigned, bool> slots;	
	for (unsigned i = 0; i < word.length(); i++) {
		bool found = false;
		for (unsigned j = 0; j < anagram.length(); j++) {			
			if (anagram[j] == word[i] && !found) {
				if (!slots[j]) {
					found = true;
					slots[j] = true;										
				}	
			}		
		}
		if (found == false) {
			valid = false;
			break;
		}
	}

	if (valid && solution.length() < word.length()) {
		solution = word;		
	}	
}



string GetAnagram(unsigned maxLength) {
	string a;
	do {
		std::cout << "Anagram: ";
		cin >> a;
		std::cout << endl;
		if (a.length() > maxLength) {
			std::cout << "Anagram can have " << maxLength << " maximum letters" << endl;
		}
	} while (a.length() > maxLength);

	return a;
}



vector<string> split(string value, char token) {
	stringstream ss(value);
	vector<string> vect;

	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		vect.push_back(substr);
	}

	return vect;
}

