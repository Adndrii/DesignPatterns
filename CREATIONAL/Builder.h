#ifndef BUILDER_H
#define BUILDER_H

#include <string>

class Item {
public:
    void setPartA(const std::string& part);
    void setPartB(const std::string& part);
    void show() const;

private:
    std::string partA;
    std::string partB;
};

class ItemBuilder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual Item* getResult() = 0;
    virtual ~ItemBuilder() {}
};

class ConcreteItemBuilder : public ItemBuilder {
public:
    ConcreteItemBuilder();
    void buildPartA() override;
    void buildPartB() override;
    Item* getResult() override;

private:
    Item* item;
};

class Director {
public:
    void setBuilder(ItemBuilder* b);
    void construct();

private:
    ItemBuilder* builder;
};

#endif // BUILDER_H
