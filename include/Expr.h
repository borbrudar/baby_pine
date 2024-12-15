#pragma once
#include <bits/stdc++.h>
#include "Token.h"
class Expr{
};

class Binary : public Expr{
public:
    Binary( Expr left,  Token op,  Expr right){
        this->left = left;
        this->op = op;
        this->right = right;
}
 Expr left;
 Token op;
 Expr right;
};

class Grouping : public Expr{
public:
    Grouping( Expr expression){
        this->expression = expression;
}
 Expr expression;
};

class Literal : public Expr{
public:
    Literal( Expr value){
        this->value = value;
}
 Expr value;
};

class Unary : public Expr{
public:
    Unary( Token op,  Expr right){
        this->op = op;
        this->right = right;
}
 Token op;
 Expr right;
};