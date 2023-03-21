#pragma once

#include "source/assignments/Statement.hpp"
#include "source/Decl/VarDecl.hpp"


class LocalVarDeclStmt : public Statement,
                         public std::enable_shared_from_this<LocalVarDeclStmt> {
public:
    LocalVarDeclStmt(std::shared_ptr <VarDecl> expr);

    void Accept(std::shared_ptr <Visitor> visitor) override;

    void Perform() const override;

    std::shared_ptr <VarDecl> var_decl;
};
