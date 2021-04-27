#include <iostream>
#include <cstdio>
#include "Sets.hpp"
using namespace std;

void menuUP() {
    bool run = true, go = true;
    bool input;
    int number;
    int method = 1;
    string str, strng;
    Set* testSet = nullptr;
    Set* findSet = nullptr;
    string nameA, nameB;
    bool yes;

    while (run) {
        input = true;
        go = true;
        std::cout << "ТЕОРЕТИКО-МНОЖЕСТВЕННЫЙ ПОКЕТ: \n";
        std::cout << "1) Просмотреть список множеств \n";
        std::cout << "2) Создание множества \n";
        std::cout << "3) Удаление существующего множества \n";
        std::cout << "4) Методы и свойства множества\n";
        std::cout << "5) Операции над множествами \n";
        std::cout << "0) Выход\n";
        std::cin >> number;
        try {
            switch (number) {
            case 1:
                if (testSet == nullptr) {
                    std::cout << "Невозможно просмотреть список множеств, так как здесь нет ни одного множества\n\n";
                }
                else
                    testSet->printListOfSets();
                break;
            case 2: {
                std::cout << "Введите имя нового множества: ";
                std::cin >> str;
                if (str.size() > 80) {
                    cout << "Название множества не может быть больше 80 символов\n";
                    break;
                }
                if (testSet == nullptr) {
                    testSet = new Set(str);
                    std::cout << "Множество успешно добавлено\n\n";
                }
                else {
                    if (testSet->addSet(str))
                        std::cout << "Множество успешно добавлено\n\n";
                    else
                        std::cout << "Имя множества уже занято, добавьте множество с другим именем \n\n";
                }
                break;
            case 3:
                if (testSet == nullptr) {
                    std::cout << "Невозможно удалить множество, так как здесь нет ни одного множества\n\n";
                }
                else {
                    std::cout << "Введите имя удаляемого множества: ";
                    std::cin >> str;
                    if (testSet->name == str && testSet->Next == nullptr) {
                        delete testSet;
                        testSet = nullptr;
                        std::cout << "Множество успешно удалено \n\n";
                    }
                    else
                        if (testSet->deleteSet(str)) {
                            std::cout << "Множество успешно удалено \n\n";
                        }
                        else {
                            std::cout << "Такого множества нет \n\n";

                        }

                }
                break;
            case 4:
                std::cout << "Введите название множества: ";
                std::cin >> str;
                if (testSet->ToSet(str) == nullptr) {
                    std::cout << "Множества с названием " << str << " нет\n\n";
                    break;
                }
                std::cout << "\n";
                std::cout << "Методы и свойства множества: " << str << "\n";
                while (method != 0) {
                    std::cout << "1) Добавить элемент в множество\n";
                    std::cout << "2) Удалить элемент из множества\n";
                    std::cout << "3) Вывести мощность множества\n";
                    std::cout << "4) Проверить на наличие в множестве\n";
                    std::cout << "5) Вывести список элементов множества\n";
                    std::cout << "Чтобы перестать работать с методами и свойствами множества введите 0\n\n";
                    std::cin >> method;
                    switch (method) {
                    case 1:
                        std::cout << "Введите название элемента: ";
                        std::cin >> strng;
                        if (strng.size() > 80) {
                            cout << "Название элемента не может быть больше 80 символов\n";
                            break;
                        }
                        if (testSet->ToSet(str)->set == nullptr) {
                            testSet->ToSet(str)->set = new list(1, strng);
                            testSet->ToSet(str)->power++;
                            std::cout << "Элемент " << strng << " успешно добавлен\n\n";
                        }
                        else if (testSet->addElemToSet(str, strng))
                            std::cout << "Элемент " << strng << " успешно добавлен\n\n";
                        else
                            std::cout << "Элемент " << strng << " уже присутствует в множестве\n\n";
                        break;
                    case 2:
                        std::cout << "Введите название элемента: ";
                        std::cin >> strng;
                        if (testSet->deleteElemFromSet(str, strng))
                            std::cout << "Элемент " << strng << " успешно удален\n\n";
                        else
                            std::cout << "Элемента " << strng << " не было в множестве\n\n";
                        break;
                    case 3:
                        std::cout << "Мощность множества равна " << testSet->getPowerOfSet(str) << "\n\n";
                        break;
                    case 4:
                        std::cout << "Введите название элемента: ";
                        std::cin >> strng;
                        if (testSet->IsInSet(str, strng))
                            std::cout << "Элемент " << strng << " присутствует в множестве\n\n";
                        else
                            std::cout << "Элемент " << strng << " отсутствует в множестве\n\n";
                        break;
                    case 5:
                        testSet->printSetList(str);
                        break;
                    default:
                        break;
                    }
                }
                method = 1;
                break;
            case 5:
                std::cout << "Операции над множествами: \n";
                std::cout << "1) Объединение множеств\n";
                std::cout << "2) Пересечение множеств\n";
                std::cout << "3) Разность множеств\n";
                std::cout << "4) Симметричная разность множеств\n";
                std::cout << "5) Проверка включения одного множества в другое\n";
                std::cout << "Чтобы перестать работать с операциями над множествами введите 0\n\n";
                std::cin >> method;
                switch (method) {
                case 1:
                    std::cout << "Введите название первого множества: ";
                    std::cin >> nameA;
                    std::cout << "Введите название второго множества: ";
                    std::cin >> nameB;
                    testSet->UnionOfSets(nameA, nameB);
                    break;
                case 2:
                    std::cout << "Введите название первого множества: ";
                    std::cin >> nameA;
                    std::cout << "Введите название второго множества: ";
                    std::cin >> nameB;
                    testSet->IntersectionOfSets(nameA, nameB);
                    break;
                case 3:
                    std::cout << "Введите название первого множества: ";
                    std::cin >> nameA;
                    std::cout << "Введите название второго множества: ";
                    std::cin >> nameB;
                    testSet->DifferenceOfSets(nameA, nameB);
                    break;
                case 4:
                    std::cout << "Введите название первого множества: ";
                    std::cin >> nameA;
                    std::cout << "Введите название второго множества: ";
                    std::cin >> nameB;
                    testSet->SymmetricDifferenceOfSets(nameA, nameB);
                    break;
                case 5:
                    std::cout << "Введите название первого множества: ";
                    std::cin >> nameA;
                    std::cout << "Введите название второго множества: ";
                    std::cin >> nameB;
                    yes = testSet->IsInConclusionSet(nameA, nameB);
                    if (yes) {
                        cout << nameA << " включен в множество " << nameB << endl;
                    }
                    else
                        cout << nameA << " не включен в множество " << nameB << endl;
                    break;
                default:
                    method = 1;
                    break;
                }
                break;
            default:
                return;
            }
            }
        }
        catch (std::exception const& e) {
            std::cout << "Вы ввели не то что нужно:\n";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    menuUP();
    //printManual();
    return 0;
}
