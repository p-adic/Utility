// c:/Users/user/Documents/Programming/Utility/VLArray/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "Entry/a.hpp"

#include "a_Alias.hpp"

template <typename T> class IteratorOfVLArray;
template <typename T> class ConstIteratorOfVLArray;
template <typename Arg> class WrappedType;

template <typename T>
class VLArray
{

private:
  EntryOfVLArray<T> m_e;
  EntryOfVLArray<T>* const m_p_e;
  uint m_size;

  EntryOfVLArray<T>* m_p_last;
  EntryOfVLArray<T>** m_p_p_last;
  uint m_i_last;
  uint* m_p_i_last;

public:
  // T�͈���0�̃R���X�g���N�^�����N���X�̂݋��e�B
  inline VLArray();
  template <typename Arg1 , typename... Arg2> inline VLArray( const Arg1& , const Arg2&... );
  inline VLArray( const VLArray<T>& );

  // T������0�̃R���X�g���N�^�������Ȃ��N���X�̏ꍇ�Ɏg�p�B
  template <typename Arg> inline VLArray( const WrappedType<Arg>& t );
  
  virtual ~VLArray();
  
  VLArray<T>& operator=( const VLArray<T>& );
  
  inline const uint& size() const noexcept;
  inline void clear();
  inline bool empty() const noexcept;
  T& front();
  const T& front() const;
  T& back();
  const T& back() const;
  
  template <typename Arg> void push_back( const Arg& );
  template <typename... Args> void push_back( const Args&... );
  template <typename Arg> void push_front( const Arg& );
  // �O���珇��push_front����B
  template <typename... Args> void push_front( const Args&... );
  void pop_back();
  void pop_front();

  template <typename... Args> inline void Concatenate( const Args&... );
  template <typename Arg> void Concatenate_back( const Arg& );
  template <typename... Args> void Concatenate_back( const Args&... );
  template <typename Arg> void Concatenate_front( const Arg& );
  // �O���珇��Concatenate_front����B
  template <typename... Args> void Concatenate_front( const Args&... );

  using iterator = IteratorOfVLArray<T>;
  using const_iterator = ConstIteratorOfVLArray<T>;

  // *this��const�ł���ꍇ�Ɋm����const_iterator�Ԃ������邽�߂ɁAiterator�Ԃ��͔�const�ɂ���K�v������B
  inline iterator begin() noexcept;
  inline const_iterator begin() const noexcept;
  inline iterator end() noexcept;
  inline const_iterator end() const noexcept;
  // insert_front�Ɠ���
  template <typename Arg> inline iterator insert( const iterator& , const Arg& );
  template <typename Arg> iterator insert_front( const iterator& , const Arg& );
  template <typename Arg> iterator insert_back( const iterator& , const Arg& );
  // erase_back�Ɠ���
  inline iterator erase( iterator& );
  iterator erase_back( iterator& );
  iterator erase_front( iterator& );

  T& operator[]( const uint& );
  const T& operator[]( const uint& ) const;
  VLArray<T> GetInitialSegment( const int& ) const;
  VLArray<T> GetFinalSegment( const int& ) const;

  bool CheckContain( const iterator& ) const noexcept;
  bool CheckContain( const const_iterator& ) const noexcept;

  string Display() const noexcept;

private:
  template <typename Arg> inline int push_back_int( const Arg& );
  template <typename Arg> inline int push_front_int( const Arg& );
  template <typename Arg> inline int Concatenate_back_int( const Arg& );
  template <typename Arg> inline int Concatenate_front_int( const Arg& );

  template <typename... Args> static inline void ExpandParameterPack( const Args&... ) noexcept;

};


template <typename T> bool operator==( const VLArray<T>& , const VLArray<T>& );
template <typename T> inline bool operator!=( const VLArray<T>& , const VLArray<T>& );

template <typename T> VLArray<T> to_VLArray( const uint& , const T& );
template <typename T> inline VLMatrix<1,T> to_VLMatrix( const uint& , const T& );
template <typename T> inline VLMatrix<2,T> to_VLMatrix( const uint& , const uint& , const T& );
template <typename T> inline VLMatrix<3,T> to_VLMatrix( const uint& , const uint& , const uint& , const T& );

template <typename T , typename... Arg> VLArray<T> Frown( const Arg&... );
template <typename T> T Sum( const VLArray<T>& );
