// Time:  O(n)
// Space: O(1)

#include <vector>
using namespace std;
class Solution {
public:
    /*
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            if (nums[left] < k){
                left++;
            }else if (nums[right] >=k){
                right--;
            }else{
                swap(nums[left++], nums[right--]);
            }
        }
        return left;
    }
};
