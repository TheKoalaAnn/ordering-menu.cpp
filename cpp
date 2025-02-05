
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const double DISCOUNT_RATE = 0.10; // Enter the 10% discount amount
const double DISCOUNT_THRESHOLD = 100.00; // Discount applies if bill is over R100, if under R100 discount does not apply
// Menu prices for the cafeteria
const double COFFEE_PRICE = 15.00;
const double SANDWICH_PRICE = 30.00;
const double SALAD_PRICE = 25.00;
const double JUICE_PRICE = 10.00;
const double MUFFIN_PRICE = 20.00;
const double PIZZA_PRICE = 35.00;
const double SOUP_PRICE = 18.00;
const double BURGER_PRICE = 40.00;
void displayMenu() {
cout << " Cafeteria Menu:\n";
//ITPPA1-44 EDUV4908885 FORMATIVE

cout << "1. Coffee - R15.00\n";
cout << "2. Sandwich - R30.00\n";
cout << "3. Salad - R25.00\n";
cout << "4. Juice - R10.00\n";
cout << "5. Muffin - R20.00\n";
cout << "6. Pizza Slice - R35.00\n";
cout << "7. Soup - R18.00\n";
cout << "8. Burger - R40.00\n";
}
double getItemPrice(int itemNumber) {
switch (itemNumber) {
case 1: return COFFEE_PRICE;
case 2: return SANDWICH_PRICE;
case 3: return SALAD_PRICE;
case 4: return JUICE_PRICE;
case 5: return MUFFIN_PRICE;
case 6: return PIZZA_PRICE;
case 7: return SOUP_PRICE;
case 8: return BURGER_PRICE;
default: return 0.0;
}
}
int main() {
string firstName, lastName;
// ITPPA1-44 EDUV4908885 FORMATIVE

int itemCount = 0;
double totalBill = 0.0;
// Get customer's name and surname
cout << "Please enter your first name: ";
cin >> firstName;
cout << "Please enter your last name: ";
cin >> lastName;
// Display the menu
displayMenu();
cout << "How many items would you like to order (up to 8)? ";
cin >> itemCount;
if (itemCount < 1 || itemCount > 8) {
cout << "Invalid item count. Please order between 1 and 8 items.\n";
return 1;
}
// Loop through each item and get the price
for (int i = 1; i <= itemCount; i++) {
int itemNumber;
cout << "Enter the item number only " << i << ": ";
cin >> itemNumber;
ITPPA1-44 EDUV4908885 FORMATIVE

if (itemNumber < 1 || itemNumber > 8) {
cout << "Invalid item number. Please select a number between 1 and 8.\n";
i--; // Adjust loop counter for retry
continue;
}
totalBill += getItemPrice(itemNumber);
}
// Apply discount if applicable
double discount = 0.0;
if (totalBill > DISCOUNT_THRESHOLD) {
discount = totalBill * DISCOUNT_RATE;
totalBill -= discount;
}
// Display the bill details and the total with the discount if applicable
cout << fixed << setprecision(2);
cout << "\nTotal bill: R" << totalBill + discount;
if (discount > 0) {
cout << "\nDiscount applied: R" << discount;
}
cout << "\nFinal bill after discount: R" << totalBill << endl;
// Save to file in the appropriate folder
ofstream outfile("Cafeteria_Order.txt", ios::app);
ITPPA1-44 EDUV4908885 FORMATIVE

if (outfile.is_open()) {
outfile << "Customer: " << firstName << " " << lastName << endl;
outfile << "Total bill: R" << totalBill + discount << endl;
if (discount > 0) {
outfile << "Discount applied: R" << discount << endl;
}
outfile << "Final bill after discount: R" << totalBill << endl;
outfile << "--------------------------" << endl;
outfile.close();
cout << "Order saved to Cafeteria_Order.txt" << endl;
}
else {
cout << "Error saving the order to file, please try again." << endl;
}
return 0;
}
