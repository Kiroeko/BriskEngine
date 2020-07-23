@echo off

cd ../..
if exist build (
	del /f /s /q build\*.*
	rd /s /q build
)

md build
cd build
call cmake ..

pause