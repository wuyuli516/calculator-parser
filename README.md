# Calculator Parser
This is a project for Compiler Theory lesson. Completed in Jan 2023.

## Description
implemented an expression parser which supports the following operations and variable assignments/storage. Note that the symbols are listed in a descending priority.

| category | symbol |
| ------- | ------- |
|     constant    |    id, true, false, decimal, number     |
|parenthesis|()|
|unary operation|+,-,!|
|arithmetic operation|*,/,%|
|arithmetic operation|+,-|
|relational operation|<,<=,>,>=|
|relational operation|==,!=|
|AND|&&|
|OR|\|\||
|assignment|=|

## Platform
* Dev-C++
* Bison (version=1.28)

## CFG Design
### a simple CFG
A simple CFG can be written as follows:

exp → DNUM | INUM | TRUE | FALSE | VAR | VAR ′ = ′ exp |

exp ′|′ ′|′ exp | exp ′&′ ′&′ exp | exp ′ ! ′ ′ = ′ exp |

exp ′ < ′ exp | exp ′ > ′ ′ = ′exp | exp ′ > ′ exp |

exp ′ > ′ ′ = ′ exp | exp ′ = ′ ′ = ′ exp | exp ′ + ′ exp|

exp ′ − ′ exp | exp ′ ∗ ′ exp | exp ′/′ exp | exp ′%′ exp|

′ + ′exp| ′ − ′ exp | ′ ! ′ exp| ′(′ exp ′)′

However, it doesn't consider shift/reduce conflicts. A modified CFG based on priority and associativity is demonstrated below. The code is built upon this CFG.
### a revised CFG
(1) line_list → line | line_list line

(2) line → expression ′\n′ | error ′\n′

(3) expression → orExpr | VAR ′ = ′ expression % prec UMI

(4) orExpr → andExpr | orExpr ′|′ ′|′ andExpr

(5) andExpr → eqExpr | andExpr ′&′ ′&′ eqExpr

(6) eqExpr → cmpExpr | eqExpr′ = ′ ′ = ′ cmpExpr | eqExpr ′ ! ′ ′ = ′ cmpExpr

(7) cmpExpr → addExpr | cmpExpr ′ < ′ addExpr | cmpExpr ′ < ′ ′ = ′ addExpr | cmpExpr ′ > ′ addExpr | cmpExpr ′ > ′ ′ = ′ addExpr

(8) addExpr → mulExpr | addExpr ′ + ′ mulExpr | addExpr ′ − ′ mulExpr

(9) mulExpr → uniExpr | mulExpr ′ ∗ ′ uniExpr | mulExpr ′/′ uniExpr | mulExpr ′%′ uniExpr

(10) uniExpr → single | ′ + ′ uniExpr %prec UMINUS| ′ − ′uniExpr %prec UMINUS | ′ ! ′uniExpr %prec UMINUS | ′ ( ′ expression ′ ) ′

(11) single → DNUM | INUM | VAR | TRUE | FALSE

## Deployment
* install Bison (version=1.28) and set environment variables
* run command under Bison directory
```
bison calculator.y
```

* run command
```
gcc -o calculator calculator.tab.c -std=c11
```
* if everything goes smoothly, calculator.exe will be generated.
## Reference
https://www.gnu.org/software/bison/manual/bison.html

