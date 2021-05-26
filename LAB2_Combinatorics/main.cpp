#include "combinatorics.hpp"


int main()
{
    setlocale(LC_ALL, "Rus");
    help();
    char command = 0;
    integer_t numb1, numb2;
    int args;

    while (1) {
        args = get_arg(command, numb1, numb2);

        switch (command) {
        case 'U':
            if (args == 3)
                cout << U(numb1, numb2) << endl;
            else
                cout << "Íåâåðíîå êîëè÷åñòâî àðãóìåíòîâ." << endl;
            break;
        case 'A':
            if (args == 3)
                cout << A(numb1, numb2) << endl;
            else
                cout << "Íåâåðíîå êîëè÷åñòâî àðãóìåíòîâ." << endl;
            break;
        case 'P':
            if (args == 2)
                cout << P(numb1) << endl;
            else
                cout << "Íåâåðíîå êîëè÷åñòâî àðãóìåíòîâ." << endl;
            break;
        case 'C':
            if (args == 3)
                cout << C(numb1, numb2) << endl;
            else
                cout << "Íåâåðíîå êîëè÷åñòâî àðãóìåíòîâ." << endl;
            break;
        case 'S':
            if (args == 3)
                cout << S(numb1, numb2) << endl;
            else
                cout << "Íåâåðíîå êîëè÷åñòâî àðãóìåíòîâ." << endl;
            break;
        case 'B':
            if (args == 2)
                cout << B(numb1) << endl;
            else
                cout << "Íåâåðíîå êîëè÷åñòâî àðãóìåíòîâ." << endl;
            break;
        case 'H':
            if (args == 1)
                help();
            else
                cout << "Íåâåðíîå êîëè÷åñòâî àðãóìåíòîâ." << endl;
            break;
        case 'Q':
            if (args == 1)
                return 0;
            else
                cout << "Íåâåðíîå êîëè÷åñòâî àðãóìåíòîâ." << endl;
            break;
        default:
            cout << "Íåñóùåñòâóþùàÿ êîìàíäà." << endl;
            break;
        }
    }
    return 0;
}
