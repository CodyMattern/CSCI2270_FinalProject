
#include "RiotAPI.h"

namespace Riot
{
	std::string api_key = "";
	//Region region = Region::NA;
	//Locale locale = Locale::en_US;

	namespace
	{
		const std::string BASE_URL = "http://prod.api.pvp.net/api/lol/";
		const std::string BASE_STATIC_URL = "http://prod.api.pvp.net/api/lol/static-data/";
		const std::string CHAMPION_API_VERSION = "/v1.1/";
		const std::string GAME_API_VERSION = "/v1.3/";
		const std::string LEAGUE_API_VERSION = "/v2.3/";
		const std::string STATIC_API_VERSION = "/v1/";
		const std::string STATS_API_VERSION = "/v1.2/";
		const std::string SUMMONER_API_VERSION = "/v1.3/";
		const std::string TEAM_API_VERSION = "/v2.2/";

		/*rapidjson::Document parseJSON(std::string url)
		{
			rapidjson::Document json;
			std::string* contents = URLReader::read(url);
			json.Parse<0>(contents->c_str());
			delete contents;
			return json;
		}*/
	}
}
