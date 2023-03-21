#pragma once

#include "source/base_elements/BasicList.hpp"

class StmtList : public BasicList,
                 public std::enable_shared_from_this<StmtList> {
};
