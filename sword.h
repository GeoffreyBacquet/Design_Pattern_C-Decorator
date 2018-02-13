#ifndef SWORD_H
#define SWORD_H
#include <iostream>
#include <memory>

//////////////////////////////
///      Virtual class     ///
//////////////////////////////
class Sword
{
public:
    virtual int degat() = 0;
    virtual std::string name() = 0;
};

//////////////////////////////
///      Weapon type       ///
//////////////////////////////
class One_handed : public Sword
{
public:
    int degat() override { return 10; }
    std::string name() override { return "One handed Sword"; }
};

class Two_handed : public Sword
{
public:
    int degat() override { return 20; }
    std::string name() override { return "Two handed Sword"; }
};

//////////////////////////////
///   Decorator Element    ///
//////////////////////////////

class DecoratorElement : public Sword
{
public:
    DecoratorElement( std::unique_ptr< Sword > sword, int degats_sup, std::string prefix_name )
        : sword_( std::move( sword ) ), degats_sup_( degats_sup ), name_( prefix_name )
    {}
    int degat() override;
    std::string name() override;
protected:
    std::unique_ptr< Sword > sword_;
    int degats_sup_;
    std::string name_;
};

//////////////////////////////
///      Element type      ///
//////////////////////////////

class Fire : public DecoratorElement
{

public:
    Fire( std::unique_ptr< Sword > sword ) : DecoratorElement( std::move( sword ), 10, "Fire" ) {}

};

class Ice : public DecoratorElement
{

public:
    Ice( std::unique_ptr< Sword > sword ) : DecoratorElement( std::move( sword ), 10, "Ice" ) {}

};

class Lightning : public DecoratorElement
{

public:
    Lightning( std::unique_ptr< Sword > sword) : DecoratorElement( std::move( sword ), 10, "Lightning" ) {}
};

//////////////////////////////
///    Decorator Tier      ///
//////////////////////////////
class DecoratorTier : public Sword
{
public:
    DecoratorTier( std::unique_ptr< Sword > sword, int degats_sup, std::string suffix_name )
        : sword_( std::move( sword ) ), degats_sup_( degats_sup ), name_( suffix_name )
    {}
    int degat() override;
    std::string name();
protected:
    std::unique_ptr< Sword > sword_;
    int degats_sup_;
    std::string name_;
};

//////////////////////////////
///        Tier Type       ///
//////////////////////////////

class TierI : public DecoratorTier
{

public:
    TierI( std::unique_ptr< Sword > sword ) : DecoratorTier(std::move( sword ), 1, " Tier I" ) {}
};

class TierII : public DecoratorTier
{

public:
    TierII( std::unique_ptr< Sword > sword ) : DecoratorTier(std::move( sword ), 2, " Tier II" ) {}
};

class TierIII : public DecoratorTier
{

public:
    TierIII( std::unique_ptr< Sword > sword ) : DecoratorTier( std::move( sword ), 3, " Tier III" ) {}
};

class TierIV : public DecoratorTier
{

public:
    TierIV( std::unique_ptr< Sword > sword ) : DecoratorTier( std::move( sword ), 4, " Tier IV" ) {}
};


#endif // SWORD_H
