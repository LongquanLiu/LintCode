// Time:  O(logn) = O(32)
// Space: O(1)

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        while (b != 0) {
            int carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return a;
    }
};

class Solution2 {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        if (b == 0) {
            return a;
        }
        return aplusb(a ^ b, (a & b) << 1);
    }
};
//  step1: 不进位相加，即忽略掉进位相加 0+0=0,0+1=1,1+0=1，1+1=0 正是位运算 ^ 异或操作
//  step2: 进位，知道哪位进位(需要进位的数进位) &操作即可，例如1&1=1，而进位则是10=（1&1）<<1,把与操作的结果向左移动了一位
//  step3: 不进位相加+进位结果  1.若进位结果为0，则求和结果就是不进位相加结果；若进位结果不为0，则循环
//                           2.递归 直至进位结果为0停止
//  ps:solution1 减少空间消耗
// Created by llq on 17-12-21.
//
