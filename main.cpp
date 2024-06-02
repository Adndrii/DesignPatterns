#include <iostream>
#include <string>
//#define CREATIONAL
#define STRUCTURAL
    using namespace std;

#define pattr // current pattern 'pattr[]'

using namespace std;

#ifdef CREATIONAL
#include "CREATIONAL/AbstractFactory.h"
#include "CREATIONAL/Builder.h"
#include "CREATIONAL/FactoryMethod.h"
#include "CREATIONAL/Prototype.h"
#include "CREATIONAL/Singleton.h"
#endif // CREATIONAL

#ifdef STRUCTURAL


#ifdef pattr1
#include "STRUCTURAL/Adapter.h"

#elif defined (pattr2)
#include "STRUCTURAL/Bridge.h"
    void ClientCode(const Hero & hero) {
    std::cout << hero.Ability();
}

#elif defined (pattr3)
#include "STRUCTURAL/Composite.h"

    class DotaHero : public Hero {
    public:
        std::string Ability() const override {
            return "Hero Ability";
        }
};

#elif defined (pattr4)
#include "STRUCTURAL/Decorator.h"

    void ClientCode(Ability* ability) {
    std::cout << "RESULT: " << ability->Operation() << std::endl;
}

#elif defined (pattr5)
#include "STRUCTURAL/Facade.h"

    void ClientCode(Dota2Facade* facade) {
    std::cout << facade->PlayGame();
}
#elif defined (pattr6)
#include "STRUCTURAL/Flyweight.h"

    void AddHeroToTeam(FlyweightFactory& ff, const std::string& name, const std::string& attribute, const std::string& type, const std::string& role) {
    std::cout << "\nAdding hero to team:\n";
    const Flyweight& flyweight = ff.GetFlyweight({ type, role });
    flyweight.Operation({ name, attribute });
}

#elif defined (pattr7)
#include "STRUCTURAL/Proxy.h"
    void ClientCode(const Hero& hero) {

    hero.Attack();
}
#endif
#endif


int main()
{
    
#ifdef CREATIONAL
            // Singleton
            GameManager& gameManager = GameManager::getInstance();
        gameManager.showGameStatus();

        // Factory Method
        HeroFactory* antiMageFactory = new AntiMageFactory();
        Hero* antiMage = antiMageFactory->createHero();
        antiMage->showHero();
        delete antiMage;
        delete antiMageFactory;

        HeroFactory* crystalMaidenFactory = new CrystalMaidenFactory();
        Hero* crystalMaiden = crystalMaidenFactory->createHero();
        crystalMaiden->showHero();
        delete crystalMaiden;
        delete crystalMaidenFactory;

        // Builder
        Director director;
        ItemBuilder* builder = new ConcreteItemBuilder();
        director.setBuilder(builder);
        director.construct();
        Item* item = builder->getResult();
        item->show();
        delete item;
        delete builder;

        // Prototype
        HeroPrototype* antiMagePrototype = new AntiMagePrototype("Anti-Mage");
        HeroPrototype* cloneAntiMage = antiMagePrototype->clone();
        cloneAntiMage->use();
        delete antiMagePrototype;
        delete cloneAntiMage;

        HeroPrototype* crystalMaidenPrototype = new CrystalMaidenPrototype("Crystal Maiden");
        HeroPrototype* cloneCrystalMaiden = crystalMaidenPrototype->clone();
        cloneCrystalMaiden->use();
        delete crystalMaidenPrototype;
        delete cloneCrystalMaiden;

        // Abstract Factory
        AbstractFactory* radiantFactory = new RadiantFactory();
        AbstractHero* radiantHero = radiantFactory->createHero();
        radiantHero->use();
        delete radiantHero;
        delete radiantFactory;

        AbstractFactory* direFactory = new DireFactory();
        AbstractHero* direHero = direFactory->createHero();
        direHero->use();
        delete direHero;
        delete direFactory;


#endif 


#ifdef STRUCTURAL

            //Adapter
#ifdef pattr1
        Hero antimage("Anti-Mage", "Agility", "Mana Break", "Blink", "Spell Shield", "Mana Void");
        Hero axe("Axe", "Strength", "Berserker's Call", "Battle Hunger", "Counter Helix", "Culling Blade");

        std::cout << "Anti-Mage Abilities:" << std::endl;
        antimage.DisplayAbilities();
        std::cout << std::endl;

        std::cout << "Axe Abilities:" << std::endl;
        axe.DisplayAbilities();


        // Bridge
#elif defined(pattr2)
            Hero* hero = new QueenOfPain;
        ClientCode(*hero);
        std::cout << std::endl;
        delete hero;

        hero = new LegionCommander;
        ClientCode(*hero);
        delete hero;

        // Composite
#elif defined(pattr3)

            Component* antiMage = new DotaHero;
        std::cout << "Anti-Mage: I've got a simple component:\n";
        std::cout << "RESULT: " << antiMage->Operation() << std::endl << std::endl;

        delete antiMage;

        Component* abilityTree = new AbilityGroup;
        Component* blink = new DotaHero;
        Component* berserkersCall = new DotaHero;

        abilityTree->Add(blink);
        abilityTree->Add(berserkersCall);

        std::cout << "Recived a composite tree:\n";
        std::cout << "RESULT: " << abilityTree->Operation() << std::endl << std::endl;

        delete abilityTree;
        delete blink;
        delete berserkersCall;


        // Decorator
#elif defined(pattr4)
            Ability* basic = new BasicAbility;
        std::cout << "Hero: I've got a basic ability:\n";
        ClientCode(basic);
        std::cout << "\n\n";

        // Decorated component
        Ability* enhanced = new EnhancedAbility(new BasicAbility);
        std::cout << "Hero: Now I've got an enhanced ability:\n";
        ClientCode(enhanced);
        std::cout << "\n";

        delete basic;
        delete enhanced;

        // Facade
#elif defined(pattr5)
            HeroSelection* heroSelection = new HeroSelection;
        ItemShop* itemShop = new ItemShop;
        Dota2Facade* facade = new Dota2Facade(heroSelection, itemShop);
        ClientCode(facade);

        delete facade;

        // Flyweight
#elif defined(pattr6)
            FlyweightFactory* factory = new FlyweightFactory({
                 {"Strength", "Carry"},
                 {"Agility", "Support"},
                 {"Intelligence", "Initiator"},
                });
        factory->ListFlyweights();

        AddHeroToTeam(*factory, "Anti-Mage", "Agility", "Agility", "Carry");
        AddHeroToTeam(*factory, "Axe", "Strength", "Strength", "Initiator");

        factory->ListFlyweights();

        delete factory;


        // Proxy
#elif defined(pattr7)
            std::cout << "Executing the client code with a real hero:\n";
        Hero* real_hero = new AntiMage;
        ClientCode(*real_hero);
        std::cout << "\n";

        std::cout << "Executing the same client code with a hero proxy:\n";
        Hero* proxy = new HeroProxy(real_hero);
        ClientCode(*proxy);

        delete real_hero;
        delete proxy;
#endif
#endif
       

            return 0;
  }