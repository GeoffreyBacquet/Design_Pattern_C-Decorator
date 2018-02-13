#include "sword.h"

int DecoratorElement::degat()
{
    return sword_->degat() + degats_sup_;
}

std::string DecoratorElement::name()
{
    std::string name;
    name.append(name_);
    name.append( " " );
    name.append(sword_->name());
    return name;
}

int DecoratorTier::degat()
{
    return sword_->degat() * degats_sup_;
}

std::string DecoratorTier::name()
{
    std::string name;
    name.append( sword_->name());
    size_t index =  name.find("Tier");
    if(index != std::string::npos)
    {
        name.resize( index );
        name.append( name_ );
    }
    else
    {
        name.append( name_ );
    }

    return name;
}
