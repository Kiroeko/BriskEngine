#ifndef _DX12_RENDERER_H_
#define _DX12_RENDERER_H_

#include "common/interface/base_renderer.h"
namespace BriskEngine {

	class DX12Renderer : public BaseRenderer {
	public:
		bool Initialize() override;
		void Finalize() override;
		void Tick() override;
	};

}
#endif