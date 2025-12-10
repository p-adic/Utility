// c:/Users/user/Documents/Programming/Utility/Time/Calender/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline bool IsLeap( const INT& y ) { return y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0 ); }

template <typename INT> inline bool IsValidDate( const INT& y , const int& m , const int& d ) { static constexpr const int days[] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }; return 1 <= y && 1 <= m && m <= 12 && 1 <= d && d <= days[m] + ( m == 2 && IsLeap( y ) ? 1 : 0 ); }
template <typename TUPLE> inline bool IsValidDate( const TUPLE& ymd ) { auto& [y,m,d] = ymd; return IsValidDate( y , m , d ); }

template <typename INT> inline INT CountDay( const INT& y , const int& m , const int& d ) { assert( IsValidDate( y , m , d ) ); static constexpr const int cdays = { 0 , 31 , 59 , 90 , 120 , 151 , 181 , 212 , 243 , 273 , 304 , 334 }; return ( y - 1 ) * 365 + ( y - 1 ) / 4 - ( y - 1 ) / 100 + ( y - 1 ) / 400 + cdays[m-1] + ( m > 2 && y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0 ) ? 1 : 0 ) + d; }
template <typename TUPLE> inline auto CountDay( const TUPLE& ymd ) -> decltype( get<0>( ymd ) ) { auto& [y,m,d] = ymd; return CountDay( y , m , d ); }
