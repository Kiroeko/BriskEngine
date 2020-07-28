#ifndef _FILE_UTILS_H_
#define _FILE_UTILS_H_

#include <vector>
#include <string>
#include "common/interface/singleton.h"
namespace BriskEngine {

constexpr uint32_t FILE_FIND_MODE_IS_DIR = 0b1;
constexpr uint32_t FILE_FIND_MODE_IGNORE_UPPER_OR_LOWER = 0b10;
constexpr uint32_t FILE_FIND_MODE_FULL_MATCH = 0b100;
constexpr uint32_t FILE_FIND_MODE_USE_REGEX = 0b1000;
constexpr uint32_t FILE_FIND_MODE_RECURSION = 0b10000;

class FileUtils : implements Singleton<FileUtils> {
public:
	std::vector<std::string> findFileInDirPath(const std::string& findKeyName, const std::string &findDirPath, uint32_t findMode);
	bool isLegalDir(const std::string &path);
private:
	void findFileInCurPath(
		std::vector<std::string> &result, 
		const std::string &findKeyName, 
		const std::string &nowDirPath, 
		bool modeDir,
		bool modeIgnoreUpperOrLower,
		bool modeFullMatch,
		bool modeUseRegex,
		bool modeRecursion	
	);
};

}
#endif