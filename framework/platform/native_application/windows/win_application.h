#ifndef _WIN_APPLICATION_H_
#define _WIN_APPLICATION_H_

#include "common/interface/base_application.h"
namespace BriskEngine{

class WinApplication : public BaseApplication{
    public:
		bool Initialize() override;
		void Finalize() override;
		void Update() override;
		
		void ExitApplication();
	private:
		bool isNeedExit() override;
    	bool m_bNeedExit = false;
};

}
#endif