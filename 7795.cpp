/// ACM ICPC Live Archive
/// 7795 What's a cubit?
/// Author: Carlos L. Cuenca
/// Date: 10/05/20

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>

/// -----------------
/// Program Constants

const int   SUCCESS             = 0       ;
const int   CUBIT_INDEX         = 0       ;
const int   PALM_INDEX          = 1       ;
const int   DIGIT_INDEX         = 2       ;
const float DIGIT_TO_PALM       = 4.0f    ;
const float PALM_TO_CUBITS      = 7.0f    ;
const float MM_TO_CUBIT  		= 526.35f ;
const float MM_TO_METER 		= 1000.0f ;
const float MM_TO_INCH			= 25.4f   ;
const float INCHES_TO_FOOT 		= 12.0f   ;
const float ROUND 				= 0.5f    ;

/// --------------
/// Driver Program

int main(int argc, char* argv[]) {

	/// -----------------
	/// Program Variables

	std::string inputLine    ;
	std::string numberBuffer ;
	std::string unitBuffer   ;
	uint32_t    number       ;

	/// -------
	/// Program

	while(!std::cin.eof()) {

		std::getline(std::cin, inputLine);

		uint32_t index = 0;
		std::vector<uint32_t> units(3, 0);

		while(index < inputLine.size()) {

			numberBuffer = "";
			unitBuffer = "";

			while(inputLine[index] != ' ') {

				numberBuffer += inputLine[index];

				index++;

			}

			index++;

			while((inputLine[index] != ' ') && (index < inputLine.size())) {

				unitBuffer += inputLine[index];

				index++;

			}

			index++;

			number = std::stoi(numberBuffer);

			if     (unitBuffer[0] == 'c') units[CUBIT_INDEX] = number;
			else if(unitBuffer[0] == 'p') units[PALM_INDEX]  = number;
			else if(unitBuffer[0] == 'd') units[DIGIT_INDEX] = number;

		}

		float palms  = (float) units[PALM_INDEX] + ((float) units[DIGIT_INDEX] / DIGIT_TO_PALM);
		float cubits = (float) units[CUBIT_INDEX] + (palms / PALM_TO_CUBITS);
		float mm     = cubits * MM_TO_CUBIT;
		float meters = mm / MM_TO_METER;
		float inches = mm / MM_TO_INCH;
		float feet   = inches / INCHES_TO_FOOT;

		std::cout << std::fixed << std::setprecision(3) << meters << "m ";

		if(feet < 1.0) { 

			std::cout << std::fixed << std::setprecision(2) << inches << "\"" << std::endl;

		} else {

			int feet = inches / INCHES_TO_FOOT;

			inches -= feet * INCHES_TO_FOOT;

			std::cout << feet << "\' " << std::fixed << std::setprecision(2) << inches << "\"" << std::endl;

		}

	}

	return SUCCESS;

}