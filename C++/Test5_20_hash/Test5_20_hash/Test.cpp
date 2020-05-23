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

template <class Key, class Value, class HashFcn, class ExtractKey>
class hashtable;

/////////////////////////////////////////////////////////////////////////////////////
template <class Key, class Value, class HashFcn, class ExtractKey>
struct __hashtable_iterator 
{
  typedef hashtable<Key,Value , HashFcn, ExtractKey> hashtable;
  typedef __hashtable_iterator<Key,Value , HashFcn, ExtractKey> iterator;
  typedef __hashtable_node<Value> node;
  typedef Value&  reference;
  typedef Value* pointer;
  typedef size_t size_type;


  node* cur;
  hashtable* ht;

  __hashtable_iterator(node* n, hashtable* tab) : cur(n), ht(tab) 
  {}
  __hashtable_iterator()
  {}
  reference operator*() const 
  {
	  return cur->val; 
  }
  pointer operator->() const 
  {
	  return &(operator*()); 
  }

  iterator& operator++()
  {
	  const node* old = cur;
	  cur = cur->next;
	  if (!cur) 
	  {
		  size_type bucket = ht->bkt_num(old->val);
		  while (!cur && ++bucket < ht->buckets.size())
			  cur = ht->buckets[bucket];
	  }
	  return *this;
  }
  iterator operator++(int);
  bool operator==(const iterator& it) const
  {
	  return cur == it.cur;
  }
  bool operator!=(const iterator& it) const 
  { 
	  return cur != it.cur; 
  }
};
//////////////////////////////////////////////////////////////////////////////////////////

//key-value
template <class Key, class Value, class HashFcn, class ExtractKey>
class hashtable 
{
	friend struct __hashtable_iterator<Key,Value , HashFcn, ExtractKey>;
public:
	typedef __hashtable_node<Value> node;
	typedef size_t size_type;
	typedef Value  value_type;
	typedef Key    key_type;

	typedef HashFcn hasher; 

	typedef __hashtable_iterator<Key,Value , HashFcn, ExtractKey> iterator;
 
public:
	hashtable(size_type n)
	{
		initialize_buckets(n);
	}
	void print_hashtable()
	{
		for(int i=0; i<buckets.size(); ++i)
		{
			cout<<i<<":";
			node *p = buckets[i];
			while(p != NULL)
			{
				cout<<p->val<<"->";
				p = p->next;
			}
			cout<<"Nil"<<endl;

		}
	}
public:
	iterator begin()
	{
		node *p;
		for(int i=0; i<buckets.size(); ++i)
		{
			p = buckets[i];
			if(p != NULL)
				break;
		}
		return iterator(p, this);
	}
	iterator end()
	{
		return iterator(0, this);
	}
public:
	bool insert_unique(const value_type& obj)
	{
		resize(num_elements + 1);
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

	iterator insert_equal(const value_type& obj)
	{
		resize(num_elements + 1);
		return insert_equal_noresize(obj);
	}
	iterator insert_equal_noresize(const value_type& obj)
	{
		const size_type n = bkt_num(obj);
		node* first = buckets[n];

		for (node* cur = first; cur; cur = cur->next)
		{
			//if (equals(get_key(cur->val), get_key(obj))) 
			if (get_key(cur->val) == get_key(obj))
			{
				node* tmp = new_node(obj);
				tmp->next = cur->next;
				cur->next = tmp;
				++num_elements;
				return iterator(tmp, this);
			}
		}
		
		node* tmp = new_node(obj);
		tmp->next = first;
		buckets[n] = tmp;
		++num_elements;
		return iterator(tmp, this);
	}
private:
	void resize(size_type num_elements_hint);

	size_type bkt_num_key(const key_type& key) const
	{
		return bkt_num_key(key, buckets.size());
	}
	size_type bkt_num(const value_type& obj) const
	{
		return bkt_num_key(get_key(obj));
	}
	size_type bkt_num_key(const key_type& key, size_t n) const
	{
		return hash(key) % n;
	}
	size_type bkt_num(const value_type& obj, size_t n) const
	{
		return bkt_num_key(get_key(obj), n);
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
	hasher      hash;
	ExtractKey  get_key;
private:
	vector<node*> buckets;
	size_type num_elements;
};

template <class Key, class Value, class HashFcn, class ExtractKey>
void hashtable<Key, Value, HashFcn, ExtractKey>::resize(size_type num_elements_hint)
{
	size_type old_n = buckets.size();
	if(num_elements_hint > old_n)
	{
		//调整
		const size_type n = next_size(num_elements_hint);
		if(n > old_n)
		{
			vector<node*> tmp(n, (node*)0);  //
			for (size_type bucket = 0; bucket < old_n; ++bucket)
			{
				node* first = buckets[bucket];
				while (first)
				{
					size_type new_bucket = bkt_num(first->val, n);
					buckets[bucket] = first->next;
					
					first->next = tmp[new_bucket];
					tmp[new_bucket] = first;
					first = buckets[bucket];
				}
			}
			buckets.swap(tmp);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
struct hashfun
{
	const int operator()(int x)const
	{
		return x;
	}
};

struct KeyOfValue
{
	const int operator()(const pair<int, int> &s)const
	{
		return s.first;
	}
};

template<class Type>
class my_unordered_set
{
public:
	typedef hashtable<Type, Type,hashfun, KeyOfValue> hashtable;
	typedef __hashtable_iterator<Type,Type , hashfun, KeyOfValue> iterator;
public:
	my_unordered_set()
	{
		ht = new hashtable(53);
	}
	~my_unordered_set()
	{
		delete ht;
	}
public:
	iterator begin()
	{
		return ht->begin();
	}
	iterator end()
	{
		return ht->end();
	}
public:
	void insert(const Type &x)
	{
		ht->insert_unique(x);
	}
private:
	hashtable *ht;
};

//////////////////////////////////////////////////////////////////////////////////
template<class Type>
class my_unordered_multiset
{
public:
	typedef hashtable<Type, Type,hashfun, KeyOfValue> hashtable;
	typedef __hashtable_iterator<Type,Type , hashfun, KeyOfValue> iterator;
public:
	my_unordered_multiset()
	{
		ht = new hashtable(53);
	}
	~my_unordered_multiset()
	{
		delete ht;
	}
public:
	iterator begin()
	{
		return ht->begin();
	}
	iterator end()
	{
		return ht->end();
	}
public:
	void insert(const Type &x)
	{
		ht->insert_equal(x);
	}
private:
	hashtable *ht;
};

/////////////////////////////////////////////////////////////////////////

template<class Key, class Value>
class my_unordered_map
{
public:

	typedef hashtable<Key, pair<Key, Value>,hashfun, KeyOfValue> hashtable;
	typedef __hashtable_iterator<Key, pair<Key, Value> , hashfun, KeyOfValue> iterator;
public:
	my_unordered_map()
	{
		ht = new hashtable(53);
	}
	~my_unordered_map()
	{
		delete ht;
	}
public:
	iterator begin()
	{
		return ht->begin();
	}
	iterator end()
	{
		return ht->end();
	}
public:
	void insert(const pair<Key, Value> &x)
	{
		ht->insert_unique(x);
	}
private:
	hashtable *ht;
};

template<class Key, class Value>
class my_unordered_multimap
{
public:

	typedef hashtable<Key, pair<Key, Value>,hashfun, KeyOfValue> hashtable;
	typedef __hashtable_iterator<Key, pair<Key, Value> , hashfun, KeyOfValue> iterator;
public:
	my_unordered_multimap()
	{
		ht = new hashtable(53);
	}
	~my_unordered_multimap()
	{
		delete ht;
	}
public:
	iterator begin()
	{
		return ht->begin();
	}
	iterator end()
	{
		return ht->end();
	}
public:
	void insert(const pair<Key, Value> &x)
	{
		ht->insert_equal(x);
	}
private:
	hashtable *ht;
};


void main()
{
	my_unordered_multimap<int, int> mp;
	mp.insert(make_pair(1,11));
	mp.insert(make_pair(5,55));
	mp.insert(make_pair(3,33));
	mp.insert(make_pair(2,22));
	mp.insert(make_pair(5,55));
	mp.insert(make_pair(3,33));

	for(auto &e : mp)
		cout<<e.first<<" : "<<e.second<<endl;

}

/*
void main()
{
	my_unordered_multiset<int> myunset;
	myunset.insert(1);
	myunset.insert(55);
	myunset.insert(5);
	myunset.insert(62);
	myunset.insert(5);
	myunset.insert(62);
	myunset.insert(5);
	myunset.insert(62);
	myunset.insert(30);

	auto it = myunset.begin();
	while(it != myunset.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
////////////////////////////////////////////////////////////////////////////////////////////

class Student
{
public:
	Student(char *n, int a, char *s)
	{
		strcpy(name,n);
		age = a;
		strcpy(sex, s);
	}
public:
	bool operator==(const Student &s)
	{
		return this == &s;
	}
public:
	char name[10];
	int age;
	char sex[3];
};


template<class T>  
size_t BKDRHash(const T *str)  
{  
    register size_t hash = 0;  
    while (size_t ch = (size_t)*str++)  
    {         
        hash = hash * 131 + ch;         
    }  
    return hash;  
} 
struct hashfun
{
	const size_t operator()(const size_t key)const
	{
		return key;
	}
};
struct KeyOfValue
{
	size_t operator()(const char* s)const
	{
		return BKDRHash(s);
	}
};
void main()
{
	char * str[] = {"fjalfja", "hellofafl","abcxyz"};
	hashtable<int, char*, hashfun, KeyOfValue> ht(5); 

	ht.insert_unique(str[0]);
	ht.insert_unique(str[1]);
	ht.insert_unique(str[2]);

}

/*
struct hashfun
{
	const int operator()(int x)const
	{
		return x;
	}
};

struct KeyOfValue
{
	const int operator()(const int &s)const
	{
		return s;
	}
};



/*
void main()
{
	hashtable<int, int, hashfun, KeyOfValue> ht(5); //int-string
	ht.insert_unique(59);
	ht.insert_unique(63);
	ht.insert_unique(108);
	ht.insert_unique(2);
	ht.insert_unique(53);
	ht.insert_unique(55);
	ht.insert_equal(55);
	ht.insert_equal(55);
	//ht.print_hashtable();
	hashtable<int, int, hashfun, KeyOfValue>::iterator it = ht.begin();
	while(it != ht.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
struct KeyOfValue
{
	const int operator()(const Student &s)const
	{
		return s.age;
	}
};
void main()
{
	Student s[] = {{"abc", 15, "男"}, {"xyz", 20, "女"},{"hjk", 56, "男"}};
	
	hashtable<int, Student, hashfun, KeyOfValue> ht(5); //int-string
	
	for(int i=1; i<=53; ++i)   //53
		ht.insert_unique(s[i]);
}

/*
void main()
{
	hashtable<int, int> ht(5); //int-string
	
	for(int i=1; i<=53; ++i)   //53
		ht.insert_unique(i);

	ht.print_hashtable();

	ht.insert_unique(54); //54

	//for(int i=54; i<=106; ++i) 
	//ht.insert_unique(i);

	ht.print_hashtable();

	return;
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