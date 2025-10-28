// Land.cpp (Skeleton)
#include <iostream>

#include "Land.h"

int Land::totalLands = 0;

Land::Land(const std::string& name, int cost, LandType t) : Card(name, cost), landType(t) {
  // TODO: initialize landType
  // TODO: increment totalLands count
    totalLands++;
}

Land::Land(const Land& other) : Card(other.name, other.cost), landType(other.landType) {
  // TODO: increment totalLands count
  totalLands++;
}

Land::~Land() {
    totalLands--;
  // TODO: decrement totalLands count
}

void Land::printInfo() const {
    std::string typeName;

    switch(landType){

        case LandType::FOREST:
            typeName = "Forest";
            break;
        case LandType::MOUNTAIN:
            typeName = "Mountain";
            break;
        case LandType::SWAMP:
            typeName = "Swamp";
            break;
    }

    std::cout << "Land - " << name << " (Cost " << cost << ": " << typeName << " land." << std::endl;
  // TODO: print land details in format:
  // "Land - <name> (Cost <cost>): <TypeName> land."
}

Land::LandType Land::getLandType() const {
  // TODO
    return landType;
}

int Land::getTotalLands() {
    return totalLands;
}
// clone() method creates a deep copy of the Landobject using the copy
// constructor
Card* Land::clone() const { 
    return new Land(*this); 
}
// getType() method returns the Type for a Card object
Card::Type Land::getType() const { 
    return Type::LAND; 
}