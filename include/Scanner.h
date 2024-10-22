#pragma once
#include <bits/stdc++.h>
#include "Token.h"

class Scanner{
    public:
    Scanner(std::string source);

    std::string source;
    std::vector<Token> tokens;
};