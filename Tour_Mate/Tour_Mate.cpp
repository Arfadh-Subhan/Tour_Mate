#include <iostream>
#include <string>
#include <iomanip> // for setw()
using namespace std;

// vehicle struct
struct Vehicle {
    string vehicle;
    int seats;
    string rateperkm;
    int rate; // integer rate for calculation
};

// sales struct
struct Sales {
    string vehicle;
    string customer;
    int distance;
    float amount;
};

int main() {
    Vehicle vehicles[10];   // can store up to 10 vehicles
    int vehicleCount = 5;   // currently 5 default vehicles
    Sales sales[50];        // can store up to 50 sales records
    int salesCount = 0;     // currently no sales

    // initialize default vehicles with integer rates
    vehicles[0] = { "Car", 2, "Rs. 300/-", 300 };
    vehicles[1] = { "Buddy van", 6, "Rs. 500/-", 500 };
    vehicles[2] = { "Family van", 12, "Rs. 600/-", 600 };
    vehicles[3] = { "Small AC bus", 25, "Rs. 700/-", 700 };
    vehicles[4] = { "Bus", 45, "Rs. 800/-", 800 };

    string username, userpassword;
    int menunumber, back, tryagain;

    bool exitProgram = false;

    do { // login loop
        //Username : user1
        //Password : 1234

        bool loggedIn = false;
        do {
            cout << "_______________________________________" << endl;
            cout << "       Welcome To Tour Mate!" << endl;
            cout << " " << endl;
            cout << "  Tour mate is a famous CAB service, " << endl;
            cout << "   taking you all over the island!" << endl;
            cout << "           Ready to ride?" << endl;
            cout << "      Login and Book your Ride!" << endl;
            cout << "_______________________________________" << endl;
            cout << " " << endl;
            cout << "======Please Enter Login Details=======" << endl;
            cout << "Enter User name         : ";
            cin >> username;
            cout << "Enter password          : ";
            cin >> userpassword;
            cout << " " << endl;

            if (username == "user1" && userpassword == "1234") {
                loggedIn = true;
                cout << "Logging in..." << endl;
                cout << "_______________________________________" << endl;
                cout << " " << endl;
                cout << "        Welcome " << username << "!" << endl;
                cout << " " << endl;
            }
            else {
                cout << "Username or Password is incorrect." << endl;
                cout << "Enter any number to Try again." << endl;
                cin >> tryagain;
                cout << " " << endl;
            }
        } while (!loggedIn);

        // main menu loop
        do {
            cout << "   Choose a menu to proceed" << endl;
            cout << "_______________________________" << endl;
            cout << "[  1. Vehicle Management      ]" << endl;
            cout << "[  2. View Vehicles           ]" << endl;
            cout << "[  3. Sales Management        ]" << endl;
            cout << "[  4. Company Details         ]" << endl;
            cout << "[  5. User Details            ]" << endl;
            cout << "[  6. Logout                  ]" << endl;
            cout << "[  7. Exit                    ]" << endl;
            cout << "[_____________________________]" << endl;
            cout << "Enter valid number (1 - 7): ";
            cin >> menunumber;
            cout << " " << endl;

            switch (menunumber) {
            case 1: {
                int vehicledetailsmenunumber;
                do {
                    cout << "===== Vehicle Details =====" << endl;
                    cout << "[1. View Vehicles         ]" << endl;
                    cout << "[2. Add Vehicle           ]" << endl;
                    cout << "[3. Edit Vehicle          ]" << endl;
                    cout << "[4. Delete Vehicle        ]" << endl;
                    cout << "[5. Back to Main Menu     ]" << endl;
                    cout << "===========================" << endl;
                    cout << "Enter valid number (1 - 5): ";
                    cin >> vehicledetailsmenunumber;
                    cout << " " << endl;

                    switch (vehicledetailsmenunumber) {
                    case 1: {
                        cout << left << setw(20) << "Vehicle"
                            << setw(10) << "Seats"
                            << setw(15) << "Rate per KM" << endl;
                        cout << "--------------------------------------------" << endl;
                        for (int i = 0; i < vehicleCount; i++) {
                            cout << setw(2) << i + 1 << ". "
                                << left << setw(18) << vehicles[i].vehicle
                                << setw(10) << vehicles[i].seats
                                << setw(15) << vehicles[i].rateperkm << endl;
                            cout << " " << endl;
                        }
                        cout << "Press any number to go back: ";
                        cin >> back;
                        cout << " " << endl;
                        break;
                    }
                    case 2: {
                        if (vehicleCount < 10) {
                            cin.ignore();
                            cout << "Enter vehicle name : ";
                            getline(cin, vehicles[vehicleCount].vehicle);
                            cout << "Enter seats: ";
                            cin >> vehicles[vehicleCount].seats;
                            cout << "Enter rate per KM (number only, e.g., 1000): ";
                            cin >> vehicles[vehicleCount].rate;
                            vehicles[vehicleCount].rateperkm = "Rs. " + to_string(vehicles[vehicleCount].rate) + "/-";
                            vehicleCount++;
                            cout << " " << endl;
                            cout << "Vehicle added successfully!" << endl;
                            cout << " " << endl;
                        }
                        else {
                            cout << "Vehicle list is full (max 10)!" << endl;
                            cout << " " << endl;
                        }
                        break;
                    }
                    case 3: {
                        int editvehicle;
                        cout << "Enter vehicle number to edit (1-" << vehicleCount << "): ";
                        cin >> editvehicle;
                        cin.ignore();
                        cout << " " << endl;
                        if (editvehicle >= 1 && editvehicle <= vehicleCount) {
                            cout << "Enter new vehicle name : ";
                            getline(cin, vehicles[editvehicle - 1].vehicle);
                            cout << "Enter seats: ";
                            cin >> vehicles[editvehicle - 1].seats;
                            cout << "Enter rate per KM (number only, e.g., 1000): ";
                            cin >> vehicles[editvehicle - 1].rate;
                            vehicles[editvehicle - 1].rateperkm = "Rs. " + to_string(vehicles[editvehicle - 1].rate) + "/-";
                            cout << " " << endl;
                            cout << "Vehicle updated successfully!" << endl;
                            cout << " " << endl;
                        }
                        else {
                            cout << "Invalid vehicle number." << endl;
                            cout << " " << endl;
                        }
                        break;
                    }
                    case 4: {
                        int deletevehicle;
                        cout << "Enter vehicle number to delete (1-" << vehicleCount << "): ";
                        cin >> deletevehicle;
                        cout << " " << endl;
                        if (deletevehicle >= 1 && deletevehicle <= vehicleCount) {
                            for (int i = deletevehicle - 1; i < vehicleCount - 1; i++) {
                                vehicles[i] = vehicles[i + 1];
                            }
                            vehicleCount--;
                            cout << "Vehicle deleted successfully!" << endl;
                            cout << " " << endl;
                        }
                        else {
                            cout << "Invalid vehicle number." << endl;
                            cout << " " << endl;
                        }
                        break;
                    }
                    case 5:
                        cout << "Returning to Main Menu..." << endl;
                        cout << " " << endl;
                        break;
                    default:
                        cout << "Invalid option. Try again." << endl;
                        cout << " " << endl;
                        break;
                    }

                } while (vehicledetailsmenunumber != 5);
                break;
            }

            case 2: {
                cout << left << setw(20) << "Vehicle"
                    << setw(10) << "Seats"
                    << setw(15) << "Rate per KM" << endl;
                cout << "--------------------------------------------" << endl;
                for (int i = 0; i < vehicleCount; i++) {
                    cout << setw(2) << i + 1 << ". "
                        << left << setw(18) << vehicles[i].vehicle
                        << setw(10) << vehicles[i].seats
                        << setw(15) << vehicles[i].rateperkm << endl;
                    cout << " " << endl;
                }
                cout << "Press any number to go back: ";
                cin >> back;
                cout << " " << endl;
                break;
            }

            case 3: { // Sales management remains the same (can adjust spacing similarly)
                int salesmenu;
                do {
                    cout << "===== Sales Management =====" << endl;
                    cout << "1. View All Sales" << endl;
                    cout << "2. Add Sales Record" << endl;
                    cout << "3. Back to Main Menu" << endl;
                    cout << "Enter valid number (1 - 3): ";
                    cin >> salesmenu;
                    cout << " " << endl;

                    switch (salesmenu) {
                    case 1: {
                        if (salesCount == 0) {
                            cout << "No sales records found!" << endl;
                            cout << " " << endl;
                        }
                        else {
                            cout << left << setw(15) << "Vehicle"
                                << setw(15) << "Customer"
                                << setw(15) << "Distance"
                                << setw(15) << "Amount" << endl;
                            cout << "---------------------------------------------------" << endl;
                            for (int i = 0; i < salesCount; i++) {
                                cout << setw(15) << sales[i].vehicle
                                    << setw(15) << sales[i].customer
                                    << setw(15) << to_string(sales[i].distance) + " km"
                                    << "Rs. " << sales[i].amount << "/-" << endl;
                                cout << " " << endl;
                            }
                        }
                        cout << "Press any number to go back: ";
                        cin >> back;
                        cout << " " << endl;
                        break;
                    }
                    case 2: {
                        if (vehicleCount == 0) {
                            cout << "No sale data found!" << endl;
                            cout << " " << endl;
                        }
                        else if (salesCount < 50) {
                            int vehicleChoice;
                            cin.ignore();
                            cout << "Enter customer name: ";
                            getline(cin, sales[salesCount].customer);
                            cout << " " << endl;
                            cout << "Available Vehicles:" << endl;
                            for (int i = 0; i < vehicleCount; i++) {
                                cout << i + 1 << ". " << vehicles[i].vehicle
                                    << " (" << vehicles[i].seats << " seats, "
                                    << vehicles[i].rateperkm << ")" << endl;
                            }
                            cout << " " << endl;
                            cout << "Select vehicle number (1-" << vehicleCount << "): ";
                            cin >> vehicleChoice;
                            cout << " " << endl;
                            if (vehicleChoice >= 1 && vehicleChoice <= vehicleCount) {
                                cout << "Enter distance (km): ";
                                cin >> sales[salesCount].distance;
                                cout << " " << endl;
                                sales[salesCount].vehicle = vehicles[vehicleChoice - 1].vehicle;
                                sales[salesCount].amount = vehicles[vehicleChoice - 1].rate * sales[salesCount].distance;
                                cout << "Sales record added successfully!" << endl;
                                cout << "Total amount: Rs. " << sales[salesCount].amount << "/-" << endl;
                                cout << " " << endl;
                                salesCount++;
                            }
                            else {
                                cout << "Invalid vehicle number!" << endl;
                                cout << " " << endl;
                            }
                        }
                        else {
                            cout << "Sales records full (max 50)!" << endl;
                            cout << " " << endl;
                        }
                        break;
                    }
                    case 3:
                        cout << "Returning to Main Menu..." << endl;
                        cout << " " << endl;
                        break;
                    default:
                        cout << "Invalid option. Try again." << endl;
                        cout << " " << endl;
                        break;
                    }

                } while (salesmenu != 3);
                break;
            }

            case 4: {
                cout << "============== Company Details =============" << endl;
                cout << "Tour Mate is a Famous CAB service in the city." << endl;
                cout << "It provides 24 hours service all island wide." << endl;
                cout << "Our drivers are highly talented and your" << endl;
                cout << "safety is highly valued!" << endl;
                cout << "===========================================" << endl;
                cout << "[Company Name         : Tour Mate Pvt Ltd ]" << endl;
                cout << "[Service Type         : City CAB service  ]" << endl;
                cout << "[Hotline              : +94 11 234 5678   ]" << endl;
                cout << "[Info                 : www.tourmate.lk   ]" << endl;
                cout << "[Working Hours        : 24 Hours service  ]" << endl;
                cout << "[Provide Feedback Mail: cabs.tourmate.lk  ]" << endl;
                cout << "===========================================" << endl;
                cout << "Press any number to go back: ";
                cin >> back;
                cout << " " << endl;
                break;
            }

            case 5: {
                int userdetails;
                do {
                    cout << "===== User Details =====" << endl;
                    cout << "User Name     : " << username << endl;
                    cout << "User Password : " << userpassword << endl;
                    cout << "[1. Edit Username       ]" << endl;
                    cout << "[2. Edit Password       ]" << endl;
                    cout << "[3. Back to Main Menu   ]" << endl;
                    cout << "Enter valid number (1 - 3): ";
                    cin >> userdetails;
                    cout << " " << endl;
                    switch (userdetails) {
                    case 1:
                        cout << "===== Do Not Use Space in Between =====" << endl;
                        cout << "====== Two Names, Use underscope ======" << endl;
                        cout << "============== Instead ================" << endl;
                        cout << " " << endl;
                        cout << "Enter new User Name : ";
                        cin >> username;
                        cout << "User Name changed successfully!" << endl;
                        cout << " " << endl;
                        break;
                    case 2:
                        cout << "===== Do Not Use Space in Between =====" << endl;
                        cout << " " << endl;
                        cout << "Enter new Password: ";
                        cin >> userpassword;
                        cout << "Password changed successfully!" << endl;
                        cout << " " << endl;
                        break;
                    case 3:
                        cout << "Returning to Main Menu..." << endl;
                        cout << " " << endl;
                        break;
                    default:
                        cout << "Invalid option. Try again." << endl;
                        cout << " " << endl;
                        break;
                    }
                } while (userdetails != 3);
                break;
            }

            case 6:
                cout << "Logging out..." << endl;
                cout << " " << endl;
                break; // this breaks main menu and goes back to login

            case 7:
                cout << "Thank you for visiting Tour Mate!" << endl;
                cout << "Have a Great Day!" << endl;
                cout << "Exiting program..." << endl;
                cout << " " << endl;
                exitProgram = true;
                break;

            default:
                cout << "Invalid option. Try again." << endl;
                cout << " " << endl;
                break;
            }

        } while (menunumber != 6 && !exitProgram);

    } while (!exitProgram); // end of login loop

    return 0;
}
