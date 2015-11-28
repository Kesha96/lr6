
#include "stdafx.h"
#include <iostream>
#include "Set.h"

void main()
{
	int *A = new int[5];
	A[0] = 4;
	A[1] = 1;
	A[2] = 6;
	A[3] = 0;
	A[4] = 2;
	Set MN(A, 5);
	//MN - 2;
	//MN.Print();



	int *B = new int[3];
	B[0] = 2;
	B[1] = 3;
	B[2] = 6;


	Set MC(B,3);

	//MC.Print();

	int *C = new int[3];
	C[0] = 1;
	C[1] = 6;
	C[2] = 0;


	Set MQ(C,3);

	//Set RR = MN*MC;
	cout << "00000000000000000000000" << endl;
	//RR.Print();
	bool qwerty = MN>MQ;
	cout << qwerty << endl;
	system("pause");
}

