#include <iostream>
#include <sstream>
#include <fstream>

int main () 
{
	std::string number_string;

	std::ifstream inputFile("example.txt");

	// New instance of Stringstream with identifier 'ss'
	std::stringstream ss;

	if (inputFile.is_open())
	{
		// We need to make sure the Stringstream is "cleared" out.
		ss.clear();
		ss.str("");

		std::string line;
	
		while (std::getline(inputFile,line))
		{
			// We can provide the stringstream with the line.
			ss.str(line);
			
			// Now we want to use the stringstream to parse based upon the delimiter.
			std::getline(ss, number_string, ',');

			std::cout << number_string << std::endl;
		}
    
		inputFile.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	} 
	
	return 0;
}

