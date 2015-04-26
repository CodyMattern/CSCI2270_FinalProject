#ifndef SUMMONERBST_H
#define SUMMONERBST_H
#include <string>
#include <iostream>
#include <iomanip>
#include <RiotCPP/DTO/Champion.hpp>
#include <RiotCPP/DTO/ChampionList.hpp>
#include <RiotCPP/DTO/ChampionData.hpp>
#include <RiotCPP/DTO/ChampionDataList.hpp>
#include <RiotCPP/DTO/RecentGames.hpp>
#include <RiotCPP/DTO/Game.hpp>
#include <RiotCPP/DTO/League.hpp>
#include <RiotCPP/DTO/LeagueItem.hpp>
#include <RiotCPP/DTO/Item.hpp>
#include <RiotCPP/DTO/ItemList.hpp>
#include <RiotCPP/DTO/Mastery.hpp>
#include <RiotCPP/DTO/MasteryList.hpp>
#include <RiotCPP/DTO/Realm.hpp>
#include <RiotCPP/DTO/Rune.hpp>
#include <RiotCPP/DTO/RuneList.hpp>
#include <RiotCPP/DTO/SummonerSpell.hpp>
#include <RiotCPP/DTO/SummonerSpellList.hpp>
#include <RiotCPP/DTO/PlayerStatsSummaryList.hpp>
#include <RiotCPP/DTO/RankedStats.hpp>
#include <RiotCPP/DTO/Summoner.hpp>
#include <RiotCPP/DTO/MasteryPages.hpp>
#include <RiotCPP/DTO/RunePages.hpp>
#include <RiotCPP/DTO/Team.hpp>
namespace Riot
{
struct SummonerNode
{
    //vari
    int championID;
    std::string championName;
    double kills, deaths, assists, KDA;
    int games, cs;

    SummonerNode *left = NULL;
    SummonerNode *right = NULL;
    SummonerNode *parent = NULL;

    SummonerNode() {};
    SummonerNode(std::string in_championName, int in_championID, double in_kills, double in_deaths, double in_assists, int in_games, double in_KDA) //cstr
    {
        championName = in_championName;
        championID = in_championID;
        kills = in_kills;
        deaths = in_deaths;
        assists = in_assists;
        games = in_games;
        KDA = in_KDA;

    }
};

class SummonerBST //: public MovieNode
{
public:
    SummonerBST();
    virtual ~SummonerBST();
    void addSummonerNode(std::string, int, double, double, double, int, double);
    void printSummonerBST();
    void printSummonerBST(SummonerNode *root);
    void getChampRankedStats(const RankedStats& data);
    void addChampionStats(const ChampionStats& data);
    bool ifPlayed(const AggregatedStats& data);
    void setSummonerStats(const ChampionStats& data);
    void printSummonerStats();
    void buildChampList();
    std::string getChampName(int champID);
    void printBestChamp();
protected:
private:
    int totalGames, totalWins, totalLosses, totalDouble, totalTriple, totalQuadra, totalPenta, maxKills, totalKills, totalDeaths, totalAssists, totalCS;
    SummonerNode *root;
    std::map<int,std::string>champlist;
    SummonerNode *best;
    SummonerNode *worst;
};

#endif // SUMMONERBST_H

}
