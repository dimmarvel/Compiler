/*
uint get_keyword_index(); - получить индекс текущего токена
void set_keyword_index(uint index); - изменить индекс текущего токена
void set_input_stream(char* input); - установить начальные значения
KeywordsLexeme get_next_token(); - получить следующий токен
*/
#pragma once
#include "Lex_analyzer.h"
static uint keyword_index;
static string input_code;
static uint stopped_index;

void set_keyword_index(uint index) { keyword_index = index; }
uint get_keyword_index() { return keyword_index; }

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
	KeywordsLexeme token; int tI = 0;
	keyword_index = stopped_index;

	while (keyword_index < input_code.size()) {
		if (input_code[keyword_index] != '\n' && input_code[keyword_index] != ' ') {
			token += input_code[keyword_index];
		}
		if (isKeyword(token)) {
			return token;
		}
		keyword_index++;
	}

	return "EOF (" + token + ")\n";
}