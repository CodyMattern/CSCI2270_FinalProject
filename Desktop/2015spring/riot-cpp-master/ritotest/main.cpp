// main.cpp
#include <iostream>
#include <RiotCPP/Riot.hpp>
#include <RiotCPP/Riot.hpp>
#include <RiotCPP/RiotPrinter.hpp>
//using namespace std;

int main(int argc, char** argv)
{
	Riot::api_key = "<your key>";
	Riot::region = Riot::Region::NA;
	Riot::locale = Riot::Locale::en_US;
    Riot::ChampionList championList = Riot::getChampionList(true);
	Riot::RiotPrinter::printChampionList(championList);


}
