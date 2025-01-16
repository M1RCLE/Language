#include "ASTBuilder.h"

std::any ASTBuilder::visitProgram(MyLanguageParser::ProgramContext *ctx) {
    auto program = std::make_unique<ASTProgram>();
    for (auto stmtCtx : ctx->statement()) {
        program->statements.push_back(std::any_cast<std::unique_ptr<ASTStatement>>(visit(stmtCtx)));
    }
    return program;
}

std::any ASTBuilder::visitVarDeclaration(MyLanguageParser::VarDeclarationContext *ctx) {
    auto varDecl = std::make_unique<ASTVarDeclaration>();
    varDecl->name = ctx->ID()->getText();
    if (ctx->expression()) {
        varDecl->expression = std::any_cast<std::unique_ptr<ASTExpression>>(visit(ctx->expression()));
    }
    return varDecl;
}

std::any ASTBuilder::visitAssignment(MyLanguageParser::AssignmentContext *ctx) {
    auto assign = std::make_unique<ASTAssignment>();
    assign->name = ctx->ID()->getText();
    assign->expression = std::any_cast<std::unique_ptr<ASTExpression>>(visit(ctx->expression()));
    return assign;
}

std::any ASTBuilder::visitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *ctx) {
    auto funcDecl = std::make_unique<ASTFunctionDeclaration>();
    funcDecl->name = ctx->ID()->getText();
    if (ctx->parameterList()) {
        for (auto param : ctx->parameterList()->ID()) {
            funcDecl->parameters.push_back(param->getText());
        }
    }
    for (auto stmtCtx : ctx->block()->statement()) {
        funcDecl->body.push_back(std::any_cast<std::unique_ptr<ASTStatement>>(visit(stmtCtx)));
    }
    return funcDecl;
}
