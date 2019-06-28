class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int target1 = (nums1.size() + nums2.size() +1)/2;
    int target2 = (nums1.size() + nums2.size() +2)/2;
    return (findValueAt(target1, nums1, 0, nums2, 0) + findValueAt(target2, nums1, 0, nums2, 0))/2.;
  }
  int findValueAt(int k, vector<int> nums1, int i, vector<int> nums2, int j){
    if(i >= nums1.size()){
      return nums2[j+k-1];
    }
    if(j >= nums2.size()){
      return nums1[i+k-1];
    }
    if(k == 1){
      return min(nums1[i],nums2[j]);
    }
    int value1 = (i+k/2-1 < nums1.size()) ? nums1[i+k/2-1] : INT_MAX;
    int value2 = (j+k/2-1 < nums2.size()) ? nums2[j+k/2-1] : INT_MAX;
    if(value1 > value2){
      return findValueAt(k-k/2, nums1, i, nums2, j+k/2);
    }else{
      return findValueAt(k-k/2, nums1, i+k/2, nums2, j);
    }
  }
};
