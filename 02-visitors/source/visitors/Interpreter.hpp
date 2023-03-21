#pragma once

#include <map>

#include "source/base_elements/Elements.hpp"
#include "source/visitors/Visitor.hpp"


class Interpreter : public Visitor,
                    public std::enable_shared_from_this<Interpreter> {
public:
    Interpreter();

    void Visit(std::shared_ptr <Program> program) override;

    void Visit(std::shared_ptr <MainClass> main_class) override;

    void Visit(std::shared_ptr <AssertStmt> assert_stmt) override;

    void Visit(std::shared_ptr <LocalVarDeclStmt> local_var_decl_stmt) override;

    void Visit(std::shared_ptr <StmtListStmt> stmt_list_stmt) override;

    void Visit(std::shared_ptr <IfStmt> if_stmt) override;

    void Visit(std::shared_ptr <IfElseStmt> if_else_stmt) override;

    void Visit(std::shared_ptr <WhileStmt> while_stmt) override;

    void Visit(std::shared_ptr <PrintStmt> print_stmt) override;

    void Visit(std::shared_ptr <AssignmentStmt> assignment_stmt) override;

    void Visit(std::shared_ptr <BinOpExpr> bin_op_expr) override;

    void Visit(std::shared_ptr <TrueExpr> true_expr) override;

    void Visit(std::shared_ptr <FalseExpr> false_expr) override;

    void Visit(std::shared_ptr <IntExpr> int_expr) override;

    void Visit(std::shared_ptr <NewExpr> new_expr) override;

    void Visit(std::shared_ptr <NotExpr> not_expr) override;

    void Visit(std::shared_ptr <IdentExpr> ident_expr) override;

    void Visit(std::shared_ptr <VarDecl> var_decl) override;

    void Visit(std::shared_ptr <Lvalue> lvalue) override;

    int GetResult(std::shared_ptr <Program> program);

private:
    void SetTosValue(int value);

    void UnsetTosValue();

private:
    struct Variable {
        Variable() = default;

        Variable(Type type, bool is_init, int value) : type{std::move(type)}, is_init{is_init}, value{value} {}

        Type type;
        bool is_init = false;
        int value;
    };

    std::map <std::string, Variable> variables;
    int tos_value_;
    bool is_tos_expression_;

};
