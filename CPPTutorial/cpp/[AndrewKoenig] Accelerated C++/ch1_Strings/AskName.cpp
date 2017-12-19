// Koenig book

// ask for name and greet the person

#include <iostream>
#include <string>

void askAndGetName() {
    std::cout << "Please enter your first name: ";

    std::string name; // define the name
    std::cin >> name; //read into

    std::cout << "Hello, " << name << "!" << std::endl;
}

void askNameAndShowElaborateGreeting(){
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;

    //build the message
    const std::string greeting = "Hello, " + name + "!";

    //build the second and fourth lines
    const std::string spaces(greeting.size(), ' ');
    const std:: string second = "* " + spaces + " *";

    //build the first and fifth lines
    const std::string first(second.size(), '*');

    //write it all
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
}


void testExercise4() {

    {
        const std::string s = "a string";
        std::cout << s << std::endl;
        {
            const std::string s = "another string";
            std::cout << s << std::endl;
        };
    }
}

void testExercise5() {
    {
        std::string s = "a string";
        {
            std::string x = s + ", really";
            std::cout << s << std::endl;
            std::cout << x << std::endl;
        }
    }
}


void testExercise6() {
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << std::endl << "And what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;
}


int main(){
    //askAndGetName();
    askNameAndShowElaborateGreeting();
    //testExercise6();
}