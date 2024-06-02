#include "Builder.h"
#include <iostream>

void Item::setPartA(const std::string& part) {
    partA = part;
}

void Item::setPartB(const std::string& part) {
    partB = part;
}

void Item::show() const {
    std::cout << "Item Parts: " << partA << ", " << partB << std::endl;
}

ConcreteItemBuilder::ConcreteItemBuilder() {
    item = new Item();
}

void ConcreteItemBuilder::buildPartA() {
    item->setPartA("Blade of Alacrity");
}

void ConcreteItemBuilder::buildPartB() {
    item->setPartB("Robe of the Magi");
}

Item* ConcreteItemBuilder::getResult() {
    return item;
}

void Director::setBuilder(ItemBuilder* b) {
    builder = b;
}

void Director::construct() {
    builder->buildPartA();
    builder->buildPartB();
}
