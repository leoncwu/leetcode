#include <string>
#include <iostream>
using std:: string;
using std:: cout;
using std:: endl;

class Solution {
public:
  string convert(string s, int numRows) {
    int space = 2*(numRows-1);
    string result;
    for(int i=0; i < numRows; i++){
      for(int j=i; j < s.size(); j+=space){
       	result.append(1,s.at(j));
	if(i != 0 && i != (numRows-1) && j+space-2*i < s.size()){
	  result.append(1,s.at(j+space-2*i));
	}
      }
    }
    cout << result << endl;
    return result;
  }
};


int main(){
  string s = "PAYPALISHIRING";
  string tmp;
  // tmp.append(1,s.at(0));
  // tmp.append(1,s.at(1));
  // cout << tmp << endl;
  Solution astring;
  astring.convert(s,4);
}
