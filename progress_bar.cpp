#include "progress_bar.h"

#include <iostream>
#include <sstream>

void progressBar(int current_value, int max_value, char fill_char)
{
	std::stringstream s;
	s << "||";

	const int bar_length = 50;
	int grid = max_value / bar_length;
	bool update = false;

	for(int i = 1; i <= bar_length; i++)
	{
		if(current_value >= i * grid) { s << fill_char; update = true; }
		else { s << " "; }
	}
	s << "||\r";

	if(update) { std::cout << s.str(); update = false; }

}

