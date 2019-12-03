#include "Song.h"
#include <iostream>
#pragma once

namespace MusicDB // this namespace means that it will recognize the names of the functions in different windows
{
	std::vector<Song> tempList[8]; //list of temporary songs to be stored to the database
	void commands(); //commands function
	void load(); //load songs function
	void add(); //add song function
	Genre convertStringToGenre(std::string genre);
	void save(Song newSong, int songNumber); // specifies how to save file to db in binary
	void list(Song newSong, int songNumber); // list songs
	std::string convertGenreToString(Genre genre); // convert a Genre to std::string
}
