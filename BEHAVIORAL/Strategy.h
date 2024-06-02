#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include <memory>
#include <string>


class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual std::string UseAbility(const std::string& hero) const = 0;
};


class Context
{
   
private:
    std::unique_ptr<Strategy> strategy_;

public:
    explicit Context(std::unique_ptr<Strategy>&& strategy = {}) : strategy_(std::move(strategy))
    {
    }

    void set_strategy(std::unique_ptr<Strategy>&& strategy)
    {
        strategy_ = std::move(strategy);
    }

    void PerformAbility() const
    {
        if (strategy_)
        {
            std::cout << "Context: Performing ability using the strategy (not sure which one it is)\n";
            std::string result = strategy_->UseAbility("Hero");
            std::cout << result << "\n";
        }
        else
        {
            std::cout << "Context: Strategy isn't set\n";
        }
    }
};


class AntiMageStrategy : public Strategy
{
public:
    std::string UseAbility(const std::string& hero) const override
    {
        return hero + " uses Blink.\n";
    }
};

class AxeStrategy : public Strategy
{
public:
    std::string UseAbility(const std::string& hero) const override
    {
        return hero + " uses Berserker's Call.\n";
    }
};

#endif // STRATEGY_H
