#pragma once

#include "source/base_elements/BasicElement.hpp"


class Statement : virtual public BasicElement {
public:
    virtual void Perform() const = 0;
};
