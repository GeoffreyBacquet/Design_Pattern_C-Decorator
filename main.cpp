#include <QCoreApplication>
#include "sword.h"
#include <memory>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    auto Weapon1 = std::unique_ptr< Sword >(std::make_unique< One_handed>() );
    std::cout << "Weapon1 address " << &Weapon1 << std::endl;
    std::cout << Weapon1->name() << " deals " << Weapon1->degat() << " damages" << std::endl << std::endl;

    Weapon1 = std::make_unique< Fire >( std::move( Weapon1 ) );
    std::cout << "Weapon1 address " << &Weapon1 << std::endl;
    std::cout << Weapon1->name() << " deals " << Weapon1->degat() << " damages" << std::endl << std::endl;

    Weapon1 = std::make_unique< TierII >( std::move( Weapon1 ) );
    std::cout << "Weapon1 address " << &Weapon1 << std::endl;
    std::cout << Weapon1->name() << " deals " << Weapon1->degat() << " damages" << std::endl << std::endl;

    Weapon1 = std::make_unique< TierIII >( std::move( Weapon1 ) );
    std::cout << "Weapon1 address " << &Weapon1 << std::endl;
    std::cout << Weapon1->name() << " deals " << Weapon1->degat() << " damages" << std::endl << std::endl;

}
