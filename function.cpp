#include "MyLib.h"


void initQueue(Operator& op)
{
	op.size = 0;
	op.operater = new char[0];
	op.head = op.tail = 0;
}

void addElementToArray(char*& a, int& n, char item)
{
	char* temp = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		temp[i] = a[i];
	}
	temp[n] = item;
	n++;
	delete[] a;
	a = temp;
}

void deleteElementFromTailArray(char*& a, int& n)
{
	char* temp = new char[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		temp[i] = a[i + 1];
	}
	n--;
	delete[] a;
	a = temp;
}

void pushQueue(Operator& op, char item)
{
	addElementToArray(op.operater, op.size, item);
	op.tail += 1;
}

char popQueue(Operator& op)
{
	char x = op.operater[0];
	deleteElementFromTailArray(op.operater, op.size); // pop the item out 
	op.tail -= 1;
	return x;
}

Node* createNode(Data x)
{
	Node* p = new Node;
	p->data = x;
	p->ptrNext = nullptr;
	return p;
}

void initList(List& ll)
{
	ll.ptrHead = ll.ptrTail = nullptr;
	ll.sign = 1;
}

bool isListEmpty(List ll)
{
	return (ll.ptrHead == nullptr && ll.ptrTail == nullptr);
}

void addNodeTail(List& ll, Data x)
{
	Node* p = createNode(x);
	if (isListEmpty(ll))
	{
		ll.ptrHead = ll.ptrTail = p;
		return;
	}
	ll.ptrTail->ptrNext = p;
	ll.ptrTail = p;
}


void printLinkedListCMD(List ll, int k)
{
	Node* p = ll.ptrHead;
	while (p != nullptr)
	{
		if (p == ll.ptrHead)
		{
			for (int i = 0; i < countNumberChar(ll.ptrHead->data.number, k); i++)
			{
				cout << (p->data.number)[i];
			}
		}
		else {
			for (int i = 0; i < k; i++)
			{
				cout << (p->data.number)[i];
			}
		}
		p = p->ptrNext;
	}
}

void reverseLinkedList(List& ll)
{
	Node* temp_Head = ll.ptrHead;
	Node* prev = nullptr;
	Node* next = nullptr;
	while (ll.ptrHead != nullptr)
	{
		//First we need to get the next ptr to the second node ( will be the second - last node later on )
		next = ll.ptrHead->ptrNext; // this node has been saved
		ll.ptrHead->ptrNext = prev; // for the first loop, it will be null ptr, which is the last node of the reversed list
		// Later on the another side of the loop, this step will make the current ptrNext of the current node
		// point to the last node
		prev = ll.ptrHead;
		ll.ptrHead = next;
	}
	ll.ptrHead = prev;
	ll.ptrTail = temp_Head;
}

void reverseCharacterArray(char*& a, int n)
{
	char* temp = new char[n];
	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		temp[count++] = a[i];
	}
	a = temp;
	temp = nullptr;
}

void reverseValueList(List* BigNum, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		Node* p = BigNum[i].ptrHead;
		while (p != nullptr)
		{
			reverseCharacterArray(p->data.number, countNumberChar(p->data.number, k));
			p = p->ptrNext;
		}
	}
}


int countNumberChar(char* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '\0')
			break;
		else {
			count++;
		}
	}
	return count;
}

long long pow(int x, int n)
{
	if (n == 1)
	{
		return long long(x);
	}
	return long long(x) * (pow(x, n - 1));
}

string addZeroToAString(string a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a = "0" + a;
	}
	return a;
}

List Add(List a, List b, int k)
{
	Node* pA = a.ptrHead;
	Node* pB = b.ptrHead;
	long long memorize = 0;
	List Addition;
	initList(Addition);
	while (pA != nullptr && pB != nullptr)
	{
		long long numA = atoll(pA->data.number);
		long long numB = atoll(pB->data.number);
		long long add = numA + numB + memorize;
		memorize = add / pow(10, k);
		add %= pow(10, k);
		string add_string = to_string(add);
		if (add_string.size() < k)
		{
			int temp = k - add_string.size();
			add_string = addZeroToAString(add_string, temp);
		}
		Data x;
		x.number = new char[add_string.size() + 1];
		strcpy(x.number, add_string.c_str());
		x.number[add_string.size()] = '\0';
		addNodeTail(Addition, x);
		pA = pA->ptrNext;
		pB = pB->ptrNext;
	}

	while (pA != nullptr)
	{
		long long numA = atoll(pA->data.number);
		long long add = numA + 0 + memorize;
		memorize = add / pow(10, k);
		string add_string = to_string(add);
		if (add_string.size() < k)
		{
			int temp = k - add_string.size();
			add_string = addZeroToAString(add_string, temp);
		}
		Data x;
		x.number = new char[add_string.size() + 1];
		strcpy(x.number, add_string.c_str());
		x.number[add_string.size()] = '\0';
		addNodeTail(Addition, x);
		pA = pA->ptrNext;
	}

	while (pB != nullptr)
	{

		long long numB = atoll(pB->data.number);
		long long add = numB + 0 + memorize;
		memorize = add / pow(10, k);
		string add_string = to_string(add);
		if (add_string.size() < k)
		{
			int temp = k - add_string.size();
			add_string = addZeroToAString(add_string, temp);
		}
		Data x;
		x.number = new char[add_string.size() + 1];
		strcpy(x.number, add_string.c_str());
		x.number[add_string.size()] = '\0';
		addNodeTail(Addition, x);
		pB = pB->ptrNext;
	}

	return Addition;
}

void get_BigNum_LinkedList(List* BigNum, string* BigNum_string, int n, int k)
{
	// init list
	for (int i = 0; i < n; i++)
	{
		initList(BigNum[i]);
	}

	for (int j = 0; j < n; j++)
	{
		int countK = -1;
		// Lay nguoc so de de cong tru
		for (int i = BigNum_string[j].size() - 1; i >= 0; i--)
		{
			if (i == BigNum_string[j].size() - 1)
			{
				if (i == 0)
				{
					Data x;
					x.number = new char[k];
					x.number[0] = BigNum_string[j][i];
					addNodeTail(BigNum[j], x);
					for (int a = 1; a < k; a++)
					{
						(BigNum[j].ptrTail->data.number)[a] = '\0';
					}
					countK = -1;
				}
				else {
					Data x;
					x.number = new char[k];
					x.number[++countK] = BigNum_string[j][i];
					addNodeTail(BigNum[j], x);
				}
			}
			else if (i == 0)
			{
				if (countK == k - 1)
				{
					Data x;
					x.number = new char[k];
					x.number[0] = BigNum_string[j][i];
					addNodeTail(BigNum[j], x);
					for (int a = 1; a < k; a++)
					{
						(BigNum[j].ptrTail->data.number)[a] = '\0';
					}
					countK = -1;
				}
				else {
					(BigNum[j].ptrTail->data.number)[++countK] = BigNum_string[j][i];
					for (int a = countK + 1; a < k; a++)
					{
						(BigNum[j].ptrTail->data.number)[a] = '\0';
					}
				}
			}
			else {
				if (countK == k - 1)
				{
					countK = -1;
					Data x;
					x.number = new char[k];
					x.number[++countK] = BigNum_string[j][i];
					addNodeTail(BigNum[j], x);
				}
				else {
					(BigNum[j].ptrTail->data.number)[++countK] = BigNum_string[j][i];
				}
			}
		}
	}
}

void deleteHeadCharArray(char*& a, int& n)
{
	char* temp = new char[n - 1];
	for (int i = 0; i < n; i++)
	{
		temp[i] = a[i + 1];
	}
	a = temp;
}

void deleteHeadList(List& a)
{
	Node* p = a.ptrHead->ptrNext;
	delete a.ptrHead;
	a.ptrHead = p;
}

int countZeroInCharArray(char* a, int k)
{
	int count = 0;
	for (int i = 0; i < k; i++)
	{
		if (a[i] == '0')
		{
			count++;
		}
	}
	return count;
}

void deleteZeroFromStart(List& a, int k)
{
	Node* p = a.ptrHead;
	while (p != nullptr) {
		int size = countNumberChar(p->data.number, k);
		int countP = countNodeList(a);
		if (countZeroInCharArray(p->data.number, size) == k && countP > 1)
		{
			deleteHeadList(a);
			p = a.ptrHead;
			continue;
		}
		while (p->data.number[0] == '0')
		{
			if (p->data.number[0] == '0')
			{
				if (p->data.number[0 + 1] != '0')
				{
					deleteHeadCharArray(p->data.number, size);
					break;
				}
				else
					deleteHeadCharArray(p->data.number, size);
			}
			else {
				break;
			}
		}
		break;
	}

}

int countNodeList(List a)
{
	Node* p = a.ptrHead;
	int count = 0;
	while (p != nullptr)
	{
		count++;
		p = p->ptrNext;
	}
	return count;
}

int compare2BigNumIfHaveSameNode(List a, List b)
{
	Node* pA = a.ptrHead;
	Node* pB = b.ptrHead;
	while (pA != nullptr && pB != nullptr)
	{
		int numA = atoi(pA->data.number);
		int numB = atoi(pB->data.number);
		if (numA > numB)
			return 1;
		else if (numA < numB)
			return -1;
		pA = pA->ptrNext;
		pB = pB->ptrNext;
	}
	return 0;
}

int compare2BigNum(List a, List b) // return 1 neu a > b, -1 neu a < b, 0 neu a = b
{
	//Xet sign cua hai so 
	if (a.sign == 1) // Neu a duong 
	{
		if (b.sign == -1) // neu b am
		{
			return 1;
		}
		else {
			int countNodeA = countNodeList(a);
			int countNodeB = countNodeList(b);
			if (countNodeA > countNodeB)// So node a lon hon be thi a > b
			{
				return 1;
			}
			else if (countNodeA < countNodeB)
			{
				return -1;
			}
			else {
				return compare2BigNumIfHaveSameNode(a, b);
			}
		}
	}
	else { // Neu a am
		if (b.sign == 1)
		{
			return -1;
		}
		else {
			//Neu nhu ca hai so cung am 
			int countNodeA = countNodeList(a);
			int countNodeB = countNodeList(b);
			if (countNodeA > countNodeB)// So node a lon hon be thi a > b
			{
				return -1; // Cai nay nguoc voi cai tren, boi vi so am cang nhieu chu so cang nho
			}
			else if (countNodeA < countNodeB)
			{
				return  1;
			}
			else {
				return -1 * compare2BigNumIfHaveSameNode(a, b); // Ta nhan them -1 de thoa tinh chat tren
			}
		}
	}

}

int compareAbsolute(List a, List b) // So sanh gia tri tuyet doi
{
	int countNodeA = countNodeList(a);
	int countNodeB = countNodeList(b);
	if (countNodeA > countNodeB)
	{
		return 1;
	}
	else if (countNodeA < countNodeB)
	{
		return -1;
	}
	else {
		return compare2BigNumIfHaveSameNode(a, b);
	}
}

List Subtraction(List a, List b, int k) // Chi su dung duoc khi a >= b
{
	Node* pA = a.ptrHead;
	Node* pB = b.ptrHead;
	int memorize = 0;
	List Subtraction;
	initList(Subtraction);
	while (pA != nullptr && pB != nullptr)
	{
		long long numA = atoll(pA->data.number);
		long long numB = atoll(pB->data.number) + memorize;
		long long subtract = 0;;
		if (numA < numB) // numA < numB ta can phai cong them 10^k vo numA de co the tru duoc
		{
			numA += pow(10, k);
			subtract = numA - numB;
			memorize = 1;
			string subtract_string = to_string(subtract);
			if (subtract_string.size() < k)
			{
				int temp = k - subtract_string.size();
				subtract_string = addZeroToAString(subtract_string, temp);
			}
			Data x;
			x.number = new char[subtract_string.size() + 1];
			strcpy(x.number, subtract_string.c_str());
			x.number[subtract_string.size()] = '\0';
			addNodeTail(Subtraction, x);
		}
		else // numA >= numB thi chac chac luon duong khoi tinh
		{
			subtract = numA - numB;
			memorize = 0;
			string subtract_string = to_string(subtract);
			if (subtract_string.size() < k)
			{
				int temp = k - subtract_string.size();
				subtract_string = addZeroToAString(subtract_string, temp);
			}
			Data x;
			x.number = new char[subtract_string.size() + 1];
			strcpy(x.number, subtract_string.c_str());
			x.number[subtract_string.size()] = '\0';
			addNodeTail(Subtraction, x);
		}
		pA = pA->ptrNext;
		pB = pB->ptrNext;
	}
	while (pA != nullptr)
	{
		long long numA = atoll(pA->data.number);
		long long subtract = numA - memorize;
		memorize = 0;
		string subtract_string = to_string(subtract);
		if (subtract_string.size() < k)
		{
			int temp = k - subtract_string.size();
			subtract_string = addZeroToAString(subtract_string, temp);
		}
		Data x;
		x.number = new char[subtract_string.size() + 1];
		strcpy(x.number, subtract_string.c_str());
		x.number[subtract_string.size()] = '\0';
		addNodeTail(Subtraction, x);
		pA = pA->ptrNext;
	}
	while (pB != nullptr)
	{
		long long numB = atoll(pB->data.number);
		long long subtract = pow(10, k) - numB - memorize;
		memorize = 1;
		string subtract_string = to_string(subtract);
		if (subtract_string.size() < k)
		{
			int temp = k - subtract_string.size();
			subtract_string = addZeroToAString(subtract_string, temp);
		}
		Data x;
		x.number = new char[subtract_string.size() + 1];
		strcpy(x.number, subtract_string.c_str());
		x.number[subtract_string.size()] = '\0';
		addNodeTail(Subtraction, x);
		pB = pB->ptrNext;
	}
	return Subtraction;
}

bool isQueueEmpty(Operator op)
{
	return (op.tail == 0);
}

void deleteTail(List& a)
{
	if (a.ptrHead == a.ptrTail && a.ptrHead != nullptr)
	{
		delete a.ptrHead;
		a.ptrHead = a.ptrTail = nullptr;
		return;
	}
	Node* p = a.ptrHead;
	while (p->ptrNext != a.ptrTail)
	{
		p = p->ptrNext;
	}
	char* temp = p->data.number;
	delete[] temp;
	delete a.ptrTail;
	a.ptrTail = p;
	p->ptrNext = nullptr;
}

void clearLinkedList(List& a)
{
	while (!isListEmpty(a))
	{
		deleteTail(a);
	}
}

List generateListZero(int k)
{
	List zero;
	initList(zero);
	Data x;
	x.number = new char[k];
	x.number[0] = '0';
	for (int i = 1; i < k; i++)
	{
		x.number[i] = '\0';
	}
	addNodeTail(zero, x);
	return zero;
}

bool checkIfZero(List ll, int k)
{
	//Because zero always have one node and zero on the char[0]
	int count = 0;
	if (ll.ptrHead->data.number[0] != '0')
		return 0;
	else {
		return (countZeroInCharArray(ll.ptrHead->data.number, k) == 1 && countNumberChar(ll.ptrHead->data.number, k) == 1);
	}
}


List getOperatorsAndList(List*& BigNum, Operator& op, int k, string s)
{
	initQueue(op); // initialize queue
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			// if the element of the List is plus or minus it will be a push into the queue
			pushQueue(op, s[i]);
		}
	}
	int amountOfNumbers = op.size + 1; // Number of BigNum in an operation 

	//This will be used for reversed a num without any trouble
	BigNum = new List[amountOfNumbers]; // dynamically allocated the List
	string* BigNum_String = new string[amountOfNumbers];
	for (int i = 0; i < amountOfNumbers; i++)
	{
		BigNum_String[i] = "";
	}


	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			s.erase(s.begin() + i);
		}
	}


	//Get the number to the string
	int countString = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' || s[i] == '+' || s[i] == '-')
		{
			continue;
		}
		if (s[i + 1] == '+' || s[i + 1] == '-') // end of a bigNum
		{
			BigNum_String[countString] += s[i];
			countString++;
		}
		else {
			BigNum_String[countString] += s[i];
		}
	}

	//We must get the bignum and then reverse the value of each node 
	get_BigNum_LinkedList(BigNum, BigNum_String, amountOfNumbers, k);
	reverseValueList(BigNum, amountOfNumbers, k);

	//Get the first list 
	char pop = popQueue(op);
	List ans;
	if (pop == '+')
	{
		ans = Add(BigNum[0], BigNum[1], k);
	}
	else if (pop == '-')
	{
		reverseLinkedList(BigNum[0]);
		reverseLinkedList(BigNum[1]);
		if (compareAbsolute(BigNum[0], BigNum[1]) == 1)
		{
			reverseLinkedList(BigNum[0]);
			reverseLinkedList(BigNum[1]);
			ans = Subtraction(BigNum[0], BigNum[1], k);
		}
		else if (compareAbsolute(BigNum[0], BigNum[1]) == -1)
		{
			reverseLinkedList(BigNum[0]);
			reverseLinkedList(BigNum[1]);
			ans = Subtraction(BigNum[1], BigNum[0], k);
			ans.sign = -1;
		}
		else if (compareAbsolute(BigNum[0], BigNum[1]) == 0)
		{
			ans = generateListZero(k);
		}
	}
	int i = 2;
	while (!isQueueEmpty(op))
	{
		pop = popQueue(op);
		if (pop == '+')
		{
			if (ans.sign == 1) // Neu list ans duong
			{
				ans = Add(ans, BigNum[i], k);
				ans.sign = 1;
			}
			if (ans.sign == -1)
			{
				// O day em ap dung mot so ky thuat giong nhu quay lui, em se reverse linked list de so sanh
				//, sau do reverse nguoc lai de tinh toan
				reverseLinkedList(ans);
				reverseLinkedList(BigNum[i]);
				if (compareAbsolute(ans, BigNum[i]) == -1)
				{
					reverseLinkedList(ans);
					reverseLinkedList(BigNum[i]);
					ans = Subtraction(BigNum[i], ans, k);
					ans.sign = 1;
				}
				else if (compareAbsolute(ans, BigNum[i]) == 0)
				{
					ans = generateListZero(k);
				}
				else {
					reverseLinkedList(ans);
					reverseLinkedList(BigNum[i]);
					ans = Subtraction(ans, BigNum[i], k);
					ans.sign = -1;
				}
			}
		}
		else if (pop == '-')
		{
			if (ans.sign == -1)
			{
				ans = Add(ans, BigNum[i], k);
				ans.sign = -1;
			}
			else {
				reverseLinkedList(ans);
				reverseLinkedList(BigNum[i]);
				if (compareAbsolute(ans, BigNum[i]) == -1)
				{
					reverseLinkedList(ans);
					reverseLinkedList(BigNum[i]);
					ans = Subtraction(BigNum[i], ans, k);
					ans.sign = -1;
				}
				else if (compareAbsolute(ans, BigNum[i]) == 0)
				{
					ans = generateListZero(k);
				}
				else {
					reverseLinkedList(ans);
					reverseLinkedList(BigNum[i]);
					ans = Subtraction(ans, BigNum[i], k);
					ans.sign = 1;
				}
			}
		}
		i++;
	}
	if (!checkIfZero(ans, k))
	{
		reverseLinkedList(ans);
		deleteZeroFromStart(ans, k);
	}
	for (int i = 0; i < amountOfNumbers; i++)
	{
		clearLinkedList(BigNum[i]);
	}
	delete[] BigNum_String;
 	return ans;
}


void transferStringToLinkedList(List* BigNum, string* BigNum_string, int n, int k)
{
	get_BigNum_LinkedList(BigNum, BigNum_string, n, k);
	reverseValueList(BigNum, n, k);
	for (int i = 0; i < n; i++)
	{
		reverseLinkedList(BigNum[i]);
		Node* p = BigNum[i].ptrHead;
		while (p != nullptr)
		{
			long long num = atoll(p->data.number);
			string num_string = to_string(num);
			if (num_string.size() < k)
			{
				int temp = k - num_string.size();
				num_string = addZeroToAString(num_string, temp);
			}
			delete[] p->data.number;
			p->data.number = nullptr;
			p->data.number = strcpy(new char[num_string.size() + 1], num_string.c_str());
			p = p->ptrNext;
		}
		if (BigNum_string[i] != "0") {
			deleteZeroFromStart(BigNum[i], k);
		}
		else {
			clearLinkedList(BigNum[i]);
			BigNum[i] = generateListZero(k);
		}
	}
}

void swapList(List& a, List& b)
{
	List c = a;
	a = b;
	b = c;
}


int partition(List* BigNum, int start, int end)
{
	int pivot = (start + end) / 2;
	swapList(BigNum[pivot], BigNum[end]);
	int i = start - 1;
	for (int j = start; j < end; j++)
	{
		if (compare2BigNum(BigNum[j], BigNum[end]) == -1)
		{
			i++;
			swapList(BigNum[j], BigNum[i]);
		}
	}
	swapList(BigNum[i + 1], BigNum[end]);
	return i + 1;

}

void quicksort(List* BigNum, int start, int end)
{
	if (start < end)
	{
		int p = partition(BigNum, start, end);
		quicksort(BigNum, start, p - 1);
		quicksort(BigNum, p + 1, end);
	}
}


void merge(List* a, int start, int mid, int end)
{
	int nLeft = mid - start + 1;
	int nRight = end - mid;
	List* Left = new List[nLeft];
	List* Right = new List[nRight];

	for (int i = 0; i < nLeft; i++)
	{
		Left[i] = a[start + i];
	}
	for (int i = 0; i < nRight; i++)
	{
		Right[i] = a[mid + 1 + i];
	}

	int iLeft = 0, iRight = 0, k = start;
	while (iLeft < nLeft && iRight < nRight)
	{
		if (compare2BigNum(Left[iLeft], Right[iRight]) == -1 || compare2BigNum(Left[iLeft], Right[iRight]) == 0)
		{
			a[k++] = Left[iLeft++];
		}
		else {
			a[k++] = Right[iRight++];
		}
	}
	while (iLeft < nLeft)
	{
		a[k++] = Left[iLeft++];
	}
	while (iRight < nRight)
	{
		a[k++] = Right[iRight++];
	}
	delete[] Right;
	delete[] Left;
}

void mergesort(List* a, int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(a, start, mid);
		mergesort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}