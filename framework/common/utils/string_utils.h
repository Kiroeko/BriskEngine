#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

#include <vector>
#include <string>
#include "common/utils/singleton.h"
namespace BriskEngine {

class StringUtils : implements Singleton<StringUtils> {
public:
	void toUpper(std::string &str);
	void toLower(std::string &str);
	std::vector<std::string> split(const std::string &str, const std::string &delimiter);

	std::string ws2s(const std::wstring& ws);
	std::wstring s2ws(const std::string& s);
};

}
#endif