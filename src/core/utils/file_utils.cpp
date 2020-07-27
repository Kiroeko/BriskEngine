#include <iostream>
#include <regex>
#include <algorithm>
#include <filesystem>
#include "core/utils/file_utils.h"
#include "core/utils/string_utils.h"

using namespace std;
using namespace std::filesystem;
using namespace CppToolBox;

vector<string> FileUtils::findFileInDirPath(const string &findKeyName, const string &findDirPath, uint32_t findMode)
{
	vector<string> result;

	if (!isLegalDir(findDirPath)) {
		cerr << "Directory path "+findDirPath+" is illegal." << endl;
		return result;
	}

	bool modeDir = findMode & FILE_FIND_MODE_IS_DIR;
	bool modeIgnoreUpperOrLower = findMode & FILE_FIND_MODE_IGNORE_UPPER_OR_LOWER;
	bool modeFullMatch = findMode & FILE_FIND_MODE_FULL_MATCH;
	bool modeUseRegex = findMode & FILE_FIND_MODE_USE_REGEX;
	bool modeRecursion = findMode & FILE_FIND_MODE_RECURSION;

	findFileInCurPath(result, findKeyName, findDirPath, modeDir, modeIgnoreUpperOrLower, modeFullMatch, modeUseRegex, modeRecursion);
	return result;
}

bool FileUtils::isLegalDir(const string &path)
{
	if (exists(path)) {
		directory_entry entry(path);
		if (entry.status().type() == file_type::directory)
			return true;
	}
	return false;
}

void FileUtils::findFileInCurPath(
	vector<string> &result, 
	const string &findKeyName, 
	const string &nowDirPath, 
	bool modeDir,
	bool modeIgnoreUpperOrLower,
	bool modeFullMatch,
	bool modeUseRegex,
	bool modeRecursion
)
{
	file_type targetFileType;
	if (modeDir) {
		targetFileType = file_type::directory;
	} else {
		targetFileType = file_type::regular;
	}

	directory_entry entry(nowDirPath);
	if (entry.status().type() == targetFileType) {
		string keyName = findKeyName;
		if (modeIgnoreUpperOrLower)
			StringUtils::getInstance().toLower(keyName);
		
		const string nowFileName = entry.path().filename().string();
		string fileName = nowFileName;
		if (modeIgnoreUpperOrLower)
			StringUtils::getInstance().toLower(fileName);

		bool match = false;
		if (modeUseRegex) {
			std::string pattern(findKeyName);
			std::regex r(pattern);
			std::smatch results;
			if (regex_search(nowFileName, results, r))
				match = true;
		} else {
			if (modeFullMatch) {
				if (keyName == fileName)
					match = true;
			}
			else {
				if (fileName.find(keyName) != string::npos)
					match = true;
			}
		}

		if(match)
			result.push_back(entry.path().string());
	}

	if (entry.status().type() == file_type::directory) {
		directory_iterator iterNowFile(nowDirPath);
		for (const auto &it : iterNowFile) {
			findFileInCurPath(result, findKeyName, it.path().string(), modeDir, modeIgnoreUpperOrLower, modeFullMatch, modeUseRegex, modeRecursion);
		}
	}
}