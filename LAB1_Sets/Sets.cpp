#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
#include <iterator>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

struct set {

	vector<string> list;

	string name;

	set(string set_name) { name = set_name; }

	int get_power() {
		return list.size();
	}

	bool add_elem(string elem) {
		for (size_t i = 0; i < list.size(); i++) {
			if (list[i] == elem) {
				cout << "����� ������� ��� ���� \n";
				return false;
			}
		}
		list.push_back(elem);
		cout << "������� ������� ��������\n";
		std::sort(list.begin(), list.end());
		return true;
	}

	bool del_elem(string elem) {
		if (list.size() == 0) {
			cout << "���������� ������� �������, ��� ��� ������ ��������� ������\n";
			return false;
		}
		vector<string> ::iterator it;
		for (it = list.begin(); it != list.end(); it++) {
			if (*it == elem) {
				list.erase(it);
				cout << "������� ������� ������ \n";
				return true;
			}
		}
		cout << "������ �������� ��� \n";
		return false;
	}

	bool check_elem(string elem) {
		for (size_t i = 0; i < list.size(); i++) {
			if (list[i] == elem) {
				cout << "������ ������� ������������ � ���������\n";
				return true;
			}
		}
		cout << "������ ������� ����������� � ���������\n";
		return false;
	}

	void print_list() {
		for (size_t i = 0; i < list.size(); i++) {
			cout << list[i] << endl;
		}
	}
};

bool comp(set& a, set& b) {
	return a.name < b.name;
}

bool add_set(vector<set>& set_vector, string set_name) {
	for (size_t i = 0; i < set_vector.size(); i++) {
		if (set_vector[i].name == set_name) {
			cout << "��� ��������� ��� ������, �������� ��������� � ������ ������ \n";
			return false;
		}
	}
	set_vector.push_back(set(set_name));
	std::sort(set_vector.begin(), set_vector.end(), comp);
	cout << "��������� ������� ���������\n";
	return true;
}

bool add_set(vector<set>& set_vector, set just_set) {
	for (size_t i = 0; i < set_vector.size(); i++) {
		if (set_vector[i].name == just_set.name) {
			cout << "��� ��������� ��� ������, ������������ ��������� \n";
			return false;
		}
	}
	set_vector.push_back(just_set);
	std::sort(set_vector.begin(), set_vector.end(), comp);
	cout << "��������� ������� ���������\n";
	return true;
}

bool del_set(vector<set>& set_vector, string set_name) {
	if (set_vector.size() == 0) {
		cout << "���������� ������� ���������, ��� ��� ����� ��� �� ������ ���������\n";
		return false;
	}
	vector<set> ::iterator it;
	for (it = set_vector.begin(); it != set_vector.end(); it++) {
		if (it->name == set_name) {
			set_vector.erase(it);
			cout << "��������� ������� ������� \n";
			return true;
		}
	}
	cout << "������ ��������� ��� \n";
	return false;
}

void print_sets(vector<set>& set_vector) {
	if (set_vector.size() == 0) {
		cout << "���������� ����������� ������ ��������, ��� ��� ����� ��� �� ������ ���������\n";
	}
	for (size_t i = 0; i < set_vector.size(); i++) {
		cout << i + 1 << ". " << set_vector[i].name << endl;
	}
}

void set_union(vector<set>& set_vector, string set_nameA, string set_nameB) {
	int indxA, indxB;
	for (size_t i = 0; i < set_vector.size(); i++) {
		if (set_vector[i].name == set_nameA) {
			indxA = i;
		}
		if (set_vector[i].name == set_nameB) {
			indxB = i;
		}
	}

	vector<string> ::iterator itA = set_vector[indxA].list.begin(), itB = set_vector[indxB].list.begin();
	string set_name;

	cout << "������� �������� ��������������� ���������: ";
	cin.seekg(cin.eof());
	getline(cin, set_name);
	auto C = set(set_name);
	while (itA != set_vector[indxA].list.end() && itB != set_vector[indxB].list.end()) {
		if (*itA < *itB) {
			C.add_elem(*itA);
			itA++;
		}
		else if (*itA > * itB) {
			C.add_elem(*itB);
			itB++;
		}
		else {
			C.add_elem(*itA);
			itA++;
			itB++;
		}
	}

	while (itA != set_vector[indxA].list.end()) {
		C.add_elem(*itA);
		itA++;
	}
	while (itB != set_vector[indxB].list.end()) {
		C.add_elem(*itB);
		itB++;
	}

	while (!add_set(set_vector, C)) {
		cout << "������� �������� ��������������� ���������: ";
		cin.seekg(cin.eof());
		getline(cin, C.name);
	}
}

void set_difference(vector<set>& set_vector, string set_nameA, string set_nameB) {
	int indxA, indxB;
	for (size_t i = 0; i < set_vector.size(); i++) {
		if (set_vector[i].name == set_nameA) {
			indxA = i;
		}
		if (set_vector[i].name == set_nameB) {
			indxB = i;
		}
	}

	vector<string> ::iterator itA = set_vector[indxA].list.begin(), itB = set_vector[indxB].list.begin();
	string set_name;

	cout << "������� �������� ��������������� ���������: ";
	cin.seekg(cin.eof());
	getline(cin, set_name);
	auto C = set(set_name);

	while (itA != set_vector[indxA].list.end() && itB != set_vector[indxB].list.end()) {
		if (*itA < *itB) {
			C.add_elem(*itA);
			itA++;
		}
		else if (*itA > * itB) {
			itB++;
		}
		else {
			itA++;
			itB++;
		}
	}
	while (itA != set_vector[indxA].list.end()) {
		C.add_elem(*itA);
		itA++;
	}
	while (!add_set(set_vector, C)) {
		cout << "������� �������� ��������������� ���������: ";
		cin.seekg(cin.eof());
		getline(cin, C.name);
	}
}

void set_symdifference(vector<set>& set_vector, string set_nameA, string set_nameB) {
	int indxA, indxB;
	for (size_t i = 0; i < set_vector.size(); i++) {
		if (set_vector[i].name == set_nameA) {
			indxA = i;
		}
		if (set_vector[i].name == set_nameB) {
			indxB = i;
		}
	}

	vector<string> ::iterator itA = set_vector[indxA].list.begin(), itB = set_vector[indxB].list.begin();
	string set_name;

	cout << "������� �������� ��������������� ���������: ";
	cin.seekg(cin.eof());
	getline(cin, set_name);
	auto C = set(set_name);

	while (itA != set_vector[indxA].list.end() && itB != set_vector[indxB].list.end()) {
		if (*itA < *itB) {
			C.add_elem(*itA);
			itA++;
		}
		else if (*itA > * itB) {
			C.add_elem(*itB);
			itB++;
		}
		else {
			itA++;
			itB++;
		}
	}

	while (itA != set_vector[indxA].list.end()) {
		C.add_elem(*itA);
		itA++;
	}
	while (itB != set_vector[indxB].list.end()) {
		C.add_elem(*itB);
		itB++;
	}

	while (!add_set(set_vector, C)) {
		cout << "������� �������� ��������������� ���������: ";
		cin.seekg(cin.eof());
		getline(cin, C.name);
	}
}

void set_intersection(vector<set>& set_vector, string set_nameA, string set_nameB) {
	int indxA, indxB;
	for (size_t i = 0; i < set_vector.size(); i++) {
		if (set_vector[i].name == set_nameA) {
			indxA = i;
		}
		if (set_vector[i].name == set_nameB) {
			indxB = i;
		}
	}

	vector<string> ::iterator itA = set_vector[indxA].list.begin(), itB = set_vector[indxB].list.begin();
	string set_name;

	cout << "������� �������� ��������������� ���������: ";
	cin.seekg(cin.eof());
	getline(cin, set_name);
	auto C = set(set_name);

	while (itA != set_vector[indxA].list.end() && itB != set_vector[indxB].list.end()) {
		if (*itA < *itB) {
			itA++;
		}
		else if (*itA > * itB) {
			itB++;
		}
		else {
			C.add_elem(*itA);
			itA++;
			itB++;
		}
	}
	while (!add_set(set_vector, C)) {
		cout << "������� �������� ��������������� ���������: ";
		cin.seekg(cin.eof());
		getline(cin, C.name);
	}
}

bool set_conclusion(vector<set>& set_vector, string set_nameA, string set_nameB) {
	int indxA, indxB;
	for (size_t i = 0; i < set_vector.size(); i++) {
		if (set_vector[i].name == set_nameA) {
			indxA = i;
		}
		if (set_vector[i].name == set_nameB) {
			indxB = i;
		}
	}

	vector<string> ::iterator itA = set_vector[indxA].list.begin(), itB = set_vector[indxB].list.begin();

	while (itA != set_vector[indxA].list.end() && itB != set_vector[indxB].list.end()) {
		if (*itA < *itB) {
			return false;
		}
		else if (*itA > * itB) {
			itB++;
		}
		else {
			itA++;
			itB++;
		}
	}

	if (itA != set_vector[indxA].list.end()) {
		return false;
	}
	else
		return true;

}


int main() {
	vector<set> test;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string command;
	string method = "1";
	string operation = "1";
	string set_name, set_nameA, set_nameB;
	string elem_name;

	while (1) {
		cout << "���������-������������� �A���: \n";
		cout << "1) ����������� ������ �������� \n";
		cout << "2) �������� ��������� \n";
		cout << "3) �������� ������������� ��������� \n";
		cout << "4) ������ � �������� ���������\n";
		cout << "5) �������� ��� ����������� \n";
		cout << "6) �����\n\n";

		cout << "������� �������: ";
		cin >> command;
		switch (atoi(command.c_str())) {
		default:
			cout << "�� ����� �����!\n";
			break;
		case 6:
			return 0;
		case 1:
			print_sets(test);
			break;
		case 2:
			cout << "������� �������� ������������ ���������: ";
			cin.seekg(cin.eof());
			getline(cin, set_name);

			if (set_name.size() > 80) {
				cout << "�������� ��������� �� ����� ���� ������ ������ 80 ��������\n";
				break;
			}
			add_set(test, set_name);
			break;
		case 3:
			if (test.size() == 0) {
				cout << "���������� ������� ���������, ��� ��� ����� ��� �� ������ ���������\n";
				break;
			}
			cout << "������� �������� ���������� ���������: ";
			cin.seekg(cin.eof());
			getline(cin, set_name);

			del_set(test, set_name);
			break;
		case 5:
			if (test.size() == 0) {
				cout << "���������� �������� �� �����������, ��� ��� ����� ��� �� ������ ���������\n";
				break;
			}
			cout << "�������� ��� �����������: \n";
			cout << "1) ����������� ��������\n";
			cout << "2) ����������� ��������\n";
			cout << "3) �������� ��������\n";
			cout << "4) ������������ �������� ��������\n";
			cout << "5) �������� ��������� ������ ��������� � ������\n";
			cout << "6) ��������� �������� � ���������� ��� �����������\n\n";
			operation = "1";
			while (atoi(operation.c_str()) != 6) {
				cout << "������� ��������: ";
				cin >> operation;
				switch (atoi(operation.c_str())) {
				case 0:
					cout << "�� ����� �����!\n";
					break;
				case 1:
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					set_union(test, set_nameA, set_nameB);
					break;
				case 2:
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					set_intersection(test, set_nameA, set_nameB);
					break;
				case 3:
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					set_difference(test, set_nameA, set_nameB);
					break;
				case 4:
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					set_symdifference(test, set_nameA, set_nameB);
					break;
				case 5:
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "������� �������� ������� ���������: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					if (set_conclusion(test, set_nameA, set_nameB)) {
						cout << "��������� " << set_nameA << " �������� � ��������� " << set_nameB << endl;
					}
					else {
						cout << "��������� " << set_nameA << " �� �������� � ��������� " << set_nameB << endl;
					}
					break;
				default:
					break;
				}
			}
			break;
		case 4:
			if (test.size() == 0) {
				cout << "���������� �������� �� �����������, ��� ��� ����� ��� �� ������ ���������\n";
				break;
			}
			cout << "������� �������� ���������, � ������� ������ ����������: ";
			cin.seekg(cin.eof());
			getline(cin, set_name);
			cout << set_name << endl;
			vector<set> ::iterator it;
			for (it = test.begin(); it != test.end(); it++) {
				if (it->name == set_name) {
					cout << "1) �������� ������� � ���������\n";
					cout << "2) ������� ������� �� ���������\n";
					cout << "3) ������� �������� ���������\n";
					cout << "4) ��������� �� ������� � ���������\n";
					cout << "5) ������� ������ ��������� ���������\n";
					cout << "6) ��������� �������� � �������� ���������\n\n";
					method = "1";
					while (atoi(method.c_str()) != 6) {
						cout << "������� �����: ";
						cin >> method;
						switch (atoi(method.c_str())) {
						case 0:
							cout << "�� ����� �����!\n";
							break;
						case 1:
							cout << "������� ����������� �������: ";
							cin.seekg(cin.eof());
							getline(cin, elem_name);

							if (elem_name.size() > 80) {
								cout << "������� �� ����� ���� ������ ������ 80 ��������\n";
								break;
							}
							it->add_elem(elem_name);
							break;
						case 2:
							if (it->list.size() == 0) {
								cout << "���������� ������� �������, ��� ��� ������ ��������� ������\n";
								break;
							}
							cout << "������� ��������� �������: ";
							cin.seekg(cin.eof());
							getline(cin, elem_name);

							it->del_elem(elem_name);
							break;
						case 3:
							cout << "�������� ��������� " << set_name << "����� " << it->get_power() << endl;
							break;
						case 4:
							cout << "������� ����������� �������: ";
							cin.seekg(cin.eof());
							getline(cin, elem_name);

							it->check_elem(elem_name);
							break;
						case 5:
							it->print_list();
						default:
							break;
						}
					}
				}
			}
			if (it == test.end() && atoi(method.c_str()) != 6) {
				cout << "��� ������ ���������\n";
				it = test.begin();
				break;
			}
			break;
		}
	}
}
