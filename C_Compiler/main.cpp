#include "parser.h"

int main(int argc, char **argv) {
	string code = {"int some->arr>= ++ -- main(){return 0;}"};
	C_parser(code);
	system("pause");
}