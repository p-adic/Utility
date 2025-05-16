// c:/Users/user/Documents/Programming/Utility/String/Encode/a.hpp

#pragma once

template <typename INT> inline char IntToChar( const INT& i , const char& c = 'a' );
template <typename INT = int> inline INT CharToInt( const char& c );

template <typename INT> string ArrayToString( const vector<INT>& A , const char& c = 'a' );
template <typename INT = int> vector<INT> StringToArray( const string& S );

inline char Chapitalise( const char& c );

template <typename INT> string ArrayToParenthesisString( const vector<INT>& A );
template <typename INT = int> vector<INT> ParenthesisStringToArray( const string& S );
