#pragma once

#include "source/base_elements/BasicList.hpp"

class ClassDeclList : public BasicList,
                      public std::enable_shared_from_this<ClassDeclList> {
};
