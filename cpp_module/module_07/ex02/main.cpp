#include <iostream>
#include <Array.hpp>

int main(int, char **) {
  int maxVal = 750;
  Array<int> numbers(maxVal);
  int *mirror = new int[maxVal];
  srand(time(NULL));
  for (int i = 0; i < maxVal; i++) {
	const int value = rand();
	numbers[i] = value;
	mirror[i] = value;
  }

  {
	Array<int> tmp = numbers;
	Array<int> test(tmp);

	tmp[0] = 21;
	test[0] = 42;
	std::cout << "numbers[0]: " << numbers[0] << std::endl;
	std::cout << "tmp[0]: " << tmp[0] << std::endl;
	std::cout << "test[0]: " << test[0] << std::endl;
  }

  try {
	for (int i = 0; i < maxVal; i++) {
	  if (mirror[i] != numbers[i])
		throw std::exception();
	}
  } catch (const std::exception &e) {
	std::cout << "Error: didn't save the same value!!" << std::endl;
  }
  try {
	numbers[-2] = 0;
  }
  catch (const std::exception &e) {
	std::cout << "Error: minus index" << std::endl;
  }
  try {
	numbers[maxVal] = 0;
  }
  catch (const std::exception &e) {
	std::cout << "Error: max index" << std::endl;
  }
  delete[] mirror;
  return 0;
}