#pragma once

#include "source/assignments/Statement.hpp"
#include "source/Expr/Expression.hpp"


class AssertStmt : public Statement,
                   public std::enable_shared_from_this<AssertStmt> {
public:
    AssertStmt(std::shared_ptr <Expression> expr);

    void Accept(std::shared_ptr <Visitor> visitor) override;

    void Perform() const override;

    std::shared_ptr <Expression> expr;
};
