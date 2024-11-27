// c:/Users/user/Documents/Programming/Utility/Vector/Linked/a.hpp

#pragma once
#include "Entry/a.hpp"
#include "Iterator/a.hpp"
#include <vector>

template <typename T> class IteratorOfLinkedVector;
template <typename T> class ConstIteratorOfLinkedVector;

template <typename T>
class LinkedVector
{

  friend IteratorOfLinkedVector<T>;
  friend ConstIteratorOfLinkedVector<T>;
  
protected:
  vector<EntryOfLinkedVector<T> > m_entry;
  uint m_front_linked_entry;
  uint m_back_linked_entry;
  uint m_size_of_vector;
  uint m_size_of_link;

public:
  inline LinkedVector();
  // �v�f�₻�̃����o�ւ̃|�C���^�������o�Ɏ�������N���X�ɑ΂��Ă�
  // vector��capacity�𒴂���ۂ̃R�s�[�Ń|�C���^�̎Q�Ɛ悪�����ɂȂ��Ă��܂��̂�
  // �\�ߍő�v�f����ݒ肷��B
  inline LinkedVector( const uint& max_size );

  // vector���i�Ԗڂ̗v�f��Ԃ��B
  inline const T& operator[]( const uint& i ) const;
  inline T& operator[]( const uint& i );

  // link���i�Ԗڂ̗v�f�̍��W��Ԃ��B
  uint GetLinkedEntry( const uint& i ) const;

  inline const uint& GetFrontLinkedEntryIndex() const noexcept;
  inline const uint& GetBackLinkedEntryIndex() const noexcept;
  inline const uint& GetSizeOfVector() const noexcept;
  inline const uint& GetSizeOfLink() const noexcept;

  inline bool EmptyVector() const noexcept;
  inline bool EmptyLink() const noexcept;

  inline void push_back();
  template <typename U> void push_back( const U& u );
  template <typename U , typename... ARGS> inline void push_back( const U& u , const ARGS&... args );

  inline void SetPreviousLink( const uint& i , const uint& j );
  inline void SetNexttLink( const uint& i , const uint& j );
  inline const uint& GetPreviousLinkIndex( const uint& i ) const;
  inline const uint& GetNexttLinkIndex( const uint& i ) const;

  // vector���i�Ԗڂ̗v�f��link��ɂ���ꍇ�̂݃T�|�[�g
  const uint& DeLink( const uint& i );
  // vector���i�Ԗڂ̗v�f��link��ɂȂ��ꍇ�̂݃T�|�[�g
  void ReLink( const uint& i );

  using iterator = IteratorOfLinkedVector<T>;
  using const_iterator = ConstIteratorOfLinkedVector<T>;

  // *this��const�ł���ꍇ�Ɋm����const_iterator�Ԃ������邽�߂ɁAiterator�Ԃ��͔�const�ɂ���K�v������B
  inline iterator GetIterator( const uint& i ) noexcept;
  inline const_iterator GetIterator( const uint& i ) const noexcept;
  inline iterator begin() noexcept;
  inline const_iterator begin() const noexcept;
  inline iterator end() noexcept;
  inline const_iterator end() const noexcept;
  // itr�̎w���v�f��link��ɂ���ꍇ�̂݃T�|�[�g
  iterator erase( iterator& itr );


protected:
  inline EntryOfLinkedVector<T>& push_back_Body_0();
  inline void push_back_Body_1( EntryOfLinkedVector<T>& e );
  
};
