#include <utilities.h>

std::vector<std::string> splitString(std::string str, const char del)
{
    std::vector<std::string> out;
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, del))
    {
        out.push_back(s);
    }
    return out;
}