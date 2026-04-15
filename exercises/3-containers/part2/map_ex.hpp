#ifndef CPPEX_MAP_EX_HPP
#define CPPEX_MAP_EX_HPP

#include <map>
#include <string>

using StrIntMap = std::map<std::string, int>;

// Use the concise def of StrIntMap above to improve clarity
// bool AddWord(std::map<std::string, int>& mymap, std::string mystring);
bool AddWord(StrIntMap& mymap, std::string const& mystring);

#endif
