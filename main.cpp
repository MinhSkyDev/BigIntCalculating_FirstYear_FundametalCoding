#include "MyLib.h"

// Doing task with the command line formular
// 20120329.exe <command> K <input path> <output path>



int main(int argv, char* argc[])
{
	if (argv != 5)
	{
		cout << "The command line is wrong ! \n";
		system("pause");
	}
	else {
		if (strcmp(argc[1], "-comp") == 0) // when the comparision is true
		{
			string* Component = nullptr; // get all of the line first, then process with it later !
			fstream input;
			fstream output;
			output.open(argc[4], ios::out);
			input.open(argc[3], ios::in || ios::binary);
			int numberOfComponent;
			input >> numberOfComponent; // read the first integer number
			Component = new string[numberOfComponent];
			char temp; int count = 0;
			List* BigNum = nullptr;
			Operator op;
			int k = atoi(argc[2]);
			// Get everyline into a string array
			input.ignore();
			for (int i = 0; i < numberOfComponent; i++)
			{
				getline(input, Component[count++]);
			}
			output << numberOfComponent << "\n";
			for (int i = 0; i < numberOfComponent; i++)
			{
				List temp = getOperatorsAndList(BigNum, op, k, Component[i]);
				if (temp.sign == -1)
				{
					string temp_string = "NaN";
					for (int i = 0; i < temp_string.size(); i++)
					{
						output << temp_string[i];
					}
				}
				else {
					Node* p = temp.ptrHead;
					while (p != nullptr)
					{
						for (int i = 0; i < countNumberChar(p->data.number, k); i++)
						{
							output << (p->data.number)[i];
						}
						p = p->ptrNext;
					}
				}
				char endline = '\n';
				output << endline;
				reverseLinkedList(temp);
				clearLinkedList(temp);
			}
			delete[] Component;
			input.close();
			output.close();
		}
		else if (strcmp(argc[1], "-qsort") == 0 || strcmp(argc[1], "-msort") == 0)
		{
			// Tai vi cau truc sort tung Bignum cua qsort msort la y chang nhau cho nen 
			// su dung chung mot dong if, de tranh viec viet lai qua nhieu
			int amountOfBigNums;
			int k = atoi(argc[2]);
			fstream input, output;
			input.open(argc[3], ios::in);
			output.open(argc[4], ios::out);
			input >> amountOfBigNums; // Nhap so nguyen dau tien chua so luong cua so BigNum
			string* BigNum_string = new string[amountOfBigNums];
			input.ignore();
			for (int i = 0; i < amountOfBigNums; i++)
			{
				getline(input, BigNum_string[i]);
			}
			//GetLinkedList
			List* BigNum = new List[amountOfBigNums];
			//Get the String into the linkedlist
			transferStringToLinkedList(BigNum, BigNum_string, amountOfBigNums, k);
			//Sort the list
			if (strcmp(argc[1], "-qsort") == 0)
			{
				quicksort(BigNum, 0, amountOfBigNums - 1);
			}
			else if (strcmp(argc[1], "-msort") == 0)
			{
				mergesort(BigNum, 0, amountOfBigNums - 1);
			}
			output << amountOfBigNums << "\n";

			for (int i = 0; i < amountOfBigNums; i++)
			{
				Node* p = BigNum[i].ptrHead;
				while (p != nullptr)
				{
					for (int j = 0; j < countNumberChar(p->data.number, k); j++)
					{
						output << (p->data.number)[j];
					}
					p = p->ptrNext;
				}
				char endline = '\n';
				output << endline;
			}

			for (int i = 0; i < amountOfBigNums; i++)
			{
				reverseLinkedList(BigNum[i]);
				clearLinkedList(BigNum[i]);
			}
			delete[] BigNum;
			delete[] BigNum_string;
			input.close();
			output.close();
		}
		else {
			cout << "The command line is wrong, pls try again ! \n";
			system("pause");
		}
		cout << "Chuong trinh da duoc thuc hien thanh cong \n";
	}
	return 0;
}