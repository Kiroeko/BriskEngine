#ifndef _BASE_APPLICATION_H_
#define _BASE_APPLICATION_H_

#include "common/interface/runtime_module.h"
namespace BriskEngine{

Interface BaseApplication : implements RuntimeModule
{
public:
	virtual bool Initialize() {
		m_bQuit = false;
		return true;
	}
	virtual void Finalize() {}
	virtual void Tick() {}
	virtual bool IsQuit() {
		return m_bQuit;
	}
protected:
	bool m_bQuit = false;
};

}
#endif