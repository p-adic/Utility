// c:/Users/user/Documents/Programming/Utility/VLTree/SubTree/a.hpp

#pragma once
#include "../Entry/a.hpp"
#include "../Iterator/a.hpp"
#include "../../WrappedType/a.hpp"

template <typename T> class VLTree;
template <typename T> class EntryOfUnionFindForest;
template <typename T> class UnionFindForest;

template <typename T>
class VLSubTree
{

  friend VLTree<T>;
  friend EntryOfUnionFindForest<T>;
  friend UnionFindForest<T>;
  
private:
  EntryOfVLTree<T> m_e;
  // �ʏ��m_e���w�����AVLSubTree( EntryOfVLTree<T>& )��
  // VLSubTree( const IteratorOfVLTree<T>& )�o�R�ŌĂяo���ꂽ�ꍇ�̂�
  // �Q�ƌ���Node���w���B
  EntryOfVLTree<T>* m_p_root;
  uint m_size;

private:
  // T�͈���0�̃R���X�g���N�^�����N���X�̂݋��e�B
  // �f�X�g���N�^��delete���Z�q���Ă΂Ȃ����߁AVLTree��Forest�o�R�ł����Ăяo���Ă͂����Ȃ��B
  inline VLSubTree();

  // T�͈���0�̃R���X�g���N�^�����N���X�̂݋��e�B
  // root�݂̖̂؂Ɉ���������push_RightMost���č��Xm_size == 1�̖؂��\�z����B
  // �f�X�g���N�^��delete���Z�q���Ă΂Ȃ����߁AVLTree�o�R�ł����Ăяo���Ă͂����Ȃ��B
  template <typename Arg1 , typename... Arg2> inline VLSubTree( const Arg1& , const Arg2&... );
  
  // T������0�̃R���X�g���N�^�������Ȃ��N���X�̏ꍇ�Ɏg�p�B
  // �f�X�g���N�^��delete���Z�q���Ă΂Ȃ����߁AVLTree�o�R�ł����Ăяo���Ă͂����Ȃ��B
  template <typename Arg> inline VLSubTree( const WrappedType<Arg>& t );

  // �\�z���ꂽ�؂ւ̕ύX���R�s�[���ւ͔��f����Ȃ��B
  // �f�X�g���N�^��delete���Z�q���Ă΂Ȃ����߁AVLTree�o�R�ł����Ăяo���Ă͂����Ȃ��B
  // Substriture_Body���o�R���邽�߁A���g�ւ̕ύX�������ւ͔��f����Ȃ��B
  // ������VLSubConstTree<T>�ɂ������̂��`���ĈϏ�����ƃ��[�v���Ă��܂��B
  inline VLSubTree( const VLSubTree<T>& );

  // �\�z���ꂽ�؂ւ̕ύX���R�s�[���ւ͔��f�����B
  // VLTree���o�R���Ȃ��Ă��Ăяo���ėǂ��B
  // VLTree���o�R���Ă͂Ȃ�Ȃ��B
  inline VLSubTree( EntryOfVLTree<T>& );
  inline VLSubTree( const IteratorOfVLTree<T>& );
  
  // �\�z���ꂽ�؂ւ̕ύX���R�s�[���ւ͔��f����Ȃ��B
  // �f�X�g���N�^��delete���Z�q���Ă΂Ȃ����߁AVLTree�o�R�ł����Ăяo���Ă͂����Ȃ��B
  // int�̓_�~�[�����B
  inline VLSubTree( const int& , const EntryOfVLTree<T>& );
  inline VLSubTree( const int& , const ConstIteratorOfVLTree<T>& );

  // �����؂̃R�s�[���\�z����push_RightMostNode�ő}�����邽�߁A���g�ւ̕ύX�������ւ͔��f����Ȃ��B
  // LeafToTree��push_RightMost��Concatenate�̑��ݍċA�B
  // m_size == 0�̎������Ă�ł͂����Ȃ��B
  void LeafToTree( const VLSubTree<T>& );

  // �V����RightMostNode���\�z���A�����𕔕��؂�Root�Ƃ��Č�������B
  // �\�z���ꂽ�؂ւ̕ύX���R�s�[���֔��f�����B
  // Forest�o�R�ł����Ăяo���Ă͂����Ȃ��B
  void Graft( VLSubTree<T>& );

  
public:
  virtual ~VLSubTree() = default;

  // Substriture_Body���o�R���邽�߁A���������g�ƓƗ��ł�������΁A���g�ւ̕ύX�������ւ͔��f����Ȃ��B
  // CutBranches���Ăяo�����߁A���������g�ƓƗ��łȂ��ꍇ�́A���g�ւ̕ύX�������֔��f���ꂤ���ɁASegmentation Fault�������N�����\��������B
  // ������VLTree<T>�ɂ������̂��`���ČĂяo���ƃ��[�v���Ă��܂��B
  VLSubTree<T>& operator=( const VLSubTree<T>& );
  
  inline const uint& size() const noexcept;
  inline void CutBranches();
  inline bool IsLeaf() const noexcept;

  // �����؂��\�z���ĕԂ����߁A�����؂ւ̕ύX�����g�ւ����f�����B
  inline VLSubTree<T> LeftMostSubTree();
  inline VLSubTree<T> RightMostSubTree();
  
  // �����؂̃R�s�[���\�z���ĕԂ����߁A�����؂ւ̕ύX�����g�ւ͔��f����Ȃ��B
  inline VLTree<T> LeftMostSubTreeCopy() const;
  inline VLTree<T> RightMostSubTreeCopy() const;
  
  // LeafToTree��push_RightMost��Concatenate�̑��ݍċA�B
  inline void push_RightMost() const noexcept;
  template <typename Arg1 , typename... Arg2> void push_RightMost( const Arg1& , const Arg2&... );
  template <typename... Args> void push_RightMost( const VLTree<T>& , const Args&... );
  template <typename Arg> void push_LeftMost( const Arg& );
  
  void pop_RightMost();
  void pop_LeftMost();

  // m_size == 1�i����m_p_root->m_leftmost_node== m_p_root->m_rightmost_node�j�̎������Ă�ł͂Ȃ�Ȃ��B
  // m_p_root��delete�\�Ƃ͌���Ȃ����߁A����ɒl�̂����������s�����ۂ�delete�����̂�m_p_root�łȂ�m_p_root->m_leftmost_node�ł���B
  // �]���ē���iterator�̏����ɒ��ӂ��K�v�B
  void pop_Root();

  using iterator = IteratorOfVLTree<T>;
  using const_iterator = ConstIteratorOfVLTree<T>;

  // *this��const�ł���ꍇ�Ɋm����const_iterator�Ԃ������邽�߂ɁAiterator�Ԃ��͔�const�ɂ���K�v������B
  inline iterator LeftMostNode() noexcept;
  inline const_iterator LeftMostNode() const noexcept;
  inline iterator RightMostNode() noexcept;
  inline const_iterator RightMostNode() const noexcept;
  iterator LeftMostLeaf() noexcept;
  const_iterator LeftMostLeaf() const noexcept;
  iterator RightMostLeaf() noexcept;
  const_iterator RightMostLeaf() const noexcept;
  inline iterator Root() noexcept;
  inline const_iterator Root() const noexcept;
  template <typename... Args> inline iterator GetIterator( const Args&... );
  template <typename... Args> inline const_iterator GetIterator( const Args&... ) const;

  // iterator�̉E�ɐV����Leaf���\�z����B
  template <typename Arg> void insert( const iterator& , const Arg& );

  // RightMost�ł���ꍇ��root�ւ̃C�e���[�^��Ԃ��B
  iterator erase( iterator& );

  // Root��Node�̃��x���ɒ��ړǂݏ������s���B
  inline const T& GetRoot() const noexcept;
  inline T& RefRoot() noexcept;
  inline void SetRoot( const T& );
  template <typename... Args> inline const T& GetNode( const Args&... ) const;

  // �����؂��\�z���ĕԂ����߁A�����؂ւ̕ύX�����g�ւ����f�����B
  VLSubTree<T> operator[]( const uint& );
  VLSubTree<T> operator[]( iterator& );
  
  // �����؂̃R�s�[���\�z���ĕԂ����߁A�����؂ւ̕ύX�����g�ւ͔��f����Ȃ��B
  VLTree<T> operator[]( const const_iterator& ) const;
  VLTree<T> GetBranchCopy( const uint& ) const;
  VLTree<T> GetBranchCopy( const iterator& ) const;
  VLTree<T> GetBranchCopy( const const_iterator& ) const;

  // ���݂�RightMostNode��iterator�̎w���ʒu�𕔕��؂�Root�Ƃ��ăR�s�[���\�z����B
  // �\�z���ꂽ�؂ւ̕ύX���R�s�[���ւ͔��f����Ȃ��B
  // LeafToTree��push_RightMost��Concatenate�̑��ݍċA�B
  void Concatenate( const VLTree<T>& );
  void Concatenate( const iterator& , const VLTree<T>& );

  bool CheckContain( const iterator& ) const noexcept;
  bool CheckContain( const const_iterator& ) const noexcept;
  string Display() const;
  
};

template <typename T> bool operator==( const VLTree<T>& , const VLTree<T>& );
template <typename T> inline bool operator!=( const VLTree<T>& , const VLTree<T>& );
