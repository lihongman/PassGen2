#include <iostream>
#include <string>

//Rotates characters so they are 0-9, a-z, A-Z, and other characters. Returns the rotated character
char getChar(int chara)
{
	while (chara != 33 && !(47 < chara && chara < 58) && !(59 < chara && chara < 91) && !(96 < chara && chara < 123))
	{
		if (chara > 122) {
			chara = chara % 122;
		}
		chara += 21;
	}
	return chara;
}


//Sums the integer value of the chars in a string.
int sum(std::string& inputs)
{
	int sums = 0;
	for (unsigned int i = 0; i < inputs.length(); ++i)
	{
		sums += inputs[i];
	}
	return sums;
}

//Rotates the password
void rotate(std::string& password)
{
	int front = 0, back = password.length()-1;

	while ((back - front) > 1)
	{
		password[front] = getChar(password[front] + sum(password) + password[back]*2);
		password[back] = getChar(password[back] + +sum(password) + password[front]*2);
		++front;
		--back;
	}
	if ((back - front) == 1)
	{
		password[front + 1] = getChar(password[front + 1] + 100);
	}
}

//Changes password length by repeating from start.
void changeLength(unsigned int& length, std::string& input)
{
	if (length < input.size())
	{
		input = input.substr(0, length);
	}
	else if (length > input.size())
	{
		int i = 0;
		while (length > input.size())
		{
			input += input[i];
			++i;
		}
	}
}


int main()
{
	std::string input, length;
	unsigned int digits;

	std::cout << "Enter you password : ";
	std::getline(std::cin, input);

	std::cout << "Enter desired password length : ";
	std::getline(std::cin, length);

	//Try catch statement to check whether input is appropriate or out of bounds.
	try {
	
		digits = std::stoi(length);
		if (digits < 1)
		{
			throw "Out of Bounds";
		}

		changeLength(digits, input);
		rotate(input);

	} catch (char const* e) {
		//Catches when password length request is less than 1.
		std::cout << e << std::endl;
		input = "N/A";

	} catch (...) {
		//Catches remaining exceptions and ends program.
		std::cout << "An exception occurred..." << std::endl;
		input = "N/A";

	}
	
	std::cout << "Ciphered Password: " << input << std::endl;
	std::cin.get();

	return 0;
}