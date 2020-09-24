/// ---------------------------------------------
/// ICPC 4367 - Think I'll Buy Me a Football Team
/// author - Carlos L. Cuenca
/// Date - 09/24/2020

#include <iostream>
#include <vector>

/// -----------------
/// Program Constants

const int EXIT_SUCCESS = 0;

/// --------------
/// Driver Program

int main(int argc, char* argv[]) {

	/// -----------------
	/// Program Variables

	int maximum = 0;
	int buffer  = 0;

	std::cin >> maximum;

	std::vector<std::vector<int>> matrix(maximum);

	for(uint32_t index = 0; index < maximum; index++) {

		for(uint32_t jindex = 0; jindex < maxmimum; jindex++) {

			std::cin >> buffer;

			matrix[index].push_back(buffer);

		}


	}



	return EXIT_SUCCESS;

}

