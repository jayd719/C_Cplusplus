#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the minimum number of towers required
int MinNumberOfTowers(int P[], int R, int n)
{
    // Step 1: Sort the house positions
    sort(P,P+n);

    int towers = 0; // Count of towers
    int i = 0;      // Iterator for house positions

    // Step 2: Process all houses
    while (i < n)
    {
        towers++; // Place a new tower

        // Find the furthest point to the east the tower can cover
        int location = P[i] + R;

        // Skip houses within the west-side coverage
        while (i < n && P[i] <= location)
        {
            i++;
        }

        // Step back to find the optimal location for the tower
        i--; // Position of the tower
        location = P[i] + R;

        // Skip houses within the east-side coverage
        while (i < n && P[i] <= location)
        {
            i++;
        }
    }

    return towers; // Return the total number of towers
}

int main()
{
    // Test Case 1: Basic example
    int houses1[] = {2, 5, 8, 12};
    int radius1 = 3;
    cout << "Test Case 1: " << MinNumberOfTowers(houses1, radius1,sizeof(houses1)/sizeof(houses1[0])) << " (Expected: 2)" << endl;

    // Test Case 2: All houses within the coverage of one tower
    int houses2[] = {1, 2, 3, 4, 5};
    int radius2 = 5;
    cout << "Test Case 2: " << MinNumberOfTowers(houses2, radius2,sizeof(houses2)/sizeof(houses2[0])) << " (Expected: 1)" << endl;

    // Test Case 3: No overlap between houses
    int houses3[] = {1, 10, 20, 30};
    int radius3 = 4;
    cout << "Test Case 3: " << MinNumberOfTowers(houses3, radius3,sizeof(houses3)/sizeof(houses3[0])) << " (Expected: 4)" << endl;

    // Test Case 4: Sparse and clustered houses
    int houses4[] = {1, 2, 4, 8, 10, 15, 20};
    int radius4 = 3;
    cout << "Test Case 4: " << MinNumberOfTowers(houses4, radius4,sizeof(houses4)/sizeof(houses4[0])) << " (Expected: 4)" << endl;

    // Test Case 5: No houses
    int houses5[] = {};
    int radius5 = 2;
    cout << "Test Case 5: " << MinNumberOfTowers(houses5, radius5,sizeof(houses5)/sizeof(houses5[0])) << " (Expected: 0)" << endl;

    // Test Case 6: Single house
    int houses6[] = {5};
    int radius6 = 1;
    cout << "Test Case 6: " << MinNumberOfTowers(houses6, radius6,sizeof(houses6)/sizeof(houses6[0])) << " (Expected: 1)" << endl;

    return 0;
}
