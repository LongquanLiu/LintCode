// Time:  O(n)
// Space: O(1)

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    /*
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        // write your code here
        vector<string> str;
        for (int i = 1; i <= n; i++){
            if (i % 3 == 0 && i % 5 == 0){
                str.emplace_back("fizz buzz");
            }else if (i % 3 == 0){
                str.emplace_back("fizz");
            }else if (i % 5 == 0){
                str.emplace_back("buzz");
            }else{
                str.emplace_back(to_string(i));
            }
        }
        return str;
    }
};

/* C11
 * emplace_back能就地通过参数构造对象，不需要拷贝或者移动内存，
 * 相比push_back能更好地避免内存的拷贝与移动，使容器插入元素的性能得到进一步提升。
 * 在大多数情况下应该优先使用emplace_back来代替push_back。
 * */
