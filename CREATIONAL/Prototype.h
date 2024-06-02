#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <string>

class HeroPrototype {
public:
    virtual HeroPrototype* clone() const = 0;
    virtual void use() const = 0;
    virtual ~HeroPrototype() {}
};

class AntiMagePrototype : public HeroPrototype {
public:
    AntiMagePrototype(const std::string& name);
    HeroPrototype* clone() const override;
    void use() const override;

private:
    std::string name;
};

class CrystalMaidenPrototype : public HeroPrototype {
public:
    CrystalMaidenPrototype(const std::string& name);
    HeroPrototype* clone() const override;
    void use() const override;

private:
    std::string name;
};

#endif // PROTOTYPE_H
