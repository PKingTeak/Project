#include <iostream>
#include <map>
#include <ConsoleEngine/EngineDebug.h>

typedef int KeyType;
typedef int DataType;

// ��Ʈ ���� �θ� ���ٴ� ���� ����ؾ� �Ѵ�.
// delete this;

class MyPair
{
public:
	MyPair()
	{

	}

	MyPair(KeyType _first, DataType _second)
		: Key(_first), Value(_second)
	{

	}
	~MyPair()
	{
		
	}

	KeyType Key = KeyType();
	DataType Value = DataType();


};

// template<typename KeyType, typename ValueType>
class MyMap
{
private:
	class MapNode
	{
	public:
		MyPair Pair;
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;

		bool containsNode(const KeyType& _Key)
		{
			if (this->Pair.Key == _Key)
			{
				return true;
			}

			if (this->Pair.Key > _Key)
			{
				if (nullptr != this->LeftChild)
				{
					// ���ϰ� ���ÿ� ��͸� �ϴ°��� ���� ��Ͷ�� �մϴ�.
					// �����Ϸ��� �����ϴٸ� while�� �������� �ٲ�����ϴ�.
					// inline�̶� ����ϰ� �����ض�. 
					return this->LeftChild->containsNode(_Key);
				}
			}

			if (this->Pair.Key < _Key)
			{
				if (nullptr != this->RightChild)
				{
					return this->RightChild->containsNode(_Key);
				}
			}

			return false;
		}

		void Release()
		{
			if (nullptr != Parent)
			{
				// ���� �ڽ��̾��ٴ� ��
				if (Parent->LeftChild == this)
				{
					Parent->LeftChild = nullptr;
				}

				if (Parent->RightChild == this)
				{
					Parent->RightChild = nullptr;
				}
			}
		}

		MapNode* minnode()
		{
			if (nullptr == this->LeftChild)
			{
				return this;
			}

			return LeftChild->minnode();
		}

		MapNode* maxnode()
		{
			if (nullptr == this->RightChild)
			{
				return this;
			}

			return RightChild->maxnode();
		}

		// ��ͷε� ����� �ִµ� while�� �غô�.
		MapNode* OverParent()
		{
			MapNode* PNode = Parent;

			while (PNode)
			{
				if (PNode->Pair.Key > Pair.Key)
				{
					return PNode;
				}

				PNode = PNode->Parent;
			}

			return nullptr;
		}

		MapNode* SmallParent()
		{
			MapNode* PNode = Parent;

			while (PNode)
			{
				if (PNode->Pair.Key < Pair.Key)
				{
					return PNode;
				}

				PNode = PNode->Parent;
			}

			return nullptr;
		}

		void firstOrderPrint()
		{
			// ������ �� �տ��� ��.
			//std::cout << Pair.Key << std::endl;
			
			if (nullptr != LeftChild)
			{
				LeftChild->firstOrderPrint();
				
			}
			if (nullptr != RightChild)
			{
				RightChild->firstOrderPrint();
				
			}

			return;
		}

		void midOrderPrint()
		{
			
			if (nullptr != LeftChild)
			{
				//LeftChild->midOrderPrint();
				
			}
			//std::cout << Pair.Key << std::endl;
			
			if (nullptr != RightChild)
			{
				//RightChild->midOrderPrint();
				
			}
			return;
		}

	void lastOrderPrint()
	{
		if (nullptr != LeftChild)
		{
			LeftChild->lastOrderPrint();
			delete LeftChild;
		}
		if (nullptr != RightChild)
		{
			RightChild->lastOrderPrint();
			delete RightChild;
		}
		//std::cout << Pair.Key << std::endl;
		delete this;
		return;
	}
	

		MapNode* NextNode()
		{
			if (nullptr != this->RightChild)
			{
				return this->RightChild->minnode();
			}

			// �θ��߿� �����Ѵ�.
			return OverParent();
		}

		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}


		MapNode* PrevNode()
		{
			if (nullptr != this->LeftChild)
			{
				return this->LeftChild->maxnode();
			}

			// �θ��߿� �����Ѵ�.
			return SmallParent();
		}

		MapNode* findNode(const KeyType& _Key)
		{
			if (this->Pair.Key == _Key)
			{
				return this;
			}

			if (this->Pair.Key > _Key)
			{
				if (nullptr != this->LeftChild)
				{
					// ���ϰ� ���ÿ� ��͸� �ϴ°��� ���� ��Ͷ�� �մϴ�.
					// �����Ϸ��� �����ϴٸ� while�� �������� �ٲ�����ϴ�.
					// inline�̶� ����ϰ� �����ض�. 
					return this->LeftChild->findNode(_Key);
				}
			}

			if (this->Pair.Key < _Key)
			{
				if (nullptr != this->RightChild)
				{
					return this->RightChild->findNode(_Key);
				}
			}


			return nullptr;
		}

		void insertNode(MapNode* _Node)
		{
			_Node->Parent = this;
			//        10              5
			if (this->Pair.Key > _Node->Pair.Key)
			{
				if (nullptr == this->LeftChild)
				{
					this->LeftChild = _Node;
					return;
				}

				this->LeftChild->insertNode(_Node);
			}

			if (this->Pair.Key < _Node->Pair.Key)
			{
				if (nullptr == this->RightChild)
				{
					this->RightChild = _Node;
					return;
				}

				this->RightChild->insertNode(_Node);
			}

			return;
		}
	};


public:
	class iterator
	{
		friend MyMap;

	public:
		iterator()
		{
		}

		iterator(MapNode* _CurNode)
			: CurNode(_CurNode)
		{
		}

		MyPair* operator->()
		{
			MyPair& MapPair = CurNode->Pair;
			return &MapPair;
		}

		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		void operator++()
		{
			CurNode = CurNode->NextNode();
			return;
		}

	private:
		MapNode* CurNode = nullptr;
	};

	// map�� �ڷᰡ �������϶� ȿ���� �����մϴ�.
	// �ڷᰡ Ư�� �������� �̹� ���ĵ� ���·� ���ٸ� ��κ� ��δ� �ʺ��� ������.
	void insert(const MyPair& _Value)
	{
		MapNode* NewNode = new MapNode();
		NewNode->Pair = _Value;

		// Ʈ���� �⺻�� �Ѹ�
		// ������ ���� ������ �Ѹ� ��尡 �ɼ��ۿ� ����.
		// ���ʿ��� root�� nullptr�̶�� 
		if (nullptr == Root)
		{
			Root = NewNode;
			return;
		}

		Root->insertNode(/*Root, */NewNode);
	}

	bool contains(const KeyType& _Key)
	{
		if (nullptr == Root)
		{
			return false;
		}

		// �ȵɼ��� �ִ�.
		return Root->containsNode(_Key);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	iterator erase(iterator& _Iter)
	{
		iterator Return;

		if (nullptr == _Iter.CurNode)
		{
			MsgBoxAssert("��ȿ���� ���� ���Ҹ� �����Ϸ��� �߽��ϴ�.");
			return Return;
		}

		MapNode* NextNode = _Iter.CurNode->NextNode();

		Return.CurNode = NextNode;

		// �ϴ� ó���Ǹ� ������ 
		if (true == _Iter.CurNode->IsLeaf())
		{
			MapNode* ParentNode = _Iter.CurNode->Parent;
			_Iter.CurNode->Release();
			delete _Iter.CurNode;
			return Return;
		}

		// ��ü�� ����� �Ѵ�.
		// �ڽ��� �ϳ��� �ִ� ����̴�.
		MapNode* ChangeNode = nullptr;
		MapNode* CurNode = _Iter.CurNode;

		ChangeNode = CurNode->RightChild->minnode();
		if (nullptr == ChangeNode)
		{
			ChangeNode = CurNode->LeftChild->maxnode();
		}

		if (nullptr == ChangeNode)
		{
			MsgBoxAssert("ü���� ��� ����.");
			return Return;
		}
		ChangeNode->Release();

		MapNode* LeftChild = CurNode->LeftChild;
		MapNode* RightChild = CurNode->RightChild;

		if (nullptr != LeftChild)
		{
			LeftChild->Parent = nullptr;
		}

		if (nullptr != RightChild)
		{
			RightChild->Parent = nullptr;
		}

		if (nullptr != LeftChild)
		{
			LeftChild->Parent = ChangeNode;
			if (CurNode->LeftChild != ChangeNode)
			{
				ChangeNode->LeftChild = LeftChild;
			}
		}

		if (nullptr != RightChild)
		{
			RightChild->Parent = ChangeNode;
			if (CurNode->RightChild != ChangeNode)
			{
				ChangeNode->RightChild = RightChild;
			}
		}

		ChangeNode->Parent = CurNode->Parent;
		MapNode* Parent = ChangeNode->Parent;
		if (nullptr != Parent && Parent->LeftChild == CurNode)
		{
			Parent->LeftChild = ChangeNode;
		}

		if (nullptr != Parent && Parent->RightChild == CurNode)
		{
			Parent->RightChild = ChangeNode;
		}

		if (Root == CurNode)
		{
			Root = ChangeNode;
		}

		delete CurNode;

		return Return;

	}


	iterator find(const KeyType& _Key)
	{
		if (nullptr == Root)
		{
			return end();
		}

		// �ȵɼ��� �ִ�.
		return iterator(Root->findNode(_Key));
	}

	iterator begin()
	{
		if (nullptr == Root)
		{
			return end();
		}

		// �ȵɼ��� �ִ�.
		return iterator(Root->minnode());
	}

	void firstOrderPrint()
	{
		Root->firstOrderPrint();
		return;
	}

	void midOrderPrint()
	{
		Root->midOrderPrint();
	
		return;
	}

	void lastOrderPrint()
	{
		Root->lastOrderPrint();
		return;
	}



	MapNode* Root = nullptr;
};


int main()
{
	LeckCheck;

	{
		std::cout << "std ��" << std::endl;

		//      Key   Value
		std::map<int, int> NewMap = std::map<int, int>();

		// �̰� Map�� �ڷḦ �߰��ϴ� ��� 1�Դϴ�.
		// ����� ���� 5�� �˴ϴ�.
		{
			// ���� �ڵ����� �������� ������ �ȴ�.
			// ��� 1 Pair�� �ϴ¹�
			//NewMap.insert(std::pair<int, int>(5, 12345648915));

			// ��� 2 make_pair
			//NewMap.insert(std::make_pair(2, 12345648915));

			// �迭 3 �迭 ������ ��
			//NewMap[3] = 1;

			// std::map<int, int>::value_type == std::pair<int, int>
			// ��� 4 
			//NewMap.insert(std::map<int, int>::value_type(7, 10));
		}

		// �������� ������ => ū���� ������ �˴ϴ�.
		NewMap.insert(std::pair<int, int>(10, 0));
		NewMap.insert(std::pair<int, int>(10, 2));
		NewMap.insert(std::pair<int, int>(5, 0));
		NewMap.insert(std::pair<int, int>(15, 0));
		NewMap.insert(std::pair<int, int>(12, 0));
		NewMap.insert(std::pair<int, int>(3, 0));
		NewMap.insert(std::pair<int, int>(7, 0));

		// C++20������ ��밡��
	//	if (true == NewMap.contains(15))
	//	{
	//		int a = 0;
	//		// �ִ�.
	//	}
	//
		std::map<int, int>::iterator FindIter = NewMap.find(15);
		NewMap.erase(FindIter);

		//if (NewMap.end() != NewMap.find(15))
		//{
		//}

		//if (FindIter != NewMap.end())
		//{
		//	// �ִ�.
		//}

		// ���� ��ȸ�����°� ȿ������ ���� �ƴϿ���.
		// ������ �������� ����������
		std::map<int, int>::iterator StartIter = NewMap.begin();
		std::map<int, int>::iterator EndIter = NewMap.end();

		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; StartIter != EndIter
			; ++StartIter)
		{
			std::cout << "Key : " << StartIter->first << std::endl;
			// std::cout << "Value : " << StartIter->second << std::endl;
		}
	}

	{
		std::cout << "�� ��" << std::endl;
		//      Key   Value
		MyMap NewMap = MyMap();

		// �������� ������ => ū���� ������ �˴ϴ�.
		NewMap.insert(MyPair(10, 0));
		NewMap.insert(MyPair(5, 0));
		NewMap.insert(MyPair(15, 0));
		NewMap.insert(MyPair(12, 99));
		NewMap.insert(MyPair(3, 0));
		NewMap.insert(MyPair(7, 0));

		if (true == NewMap.contains(12))
		{
			int a = 0;
		}


		//MyMap::iterator FindIter =  NewMap.find(12);
		//std::cout << "Key : " << FindIter->Key << std::endl;
		//std::cout << "Value : " << FindIter->Value << std::endl;

		//MyMap::iterator FindIter = NewMap.find(10);
		//NewMap.erase(FindIter);

		std::cout << "first" << std::endl;
		NewMap.firstOrderPrint();
		std::cout << "mid" << std::endl;
		NewMap.midOrderPrint();
		std::cout << "last" << std::endl;
		NewMap.lastOrderPrint();

		//MyMap::iterator StartIter = NewMap.begin();
		//MyMap::iterator EndIter = NewMap.end();



		//for (/*std::list<int>::iterator StartIter = NewList.begin()*/
		//	; StartIter != EndIter
		//	; ++StartIter)
		//{
		//	std::cout << StartIter->Key << std::endl;
		//	//std::cout << StartIter->second << std::endl;
		//}
	}
}
