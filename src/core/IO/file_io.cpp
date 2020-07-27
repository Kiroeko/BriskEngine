#include <iostream>
#include <sstream>
#include <fstream>
#include "core/IO/file_io.h"

using namespace std;
using namespace CppToolBox;

bool FileIO::writeStrToFile(const string& str, const string& pathName){
	stringstream ss;
	ss << str;

	fstream f(pathName, ios::ate | ios::out);
	if (f.is_open()) {
		string tmpStr;
		for (int i = 0; getline(ss, tmpStr); ++i) {
			if (i != 0)
				f << "\n";
			f << tmpStr;
		}
		f.close();
		return true;
	} else {
		cerr << "Can not open path name: "+pathName+"." << endl;
	}
	return false;
}

const string FileIO::readFileToStr(const string &pathName)
{
	string result;

	fstream f(pathName, ios::in);
	if (f.is_open()) {
		string tmpStr;
		for (int i = 0; getline(f, tmpStr); ++i) {
			if (i != 0)
				result += "\n";
			result += tmpStr;
		}
		f.close();
	} else {
		cerr << "Can not open path name: "+pathName+"." << endl;
	}
	return result;
}