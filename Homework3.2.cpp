// Homework3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <variant>
#include <string>
#include <vector>

std::variant <int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	auto temp = get_variant();

	switch (temp.index()) {
	case 0:
		std::cout << get<int>(temp) * 2 << std::endl;
		break;
	case 1:
		std::cout << get<std::string>(temp) << std::endl;
		break;
	case 2:
		std::vector<int> temp1 = get<std::vector<int>>(temp);
		for (int i = 0; i < temp1.size(); i++) {
			std::cout << temp1[i] << " ";
		}
		std::cout << std::endl;
		break;
 }
	return 0;
}