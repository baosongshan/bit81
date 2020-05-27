#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

namespace bit
{
	template<size_t _N>
	class  bitset
	{
	public:
		bitset() : m_bit((_N-1)/32+1), m_size(_N)
		{}
		void set(size_t pos)
		{
			if(pos >= m_size)
				return;
			size_t index = pos / 32;
			size_t offset = pos % 32;

			m_bit[index] |= (1<<offset);
		}
	private:
		vector<int> m_bit;
		size_t      m_size;
	};
};

void main()
{
	bit::bitset<32> bt;
	//cout<<sizeof(bt)<<endl;
}
/*
void main()
{
	bitset<10> bt(100);
	cout<<bt<<endl;   //0001100100
	bt.flip();
	cout<<bt<<endl;   //1110011011
	bt.set(2);
	cout<<bt<<endl;   //1110011111
	bt.set(3, 0);
	cout<<bt<<endl;   //1110010111

	cout<<bt.count()<<endl; // 7
	//cout<<bt.any()<<endl;   // 1
	//bt.reset();       //0000000000
	//cout<<bt.any()<<endl;   // 1

	cout<<bt.test(3)<<endl;

	cout<<bt.to_ulong()<<endl;

	cout<<~bt<<endl;
}

/*
void main()
{
	vector<int> v;
	//v.resize(10);  //
	v.reserve(10);
	v.insert(v.end(), 2, 5);
}
*/