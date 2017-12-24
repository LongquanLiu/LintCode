// Time:  O(n)
// Space: O(1)

#include <vector>
using namespace std;
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Interval {
     public:
         int start, end;
        Interval(int start, int end) {
                 this->start = start;
                 this->end = end;
        }
};

class Solution {
public:
    /*
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        size_t i = 0;
        vector<Interval> result;
            // Insert intervals appeared before newInterval.
        while(i < intervals.size() && intervals[i].end < newInterval.start){
            result.emplace_back(intervals[i]);
            i++;
        }
        // Merge intervals that overlap with newInterval.
        while(i < intervals.size() && intervals[i].start <= newInterval.end){
            newInterval = {min(intervals[i].start, newInterval.start),
                           max(intervals[i].end, newInterval.end)};
            i++;
        }
        result.emplace_back(newInterval);
        // Insert intervals appearing after newInterval. 581ms
        while(i < intervals.size() && intervals[i].start > newInterval.end){
            result.emplace_back(intervals[i]);
            i++;
        }
        // 689ms result.insert(result.end(), intervals.cbegin()+i, intervals.cend());
        return result;
    }
};
