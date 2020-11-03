#ifndef _FILE_IO_H_
#define _FILE_IO_H_

#include <string>
#include "common/utils/singleton.h"
namespace BriskEngine {

class FileIO : implements Singleton<FileIO>{
public:
	bool writeStrToFile(const std::string &str, const std::string &pathName);
	const std::string readFileToStr(const std::string &pathName);
};

}
#endif