cd ../..
if [ -d build ]
then
	sudo rm -rf build
fi
mkdir build

call cmake -S . -B ./build -A ARM64 -D TARGET_PLATFORM_TYPE_LINUX="Linux" -D GRAPHIC_API_TYPE_VULKAN="Vulkan"

read -n 1 -p "Press any key to continue..."