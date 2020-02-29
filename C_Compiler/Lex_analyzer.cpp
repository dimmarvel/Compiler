#pragma once
#include "Lex_analyzer.h"
#define DEBUG

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
token_lexeme get_next_token()
{
	token_lexeme temp_token_lexeme = { "undefind", UNDEFIND };
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
					temp_token_lexeme.value = temp_token;
					string temp_IDENTIFIER = token;
					temp_IDENTIFIER.erase(temp_IDENTIFIER.size() - 1, 1);
					if (temp_IDENTIFIER != "") {

						cout << "IDENTIFIER (" + temp_IDENTIFIER + ")" << endl;
					}
					return temp_token_lexeme;
				}

				stopped_index = keyword_index;
				temp_token_lexeme.value = ch_token;
				return temp_token_lexeme;
			}
			else if (isKeyword(token)) {
				stopped_index = ++keyword_index;
				temp_token_lexeme.value = token;
				return temp_token_lexeme;
			}
		}
		else {
#ifdef DEBUG
			if (token != "" && token != " ") {
				cout << "UNDEFINE - token(" << token << ")" << endl;
			}
#endif
			token = "";
		}
		keyword_index++;
	}
	stopped_index = keyword_index;
	temp_token_lexeme.value = token;
#ifdef DEBUG
	cout << "ERROR (" << temp_token_lexeme.value << ")\n";
#endif
	return temp_token_lexeme;
}
void token_definition(token_lexeme tl) {
	if (tl.lexeme != UNDEFIND) {
		if (tl.value == "(") 
		{
			tl.lexeme = OPEN_BRACE;
			tl.token_string = "OPEN_BRACE"; 
		}
		else if (tl.value == ")")
		{
			tl.lexeme = CLOSE_BRACE;
			tl.token_string = "CLOSE_BRACE";
		}
		else if (tl.value == "{")
		{
			tl.lexeme = OPEN_PARENTHESIS;
			tl.token_string = "OPEN_PARENTHESIS";
		}
		else if (tl.value == "}")
		{
			tl.lexeme = CLOSE_PARENTHESIS;
			tl.token_string = "CLOSE_PARENTHESIS";
		}
		else if (tl.value == "")
		{
			tl.lexeme = SEMICOLON;
			tl.token_string = "SEMICOLON";
		}
		else if (tl.value == "int")
		{
			tl.lexeme = INT_KEYWORD;
			tl.token_string = "INT_KEYWORD";
		}
		else if (tl.value == "return")
		{
			tl.lexeme = RETURN_KEYWORD;
			tl.token_string = "RETURN_KEYWORD";
		}
		else {
			tl.lexeme = UNDEFIND;
		}
	}
}

//add push backing