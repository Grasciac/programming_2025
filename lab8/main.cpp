#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Vagon
{
    int number;
    std::string cargo;
    double weight;
    Vagon *next;

    Vagon(int num, std::string c, double w)
    {
        number = num;
        cargo = c;
        weight = w;
        next = nullptr;
    }
};

struct Locomotiv
{
    int id;
    Vagon *next;

    Locomotiv(int i)
    {
        id = i;
        next = nullptr;
    }

    Locomotiv()
    {
        id = 0;
        next = nullptr;
    }
};

void Check_Elem(std::vector<Locomotiv> &Locomotivs)
{
    std::cout << "\n---ПРОСМОТР---" << std::endl;
    std::cout << "Локомотивы:" << std::endl;
    for (int i = 0; i < Locomotivs.size(); i++)
    {
        std::cout << i + 1 << ". ID: " << Locomotivs[i].id << std::endl;
    }
    std::cout << "\nСоставы:" << std::endl;
    for (int i = 0; i < Locomotivs.size(); i++)
    {
        std::cout << "Состав " << i + 1 << " (Локомотив ID: " << Locomotivs[i].id << ")" << std::endl;

        int VagonCount = 0;
        double totalWeight = 0;
        Vagon *current = Locomotivs[i].next;
        while (current != nullptr)
        {
            VagonCount++;
            totalWeight += current->weight;
            current = current->next;
        }
        std::cout << "   Вагонов: " << VagonCount << ", вес: " << totalWeight << " т" << std::endl;
    }
}

void Create_Loco(std::vector<Locomotiv> &Locomotivs)
{
    Locomotiv newLoco = Locomotiv(Locomotivs.size() + 1);
    Locomotivs.push_back(newLoco);
}

void Create_Vagon(std::vector<Locomotiv> &Locomotivs)
{
    std::cout << "\nК какому составу добавить вагон? (1-" << Locomotivs.size() << "): ";
    int train_num;
    std::cin >> train_num;

    if (train_num < 1 || train_num > Locomotivs.size())
    {
        std::cout << "Неверный номер!" << std::endl;
        return;
    }
    int number;
    std::string cargo;
    double weight;
    std::cout << "Номер вагона (0-999): ";
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Груз: ";
    std::getline(std::cin, cargo);
    std::cout << "Вес: ";
    std::cin >> weight;
    Vagon *newVagon = new Vagon(number, cargo, weight);
    newVagon->next = Locomotivs[train_num - 1].next;
    Locomotivs[train_num - 1].next = newVagon;
    std::cout << "Вагон добавлен!" << std::endl;
}

void Check_Trn(std::vector<Locomotiv> &Locomotivs)
{
    std::cout << "\nВыберите состав (1-" << Locomotivs.size() << "): ";
    int train_num;
    std::cin >> train_num;
    if (train_num < 1 || train_num > Locomotivs.size())
    {
        std::cout << "Неверный номер!" << std::endl;
        return;
    }
    std::cout << "\nСостав " << train_num << " (Локомотив ID: " << Locomotivs[train_num - 1].id << ")" << std::endl;
    std::cout << "Вагоны:" << std::endl;
    int VagonCount = 0;
    double totalWeight = 0;
    Vagon *current = Locomotivs[train_num - 1].next;
    while (current != nullptr)
    {
        std::cout << "  " << current->number << ": "
                  << current->cargo << " (" << current->weight << " т)" << std::endl;
        VagonCount++;
        totalWeight += current->weight;
        current = current->next;
    }
    std::cout << "Всего: " << VagonCount << " вагонов, " << totalWeight << " т" << std::endl;
}

void Delete_Last_Vagon(std::vector<Locomotiv> &Locomotivs)
{
    std::cout << "\nОт какого состава отцепить (1-" << Locomotivs.size() << "): ";
    int train_num;
    std::cin >> train_num;
    if (train_num < 1 || train_num > Locomotivs.size())
    {
        std::cout << "Неверный номер" << std::endl;
        return;
    }
    Vagon *first = Locomotivs[train_num - 1].next;
    if (first == nullptr)
    {
        std::cout << "В составе нет вагонов" << std::endl;
        return;
    }
    if (first->next == nullptr)
    {
        delete first;
        Locomotivs[train_num - 1].next = nullptr;
        std::cout << "Последний вагон отцеплен!" << std::endl;
        return;
    }
    while (first->next->next != nullptr)
    {
        first = first->next;
    }
    delete first->next;
    first->next = nullptr;
    std::cout << "Последний вагон отцеплен!" << std::endl;
}

void Int_Sostav(std::vector<Locomotiv> &Locomotivs)
{
    Create_Loco(Locomotivs);
    Create_Loco(Locomotivs);
    Create_Loco(Locomotivs);
    Vagon *w1 = new Vagon(101, "Уголь", 25.5);
    Vagon *w2 = new Vagon(102, "Нефть", 32.1);
    Vagon *w3 = new Vagon(103, "Зерно", 22.3);
    Locomotivs[0].next = w1;
    w1->next = w2;
    w2->next = w3;
    Vagon *w4 = new Vagon(201, "Лес", 18.7);
    Vagon *w5 = new Vagon(202, "Бензин", 31.8);
    Locomotivs[1].next = w4;
    w4->next = w5;
    Vagon *w6 = new Vagon(301, "Руда", 26.2);
    Vagon *w7 = new Vagon(302, "Продукты", 28.9);
    Vagon *w8 = new Vagon(303, "Контейнеры", 19.5);
    Locomotivs[2].next = w6;
    w6->next = w7;
    w7->next = w8;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Locomotiv> Locomotivs;
    Int_Sostav(Locomotivs);
    int choice;
    do
    {
        std::cout << "\n---МЕНЮ---" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "1. Просмотр" << std::endl;
        std::cout << "2. Создать вагон" << std::endl;
        std::cout << "3. Создать локоматив" << std::endl;
        std::cout << "4. Вывод состава" << std::endl;
        std::cout << "5. Отцепить вагон" << std::endl;
        std::cout << "Выберите: ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << "Выход. " << std::endl;
            break;
        case 1:
            Check_Elem(Locomotivs);
            break;
        case 2:
            Create_Vagon(Locomotivs);
            break;
        case 3:
            Create_Loco(Locomotivs);
            break;
        case 4:
            Check_Trn(Locomotivs);
            break;
        case 5:
            Delete_Last_Vagon(Locomotivs);
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
            break;
        }
    } while (choice != 0);
    return 0;
}