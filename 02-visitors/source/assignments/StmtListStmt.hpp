#pragma once

#include "source/assignments/Statement.hpp"
#include "source/assignments/StmtList.hpp"


class StmtListStmt : public Statement,
                     public std::enable_shared_from_this<StmtListStmt> {
public:
    StmtListStmt(std::shared_ptr <StmtList> stmt_list);

    void Accept(std::shared_ptr <Visitor> visitor) override;

    void Perform() const override;

    std::shared_ptr <StmtList> stmt_list;
};
