#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef unsigned char bool;
typedef bool (*func1)(const char*,int);
typedef bool (*func2)(const char*);
typedef struct{
	char* str;
	bool v;
} st_test;

enum b_type{
	True,False
};


st_test testarr[10]={
	{"a",True},
	{"A1BB1A",True},
	{"545421564",False},
	{"4484412",False},
	{"44844",True},
	{"aba",True},
	{"abaa",False},
	{"3A1BB1A54ad31weffv~@354awexexewa453@~vffew13da45A1BB1A3",True},
	{"3A1BB1A54ad31weffv~@354awexexewa453@~vffew13da45A1BB1A",False},
	{"0",True}};

void str_reverser(const char *str, char* str1)
{
	int i,j;
	for(i=strlen(str)-1,j=0; i>=0; i--,j++){
		str1[j]=str[i];
	}
	str1[j+1]='\0';
	}

bool palindrome1(const char* str, int i)
{
	if(str[i]^str[strlen(str)-i-1])
		return False;
	else
		if(i==strlen(str)>>2)
			return True;
		else
			palindrome1(str, i+1);
}

bool palindrome2(const char* str)
{
	int i;
	for(i=0; i<=(strlen(str)>>2); i++){
		if(str[i]^str[strlen(str)-i-1])
			return False;
	}
	return True;
}

bool test_palindrome2(func2 func,st_test* strs)
{
	int i;
	for(i=0;i<10;i++){
		if(func(strs[i].str)==strs[i].v)
			printf("String %s... PASS!\n",strs[i].str);
		else{
			printf("String %s... Fail!\n",strs[i].str);
			return False;
		}
	}
	return True;
}

bool test_palindrome1(func1 func,st_test* strs)
{
	int i;
	for(i=0;i<10;i++){
		if(func(strs[i].str,0)==strs[i].v)
			printf("String %s... PASS!\n",strs[i].str);
		else{
			printf("String %s... Fail!\n",strs[i].str);
			return False;
		}
	}
	return True;
}

int main(int argc, char* argv[])
{
	char str[128];
	char rts[128];
	int i,j;

	memcpy(str,argv[1],128);
	str_reverser(str,rts);
	printf("string: %s,reverse string: %s\n", str, rts);

//	printf("palindrome1 result: %s\n",palindrome1(str, 0)?"False":"True");
//	printf("palindrome2 result: %s\n",palindrome2(str)?"False":"True");

	printf("palindrome1 TESTIng...\n");
	test_palindrome1(palindrome1,testarr);
	printf("palindrome2 TESTIng...\n");
	test_palindrome2(palindrome2,testarr);
	return 0;
}
