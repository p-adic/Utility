// c:/Users/user/Documents/Programming/Utility/StdStream/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <unistd.h>

class StdStream
{

private:
  using CharT = char;
  using Traits = char_traits<CharT>;
  // �茳�̊�����g_length_lim = 1000000�ł�Terminal�������I������B
  #ifdef DEBUG
    static constexpr int g_length_lim = 100000;
  #else
    static constexpr int g_length_lim = 1000000;
  #endif
  static constexpr int g_length_max = g_length_lim - 1;
  static constexpr CharT g_space = ' ';
  static constexpr CharT g_new_line = '\n';
  static constexpr CharT g_minus = '-';
  static constexpr CharT g_zero = '0';

  static int g_length;
  static int g_head;
  static basic_streambuf<CharT>::int_type g_code;
  static CharT g_c;
  static CharT g_buffer[g_length_lim];
  
public:
  StdStream() = delete;
  DECLARATION_OF_SCAN( int );
  DECLARATION_OF_SCAN( uint );
  DECLARATION_OF_SCAN( ll );
  DECLARATION_OF_SCAN( ull );
  DECLARATION_OF_SCAN( string );
  
private:
  // basic_istream::read()����try/catch�u���b�N��iostate�̍X�V���폜����read�֐�
  static inline void Load();
  static inline void ShiftHead();
  static inline void ReadHead();

};
