// c:/Users/user/Documents/Programming/Utility/List/Labeled/a.hpp

#pragma once
#include "../../VLArray/a.hpp"
#include "../../../Mathematics/SetTheory/DirectProduct/a.hpp"

template <typename T , typename Key1 , typename... Key2>
class LabeledList
{

private:
  VLArray<DirectProduct<DirectProduct<Key1,Key2...>,T> > m_v;
  
public:
  inline LabeledList();
  // ofstream�̂悤�ɃR�s�[�R���X�g���N�^�������Ȃ��^T���g���������͑����SartPointer<T>��p���A���̃R���X�g���N�^��K�p����WrappedType<DirectProduct<DirectProduct<Key1,Key2...>,SmartPointer<T> > >��n���B
  inline LabeledList( const WrappedType<DirectProduct<DirectProduct<Key1,Key2...>,T> >& );
  
  inline const VLArray<DirectProduct<DirectProduct<Key1,Key2...>,T> >& Get() const noexcept;
  T& operator()( const Key1& , const Key2&... );
  const T& operator()( const Key1& , const Key2&... ) const;
  inline void Insert( const Key1& , const Key2&... , const T& );
  void Delete( const Key1& , const Key2&... );
  bool Contain( const Key1& , const Key2&... ) const;

  // Contain�łȂ��Ȃ��insert�����A���̌�operator()������B
  T& RefInsert( const Key1& , const Key2&... , const T& );

  
  // �ȉ�bool operator<( const DirectProduct<Key1,Key2...>& , const DirectProduct<Key1,Key2...>& )����`����Ă��鎞�̂ݎ��̉��\
  void SortKey( const string& method = "normal" , const VLArray<int>& option = VLArray<int>() );

};

template <typename T , typename Key1 , typename... Key2> inline bool operator<( const DirectProduct<DirectProduct<Key1,Key2...>,T>& , const DirectProduct<DirectProduct<Key1,Key2...>,T>& );
