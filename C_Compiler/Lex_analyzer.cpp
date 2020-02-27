#pragma once
#include "Lex_analyzer.h"
#define DEBUG

static uint keyword_index;						/*
							Текущий индекс парсинга.*/
static string input_code;						/*
							Здесь хранится код на языке С.*/
static uint stopped_index;						/*
							Хранит значение символа на котором остановился парсер.*/
static vector <token_lexeme> Token_lexeme_vec;	/*
							Хранит набор спаршеных токен-лексем*/



void set_keyword_index(uint index)
{
	keyword_index = index;
}
uint get_keyword_index()
{
	return keyword_index;
}
void set_input_stream(string input_cod)
{
	input_code = input_cod;
	stopped_index = 0;
	keyword_index = 0;
}
bool isKeyword(string word) {

	for (int i = 0; i < keywords_lexeme.size(); i++)
		if (keywords_lexeme[i] == word)
			return true;
	return false;
}
KeywordsLexeme get_next_token()
{
	KeywordsLexeme token;
	KeywordsLexeme ch_token;
	keyword_index = stopped_index;

	while (keyword_index <= input_code.size()) {
		if (input_code[keyword_index] != '\n' && input_code[keyword_index] != ' ') {
			
			token += input_code[keyword_index];
			ch_token = input_code[keyword_index];

			if (isKeyword(ch_token)) {
				++keyword_index;
				string temp_token = ch_token + input_code[keyword_index];
				
				if (isKeyword(temp_token)) {
					stopped_index = ++keyword_index;
					return temp_token;
				}
				
				stopped_index = keyword_index;
				return ch_token;
			}
			else if (isKeyword(token)) {
				stopped_index = ++keyword_index;
				return token;
			}
		}
		else {
#ifdef DEBUG
			if (token != "" && token != " ") {
				cout << "UNDEFINE - token(" << ch_token << ")" << endl;
				cout << "UNDEFINE - token(" << token << ")" << endl;
			}
#endif
			token = "";
		}
		keyword_index++;
	}
	stopped_index = keyword_index;
	return "ERROR (" + token + ")\n";
}
TOKENS token_definition() {
	TOKENS some = UNDEFIND;
	return some;
}