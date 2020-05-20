#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

static const int __stl_num_primes = 28;
static const unsigned long __stl_prime_list[__stl_num_primes] =
{
	53, 97, 193, 389, 769,
	1543, 3079, 6151, 12289, 24593,
	49157, 98317, 196613, 393241, 786433,
	1572869, 3145739, 6291469, 12582917, 25165843,
	50331653, 100663319, 201326611, 402653189, 805306457,
	1610612741, 3221225473ul, 4294967291ul
};
inline unsigned long __stl_next_prime(unsigned long n)
{
  const unsigned long* first = __stl_prime_list;
  const unsigned long* last = __stl_prime_list + __stl_num_primes;
  const unsigned long* pos = lower_bound(first, last, n);
  return pos == last ? *(last - 1) : *pos;
}


template <class Value>
struct __hashtable_node
{
	__hashtable_node* next;
	Value val;
};

template <class Key, class Value>
class hashtable 
{
public:
	typedef __hashtable_node<Value> node;
	typedef size_t size_type;
	typedef Value  value_type;
public:
	hashtable(size_type n) :num_elements(0)
	{
		initialize_buckets(n);
	}
public:
	bool insert_unique(const value_type& obj)
	{

		return insert_unique_noresize(obj);
	}
	bool insert_unique_noresize(const value_type& obj)
	{
		const size_type n = bkt_num(obj);
		node* first = buckets[n];

		for (node* cur = first; cur; cur = cur->next)
		if(cur->val == obj)
			return false;

		node* tmp = new_node(obj);
		tmp->next = first;
		buckets[n] = tmp;
		++num_elements;
		return true;
	}
private:
	size_type bkt_num(const value_type& obj) const
	{
		return obj % buckets.size();
	}
	node* new_node(const value_type& obj)
	{
		node* n = (node*)malloc(sizeof(node));
		n->next = 0;
		n->val = obj;
		return n;
	}
	size_type next_size(size_type n) const 
	{
		return __stl_next_prime(n); 
	}
	void initialize_buckets(size_type n)
	{
		const size_type n_buckets = next_size(n);
		buckets.reserve(n_buckets);
		buckets.insert(buckets.end(), n_buckets, (node*)0);
		num_elements = 0;
	}
private:
	vector<node*> buckets;
	size_type num_elements;
};

void main()
{
	hashtable<int, int> ht(53); //int-string
	ht.insert_unique(1);
	ht.insert_unique(54);
}

////////////////////////////////////////////////////////////////////////////////
/*
const int PRIMECOUNT = 28;
const size_t primeList[PRIMECOUNT] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};
size_t GetNextPrime(size_t prime)
{
	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] >= prime)
			return primeList[i];
	}
	return primeList[i];
}
///////////////////////////////////////////////////////////////

template<class V>
struct HashBucketNode
{
	HashBucketNode(const V& data): _pNext(nullptr), _data(data)
	{}
	HashBucketNode<V>* _pNext;
	V _data;
};

template<class V>
class HashBucket
{
	typedef HashBucketNode<V> Node;
	typedef Node* PNode;
public:
	HashBucket(size_t capacity = 3) : _size(0)
	{
		_ht.resize(GetNextPrime(capacity), nullptr);
	}
public:
	PNode* Insert(const V& data)
	{
		// 确认是否需要扩容。。。
		// _CheckCapacity();
		// 1. 计算元素所在的桶号
		size_t bucketNo = HashFunc(data);
		// 2. 检测该元素是否在桶中
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;
			pCur = pCur->_pNext;
		}
		// 3. 插入新元素
		pCur = new Node(data);
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		_size++;
		return pCur;
	}

	PNode* Erase(const V& data)
	{
		size_t bucketNo = HashFunc(data);
		PNode pCur = _ht[bucketNo];
		PNode pPrev = nullptr, pRet = nullptr;
		while (pCur)
		{
			if (pCur->_data == data)
			{
				if (pCur == _ht[bucketNo])
					_ht[bucketNo] = pCur->_pNext;
				else
					pPrev->_pNext = pCur->_pNext;
				pRet = pCur->_pNext;
				delete pCur;
				_size--;
				return pRet;
			}
		}
		return nullptr;
	}
public:
	PNode* Find(const V& data);
	size_t Size()const;
	bool Empty()const;
	void Clear();
	bool BucketCount()const
	{
		return _ht.capacity();
	}
	void Swap(HashBucket<V, HF>& ht;
	~HashBucket();
private:
	size_t HashFunc(const V& data)
	{
		return data%_ht.capacity();
	}
private:
	vector<PNode*> _ht;
	size_t _size; // 哈希表中有效元素的个数
};

void main()
{
	HashBucket<int> ht;
	ht.Insert(4);
	ht.Insert(17);
}

/*
enum State{EMPTY, EXIST, DELETE};

template<class K, class V>
class HashTable
{
	struct Elem
	{
		pair<K, V> _val;   //key-value
		State _state;      //标记
	};
public:
	HashTable(size_t capacity = 3) : _ht(capacity), _size(0)
	{
		for (size_t i = 0; i < capacity; ++i)
			_ht[i]._state = EMPTY;
	}
	bool Insert(const pair<K, V>& val)
	{
		// 检测哈希表底层空间是否充足
		 _CheckCapacity();
		size_t hashAddr = HashFunc(val.first);
		// size_t startAddr = hashAddr;
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == val.first)
				return false;
			hashAddr++;
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
		}
		// 插入元素
		_ht[hashAddr]._state = EXIST;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}
	int Find(const K& key)
	{
		size_t hashAddr = HashFunc(key);
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
				return hashAddr;
			hashAddr++;
			if(hashAddr == _ht.capacity())
				hashAddr = 0;
		}
		return hashAddr;
	}
	bool Erase(const K& key)
	{
		int index = Find(key);
		if (-1 != index)
		{
			_ht[index]._state = DELETE;
			_size--;
			return true;
		}
		return false;
	}
	size_t Size()const
	{
		return _size;
	}
	bool Empty() const
	{
		return _size == 0;
	}
	void Swap(HashTable<K, V>& ht)
	{
		swap(ht._ht, _ht);
		swap(ht._size, _size);
	}
private:
	size_t HashFunc(const K& key)
	{
		return key % _ht.capacity();
	}
	void _CheckCapacity()
	{
		if (_size * 10 / _ht.capacity() >= 7)
		{
			HashTable<K, V> newHt(_ht.capacity() * 2);
			for (size_t i = 0; i < _ht.capacity(); ++i)
			{
				if (_ht[i]._state == EXIST)
					newHt.Insert(_ht[i]._val);
			}
			Swap(newHt);
		}
	}
private:
	vector<Elem> _ht;
	size_t _size;
};

void main()
{
	HashTable<int, string> ht(13);
	ht.Insert(make_pair(1, "abc"));
	ht.Insert(make_pair(3, "xyz"));
	ht.Insert(make_pair(2, "hjk"));

	ht.Insert(make_pair(14, "lmn"));

	int index = ht.Find(14);  // % 13 =1
}

/*
void main()
{
	HashTable<int, string> ht1(13);
	ht1.Insert(make_pair(1, "abc"));

	HashTable<int, string> ht2;
	ht2.Insert(make_pair(2, "xyz"));

	ht1.Swap(ht2);
}

/*
void main()
{
	HashTable<int, string> ht1(13);
	ht1.Insert(make_pair(1, "abc"));
	ht.Insert(make_pair(3, "xyz"));
	ht.Insert(make_pair(2, "hjk"));

	ht.Insert(make_pair(14, "lmn"));
}
*/