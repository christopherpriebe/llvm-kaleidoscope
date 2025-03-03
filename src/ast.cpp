#include "ast.h"

#include <string>

NumberExprAST::NumberExprAST(double val) : val(val) {}

VariableExprAST::VariableExprAST(std::string &name) : name(name) {}

BinaryExprAST::BinaryExprAST(char op, std::unique_ptr<ExprAST> lhs,
                             std::unique_ptr<ExprAST> rhs)
    : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}

CallExprAST::CallExprAST(const std::string &callee,
                         std::vector<std::unique_ptr<ExprAST>> args)
    : callee(callee), args(std::move(args)) {}

FunctionHeaderAST::FunctionHeaderAST(std::string &name,
                                     std::vector<std::string> args)
    : name(name), args(std::move(args)) {}

const std::string &FunctionHeaderAST::get_name() const { return this->name; }

FunctionAST::FunctionAST(std::unique_ptr<FunctionHeaderAST> header,
                         std::unique_ptr<ExprAST> body)
    : header(std::move(header)), body(std::move(body)) {}
