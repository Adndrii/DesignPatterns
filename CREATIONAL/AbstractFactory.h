#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

class AbstractHero {
public:
    virtual void use() = 0;
    virtual ~AbstractHero() {}
};

class RadiantHero : public AbstractHero {
public:
    void use() override;
};

class DireHero : public AbstractHero {
public:
    void use() override;
};

class AbstractFactory {
public:
    virtual AbstractHero* createHero() = 0;
    virtual ~AbstractFactory() {}
};

class RadiantFactory : public AbstractFactory {
public:
    AbstractHero* createHero() override;
};

class DireFactory : public AbstractFactory {
public:
    AbstractHero* createHero() override;
};

#endif // ABSTRACTFACTORY_H
