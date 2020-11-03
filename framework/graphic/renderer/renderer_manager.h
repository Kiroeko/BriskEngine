#ifndef _RENDER_MANAGER_H_
#define _RENDER_MANAGER_H_

#include "common/utils/singleton.h"
#include "cmake_val.h"
namespace BriskEngine {

enum class ENUM_GRAPIC_API_TYPE :unsigned {
	DX12,
	NA
};

class RendererManager : implements Singleton<RendererManager>
{
public:
	inline ENUM_GRAPIC_API_TYPE getGraphicType() { return m_eGraphicType; }
private:
#ifdef GRAPHIC_API_TYPE_DX12
	ENUM_GRAPIC_API_TYPE m_eGraphicType = ENUM_GRAPIC_API_TYPE::DX12;
#elif defined GRAPHIC_API_TYPE_NA
	ENUM_GRAPIC_API_TYPE m_eGraphicType = ENUM_GRAPIC_API_TYPE::NA;
#endif
};

}
#endif