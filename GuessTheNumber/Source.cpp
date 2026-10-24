#include <iostream>
#include <ctime>
#include <windows.h>
#include <limits>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int secretNumber;
	int guess;
	int attempts = 0;
	char comand;

	secretNumber = rand() % 100 + 1;

    cout << "Игра угадай число\n";
    cout << "Правила: вводите числа, чтобы угадать загаданное\n";
    cout << "Чтобы выйти, нажмите 0\n";

    while (true)
    {
        cout << "\nВведите число от 1 до 100 (0 — выход): ";
        cin >> guess;

        while (cin.fail() || guess < 0 || guess > 100)
        {
            if (cin.fail())
            {
                cout << "Ошибка ввода! Нужно ввести целое число\n";
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            }

            else
            {
                cout << "Число должно быть от 0 до 100\n";
            }

            cout << "Введите число еще раз: ";
            cin >> guess;
        }

        if (guess == 0)
        {
            do
            {
                cout << "\nВы уверены, что хотите выйти? (y/n) ";
                cin >> comand;

                if (comand != 'y' && comand != 'n')
                {
                    cout << "Ошибка! Введите только y или n.\n";
                }

            } 
            while (comand != 'y' && comand != 'n');

            if (comand == 'y')
            {
                cout << "Вы вышли из игры.\n";
                break;
            }
            else
            {
                cout << "Игра продолжается!\n";
                continue;
            }
        }

        attempts++;

        if (guess < secretNumber)
        {
            cout << "\nЗагаданное число больше " << guess << "!\n";
        }

        else if (guess > secretNumber)
        {
            cout << "\nЗагаданное число меньше " << guess << "!\n";
        }

        else
        {
            cout << "Вы угадали число! " << secretNumber << "\nПобеда!\n";
            cout << "Количество попыток: " << attempts << "\n";
            break;
        }
    }

    return 0;
}