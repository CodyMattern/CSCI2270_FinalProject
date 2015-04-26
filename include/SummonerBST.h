#ifndef SUMMONERBST_H
#define SUMMONERBST_H
#include <string>
struct SummonerNode{
    //vari
    std::string championName;
    long int gold;
    int kills, deaths, assists, games, cs;



    SummonerNode *parent;
    SummonerNode *left;
    SummonerNode *right;

    SummonerNode(){};
    SummonerNode(std::string in_championName, int in_kills, int in_deaths, int in_assists, int in_games, int in_cs, long int in_gold_earned) //cstr
    {
        championName = in_championName;
        kills = in_kills;
        deaths = in_deaths;
        assists = in_assists;
        games = in_games;
        cs = in_cs;
        gold = in_gold_earned;


    }
};

class SummonerBST //: public MovieNode
{
    public:
        SummonerBST();
        virtual ~SummonerBST();
        void addSummonerNode(std::string, int, int, int, int, int, long int);
        void printSummonerBST();
        void printSummonerBST(SummonerNode *root);
    protected:
    private:
    SummonerNode *root;

};

#endif // SUMMONERBST_H
