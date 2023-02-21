#include <cmath>
#include <iostream>

class NumberChecker {
public:
    static bool is_prime(int number);
    static bool is_perfect(int number);
    static bool is_palindrome(int number);
    static bool is_square(int number);
};

int main() {
    int number;
    std::cout << "Nhap so: ";
    std::cin >> number;

    std::cout << "1. " << (NumberChecker::is_prime(number) ? "Dung" : "Khong") << " la so nguyen to" << std::endl;
    std::cout << "2. " << (NumberChecker::is_perfect(number) ? "Dung" : "Khong") << " la so hoan hao" << std::endl;
    std::cout << "3. " << (NumberChecker::is_palindrome(number) ? "Dung" : "Khong") << " la so doi xung" << std::endl;
    std::cout << "4. " << (NumberChecker::is_square(number) ? "Dung" : "Khong") << " la so chinh phuong" << std::endl;
    return 0;
}

/*
bool is_prime_old(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
*/

// kiem tra so nguyen to
bool NumberChecker::is_prime(int number) {
    if (number < 2) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }

    for (int i = 3; i < number - 1; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

// kiem tra so hoan hao
bool NumberChecker::is_perfect(int number) {
    int sum = 1;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            sum = (i * i != number) ? sum + i + number / i : sum + i;
        }
    }

    if (sum == number && number != 1) {
        return true;
    }

    return false;
}

// kiem tra doi xung (so doc xuoi nguoc deu duoc)
bool NumberChecker::is_palindrome(int number) {
    int reversed = 0, original = number;

    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    return (reversed == original);
}

// kiem tra chinh phuong
bool NumberChecker::is_square(int number) {
    int temp = sqrt(number);
    return (temp * temp == number);
}
