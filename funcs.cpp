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
    cout<<level;
    for(int i = 0; i < level; i++){
      //if(closes==1)  closes is 1 when the last brace
      //{
          //break;//this fixes the last brace
      //}
      //else if (line[0]=='}') //if the first character is }
      //{
        //for(int j = 0; j < 4; j++){ indentation should be reduced
        //by one
            //cout << ' ';
          //}//having issues fixing the semi last brace because
          //there is no different between that line and the one before it
          //in terms of closes,opens, and level 
      //}
      else
      {
        for(int j = 0; j < 5; j++){
            cout << ' ';
        }
      }

    }
  }
  inputStream.close();
}
