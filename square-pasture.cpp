#include <iostream>
#include <bits/stdc++.h>

int main() {

	int xvals[4];
	int yvals[4];

	int xdist;
	int ydist;
	
	for (int i = 0; i < 4; ++i) {
	
		std::cin >> xvals[i] >> yvals[i];

	}

	xdist = std::max(xvals[1], xvals[3]) - std::min(xvals[0], xvals[2]);
	ydist = std::max(yvals[1], yvals[3]) - std::min(yvals[0], yvals[2]);

	if (ydist > xdist) {

		int rval = ydist * ydist;
		std::cout << rval << "\n";

	} else {

		int rval = xdist * xdist;
		std::cout << rval << "\n";

	}

	return 0;

}
