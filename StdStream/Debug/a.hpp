// c:/Users/user/Documents/Programming/Utility/StdStream/Debug/a.hpp

#pragma once
#include "../a.hpp"

// デバッグ出力用にVariadicCoutとVariadicCoutNonSepの定義に改行の有無の判定を追加する。
inline bool HasBr();
template <typename T> inline bool HasBr( const T& s );
inline bool HasBr( const char& c );
template <size_t L> bool HasBr( const char ( &s )[L] );
inline bool HasBr( const string& s );
// template <typename Arg0 , typename Arg1 , typename...Args> inline bool HasBr( const Arg0& arg0 , const Arg1& arg1 , const Args&... args );
inline bool& SearchedBr();
