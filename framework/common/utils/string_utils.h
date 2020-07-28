#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

#include <vector>
#include <string>
#include "common/interface/singleton.h"
namespace BriskEngine {

class StringUtils : implements Singleton<StringUtils> {
public:
	void toUpper(std::string &str);
	void toLower(std::string &str);
	std::vector<std::string> split(const std::string &str, const std::string &delimiter);
};

}
#endif