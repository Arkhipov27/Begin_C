#include <iostream>
#include <cctype>
#include <cstring>

void print_no_space(char* text) {
	char* t = text;
	while (*text) {
		if (isspace(*text)) {
			*text = ""[0];
		}
		putchar(tolower(*text));
		text++;
	}
}

int main() {
	char str[1000];
	std::cin.get(str, 1000);
	print_no_space(&str[0]);
}