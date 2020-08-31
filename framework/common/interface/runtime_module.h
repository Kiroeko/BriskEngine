#ifndef _RUNTIME_MODULE_H_
#define _RUNTIME_MODULE_H_

#include "common/interface/interface.h"
namespace BriskEngine {

Interface RuntimeModule{
public:
	virtual ~RuntimeModule() {};
	virtual bool Initialize() = 0;
	virtual void Finalize() = 0;
	virtual void Tick() = 0;
};

}
#endif