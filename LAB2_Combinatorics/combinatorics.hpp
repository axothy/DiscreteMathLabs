#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <locale.h>

using std::getline;
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::stringstream;
using std::endl;

typedef uint32_t integer_t;


// ��������� ���������� ��� ��������
int assert_add(integer_t num1, integer_t num2);

// ��������� ���������� ��� ���������
bool assert_mult(integer_t num1, integer_t num2);

// ���������� � �������
integer_t pow_num(integer_t num, integer_t deg);

// ����� ����������
integer_t U(integer_t m, integer_t n);

// ����� ���������� ��� ����������
integer_t A(integer_t m, integer_t n); 

// ����� ������������ 
integer_t P(integer_t n);

// ����� ���������
integer_t C(integer_t m, integer_t n);

// ����� ��������� ������� ���� 
integer_t S(integer_t m, integer_t n);

// ����� �����
integer_t B(integer_t m);

// �������
void help();

// ���� ����������
int get_arg(char& cmd, integer_t& numb1, integer_t& numb2);
