// Define the grammar
grammar MyLanguage;

// Parser rules
program         : statement* EOF ;

statement       : variableDeclaration
                | assignment
                | ifStatement
                | functionDeclaration
                | functionCall
                | forStatement
                | printStatement
                ;

variableDeclaration
                : 'let' IDENTIFIER '=' expression ';' ;

assignment      : IDENTIFIER '=' expression ';' ;

ifStatement     : 'if' '(' expression ')' block ('else' block)? ;

functionDeclaration
                : 'func' IDENTIFIER '(' parameterList? ')' block ;

parameterList   : IDENTIFIER (',' IDENTIFIER)* ;

functionCall    : IDENTIFIER '(' argumentList? ')' ';' ;

argumentList    : expression (',' expression)* ;

forStatement    : 'for' '(' variableDeclaration expression ';' assignment ')' block ;

printStatement  : 'print' '(' expression ')' ';' ;

block           : '{' statement* '}' ;

expression      : expression ('*' | '/' | '+' | '-') expression
                | expression ('<' | '<=' | '>' | '>=') expression
                | expression ('==' | '!=') expression
                | '(' expression ')'
                | IDENTIFIER
                | NUMBER
                ;

// Lexer rules
IDENTIFIER      : [a-zA-Z_][a-zA-Z0-9_]* ;
NUMBER          : [0-9]+ ;

WS              : [ \t\r\n]+ -> skip ;
