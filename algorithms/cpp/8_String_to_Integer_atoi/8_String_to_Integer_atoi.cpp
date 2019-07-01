#include <iostream>
#include <string>
#include <climits>
using std::cout;
using std::endl;
using std::string;


class Solution {
public:
  int myAtoi(string str) {
    int num{0}, sign{1};
    int element;
    for(int i = 0; i<str.size();){
      element = str.at(i);
      if(element==32){
	i++;
      }else if(element==45){
	sign = -1;
	i++;
      }else if(47<element && element<58){
	if(num > INT_MAX/10){
	  return 0;
	}else{
	  num = num*10 + element - 48;
	  i++;
	}
      }else{
	break;
      }
    }
    return num*sign;
  }
};


int main(){

  string s{"4193 with words"};
  Solution atoi;
  cout << atoi.myAtoi(s) << endl;;

}
