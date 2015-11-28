#pragma once
#include <iostream>
using namespace std;


class Set
{
	int *arr;
	int size ;
public:
	Set(int *a, int s)
	{  
		arr = a;
		size = s;
	};
	void setSize(int s)
	{
		size = s;
	};
	int GetSize()
	{
		return size;
	};
	int* GetArr()
	{
		return arr;
	};
	void Print()
	{
		for (int i = 0; i < size;i++)
		{
			cout << arr[i] << endl;
		}
	}
	friend int* operator -(Set &s, int a)
	{
		int *arr = s.GetArr();
		for (int i = a; i<s.GetSize(); i++)
		{
			arr[i] = arr[i + 1];
		}
		s.setSize(s.GetSize() - 1);
		return arr;
	};
	friend Set operator *(Set &s1,Set &s2)
	{
		int *a1 = s1.GetArr();
		int *a2 = s2.GetArr();


		int *buf = new int[s1.GetSize() + s2.GetSize()];
		int sb = 0;
		for (int i = 0; i < s1.GetSize();i++)
		{
			for (int ii = 0; ii < s2.GetSize();ii++)
			{
				if (a1[i] == a2[ii])
				{
					//cout << "---" << a1[i]<< "<><><><><>" << a2[ii] << endl;
					buf[sb] = a1[i];
					sb++;
				}
			}
		}
		Set s(buf, sb);
		return s;
	}
	friend bool operator >(Set &S, Set &s)
	{
		int *A = S.GetArr();
		int *a = s.GetArr();

		if (S.GetSize() < s.GetSize())
		{
			return false;
		}
		for (int i = 0; i < S.GetSize();i++)
		{
			if (A[i] == a[0])
			{
				for (int ii = 0,iii = i; ii < s.GetSize();ii++,iii++)
				{
					if (A[iii]!=a[ii])
					{
						break;
					}
					if (ii+1==s.GetSize())
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	friend bool operator <(Set &s1, Set &s2)
	{
		if (s1.GetSize()<s2.GetSize())
		{
			return true;
		}
		return false;
	}
};
