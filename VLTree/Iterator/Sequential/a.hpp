// c:/Users/user/Documents/Programming/Utility/VLTree/Iterator/Sequential/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../VLArray/a.hpp"

template <typename T> class SequentialConstIteratorOfVLTree;

template <typename T>
class SequentialIteratorOfVLTree :
  public IteratorOfVLTree<T>
{

  // �L���X�g�p�̃R���X�g���N�^�ɂ̂ݗp����B
  friend SequentialConstIteratorOfVLTree<T>;

private:
  VLArray<IteratorOfVLTree<T> > m_itr;

public:
  inline SequentialIteratorOfVLTree( const IteratorOfVLTree<T>& );
  inline SequentialIteratorOfVLTree( const SequentialIteratorOfVLTree<T>& );
  
  inline SequentialIteratorOfVLTree<T>& operator=( const IteratorOfVLTree<T>& );
  inline SequentialIteratorOfVLTree<T>& operator=( const SequentialIteratorOfVLTree<T>& );
  void operator[]( const int& );

  inline T& Access_Body( const char* const , const int& , const char* const , const string& , const uint& ) const;
  inline T& Ref( const uint& ) const;
  inline const T& Get( const uint& ) const;

  inline void pop_front();
  void erase_back( VLSubTree<T>& );
  
  bool CheckContained( const VLSubTree<T>& ) const;

  inline uint size() const noexcept;

private:
  static void erase_back_Body( VLSubTree<T>& , SequentialIteratorOfVLTree<T>& );
  static bool CheckContained_Body( const VLSubTree<T>& , const SequentialIteratorOfVLTree<T>& );

};

template <typename T>
class SequentialConstIteratorOfVLTree :
  public ConstIteratorOfVLTree<T>
{

private:
  VLArray<ConstIteratorOfVLTree<T> > m_itr;

public:
  inline SequentialConstIteratorOfVLTree( const ConstIteratorOfVLTree<T>& );
  inline SequentialConstIteratorOfVLTree( const SequentialConstIteratorOfVLTree<T>& );
  SequentialConstIteratorOfVLTree( const SequentialIteratorOfVLTree<T>& );
  
  inline SequentialConstIteratorOfVLTree<T>& operator=( const ConstIteratorOfVLTree<T>& );
  inline SequentialConstIteratorOfVLTree<T>& operator=( const SequentialConstIteratorOfVLTree<T>& );
  void operator[]( const int& );


  inline const T& Access_Body( const char* const , const int& , const char* const , const string& , const uint& ) const;
  inline const T& Get( const uint& ) const;

  inline void pop_front();

  bool CheckContained( const VLSubTree<T>& ) const;

  inline uint size() const noexcept;

private:
  static bool CheckContained_Body( const VLSubTree<T>& , const SequentialConstIteratorOfVLTree<T>& );

};

// �}�N��ACCESS( itr )���g���B
template <typename T> inline T& Access( const char* const , const int& , const char* const , const string& , const SequentialIteratorOfVLTree<T>& , const uint& );
template <typename T> inline const T& Access( const char* const , const int& , const char* const , const string& , const SequentialConstIteratorOfVLTree<T>& , const uint& );
