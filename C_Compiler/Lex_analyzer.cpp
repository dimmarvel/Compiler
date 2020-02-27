#pragma once
#include "Lex_analyzer.h"
/*
Текущий индекс парсинга.
*/
static uint keyword_index;
/*
Здесь хранится код на языке С.*/
static string input_code;
/*
Хранит значение символа на котором остановился парсер.
*/
static uint stopped_index;
/*
void set_keyword_index(uint index); - изменить индекс текущего токена
*/
void set_keyword_index(uint index)
{
	keyword_index = index;
}
/*
void set_keyword_index(uint index); - изменить индекс текущего токена
*/
uint get_keyword_index() 
{
	return keyword_index; 
}
/*
void set_input_stream(char* input); - установить начальные значения
*/
void set_input_stream(string input_cod)
{
	input_code = input_cod;
	stopped_index = 0;
	keyword_index = 0;
}
/*
bool isKeyword(string word) - является ли входящяя строка токеном
*/
bool isKeyword(string word) {

	for (int i = 0; i < keywords_lexeme.size(); i++)
		if (keywords_lexeme[i] == word)
			return true;
	return false;
}
/*
KeywordsLexeme get_next_token(); - получить следующий токен
*/
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
		else
			token = "";
		keyword_index++;

	}
	stopped_index = keyword_index;
	return "ERROR (" + token + ")\n";
}