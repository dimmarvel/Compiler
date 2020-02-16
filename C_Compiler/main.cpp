#include "parser.h"

int main(int argc, char **argv) {
	string code = {"int some->arr>= ++ inline get next do else -- main(){return 0;}"};
	C_parser(code);
	system("pause");
}