#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include "MusicDB.h"


using namespace std;

//write function to convert genre entry from text to "Genre":
Genre convertStringToGenre (std::string genre)
{
	Genre return_value;

	std::transform(genre.begin(), genre.end(), genre.begin(),
		[](unsigned char c) { return std::tolower(c); });

	//convert here
	if (genre == "Blues")
	{
		return_value = Blues;
	}
	else if (genre == "Rock") {
		return_value = Rock;
	}
	else if (genre == "Metal") {
		return_value = Metal;
	}
	else if (genre == "Hiphop") {
		return_value = Hiphop;
	}
	else if (genre == "Jazz") {
		return_value = Jazz;
	}
	else if (genre == "Contemporary") {
		return_value = Contemporary;
	}
	else if (genre == "Instrumental") {
		return_value = Instrumental;
	}
	else
	{
		std::cout << "Genre is unidentified.";
	}
	return return_value;
}

std::string convertGenreToString(Genre genre)
{
	std::string return_value;
						//switch statement only works on intergers
	switch (genre) {
	case Blues:
		return_value = "Blues";
		break;
	case Rock:
		return_value = "Rock";
		break;
	case Metal:
		return_value = "Metal";
		break;
	case Hiphop:
		return_value = "Hiphop";
		break;
	case Jazz:
		return_value = "Jazz";
		break;
	case Contemporary:
		return_value = "Contemporary";
		break;
	case Instrumental:
		return_value = "Instrumental";
		break;
		
	}
	return return_value;

}

int main()
{
	std::cout << "If you are lost in the database, type \"help\"" << endl;
	string input;

/*	Song newSong1;
	Song newSong2;
	Song newSong3;
	Song newSong4;
	Song newSong5;
	Song newSong6;
	Song newSong7;
	Song newSong8;
*/

	Song currentSong; // this will make it so the most recent song added, which always goes to newSong1, will be listed as "current song"
	int count = 0;
	MusicDB::commands(); // wherever the function is saved, add this surname to the beginning of code
	while (input != "exit")
	{
		std::cin >> input; // "cin will now be looking for user input and will store anything computed"
		if (input == "help")
			MusicDB::commands();
		else if (input == "load")
			MusicDB::load();
		else if (input == "add")
		{   
			count++;//requires curly brackets here because the else if below has more than 1 line of commands //every time someone enters "add", the counter will increment by one			
			if (count < 8)
			{
				MusicDB::add();
			}
			else
			{
				std::cout << "There are already 8 songs in the list." << endl;
				count--; //puts count back to 8 if the tally has been taken to 9
			}
		}
		else if (input == "save")
		{

		}
		else if (input == "list")
			//MusicDB::list(newSong1, count);

	}
}



