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
				cout << "Такой элемент уже есть \n";
				return false;
			}
		}
		list.push_back(elem);
		cout << "Элемент успешно добавлен\n";
		std::sort(list.begin(), list.end());
		return true;
	}

	bool del_elem(string elem) {
		if (list.size() == 0) {
			cout << "Невозможно удалить элемент, так как данное множество пустое\n";
			return false;
		}
		vector<string> ::iterator it;
		for (it = list.begin(); it != list.end(); it++) {
			if (*it == elem) {
				list.erase(it);
				cout << "Элемент успешно удален \n";
				return true;
			}
		}
		cout << "Такого элемента нет \n";
		return false;
	}

	bool check_elem(string elem) {
		for (size_t i = 0; i < list.size(); i++) {
			if (list[i] == elem) {
				cout << "Данный элемент присутствует в множестве\n";
				return true;
			}
		}
		cout << "Данный элемент отсутствует в множества\n";
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
			cout << "Имя множества уже занято, добавьте множество с другим именем \n";
			return false;
		}
	}
	set_vector.push_back(set(set_name));
	std::sort(set_vector.begin(), set_vector.end(), comp);
	cout << "Множество успешно добавлено\n";
	return true;
}

bool add_set(vector<set>& set_vector, set just_set) {
	for (size_t i = 0; i < set_vector.size(); i++) {
		if (set_vector[i].name == just_set.name) {
			cout << "Имя множества уже занято, переименуйте множество \n";
			return false;
		}
	}
	set_vector.push_back(just_set);
	std::sort(set_vector.begin(), set_vector.end(), comp);
	cout << "Множество успешно добавлено\n";
	return true;
}

bool del_set(vector<set>& set_vector, string set_name) {
	if (set_vector.size() == 0) {
		cout << "Невозможно удалить множество, так как здесь нет ни одного множества\n";
		return false;
	}
	vector<set> ::iterator it;
	for (it = set_vector.begin(); it != set_vector.end(); it++) {
		if (it->name == set_name) {
			set_vector.erase(it);
			cout << "Множество успешно удалено \n";
			return true;
		}
	}
	cout << "Такого множества нет \n";
	return false;
}

void print_sets(vector<set>& set_vector) {
	if (set_vector.size() == 0) {
		cout << "Невозможно просмотреть список множеств, так как здесь нет ни одного множества\n";
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

	cout << "Введите название результирующего множества: ";
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
		cout << "Введите название результирующего множества: ";
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

	cout << "Введите название результирующего множества: ";
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
		cout << "Введите название результирующего множества: ";
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

	cout << "Введите название результирующего множества: ";
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
		cout << "Введите название результирующего множества: ";
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

	cout << "Введите название результирующего множества: ";
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
		cout << "Введите название результирующего множества: ";
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
		cout << "ТЕОРЕТИКО-МНОЖЕСТВЕННЫЙ ПAКЕТ: \n";
		cout << "1) Просмотреть список множеств \n";
		cout << "2) Создание множества \n";
		cout << "3) Удаление существующего множества \n";
		cout << "4) Методы и свойства множества\n";
		cout << "5) Операции над множествами \n";
		cout << "6) Выход\n\n";

		cout << "Введите команду: ";
		cin >> command;
		switch (atoi(command.c_str())) {
		default:
			cout << "Вы ввели мусор!\n";
			break;
		case 6:
			return 0;
		case 1:
			print_sets(test);
			break;
		case 2:
			cout << "Введите название добавляемого множества: ";
			cin.seekg(cin.eof());
			getline(cin, set_name);

			if (set_name.size() > 80) {
				cout << "Название множества не может быть длиной больше 80 символов\n";
				break;
			}
			add_set(test, set_name);
			break;
		case 3:
			if (test.size() == 0) {
				cout << "Невозможно удалить множество, так как здесь нет ни одного множества\n";
				break;
			}
			cout << "Введите название удаляемого множества: ";
			cin.seekg(cin.eof());
			getline(cin, set_name);

			del_set(test, set_name);
			break;
		case 5:
			if (test.size() == 0) {
				cout << "Невозможно работать со множествами, так как здесь нет ни одного множества\n";
				break;
			}
			cout << "Операции над множествами: \n";
			cout << "1) Объединение множеств\n";
			cout << "2) Пересечение множеств\n";
			cout << "3) Разность множеств\n";
			cout << "4) Симметричная разность множеств\n";
			cout << "5) Проверка включения одного множества в другое\n";
			cout << "6) Перестать работать с операциями над множествами\n\n";
			operation = "1";
			while (atoi(operation.c_str()) != 6) {
				cout << "Введите операцию: ";
				cin >> operation;
				switch (atoi(operation.c_str())) {
				case 0:
					cout << "Вы ввели мусор!\n";
					break;
				case 1:
					cout << "Введите название первого множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "Введите название второго множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					set_union(test, set_nameA, set_nameB);
					break;
				case 2:
					cout << "Введите название первого множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "Введите название второго множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					set_intersection(test, set_nameA, set_nameB);
					break;
				case 3:
					cout << "Введите название первого множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "Введите название второго множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					set_difference(test, set_nameA, set_nameB);
					break;
				case 4:
					cout << "Введите название первого множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "Введите название второго множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					set_symdifference(test, set_nameA, set_nameB);
					break;
				case 5:
					cout << "Введите название первого множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameA);
					cout << "Введите название второго множества: ";
					cin.seekg(cin.eof());
					getline(cin, set_nameB);
					if (set_conclusion(test, set_nameA, set_nameB)) {
						cout << "Множество " << set_nameA << " включено в множество " << set_nameB << endl;
					}
					else {
						cout << "Множество " << set_nameA << " не включено в множество " << set_nameB << endl;
					}
					break;
				default:
					break;
				}
			}
			break;
		case 4:
			if (test.size() == 0) {
				cout << "Невозможно работать со множествами, так как здесь нет ни одного множества\n";
				break;
			}
			cout << "Введите название множества, с которым хотите поработать: ";
			cin.seekg(cin.eof());
			getline(cin, set_name);
			cout << set_name << endl;
			vector<set> ::iterator it;
			for (it = test.begin(); it != test.end(); it++) {
				if (it->name == set_name) {
					cout << "1) Добавить элемент в множество\n";
					cout << "2) Удалить элемент из множества\n";
					cout << "3) Вывести мощность множества\n";
					cout << "4) Проверить на наличие в множестве\n";
					cout << "5) Вывести список элементов множества\n";
					cout << "6) Перестать работать с методами множества\n\n";
					method = "1";
					while (atoi(method.c_str()) != 6) {
						cout << "Введите метод: ";
						cin >> method;
						switch (atoi(method.c_str())) {
						case 0:
							cout << "Вы ввели мусор!\n";
							break;
						case 1:
							cout << "Введите добавляемый элемент: ";
							cin.seekg(cin.eof());
							getline(cin, elem_name);

							if (elem_name.size() > 80) {
								cout << "Элемент не может быть длиной больше 80 символов\n";
								break;
							}
							it->add_elem(elem_name);
							break;
						case 2:
							if (it->list.size() == 0) {
								cout << "Невозможно удалить элемент, так как данное множество пустое\n";
								break;
							}
							cout << "Введите удаляемый элемент: ";
							cin.seekg(cin.eof());
							getline(cin, elem_name);

							it->del_elem(elem_name);
							break;
						case 3:
							cout << "Мощность множества " << set_name << "равна " << it->get_power() << endl;
							break;
						case 4:
							cout << "Введите проверяемый элемент: ";
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
				cout << "Нет такого множества\n";
				it = test.begin();
				break;
			}
			break;
		}
	}
}
