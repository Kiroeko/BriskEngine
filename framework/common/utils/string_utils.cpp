#include <locale>
#include "common/utils/string_utils.h"

using namespace std;
using namespace BriskEngine;

void StringUtils::toUpper(string &str)
{
	for (auto &c : str) {
		c = toupper(c);
	}
}

void StringUtils::toLower(string &str)
{
	for (auto &c : str) {
		c = tolower(c);
	}
}

vector<string> StringUtils::split(const string &str, const string &delimiter)
{
	string targetStr = str;
	vector<string> matchResult;

	string::size_type pos = 0;
	while ((pos=targetStr.find(delimiter)) != string::npos) {
		if (pos != 0)
			matchResult.push_back(targetStr.substr(0, pos));
		targetStr = targetStr.substr(pos + delimiter.size());
	}
	if (!targetStr.empty())
		matchResult.push_back(targetStr);

	return matchResult;
}

std::string ws2s(const std::wstring& ws)
{
    std::locale sys_loc("");
    mbstate_t out_cvt_state;

    const wchar_t* src_wstr = ws.c_str();
    constexpr size_t MAX_UNICODE_BYTES = 4;
    const size_t BUFFER_SIZE =
        ws.size() * MAX_UNICODE_BYTES + 1;
    char* extern_buffer = new char[BUFFER_SIZE];
    memset(extern_buffer, 0, BUFFER_SIZE);

    const wchar_t* intern_from = src_wstr;
    const wchar_t* intern_from_end = intern_from + ws.size();
    const wchar_t* intern_from_next = 0;
    char* extern_to = extern_buffer;
    char* extern_to_end = extern_to + BUFFER_SIZE;
    char* extern_to_next = 0;

    using CodecvtFacet = std::codecvt<wchar_t, char, mbstate_t>;
    CodecvtFacet::result cvt_rst =
        std::use_facet<CodecvtFacet>(sys_loc).out(
            out_cvt_state,
            intern_from, intern_from_end, intern_from_next,
            extern_to, extern_to_end, extern_to_next
        );

    std::string result = extern_buffer;
    delete[]extern_buffer;
    return result;
}

std::wstring s2ws(const std::string& s)
{
    std::locale sys_loc("");
    mbstate_t in_cvt_state;

    const char* src_str = s.c_str();
    const size_t BUFFER_SIZE = s.size() + 1;
    wchar_t* intern_buffer = new wchar_t[BUFFER_SIZE];
    wmemset(intern_buffer, 0, BUFFER_SIZE);

    const char* extern_from = src_str;
    const char* extern_from_end = extern_from + s.size();
    const char* extern_from_next = 0;
    wchar_t* intern_to = intern_buffer;
    wchar_t* intern_to_end = intern_to + BUFFER_SIZE;
    wchar_t* intern_to_next = 0;

    using CodecvtFacet = std::codecvt<wchar_t, char, mbstate_t>;
    CodecvtFacet::result cvt_rst =
        std::use_facet<CodecvtFacet>(sys_loc).in(
            in_cvt_state,
            extern_from, extern_from_end, extern_from_next,
            intern_to, intern_to_end, intern_to_next
        );

    std::wstring result = intern_buffer;
    delete[]intern_buffer;
    return result;
}