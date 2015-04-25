#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iterator>
#include "RiotAPI.h"
using namespace std;


int main()
{
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
        }
        break;
        default:
            cout << "Sorry, that was not a valid input!" << endl;
            break;
        }
        return 0;
    }
}
