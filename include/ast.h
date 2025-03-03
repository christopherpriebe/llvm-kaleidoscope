#include <string>

class ExprAST {
   public:
    virtual ~ExprAST() = default;
};

class NumberExprAST : public ExprAST {
    double val;

   public:
    NumberExprAST(double);
};

class VariableExprAST : public ExprAST {
    std::string name;

   public:
    VariableExprAST(std::string &);
};

class BinaryExprAST : public ExprAST {
    char op;
    std::unique_ptr<ExprAST> lhs, rhs;

   public:
    BinaryExprAST(char op, std::unique_ptr<ExprAST>, std::unique_ptr<ExprAST>);
};

class CallExprAST : public ExprAST {
    std::string callee;
    std::vector<std::unique_ptr<ExprAST>> args;

   public:
    CallExprAST(const std::string &, std::vector<std::unique_ptr<ExprAST>>);
};

class FunctionHeaderAST {
    std::string name;
    std::vector<std::string> args;

   public:
    FunctionHeaderAST(std::string &, std::vector<std::string>);
    const std::string &get_name() const;
};

class FunctionAST {
    std::unique_ptr<FunctionHeaderAST> header;
    std::unique_ptr<ExprAST> body;

   public:
    FunctionAST(std::unique_ptr<FunctionHeaderAST>, std::unique_ptr<ExprAST>);
};
