#include "controller_document.hpp"

void ControllerDocument::newDocument(size_t number){
    for (auto i : documents){
        if (i->getNumber() == number){
            std::cout << "Файл уже существует." << '\n';
            return;
        }
    }
    std::shared_ptr<Document> temp = std::make_shared<Document>(number);
    documents.push_back(temp);
    document = &(*temp);
    std::cout << "Создан новый документ №" << documents.back()->getNumber() << '\n';
};

void ControllerDocument::exportDocument(){
    std::string filepath = "document";
    filepath+=std::to_string(document->getNumber()) +".txt";
    std::ofstream outDocument(filepath);
    if (outDocument.is_open()) outDocument << "In document" << document->getNumber() << ": " << document->getPrimitivesStr();
    outDocument.close();
    std::cout << "Экспорт документа №" << document->getNumber();
}

void ControllerDocument::importDocument(std::string filepath){
    std::cout << "-- Импортировать документ --\n";
    std::ifstream importData(filepath);
    std::string read;
    if (importData.is_open()) while(std::getline(importData, read)) std::cout << read << '\n';
    
    else std::cout << "Файл не найден.\n";
}

void ControllerDocument::switchDocument(size_t number){
    for (auto i : documents){
        if (number > documents.size()){
            std::cout << "Документ не найден." << '\n';
            break;
        }
        if (i->getNumber() == number){
            document = &(*i);
            std::cout << "Переключение на документ №" << document->getNumber() << "" << '\n';
            break;
        }
    }
};
