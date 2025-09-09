#include <iostream>
#include <vector> // For dynamic arrays
#include <string>   // For string manipulation
#include <numeric>  // For accumulate function
#include <algorithm>    // For sort function
using namespace std;    // For input validation

//function prototypes
int displayMenu();
void runMenu();

// Vector to store grades
vector<double> grades; 

int main() {
    // Initialization
    runMenu();
    // Cleanup
    return 0;
}

// Function to display the menu
int displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add a Grade\n";
    std::cout << "2. Display All Grades\n";
	std::cout << "3. Calculate Average Grade\n";
	std::cout << "4. Find Highest and Lowest Grades\n";
	std::cout << "5. Count Grades Above Threshold\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice (1-5): ";

    int choice;
    std::cin >> choice;

    while (std::cin.fail() || choice < 1 || choice > 6) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a number between 1 and 6: ";
        std::cin >> choice;
	}
    return choice;
}

// Function to get a validated grade input
double getValidatedGrade(const string& prompt) {
	double grade;
	std::cout << prompt;
	std::cin >> grade;

    while (std::cin.fail()) {
		std::cin.clear(); // Clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		std::cout << "Invalid input. Please enter a valid grade: ";
		std::cin >> grade;
    }
	return grade;
}

// Function to run the menu loop
void runMenu() {
    int choice; //The menu selection
    do {
        choice = displayMenu();
        switch (choice) {
		    case 1: {   // Add a grade base on validated input
			    double grade = getValidatedGrade("Enter the grade to add: ");
			    grades.push_back(grade);
			    std::cout << "Grade added successfully.\n";
			    break;
            }
			case 2: {   // Display all grades base on vector contents
                if (grades.empty()) {
                    std::cout << "No grades available.\n";
                }
                else {
                    std::cout << "Grades:\n";
                    for (double grade : grades) {
                        std::cout << grade << " ";
                    }
                    std::cout << "\n" << std::endl;
                }
                break;
            }

			case 3: {   // Calculate average grade base on vector contents
                if (grades.empty()) {
					std::cout << "No grades available to calculate average.\n";
                } 
                else {
					double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
					double average = sum / grades.size();
					std::cout << "Average Grade: " << average << "\n" << std::endl;
                }
				break;
            }

			case 4: { // Find highest and lowest grades
				if (grades.empty()) {
					std::cout << "No grades available to find highest and lowest.\n";
				}
                else {
					double minGrade = *std::min_element(grades.begin(), grades.end());
					double maxGrade = *std::max_element(grades.begin(), grades.end());
					std::cout << "Lowest Grade: " << minGrade << "\n";
                    std::cout << "Highest Grade: " << maxGrade << "\n" << std::endl;
				}
                break;
			}  

			case 5: {   // Count grades above a threshold based on validated input
				if (grades.empty()) {
					std::cout << "No grades available to count.\n";
                    } 
				else {
					double threshold = getValidatedGrade("Enter the threshold grade: ");
					int count = std::count_if(grades.begin(), grades.end(), [threshold](double grade) {return grade > threshold; });
					std::cout << count << " grades are above " << threshold << ".\n" << std::endl;
                    }
				break;
			}

			case 6: // Exiting the program
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        //End of menu selection if 0 was selected
    } while (choice != 0);
}