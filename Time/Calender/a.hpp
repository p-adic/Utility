// c:/Users/user/Documents/Programming/Utility/Time/Calender/a.hpp

#pragma once

// 閏年判定
template <typename INT> inline bool IsLeap( const INT& y );

// 有効な日付か否かの判定
template <typename INT> inline bool IsValidDate( const INT& y , const int& m , const int& d );
template <typename TUPLE> inline bool IsValidDate( const TUPLE& ymd );

// 西暦1年1月1日を1日目として何日目かを計算。
template <typename INT> inline INT CountDay( const INT& y , const int& m , const int& d );
template <typename TUPLE> inline auto CountDay( const TUPLE& ymd ) -> decltype( get<0>( ymd ) );
