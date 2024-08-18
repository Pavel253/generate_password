#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generatePassword(int length) {
  const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "abcdefghijklmnopqrstuvwxyz"
                                  "0123456789"
                                  "!@#$%^&*()_-+=<>?"; 

  std::string password;
  
  for (int i = 0; i< length; ++i) {
    int index = rand() % characters.size();
    password += characters[index];
  }

  return password;
}

int main() {
  std::srand(static_cast<unsigned>(std::time(0)));

  int length;
  std::cout << "Введите длину пароля: ";
  std::cin >> length;

  if (length <= 0) {
      std::cout << "Длина пароля должна быть положительным числом!" << std::endl;
      return 1;
  }

  std::string password = generatePassword(length);
  std::cout << "Сгенерированный пароль: " << password << std::endl;

  return 0;
}