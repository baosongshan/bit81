#include<iostream>
#include<assert.h>
using namespace std;

class Test
{
public:
	virtual void fun()
	{}
private:
	char d;   //1 + 7
	double c; //8
	int  a;   //4 +4 +4
};
void main()
{
	Test t;
	cout<<sizeof(Test)<<endl;
}


/*
void AddFunc(unsigned int a, unsigned int b, unsigned char *c) //越界操作
{
	*c = a + b;
}

void main()
{
	//int a = 365*24*60*60, //471741794; //魔鬼数字
	unsigned char e = 200;
	unsigned char f = 100;
	unsigned char g = 0;
	AddFunc((unsigned int)e, (unsigned int)f, (unsigned char*)&g);
	printf("%d", g);
}


/*
void VarInit(unsigned long *pucArg)
{
	*pucArg = 1;
	return;
}
void main()
{
	unsigned long ulGlobal;
	VarInit(&ulGlobal);

	printf("%lu", ulGlobal); //1
	return;
}


/*
char* GetStr(char **p)
{
	*p = "hello world";
	return *p;
}
void main()
{
	char *str = NULL;
	if (NULL != GetStr(&str))
	{
		printf("\r\n str = %s", str);
	}
	return;
}


/*
#define BUFFER_SIZE 256
void GetMemory(char **ppszBuf)
{
	if (NULL == ppszBuf)
	{
		assert(0);
		return;
	}
	//ppszBuf = (char **)malloc(BUFFER_SIZE);
	*ppszBuf = (char *)malloc(BUFFER_SIZE);
	return;
}
void main()
{
	char *pszBuf = NULL;
	GetMemory(&pszBuf);

	strcpy(pszBuf, "hello world\r\n");
	printf("%s", pszBuf);
	free(pszBuf);
	return;
}


/*
#pragma pack(4)

int main()
{
	unsigned char puc[4];
	struct tagPIM
	{
		unsigned char ucPim1;
		unsigned char ucData0 : 1;
		unsigned char ucData1 : 2;
		unsigned char ucData2 : 3;
	}*pstPimData;

	pstPimData = (struct tagPIM*)puc;

	memset(puc, 0, 4);
	pstPimData->ucPim1 = 2;
	pstPimData->ucData0 = 3;
	pstPimData->ucData1 = 4;
	pstPimData->ucData2 = 5;

	printf("% 02x % 02x % 02x % 02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}
#pragma pack()


/*
unsigned long FUNC_C(unsigned long ulAction)
{
	unsigned long ulResult = 0;
	switch (ulAction)
	{
	case ACTION_A:
	{
					 ulResult += 1;
					 break;
	}
	case ACTION_B:
	{
					 ulResult += 1;
	}
	default:
	{
			   ulResult += 1;
	}
	}
	printf(“ulResult = %u”, ulResult);
	return ulResult;
}


/*
class Test
{
public:
	virtual void fun()
	{}
private:
	//void *ptr; //4
	char d;   //1 + 7
	double c; //8
	int  a;   //4 + 4
};
void main()
{
	Test t;
	cout<<sizeof(Test)<<endl;
}

/*
class Test
{
public:
	virtual void fun()
	{}
private:
	//__vfptr  //4 + 4
	//------------
	int a;     //4
	double b;  //8
	char c;    //1
};
void main()
{
	cout<<sizeof(Test)<<endl;
}

/*
#pragma pack(4)

union tagAAAA
{
	struct
	{
		char ucFirst;    //1 + 1
		short usSecond;  //2
		char ucThird;    //1 + 1
	}half;
	short kk;
}number;

struct tagBBBB
{
	char ucFirst;    //1 + 1
	short usSecond;  //2
	char ucThird;    //1 + 1
	short usForth;   //2
}half;

struct tagCCCC
{
	struct
	{
		char ucFirst;    //1 + 1
		short usSecond;  //2
		char ucThird;    //1 + 1
	}half;
	long kk;             //4 + 2
};

void main()
{
	cout<<sizeof(union tagAAAA)<<endl;  //4    //6
	cout<<sizeof(struct tagBBBB)<<endl; //6    //8
	cout<<sizeof(struct tagCCCC)<<endl; //8    //12
}

/*
           //4     1
int fun(int x, int y)
{
	static int m = 0;  //8
	static int i = 2;  //3
	i += m + 1;    //i = i+ m+1 = 3   // i = 3 + 8 + 1 = 12
	m = i + x + y; //m = 3+4+1=8      //m = 12 + 4 + 1
	return m;
}

void main()
{
	int j = 4;
	int m = 1;
	int k;

	k = fun(j, m);
	printf("%d\n" , k); // 8

	k = fun(j, m);
	printf("%d\n",  k); //17
	return;
}


/*
enum ENUM_A
{
	X1,
	Y1,
	Z1 = 255,
	A1,
	B1,
};
enum ENUM_A enumA = Y1;
enum ENUM_A enumB = B1;

void main()
{
	cout << enumA << endl;
	cout << enumB << endl;
}

/*
#pragma pack(4)

struct tagAAA
{
	unsigned char ucld : 1;
	unsigned char ucPara0 : 2; //1
	unsigned char ucState : 6; //1
	unsigned char ucTail : 4;  //1
	unsigned char ucAvail;     //1
	unsigned char ucTail2 : 4; //1
	unsigned char ucData;      //1
}AAA_S;

void main()
{
	cout<<sizeof(AAA_S)<<endl;
}

/*
#define CHAR char
#define ULONG unsigned long
#define VOID void

CHAR *VOS_strncpy(CHAR *pcDest, const CHAR *szSrc, ULONG ulLength)
{
	CHAR *pcPoint = pcDest;
	if ((NULL == szSrc) || (NULL == pcDest))
	{
		return NULL;
	}
	while (ulLength && (*pcPoint = *szSrc))
	{
		pcPoint++;
		szSrc++;
		ulLength--;
	}
	if (!ulLength)
	{
		*pcPoint = '\0';
	}
	return pcDest;
}
VOID main(VOID)
{
	CHAR szStrBuf[] = "1234567890";
	CHAR szStrBuf1[] = "1234567890";
	strncpy(szStrBuf, "ABC", strlen("ABC")); // ABC4567890
	VOS_strncpy(szStrBuf1, "ABC", strlen("ABC")); //ABC
	printf("Str1 = %s\nStr2 = %s", szStrBuf, szStrBuf1);
}


/*
struct BBB
{
	long lA1;  //4
	char cA2;  //1
	char cA3;  //1 + 2
	long lA4;  //4
	long lA5;  //4
}*p;

void main()
{
	p = (struct BBB*)0x100000;
	printf("%p\n", p + 0x1);  //0x100010
	printf("%x\n",(unsigned long)p + 0x1); //0x100001
	printf("%p\n",(unsigned long*)p + 0x1);//0x100004
	printf("%p\n",(char *)p + 0x1);//0x100001
}

/*
#pragma pack(8)

unsigned short *pucCharArray[10][10];

typedef union unRec
{
	unsigned long ullndex;
	unsigned short usLevel[7];
	unsigned char ucPos;
}REC_S;

REC_S stMax, *pstMax;
void main()
{
	cout<<sizeof(pucCharArray)<<endl; //400
	cout<<sizeof(stMax)<<endl;        //16
	cout<<sizeof(pstMax)<<endl;       //4
	cout<<sizeof(*pstMax)<<endl;      //16
}

/*
void main()
{
	char *pcColor =  "CSOFTX3000";
	char acColor[] = "CSOFTX3000";
	cout<<strlen(pcColor)<<endl; //10
	cout<<strlen(acColor)<<endl; //10
	cout<<sizeof(pcColor)<<endl; //4
	cout<<sizeof(acColor)<<endl; //11
}

/*
unsigned short *sum(unsigned char a, unsigned char b)
{
	unsigned short s = 0;
	s = a + b;
	return &s;
}
int main()
{
	unsigned short *p = NULL;
	unsigned char a = 1, b = 2;
	p = sum(a, b);
	printf("%u + %u", a, b);  //1+2=
	printf(" = %u\n", *p);
	return 0;
}


/*
int main()
{
	char c;            //-128 ~ 127
	unsigned char uc;  // 0 ~ 255
	unsigned short us; // 0 ~ 65535

	c = 128;  //-128
	uc = 128;
	us = c + uc;
	printf("0x%x", us); //0x0

	us = (unsigned char)c + uc; //128 + 128
	printf("0x%x", us); //0x100 1*16^2

	us = c + (char)uc;  //-128 + -128 =》 -256
	printf("0x%x", us);
	return 0;
}


/*
#define MAX_SIZE  A+B
struct _Record_Struct
{
	unsigned char Env_Alarm_ID : 4;
	unsigned char Para1 : 2;
	unsigned char state;
	unsigned char avail : 1;
}*Env_Alarm_Record;

//2 3

struct _Record_Struct *pointer = (struct _Record_Struct*)malloc
(sizeof(struct _Record_Struct) * 2 + 3);


/*
void main()
{
	for(char i = 0; i<=127; ++i)
	{
		cout<<"Hello Bit."<<endl;
	}
}

/*
void main()
{
	//0 ~ 255
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;
	printf("%d %d", a + b, c);
}


/*
 #define N 4
   #define Y(n) ((N+2)*n) 


void main()
{
	int z = 2 * (N + Y(5+1));
	cout<<z<<endl;
}

/*
void main()
{
	union
	{
		int  k;
		char i[2];
	}*s, a;

	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;
	printf("%x\n", a.k); //3839  3938
}


/*
struct stu
{
	int num;
	char name[10];
	int age;
};
void fun(struct stu *p)
{
	printf("%s\n", (*p).name);
	return;
}
void main()
{
	struct stu students[3] =
	{
		{ 9801, "zhang", 20 },
		{ 9802, "wang", 19 },
		{ 9803, "zhao", 18 } 
	};
	fun(students + 1);
	return;
}


/*
//strlen()  sizeof()

void main()
{
	short (*ar)[10][10] = {0};
	cout<<sizeof(ar)<<endl;   //4 200 400  32 400 
}

/*
//char acNew[20];
void example()
{
	int i;
	char acNew[20] = {0};
	for (i = 0; i < 5; i++)
	{
		acNew[i] = 0;  //'0'  0  '\0'
	}
	printf("%d\n", strlen(acNew));
	return;
}

void main()
{
	example();
}



/*
void main()
{
	unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
	unsigned long *pulPtr;

	pulPtr = pulArray;
	*(pulPtr + 3) += 3;
	printf("%d, %d\n", *pulPtr, *(pulPtr + 3));

}

/*
void example(char acHello[])
{
	printf("%d", sizeof(acHello));
	return;
}
void main()
{
	char acHello[] = "hello, Bit";

	{
		static int a = 10;
		cout<<"a = "<<a<<endl;
	}
	//cout<<"a = "<<a<<endl;

	example(acHello);
	return;
}
*/