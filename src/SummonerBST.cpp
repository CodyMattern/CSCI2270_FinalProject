#include <string.h>
#include <stdio.h>
#include <iostream>
#include "SummonerBST.h"
using namespace std;

SummonerBST::~SummonerBST(){}
SummonerBST::SummonerBST(){}

void SummonerBST::addSummonerNode(std::string championName, int kills, int deaths, int assists, int games, int cs, long int gold_earned)
{
    SummonerNode *y = new SummonerNode;
    SummonerNode *x = root;
    SummonerNode *z = new SummonerNode(championName, kills, deaths, assists, games, cs, gold_earned);
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
}

void SummonerBST::printSummonerBST()
{
    printSummonerBST(root);
}
void SummonerBST::printSummonerBST(SummonerNode *x)
{
    if(x->left != NULL){
        printSummonerBST(x->left);
        }
        cout<<"Movie: "<<x->championName<<endl;

    if(x->right != NULL)
        printSummonerBST(x->right);

}
