// C++ code to implement the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum value among all distinct
// ordered tuple
long maxValue(int a[], int n)
{
    sort(a, a + n);
    int min = a[0];
    int max = a[n - 1];
    int secmax = a[n - 2];
    long ans = (long)(a[n - 1] - a[0]) * a[n - 2];
    return ans;
}

// Driver Code
int main()
{
    int A[] = {12, 6, 1, 2, 7};
    int N = sizeof(A) / sizeof(A[0]);

    // Function call
    cout << maxValue(A, N);
    return 0;
}

// This code is contributed by aarohirai2616.
