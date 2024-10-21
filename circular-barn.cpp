#include <iostream>
#include <bits/stdc++.h>

int main() {

	int rooms;
	std::cin >> rooms;

	int cownums[rooms];
	int distance[rooms];
	int dist;

	for (int i = 0; i < rooms; ++i) {

		std::cin >> cownums[i];

	}

	for (int i = 0; i < rooms; ++i) {
		
		dist = 0;

		for (int j = 0; j < rooms; ++j) {

			int nextroom = i + j;
			if (nextroom >= rooms) {

				nextroom -= rooms;

			}
			
			dist += cownums[nextroom] * j;

		}

		distance[i] = dist;

	}

	std::sort(distance, distance + rooms);

	std::cout << distance[0] << "\n";

}
