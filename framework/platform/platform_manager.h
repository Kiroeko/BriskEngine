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

enum class ENUM_GRAPIC_API_TYPE:unsigned{
	NULL,
	DX12,
	VULKAN,
	METAL
};

class PlatformManager : implements Singleton<PlatformManager>
{
public:
	void Initialize();
	inline ENUM_TARGET_PLATFORM_TYPE getPlatformType() { return m_ePlatformType; }
	inline ENUM_GRAPIC_API_TYPE      getGraphicType() { return m_eGraphicType; }
private:
#ifdef TARGET_PLATFORM_TYPE_WINDOWS
	ENUM_TARGET_PLATFORM_TYPE m_ePlatformType = ENUM_TARGET_PLATFORM_TYPE::WINDOWS;
#elif defined TARGET_PLATFORM_TYPE_LINUX
	ENUM_TARGET_PLATFORM_TYPE m_ePlatformType = ENUM_TARGET_PLATFORM_TYPE::LINUX;
#elif defined TARGET_PLATFORM_TYPE_MACOS
	ENUM_TARGET_PLATFORM_TYPE m_ePlatformType = ENUM_TARGET_PLATFORM_TYPE::MACOS;
#endif

#ifdef GRAPHIC_API_TYPE_DX12
	ENUM_GRAPIC_API_TYPE m_eGraphicType = ENUM_GRAPIC_API_TYPE::DX12;
#elif defined GRAPHIC_API_TYPE_VULKAN
	ENUM_GRAPIC_API_TYPE m_eGraphicType = ENUM_GRAPIC_API_TYPE::VULKAN;
#elif defined GRAPHIC_API_TYPE_METAL
	ENUM_GRAPIC_API_TYPE m_eGraphicType = ENUM_GRAPIC_API_TYPE::METAL;
#endif
};

}
#endif