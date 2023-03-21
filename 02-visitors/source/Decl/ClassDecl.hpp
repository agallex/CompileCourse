#pragma once

#include "Decl.hpp"
#include "DeclList.hpp"
#include "source/visitors/Visitor.hpp"


class ClassDecl : public Decl,
                  public std::enable_shared_from_this<ClassDecl> {
public:
    ClassDecl(std::shared_ptr <DeclList> decl_list);

    void Accept(std::shared_ptr <Visitor> visitor) override;

    std::shared_ptr <DeclList> decl_list;
};
