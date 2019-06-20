#include <vector>
using std :: vector;

class Solution{
public:
  vector<int> twoSum(vector<int> &num, int target ){
    vector<int> location;
    bool notfound=true;
    for(int i = 0; i < num.size() && notfound; i++){
      for(int j = i+1; j < num.size(); j++){
        if(num.at(i)+num.at(j) == target){
          location.push_back(i);
          location.push_back(j);
          notfound = false;
          break;
        }
      }
    }
    return location;
  }
};
