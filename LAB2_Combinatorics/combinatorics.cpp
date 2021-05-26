#include "combinatorics.hpp"

int assert_add(integer_t num1, integer_t num2)
{
    integer_t maxR = UINT32_MAX - num1;
    if (num2 <= maxR) {
        return 0;
    }
    else {
        throw (string)"Переполнение 32 битного числа при сложении";
        return 1;
    }
}

bool assert_mult(integer_t num1, integer_t num2)
{
    if (num1 == 0)
        return 0;
    integer_t maxR = UINT32_MAX / num1;
    if (num2 <= maxR) {
        return 0;
    }
    else {
        throw (string)"Переполнение 32 битного числа при умножении";
        return 1;
    }
}

integer_t pow_num(integer_t num, integer_t deg)
{
    integer_t res = 1;
    while (deg) {
        if (deg % 2 == 0) {
            deg /= 2;
            assert_mult(num, num);
            num *= num;
        }
        else {
            deg--;
            assert_mult(res, num);
            res *= num;
        }
    }

    return res;
}


integer_t U(integer_t m, integer_t n)
{
    return pow_num(m, n);
}

integer_t A(integer_t m, integer_t n)
{
    if (n > m)
        return 0;

    integer_t res = 1;
    for (integer_t k = 0; k < n; k++) {
        assert_add(m, k);
        assert_mult(res, m - k);
        res *= (m - k);
    }
    return res;
}


integer_t P(integer_t n)
{
    return A(n, n);
}


integer_t C(integer_t m, integer_t n)
{
    if (n > m) 
        return 0;
    else if (m == n || n == 0) 
        return 1;
    else if (n == 1 || (m - n) == 1) 
        return m;
    else 
    {
        integer_t c1 = C(m - 1, n);
        integer_t c2 = C(m - 1, n - 1);

        assert_add(c1, c2);
        return c1 + c2;
    }
}



integer_t S(integer_t m, integer_t n)
{
    if (m == n || n == 1) 
    {
        return 1;
    }
    if (n == 0 || n > m) 
    {
        return 0;
    }

    integer_t d, s;
    if (n < (m - n + 1))
    {
        d = n;
        s = m - n + 1;
    }
    else
    {
        d = m - n + 1;
        s = n;
    }

    integer_t* D = new integer_t[d + 1];
    for (integer_t i = 1; i <= d; i++) D[i] = (integer_t)1;
    try {
        for (integer_t i = 2; i <= s; i++)
            for (integer_t j = 2; j <= d; j++) {
                if (d == n) {
                    assert_mult(j, D[j]);
                    assert_add(D[j - 1], j * D[j]);
                    D[j] = D[j - 1] + j * D[j];
                }
                else {
                    assert_mult(j, D[j - 1]);
                    assert_add(D[j], j * D[j - 1]);
                    D[j] = D[j] + j * D[j - 1];
                }
            }
    }
    catch (string const& str) {
        delete[] D;
        throw str;
    }

    integer_t res = D[d];
    delete[] D;

    return res;
}


integer_t B(integer_t m)
{
    if (m == 0) {
        return 1;
    }
    integer_t* A = new integer_t[m + 1];

    A[1] = 1;
    integer_t t, s;

    try {
        for (integer_t n = 2; n <= m; n++) {
            t = A[1];
            A[1] = A[n - 1];
            for (integer_t k = 2; k <= n; k++) {
                s = A[k];
                assert_add(A[k - 1], t);
                A[k] = A[k - 1] + t;
                t = s;
            }
        }
    }
    catch (string const& str) {
        delete[] A;
        throw str;
    }

    integer_t res = A[m];
    delete[] A;

    return res;
}

void help()
{
    cout << "КОМБИНАТОРНЫЙ ПОКЕТ:" << endl;
    cout << "\tU <m> <n> : число размещений с повторениями " << endl;
    cout << "\tA <m> <n> : число размещений без повторений" << endl;
    cout << "\tP <n> : число перестановок" << endl;
    cout << "\tC <m> <n> : число сочетаний" << endl;
    cout << "\tS <m> <n> : число Стирлинга второго рода" << endl;
    cout << "\tB <n> : число Белла: " << endl;
    cout << "\tH : получить помощь" << endl;
    cout << "\tQ : завершить работу с покетом" << endl;
}

int get_arg(char& cmd, integer_t& numb1, integer_t& numb2)
{
    string str;
    getline(cin, str);
    size_t len = str.length();
    cmd = 0;
    numb1 = 0;
    numb2 = 0;

    stringstream stream(str);
    string word;
    vector<string> words;

    while (stream >> word)
        words.push_back(word);

    if (words.size() > 0) {
        if (words[0].length() != 1) {
            cout << "Ошибка, первый аргумент - один символ" << endl;
        }
        else {
            cmd = words[0][0];
        }

        if (words.size() > 1) {
            string tmp = words[1];
            int i = 0;
            if (tmp[i] < '0' || tmp[i] > '9') {
                if (tmp[i] == '+') {
                    i++;
                }
                else if (tmp[i] == '-') {
                    cout << "Ошибка, второй аргумент должен быть положительным" << endl;
                }
                else {
                    cout << "Ошибка, неправильный второй аргумент" << endl;
                }
            }
            for (int len = tmp.length(); i < len; i++) {
                if (tmp[i] < '0' || tmp[i] > '9')
                    cout << "Ошибка, неправильный второй аргумент" << endl;
                assert_mult(numb1, 10);
                assert_add(numb1 * 10, tmp[i] - '0');
                numb1 = numb1 * 10 + tmp[i] - '0';
            }


            if (words.size() > 2) {
                string tmp = words[2];
                int i = 0;
                if (tmp[i] < '0' || tmp[i] > '9') {
                    if (tmp[i] == '+') {
                        i++;
                    }
                    else if (tmp[i] == '-') {
                        cout << "Ошибка, второй аргумент должен быть положительным" << endl;
                    }
                    else {
                        cout << "Ошибка, неправильный второй аргумент" << endl;
                    }
                }
                for (int len = tmp.length(); i < len; i++) {
                    if (tmp[i] < '0' || tmp[i] > '9')
                        cout << "Ошибка, неправильный второй аргумент" << endl;
                    assert_mult(numb2, 10);
                    assert_add(numb2 * 10, tmp[i] - '0');
                    numb2 = numb2 * 10 + tmp[i] - '0';
                }

                if (words.size() > 3) {
                    cout << "Не должно быть больше 3-х аргументов" << endl;
                }
                return 3;
            }
            return 2;
        }
        return 1;
    }



    return 0;
}