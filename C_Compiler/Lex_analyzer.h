#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef unsigned int uint;
typedef string KeywordsLexeme;
enum TOKENS;
struct token_lexeme;
static vector <token_lexeme> token_lexeme_vec;	/*
							Хранит набор спаршеных токен-лексем*/
static uint keyword_index;						/*
							Текущий индекс парсинга.*/
static string input_code;						/*
							Здесь хранится код на языке С.*/
static uint stopped_index;						/*
							Хранит значение символа на котором остановился парсер.*/

/*
Ключевые слова\символы\сочетания символов*/
const vector <string> keywords_lexeme {
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
	",",	"inline",
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

/*
Для определения ключевых слов.*/
enum TOKENS {
	OPEN_BRACE,			/*
	Открывающая скобка */
	CLOSE_BRACE,		/*
	Закрывающая скобка */
	OPEN_PARENTHESIS,	/*
	Открывающая круглая скобка */
	CLOSE_PARENTHESIS,	/*
	Закрывающая круглая скобка*/
	SEMICOLON,			/*
	Ключевое слово "точка с запятой" ; */
	INT_KEYWORD,		/*
	Ключевое слово int */
	RETURN_KEYWORD,		/*
	Ключевое слово return */
	IDENTIFIER,			/*
	Все имена функций и имена переменных*/
	INTEGER_LITERAL,	/*
	Когда код содержит числа не являющиеся частью
	идентификаторов они INTEGER_LITERAL(целочисленные литералы)
	CHANGE - Язык поддерживает только целые числа, а не десятичные и тд.*/
	STRING_LITERAL,		/*
	Строковые литералы являются выражения - которые начинаются с двойных ковычек
	и заканчиваются другой двойной ковычкой
	P.s. для ясности, этот язык не имеет строкового типа.
	Строковые константы на самом деле являются значениями указателя
	которые указывают на конкретное место в памяти где компилятор
	поместил поледовательность символов - которые составляют строку*/
	END_OF_FILE,		/*
	Маркер конца файла*/
	UNDEFIND			/*
	Неизвестное поведение */
};

/*
Токен - это наименьшая единица, которую может понять синтаксический анализатор - 
если программа похожа на абзац, токены подобны отдельным словам.
Лексема - оригинальная строка символов составляющее токен
Пример: 25 + 30
1. Токен "число" с лексемой "25"
2. Токен "арифметическая операция" с лексемой "+"
3. Токен "число" с лексемой "30"                                          */
struct token_lexeme {
	string value;			/*
Значение токена типа string*/
	TOKENS lexeme;			/*
Определение каким является значение взятое из value
value */
	string token_string;	/*
						Представление лексемы в строковом значенииO*/
};


uint get_keyword_index();					/*
						Получить индекс*/
void set_keyword_index(uint index);			/*
Изменить индекс текущего токена
*/
void set_input_stream(string input_cod);	/*
Установить начальные значения*/
bool isKeyword(string word);				/*
Является ли входящяя строка токеном*/
token_lexeme get_next_token();				/*
Получить следующий токен*/
void token_definition(token_lexeme tl);		/*
Определение каким токеном является лексема*/