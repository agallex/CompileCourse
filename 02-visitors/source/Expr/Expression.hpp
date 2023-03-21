#pragma once

#include "source/base_elements/BasicElement.hpp"


class Expression : virtual public BasicElement {
public:
    virtual int Eval() const = 0;
};
