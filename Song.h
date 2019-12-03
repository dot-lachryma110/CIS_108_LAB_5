#include <string>
#include <iostream>

using namespace std;

enum Genre
{
	Blues = 0, Rock, Metal, Rap, Hiphop, Jazz, Contemporary, Instrumental
};


//How can we show this so that the people using the music database don't have to type in 0,1,2,3,4....... to represent a music type
struct Song
{
	char Album_name[64];
	char Song_Name[64];
	char Artist[32];
	char Year[4];
	char Geo_Region[64];
	char track_no [3];
	Genre genre;
};


