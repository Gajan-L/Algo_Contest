#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/*  focus on the mid
*   find the candidate of left part
*   for i-th element in nums1, find its index in nums2, order_of_key(index in nums2) gives how many nums that are before cur-element in both array
*   then insert it into the ordered_set
*   similar way to find the right part
*/
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long res = 0;
        vector<int> ind2(n);
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            ind2[nums2[i]] = i;
        }
        ordered_set s;
        for (int i = 0; i < n; i++) {
            int pos = ind2[nums1[i]];
            x[i] = s.order_of_key(pos);
            s.insert(pos);
        }
        ordered_set s2;
        for (int i = n - 1; i > 0; i--) {
            int pos = ind2[nums1[i]];
            int z = (n - i - 1) - s2.order_of_key(pos);
            res += (long long)z *(long long)x[i];
            s2.insert(pos);
        }
        return res;
    }
};
