#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
#include <string>

class DotaHero;
class DotaItem;

class Visitor {
public:
    virtual void VisitDotaHero(const DotaHero* element) const = 0;
    virtual void VisitDotaItem(const DotaItem* element) const = 0;
};

class Component {
public:
    virtual ~Component() {}
    virtual void Accept(Visitor* visitor) const = 0;
};

class DotaHero : public Component {
public:
    void Accept(Visitor* visitor) const override {
        visitor->VisitDotaHero(this);
    }

    std::string ExclusiveMethodOfDotaHero() const {
        return "DotaHero";
    }
};

class DotaItem : public Component {
public:
    void Accept(Visitor* visitor) const override {
        visitor->VisitDotaItem(this);
    }

    std::string SpecialMethodOfDotaItem() const {
        return "DotaItem";
    }
};

class ConcreteVisitor1 : public Visitor {
public:
    void VisitDotaHero(const DotaHero* element) const override {
        std::cout << element->ExclusiveMethodOfDotaHero() << " + ConcreteVisitor1\n";
    }

    void VisitDotaItem(const DotaItem* element) const override {
        std::cout << element->SpecialMethodOfDotaItem() << " + ConcreteVisitor1\n";
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void VisitDotaHero(const DotaHero* element) const override {
        std::cout << element->ExclusiveMethodOfDotaHero() << " + ConcreteVisitor2\n";
    }

    void VisitDotaItem(const DotaItem* element) const override {
        std::cout << element->SpecialMethodOfDotaItem() << " + ConcreteVisitor2\n";
    }
};

#endif // VISITOR_H
