#include <iostream>
#include <map>

// This is a "user-defined" function
// void printstuff()
// {
//   std::cout << "stuff" << std::endl;
// }

bool isValidDate(int day, int month, int year)
{
    if (month < 1 || month > 12)
    {
        std::cout << "The month is not valid. "
            << "It must be between 1 and 12."
            << std::endl;
        return false;
    }

    int minimumPossibleDay = 1;
    int maximumPossibleDay = 31;

    if (day < minimumPossibleDay || day > maximumPossibleDay)
    {
        std::cout << "The day is not valid. It must be between "
            << minimumPossibleDay << " and "
            << maximumPossibleDay << std::endl;
        return false;
    }

    if (year < 1999 || year > 2026)
    {
        std::cout << "The year is not valid." << std::endl;
        return false;
    }

    return true;
}

int calculateAge(int birthDay, int birthMonth, int birthYear,
    int currentDay, int currentMonth, int currentYear)
{
    int age = currentYear - birthYear;

    // If the birthday has not happened yet this year
    if (currentMonth < birthMonth)
    {
        age = age - 1;
    }
    else if (currentMonth == birthMonth && currentDay < birthDay)
    {
        age = age - 1;
    }

    return age;
}

int main()
{
    // First, get the user's birthdate
    int birthDay = -1;
    int birthMonth = -1;
    int birthYear = -1;

    while (isValidDate(birthDay, birthMonth, birthYear) == false)
    {
        // Prompt the user to enter their birthdate
        std::cout << "Enter your birthday (day): " << std::endl;
        std::cin >> birthDay;

        std::cout << "Enter your birth month (1-12): " << std::endl;
        std::cin >> birthMonth;

        std::cout << "Enter your birth year: " << std::endl;
        std::cin >> birthYear;
    }

    int currentDay = 22;
    int currentMonth = 10;
    int currentYear = 2026;

    int age = calculateAge(birthDay, birthMonth, birthYear,
        currentDay, currentMonth, currentYear);

    std::cout << "Your age is: " << age << std::endl;

    return 0;
}