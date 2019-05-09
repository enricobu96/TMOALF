grammar tinyrexx;

program   : statement+;

statement : assign | print | input | w_loop | f_loop | i_t_e | b_op | terminate;

assign    : ID '=' a_expr | ID '=' b_op;
print     : 'say' a_expr ;
input     : 'pull' ID ;
w_loop    : 'do' 'while' test statement+ 'end' ;
f_loop    : 'do' f_cond statement+ 'end';
test      : a_expr r_op a_expr;
i_t_e     : if_cond do_block | if_cond do_block else_cond do_block;
if_cond   : 'if' b_op 'then';
do_block  : 'do' statement+ 'end';
else_cond : 'else';
a_expr    : ID | NUMBER | '(' a_expr ')' | a_expr a_op a_expr | MINUS a_expr ;
a_op      : MINUS | PLUS | MUL | DIV ;
r_op      : EQUAL | LT | LEQ | GT | GEQ | DISEQUAL;
b_op      : b_op AND b_op | b_op OR b_op | NOT b_op | OB b_op CB | test;
f_cond    : OB f_cond CB | ID '=' a_expr 'to' a_expr | b_op;
terminate : 'exit' a_expr;

OB        : '(' ;
CB        : ')' ;
AND       : '&' ;
OR        : '|' ;
NOT       : '\\' ;
MINUS     : '-' ;
PLUS      : '+' ;
MUL       : '*' ;
DIV       : '/' ;
EQUAL     : '==' ;
DISEQUAL  : '!=' ;
LT        : '<' ;
LEQ       : '<=' ;
GT        : '>' ;
GEQ       : '>=' ;
ID        : [a-z]+ ;
NUMBER    : [0-9]+ ;
WS        : [ \n\t]+ -> skip;
ErrorChar : . ;
