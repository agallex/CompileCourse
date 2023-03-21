#pragma once

#include <string>
#include "source/base_elements/BasicElement.hpp"
#include "source/visitors/VarScope.hpp"


class Decl : virtual public BasicElement {
public:
    Type type;
    std::string name;
};
