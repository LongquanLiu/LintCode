// Time:  O(n)
// Space: O(1)

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    /*
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        if (!str.empty()){
            offset %= str.length();
            reverse(str.begin(), str.begin() + str.length() - offset);
            reverse(str.begin() + str.length() - offset, str.end());
            reverse(str.begin(), str.end());
        }
    }
};
