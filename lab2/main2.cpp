#include <iostream>
int main() {
    setlocale(LC_ALL, "RU");
    unsigned int N;
    std::cout <<"Введите номер маршрута: "; std:: cin >> N;
    switch (N) {
        case 113:
            std::cout << "Маршрут: Калининград - Чапаево";
            break;
        case 114:
            std::cout << "Маршрут: Калининград - Зеленоградск";
            break; 
        case 117:
            std::cout << "Маршрут: Калининград - Мамоново";
            break;
        case 118:
            std::cout << "Маршрут: Калининград - Светлогорск";
            break;
        case 119:
            std::cout << "Маршрут: Калининград - Пионерский";
            break;
        case 125:
            std::cout << "Маршрут: Калининград - Донское";
            break;
        case 136:
            std::cout << "Маршрут: Калининград - Партизанское";
            break;
        case 141:
            std::cout << "Маршрут: Калининград - Зеленоградск";
            break;
        case 148:
            std::cout << "Маршрут: Калининград - Багратионовск";
            break;
        case 161:
            std::cout << "Маршрут: Калининград - Светлое";
            break;
        case 191:
            std::cout << "Маршрут: Калининград - Багратионовск";
            break;
        case 593:
            std::cout << "Маршрут: Калининград - Морское";
            break;
        case 802:
            std::cout << "Маршрут: Калининград - Гданьск";
            break;
        default:
            std:: cout << "Нет данного маршрута, повторите попытку";
    }
    return 0;
}