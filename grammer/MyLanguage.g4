grammar MyLanguage;

// Rules
program
    : statement* EOF
    ;

statement
    : varDeclaration
    | assignment
    | functionDeclaration
    | ifStatement
    | whileLoop
    | forLoop
    | expressionStatement
    | returnStatement
    ;

varDeclaration
    : 'let' ID ('=' expression)? ';'
    ;

assignment
    : ID '=' expression ';'
    ;

functionDeclaration
    : 'func' ID '(' parameterList? ')' block
    ;

parameterList
    : ID (',' ID)*
    ;

ifStatement
    : 'if' '(' expression ')' block ('else' block)?
    ;

whileLoop
    : 'while' '(' expression ')' block
    ;

forLoop
    : 'for' '(' (varDeclaration | assignment | ';') expression? ';' (expression | assignment)? ')' block
    ;

returnStatement
    : 'return' expression? ';'
    ;

block
    : '{' statement* '}'
    ;

expressionStatement
    : expression ';'
    ;

expression
    : comparison
    ;

comparison
    : addition (( '==' | '!=' | '<' | '<=' | '>' | '>=' ) addition)*
    ;

addition
    : multiplication (('+' | '-') multiplication)*
    ;

multiplication
    : unary (('*' | '/') unary)*
    ;

unary
    : ('+' | '-' | '!') unary
    | primary
    ;

primary
    : INT
    | FLOAT
    | STRING
    | 'true'
    | 'false'
    | '(' expression ')'
    | ID
    | functionCall
    ;

functionCall
    : ID '(' argumentList? ')'
    ;

argumentList
    : expression (',' expression)*
    ;

// Tokens
ID          : [a-zA-Z_][a-zA-Z_0-9]* ;
INT         : [0-9]+ ;
FLOAT       : [0-9]+ '.' [0-9]+ ;
STRING      : '"' (~["\\] | '\\' .)* '"' ;
WS          : [ \t\r\n]+ -> skip ;
COMMENT     : '//' ~[\r\n]* -> skip ;
MULTILINE_COMMENT : '/*' .*? '*/' -> skip ;
