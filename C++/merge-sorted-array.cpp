// Time:  O(m + n)
// Space: O(1)

#include <vector>
using namespace std;
class Solution1 {
public:
    /*
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> vec;
        int index1 = 0, index2 = 0, len1 = A.size(), len2 = B.size();
        while(index1 < len1 && index2 < len2) {
            if(A[index1] < B[index2]){
                vec.push_back(A[index1]);
                index1++;
            }else{
                vec.push_back(B[index2]);
                index2++;
            }
        }
        while(index1 < len1){
            vec.push_back(A[index1]);
            index1++;
        }
        while(index2 < len2){
            vec.push_back(B[index2]);
            index2++;
        }
        return vec;
    }
};

class Solution2 {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int i = m + n;
        while (m > 0 && n > 0) {
            if (A[m - 1] > B[n - 1]) {
                A[i - 1] = A[m - 1];
                --m;
            } else {
                A[i - 1] = B[n - 1];
                --n;
            }
            --i;
        }

        while (n > 0) {
            A[i - 1] = B[n - 1];
            --n;
            --i;
        }
    }
};

