cd ../..
if [ -d build ]
then
	sudo rm -rf build
fi

mkdir build
cd build
cmake ..

read -n 1 -p "Press any key to continue..."