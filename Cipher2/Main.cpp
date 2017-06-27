#include <iostream>
#include <string>

char getChar(int chara) {
	while (!(47 < chara && chara < 58) && !(59 < chara && chara < 91) && !(96 < chara && chara < 123)) {
		if (chara > 122) {
			chara = chara % 122;
		}
		chara += 10;
	}
	return chara;
}

void Rotate(std::string& password) {
	int front = 0, back = password.length()-1;
	while ((back - front) > 1) {
		password[front] = getChar(password[front] + password[back]*2);
		password[back] = getChar(password[back] + password[front]*2);
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