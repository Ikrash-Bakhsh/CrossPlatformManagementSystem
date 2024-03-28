#include <iostream>
#include <iomanip>
#include <vector> // used for dymanic memory to print bill beacause the bill my be long and array do not have that mush of memory to store all of it or to store the different type of data type
#include <string>
#include <map> //it is used to store the menu and its prices if we use if eles it would take very lang and not efficient way to make 

using namespace std;
string arr1[100], arr2[100], arr3[100], arr4[100], arr5[100], arr6[100], arr7[100];
int total;
void billingSystem();
void menu_system();
void LMS_System();
void enter();
void show();
void search();
void update();
void deleted();
void interface();
void add(string name[], int price[][2],int size1);
void changep(string name[], int price[][2]);
void del(string name[], int price[][2], int size1);
    string name[8] = {"beef biryani", "chicken biryani", "beef pulao", "chicken pulao", "chicken karahi", "chicken kebab", "roti(1 piece)", "mineral water"};


void billingSystem() 
    // billing system code here
    {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "WELCOME !!!!!";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "BILLING SYSTEM RESTAURANT !!!";
    cout << endl;

    // Map to store menu items and their prices its syntax is name of the map here its is the menu and with in the type of variable u want to store in this case the string and double is used that is used to store the value of product and its price 
    map<string, double> menu;

    //  the menu 
    menu["tikka pizza"] = 10.99;
    menu["supreme pizza"] = 9.99;
    menu["fajita pizza"] = 8.99;
    menu["burger"] = 5.99;
    menu["pepsi"] = 2.99;
    menu["coke"] = 2.99;
    menu["shawarma"] = 5.99;
    menu["water"] = 1.99;
    menu["doner"] = 4.99;
    menu["tacos"] = 12.99;
    menu["chocolate and brownie"] = 7.99;
    menu["sandwich"] = 3.99;
    menu["grilled chicken"] = 15.99;
    menu["fish"] = 15.99;
    menu["fries"] = 5.99;
    menu["loaded fires"] = 9.99;
    menu["bbq"] = 15.99;
    menu["ice cream"] = 2.99;
    // Add more items to the menu as needed or remove if nessesery 

    double grandTotal = 0.0; // Variable to store the grand total of all bills in the day 

    do {  // we used the do to make interface run until the user enter the 0 and it will exit the loop
        int numVariables;
         cout << endl;
         cout << endl;
         // its takes the number of item and the loop is executer addording tu the value enter by the user

        cout << "Enter the number of items (enter 0 to exit): ";
        cin >> numVariables;

        if (numVariables == 0) {
            // Exit the loop if the user enters 0 
            break;
        }

        vector<string> names(numVariables);// first we write the vector then declear its type in <> here we used the string then the name of the vector that is "names"and then decleared its size that we have taken foem the user  
        vector<int> quantities(numVariables); //same here
        vector<double> prices(numVariables); // same here
        double GST=0.0; // variable for GST 
        double total1=0.0; //variable for total with GST included 

        double total = 0.0; // Variable to store the total of the current bill

        for (int i = 0; i < numVariables; ++i) { // in this loop the the userwill be asked to enter the products and its name according to the number the user has entered above in numVariable 
            cout << "Enter details for item " << i + 1 << ":" << endl;

            cout << "Name: ";
            cin.ignore();  // Clear the input buffer
            getline(cin, names[i]);

            // Check if the entered item is in the menu
            if (menu.find(names[i]) != menu.end()) {
                // If the item is in the menu, use its price
                prices[i] = menu[names[i]]; // Array is used to store multiple value in variable like its price product and their name until the i = numVariable
            } else { // if not found the option is provieded to enter it maually
                cout << "Item not found in the menu. Enter price manually: $";
                cin >> prices[i]; //here it takes the price if the product is not decleared in the menu
                if(prices[i]<0)
        
            }

            cout << "Quantity: ";
            cin >> quantities[i]; //here is the how many quantity of product are entered 

            // Update the total for the current bill
            total = total + prices[i] * quantities[i]; //the quantities are multiplied by the decleared price and added to gether 
           
        }
         GST=0.18 * total;
            total1=total +GST; // Calculats the GST tax which is 18% and add to the total 

        // Accumulate the grand total
        grandTotal = grandTotal + total1;

        // Display the entered values for the current bill
        cout << "\n----------------------------------------------";
        cout << "\n| Item   | Name             | Quantity | Price  |";
        cout << "\n----------------------------------------------" << endl;

        for (int i = 0; i < numVariables; ++i) {
            cout << "| Item " << setw(1) << i + 1 << " | " << setw(16) << left << names[i] << " | " << setw(8) << left << quantities[i] << " | $" << setw(6) << fixed << setprecision(2) << prices[i] << "|" << endl;
            cout << "\n----------------------------------------------" << endl;
        }

        // Display the total for the current bill
        cout << "                        GST Tax: $" << setw(18) << fixed << setprecision(2) << GST << endl;
        cout << "                          Total: $" << setw(18) << fixed << setprecision(2) << total1 << endl;
        cout << endl;
        cout << endl;

    } while (true);

    cout << endl;
    cout << endl;

    // Display the grand total at the end
    cout << "----------------------- Total Sale Today: $" << setw(18) << fixed << grandTotal << " -----------------------" << endl;

}

void menu_system() {
    // Abdullah's logic code here
    string name[8] = {"beef biryani", "chicken biryani", "beef pulao", "chicken pulao", "chicken karahi", "chicken kebab", "roti(1 piece)", "mineral water"};
    int size1=8,size2=2;
    int price[size1][2] = {
        {300, 600},
        {250, 500},
        {300, 600},
        {250, 500},
        {400, 800},
        {350, 700},
        {15, 0},
        {60, 120}
    };
    cout << "\t\t\t Our current menu  :" << endl;
    cout << endl;
    cout << "items:\t\t \thalf\tfull" << endl;
    cout << endl;

    for (int r = 0; r < 8; r++) {
        cout << name[r] << "\t\t" << price[r][0] << "\t" << price[r][1] << endl;
    }

    cout << endl;
    cout << "Enter the thing you want : ";
    cout << endl;
    cout << "Press 1 to change the price of food items : "<<endl;
    cout << endl;
    cout << "Press 2 to add more food item : "<<endl;
    cout << endl;
    cout << "Press 3 to delete a food item : "<<endl;
    cout << endl;

    int s;
    cin >> s;
    cout << endl;

    switch (s) {
        case 1:
           { changep(name, price);
            break;}

        case 2:
            {add(name, price,size1);
            break;}

        case 3:
       { del( name,  price, size1);
       break;}
        default:
            break;
    }

   
}

void changep(string name[], int price[][2]) {
    while (true) {
        cout << "Enter the product to change the price (or 'exit' to exit): ";
        string n;
        cin.ignore();
        getline(cin,n);

        if (n == "exit") {
            break;
        }

        int index = -1;
        for (int i = 0; i < 8; i++) {
            if (n == name[i]) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            cout << "Enter new price for " << n << "\nhalf serving = ";
            cin >> price[index][0];
            cout << "full serving = ";
            cin >> price[index][1];
        } else {
            cout << "Product not found. Please enter a valid product name." << endl;
        }
    }

    cout << "\t\t\t Our updated menu  :" << endl;
    cout << endl;
    cout << "items:\t\t \thalf\tfull" << endl;
    cout << endl;

    for (int r = 0; r < 8; r++) {
        cout << name[r] << "\t\t" << price[r][0] << "\t" << price[r][1] << endl;
    }

    cout << endl;
    cout << "Enter the thing you want : ";
    cout << endl;
}



void add(string name[], int price[][2], int size1) {
    while (true) {
        cout << "Enter the name of the item you want to add to the menu or type 'exit': ";
        cin.ignore();
        getline(cin, name[size1]);
        cin.ignore();

        if (name[size1] == "exit") {
            break;
        }

        cout << "Enter the price of " << name[size1] << " for half serving: ";
        cin >> price[size1][0];

        cout << "Enter the price of " << name[size1] << " for full serving: ";
        cin >> price[size1][1];

        ++size1; // Increment the size of the menu
    }

    cout << "\t\t\t Our updated menu  :" << endl;
    cout << endl;
    cout << "items:\t\t \thalf\tfull" << endl;
    cout << endl;

    for (int r = 0; r < size1; r++) {
        cout << name[r] << "\t\t" << price[r][0] << "\t" << price[r][1] << endl;
    }
    cout << endl;
    cout << "Enter the thing you want : ";
    cout << endl;
}



void del(string name[], int price[][2], int size1)
{
    while (true) {
        --size1;
        string p;
        cout << "Enter the name of the item you want to delete from the menu(or type 'exit'): ";
        cin.ignore();
        getline(cin, p);
        if (p == "exit") {
            break;
        }

        cout << "\t\t\t Our updated menu  :" << endl;
        cout << endl;
        cout << "items:\t\t \thalf\tfull" << endl;
        cout << endl;

        for (int r = 0; r <= size1; r++) {
            if (name[r] == p) {
                continue;
            }

            cout << name[r] << "\t\t" << price[r][0] << "\t" << price[r][1] << endl;
        }
    }
}



void LMS_System() {
    // Saddiqui's logic code here
    interface();
}

void enter() {
    int a;
    cout << "How many students do you want to enter: ";
    cin >> a;
    if (total == 0) {
        total = total + a;
        for (int i = 0; i < a; i++) {
            cout << endl;
            cout << "Enter data of student " << i + 1 << endl;
            cout << "Enter Student's name: ";
            cin >> arr1[i];
            cout << "Enter Student ID: ";
            cin >> arr2[i];
            cout << "Enter Student's Department: ";
            cin >> arr3[i];
            cout << "Enter Student's Quiz marks: ";
            cin >> arr4[i];
            cout << "Enter Student's Assignment Marks: ";
            cin >> arr5[i];
            cout << "Enter Student's Mid-term marks: ";
            cin >> arr6[i];
            cout << "Enter Student's Final marks: ";
            cin >> arr7[i];
        }
    } else {
        for (int i = total; i < a; i++) {
            cout << endl;
            cout << "Enter data of student " << i + 1 << endl;
            cout << "Enter Student's name: ";
            cin >> arr1[i];
            cout << "Enter Student ID: ";
            cin >> arr2[i];
            cout << "Enter Student's Department: ";
            cin >> arr3[i];
            cout << "Enter Student's Quiz marks: ";
            cin >> arr4[i];
            cout << "Enter Student's Assignment Marks: ";
            cin >> arr5[i];
            cout << "Enter Student's Mid-term marks: ";
            cin >> arr6[i];
            cout << "Enter Student's Final marks: ";
            cin >> arr7[i];
        }
    }
}

void show() {
    for (int i = 0; i < total; i++) {
        cout << "Data Of Student " << i + 1 << endl << endl;
        cout << "Student's Name: " << arr1[i] << endl;
        cout << "Student's ID: " << arr2[i] << endl;
        cout << "Student's Department: " << arr3[i] << endl;
        cout << "Student's Quiz Marks: " << arr4[i] << endl;
        cout << "Student's Assignment Marks: " << arr5[i] << endl;
        cout << "Student's Mid-term Marks: " << arr5[i] << endl;
        cout << "Student's Final-term Marks: " << arr6[i] << endl;
    }
}

void search() {
    string b;
    cout << "Enter Student's ID: ";
    cin >> b;
    for (int i = 0; i < total; i++) {
        if (b == arr2[i]) {
            cout << "Student's Name: " << arr1[i] << endl;
            cout << "Student's ID: " << arr2[i] << endl;
            cout << "Student's Department: " << arr3[i] << endl;
            cout << "Student's Quiz Marks: " << arr4[i] << endl;
            cout << "Student's Assignment Marks: " << arr5[i] << endl;
            cout << "Student's Mid-term Marks: " << arr5[i] << endl;
            cout << "Student's Final-term Marks: " << arr6[i] << endl;
        } else {
            cout << "Student Does not exist!\n";
        }
    }
}

void update() {
    string b;
    cout << "Enter Student's ID: ";
    cin >> b;
    for (int i = 0; i < total; i++) {
        if (b == arr2[i]) {
            cout << "Previous Data: " << endl << endl;
            cout << "Student's Name: " << arr1[i] << endl;
            cout << "Student's ID: " << arr2[i] << endl;
            cout << "Student's Department: " << arr3[i] << endl;
            cout << "Student's Quiz Marks: " << arr4[i] << endl;
            cout << "Student's Assignment Marks: " << arr5[i] << endl;
            cout << "Student's Mid-term Marks: " << arr5[i] << endl;
            cout << "Student's Final-term Marks: " << arr6[i] << endl;
            cout << endl;
            cout << "Enter New Data: " << endl;
            cout << "Enter Student's name: ";
            cin >> arr1[i];
            cout << "Enter Student ID: ";
            cin >> arr2[i];
            cout << "Enter Student's Department: ";
            cin >> arr3[i];
            cout << "Enter Student's Quiz marks: ";
            cin >> arr4[i];
            cout << "Enter Student's Assignment Marks: ";
            cin >> arr5[i];
            cout << "Enter Student's Mid-term marks: ";
            cin >> arr6[i];
            cout << "Enter Student's Final marks: ";
            cin >> arr7[i];
        } else {
            cout << "Student Does not exist!\n";
        }
    }
}

void deleted() {
    cout << "Press 1 to Delete Complete Data\n";
    cout << "Press 2 to Delete Specific Data\n";
    int c;
    cin >> c;
    if (c == 1) {
        total = 0;
        cout << "All data is deleted successfully!!\n";
    } else {
        string id;
        cout << "Enter Student ID:\n";
        cin >> id;
        for (int i = 0; i < total; i++) {
            if (id == arr2[i]) {
                for (int j = i; j < total; j++) {
                    arr1[j] = arr1[j + 1];
                    arr2[j] = arr2[j + 1];
                    arr3[j] = arr3[j + 1];
                    arr4[j] = arr3[j + 1];
                    arr5[j] = arr4[j + 1];
                    arr6[j] = arr6[j + 1];
                    arr7[j] = arr7[j + 1];
                }
                total--;
                cout << "Your required record is deleted!!\n";
            }
        }
    }
}

void interface() {
    int num;
    while (true) {
        cout << " __________________________ " << endl;
        cout << "| Press 1 to 'Enter data'  |" << endl;
        cout << "| press 2 to 'Show Data'   |" << endl;
        cout << "| Press 3 to 'Search data' |" << endl;
        cout << "| Press 4 to 'Update data' |" << endl;
        cout << "| Press 5 to 'Delete data' |" << endl;
        cout << "| Press 6 to 'Exit Portal' |" << endl;
        cout << " __________________________  " << endl;
        cin >> num;
        switch (num) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleted();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Invalid Input\n";
                break;
        }
    }
}


int main (){
    int a,b,c;
    cout << endl;
    cout << endl;
    cout << " WELCOME TO CROSS PLATFORM MANAGEMAENT SYSTEM !!!! ";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "============   =========   ==========   ||       ||        || \\      ||   ==========   \\      //  ||        ||  =========\n";
    cout << "     ||        ||          ||           ||       ||        ||  \\     ||   ||            \\    //   ||        ||  ||\n";
    cout << "     ||        ||          ||           ||       ||        ||   \\    ||   ||             \\  //    ||        ||  ||\n";
    cout << "     ||        ||======    ||           ||=======||  ====  ||    \\   ||   ||========      \\//     ||        ||  =========\n";
    cout << "     ||        ||          ||           ||       ||        ||     \\  ||   ||             // \\     ||        ||          ||\n";
    cout << "     ||        ||          ||           ||       ||        ||      \\ ||   ||            //   \\    ||        ||          ||\n";
    cout << "     ||        =========   ==========   ||       ||        ||       \\||   ==========   //     \\     ========    ==========\n";
    cout << endl;
    cout << endl;
    cout << endl;

    int choice;
    cout << "Enter which system you want to access:" << endl;
    cout << "1. Billing System" << endl;
    cout << "2. Abdullah's Logic" << endl;
    cout << "3. LMS System" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            billingSystem();
            break;
        case 2:
            menu_system();
            break;
        case 3:
            LMS_System();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}



