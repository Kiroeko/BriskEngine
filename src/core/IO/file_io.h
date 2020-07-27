#ifndef _FILE_IO_H_
#define _FILE_IO_H_

#include <string>
#include "core/utils/singleton.h"
namespace CppToolBox {

class FileIO : public Singleton<FileIO>{
public:
	bool writeStrToFile(const std::string &str, const std::string &pathName);
	const std::string readFileToStr(const std::string &pathName);
};

}
#endif