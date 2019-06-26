class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> search;
    int max_length{0};
    int prv_loc{-1};
    for(int i=0; i<s.size(); i++){
      if(search.count(s.at(i)) && prv_loc < search.at(s.at(i))){
	prv_loc = search.at(s.at(i));
      }
      max_length=max(max_length,(i-prv_loc));
      search[(s.at(i))] = i;
    }
    return max_length;
  }
};
