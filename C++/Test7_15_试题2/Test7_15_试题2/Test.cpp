#include<iostream>
#include<bitset>
#include<string>
#include<assert.h>
using namespace std;

class Base
{
public:
	virtual void f()
	{
		this->print(); 
	}
	virtual void print(int i=6)
	{
		cout<<"Base:"<< i*i <<endl;
	}
};

class Derived : public Base
{
public:
	virtual void f()
	{
		this->print();  //
	}
	virtual void print(int i=10)
	{
		cout<<"Derived" << i*i<<endl;
	}
};

void bar(Base* p)
{
	p->print();
	p->f();
}
 
int main()
{
	Base * p = new Base;
	bar(p); //Base 36,

    Derived  * q = new Derived();
    bar(q);

	Base * r = (Base *)new Derived();
	bar(r);

	system("pause");
	return 0;
}


/*
class animal
{
protected:
    int age;
public:
    virtual void print_age(void) = 0;
};
 
class dog : public animal
{
public:
    dog(){ this->age = 2; }
    ~dog(){}
    virtual void print_age(void){ cout << "wang. my age=" << this->age << endl; }
};
 
class cat:public animal
{
public :
    cat(){ this->age = 1; }
    ~cat(){}
    virtual void print_age(void){ cout << " Miao,my age= " << this->age << endl; }
};
 
int main(void)
{
    cat kitty;
    dog jd;

    animal *pa;
    int *p = (int *)(&kitty);
    int *q = (int *)(&jd);
    p[1] = q[1] = 2;

    pa = &kitty;
    pa->print_age();

	pa = &jd;
	pa->print_age();

    return 0;
}


/*
class Base
 {
 public:
     int Bar(char x)
     {
         return (int)(x);
     }
     virtual int Bar(int x)
     {
         return (2 * x);
     }
 };
 class Derived : public Base
 {
 public:
     int Bar(char x)
     {
         return (int)(-x);
     }
     int Bar(int x)
     {
         return (x / 2);
     }
 };
 int main(void)
 {
     Derived Obj;
     Base *pObj = &Obj;

     printf("%d,", pObj->Bar((char)(100)));
     printf("%d,", pObj->Bar(100));
 }


/*
class SmallInt
{
public:
	SmallInt(int i = 0);
	//重载插入和抽取运算符
	ostream &operator<<(ostream&os)
	{
		os<<(int)val;
		return os;
	}
	istream &operator>>(istream&is)
	{
		int tmp;
		is >> tmp;
		*this = SmallInt(tmp);
		return is;
	}

	//重载算术运算符
	SmallInt operator+(const SmallInt &si){ return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt &si){ return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt &si){ return SmallInt(val*si.val); }
	SmallInt operator/(const SmallInt &si){ return SmallInt(val / si.val); }

	SmallInt &operator +=(const SmallInt &si)
	{
		int tmp = val + si.val;
		while(tmp > 127)
			tmp -= 256;
		while(tmp < -128)
			tmp += 256;
		return *this;
	}

	SmallInt &operator +=(const SmallInt &si)
	{
		int tmp =  val + si.val;
		*this = SmallImt(tmp);
		retutn *this;
	}

	//重载比较运算符
	bool operator==(const SmallInt &si){ return (val == si.val); }
private:
	char val;
};

SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}


void main()
{
	char ch = 1000;
	SmallInt si(1000);
	//cout<<"si = "<<si<<endl;
	si<<cout<<endl; //cout<<si<<endl;
	//si.operator<<(cout);

	SmallInt si1;
	si1>>cin;   //cin>>si1;
}

/*
//-128 ~ 127   char
class SmallInt
{
public:
	SmallInt(int i = 0);
	//重载插入和抽取运算符
	friend ostream &operator<<(ostream&os, const SmallInt &si);
	friend istream &operator>>(istream &is, SmallInt &si);

	//重载算术运算符
	SmallInt operator+(const SmallInt &si){ return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt &si){ return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt &si){ return SmallInt(val*si.val); }
	SmallInt operator/(const SmallInt &si){ return SmallInt(val / si.val); }
	//重载比较运算符
	bool operator==(const SmallInt &si){ return (val == si.val); }
private:
	char val;
};

SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}

ostream &operator<<(ostream &os, const SmallInt &si)
{
	os << (int)si.val;
	return os;
}

istream &operator>>(istream &is, SmallInt &si)
{
	int tmp;
	is >> tmp;
	si = SmallInt(tmp);
	return is;
}

void main()
{
	char ch = 1000;
	SmallInt si(1000);
	cout<<"si = "<<si<<endl;
}


/*
class A
{
private:
	//…其它成员
	static int obj_count;
public:
	A()
	{
		obj_count++;
	}
	~A()
	{
		--obj_count;
	}
public:
	static int GetObjectCount()
	{
		return obj_count;
	}
public:
	virtual void func(int data)
	{
		cout << "class A:" << data << endl;
	}
	void func(char *str)
	{
		cout << "class A:" << str << endl;
	}
};
 
class B : public A
{
	//…其它成员
public:
	void func()
	{
		cout << "function in B without parameter!\n";
	}
	void func(int data) 
	{
		cout << "class B : " << data << endl; 
	}
	void func(char *str)
	{
		cout << "class B : " << str << endl; 
	}
};

int A::obj_count = 0;

void main()
{
	A *pA = new A[3];
	cout << "There are " << pA->GetObjectCount() <<"objects" << endl;
	delete[]pA;
	cout << "There are " << A::GetObjectCount() << " objects" << endl;
}


/*
int main(int argc, char *argv[])
{
	A *pA;
	B b;
	pA = &b;

	pA->func(1);  //class B:1
	pA->func("haha"); //class A:haha

	pA->func();
	return 0;
}

/*
long sum(int n)
{
	if(n == 1)
		return 1;
	else
		return n*n + sum(n-1);
}
void main()
{
	int n;
	printf("input n:>");
	cin>>n;
	cout<<sum(n)<<endl;
}

/*
int CalcDigital(char *str)
{
	//在下面写出程序的实现
	assert(str != NULL);
	int count = 0;
	while(*str != '\0')
	{
		if(*str>='0' && *str<='9')
			count++;
		str++;
	}
	return count;
}


void main()
{
	char *str = "olympic2000";
	cout<<CalcDigital(str)<<endl;
}

/*
//O(1)
void RightLoopMove(char *pStr, unsigned short steps)
{
	int len = strlen(pStr);
	steps %= len;
	if(steps == 0)
		return;

	for(int i=0; i<steps; ++i)
	{
		char tmp = pStr[len-1];
		for(int j=len-1; j>0; --j)
			pStr[j] = pStr[j-1];
		pStr[0] = tmp;
	}
}
void main()
{
	char str[] = "abcdefghi";
	RightLoopMove(str, 2);
	cout<<"str = "<<str<<endl;
}

/*
//O(n)
void RightLoopMove(char *pStr, unsigned short steps)
{
	int len = strlen(pStr);
	steps %= len;
	if(steps == 0)
		return;
	
	char *ptmp = (char *)malloc(sizeof(char) * (len+1));
	memset(ptmp, 0, len+1);

	strcpy(ptmp, pStr + (len - steps));
	strncat(ptmp, pStr, len - steps);
	strcpy(pStr, ptmp);
	
	free(ptmp);
	ptmp = NULL;
}
void main()
{
	char str[] = "abcdefghi";
	RightLoopMove(str, 50);
	cout<<"str = "<<str<<endl;
}

/*
void bit_set(unsigned char *p_data, unsigned char position, bool flag)
{
	if(flag)
		*p_data |= (1<<(position-1));
	else
		*p_data &= ~(1<<(position-1));
}

void main()
{
	unsigned char value = 41;
	bitset<8> bt(value);
	cout<<bt<<endl;
	bit_set(&value, 5, true);  //1 ~ 8  0000 0000
	bitset<8> bt1(value);
	cout<<bt1<<endl;
}

/*
void bit_set(unsigned char *p_data, unsigned char position, bool flag)
{
	if(flag)
	{
		switch(position)
		{
		case 1:
			*p_data |= 0x01; //0000 0001
			break;
		case 2:
			*p_data |= 0x02; //0000 0010
			break;
		case 3:
			*p_data |= 0x04; //0000 0100
			break;
		case 4:
			*p_data |= 0x08; //0000 1000
			break;
		case 5:
			*p_data |= 0x10; //0001 0000
			break;
		case 6:
			*p_data |= 0x20;
			break;
		case 7:
			*p_data |= 0x40;
			break;
		case 8:
			*p_data |= 0x80;
			break;
		}
	}
	else
	{
		switch(position)
		{
		case 1:
			*p_data &= ~0x01; //0000 0001 -> 1111 1110
			break;
		case 2:
			*p_data &= ~0x02; //0000 0010
			break;
		case 3:
			*p_data &= ~0x04; //0000 0100
			break;
		case 4:
			*p_data &= ~0x08; //0000 1000
			break;
		case 5:
			*p_data &= ~0x10; //0001 0000
			break;
		case 6:
			*p_data &= ~0x20;
			break;
		case 7:
			*p_data &= ~0x40;
			break;
		case 8:
			*p_data &= ~0x80;
			break;
		}
	}
}

void main()
{
	unsigned char value = 41;
	bitset<8> bt(value);
	cout<<bt<<endl;
	bit_set(&value, 4, false);  //1 ~ 8  0000 0000
	bitset<8> bt1(value);
	cout<<bt1<<endl;
}

/*
void main()
{
	char str[100] = {0};
	strcpy(str,"Hello Bit");
	strncpy(str, "Hello Bit", strlen("Hello Bit")+1);
}

/*
int func(int a[])
{
	cout<<sizeof(a)<<endl;  //4
	return 0;
}

void main()
{
	char str[] = "Welcome to Bit";
	int Array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char *p = str;
	int  n;
		
	cout<<strlen(str)<<endl;  //14
	cout<<sizeof(str)<<endl;  //15   \0
	cout<<sizeof(Array)<<endl;//36
	cout<<sizeof(p)<<endl;    //4
	cout<<sizeof(n)<<endl;    //4
	func(Array);
}

//请计算：strlen(str), sizeof(str), sizeof(Array), sizeof(p), sizeof(n), 如果函数func参数传递数组Array,那么sizeof(a)呢？
/*
#define ID_LEN   32
struct STR_A
{
	char aucID[ID_LEN];
	int iA;
};
struct STR_B
{
	char *paucID;
	int iB;
};
void funcA(struct STR_A stA, struct STR_B *pstB)
{
	pstB->paucID = stA.aucID;
}


int * fun()
{
	int *p = new int[10];
	return p;
}
void main()
{
	STR_A stA = { 0 };
	STR_B stB;

	strcpy(stA.aucID, "12345");
	funcA(stA, &stB);
	printf("%s\n", stB.paucID);
}
*/
