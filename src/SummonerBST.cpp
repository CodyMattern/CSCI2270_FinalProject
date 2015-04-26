#include <string.h>
#include <stdio.h>
#include <iostream>
#include "SummonerBST.h"
using namespace std;

namespace Riot
{
SummonerBST::~SummonerBST() {}
SummonerBST::SummonerBST()
{
    root = NULL;
    buildChampList();
}

void SummonerBST::addSummonerNode(string championName, int championID, double kills, double deaths, double assists, int games, double KDA)
{
    SummonerNode *y = new SummonerNode();
    SummonerNode *x = root;
    SummonerNode *z = new SummonerNode(championName, championID, kills, deaths, assists, games, KDA);

    if(root == NULL)//empty
    {
        root = z;
        best = root;
    }
    else
    {
        y = NULL;
        x = root;
        while(x != NULL)
        {
            y = x;
            if(z->championName < x->championName)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        z->parent = y;
        if(z->championName < y->championName)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
    }
    if(best->KDA < KDA)
    {
        best = z;
    }
}

void SummonerBST::getChampRankedStats(const RankedStats& data)
{
    for(const ChampionStats& s : data.champions)
    {
        addChampionStats(s);
    }
}

void SummonerBST::addChampionStats(const ChampionStats& data)
{
    if(ifPlayed(data.stats))
    {
        if(data.id == 0)
        {
            setSummonerStats(data);
            return;
        }
        addSummonerNode(getChampName(data.id), data.id, ((double)data.stats.totalChampionKills/(double)data.stats.totalSessionsPlayed),
                        (double)data.stats.totalDeathsPerSession/(double)data.stats.totalSessionsPlayed,
                        ((double)data.stats.totalAssists/(double)data.stats.totalSessionsPlayed),
                        data.stats.totalSessionsPlayed,
                        ((double)(data.stats.totalChampionKills + data.stats.totalAssists) / ((data.stats.totalDeathsPerSession ))));
    }
}

void SummonerBST::printBestChamp()
{
    cout << "Champion: "<< best->championName << " ID: " << best->championID << endl;
    cout << "Total Games Played: " << best->games << endl;
    cout << "Average Kills: " << setprecision(2) << best->kills << endl;
    cout << "Average Deaths: " << setprecision(2) << best->deaths << endl;
    cout << "Average Assists: " << setprecision(2) <<  best->assists << endl;
    cout << "KDA: " << setprecision(2) << best->KDA << endl;
    cout << endl;
}

bool SummonerBST::ifPlayed(const AggregatedStats& data)
{

    if(data.totalSessionsPlayed == 0)
    {
        return false;
    }
    return true;

}

void SummonerBST::setSummonerStats(const ChampionStats& data)
{
    totalGames = data.stats.totalSessionsPlayed;
    totalWins = data.stats.totalSessionsWon;
    totalLosses = data.stats.totalSessionsLost;
    totalKills = data.stats.totalChampionKills;
    totalDeaths = data.stats.totalDeathsPerSession;
    totalDouble = data.stats.totalDoubleKills;
    totalTriple = data.stats.totalTripleKills;
    totalQuadra = data.stats.totalQuadraKills;
    totalPenta = data.stats.totalPentaKills;
}

void SummonerBST::printSummonerStats()
{
    cout << "Overall Stats for Season 4:" <<endl;
    cout << "Total Games Played: " << totalGames << endl;
    cout << "Wins: " << setprecision(2) << totalWins << endl;
    cout << "Losses: " << setprecision(2) <<  totalLosses << endl;
    cout << "Total Kills: " << setprecision(2) << totalKills << endl;
    cout << "Total Deaths: " << setprecision(2) << totalDeaths << endl;
    cout << "Total Assists: " << setprecision(2) <<  totalAssists << endl;
    cout << "Total Double: " << setprecision(2) << totalDouble << endl;
    cout << "Total Triple: " << setprecision(2) << totalTriple << endl;
    cout << "Total Quadra: " << setprecision(2) <<  totalQuadra << endl;
    cout << "Total Penta: " << setprecision(2) <<  totalPenta << endl;
    cout << endl;
}

string SummonerBST::getChampName(int champID)
{
    string ChampName = champlist[champID];
    return ChampName;
}

void SummonerBST::buildChampList()
{
    champlist[266] = "Aatrox";
    champlist[103] = "Ahri";
    champlist[84] = "Akali";
    champlist[12] = "Alistar";
    champlist[32] = "Amumu";
    champlist[34] = "Anivia";
    champlist[1] = "Annie";
    champlist[22] = "Ashe";
    champlist[268] = " Azir";
    champlist[432] = "Bard";
    champlist[53] = "Blitzcrank";
    champlist[63] ="Brand";
    champlist[201] = "Braum";
    champlist[51] = "Caitlyn";
    champlist[69] = "Cassiopeia";
    champlist[31] = "ChoGath";
    champlist[42] = "Corki";
    champlist[122] = "Darius";
    champlist[131] = "Diana";
    champlist[36] = "Dr.Mundo";
    champlist[119] = "Draven";
    champlist[60] = "Elise";
    champlist[28] = "Evelynn";
    champlist[81] = "Ezreal";
    champlist[9] = "Fiddlesticks";
    champlist[114] = "Fiora";
    champlist[105] = "Fizz";
    champlist[3] = "Galio";
    champlist[41] = "Gangplank";
    champlist[86] = "Garen";
    champlist[150] = "Gnar";
    champlist[79] = "Gragas";
    champlist[104] = "Graves";
    champlist[120] = "Hecarim";
    champlist[74] = "Heimerdinger";
    champlist[39] = "Irelia";
    champlist[40] = "Janna";
    champlist[59] = "JarvanIV";
    champlist[24] = "Jax";
    champlist[126] = "Jayce";
    champlist[222] = "Jinx";
    champlist[429] = "Kalista";
    champlist[43] = "Karma";
    champlist[30] = "Karthus";
    champlist[38] = "Kassadin";
    champlist[55] = "Katarina";
    champlist[10] = "Kayle";
    champlist[85] = "Kennen";
    champlist[121] = "KhaZix";
    champlist[96] = "KogMaw";
    champlist[7] = "LeBlanc";
    champlist[64] = "LeeSin";
    champlist[89] = "Leona";
    champlist[127] = "Lissandra";
    champlist[236] = "Lucian";
    champlist[117] = "Lulu";
    champlist[99] = "Lux";
    champlist[54] = "Malphite";
    champlist[90] = "Malzahar";
    champlist[57] = "Maokai";
    champlist[11] = "MasterYi";
    champlist[21] = "MissFortune";
    champlist[82] = "Mordekaiser";
    champlist[25] = "Morgana";
    champlist[267] = "Nami";
    champlist[75] = "Nasus";
    champlist[111] = "Nautilus";
    champlist[76] = "Nidalee";
    champlist[56] = "Nocturne";
    champlist[20] = "Nunu";
    champlist[2] = "Olaf";
    champlist[61] = "Orianna";
    champlist[80] = "Pantheon";
    champlist[78] = "Poppy";
    champlist[133] = "Quinn";
    champlist[33] = "Rammus";
    champlist[421] = "RekSai";
    champlist[58] = "Renekton";
    champlist[107] = "Rengar";
    champlist[92] = "Riven";
    champlist[68] = "Rumble";
    champlist[13] = "Ryze";
    champlist[113] = "Sejuani";
    champlist[35] = "Shaco";
    champlist[98] = "Shen";
    champlist[102] = "Shyvana";
    champlist[27] = "Singed";
    champlist[14] = "Sion";
    champlist[15] = "Sivir";
    champlist[72] = "Skarner";
    champlist[37] = "Sona";
    champlist[16] = "Soraka";
    champlist[50] = "Swain";
    champlist[134] = "Syndra";
    champlist[91] = "Talon";
    champlist[44] = "Taric";
    champlist[17] = "Teemo";
    champlist[412] = "Thresh";
    champlist[18] = "Tristana";
    champlist[48] = "Trundle";
    champlist[23] = "Tryndamere";
    champlist[4] = "TwistedFate";
    champlist[29] = "Twitch";
    champlist[77] = "Udyr";
    champlist[6] = "Urgot";
    champlist[110] = "Varus";
    champlist[67] = "Vayne";
    champlist[45] = "Veigar";
    champlist[161] = "VelKoz";
    champlist[254] = "Vi";
    champlist[112] = "Viktor";
    champlist[8] = "Vladimir";
    champlist[106] = "Volibear";
    champlist[19] = "Warwick";
    champlist[62] = "Wukong";
    champlist[101] = "Xerath";
    champlist[5] = "XinZhao";
    champlist[157] = "Yasuo";
    champlist[83] = "Yorick";
    champlist[154] = "Zac";
    champlist[238] = "Zed";
    champlist[115] = "Ziggs";
    champlist[26] = "Zilean";
    champlist[143] = "Zyra";
}
void SummonerBST::printSummonerBST()
{
    printSummonerBST(root);
}

void SummonerBST::printSummonerBST(SummonerNode *x)
{
    if(x->left != NULL)
    {
        printSummonerBST(x->left);
    }

    cout << "Champion: "<< x->championName << " ID: " << x->championID << endl;
    cout << "Total Games Played: " << x->games << endl;
    cout << "Average Kills: " << setprecision(2) << x->kills << endl;
    cout << "Average Deaths: " << setprecision(2) << x->deaths << endl;
    cout << "Average Assists: " << setprecision(2) <<  x->assists << endl;
    cout << "KDA: " << setprecision(2) << x->KDA << endl;
    cout << endl;
    if(x->right != NULL)
        printSummonerBST(x->right);

}
}
