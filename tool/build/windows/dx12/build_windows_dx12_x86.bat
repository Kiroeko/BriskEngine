@echo off

cd ../../../..
if exist build (
	del /f /s /q build\*.*
	rd /s /q build
)
md build

call cmake -S . -B ./build -G "Visual Studio 16 2019" -A Win32 -T host=x86 -D TARGET_PLATFORM_TYPE_WINDOWS="Windows" -D GRAPHIC_API_TYPE_DX12="DX12"
call cmake --open ./build

pause