#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <string>

class HeroSelection {
public:
    std::string PickHero() const {
        return "Hero Selection: Choose your hero!\n";
    }

    std::string BanHero() const {
        return "Hero Selection: Ban enemy heroes!\n";
    }
};

class ItemShop {
public:
    std::string BuyItem() const {
        return "Item Shop: Purchase your items!\n";
    }

    std::string SellItem() const {
        return "Item Shop: Sell unwanted items!\n";
    }
};

class Dota2Facade {
private:
    HeroSelection* heroSelection_;
    ItemShop* itemShop_;

public:
    Dota2Facade(HeroSelection* heroSelection = nullptr, ItemShop* itemShop = nullptr) {
        this->heroSelection_ = heroSelection ? heroSelection : new HeroSelection;
        this->itemShop_ = itemShop ? itemShop : new ItemShop;
    }

    ~Dota2Facade() {
        delete heroSelection_;
        delete itemShop_;
    }

    std::string PlayGame() {
        std::string result = "Dota 2: Prepare for battle!\n";
        result += this->heroSelection_->PickHero();
        result += this->heroSelection_->BanHero();
        result += this->itemShop_->BuyItem();
        result += this->itemShop_->SellItem();
        return result;
    }
};

#endif // FACADE_H
