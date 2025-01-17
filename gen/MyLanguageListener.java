// Generated from /Users/mshindarev/Desktop/study/Language/MyLanguage.g4 by ANTLR 4.13.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MyLanguageParser}.
 */
public interface MyLanguageListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(MyLanguageParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(MyLanguageParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(MyLanguageParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(MyLanguageParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#varDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterVarDeclaration(MyLanguageParser.VarDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#varDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitVarDeclaration(MyLanguageParser.VarDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(MyLanguageParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(MyLanguageParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#functionDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDeclaration(MyLanguageParser.FunctionDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#functionDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDeclaration(MyLanguageParser.FunctionDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void enterParameterList(MyLanguageParser.ParameterListContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void exitParameterList(MyLanguageParser.ParameterListContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#ifStatement}.
	 * @param ctx the parse tree
	 */
	void enterIfStatement(MyLanguageParser.IfStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#ifStatement}.
	 * @param ctx the parse tree
	 */
	void exitIfStatement(MyLanguageParser.IfStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#whileLoop}.
	 * @param ctx the parse tree
	 */
	void enterWhileLoop(MyLanguageParser.WhileLoopContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#whileLoop}.
	 * @param ctx the parse tree
	 */
	void exitWhileLoop(MyLanguageParser.WhileLoopContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#forLoopAssignment}.
	 * @param ctx the parse tree
	 */
	void enterForLoopAssignment(MyLanguageParser.ForLoopAssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#forLoopAssignment}.
	 * @param ctx the parse tree
	 */
	void exitForLoopAssignment(MyLanguageParser.ForLoopAssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#forLoop}.
	 * @param ctx the parse tree
	 */
	void enterForLoop(MyLanguageParser.ForLoopContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#forLoop}.
	 * @param ctx the parse tree
	 */
	void exitForLoop(MyLanguageParser.ForLoopContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#returnStatement}.
	 * @param ctx the parse tree
	 */
	void enterReturnStatement(MyLanguageParser.ReturnStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#returnStatement}.
	 * @param ctx the parse tree
	 */
	void exitReturnStatement(MyLanguageParser.ReturnStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(MyLanguageParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(MyLanguageParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#expressionStatement}.
	 * @param ctx the parse tree
	 */
	void enterExpressionStatement(MyLanguageParser.ExpressionStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#expressionStatement}.
	 * @param ctx the parse tree
	 */
	void exitExpressionStatement(MyLanguageParser.ExpressionStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(MyLanguageParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(MyLanguageParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#comparison}.
	 * @param ctx the parse tree
	 */
	void enterComparison(MyLanguageParser.ComparisonContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#comparison}.
	 * @param ctx the parse tree
	 */
	void exitComparison(MyLanguageParser.ComparisonContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#addition}.
	 * @param ctx the parse tree
	 */
	void enterAddition(MyLanguageParser.AdditionContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#addition}.
	 * @param ctx the parse tree
	 */
	void exitAddition(MyLanguageParser.AdditionContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#multiplication}.
	 * @param ctx the parse tree
	 */
	void enterMultiplication(MyLanguageParser.MultiplicationContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#multiplication}.
	 * @param ctx the parse tree
	 */
	void exitMultiplication(MyLanguageParser.MultiplicationContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#unary}.
	 * @param ctx the parse tree
	 */
	void enterUnary(MyLanguageParser.UnaryContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#unary}.
	 * @param ctx the parse tree
	 */
	void exitUnary(MyLanguageParser.UnaryContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#primary}.
	 * @param ctx the parse tree
	 */
	void enterPrimary(MyLanguageParser.PrimaryContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#primary}.
	 * @param ctx the parse tree
	 */
	void exitPrimary(MyLanguageParser.PrimaryContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#functionCall}.
	 * @param ctx the parse tree
	 */
	void enterFunctionCall(MyLanguageParser.FunctionCallContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#functionCall}.
	 * @param ctx the parse tree
	 */
	void exitFunctionCall(MyLanguageParser.FunctionCallContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyLanguageParser#argumentList}.
	 * @param ctx the parse tree
	 */
	void enterArgumentList(MyLanguageParser.ArgumentListContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyLanguageParser#argumentList}.
	 * @param ctx the parse tree
	 */
	void exitArgumentList(MyLanguageParser.ArgumentListContext ctx);
}