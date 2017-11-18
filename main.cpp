#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string value, char token);
string GetAnagram(unsigned maxLength);
void FindSolution(string anagram, string word, string &solution);

//string solution; // stores the best solution

int main() {
	ifstream db;
	string dbPath = "db.csv";

	while (true) { // Continous loop for application	
		string anagram = GetAnagram(6); // Obtain a valid anagram
		std::cout << "Please wait! Cracking..." << endl;
		db.open(dbPath); // open the database file
		string line; // store the current line
		string solution; // stores the best solution
		while (db >> line) { // read each line
			string word = split(line, ',').at(0); //because it is a csv file, split it and get the word
			if (word.length() > anagram.length()) continue; // if the word length is greater than the anagram's we skip it, because we don't need it
			FindSolution(anagram, word, solution); // Solve the anagram and get us a solution
		}
		db.close(); // close the file
		
		if (solution == "") // Check if a solution was found or not and output a message.
			std::cout << "No solution was found!" << endl;
		else
			std::cout << "Best solution: " << solution << endl;
	}
	
	
	system("pause"); // Pause the console

	return 0;
}


void FindSolution(string anagram, string word, string &solution) {
	bool valid = true; //stores if the current word is valid	
	map<unsigned, bool> slots; // maps each letter position of the anagram with the value of occupied or not.
	for (unsigned i = 0; i < word.length(); i++) { // Iterate over each letter of the given word(ACT/CAT)
		bool found = false; // stores if a word letter was found in the anagram		
		for (unsigned j = 0; j < anagram.length() && !found; j++) { // Iterate over each letter of the given anagram(TCA)
			// if the letter matches and it wasn't found already
			// If the slot is not occupied already, example: if the anagram is "sas" the world should be "ass", but without it, I will be "as" because of the repeated letters
			if (anagram[j] == word[i] && !slots[j]) { 				
					found = true; // set letter as found/match
					slots[j] = true; // occupy the slot								
			}		
		}
		if (found == false) { // if one letter was not found, we break the loop, the word is not a match
			valid = false;
			break; 
		}
	}

	if (valid && solution.length() < word.length()) { // if the given word is valid, check its length against the last solution's length
		solution = word; // we store a new solution		
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
		if (a == "" || a == " ") {
			std::cout << "Anagram can't be empty!" << endl;
		}
		
	} while (a.length() > maxLength || a == "" || a == " ");

	return a;
}



vector<string> split(string value, char token) {
	stringstream ss(value);
	vector<string> vect;

	while (ss.good()) {
		string substr;
		getline(ss, substr, token);
		vect.push_back(substr);
	}

	return vect;
}

