#include "BasicList.hpp"


BasicList::BasicList() = default;

void BasicList::AddItem(std::shared_ptr <BasicElement> item) {
    items.push_back(item);
}

void BasicList::Accept(const std::shared_ptr <Visitor>& visitor) {
    for (const auto& item: items) {
        item->Accept(visitor);
    }
}
