#include <iostream>
#include <bits/stdc++.h>

int main() {

	int N;
	std::cin >> N;

	int starttimes[N];
	int endtimes[N];
	int buckets[N];

	int bucketsneeded = 0;
	int bucketsavailable = 0;
	int bucketsused = 0;

	for (int i = 0; i < N; ++i) {

		std::cin >> starttimes[i] >> endtimes[i] >> buckets[i];

	}

	for (int i = 1; i <= *(std::max_element(endtimes, endtimes + N)); ++i) {
	    
		for (int j = 0; j < N; ++j) {

			if (i == starttimes[j]) {

				bucketsneeded += buckets[j];
				if (bucketsneeded > bucketsavailable) {

					bucketsused += bucketsneeded - bucketsavailable;
					bucketsneeded = 0;
					bucketsavailable = 0;

				}
				else {

					bucketsavailable = bucketsavailable - bucketsneeded;
					bucketsneeded = 0;

				}

			}
			if (i == endtimes[j]) {

				bucketsavailable += buckets[j];

			}

		}

	}

	std::cout << bucketsused << "\n";

}
