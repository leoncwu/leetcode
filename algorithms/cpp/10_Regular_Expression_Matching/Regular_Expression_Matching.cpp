#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Solution {
public:
  bool isMatch(string s, string p) {
    if(p.empty()){
      return s.empty();
    }
    else if(p.size() == 1){
      return (s.size() == 1 && (s.at(0) == p.at(0) || p.at(0) == '.'));
    }
    else if(p.at(1) != '*'){
      if(s.empty()) {return false;}
      else{
	return ((s.at(0) == p.at(0) || p.at(0) == '.') && isMatch(s.substr(1), p.substr(1)));
      }
    }
    else{
      return(isMatch(s,p.substr(2)) || ((!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.')) && isMatch(s.substr(1),p)));
    }
  }
};


int main(){
  string s, p;
  cin >> s;
  cin >> p;
  Solution expressions;
  cout << expressions.isMatch(s,p) << endl;


}
