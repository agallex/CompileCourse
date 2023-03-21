#pragma once

#include <memory>

#include "MainClass.hpp"
#include "ClassDeclList.hpp"
#include "source/visitors/Visitor.hpp"


class Program : public std::enable_shared_from_this<Program> {
public:
    Program(std::shared_ptr <MainClass> main_class,
            std::shared_ptr <ClassDeclList> class_decl_list);

    Program(std::shared_ptr <MainClass> main_class);

    void Accept(std::shared_ptr <Visitor> visitor);

    std::shared_ptr <MainClass> main_class;
    std::shared_ptr <ClassDeclList> class_decl_list;
};
