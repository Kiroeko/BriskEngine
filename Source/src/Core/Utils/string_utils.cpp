#include "string_utils.h"

using namespace std;
using namespace CppToolBox;

void StringUtils::toUpper(string &str)
{
	for (auto &c : str) {
		toupper(c);
	}
}

void StringUtils::toLower(string &str)
{
	for (auto &c : str) {
		tolower(c);
	}
}

vector<string> StringUtils::split(const string &str, const string &delimiter)
{
	string targetStr = str;
	vector<string> matchResult;

	string::size_type pos = 0;
	while ((pos=targetStr.find(delimiter)) != string::npos) {
		if (pos != 0)
			matchResult.push_back(targetStr.substr(0, pos));
		targetStr = targetStr.substr(pos + delimiter.size());
	}
	if (!targetStr.empty())
		matchResult.push_back(targetStr);

	return matchResult;
}