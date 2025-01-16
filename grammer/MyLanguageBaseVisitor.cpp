// Generated from study/Language/grammer/MyLanguage.g4 by ANTLR 4.13.2

#include "MyLanguageBaseVisitor.h"

#include "ASTNodes.h"

class ASTBuilderVisitor : public MyLanguageBaseVisitor {
public:
    // Program Rule
    std::any visitProgram(MyLanguageParser::ProgramContext *context) override {
        auto program = std::make_unique<ProgramNode>();
        for (auto stmt : context->statement()) {
            program->statements.push_back(std::any_cast<std::unique_ptr<ASTNode>>(visit(stmt)));
        }
        return program;
    }

    // Statements
    std::any visitVarDeclaration(MyLanguageParser::VarDeclarationContext *context) override {
        auto varDecl = std::make_unique<VarDeclarationNode>();
        varDecl->varName = context->ID()->getText();
        if (context->expression()) {
            varDecl->initializer = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->expression()));
        }
        return varDecl;
    }

    std::any visitAssignment(MyLanguageParser::AssignmentContext *context) override {
        auto assignment = std::make_unique<AssignmentNode>();
        assignment->varName = context->ID()->getText();
        assignment->value = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->expression()));
        return assignment;
    }

    std::any visitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *context) override {
        auto funcDecl = std::make_unique<FunctionDeclarationNode>();
        funcDecl->funcName = context->ID()->getText();
        if (context->parameterList()) {
            for (auto param : context->parameterList()->ID()) {
                funcDecl->parameters.push_back(param->getText());
            }
        }
        funcDecl->body = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->block()));
        return funcDecl;
    }

    std::any visitIfStatement(MyLanguageParser::IfStatementContext *context) override {
        auto ifNode = std::make_unique<IfNode>();
        ifNode->condition = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->expression()));
        ifNode->thenBlock = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->block(0)));
        if (context->block(1)) {
            ifNode->elseBlock = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->block(1)));
        }
        return ifNode;
    }

    std::any visitWhileLoop(MyLanguageParser::WhileLoopContext *context) override {
        auto whileNode = std::make_unique<WhileNode>();
        whileNode->condition = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->expression()));
        whileNode->body = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->block()));
        return whileNode;
    }

    std::any visitForLoop(MyLanguageParser::ForLoopContext *context) override {
        auto forNode = std::make_unique<ForNode>();
        if (context->varDeclaration()) {
            forNode->initializer = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->varDeclaration()));
        } else if (context->assignment()) {
            forNode->initializer = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->assignment()));
        }
        if (context->expression(0)) {
            forNode->condition = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->expression(0)));
        }
        if (context->expression(1)) {
            forNode->update = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->expression(1)));
        }
        forNode->body = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->block()));
        return forNode;
    }

    std::any visitReturnStatement(MyLanguageParser::ReturnStatementContext *context) override {
        auto returnNode = std::make_unique<ReturnNode>();
        if (context->expression()) {
            returnNode->value = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->expression()));
        }
        return returnNode;
    }

    std::any visitBlock(MyLanguageParser::BlockContext *context) override {
        auto block = std::make_unique<BlockNode>();
        for (auto stmt : context->statement()) {
            block->statements.push_back(std::any_cast<std::unique_ptr<ASTNode>>(visit(stmt)));
        }
        return block;
    }

    std::any visitExpressionStatement(MyLanguageParser::ExpressionStatementContext *context) override {
        auto exprStmt = std::make_unique<ExpressionStatementNode>();
        exprStmt->expression = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->expression()));
        return exprStmt;
    }

    // Expressions
    std::any visitComparison(MyLanguageParser::ComparisonContext *context) override {
        auto left = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->addition(0)));
        for (size_t i = 1; i < context->addition().size(); i++) {
            auto binaryExpr = std::make_unique<BinaryExpressionNode>();
            binaryExpr->op = context->children[2 * i - 1]->getText();
            binaryExpr->left = std::move(left);
            binaryExpr->right = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->addition(i)));
            left = std::move(binaryExpr);
        }
        return left;
    }

    std::any visitAddition(MyLanguageParser::AdditionContext *context) override {
        auto left = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->multiplication(0)));
        for (size_t i = 1; i < context->multiplication().size(); i++) {
            auto binaryExpr = std::make_unique<BinaryExpressionNode>();
            binaryExpr->op = context->children[2 * i - 1]->getText();
            binaryExpr->left = std::move(left);
            binaryExpr->right = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->multiplication(i)));
            left = std::move(binaryExpr);
        }
        return left;
    }

    std::any visitMultiplication(MyLanguageParser::MultiplicationContext *context) override {
        auto left = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->unary(0)));
        for (size_t i = 1; i < context->unary().size(); i++) {
            auto binaryExpr = std::make_unique<BinaryExpressionNode>();
            binaryExpr->op = context->children[2 * i - 1]->getText();
            binaryExpr->left = std::move(left);
            binaryExpr->right = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->unary(i)));
            left = std::move(binaryExpr);
        }
        return left;
    }

    std::any visitUnary(MyLanguageParser::UnaryContext *context) override {
        if (context->unary()) {
            auto unaryExpr = std::make_unique<UnaryExpressionNode>();
            unaryExpr->op = context->children[0]->getText();
            unaryExpr->operand = std::any_cast<std::unique_ptr<ASTNode>>(visit(context->unary()));
            return unaryExpr;
        }
        return visit(context->primary());
    }

    std::any visitPrimary(MyLanguageParser::PrimaryContext *context) override {
        if (context->INT()) {
            auto literal = std::make_unique<LiteralNode>();
            literal->value = context->INT()->getText();
            return literal;
        }
        if (context->FLOAT()) {
            auto literal = std::make_unique<LiteralNode>();
            literal->value = context->FLOAT()->getText();
            return literal;
        }
        if (context->STRING()) {
            auto literal = std::make_unique<LiteralNode>();
            literal->value = context->STRING()->getText();
            return literal;
        }
        if (context->ID()) {
            auto identifier = std::make_unique<IdentifierNode>();
            identifier->name = context->ID()->getText();
            return identifier;
        }
        if (context->functionCall()) {
            return visit(context->functionCall());
        }
        if (context->expression()) {
            return visit(context->expression());
        }
        return nullptr;
    }

    std::any visitFunctionCall(MyLanguageParser::FunctionCallContext *context) override {
        auto funcCall = std::make_unique<FunctionCallNode>();
        funcCall->funcName = context->ID()->getText();
        if (context->argumentList()) {
            for (auto arg : context->argumentList()->expression()) {
                funcCall->arguments.push_back(std::any_cast<std::unique_ptr<ASTNode>>(visit(arg)));
            }
        }
        return funcCall;
    }

    std::any visitArgumentList(MyLanguageParser::ArgumentListContext *context) override {
        std::vector<std::unique_ptr<ASTNode>> arguments;
        for (auto expr : context->expression()) {
            arguments.push_back(std::any_cast<std::unique_ptr<ASTNode>>(visit(expr)));
        }
        return arguments;
    }
};

