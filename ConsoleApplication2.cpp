#include <iostream>
#include <string>

void FirstLastChar()
{
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);
    if (str.empty()) {
        std::cout << "Строка пуста." << std::endl;
    }
    else {
        std::cout << "Первый символ: " << str.front() << std::endl << "Последний символ: " << str.back() << std::endl;
    }
}

void Comparing()
{
    std::string str, str1;
    std::cout << "Введите первую строку: ";
    std::cin.ignore();
    std::getline(std::cin, str);
    std::cout << "Введите вторую строку: ";
    std::getline(std::cin, str1);

    if (str == str1) {
        std::cout << "Строки лексически одинаковы" << std::endl;
    }
    else if (str > str1) {
        std::cout << "Первая строка лексически больше второй" << std::endl;
    }
    else {
        std::cout << "Первая строка лексически меньше второй" << std::endl;
    }
}

void Insertion(std::string str)
{
    int index;
    std::string str1;
    std::cout << "Введите индекс вставляемой подстроки: ";
    std::cin >> index;
    std::cout << "Введите подстроку: ";
    std::cin.ignore();
    std::getline(std::cin, str1);
    str.insert(index, str1);

    std::cout << "Вывод: " << str << std::endl;
}

void Erase(std::string str)
{
    int index, count;
    std::cout << "Введите индекс начала удаления: ";
    std::cin >> index;
    std::cout << "Введите кол-во удаляемых символов: ";
    std::cin >> count;
    str.erase(index, count);

    std::cout << "Вывод: " << str << std::endl;
}

void Replace(std::string str)
{
    int index, count;
    std::string str1;
    std::cout << "Введите индекс начала замены: ";
    std::cin >> index;
    std::cout << "Введите кол-во заменяемых символов: ";
    std::cin >> count;
    std::cout << "Введите подстроку: ";
    std::cin.ignore();
    std::getline(std::cin, str1);
    str.replace(index, count, str1);

    std::cout << "Вывод: " << str << std::endl;
}

void Finding(std::string str)
{
    std::string str1;
    std::cout << "Введите искомую подстроку: ";
    std::cin.ignore();
    std::getline(std::cin, str1);
    size_t found = str.find(str1);
    if (found != std::string::npos) {
        std::cout << "Индекс первого вхождения: " << found << std::endl;
    }
    else {
        std::cout << "Подстрока не найдена." << std::endl;
    }
}

void menu()
{
    int action;
    std::string str;
    std::cin.ignore();
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    std::cout << "Выберите действие: \n1. insert\n2. erase\n3. replace\n4. find" << std::endl;
    std::cin >> action;

    switch (action)
    {
    case 1:
        Insertion(str);
        break;
    case 2:
        Erase(str);
        break;
    case 3:
        Replace(str);
        break;
    case 4:
        Finding(str);
        break;
    default:
        std::cout << "Ничего не выбрано" << std::endl;
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int choice;

    do
    {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Вывести первый и последний символ текущей строки\n";
        std::cout << "2. Сравнить текущую строку с другой\n";
        std::cout << "3. Выполнить операции вставки, удаления или замены в текущей строке\n";
        std::cout << "0. Выйти\n";

        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character

        switch (choice)
        {
        case 1:
            FirstLastChar();
            choice = 0;
            break;
        case 2:
            Comparing();
            choice = 0;
            break;
        case 3:
            menu();
            choice = 0;
            break;
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте еще раз." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
