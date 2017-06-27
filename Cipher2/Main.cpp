#include <iostream>
#include <string>

char getChar(int chara) {
	while (chara != 33 && !(47 < chara && chara < 58) && !(59 < chara && chara < 91) && !(96 < chara && chara < 123)) {
		if (chara > 122) {
			chara = chara % 122;
		}
		chara += 21;
	}
	return chara;
}

int sum(std::string& inputs) {
	int sums = 0;
	for (unsigned int i = 0; i < inputs.length(); ++i) {
		sums += inputs[i];
	}
	return sums;
}

void Rotate(std::string& password) {
	int front = 0, back = password.length()-1;
	while ((back - front) > 1) {
		password[front] = getChar(password[front] + sum(password) + password[back]*2);
		password[back] = getChar(password[back] + +sum(password) + password[front]*2);
		++front;
		--back;
	}
	if ((back - front) == 1) {
		password[front + 1] = getChar(password[front + 1] + 100);
	}
}


int main() {
	std::string input;

	std::cout << "Enter you password : ";
	std::getline(std::cin, input);
	Rotate(input);
	
	std::cout << "Ciphered Password: " << input << std::endl;
	std::cin.get();
}