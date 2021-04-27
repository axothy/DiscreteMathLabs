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
        std::cout << "���������-������������� �����: \n";
        std::cout << "1) ����������� ������ �������� \n";
        std::cout << "2) �������� ��������� \n";
        std::cout << "3) �������� ������������� ��������� \n";
        std::cout << "4) ������ � �������� ���������\n";
        std::cout << "5) �������� ��� ����������� \n";
        std::cout << "0) �����\n";
        std::cin >> number;
        try {
            switch (number) {
            case 1:
                if (testSet == nullptr) {
                    std::cout << "���������� ����������� ������ ��������, ��� ��� ����� ��� �� ������ ���������\n\n";
                }
                else
                    testSet->printListOfSets();
                break;
            case 2: {
                std::cout << "������� ��� ������ ���������: ";
                std::cin >> str;
                if (str.size() > 80) {
                    cout << "�������� ��������� �� ����� ���� ������ 80 ��������\n";
                    break;
                }
                if (testSet == nullptr) {
                    testSet = new Set(str);
                    std::cout << "��������� ������� ���������\n\n";
                }
                else {
                    if (testSet->addSet(str))
                        std::cout << "��������� ������� ���������\n\n";
                    else
                        std::cout << "��� ��������� ��� ������, �������� ��������� � ������ ������ \n\n";
                }
                break;
            case 3:
                if (testSet == nullptr) {
                    std::cout << "���������� ������� ���������, ��� ��� ����� ��� �� ������ ���������\n\n";
                }
                else {
                    std::cout << "������� ��� ���������� ���������: ";
                    std::cin >> str;
                    if (testSet->name == str && testSet->Next == nullptr) {
                        delete testSet;
                        testSet = nullptr;
                        std::cout << "��������� ������� ������� \n\n";
                    }
                    else
                        if (testSet->deleteSet(str)) {
                            std::cout << "��������� ������� ������� \n\n";
                        }
                        else {
                            std::cout << "������ ��������� ��� \n\n";

                        }

                }
                break;
            case 4:
                std::cout << "������� �������� ���������: ";
                std::cin >> str;
                if (testSet->ToSet(str) == nullptr) {
                    std::cout << "��������� � ��������� " << str << " ���\n\n";
                    break;
                }
                std::cout << "\n";
                std::cout << "������ � �������� ���������: " << str << "\n";
                while (method != 0) {
                    std::cout << "1) �������� ������� � ���������\n";
                    std::cout << "2) ������� ������� �� ���������\n";
                    std::cout << "3) ������� �������� ���������\n";
                    std::cout << "4) ��������� �� ������� � ���������\n";
                    std::cout << "5) ������� ������ ��������� ���������\n";
                    std::cout << "����� ��������� �������� � �������� � ���������� ��������� ������� 0\n\n";
                    std::cin >> method;
                    switch (method) {
                    case 1:
                        std::cout << "������� �������� ��������: ";
                        std::cin >> strng;
                        if (strng.size() > 80) {
                            cout << "�������� �������� �� ����� ���� ������ 80 ��������\n";
                            break;
                        }
                        if (testSet->ToSet(str)->set == nullptr) {
                            testSet->ToSet(str)->set = new list(1, strng);
                            testSet->ToSet(str)->power++;
                            std::cout << "������� " << strng << " ������� ��������\n\n";
                        }
                        else if (testSet->addElemToSet(str, strng))
                            std::cout << "������� " << strng << " ������� ��������\n\n";
                        else
                            std::cout << "������� " << strng << " ��� ������������ � ���������\n\n";
                        break;
                    case 2:
                        std::cout << "������� �������� ��������: ";
                        std::cin >> strng;
                        if (testSet->deleteElemFromSet(str, strng))
                            std::cout << "������� " << strng << " ������� ������\n\n";
                        else
                            std::cout << "�������� " << strng << " �� ���� � ���������\n\n";
                        break;
                    case 3:
                        std::cout << "�������� ��������� ����� " << testSet->getPowerOfSet(str) << "\n\n";
                        break;
                    case 4:
                        std::cout << "������� �������� ��������: ";
                        std::cin >> strng;
                        if (testSet->IsInSet(str, strng))
                            std::cout << "������� " << strng << " ������������ � ���������\n\n";
                        else
                            std::cout << "������� " << strng << " ����������� � ���������\n\n";
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
                std::cout << "�������� ��� �����������: \n";
                std::cout << "1) ����������� ��������\n";
                std::cout << "2) ����������� ��������\n";
                std::cout << "3) �������� ��������\n";
                std::cout << "4) ������������ �������� ��������\n";
                std::cout << "5) �������� ��������� ������ ��������� � ������\n";
                std::cout << "����� ��������� �������� � ���������� ��� ����������� ������� 0\n\n";
                std::cin >> method;
                switch (method) {
                case 1:
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameA;
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameB;
                    testSet->UnionOfSets(nameA, nameB);
                    break;
                case 2:
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameA;
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameB;
                    testSet->IntersectionOfSets(nameA, nameB);
                    break;
                case 3:
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameA;
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameB;
                    testSet->DifferenceOfSets(nameA, nameB);
                    break;
                case 4:
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameA;
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameB;
                    testSet->SymmetricDifferenceOfSets(nameA, nameB);
                    break;
                case 5:
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameA;
                    std::cout << "������� �������� ������� ���������: ";
                    std::cin >> nameB;
                    yes = testSet->IsInConclusionSet(nameA, nameB);
                    if (yes) {
                        cout << nameA << " ������� � ��������� " << nameB << endl;
                    }
                    else
                        cout << nameA << " �� ������� � ��������� " << nameB << endl;
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
            std::cout << "�� ����� �� �� ��� �����:\n";
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
