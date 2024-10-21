#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

int main() {

	int vals[7];

	int a;
	int b;
	int c;
	
	for (int i = 0; i < 7; ++i) {

		std::cin >> vals[i];

	}

	std::sort(vals, vals + 7);
	
	a = vals[0];
	b = vals[1];
	c = vals[6] - a - b;
	
	std::cout << a << " " << b << " " << c << "\n";

	return 0;

}
