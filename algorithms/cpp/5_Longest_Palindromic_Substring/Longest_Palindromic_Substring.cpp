class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        int maxLength{0};
        int startLoc{0};
        for(int i=0; i < s.size()-1; i++){
            findPalindromicSubstring(s, i, i, i, startLoc, maxLength);
        }
        return s.substr(startLoc, maxLength);
    }
    void findPalindromicSubstring(string s, int leftLoc, int centLoc, int rightLoc, int& startLoc, int& maxLength){
        while(rightLoc < s.size() && s[centLoc] == s[rightLoc]){
            rightLoc++;
        }
        leftLoc--;
        while(leftLoc>=0 && rightLoc < s.size() && s[leftLoc] == s[rightLoc]){
            leftLoc--;
            rightLoc++;
        }
        int lengthCount = rightLoc - leftLoc - 1;
        if(lengthCount > maxLength){
            startLoc = leftLoc + 1;
            maxLength = lengthCount;
        }
    }
};