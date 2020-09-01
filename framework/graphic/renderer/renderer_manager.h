#ifndef _RENDER_MANAGER_H_
#define _RENDER_MANAGER_H_

#include "common/interface/singleton.h"
#include "cmake_val.h"
namespace BriskEngine {

enum class ENUM_GRAPIC_API_TYPE :unsigned {
	NULL,
	DX12,
	VULKAN,
	METAL
};

class RendererManager : implements Singleton<RendererManager>
{
public:
	inline ENUM_GRAPIC_API_TYPE getGraphicType() { return m_eGraphicType; }
private:
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