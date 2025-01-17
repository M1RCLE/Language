// Generated from /Users/mshindarev/Desktop/study/Language/MyLanguage.g4 by ANTLR 4.13.2
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MyLanguageParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MyLanguageVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(MyLanguageParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#statement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatement(MyLanguageParser.StatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#varDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVarDeclaration(MyLanguageParser.VarDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#assignment}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignment(MyLanguageParser.AssignmentContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#functionDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionDeclaration(MyLanguageParser.FunctionDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#parameterList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameterList(MyLanguageParser.ParameterListContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#ifStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIfStatement(MyLanguageParser.IfStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#whileLoop}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitWhileLoop(MyLanguageParser.WhileLoopContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#forLoopAssignment}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitForLoopAssignment(MyLanguageParser.ForLoopAssignmentContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#forLoop}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitForLoop(MyLanguageParser.ForLoopContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#returnStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReturnStatement(MyLanguageParser.ReturnStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock(MyLanguageParser.BlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#expressionStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionStatement(MyLanguageParser.ExpressionStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(MyLanguageParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#comparison}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComparison(MyLanguageParser.ComparisonContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#addition}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAddition(MyLanguageParser.AdditionContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#multiplication}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiplication(MyLanguageParser.MultiplicationContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#unary}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnary(MyLanguageParser.UnaryContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#primary}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrimary(MyLanguageParser.PrimaryContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#functionCall}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionCall(MyLanguageParser.FunctionCallContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyLanguageParser#argumentList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArgumentList(MyLanguageParser.ArgumentListContext ctx);
}