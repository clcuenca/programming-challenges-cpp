/// ---------------------------------------------
/// ICPC 4367 - Think I'll Buy Me a Football Team
/// author - Carlos L. Cuenca
/// Date - 09/24/2020

#include <iostream>
#include <vector>

/// -----------------
/// Program Constants

const int SUCCESS = 0;

/// --------------
/// Driver Program

int main(int argc, char* argv[]) {

	/// -----------------
	/// Program Variables

	uint32_t inputCount = 0;
	uint32_t maximum    ;
	int      buffer     ;
	uint32_t firstSum   ;
	uint32_t minimum    ;

	while(true) {

		std::cin >> maximum;

		// Exit Condition
		if(!maximum) break;

		buffer     = 0;
		firstSum   = 0;
		minimum    = 0;

		inputCount++;

		// We only need to keep track of the owe/owed
		std::vector<int>owe(maximum);
		std::vector<int>owed(maximum);

		// Read in the matrix
		for(uint32_t index = 0; index < maximum; index++)
		for(uint32_t jindex = 0; jindex < maximum; jindex++) {

			std::cin >> buffer;

			// Sum to the appropriate values
			firstSum     += buffer;
			owe[index]   += buffer;
			owed[jindex] += buffer;

			// If we're at the last line
			if(index == (maximum - 1)) {

				int difference = (owed[jindex] - owe[jindex]);

				if(difference > 0) minimum += difference;

				// Clear them out for later use
				owe[jindex]  = 0;
				owed[jindex] = 0;

			}

		}

		/// ------
		/// Print

		std::cout << inputCount << ". " << firstSum << " " << minimum << std::endl;

	}

	/// ------
	/// Finish

	return SUCCESS;

}
