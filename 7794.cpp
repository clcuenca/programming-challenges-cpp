/// ---------------------------
/// ICPC 7794 - The Great Thief
/// author - Carlos L. Cuenca
/// Date - 09/24/2020

#include <iostream>
#include <vector>
#include <cmath>

/// -------------
/// Program Types

typedef uint64_t 			Index  	   ;
typedef uint64_t 			Factor 	   ;
typedef uint64_t			Count  	   ;
typedef std::vector<Factor> FactorList ;

/// -------------------
/// Function Prototypes

void setEvenFactors(FactorList&, Factor&);
void setOddFactors(FactorList&, Factor&);
void setPrimeFactors(FactorList&, Factor);
Count getOmissionCount(FactorList&, Factor, Factor);

/// --------------
/// Driver Program

int main(int argc, char* argv[]) {

	/// -----------------
	/// Program Variables

	Factor     maximum    ;
	FactorList factorList ;
	Factor     sum 		  ;

	/// ---------
	/// Main Loop

	while(!std::cin.eof()) {

		std::cin >> maximum;

		sum = 0;		

		for(Factor current = 1; current <= maximum; current++) {

			setPrimeFactors(factorList, current);

			sum += (maximum - getOmissionCount(factorList, current, maximum));

		}

		std::cout << "Max: " << maximum << " Houses: " << maximum + 3 + sum << std::endl;


	}


	return EXIT_SUCCESS;

}

/// ------------------------
/// Function Implementations

/// -------------------------------------------
/// @procedure: setEvenFactors
/// @author: Carlos L Cuenca
/// @parameter: List, Number
/// @description: Sets the even factors of the
/// number onto the given list

void setEvenFactors(FactorList& factorList, Factor& number) {

	if(!number || number == 2) return;

	if(!(number % 2)) factorList.push_back(2);

	// We want to make sure the number is no longer divisible by two
	while(!(number % 2)) number >>= 1;

}

/// -------------------------------------------------
/// @procedure: setOddFactors
/// @author: Carlos L Cuenca
/// @parameter: List, Number
/// @description: Sets the odd factors of the number
/// onto the given list, if any

void setOddFactors(FactorList& factorList, Factor& number) {

	// Skip an element since number is odd
	for(Factor factor = 3; factor <= std::sqrt(number); factor += 2) {

		// If there's a factor, add it to the list and reduce the number
		if(!(number % factor) && number ^ factor) factorList.push_back(factor);

		// Whittle the number down
		while(!(number % factor)) number /= factor;

	}

}

/// ------------------------------------------------------
/// @procedure: SetFactors
/// @author: Carlos L Cuenca
/// @parameter: List, Factor
/// @description: Sets all the prime factors of the given
/// number into the vector.

void setPrimeFactors(FactorList& factorList, Factor number) {

	// Saving for a last-check
	Factor buffer = number;

	// Clear the list
	factorList.clear();

	// Get the 2's, if any
	setEvenFactors(factorList, number);

	// Get the odd Factors, if any
	setOddFactors(factorList, number);

	// After Mangling the number, we make a final check to see if the prime number
	// is greater than 2, not in the vector and not itself
	if(number > 2 && number ^ buffer) factorList.push_back(number);

}

Count getOmissionCount(FactorList& factorList, Factor number, Factor maximum) {

   // This means the number is prime
    if(!factorList.size()) return maximum/number;

    Count  result       = 0;
    Index  alternating  = 0;
    Index  index        = 0;
    Factor factor       = 0;

    for(Index rolling_maximum = 0; rolling_maximum < factorList.size() ;){

        factor = 1;

        for(Index rolling = 0; rolling < rolling_maximum; rolling++) { 

        	factor *= factorList[index + rolling];

        	//std::cout << factorList[index + rolling] << "*";

        }

        if(alternating < factorList.size()) { 


        	//std::cout << factorList[alternating] << std::endl;

        	factor *= factorList[alternating++];

        }

        if(rolling_maximum % 2) result -= ((maximum/factor));
        else                    result += ((maximum/factor));

        if(alternating == factorList.size()){

            if(rolling_maximum && (index + rolling_maximum < factorList.size() - 1)){

                index++;

                alternating = index + rolling_maximum;

            }else{

                rolling_maximum++;

                alternating = rolling_maximum;

                index = 0;

            }

        }

    }

    return result;

}