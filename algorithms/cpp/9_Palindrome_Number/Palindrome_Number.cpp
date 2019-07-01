#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Solution {
public:
  bool isPalindrome(int x) {
    string s = to_string(x);
    int left, right;
    int halfSize=s.size()/2;
    right = halfSize;
    if(s.size()%2 == 0){
      left = right - 1;
      halfSize--; 
    }else{
      left = right;
    }
    bool isPalindrome{true};
    for(int i=0; i<=halfSize && isPalindrome; i++){
      if(s[left-i] != s[right+i]){isPalindrome=false;}
            
    }
    return isPalindrome;
  }
};

int main(){

  Solution palindrome;
  cout << palindrome.isPalindrome(-23454321) << endl;

}
