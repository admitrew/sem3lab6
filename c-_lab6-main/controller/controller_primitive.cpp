#include "controller_primitive.hpp"
#include "controller.hpp"

void TypeToCreate(int variant, size_t number, Document &doc){
    switch(variant){
        case 1:{ // rectangle
            std::shared_ptr<Rectangle> rec = std::make_shared<Rectangle>(number);
            std::cout << "Создан в документе №" << doc.getNumber() << ": ";
            doc.addPrimitive(rec);
            std::cout << '\n';
            break;
        } 
        case 2:{ // square
            std::shared_ptr<Square> squ = std::make_shared<Square>(number);
            std::cout << "Создан в документе №" << doc.getNumber() << ": ";
            doc.addPrimitive(squ);
            std::cout << '\n';
            break;
        }
    }
}
void ControllerPrimitive::CreatePrimitive(int variant, size_t number){
    for (auto j : document->getPrimitives()){
        if (j->getNumber() == number){
            std::cout << "Примитив уже существует." << '\n';
            return;
        }
    }
    TypeToCreate(variant, number, *document);
}
void ControllerPrimitive::DeletePrimitive(int index){
    std::cout << "Удалено в документе №" << document->getNumber() << ": ";
    document->deletePrimitive(index);
    std::cout << '\n';
}

void ControllerPrimitive::AllPrimitives(){
    std::cout << document->getPrimitivesStr();
}

