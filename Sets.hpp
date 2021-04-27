#pragma once
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct list
{
public:
	string data;
	list* next = nullptr;

	list() { cin >> data; }
	list(bool NeedElem, string str);
	list(string str) { data = str; }


	inline bool insertElement(list* node);

	bool addElement(string str);

	bool delElement(string str);

	void printList();

	bool IsInList(string str);
};

class Set
{
public:
	string name;
	int power = 0;
	list* set = nullptr;
	Set* Next = nullptr;

	Set(string nameSet);
	Set(string nameSet, string str);

	inline bool insertSet(Set* node);

	bool addSet(string nameSet); // { Set* newSet = new Set(nameSet); insertSet(newSet); }

	bool deleteSet(string nameSet);

	Set* ToSet(string nameSet);

	bool addElemToSet(string nameSet, string str);

	bool deleteElemFromSet(string nameSet, string str);

	int getPowerOfSet(string nameSet);

	void printSetList(string nameSet);

	void printListOfSets();

	bool IsInSet(string nameSet, string str);

	inline void Union(Set* A, Set* B, Set* C);
	inline void Difference(Set* A, Set* B, Set* C);
	inline void Intersection(Set* A, Set* B, Set* C);

	void UnionOfSets(string nameSetA, string nameSetB);
	void IntersectionOfSets(string nameSetA, string nameSetB);
	void DifferenceOfSets(string nanameSetAmeA, string nameSetB);
	void SymmetricDifferenceOfSets(string nameSetA, string nameSetB);
	bool IsInConclusionSet(string nameSetA, string nameSetB);
};
