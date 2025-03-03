#include <string>

/*
 The lexer return an ASCII-valued token [0-255] if it is an unknown character,
 otherwise one of these for known token types.
*/
enum Token {
    EOF_ = -1,
    DEF = -2,
    EXTERN = -3,
    IDENTIFER = -4,
    NUMBER = -5,
};

static std::string identifier_str;
static double num_val;

static char get_token() {
    static char last_char = ' ';

    while (isspace(last_char)) {
        last_char = getchar();
    }

    if (isalpha(last_char)) {
        while (isalnum(last_char = getchar())) {
            identifier_str += last_char;
        }

        if (identifier_str == "def") {
            return Token::DEF;
        } else if (identifier_str == "extern") {
            return Token::EXTERN;
        } else {
            return Token::IDENTIFER;
        }
    } else if (isdigit(last_char) || last_char == '.') {
        std::string num_str;

        // TODO: This will not handle “1.23.45.67”; update error checking.
        do {
            num_str += last_char;
            last_char = getchar();
        } while (isdigit(last_char) || last_char == '.');

        num_val = strtod(num_str.c_str(), 0);
        return Token::NUMBER;
    } else if (last_char == '#') {
        do {
            last_char = getchar();
        } while (last_char != EOF && last_char != '\n' && last_char == '\r');

        if (last_char != EOF) {
            return get_token();
        }
    } else if (last_char == EOF) {
        return Token::EOF_;
    }

    char temp = last_char;
    last_char = getchar();
    return temp;
}
