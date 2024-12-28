#include "view.hpp"

void View::Selector(int variant){
    switch (variant){
        case 1:{
            int number;
            std::cout << "Введите номер документа: ";
            std::cin >> number;
            std::cout << '\n';
            controlDoc.newDocument(number);
            break;
        }
        case 2:{
            int number;
            std::cout << "Введите номер документа: ";
            std::cin >> number;
            std::cout << '\n';
            controlDoc.switchDocument(number);
            break;
        }
        case 3:{
            std::string filepath;
            std::cout << "Входной файл: ";
            std::cin >> filepath;
            std::cout << '\n';
            controlDoc.importDocument(filepath);
            break;
        }
        case 4:{
            controlDoc.exportDocument();
            break;
        }
        case 5:{
            int variant;
            int number;
            std::cout << "--- Выберите примитив ---" << "\n";
            std::cout << "1. Прямоугольник" << "\n";
            std::cout << "2. Квадрат" << "\n";
            std::cin >> variant;
            if (variant > 2){
                std::cout << "\nТакого примитива нет." << '\n';
                break;
            }
            std::cout << "Введите номер примитива: ";
            std::cin >> number;
            std::cout << '\n';
            controlPrim.CreatePrimitive(variant, number);
            break;
        }
        case 6:{
            int index;
            std::cout << "-- Введите индекс примитива --" << "\n";
            std::cin >> index;
            std::cout << '\n';
            controlPrim.DeletePrimitive(index);
            break;    
        }  
        case 7:{
            std::cout << "\nСписок примитивов в документе: ";
            controlPrim.AllPrimitives();
            std::cout << '\n';
            break;
        }
        case 8:{
            break;
        }
    }
}
void View::Run(){
    int inputVariant;
    while (inputVariant != 8){   
        std::cout << "\n" << "--- Выберите действие ---" << "\n";
        std::cout << "1. Создать новый документ" << "\n";
        std::cout << "2. Переключиться на другой документ" << "\n";
        std::cout << "3. Импорт документа" << "\n";
        std::cout << "4. Экспорт документа" << "\n";
        std::cout << "5. Создать новый примитив" << "\n";
        std::cout << "6. Удалить примитив" << "\n";
        std::cout << "7. Список примитивов" << "\n";
        std::cout << "8. Выход из программы" << "\n";
        std::cin >> inputVariant;
        Selector(inputVariant);
    }
}