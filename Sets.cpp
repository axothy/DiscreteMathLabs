#include <iostream>
#include <cstdio>
#include <algorithm>
#include "Sets.hpp"

using namespace std;


list::list(bool NeedElem, string str) {
	if (NeedElem) {
		data = str;
	}
}

inline bool list::insertElement(list* node)
{
	if (this->data > node->data)
	{
		swap(this->next, node->next);
		swap(this->data, node->data);
		this->next = node;
		return true;
	}
	else if (this->data < node->data)
	{
		list* currList = this;

		while (currList->next != nullptr && currList->next->data < node->data)
		{
			currList = currList->next;
		}
		if (currList->next != nullptr)
		{
			if (currList->next->data > node->data)
			{
				node->next = currList->next;
				currList->next = node;
				return true;
			}
			else if (currList->data == node->data)
			{
				delete node;
				return false;
			}
		}
		else
		{
			currList->next = node;
			return true;
		}
	}
	else
	{
		delete node;
		return false;
	}
}

bool list::addElement(string str)
{
	if (str.size() > 80) {
		cout << "Элемент не может быть размером больше 80 символов\n";
		return false;
	}
	list* newNode = new list(str);
	if (insertElement(newNode)) {
		return true;
	}
	else {
		return false;
	}
}

bool list::delElement(string str)
{
	if (this->data == str)
	{
		list* deleteNode = this->next;
		swap(this->data, deleteNode->data);
		this->next = deleteNode->next;
		delete deleteNode;
		return true;
	}
	else
	{
		list* deleteNode = this->next;
		list* prevNode = this;

		while (deleteNode->data != str)
		{
			prevNode = deleteNode;
			deleteNode = deleteNode->next;
			if (deleteNode == nullptr) {
				break;
			}
		}
		if (deleteNode == nullptr)
		{
			return false;
		}
		else if (deleteNode->data == str)
		{
			prevNode->next = deleteNode->next;
			delete deleteNode;
			return true;
		}
	}
}

void list::printList()
{
	list* currList = this;
	while (currList != nullptr)
	{
		cout << currList->data << endl;
		currList = currList->next;
	}
	cout << endl;
}

bool list::IsInList(string str) {
	list* currList = this;
	while (currList != nullptr) {
		if (currList->data == str) {
			return true;
		}
		currList = currList->next;
	}
	return false;
}

Set::Set(string nameSet) { name = nameSet; }
Set::Set(string nameSet, string str) { name = nameSet; set = new list(1, str); }

inline bool Set::insertSet(Set* node) {
	if (this->name > node->name) {
		swap(this->name, node->name);
		swap(this->set, node->set);

		node->Next = this->Next;
		this->Next = node;
		return true;
	}
	else if (this->name == node->name) {
		delete node;
		return false;
	}
	else {
		Set* currList = this;
		while (currList->Next != nullptr && currList->Next->name < node->name) {
			currList = currList->Next;
		}
		if (currList->Next != nullptr) {
			if (currList->Next->name == node->name) {
				delete node;
				return false;
			}
			else if (currList->Next->name > node->name) {
				Set* ptrSet = currList->Next;
				currList->Next = node;
				node->Next = ptrSet;
				return true;
			}
		}
		else if (currList->Next == nullptr) {
			currList->Next = node;
			return true;
		}
	}
	return true;
}

bool Set::addSet(string nameSet) {
	Set* newSet = new Set(nameSet);
	if (insertSet(newSet))
		return true;
	else
		return false;
}

bool Set::deleteSet(string nameSet)
{
	if (this->name == nameSet)
	{
		swap(this->name, this->Next->name);
		swap(this->set, this->Next->set);

		Set* delSet = this->Next;

		this->Next = this->Next->Next;
		delete delSet;
		return true;
	}
	else if (this->Next == nullptr && this->name == nameSet)
	{
		delete this;
		return true;
	}
	else
	{
		if (this->Next != nullptr)
		{
			Set* delSet = this->Next;
			Set* prevSet = this;
			while (delSet->name != nameSet)
			{
				prevSet = delSet;
				delSet = delSet->Next;
				if (delSet == nullptr) {
					break;
				}
			}
			if (delSet == nullptr)
			{
				cout << "Нет такого множества с названием " << nameSet << endl;
				return false;
			}
			else
			{
				prevSet->Next = delSet->Next;
				delete delSet;
				return true;
			}
		}
	}
}

Set* Set::ToSet(string nameSet)
{
	Set* currList = this;
	while (currList != nullptr && currList->name != nameSet)
	{
		currList = currList->Next;
	}
	if (currList == nullptr)
	{
		return nullptr;
	}
	return currList;
}

bool Set::addElemToSet(string nameSet, string str)
{
	Set* add = ToSet(nameSet);
	if (add->set == nullptr) {
		add->set = new list(str);
		add->power++;
		return true;
	}
	else {
		if (add->set->addElement(str)) {
			add->power++;
			return true;
		}
	}
	return false;
}

bool Set::deleteElemFromSet(string nameSet, string str) {
	Set* del = ToSet(nameSet);
	if (del->set->data == str && del->set->next == nullptr) {
		delete del->set;
		del->power--;
		del->set = nullptr;
		return true;
	}
	else if (del->set->delElement(str)) {
		del->power--;
		return true;
	}
	return false;
}

int Set::getPowerOfSet(string nameSet) { Set* power = ToSet(nameSet); return power->power; }

void Set::printSetList(string nameSet) { Set* list = ToSet(nameSet); list->set->printList(); }

void Set::printListOfSets()
{
	Set* currSet = this;
	while (currSet != nullptr) {
		cout << currSet->name << endl;
		currSet = currSet->Next;
	}
	cout << endl;
}

bool Set::IsInSet(string nameSet, string str)
{
	Set* checkInSet = ToSet(nameSet);
	if (checkInSet != nullptr) {
		bool IsIn = checkInSet->set->IsInList(str);
		if (IsIn)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

inline void Set::Union(Set* A, Set* B, Set* C) {
	list* listA = A->set;
	list* listB = B->set;
	if (C->set == nullptr && listA != nullptr) {
		C->set = new list(1, listA->data);
		C->power++;
	}
	if (C->set == nullptr && listB != nullptr) {
		C->set = new list(1, listA->data);
		C->power++;
	}
	while (listA != nullptr && listB != nullptr) {
		if (listA != nullptr) {
			if (C->set->addElement(listA->data))
				C->power++;
			listA = listA->next;
		}
		if (listB != nullptr) {
			if (C->set->addElement(listB->data))
				C->power++;
			listB = listB->next;
		}
	}
}

inline void Set::Difference(Set* A, Set* B, Set* C) {
	list* listA = A->set;
	list* listB = B->set;
	list* startListB = listB;
	if (C->set == nullptr && listA != nullptr) {
		C->set = new list(1, listA->data);
		C->power++;
	}
	while (listA != nullptr && listB != nullptr) {
		while (listB != nullptr) {
			if (listA->data == listB->data) {
				break;
			}
			listB = listB->next;
		}
		if (listB == nullptr)
			C->set->addElement(listA->data);
		listB = startListB;
		listA = listA->next;
	}
}

inline void Set::Intersection(Set* A, Set* B, Set* C) {
	list* listA = A->set;
	list* listB = B->set;
	list* startListB = listB;
	while (listA != nullptr) {
		while (listB != nullptr) {
			if (listA->data == listB->data) {
				if (C->set == nullptr) {
					C->set = new list(1, listA->data);
					C->power++;
				}
				C->set->addElement(listA->data);
			}
			listB = listB->next;
		}
		listB = startListB;
		listA = listA->next;
	}
}


void Set::UnionOfSets(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	if (A == nullptr || B == nullptr) {
		cout << "Не найдено одно или два множества\n";
		return;
	}
	string name;
	cout << "Введите название нового множества: ";
	cin >> name;
	Set* C = new Set(name);
	Union(A, B, C);
	insertSet(C);
}

void Set::IntersectionOfSets(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	if (A == nullptr || B == nullptr) {
		cout << "Не найдено одно или два множества\n";
		return;
	}
	string name;
	cout << "Введите название нового множества: ";
	cin >> name;
	Set* C = new Set(name);
	Intersection(A, B, C);
	insertSet(C);
}


void Set::DifferenceOfSets(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	if (A == nullptr || B == nullptr) {
		cout << "Не найдено одно или два множества\n";
		return;
	}
	string name;
	cout << "Введите название нового множества: ";
	cin >> name;
	Set* C = new Set(name);	Difference(A, B, C);
	insertSet(C);
}

void Set::SymmetricDifferenceOfSets(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	if (A == nullptr || B == nullptr) {
		cout << "Не найдено одно или два множества\n";
		return;
	}
	string name;
	cout << "Введите название нового множества: ";
	cin >> name;
	Set* C = new Set(name);
	Set* D = new Set("");
	Set* E = new Set("");
	Difference(A, B, D);
	Difference(B, A, E);
	Union(D, E, C);
	delete D;
	delete E;
	insertSet(C);
}

bool Set::IsInConclusionSet(string nameSetA, string nameSetB) {
	Set* A = ToSet(nameSetA);
	Set* B = ToSet(nameSetB);
	if (A == nullptr || B == nullptr) {
		cout << "Не найдено одно или два множества\n";
		return false;
	}
	list* listA = A->set;
	while (listA != nullptr) {
		if (!(B->set->IsInList(listA->data))) {
			return false;
		}
		listA = listA->next;
	}
	return true;
}