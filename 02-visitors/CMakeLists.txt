cmake_minimum_required(VERSION 3.22)
project(JavaCompiler)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
        HEADERS
        ${JavaCompiler_SOURCE_DIR}/driver.hh
        ${JavaCompiler_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
        MyParser
        parser.y
        ${JavaCompiler_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${JavaCompiler_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${JavaCompiler_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${JavaCompiler_SOURCE_DIR}/bin)

set(
        SOURCES
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        source/program/Program.cpp
        source/program/MainClass.cpp

        source/assignments/PrintStmt.cpp
        source/assignments/AssertStmt.cpp
        source/assignments/LocalVarDeclStmt.cpp
        source/assignments/StmtListStmt.cpp
        source/assignments/ConditionalStmt.cpp
        source/assignments/PrintStmt.cpp
        source/assignments/AssignmentStmt.cpp
        source/assignments/LocalVarDeclStmt.cpp

        source/Expr/BinOpExpr.cpp
        source/Expr/BoolConstExpr.cpp
        source/Expr/IntExpr.cpp
        source/Expr/NotExpr.cpp
        source/Expr/IdentExpr.cpp

        source/base_elements/BasicList.cpp

        source/Decl/VarDecl.cpp
        source/Decl/ClassDecl.cpp

        source/visitors/Lvalue.cpp

        source/visitors/PrintVisitor.cpp
        source/visitors/Interpreter.cpp
)

add_executable(
        JavaCompiler
        ${JavaCompiler_SOURCE_DIR}/main.cpp
        ${SOURCES}
)

target_include_directories(JavaCompiler PRIVATE ${JavaCompiler_SOURCE_DIR})
target_include_directories(JavaCompiler PRIVATE
        ${JavaCompiler_SOURCE_DIR}/include
        )
