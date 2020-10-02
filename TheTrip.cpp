/// Programming Challenges
/// Author: Carlos L. Cuenca
/// Date: 10/2/2020

#include<iostream>
#include<cmath>
#include<vector>

/// -----------------
/// Program Constants

const int   MAX_STUDENTS = 1000     ;
const float MAX_PRICE    = 10000.0f ;

/// --------------
/// Driver Program

int main(int argc, char* argv[]) {

	int   studentCount = 0    ;
	float sum 		   = 0.0f ;
	float average      = 0.0f ;
	int   divisor 	   = 0    ;

	do {

		std::vector<float> exchanges;

		std::cin >> studentCount;

		divisor = studentCount;

		while(studentCount--) {

			double spent;

			std::cin >> spent;

			exchanges.push_back(spent);

			sum += spent;

		}

		if(divisor) {

			average = sum / divisor;

			average = ((int) (average * 100))/100.0f;

			double exchange = 0.0;

			for(long unsigned int index = 0; index < exchanges.size(); index++) {

				if(exchanges[index] < average) {

					exchange += average - exchanges[index];

				}

			}

			std::cout << exchange << std::endl;

		}

	} while (divisor);

	return 0;

}
