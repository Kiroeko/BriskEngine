#ifndef _BASE_RENDERER_H_
#define _BASE_RENDERER_H_

#include "common/interface/runtime_module.h"
namespace BriskEngine {

	Interface BaseRenderer : implements RuntimeModule
	{
	public:
		virtual bool Initialize() {}
		virtual void Finalize() {}
		virtual void Tick() {}
	};

}
#endif