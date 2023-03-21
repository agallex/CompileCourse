#pragma once

#include "source/base_elements/BasicList.hpp"

class DeclList : public BasicList,
                 public std::enable_shared_from_this<DeclList> {
};
