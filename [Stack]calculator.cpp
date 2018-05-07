#include<bits/stdc++.h>
using namespace std;

enum TokenType {
  kNumeric = 0,
  kPlus,
  kMinus,
  kMultiply,
  kMin,
  kMax,
  kLParen,
  kRParen,
  kEndOfStream,
  kError
};

class Token {
 public:
  Token(const TokenType type)
      : type_(type), text_(nullptr), length_(0) {
  }

  Token(const TokenType type, const char *text, const std::size_t length)
      : type_(type), text_(text), length_(length) {
  }

  Token(const Token &other)
      : type_(other.type_),
        text_(other.text_),
        length_(other.length_) {
  }

  TokenType type() const {
    return type_;
  }

  std::string getText() const {
    return std::string(text_, length_);
  }

 private:
  const TokenType type_;
  const char *text_;
  const std::size_t length_;
};


// Lexer
class Tokenizer {
 public:
  Tokenizer(const std::string &stream)
      : stream_(Sanitize(stream)),
        it_(stream_.c_str()),
        end_(it_ + stream_.length()) {
  }

  // Get next token.
  Token next() {
    if (!tokens_.empty()) {
      Token token = tokens_.top();
      tokens_.pop();
      return token;
    }

    if (it_ >= end_) {
      return Token(kEndOfStream);
    }

    // Look ahead one character
    const char c = *(it_++);

    // Case 1. Parentheses or operators
    switch (c) {
      case '+':  // Fall through
        return Token(kPlus);
      case '-':
        return Token(kMinus);
      case '*':
        return Token(kMultiply);
      case '&':
        return Token(kMax);
      case '|':
        return Token(kMin);
      case '(':
        return Token(kLParen);
      case ')':
        return Token(kRParen);
      default:
        break;
    }

    // Case 2. Number
    if (c == '.' || (c >= '0' && c <= '9')) {
      --it_;
      return nextNumber();
    }

    // Case 3. Guard reached
    if (c == 0) {
      return Token(kEndOfStream);
    }

    // Otherwise, error
    return Token(kError);
  }

  // Rewind tokens
  void push(const Token &token) {
    tokens_.push(token);
  }

 private:
  inline Token nextNumber() {
    const char *begin = it_;
    char c;

    // Integral part
    do {
      c = *(it_++);
    } while (c >= '0' && c <= '9');

    // Dot
    if (c != '.') {
      return Token(kNumeric, begin, (--it_) - begin);
    }

    // Decimal part
    do {
      c = *(it_++);
    } while (c >= '0' && c <= '9');

    const std::size_t length = (--it_) - begin;
    return length == 1 ? Token(kError) : Token(kNumeric, begin, length);
  }

  static std::string Sanitize(const std::string &input) {
    std::string ret;
    for (const char c : input) {
      if (c != ' ') {
        ret.push_back(c);
      }
    }
    // Guard
    ret.push_back(0);
    return ret;
  }

  const std::string stream_;
  const char *it_;
  const char *const end_;
  std::stack<Token> tokens_;
};


// LL(1) recusive descent parser + interpreter
class RecursiveDescentSyntaxDirectedTranslator {
 public:
  RecursiveDescentSyntaxDirectedTranslator(const std::string &expression)
      : tokenizer_(expression) {
  }

  // expr : add_expr
  double eval() {
    double result;
    try {
      result = evalAdd();
      if (tokenizer_.next().type() != kEndOfStream) {
        result = 0;
      }
    } catch (std::exception e) {
      result = 0;
    }
    return result;
  }

 private:
  // add_expr : mult_expr ('+' mult_expr)*
  double evalAdd() {
    double value = evalMult();
    while (expectToken(kPlus)) {
      value += evalMult();
    }
    return value;
  }

  // mult_expr : minmax_expr ('*' minmax_expr)*
  double evalMult() {
    double value = evalMinMax();
    while (expectToken(kMultiply)) {
      value *= evalMinMax();
    }
    return value;
  }

  // minmax_expr : atom_expr (('*'|'|') atom_expr)*
  double evalMinMax() {
    double value = evalAtom();
    while (true) {
      if (expectToken(kMax)) {
        value = std::max(value, evalAtom());
        continue;
      }
      if (expectToken(kMin)) {
        value = std::min(value, evalAtom());
        continue;
      }
      break;
    }
    return value;
  }

  // atom_expr : '-' number | '(' add_expr ')' | number
  double evalAtom() {
    // Case 1. Negative number
    if (expectToken(kMinus)) {
      return -evalAtom();
    }
    // Case 2. Parentheses
    if (expectToken(kLParen)) {
      const double value = evalAdd();
      if (!expectToken(kRParen)) {
        throw std::runtime_error("Unexpected token");
      }
      return value;
    }
    // Case 3. Normal number
    return evalNumber();
  }

  double evalNumber() {
    Token token = tokenizer_.next();
    if (token.type() != kNumeric) {
      throw std::runtime_error("Unexpected token");
    }
    return std::stod(token.getText());
  }

  // Utility method
  bool expectToken(const TokenType type) {
    Token token = tokenizer_.next();
    bool match = (token.type() == type);
    if (!match) {
      tokenizer_.push(token);
    }
    return match;
  }

  Tokenizer tokenizer_;
};

class Calculator {
 public:
  static double Calculate(const std::string &expression) {
    RecursiveDescentSyntaxDirectedTranslator translator(expression);
    return translator.eval();
  }
};

int main() {
  Calculator calc;
  cout << "1 + 2 + 3 = "
    <<calc.Calculate("1 + 2 + 3") << "\n";
  cout << "1 + 2 + 3. | .5 = "
    <<calc.Calculate("1 + 2 + 3. | .5") << "\n";
  cout << "1 + 2 + (3. | .5) & 6.6 * 0.8 = "
    <<calc.Calculate("1 + 2 + (3. | .5) & 6.6 * 0.8") << "\n";
  cout << "-1 + 2 * -3 + -4 * -5 = "
    <<calc.Calculate("-1 + 2 * -3 + -4 * -5") << "\n";
  cout << "1 & 2 * (2 | 3 & 2.5) + (-(-30) * .5) & (6.6 * 0.8) = " 
    <<calc.Calculate("1 & 2 * (2 | 3 & 2.5) + (-(-30) * .5) & (6.6 * 0.8)") << "\n";

  return 0;
}
//https://instant.1point3acres.com/thread/294263