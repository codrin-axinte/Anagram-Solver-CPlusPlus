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
bool ContainsAll(string anagram, string word);

unsigned bestWeight = 0;
string solution;

int main(){
  // Get the anagram from the input and validate it
  string anagram = GetAnagram(6);
  
  ifstream infile("db.csv");
  string line;
  
  while(infile >> line){
    string word = split(line, ',').at(0);
    if(word.length() > anagram.length()) continue; 
    FindSolution(anagram, word); 
  }
  if(solution == ""){
  	cout << "No solution was found!" << endl;
  	
  } else {
  	cout << "Best solution: " << solution << endl;
  }
  
  return 0;
}

// zza -> a, OZR -> or, tca -> act
/* Tinker
	
  
*/  



void FindSolution(string anagram, string word) {
	bool valid = true;
	map<unsigned, bool> slots;
	cout << "Word: " << word << endl;
	cout << "=================" << endl;
    for(unsigned i=0; i < word.length(); i++){ // 0 -> a
	  bool found = false;
      
      for(unsigned j=0; j < anagram.length(); j++){
      	cout << word[i] << " -> " << anagram[j] << " ";
  	 	
  	 	if(slots[j] == true) { // tca -> 0,1,2 -> 
	 		cout << "@occupied";
	 	} else if(anagram[j] == word[i]) {
           slots[j] = true;
           found = true;
           cout << "@found";
    	} else {
    		slots[j] = false;
    	}
    	cout << endl;
      }
      
      cout << "----------" << endl;
      
      if(found == false) {
      	valid = false;
      	break;
      }
    }
    
	if(valid) {
		if(solution.length() > word.length()) return;
		solution = word;
		cout << "Is Valid" << endl;
	}
	
	cout << "=================" << endl;
}



string GetAnagram(unsigned maxLength) {
  string a;
  do {
  cout << "Anagram: ";
  cin >> a;
  cout << endl;
  if(a.length() > maxLength){
    cout << "Anagram can have " << maxLength << " maximum letters" << endl;
  }
  } while(a.length() > maxLength);
  
  return a;
}



vector<string> split(string value, char token){
    stringstream ss(value);
    vector<string> vect;
    
    while(ss.good()){
      string substr;
      getline(ss, substr, ',');
      vect.push_back(substr);
    }
    
    return vect;
}

