// c:/Users/user/Documents/Programming/Utility/String/Encode/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline char IntToChar( const INT& i , const char& c ) { return c + i; }
template <typename INT> inline INT CharToInt( const char& c ) { return c - ( c < 'a' ? 'A' : 'a' ); }

template <typename INT>
string ArrayToString( const vector<INT>& A , const char& c )
{

  const int N = A.size();
  string S( N , c );

  for( int i = 0 ; i < N ; i++ ){

    S[i] = IntToChar<INT>( A[i] , c );

  }

  return S;

}

template <typename INT>
vector<INT> StringToArray( const string& S )
{

  const int N = S.size();
  vector<int> A( N );

  for( int i = 0 ; i < N ; i++ ){

    A[i] = CharToInt<INT>( S[i] );

  }

  return A;

}


inline char Chapitalise( const char& c ) { return c < 'a' ? c + ( 'a' - 'A' ) :  c - ( 'a' - 'A' ); }
