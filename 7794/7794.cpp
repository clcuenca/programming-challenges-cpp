/// ACM ICPC Live Archive
/// 7794 The Great Thief
/// Author: Carlos L. Cuenca
/// Date: 10/05/20

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

/// -----------------
/// Program Constants

const int SUCCESS = 0;

/// --------------
/// Driver Program

int main(int argc, char* argv[]) {

	/// -----------------
	/// Program Variables
 
	uint64_t              maximum    ;
	uint64_t              sum        ;
	uint64_t  			  bitMaximum ;

	/// -------
	/// Program

	while(!std::cin.eof()) {

		std::cin >> maximum;

		sum = 0;

		for(uint64_t current = 2; current <= maximum; current++) {

			uint64_t buffer = current;

			std::vector<uint64_t> factors;

			// We should only include one 2 if the number is greater than 2
			// Since 2 is prime
			if(!(buffer % 2) && buffer > 2) factors.push_back(2);

			while(!(buffer % 2)) buffer >>= 1;

			for(uint64_t factor = 3; std::pow(2, buffer - 1) % buffer != 1; factor += 2) {

				// If there's a factor, add it to the list and reduce the number
				if(!(buffer % factor) && buffer ^ factor) factors.push_back(factor);

				// Whittle the number down
				while(!(buffer % factor)) buffer /= factor;

			} 

			// After Mangling the number, we make a final check to see if the prime number
			// is greater than 2 and not itself
			if(buffer > 2 && current ^ buffer) factors.push_back(buffer);

			uint64_t omission = 0;

			// This means the number is prime
			if(!factors.size()) {

				omission = (maximum / current);

			} else {

				// Get the number of bits
				bitMaximum = (1 << factors.size()) - 1;

				for(uint64_t index = 1; index <= bitMaximum; index++) {

					uint64_t number  = index;
					uint64_t jindex  = 0;
					uint64_t factor  = 1;
					uint64_t rolling = 0;

					while(number > 0) {

						if(number & 1) { 

							factor *= factors[jindex];
							rolling++;

						}

						jindex++;

						number >>= 1;

					}

					if(factor > 1) {
					
						if(rolling % 2) omission += (maximum / factor);
						else 		    omission -= (maximum / factor);
						
					}

				}

			}

			sum += (maximum - omission);

		}

		std::cout << maximum + sum + 3 << std::endl;

	}

	return SUCCESS;

}