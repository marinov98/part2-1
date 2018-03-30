#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;

string removeLeadingSpaces(string);
void unindent(string);
void indent(string);
int countChar(string, char);

string removeLeadingSpaces(string line){
  string rstring = "";
  bool skipped = false;
  for(int i = 0; i < line.length(); i++){
    if(!isspace(line[i])){
      skipped = true;
    }
    if(skipped == true){
      rstring += line[i];
    }
  }
  return rstring;
}

void unindent(string filename){
  ifstream inputStream(filename);
  string line;
  while(getline(inputStream, line)){
    cout << removeLeadingSpaces(line) << endl;
  }
  inputStream.close();
}

int countChar(string line, char c){
  int count = 0;
  for(int i = 0; i < line.length(); i++){
    if(line[i] == c){
      count += 1;
    }
  }
  return count;
}

void indent(string filename){
  ifstream inputStream(filename);
  string line;
  int opens = 0;
  int closes = 0;
  while(getline(inputStream, line)){
    cout << removeLeadingSpaces(line) << endl;
    opens += countChar(line, '{');
    closes += countChar(line, '}');
    int level = opens - closes;
    for(int i = 0; i < level; i++){
      for(int j = 0; j < 5; j++){
        cout << ' ';
      }
    }
  }
  inputStream.close();
}
