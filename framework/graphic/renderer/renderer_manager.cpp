#include "graphic/renderer/renderer_manager.h"
#include "graphic/renderer/dx12/dx12_renderer.h"
namespace BriskEngine {

#ifdef GRAPHIC_API_TYPE_DX12
	DX12Renderer g_Renderer;
#elif defined GRAPHIC_API_TYPE_VULKAN
	VulkanRenderer g_Renderer;
#elif defined GRAPHIC_API_TYPE_METAL
	MetalRenderer g_Renderer;
#endif
	BaseRenderer* g_pRenderer = &g_Renderer;
}