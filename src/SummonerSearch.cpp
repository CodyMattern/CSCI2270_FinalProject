#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iterator>
#include <RiotCPP/Riot.hpp>
#include <RiotCPP/RiotPrinter.hpp>
#include <SummonerBST.h>
using namespace std;


int main()
{
    Riot::api_key = "66f5d13c-a7d0-4a29-811c-b51794d9872f";
    SummonerBST *tree = new SummonerBST();
    bool quit = false;
    while(!quit)
    {
        cout << "Welcome to Summoner Search!" << endl;
        cout << "1) Search for Summoner" << endl;
        int menuResponse;
        cin >> menuResponse;
        switch(menuResponse)
        {
        case 1:
        {
            string summonerName;
            cout << "Enter Summoner Name:" << endl;
            cin.ignore();
            getline(cin, summonerName);
            Riot::Summoner searchedSummoner = Riot::getSummoner(summonerName);
            Riot::RiotPrinter::printSummoner(searchedSummoner);
            break;
        }
        case 2://test
        {
            //tree->SummonerBST::addSummonerNode("wide", 19507614, 30);
            Riot::ChampionData ryzeData = Riot::getChampionData(13);
            Riot::RiotPrinter::printChampionData(ryzeData);
            break;
        }
        break;
        default:
            cout << "Sorry, that was not a valid input!" << endl;
            break;
        }
    }
    return 0;
}
