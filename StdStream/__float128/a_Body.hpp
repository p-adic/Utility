// c:/Users/user/Documents/Programming/Utility/StdStream/__float128/a_Body.hpp

#pragma once
#include "a.hpp"

template <class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const __float128& x ) { return os << static_cast<ld>( x ); }
