#ifndef _BASE_APPLICATION_H_
#define _BASE_APPLICATION_H_

#include "common/interface/runtime_module.h"
namespace BriskEngine{

Interface BaseApplication : implements RuntimeModule
{
public:
	virtual bool Initialize() {}
	virtual void Finalize() {}
	virtual void Tick() {}
};

}
#endif