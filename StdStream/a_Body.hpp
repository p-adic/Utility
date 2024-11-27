// c:/Users/user/Documents/Programming/Utility/StdStream/a_Body.hpp

#pragma once
#include "a.hpp"

// operator<<�̃I�[�o�[���[�h���s�����߁A���include����B
#if !defined( SAMPLE_CHECK ) && defined( DEBUG )
  #include "../Tuple/StdStream/Debug/a_Body.hpp"
  #include "../Vector/StdStream/Debug/a_Body.hpp"
#else
  #include "../Tuple/StdStream/a_Body.hpp"
  #include "../Vector/StdStream/a_Body.hpp"
#endif

template <class Traits> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is , Arg& arg , ARGS&... args ) { return VariadicCin( is >> arg , args... ); }
template <class Traits> inline basic_istream<char,Traits>& VariadicSet( basic_istream<char,Traits>& is , const int& i ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicSet( basic_istream<char,Traits>& is , const int& i , Arg& arg , ARGS&... args ) { return VariadicSet( is >> arg[i] , i , args... ); }

template <class Traits> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator , Arg& arg , ARGS&... args ) { return VariadicGetline( getline( is , arg , separator ) , separator , args... ); }

template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , Arg&& arg ) { return os << forward<Arg>( arg ); }
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , Arg1&& arg1 , Arg2&& arg2 , ARGS&&... args ) { return VariadicCout( os << forward<Arg1>( arg1 ) << " " , forward<Arg2>( arg2 ) , forward<ARGS>( args )... ); }

template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCoutNonSep( basic_ostream<char,Traits>& os , Arg&& arg ) { return os << forward<Arg>( arg ); }
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCoutNonSep( basic_ostream<char,Traits>& os , Arg1&& arg1 , Arg2&& arg2 , ARGS&&... args ) { return VariadicCoutNonSep( os << forward<Arg1>( arg1 ) , forward<Arg2>( arg2 ) , forward<ARGS>( args )... ); }

template <class Traits , typename ARRAY> inline basic_ostream<char,Traits>& CoutArray( basic_ostream<char,Traits>& os , const int& i_start , const int& i_ulim , ARRAY&& a ) { for( int i = i_start ; i < i_ulim ; i++ ){ ( i == i_start ? os : ( os << " " ) ) << a[i]; } return os; }
