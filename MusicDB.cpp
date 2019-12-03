
#include "MusicDB.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std; 

namespace MusicDB
{                                                                                                                                                                                                                                         
	string database_filename = "Fake_Spotify.bin";
	void commands()
	{
		std::cout << "load : Load an existing song from database: " << endl;
		std::cout << "add : Add a new song to the database: " << endl;
		std::cout << "list : List the songs in the database:  " << endl;
		std::cout << "save : Save the songs to the database: " << endl;
		std::cout << "help : Display a menu explaining the commands to the users: " << endl;
		std::cout << "exit : Exit the program: " << endl;
	}

	void load()
	{
		std::cout << "loading... ";
	}

	void add() // adding a function "add" for the variable type "Song"....will return a song now.
	{
		//string title;
		//string artist;
		//string album;
		//string track_no;
		//string year;
		string genre;

		Song newSong;   

		std::cout << "Enter song title: ";
		std::cin.ignore();
		std::cin.getline (newSong.Song_Name, 64);  //use .getline to connect to our struct variables
		std::cout << "Enter artist: " << endl;
		//std::cin.ignore();
		std::cin.getline (newSong.Artist, 32);
		std::cout << "Enter album name: " << endl;
		//std::cin.ignore();
		std::cin.getline(newSong.Album_name, 64);
		std::cout << "Enter track number: " << endl;
		//std::cin.ignore();
		std::cin.getline(newSong.track_no,32);
		std::cout << "Enter year: " << endl;
		//std::cin.ignore();
		std::cin.getline(newSong.Year, 32);
		std::cout << "Enter genre: " << endl;
		//std::cin.ignore();
		std::cin >> genre;

		newSong.genre = convertStringToGenre(genre); //setting our new genre format to input. The "." means that we're accessing a property of the newSong variable.
		
		tempList->push_back(newSong);

	}
	
	void save(Song newSong, int songNumber)
	{
		//save songs to the database
		std::fstream file("Fake_Spotify.bin", ios::out | ios::binary); //  fstream is for reading and writing; fstream includes osstream as well
			// ios = out...we're writing something to it;  ios::binary = file will be stored in binary datatype.
			//file.write((char *)&newSong, sizeof(newSong));  //(char *) is a pointer type specifying the location of where in memory the data's being stored.
		for (int i = 0; i < tempList.size; i++)
		file << "Song #" + std::to_string(songNumber) <<endl;
		file << newSong.Song_Name << endl;
		file << newSong.Album_name << endl;
		file << newSong.Artist << endl;
		file << newSong.track_no << endl;
		file << newSong.Year << endl;
		file << convertGenreToString(newSong.genre) << endl;  //this will make it so that it prints out in string format

		file.close();
	}


	Genre convertStringToGenre(std::string genre) //converts a string to a genre
	{
		Genre return_value;

		//std::transform(genre.begin(), genre.end(), genre.begin(),
			//[](unsigned char c) { return std::tolower(c); });

		//convert here
		if (genre == "Blues") //compare will go through each character and see if they're the same, and return a 1 (True) or 0 (False)
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

	void list(Song newSong, int songNumber)
	{
		std::cout << "There are " + to_string(songNumber) + " songs in the database." << endl;
		//go through parameters in binary mode;  goes through list in database
		std::fstream file("Fake_Spotify.bin", std::ios::in | std::ios::binary);

		//get the start position
		std::streampos start = file.tellg();

		//go to the end of file, get the end;
		file.seekg(0, std::ios::end);
		std::streampos end = file.tellg();

		//go back to the start
		file.seekg(0, std::ios::beg);

		//create a vector to hold the data
		std::vector<char> contents;

		//resize contents and cast "end - start" to a size_t (a special datatype for vectors)
		contents.resize(static_cast<size_t>(end - start));

		//read file
		file.read(&contents[0], contents.size());

		//close file
		file.close();

		for (const char& c : contents)  // = with every character in contents...
		{
		std::cout << c;
		}


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
}