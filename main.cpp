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
  
  cout << "Best solution: " << solution << endl;
  return 0;
}


void FindSolution(string anagram, string word) {
  if(solution.length() > word.length()) return;
  unsigned weight = 0;
  map<char, int> repeateadLetters;
  for(unsigned i=0; i < anagram.length(); i++){
    for(unsigned j=0; j < word.length(); j++){
      if(anagram[i] != word[j]) continue;
      repeateadLetters[word[j]]++;
      
      if(repeateadLetters[word[j]] == 1)
        weight++;
    }
  }
  
  if(weight > bestWeight){
    solution = word;
    bestWeight = weight;
  }
  
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

