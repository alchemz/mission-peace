// Efficient C++ program to print Farey Sequence of order n
#include <bits/stdc++.h>
using namespace std;

// Optimized function to print Farey sequence of order n
void farey(int n)
{
	// We know first two terms are 0/1 and 1/n
	double x1 = 0, y1 = 1, x2 = 1, y2 = n;

	printf("%.0f/%.0f %.0f/%.0f", x1, y1, x2, y2);

	double x, y = 0; // For next terms to be evaluated
	while (y != 1.0) {
		// Using recurrence relation to find the next term
		x = floor((y1 + n) / y2) * x2 - x1;
		y = floor((y1 + n) / y2) * y2 - y1;

		// Print next term
		printf(" %.0f/%.0f", x, y);

		// Update x1, y1, x2 and y2 for next iteration
		x1 = x2, x2 = x, y1 = y2, y2 = y;
	}
}

// Driver program
int main()
{
	int n = 7;
	cout << "Farey Sequence of order " << n << " is\n";
	farey(n);
	return 0;
}
