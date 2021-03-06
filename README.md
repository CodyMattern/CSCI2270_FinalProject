<<<<<<< HEAD
# Mattern_CSCI2270_FinalProject
=======
# Project Summary
This project will be a league of legends statistic viewer. It will connect to the Riot API server to request information about the given username. It will pull ranked statistic down and store them inside the program for the user to view. Using a BST it will store each of your ranked champions statistics.
Program should be easy to use and should offer information to help them improve gameplay.

# How to Run
Select a Menu option
Enter Summoner Name
Select a Season
View stored information gathered from RIOT games


# Dependencies
GGTucker Riot API - https://github.com/ggtucker/riot-cpp. Already included in repository.

rapidjson - 
https://code.google.com/p/rapidjson/downloads/list
-Rapidjson files are included in the project but must be added as a directory in order to run
-In CodeBlocks: 
	-Settings->Compiler->Search Directories(Tab)->Compiler(Tab 		default)->Add
	-browse project for /include and hit Ok

	--for additional help with installation--
	https://code.google.com/p/rapidjson/wiki/UserGuide

cURL - used for acquiring JSON data from RIOT games
 - sudo apt-get install libcurl4-openssl-dev  (easiest method to acquire)
 - http://curl.haxx.se/download.html  (curl zip download - requires manual installation of curl)

RIOT API key
  create a username and password (if you don't already have a username for league of legends)
  - http://na.leagueoflegends.com/
  use the username and password to log into 
  - https://developer.riotgames.com/
  a key will be granted for use that should not be shared and is confidential
  
# System Requirements
c++ compiler
Recommended CodeBlocks or Geany

# Group Members
Nick Trierweiler
Cody Mattern

# Contributors
Nick Trierweiler
Cody Mattern

# Open issues/bugs


# Available added functionality
//--Menu options provide statistics for seasons 3 4 and 5--//
Current available stats:
-Champion Played
-Total Games Played
-Average Kills
-Average Deaths
-Average Assists
-Kill/Death/Assist Ratio
-Ranked Multi-Kill Stats
-Total Games Played


# TODO
Handle Response Errors
View stats from all seasons
GUI interface
Store Key in .txt file for security


>>>>>>> 4ba42fb419ca4c869f8eab7a254cb1887aa3a04c 

Disclaimer
----------
This product is not endorsed, certified or otherwise approved in any way by Riot Games, Inc. or any of its affiliates.
