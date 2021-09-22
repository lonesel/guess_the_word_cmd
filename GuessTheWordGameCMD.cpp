// Game «Guess the word»

#include <iostream>
#include <string>

int main()
{
	enum fields {WORD, HINT, NUM_FIELDS};
	const int WORD_COUNT = 5;

	const std::string words[WORD_COUNT][NUM_FIELDS] = {
		{"sugar", "Clean, but not water,\nWhite, but not snow,\nSweet, but not ice - cream."},
		{"fire", "I am always hungry,\nI must always be fed,\nThe finger I touch,\nWill soon turn red."},
		{"button", "I am round like an apple\nFlat as a chip\nI have eyes\nBut I can’t see one bit."},
		{"cloud", "I fly, yet I have no wings.\nI cry, yet I have no eyes.\nDarkness follows me;\nLower light I never see."},
		{"rainbow", "I am purple, yellow, red, and green\nThe King cannot reach me and neither can the Queen.\nI show my colors after the rain\nAnd only when the sun comes out again."}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choise = rand() % WORD_COUNT;
	const std::string hidden_word = words[choise][WORD];
	const std::string hint = words[choise][HINT];
	std::string jumble = hidden_word;
	for (int i = 0; i < jumble.length(); i++) {
		int index1 = rand() % jumble.length();
		int index2 = rand() % jumble.length();
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	std::string guess;

	std::cout << "Welcome to the game \"Guess the word\"!" << std::endl;
	std::cout << "You must name the hidden word." << std::endl;
	std::cout << "To get a hint, enter \"hint\"." << std::endl;
	std::cout << std::endl;
	
	std::cout << "Jumble word is: " << jumble << std::endl;
	std::cout << std::endl;

	while (guess != hidden_word) {
		std::cout << "Enter your answer: ";
		std::cin >> guess;

		if (guess == "hint") {
			std::cout << "Hint:" << std::endl;
			std::cout << hint << std::endl;
			std::cout << std::endl;
		}
		if (guess == hidden_word) {
			std::cout << "Excellent! Word is: " << hidden_word << "." << std::endl;
			std::cout << "You won!";
			std::cout << std::endl;
			break;
		}
		else {
			std::cout << "Ops.. Wrong answer, please try again." << std::endl;
			std::cout << std::endl;
		}
	}
	system("pause");
    return 0;
}