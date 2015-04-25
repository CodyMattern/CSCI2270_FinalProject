#ifndef SUMMONERBST_H
#define SUMMONERBST_H
#include <string>
struct SummonerNode{
    //vari
    std::string name;
    long int summonerID;
    int level;
    SummonerNode *parent;
    SummonerNode *left;
    SummonerNode *right;

    SummonerNode(){};
    SummonerNode(std::string in_name, long int in_summonerID, int in_level) //cstr
    {
        name = in_name;
        summonerID = in_summonerID;
        level = in_level;
    }
};

class SummonerBST //: public MovieNode
{
    public:
        SummonerBST();
        virtual ~SummonerBST();
        void addSummonerNode(std::string, long int, int);
    protected:
    private:
    SummonerNode *root;

};

#endif // SUMMONERBST_H
