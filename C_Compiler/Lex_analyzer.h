#pragma once
#include<iostream>
#include<string>
using namespace std;
typedef unsigned int uint;
typedef string KeywordsLexeme;
enum KEYWORDS;
struct TOKENS;
//ключевые слова\символы\сочетания символов
string const keywords_lexeme[] = {
	"!",	"int",		"->",
	"%",	"double",	"++",
	"^",	"float",	"--",
	"&",	"byte",		".*",
	"*",	"long",		"->*",
	"(",	"char",		"<<",
	")",	"const",	">>",
	"-",	"asm",		"<=",
	"+",	"auto",		">=",
	"=",	"break",	"==",
	"{",	"case",		"!=",
	"}",	"catch",	"&&",
	"|",	"class",	"||",
	"~",	"continue",	"*=",
	"[",	"default",	"/=",
	"]",	"delete",	"%=",
	"\\",	"do",		"+=",
	";",	"else",		"-=",
	"'",	"enum",		"<<=",
	":",	"extern",	">>=",
	"\"",	"for",		"&=",
	"<",	"friend",	"^=",
	">",	"goto",		"|=",
	"?",	"if",		"::"
	",",	"inlune",
	".",	"new",
	"/",	"operator",
			"private",
			"protected",
			"public",
			"register",
			"return",
			"short",
			"signed",
			"sizeof",
			"static",
			"struct",
			"switch",
			"template",
			"this",
			"throw",
			"try",
			"typedef",
			"union",
			"unsigned",
			"virtual",
			"void",
			"volatile",
			"while",
};
enum KEYWORDS {
	OPEN_BRACE,			// {
	CLOSE_BRACE,		// }
	OPEN_PARENTHESIS,	// (
	CLOSE_PAREN,		// )
	SEMICOLON,			// ;
	INT_KEYWORD,		// int
	RETURN_KEYWORD,		// return
	IDENTIFIER,			// [a-z,A-Z]\w*
	INTEGER_LITERAL,	// [0-9]
	UNDEFIND			// undefind token
};
struct TOKENS {
	string value;
	KEYWORDS lexeme;
};
uint get_keyword_index();
void set_keyword_index(uint index);
void set_input_stream(string input_cod);
bool isKeyword(string word);
KeywordsLexeme get_next_token();