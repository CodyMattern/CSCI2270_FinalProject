#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <RiotCPP/Riot.hpp>
#include <RiotCPP/RiotPrinter.hpp>
#include <SummonerBST.h>
using namespace std;


int main()
{
    Riot::api_key = "66f5d13c-a7d0-4a29-811c-b51794d9872f";
    Riot::SummonerBST *tree = new Riot::SummonerBST();
    bool quit = false;
    while(!quit)
    {
        cout << "Welcome to Summoner Search!" << endl;
        cout << "1) Search for Summoner" << endl;
        cout << "2) Quit" << endl;
        int menuResponse;
        cin >> menuResponse;
        cout << endl;
        switch(menuResponse)
        {
        case 1:
        {
            string summonerName;
            int seasonNumber;
            cout << "Enter Summoner Name:" << endl;
            cin.ignore();
            getline(cin, summonerName);
            cout << endl;
            transform(summonerName.begin(), summonerName.end(), summonerName.begin(), ::tolower);
            Riot::Summoner summonerID = Riot::getSummoner(summonerName);

            cout << "Enter what season number(Only 3, 4 or 5 work currently):" << endl;
            cin >> seasonNumber;
            cout << endl;

            Riot::Season season;
            switch(seasonNumber)
            {
            case 3:
                season = Riot::Season::SEASON3;
                break;
            case 4:
                season = Riot::Season::SEASON4;
                break;
            case 5:
                season = Riot::Season::SEASON5;
                break;
            default:
                season = Riot::Season::SEASON5;
                break;
            }


            Riot::RankedStats searchedSummoner = Riot::getRankedStats(summonerID.id, season);


            tree->getChampRankedStats(searchedSummoner);
            bool inMenu = true;
            while(inMenu)
            {
                cout << "Summoner Name: " << summonerID.name <<  " || " << "Summoner Level: " << summonerID.summonerLevel <<  " || " << "Season: " << Riot::toString(season) << endl;
                cout << "1) Ranked Stats" << endl;
                cout << "2) Ranked Stats by Champion" << endl;
                cout << "3) Best Champion Stats" << endl;
                cout << "4) Back to Main Menu" << endl;
                int menuResponse;
                cin >> menuResponse;
                cout << endl;
                switch(menuResponse)
                {
                case 1:
                    tree->printSummonerStats(season);
                    break;
                case 2:
                    tree->printSummonerBST();
                    break;
                case 3:
                    tree->printBestChamp();
                    break;
                case 4:
                    inMenu = false;
                    break;
                default:
                    break;
                }
            }


            break;
        }
        case 2://test
        {
            quit = true;
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
