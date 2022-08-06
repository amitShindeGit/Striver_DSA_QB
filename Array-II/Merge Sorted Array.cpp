class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pointer1 =  m-1;
        int pointer2 = nums1.size()-1;
        int pointer3 = n-1;
        
        while(pointer3 >= 0){
                if(pointer1 < 0){
                    while(pointer3 >= 0){
                      nums1[pointer2] = nums2[pointer3];
                        pointer3--;
                        pointer2--;  
                    }
                    break;
                }
            
                if(nums1[pointer1] > nums2[pointer3]){
                    nums1[pointer2] = nums1[pointer1];
                    pointer1--;
                    
                }else{
                    nums1[pointer2] = nums2[pointer3];
                    pointer3--;
                }
            pointer2--;
        }
      
    }
};