#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

struct Data {
	char* number; // this will be dynamically allocated depends on K
};

struct Node {
	Data data;
	Node* ptrNext;
};

struct List {
	Node* ptrHead;
	Node* ptrTail;
	int sign;
};

struct Operator { // this will be have like a queue
	char* operater;
	int size;
	int head;
	int tail;
};


List getOperatorsAndList(List*& BigNum, Operator& op, int k, string s);
int countNumberChar(char* a, int n);
void deleteHeadCharArray(char*& a, int& n);
int countNumberChar(char* a, int n);
int countNodeList(List a);
void clearLinkedList(List& a);
void transferStringToLinkedList(List* BigNum, string* BigNum_string, int n, int k);
int compare2BigNum(List a, List b); // return 1 neu a > b, -1 neu a < b, 0 neu a = b
void quicksort(List* BigNum, int start, int end);
void mergesort(List* BigNum, int start, int end);
void reverseLinkedList(List& ll);





