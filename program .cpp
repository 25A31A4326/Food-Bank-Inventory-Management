#include <iostream>
#include <string>
using namespace std;

class FoodItem {
public:
    int id;
    string name;
    int quantity;
    string expiryDate;

    void addFood() {
        cout << "\nEnter Food ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Food Name: ";
        getline(cin, name);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Expiry Date (DD/MM/YYYY): ";
        getline(cin, expiryDate);
    }

    void displayFood() {
        cout << "\n-----------------------------";
        cout << "\nFood ID      : " << id;
        cout << "\nFood Name    : " << name;
        cout << "\nQuantity     : " << quantity;
        cout << "\nExpiry Date  : " << expiryDate;
        cout << "\n-----------------------------";
    }
};

int main() {

    FoodItem inventory[100];
    int count = 0;
    int choice;
    int searchId;
    int found;

    do {
        cout << "\n\n====== FOOD BANK INVENTORY MANAGEMENT ======";
        cout << "\n1. Add Food Item";
        cout << "\n2. View All Food Items";
        cout << "\n3. Search Food Item";
        cout << "\n4. Update Quantity";
        cout << "\n5. Delete Food Item";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            inventory[count].addFood();
            count++;
            cout << "\nFood Item Added Successfully!";
            break;

        case 2:
            if(count == 0) {
                cout << "\nNo Food Items Available!";
            }
            else {
                for(int i = 0; i < count; i++) {
                    inventory[i].displayFood();
                }
            }
            break;

        case 3:
            cout << "\nEnter Food ID to Search: ";
            cin >> searchId;

            found = 0;

            for(int i = 0; i < count; i++) {
                if(inventory[i].id == searchId) {
                    inventory[i].displayFood();
                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                cout << "\nFood Item Not Found!";
            }

            break;

        case 4:
            cout << "\nEnter Food ID to Update Quantity: ";
            cin >> searchId;

            found = 0;

            for(int i = 0; i < count; i++) {
                if(inventory[i].id == searchId) {

                    cout << "Current Quantity: "
                         << inventory[i].quantity;

                    cout << "\nEnter New Quantity: ";
                    cin >> inventory[i].quantity;

                    cout << "\nQuantity Updated Successfully!";
                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                cout << "\nFood Item Not Found!";
            }

            break;

        case 5:
            cout << "\nEnter Food ID to Delete: ";
            cin >> searchId;

            found = 0;

            for(int i = 0; i < count; i++) {

                if(inventory[i].id == searchId) {

                    for(int j = i; j < count - 1; j++) {
                        inventory[j] = inventory[j + 1];
                    }

                    count--;

                    cout << "\nFood Item Deleted Successfully!";
                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                cout << "\nFood Item Not Found!";
            }

            break;

        case 6:
            cout << "\nThank You for Using the System!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while(choice != 6);

    return 0;
}
