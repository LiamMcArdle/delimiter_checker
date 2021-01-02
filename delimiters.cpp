// Author : Liam McArdle

#include <iostream>
#include "project_1.hpp"

int main();
void print_program();
bool does_delimiter_match(char delimiter);
bool do_delimiters_nest();

int main() {
	print_program();
	std::cout << does_delimiter_match( '(' ) << std::endl;
	std::cout << does_delimiter_match( '[' ) << std::endl;
	std::cout << does_delimiter_match( '{' ) << std::endl;
	std::cout << do_delimiters_nest() << std::endl;
	return 0;
}

void print_program() {
	ece150::start_reading_file();
	while (ece150::at_eof() == false) {
		std::cout << ece150::get_next_character();
	}
}

bool does_delimiter_match(char delimiter) {
	ece150::start_reading_file();
	int counter = 0;
	int unmatched = 0;
	char ch;
	char result_delimiter;

	if (delimiter == '(') {

		result_delimiter = ')';

	} else if (delimiter == '{') {

		result_delimiter = '}';

	} else if (delimiter == '[') {

		result_delimiter = ']';

	}

	while ((ece150::at_eof()) == false) {
		ch = ece150::get_next_character();

		if ((counter == 0) && (ch == result_delimiter)) {
			unmatched++;
		} else {
			if (ch == delimiter) {
				counter++;
			} else if ( ch == result_delimiter) {
				counter--;
			}
		}
	}

	for (int i = 0; i < unmatched; i++) {
		std::cout << "Unmatched " << result_delimiter << std::endl;
	}
		if (counter >= 1) {
			std::cout << "Missing ";
			for (int i = 0; i < counter; i++) {
				std::cout << result_delimiter;
		}
			std::cout << std::endl;
	} else if (unmatched == 0) {
		return 1;
	}
	else {
		return 0;
	}
	return 0;
}

bool do_delimiters_nest() {
	char ch;
	char ch2;
	char ch3;

	ece150::start_reading_file();
	ece150::initialize_table();

    while ((ece150::at_eof()) == false) {
    	ch = ece150::get_next_character();

		if (ch == '(') {
			ece150::place_character('(');
		}
		else if (ch == '{') {
			ece150::place_character('{');
		}
		else if (ch == '[') {
			ece150::place_character('[');
		}
		else if (ch == ')') {
			ch2 = ece150::get_right_most_character();
			if (ch2 == '(') {
				ece150::erase_right_most_character();
			} else if (ch2 == '{' || ch2 == '[') {
				std::cout << "Unmatched )" << std::endl;
			}
		}
		else if (ch == '}') {
			ch2 = ece150::get_right_most_character();
			if (ch2 == '{') {
				ece150::erase_right_most_character();
			}
			else if (ch2 == '(' || ch2 == '[') {
				std::cout << "Unmatched }" << std::endl;
			}
		}
		else if (ch == ']') {
			ch2 = ece150::get_right_most_character();
			if (ch2 == '[') {
				ece150::erase_right_most_character();
			}
			else if (ch2 == '(' || ch2 == '{') {
				std::cout << "Unmatched ]" << std::endl;
			}
		}
	}

    if (ece150::is_table_empty() == false) {
    	std::cout << "Missing ";
	 while((ece150::is_table_empty()) == false) {
		ch3 = ece150::get_right_most_character();
		if (ch3 == '(') {
			std::cout << ")";
		}
		else if (ch3 == '{') {
			std::cout << "}";
		}
		else if (ch3 == '[') {
			std::cout << "]";
		}
		ece150::erase_right_most_character();

	}
    	std::cout << std::endl;
  }
	return 0;
}

