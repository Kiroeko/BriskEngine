#ifndef _BASE_APPLICATION_H_
#define _BASE_APPLICATION_H_

#include "common/interface/runtime_module.h"
namespace BriskEngine{

Interface BaseApplication : implements RuntimeModule
{
public:
	virtual bool Initialize() = 0;
	virtual void Finalize() = 0;
	virtual void Update() = 0;

	virtual bool isNeedExit() = 0;
};

}
#endif