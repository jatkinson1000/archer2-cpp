#include "map_ex.hpp"

bool AddWord(StrIntMap& mymap, std::string const& mystring){
    for (auto&& [key, val] : mymap) {
        if (key == mystring) {
	    return false;
	}
   }
   mymap[mystring] = mystring.length();
   return true;
}
