#include <iostream>
#include <vector>
using str = std::string;
using std::vector;
auto &prt = std::cout;
auto &read = std::cin;

vector<vector<str> > video;
vector<str> tmpFretBoard;
vector<str> fretBoard = {
		"                                                      _----------",
		"                     123456789ABC123456789ABC     _.-~        /  ",
		"               .---.                          _.-~           /_  ",
		"            o_/| 7 | ------------------------ ||              /  ",
		"          o_/  | 6 | ------------------------ ||             /   ",
		"        o_/    | 5 | -----------o-----------o ||             \\  ",
		"      o_/      | 4 | --o-o-o-o-----o-o-o-o--- || tabbath v0.1 >  ",
		"    o_/        | 3 | -----------o-----------o ||             /   ",
		"  o_/          | 2 | ------------------------ ||             \\  ",
		"o_/____________| 1 | ------------------------ ||            __\\ ",
		"               '---'                          `-_           \\   ",     
		"                                                 `-_         \\  ",     
		"                                                    `-________\\_"};

void clearScreen()
{
	for(unsigned int i=0; i != 150; ++i)
	{
		prt << "\x0a";
	}
}

void printFretBoard(auto vec)
{
		for (auto c : vec) { prt << c <<"\n";}
}

void playVideo(auto vec)
{
		for (unsigned i=0; i < vec.size(); ++i)
		{
				
				clearScreen();
				for (unsigned j=0; j<13; ++j)
				{
						prt << vec[i][j] << char(10);			
				}
				system("sleep 0.25");
				//system("clear");
		}
}


int main(void)
{
		clearScreen();
		unsigned stringIndex, fretIndex;
		printFretBoard(fretBoard);
		while(prt << "Ctrl+d to finish" << char(10) &&
		      prt << "s|f\n" &&
			  read >> stringIndex && 
			  read >> fretIndex)
		{
				// navigating to fretboard in artwork
				stringIndex += 3; // 7th string starts from 3rd line
				fretIndex += 21; // first fret starts from 21th collumn

				if(stringIndex <= 10 && fretIndex <= 45)
				{
						//system("clear");
						clearScreen();
						fretBoard[stringIndex-1][fretIndex-1] = 'x';
						printFretBoard(fretBoard);
						video.push_back(fretBoard);
						fretBoard[stringIndex-1][fretIndex-1] = '~';
				}
				else
				{
						prt << "\nthis fret does not exist!\n"
						    << "string: " << stringIndex - 3 << "\n"
							<< "fret: " << fretIndex - 21 << "\n";
				}
		}

		playVideo(video);
			
		return 0;
}

