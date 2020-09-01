#ifndef _PLATFORM_MANAGER_H_
#define _PLATFORM_MANAGER_H_

#include "common/interface/singleton.h"
#include "cmake_val.h"
namespace BriskEngine{

enum class ENUM_TARGET_PLATFORM_TYPE:unsigned{
	NULL,
	WINDOWS,
	LINUX,
	MACOS
};

class PlatformManager : implements Singleton<PlatformManager>
{
public:
	inline ENUM_TARGET_PLATFORM_TYPE getPlatformType() { return m_ePlatformType; }
private:
#ifdef TARGET_PLATFORM_TYPE_WINDOWS
	ENUM_TARGET_PLATFORM_TYPE m_ePlatformType = ENUM_TARGET_PLATFORM_TYPE::WINDOWS;
#elif defined TARGET_PLATFORM_TYPE_LINUX
	ENUM_TARGET_PLATFORM_TYPE m_ePlatformType = ENUM_TARGET_PLATFORM_TYPE::LINUX;
#elif defined TARGET_PLATFORM_TYPE_MACOS
	ENUM_TARGET_PLATFORM_TYPE m_ePlatformType = ENUM_TARGET_PLATFORM_TYPE::MACOS;
#endif
};

}
#endif