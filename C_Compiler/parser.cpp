#pragma once
#include "parser.h"
void C_parser(string input_code)
{
	set_input_stream(input_code);
	while (stopped_index < input_code.size() && keyword_index < input_code.size()) {
		token_lexeme tl = get_next_token();
		token_definition(tl);
		token_lexeme_vec.push_back(tl);
	}
	cout << input_code << endl;
	for (int i = 0; i < token_lexeme_vec.size(); i++)
	{
		cout <<"Token N("<< i << ")\t|\tValue = "<< 
			token_lexeme_vec[i].value << "\t|\tLexeme = " << 
			token_lexeme_vec[i].token_string << "(" <<
			token_lexeme_vec[i].lexeme << ")" << endl;
	}
}