#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

class Hero {
public:
    virtual void showHero() = 0;
    virtual ~Hero() {}
};

class HeroFactory {
public:
    virtual Hero* createHero() = 0;
    virtual ~HeroFactory() {}
};

class AntiMage : public Hero {
public:
    void showHero() override;
};

class CrystalMaiden : public Hero {
public:
    void showHero() override;
};

class AntiMageFactory : public HeroFactory {
public:
    Hero* createHero() override;
};

class CrystalMaidenFactory : public HeroFactory {
public:
    Hero* createHero() override;
};

#endif // FACTORYMETHOD_H
