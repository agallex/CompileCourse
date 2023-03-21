#pragma once

#include <string>

// base_elements
class BasicList;

// program
class Program;

class MainClass;

class ClassDeclList;

// assignments
class Statement;

class AssertStmt;

class LocalVarDeclStmt;

class StmtListStmt;

class IfStmt;

class IfElseStmt;

class WhileStmt;

class PrintStmt;

class AssignmentStmt;

class StmtList;

// Expr
class Expression;

class BinOpExpr;

class TrueExpr;

class FalseExpr;

class IntExpr;

class NewExpr;

class NotExpr;

class IdentExpr;

// Decl
class Decl;

class VarDecl;

class ClassDecl;

class DeclList;

// value categories
class Lvalue;

struct Type {
    Type() = default;
    std::string type;
    bool is_array;
};
