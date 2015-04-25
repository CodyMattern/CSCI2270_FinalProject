#include <string.h>
#include <stdio.h>

#include "SummonerBST.h"
using namespace std;

SummonerBST::~SummonerBST(){}
SummonerBST::SummonerBST(){}

void SummonerBST::addSummonerNode(std::string name, long int summonerID, int level)
{
    SummonerNode *y = new SummonerNode;
    SummonerNode *x = root;
    SummonerNode *z = new SummonerNode(name, summonerID, level);
    if(root == NULL)//empty
    {
        root = z;
    }
    else
    {
        y = NULL;
        x = root;
        while(x != NULL)
        {
            y = x;
            if(z->level < x->level)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        z->parent = y;
        if(z->level < y->level)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
    }
}
