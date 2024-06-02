#include <iostream>
#include <string>
//#define CREATIONAL
//#define STRUCTURAL
#define BEHAVIORAL
using namespace std;

#define pattr10 // current pattern 'pattr#'

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

#ifdef BEHAVIORAL
#ifdef pattr1
#include "BEHAVIORAL/ChainOfResponsibility.h"

    void ClientCode(Handler& handler) {
        std::vector<std::string> actions = { "Mana", "Attack", "Gold", "Spell" };
        for (const std::string& action : actions) {
            std::cout << "Client: Using " << action << ".\n";
            const std::string result = handler.Handle(action);
            if (!result.empty()) {
                std::cout << "  " << result;
            }
            else {
                std::cout << "  " << action << " was not fully utilized.\n";
            }
        }
    }

#elif defined(pattr2)
#include "BEHAVIORAL/Command.h"
#elif defined(pattr3)
#include "BEHAVIORAL/Iterator.h"
    void ClientCode() {
        std::cout << "________________Iterator with int______________________________________" << std::endl;
        Container<int> cont;

        for (int i = 0; i < 10; i++) {
            cont.Add(i);
  }

        Iterator<int, Container<int>>* it = cont.CreateIterator();
        for (it->First(); !it->IsDone(); it->Next()) {
            std::cout << *it->Current() << std::endl;
        }

        std::cout << "________________Iterator with Dota 2 Heroes______________________________" << std::endl;
        Container<Hero> cont2;
        Hero a("Anti-Mage"), b("Axe"), c("Invoker");
        cont2.Add(a);
        cont2.Add(b);
        cont2.Add(c);

        Iterator<Hero, Container<Hero>>* it2 = cont2.CreateIterator();
        for (it2->First(); !it2->IsDone(); it2->Next()) {
            std::cout << it2->Current()->name() << std::endl;
        }

        delete it;
        delete it2;
}
#elif defined(pattr4)
#include "BEHAVIORAL/Mediator.h"

    void ClientCode() {
        RadiantHero* rh = new RadiantHero;
        DireHero* dh = new DireHero;
        Dota2Mediator* mediator = new Dota2Mediator(rh, dh);

        std::cout << "Client triggers Radiant attack.\n";
        rh->Attack();
        std::cout << "\n";

        std::cout << "Client triggers Dire retreat.\n";
        dh->Retreat();

        delete rh;
        delete dh;
        delete mediator;
}
#elif defined(pattr5)
#include "BEHAVIORAL/Memento.h"

    void ClientCode() {
        Hero* hero = new Hero("Initial State of the Hero.");
        Caretaker* caretaker = new Caretaker(hero);
        caretaker->Backup();
        hero->UseAbility();
        caretaker->Backup();
        hero->UseAbility();
        caretaker->Backup();
        hero->UseAbility();
        std::cout << "\n";
        caretaker->ShowHistory();
        std::cout << "\nClient: Now, let's rollback!\n\n";
        caretaker->Undo();
        std::cout << "\nClient: Once more!\n\n";
        caretaker->Undo();

        delete hero;
        delete caretaker;
    }
#elif defined(pattr6)
#include "BEHAVIORAL/Observer.h"

    void ClientCode() {
        Game* game = new Game;

        Player* player1 = new Player(*game);
        Player* player2 = new Player(*game);
        Player* player3 = new Player(*game);
        Player* player4;
        Player* player5;

        game->CreateMessage("First blood!");
        player3->LeaveGame();

        game->CreateMessage("Aegis has been taken!");
        player4 = new Player(*game);

        player2->LeaveGame();
        player5 = new Player(*game);

        game->CreateMessage("Mega kill streak!");
        player5->LeaveGame();

        player4->LeaveGame();
        player1->LeaveGame();

        delete player5;
        delete player4;
        delete player3;
        delete player2;
        delete player1;
        delete game;
}

#elif defined(pattr7)
#include "BEHAVIORAL/State.h"

void ClientCode() {
    HeroContext* hero = new HeroContext(new MeleeState);
    hero->RequestAttack();
    hero->RequestAbility();
    delete hero;
}
#elif defined(pattr8)
#include "BEHAVIORAL/Strategy.h"

void clientCode()
{
    Context context(std::make_unique<AntiMageStrategy>());
    std::cout << "Client: Strategy is set to Anti-Mage's ability.\n";
    context.PerformAbility();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to Axe's ability.\n";
    context.set_strategy(std::make_unique<AxeStrategy>());
    context.PerformAbility();
}

#elif defined(pattr9)
#include "BEHAVIORAL/TemplateMethod.h"

void ClientCode(const Hero* hero) {
    hero->TemplateMethod();
}

#elif defined(pattr10)
#include "BEHAVIORAL/Visitior.h"
#include <array>

void ClientCode(std::array<const Component*, 2> components, Visitor* visitor) {
    for (const Component* comp : components) {
        comp->Accept(visitor);
    }
}

#endif
#endif // BEHAVIORAL



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
#ifdef BEHAVIORAL
#ifdef pattr1

        HeroHandler* hero = new HeroHandler;
        TowerHandler* tower = new TowerHandler;
        CreepHandler* creep = new CreepHandler;
        hero->SetNext(tower)->SetNext(creep);

        std::cout << "Chain: Hero > Tower > Creep\n\n";
        ClientCode(*hero);
        std::cout << "\n";

        std::cout << "Subchain: Tower > Creep\n\n";
        ClientCode(*tower);

        delete hero;
        delete tower;
        delete creep;

#elif defined (pattr2)
        Command* ability1 = new AbilityCommand("Blink");
        Command* ability2 = new AbilityCommand("Culling Blade");

        Hero* hero = new Hero;

        Command* heroAbility1 = new HeroAbilityCommand(hero, "Mana Break");
        Command* heroAbility2 = new HeroAbilityCommand(hero, "Berserker's Call");

        CommandInvoker* invoker = new CommandInvoker;

        invoker->SetCommand(ability1);
        invoker->ExecuteCommand();

        invoker->SetCommand(heroAbility1);
        invoker->ExecuteCommand();

        invoker->SetCommand(ability2);
        invoker->ExecuteCommand();

        invoker->SetCommand(heroAbility2);
        invoker->ExecuteCommand();

        delete ability1;
        delete ability2;
        delete hero;
        delete heroAbility1;
        delete heroAbility2;
        delete invoker;
#elif defined (pattr3)
        ClientCode();
#elif defined (pattr4)
        ClientCode();
#elif defined (pattr5)
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        ClientCode();
#elif defined (pattr6)
        ClientCode();
#elif defined (pattr7)
        ClientCode();
#elif defined (pattr8)
        clientCode();
#elif defined (pattr9)
        std::cout << "Same client code can work with different heroes:\n";
        AntiMage* antiMage = new AntiMage;
        ClientCode(antiMage);
        std::cout << "\n";

        std::cout << "Same client code can work with different heroes:\n";
        Axe* axe = new Axe;
        ClientCode(axe);

        delete antiMage;
        delete axe;
#elif defined (pattr10)
        std::array<const Component*, 2> components = { new DotaHero, new DotaItem };
        std::cout << "The client code works with all visitors via the base Visitor interface:\n";
        ConcreteVisitor1* visitor1 = new ConcreteVisitor1;
        ClientCode(components, visitor1);
        std::cout << "\n";
        std::cout << "It allows the same client code to work with different types of visitors:\n";
        ConcreteVisitor2* visitor2 = new ConcreteVisitor2;
        ClientCode(components, visitor2);

        for (const Component* comp : components) {
            delete comp;
        }
        delete visitor1;
        delete visitor2;
#endif
#endif // BEHAVIORAL

return 0;
  }