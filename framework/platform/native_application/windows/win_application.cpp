#include "platform/native_application/windows/win_application.h"

using namespace BriskEngine;

bool WinApplication::Initialize() {
	m_bNeedExit = false;
	return true;
}

void WinApplication::Finalize() {

}

void WinApplication::Update() {

}

bool WinApplication::isNeedExit() {
	return m_bNeedExit;
}

void WinApplication::ExitApplication() {
	m_bNeedExit = true;
}