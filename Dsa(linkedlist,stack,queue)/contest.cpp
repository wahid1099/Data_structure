#include <iostream>
#include <vector>

using namespace std;

long long maximumTripletValue(vector<int> &nums)
{
    int n = nums.size();

    if (n < 3)
    {
        return 0; // Not enough elements to form a triplet.
    }

    long long max1 = -9223372036854775807LL;    // Minimum value for a 64-bit signed integer
    long long max2 = -9223372036854775807LL;    // Minimum value for a 64-bit signed integer
    long long max_val = -9223372036854775807LL; // Minimum value for a 64-bit signed integer

    for (int i = 0; i < n; ++i)
    {
        long long current = nums[i];
        if (current >= max1)
        {
            max2 = max1;
            max1 = current;
        }
        else if (current >= max2)
        {
            max2 = current;
        }

        // Check if we have encountered at least two distinct maximum values
        if (max1 != -9223372036854775807LL && max2 != -9223372036854775807LL)
        {
            max_val = max(max_val, (max1 - max2) * current);
        }
    }

    return max_val <= 0 ? 0 : max_val;
}

int main()
{
    vector<int> nums1 = {12, 6, 1, 2, 7};
    cout << maximumTripletValue(nums1) << endl; // Output: 77

    vector<int> nums2 = {1, 10, 3, 4, 19};
    cout << maximumTripletValue(nums2) << endl; // Output: 133

    vector<int> nums3 = {1, 2, 3};
    cout << maximumTripletValue(nums3) << endl; // Output: 0

    return 0;
}
