#pragma once
#include "parser.h"
void C_parser(string input_code)
{
	set_input_stream(input_code);
	while (stopped_index < input_code.size()) {
		token_lexeme tl = get_next_token();
		token_definition(tl);
		token_lexeme_vec.push_back(tl);
	}
	for (int i = 0; i < token_lexeme_vec.size(); i++)
	{
		cout <<"Token ¹"<< i << " | Value = "<< 
			token_lexeme_vec[i].value << endl << "Lexeme = " << 
			token_lexeme_vec[i].token_string << endl;
	}
}