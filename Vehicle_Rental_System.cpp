#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <limits>
#include <cstdlib>
using namespace std;

// Global variables and functions
int sys_budget = 0;
int selectedCarIndex;
int cntn_with_forget = 0;
void customerLogin();
void adminLogin();
void Func_registration();
void forget_pswd();
void UsersList();
void Car_Data();
void Motorcycle_Data();
int main();
void choices_Admin();

// Functions used for formatting the output screen
void htab(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t");
    }
}

void vspace(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n");
    }
}

// Function return the system budget after a transaction is successfully completed
float BudgetSystem_updation(float charge)
{
    sys_budget = sys_budget + charge;
    return sys_budget;
}

struct car
{
    char car_id[10];
    char car_name[50];
    char car_model[20];
    char car_paint[20];
    int car_yearadded;
    float car_speed;
    float car_charge;
};

struct motorcycle
{
    char motorcycle_id[10];
    char motorcycle_name[50];
    float engine_capacity;
    float engine_strength;
    float motorcycle_speed;
    float motorcycle_weightkg;
    float motorcycle_fuelcapacity;
    float motorcycle_charge;
};

struct car car[1000];
motorcycle mc[1000];

// Accessing cars.txt text file for reading file informations
void carsList()
{
    ifstream ifs;
    ifs.open("cars.txt");
    int carNum = 0;

    while (!ifs.eof())
    {
        ifs.getline(car[carNum].car_id, 10, ' ');
        ifs.getline(car[carNum].car_name, 30, ' ');
        ifs.getline(car[carNum].car_model, 25, ' ');
        ifs.getline(car[carNum].car_paint, 20, ' ');
        ifs >> car[carNum].car_yearadded;
        ifs.ignore();
        ifs >> car[carNum].car_speed;
        ifs.ignore();
        ifs >> car[carNum].car_charge;
        ifs.ignore();
        carNum++;
        ifs >> ws;
    }
    ifs.close();
}

// Accessing the motorcycles.txt text file for reading the written informations
void motorcycles()
{
    ifstream ifs;
    ifs.open("motorcycles.txt");
    int mcNum = 0;
    while (!ifs.eof())
    {
        ifs.getline(mc[mcNum].motorcycle_id, 10, ' ');
        ifs.getline(mc[mcNum].motorcycle_name, 30, ' ');
        ifs >> mc[mcNum].engine_capacity;
        /* used to input both integral value and string, otherwise when we
        enter space after enering the intergral value the null character get
        saved as the string and the actual string does not get saved that's why
        we used the ignore() function which helps in inputting the string as well
        after we input the intergral value */
        ifs.ignore();
        ifs >> mc[mcNum].engine_strength;
        ifs.ignore();
        ifs >> mc[mcNum].motorcycle_speed;
        ifs.ignore();
        ifs >> mc[mcNum].motorcycle_weightkg;
        ifs.ignore();
        ifs >> mc[mcNum].motorcycle_fuelcapacity;
        ifs.ignore();
        ifs >> mc[mcNum].motorcycle_charge;
        ifs.ignore();
        mcNum++;
        ifs >> ws;
    }
    ifs.close();
}

// Function is used for retrurning the bumber of car with the help of car.txt text file
int flagCar()
{
    int noOfCar = 0;
    ifstream ifs("cars.txt");

    string word;
    while (getline(ifs, word))
    {
        if (!word.empty())
            noOfCar++;
    }
    ifs.close();
    return noOfCar;
}

// Giving information about the number of motorcycles present in the text file "motorcycles.txt"
int flagMotorbikes()
{
    int noOfMotorbikes = 0;
    ifstream ifs("motorcycles.txt");
    string word;
    while (getline(ifs, word))
    {
        if (!word.empty())
            noOfMotorbikes++;
    }
    ifs.close();
    return noOfMotorbikes;
}

// Function used for checking the disflag present on the selected item
float checkDisflag(float oriprice)
{
    int disflag = rand() % 10;
    int ranNum = rand() % 200;
    int lastPrice;

    if (ranNum >= 100)
    {
        vspace(1);
        htab(8);
        cout << "H U R R A Y  !!!  Y O U   G O T   D I S C O U N T  ! " << endl;
        lastPrice = oriprice - (oriprice * float(float(disflag) / 100));
        // cout<<lastPrice<<endl;
        return lastPrice;
    }
    else
    {
        vspace(1);
        htab(5);
        cout << "O O P S !!!   D I D N ' T   G E T   D I S C O U N T !!!  B E T T E R   L U C K   N E X T   T I M E !!!" << endl;
        return oriprice;
    }
}

// Function coded for making direct paymants
void directPay(string customerName, float carPrice, float budget2)
{
    int index = 0;
    int okay;
    float updBalnc;
    carPrice = checkDisflag(carPrice);
    vspace(1);
    htab(9);
    cout << " N E W   P R I C E : " << carPrice << endl;
    vspace(1);
    htab(8);
    cout << " ----------------------------------" << endl;
    vspace(3);
    htab(7);
    cout << "1. Complete Your Payment " << endl;
    vspace(1);
    htab(7);
    cout << "2. Return To The Main Menu" << endl;
    vspace(2);
    htab(9);
    cout << " Enter Your Choice: ";
    cin >> okay;
    system("cls");
    if (okay == 1)
    {
        updBalnc = budget2 - carPrice;
        if (updBalnc >= 0)
        {
            vspace(1);
            htab(6);
            cout << "-------------------------------------------------------------------" << endl;
            vspace(1);
            htab(8);
            cout << "=> Total System Balance  : " << "Rs. " << BudgetSystem_updation(carPrice) << endl;
            vspace(1);
            htab(8);
            cout << "=> Current Balance Left  : " << "Rs. " << updBalnc << endl;
            vspace(1);
            htab(8);
            cout << "   Thank you for shooping with us! " << endl;
            vspace(1);
            htab(6);
            cout << "--------------------------------------------------------------------" << endl;
            int option;
            vspace(3);
            htab(5);
            cout << " 1. Return to the Main menu ";
            vspace(2);
            htab(5);
            cout << " 2. Exit the Program ";
            vspace(3);
            htab(6);
            cout << " Enter Your Choice : ";
            cin >> option;
            if (option == 1)
            {
                main();
            }
            else
            {
                vspace(1);
                htab(6);
                cout << " Thank You For Shooping With Us !!! I Hope You'll Visit Us Again !!! " << endl;
                exit(0);
            }
        }
        else
        {
            vspace(3);
            htab(6);
            cout << "----------------------------------------------------------------------" << endl;
            vspace(1);
            htab(8);
            cout << "=> Process Didn't Get Completed " << endl;
            vspace(1);
            htab(6);
            cout << "-----------------------------------------------------------------------" << endl;
            int option;
            vspace(3);
            htab(5);
            cout << " 1. Return to the Main menu ";
            vspace(2);
            htab(5);
            cout << " 2. Exit the Program ";
            vspace(3);
            htab(6);
            cout << " Enter Your Choice : ";
            cin >> option;
            if (option == 1)
            {
                main();
            }
            else
            {
                vspace(1);
                htab(6);
                cout << " Thank You For Shooping With Us !!! I Hope You'll Visit Us Again !!! " << endl;
                exit(0);
            }
        }
    }
    else if (okay == 2)
    {
        main();
        return;
    }
}

// Below Defined Function is coded for taking payment on monthly basis, and some tax also get included every month, i.e Rs. 200
void montlyPay(float charge, float budget2)
{
    int monthNo;
    int okay;
    htab(5);
    cout << "Enter the appropriate month (Montly charge will be calculated accn to the month): ";
    cin >> monthNo;

    float montlyPay = (float(charge) / float(monthNo)) + 200;
    float total = (float(montlyPay) * float(monthNo));

    for (int i = 0; i < monthNo; i++)
    {
        vspace(1);
        htab(7);
        cout << i + 1 << ". Month = " << "Rs. " << montlyPay << endl;
    }
    vspace(2);
    htab(4);
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    vspace(3);
    htab(8);
    cout << " Total Amount to be paid monthly = " << "Rs. " << total << endl;
    total = checkDisflag(total);
    vspace(3);
    htab(4);
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    vspace(3);
    htab(7);
    cout << "1. Complete Your Payment " << endl;
    vspace(1);
    htab(7);
    cout << "2. Return To The Main Menu" << endl;
    vspace(2);
    htab(9);
    cout << " Enter Your Choice: ";
    cin >> okay;
    system("cls");

    if (okay == 1)
    {
        if (budget2 >= total)
        {
            budget2 = budget2 - float(total);
            vspace(3);
            htab(6);
            cout << "---------------------------------------------------------------------------------------" << endl;
            vspace(1);
            htab(8);
            cout << "=> Current Acflag Balance = " << "Rs. " << budget2 << endl;
            vspace(1);
            htab(7);
            cout << " Transaction Completed! Thanks A Lot For Being Our Valued Customer!!! " << endl;
            vspace(1);
            htab(6);
            cout << "----------------------------------------------------------------------------------------" << endl;
            int option;
            vspace(3);
            htab(5);
            cout << " 1. Return to the Main menu ";
            vspace(2);
            htab(5);
            cout << " 2. Exit the Program ";
            vspace(3);
            htab(6);
            cout << " Enter Your Choice : ";
            cin >> option;
            if (option == 1)
            {
                main();
            }
            else
            {
                vspace(1);
                htab(5);
                cout << " Thank You For Shooping With Us !!! I Hope You'll Visit Us Again !!! \n" << endl;
                exit(0);
            }
        }
        else
        {
            vspace(3);
            htab(7);
            cout << "------------------------------------------------------------------------------" << endl;
            vspace(1);
            htab(8);
            cout << " Process Didn't Get Completed (Shortage Of Money). Thank You For Visiting! " << endl;
            vspace(1);
            htab(7);
            cout << "------------------------------------------------------------------------------" << endl;
            int option;
            vspace(3);
            htab(5);
            cout << " 1. Return to the Main menu ";
            vspace(2);
            htab(5);
            cout << " 2. Exit the Program ";
            vspace(3);
            htab(6);
            cout << " Enter Your Choice : ";
            cin >> option;
            if (option == 1)
            {
                main();
            }
            else
            {
                vspace(1);
                htab(6);
                cout << " Thank You For Shooping With Us !!! I Hope You'll Visit Us Again !!! " << endl;
                exit(0);
            }
        }
    }
    else if (okay == 2)
    {
        main();
    }
}

// Diplay the list of available cars
void displayCar()
{
    carsList();
    for (int i = 0; i < flagCar(); i++)
    {
        vspace(2);
        htab(8);
        cout << " Car Identification Document(ID) : " << car[i].car_id;
        vspace(2);
        htab(8);
        cout << " Car Name : " << car[i].car_name;
        vspace(2);
        htab(8);
        cout << " Car Model : " << car[i].car_model;
        vspace(2);
        htab(8);
        cout << " Car Colour : " << car[i].car_paint;
        vspace(2);
        htab(8);
        cout << " Year of Manufacturing(of car) : " << car[i].car_yearadded;
        vspace(2);
        htab(8);
        cout << " Car Average Speed : " << car[i].car_speed;
        vspace(2);
        htab(8);
        cout << " Rental Price of the Car : " << car[i].car_charge;
        if (i != flagCar() - 1)
        {
            vspace(3);
        }
        else
        {
            vspace(2);
        }
    }
}

// Display the list of Motorbikes available
void displayMotorcycle()
{
    motorcycles();
    for (int i = 0; i < flagMotorbikes(); i++)
    {
        vspace(2);
        htab(8);
        cout << " Motorcycle Identification Document(ID) : " << mc[i].motorcycle_id;
        vspace(2);
        htab(8);
        cout << " Name of the Motorcycle : " << mc[i].motorcycle_name;
        vspace(2);
        htab(8);
        cout << " Engine Capacity : " << mc[i].engine_capacity;
        vspace(2);
        htab(8);
        cout << " Engine Power : " << mc[i].engine_strength;
        vspace(2);
        htab(8);
        cout << " Motorcycle's Speed :  " << mc[i].motorcycle_speed;
        vspace(2);
        htab(8);
        cout << " Weight :  " << mc[i].motorcycle_weightkg;
        vspace(2);
        htab(8);
        cout << " Fuel Capacity :  " << mc[i].motorcycle_fuelcapacity;
        vspace(2);
        htab(8);
        cout << " Rental Price of Motorcycle :  " << mc[i].motorcycle_charge;
        if (i != flagMotorbikes() - 1)
        {
            vspace(3);
        }
        else
        {
            vspace(2);
        }
    }
}

// Adding car to the text file with the help of admin panel
void addCar()
{
    ofstream ofs;
    ofs.open("cars.txt", fstream::app);
    ofs << endl;

    int newCar = flagCar() + 1;
    vspace(3);
    htab(7);
    cout << " Enter Information of the Newly Added Car : " << endl;
    vspace(2);

    htab(5);
    cout << " Enter Car ID : ";
    cin >> ws;
    cin.getline(car[newCar].car_id, 10);
    ofs << car[newCar].car_id;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Enter Car Name : ";
    cin.getline(car[newCar].car_name, 30);
    ofs << car[newCar].car_name;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Enter Car Model : ";
    cin.getline(car[newCar].car_model, 25);
    ofs << car[newCar].car_model;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Colour of the new Car: ";
    cin.getline(car[newCar].car_paint, 25);
    ofs << car[newCar].car_paint;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Year of Manufacturing : ";
    cin >> car[newCar].car_yearadded;
    ofs << car[newCar].car_yearadded;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Average Speed of the Car : ";
    cin >> car[newCar].car_speed;
    ofs << car[newCar].car_speed;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Rental Price : ";
    cin >> car[newCar].car_charge;
    ofs << car[newCar].car_charge;
    ofs << " ";
    vspace(1);

    ofs.close();
    system("cls");
    Car_Data();
    choices_Admin();
}

// Function for deleting the information regarding any specific car from the car.txt text file
void deleteCar()
{
    char id[10];

    ofstream ofs;
    ofs.open("temp.txt");

    displayCar();

    cout << " " << endl;
    vspace(2);
    htab(6);
    cout << "Enter the ID of the car whose data is to be removed : ";
    cout << " ";
    cin >> ws;
    vspace(1);
    cin.getline(id, 10);
    int x = flagCar();
    for (int i = 0; i < flagCar(); i++)
    {
        if (strcmp(id, car[i].car_id) != 0)
        {
            ofs << car[i].car_id;
            ofs << " ";
            ofs << car[i].car_name;
            ofs << " ";
            ofs << car[i].car_model;
            ofs << " ";
            ofs << car[i].car_paint;
            ofs << " ";
            ofs << car[i].car_yearadded;
            ofs << " ";
            ofs << car[i].car_speed;
            ofs << " ";
            ofs << car[i].car_charge;
            ofs << " ";
            if (i != flagCar())
            {
                ofs << endl;
            }
        }
    }

    ofs.close();

    remove("cars.txt");
    rename("temp.txt", "cars.txt");
    system("cls");
    Car_Data();
    choices_Admin();
}

// Function created for adding Motorbikes
void addMotorcycle()
{
    ofstream ofs;
    ofs.open("motorcycles.txt", fstream::app);
    ofs << endl;

    int newMotorcycle = flagMotorbikes() + 1;
    vspace(2);
    htab(7);
    cout << " Enter the new motorcycle information : ";
    vspace(3);

    htab(5);
    cout << " Enter Motorcycle Identification Document(ID) : ";
    cin >> ws;
    cin.getline(mc[newMotorcycle].motorcycle_id, 10);
    ofs << mc[newMotorcycle].motorcycle_id;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Enter Name of Motorcycle : ";
    cin.getline(mc[newMotorcycle].motorcycle_name, 20);
    ofs << mc[newMotorcycle].motorcycle_name;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Enter it's Engine Capacity : " ;
    cin >> mc[newMotorcycle].engine_capacity;
    ofs << mc[newMotorcycle].engine_capacity;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Enter it's Engine Power : ";
    cin >> mc[newMotorcycle].engine_strength;
    ofs << mc[newMotorcycle].engine_strength;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Enter it's Average Speed : ";
    cin >> mc[newMotorcycle].motorcycle_speed;
    ofs << mc[newMotorcycle].motorcycle_speed;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Enter it's Weight : ";
    cin >> mc[newMotorcycle].motorcycle_weightkg;
    ofs << mc[newMotorcycle].motorcycle_weightkg;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Fuel Capacity : " ;
    cin >> mc[newMotorcycle].motorcycle_fuelcapacity;
    ofs << mc[newMotorcycle].motorcycle_fuelcapacity;
    ofs << " ";
    vspace(1);

    htab(5);
    cout << " Rental Price of the Motorbike: ";
    cin >> mc[newMotorcycle].motorcycle_charge;
    ofs << mc[newMotorcycle].motorcycle_charge;
    ofs << " ";
    vspace(1);

    ofs.close();
    system("cls");
    Motorcycle_Data();
    choices_Admin();
}

// Function created for deleting the data of any specific motorcycle
void deleteMotorcycle()
{
    char id[10];

    ofstream ofs;
    ofs.open("temp.txt");

    displayMotorcycle();

    cout << " " << endl;
    vspace(2);
    htab(6);
    cout << "Enter the motorcycle id whose data needs to get removed from the database : ";
    cout << " ";
    cin >> ws;
    vspace(1);
    cin.getline(id, 10);
    int x = flagMotorbikes();
    for (int i = 0; i < flagMotorbikes(); i++)
    {
        if (strcmp(id, mc[i].motorcycle_id) != 0)
        {
            ofs << mc[i].motorcycle_id;
            ofs << " ";
            ofs << mc[i].motorcycle_name;
            ofs << " ";
            ofs << mc[i].engine_capacity;
            ofs << " ";
            ofs << mc[i].engine_strength;
            ofs << " ";
            ofs << mc[i].motorcycle_speed;
            ofs << " ";
            ofs << mc[i].motorcycle_weightkg;
            ofs << " ";
            ofs << mc[i].motorcycle_fuelcapacity;
            ofs << " ";
            ofs << mc[i].motorcycle_charge;
            ofs << " ";
            if (i != flagCar())
            {
                ofs << endl;
            }
        }
    }
    ofs.close();
    remove("motorcycles.txt");
    rename("temp.txt", "motorcycles.txt");
    system("cls");
    Motorcycle_Data();
    choices_Admin();
}

// Function used for reading the data of Cars available
void Car_Data()
{
    ifstream ifs;
    ifs.open("cars.txt");
    int carNum = 0;

    while (!ifs.eof())
    {
        ifs.getline(car[carNum].car_id, 10, ' ');
        ifs.getline(car[carNum].car_name, 20, ' ');
        ifs.getline(car[carNum].car_model, 20, ' ');
        ifs.getline(car[carNum].car_paint, 20, ' ');
        ifs >> car[carNum].car_yearadded;
        ifs.ignore();
        ifs >> car[carNum].car_speed;
        ifs.ignore();
        ifs >> car[carNum].car_charge;
        ifs.ignore();
        carNum++;
        ifs >> ws;
    }
    ifs.close();
}

// Function created for reading the data of Motorcycles present in the database
void Motorcycle_Data()
{
    ifstream ifs;
    ifs.open("motorcycles.txt");
    int motorcycleNum = 0;

    while (!ifs.eof())
    {
        ifs.getline(mc[motorcycleNum].motorcycle_id, 10, ' ');
        ifs.getline(mc[motorcycleNum].motorcycle_name, 20, ' ');
        ifs >> mc[motorcycleNum].engine_capacity;
        ifs.ignore();
        ifs >> mc[motorcycleNum].engine_strength;
        ifs.ignore();
        ifs >> mc[motorcycleNum].motorcycle_speed;
        ifs.ignore();
        ifs >> mc[motorcycleNum].motorcycle_weightkg;
        ifs.ignore();
        ifs >> mc[motorcycleNum].motorcycle_fuelcapacity;
        ifs.ignore();
        ifs >> mc[motorcycleNum].motorcycle_charge;
        ifs.ignore();
        motorcycleNum++;
        ifs >> ws;
    }
    ifs.close();
}

// Function for handling the operatios of Admin Panel for adding / removing / showing data informations
void choices_Admin()
{
    system("CLS");
    int choice;
    vspace(2);
    htab(6);
    cout << "--------------------------------- A D M I N    P A N E L ---------------------------------" << endl;
    vspace(3);
    htab(10);
    cout << " TOTAL SYSTEM BALANCE = " << "Rs. " << sys_budget << endl;
    vspace(2);
    htab(7);
    cout << "1. ADDING / REMOVING ANY VEHICLE ";
    vspace(2);
    htab(7);
    cout << "2. VIEW THE DATA OF ALL THE VEHICLE ";
    vspace(2);
    htab(7);
    cout << "3. VIEW THE DATA OF ALL USERS ";
    vspace(2);
    htab(7);
    cout << "4. EXIT THE ADMIN BLOCK ";
    vspace(3);
    htab(10);
    cout << " Enter Your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        char c;
        system("CLS");
        vspace(3);
        htab(9);
        cout << "---A D M I N    P A N E L---";
        vspace(3);
        htab(8);
        cout << " 1. Add A New Car ";
        vspace(2);
        htab(8);
        cout << " 2. Add A New Motorcycle ";
        vspace(2);
        htab(8);
        cout << " 3. Remove A Car ";
        vspace(2);
        htab(8);
        cout << " 4. Remove A Motorcycle ";
        vspace(2);
        htab(8);
        cout << " 5. Return Back ";
        vspace(3);
        htab(9);
        cout << " Enter Your Choice : ";
        cin >> c;
        if (c == '1')
        {
            system("CLS");
            addCar();
        }
        else if (c == '2')
        {
            system("CLS");
            addMotorcycle();
        }
        else if (c == '3')
        {
            system("CLS");
            deleteCar();
        }
        else if (c == '4')
        {
            system("CLS");
            deleteMotorcycle();
        }
        else if (c == '5')
        {
            choices_Admin();
        }
        else
        {
            vspace(3);
            htab(6);
            cout << " OOPS ! WRONG CHOICE, ENTER YOUR CHOICE AGAIN ";
            system("pause");

            choices_Admin();
        }
        break;
    }
    case 2:
    {
        system("CLS");
        vspace(3);
        htab(7);
        cout << "-------------------- ALL CARS --------------------" << endl;
        displayCar();
        vspace(3);
        htab(7);
        cout << "-------------------- ALL MOTORCYCLES --------------------" << endl;
        displayMotorcycle();
        string decide;
        vspace(2);
        htab(8);
        cout << " Do you want to continue ??? ( yes / no ) : ";
        cin >> decide;
        if (decide == "yes")
        {
            choices_Admin();
        }
        else
        {
            main();
        }
        break;
    }
    case 3:
    {
        system("CLS");
        vspace(3);
        htab(6);
        cout << "----------------------- A L L   U S E R S -----------------------" << endl;
        cout << endl;
        UsersList();

        string decide;
        vspace(2);
        htab(6);
        cout << " Do you want to continue ??? ( yes / no ) : ";
        cin >> decide;
        if (decide == "yes")
        {
            choices_Admin();
        }
        else
        {
            main();
        }
    }

    break;
    case 4:
        vspace(3);
        htab(8);
        cout << " E X I T I N G ... " << endl;
        system("pause");
        system("CLS");
        main();

    default:
        vspace(3);
        htab(6);
        cout << " OOPS ! WRONG CHOICE, ENTER YOUR CHOICE AGAIN ";
        system("pause");
        choices_Admin();
    }
}

// Function for handling the operations of admin login
void adminLogin()
{
    system("CLS");
    int flag = 0;
    string adm_UserName = "admin";
    string adm_Password = "admin";
    string adm_username, adm_pswd;
    vspace(3);
    htab(6);
    cout << "------------------------------------------------------------------------------" << endl;
    vspace(1);
    htab(8);
    cout << " W E L C O M E    A D M I N    P A N E L ";
    vspace(2);
    htab(6);
    cout << "------------------------------------------------------------------------------" << endl;
    vspace(3);
    htab(8);
    cout << " U S E R N A M E : ";
    cin >> adm_username;
    vspace(2);
    htab(8);
    cout << " P A S S W O R D : ";
    char ch;
    ch = _getch();
    while (ch != 13)
    {
        adm_pswd.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (adm_username == adm_UserName && adm_pswd == adm_Password)
    {

        flag = 1;
    }
    if (flag == 1)
    {
        choices_Admin();
    }
    else
    {
        vspace(3);
        htab(7);
        cout << " Wrong username or password ! Please, Try Again ! " << endl;
        htab(7);
        system("pause");
        adminLogin();
    }
}

// Function for handling the customer login operations
void customerLogin()
{
    int flager;
    string username, check_Uname, check_pswd;
    string password = "";
    string name, surname, age, nid;
    float Bgt;
    float Budget2;
    system("CLS");
    vspace(3);
    htab(6);
    cout << "------------------------------------------------------------------------------" << endl;
    vspace(1);
    htab(8);
    cout << " WELCOME TO THE VEHICLE RENTAL SYSTEM ";
    vspace(2);
    htab(6);
    cout << "------------------------------------------------------------------------------" << endl;
    vspace(3);
    htab(8);
    cout << " U S E R N A M E  : ";
    cin >> username;
    vspace(1);
    htab(8);
    cout << " P A S S W O R D  : ";
    char ch;
    ch = _getch();
    while (ch != 13)
    {
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    ifstream input("database.txt");
    while (input >> name >> surname >> age >> nid >> Bgt >> check_Uname >> check_pswd)
    {
        if (check_Uname == username && check_pswd == password)
        {
            flager = 1;
            Budget2 = Bgt;
            system("CLS");
        }
    }
    input.close();
    if (flager == 1)
    {
        int choice;
        char carSelect[10];
        char motorcycleSelect[10];
        ofstream log;
        log.open("selection_log.txt", fstream::app);
        ofstream ofs;
        ofs.open("temp.txt");
        vspace(2);
        cout << endl;
        string customerName;
        char c;
        vspace(3);
        htab(8);
        cout << " Welcome, " << username << endl;
        vspace(1);
        htab(7);
        cout << " Pick up a Car or motorcycle ? ( 1 or 2 ) : ";
        cin >> choice;

        if (choice == 1)
        {
            float carPrice;
            system("cls");
            vspace(3);
            htab(6);
            cout << "-------------------------- CARS --------------------------" << endl;
            displayCar();
            cout << "";
            vspace(2);
            htab(9);
            cout << " Please select car ";
            vspace(2);
            htab(9);
            cout << " Enter car ID : ";
            cin >> ws;
            cin.getline(carSelect, 10);
            int x = flagCar();
            for (int i = 0; i < flagCar(); i++)
            {
                if (strcmp(carSelect, car[i].car_id) != 0)
                {
                    ofs << car[i].car_id;
                    ofs << " ";
                    ofs << car[i].car_name;
                    ofs << " ";
                    ofs << car[i].car_model;
                    ofs << " ";
                    ofs << car[i].car_paint;
                    ofs << " ";
                    ofs << car[i].car_yearadded;
                    ofs << " ";
                    ofs << car[i].car_speed;
                    ofs << " ";
                    ofs << car[i].car_charge;
                    ofs << " ";
                    if (i != flagCar())
                    {
                        ofs << endl;
                    }
                }
            }
            ofs.close();
            remove("available.txt");
            rename("temp.txt", "available.txt");
            for (int i = 0; i < flagCar(); i++)
            {
                if (strcmp(carSelect, car[i].car_id) == 0)
                {
                    log << "\n Car : " << car[i].car_id;
                    log << "\n Name : " << car[i].car_name;
                    log << "\n Model : " << car[i].car_model;
                    log << "\n Price: " << car[i].car_charge;
                    carPrice = car[i].car_charge;
                }
            }
            log.close();
            system("cls");
            cout << endl;
            int paymentSelection;
            vspace(3);
            htab(8);
            cout << " 1. For Direct payment method " << endl;
            vspace(1);
            htab(8);
            cout << " 2. For Monthly payment method " << endl;
            vspace(3);
            htab(9);
            cout << " Enter Your Choice : ";
            cin >> paymentSelection;
            cout << endl;
            system("cls");
            if (paymentSelection == 1)
            {
                directPay(customerName, carPrice, Budget2);
            }
            else if (paymentSelection == 2)
            {
                montlyPay(carPrice, Budget2);
            }
            cout << endl;
        }
        else
        {
            float motorPrice;
            vspace(3);
            htab(6);
            cout << "-------------------------- MOTORCYCLES --------------------------" << endl;
            displayMotorcycle();
            cout << " ";
            vspace(2);
            htab(9);
            cout << " Please select motorcycle ";
            vspace(2);
            htab(8);
            cout << "Enter motorcycle ID : ";
            cin >> ws;
            cin.getline(motorcycleSelect, 10);
            int x = flagMotorbikes();
            for (int i = 0; i < flagMotorbikes(); i++)
            {
                if (strcmp(motorcycleSelect, mc[i].motorcycle_id) != 0)
                {
                    ofs << mc[i].motorcycle_id;
                    ofs << " ";
                    ofs << mc[i].motorcycle_name;
                    ofs << " ";
                    ofs << mc[i].engine_capacity;
                    ofs << " ";
                    ofs << mc[i].engine_strength;
                    ofs << " ";
                    ofs << mc[i].motorcycle_speed;
                    ofs << " ";
                    ofs << mc[i].motorcycle_weightkg;
                    ofs << " ";
                    ofs << mc[i].motorcycle_fuelcapacity;
                    ofs << " ";
                    ofs << mc[i].motorcycle_charge;
                    ofs << " ";
                    if (i != flagMotorbikes())
                    {
                        ofs << endl;
                    }
                }
            }
            remove("available2.txt");
            rename("temp2.txt", "available2.txt");
            for (int i = 0; i < flagMotorbikes(); i++)
            {
                if (strcmp(motorcycleSelect, mc[i].motorcycle_id) == 0)
                {
                    log << "\n Motorcycle : " << mc[i].motorcycle_id;
                    log << "\n Name : " << mc[i].motorcycle_name;
                    log << "\n Price: " << mc[i].motorcycle_charge;
                    motorPrice = mc[i].motorcycle_charge;
                }
            }
            log.close();
            system("cls");
            cout << endl;
            int paymentSelection;
            vspace(3);
            htab(8);
            cout << " 1. For Direct payment method" << endl;
            vspace(1);
            htab(8);
            cout << " 2. For Monthly payment method" << endl;
            vspace(3);
            htab(8);
            cout << "Enter your choice:";
            cin >> paymentSelection;
            cout << endl;
            system("cls");
            if (paymentSelection == 1)
            {
                directPay(customerName, motorPrice, Budget2);
            }
            else if (paymentSelection == 2)
            {
                montlyPay(motorPrice, Budget2);
            }
            cout << endl;
        }
    }
    else
    {
        cntn_with_forget = cntn_with_forget + 1;
        string decide;
        if (cntn_with_forget != 3)
        {
            vspace(3);
            htab(7);
            cout << " Please check your username or password and try again " << endl;
            vspace(1);
            htab(8);
            cout << " Do you want to try again ??? ( yes / no ) : ";
            cin >> decide;
            if (decide == "yes")
            {
                customerLogin();
            }
            else
            {
                main();
            }
        }
        else
        {
            forget_pswd();
        }
    }
}

// Function for adding user to the text file data.txt
void Func_registration()
{
    string name, surname;
    int age;
    string id;
    float budget;
    vspace(3);
    htab(6);
    cout << "------------------------------------------------------------------------------" << endl;
    vspace(1);
    htab(8);
    cout << " WELCOME TO THE VEHICLE RENTAL SYSTEM ";
    vspace(2);
    htab(6);
    cout << "------------------------------------------------------------------------------" << endl;
    vspace(3);
    htab(8);
    cout << " Enter your name : ";
    cin >> name;
    vspace(1);
    htab(8);
    cout << " Enter your surname : ";
    cin >> surname;
    vspace(1);
    htab(8);
    cout << " Enter your age : ";
    cin >> age;
    vspace(1);
    htab(8);
    cout << " Enter your National ID : ";
    cin >> id;
    vspace(1);
    htab(8);
    cout << " Enter your Budget : ";
    cin >> budget;
    string regusername, regpassword;
    vspace(1);
    htab(8);
    cout << " Enter your username : ";
    cin >> regusername;
    ifstream check("data.txt");
    string tempusername, tempHold;
    while (check >> tempusername && check >> tempHold)
    {
        if (tempusername == regusername)
        {
            vspace(3);
            htab(10);
            cout << " Username already exist !";
            check.seekg(0, ios::beg);
            vspace(2);
            htab(10);
            cout << " Enter new username : ";
            cin >> regusername;
        }
    }
    vspace(3);
    htab(9);
    cout << " Enter new Password : ";
    cin >> regpassword;
    ofstream reg("data.txt", ios::app);
    reg << regusername << " " << regpassword << " " << id << endl;
    ofstream regg("database.txt", ios::app);
    regg << name << " " << surname << " " << age << " " << id << " " << budget << " " << regusername << " " << regpassword << endl;

    vspace(3);
    htab(9);
    cout << " Registration completed succesfully! ";
    string decide;
    vspace(2);
    htab(8);
    cout << " Do you want to Login ??? ( yes / no ) : ";
    cin >> decide;
    if (decide == "yes")
    {
        customerLogin();
    }
    else
    {
        main();
    }
}

// Function to handle the ooperation when a customer forgets theri password
void forget_pswd()
{
    int flag_forget = 0;
    string User_name, id, searchUser, searchpswd, searchID;
    system("CLS");
    vspace(3);
    htab(6);
    cout << "----------------------- Welcome to Vehicle Rental System -----------------------";
    vspace(4);
    htab(9);
    cout << " PASSWORD REMINDER ";
    vspace(1);
    htab(9);
    cout << "-------------------";
    vspace(4);
    htab(8);
    cout << " Please Enter Your Username : ";
    cin >> User_name;
    vspace(2);
    htab(8);
    cout << " Please Enter Your National ID : ";
    cin >> id;
    ifstream searchUsername("data.txt");
    while (searchUsername >> searchUser >> searchpswd >> searchID)
    {
        if (searchID == id && searchUser == User_name)
        {
            flag_forget = 1;
        }
    }
    searchUsername.close();
    if (flag_forget == 1)
    {
        vspace(3);
        htab(9);
        cout << " Your password is : " << searchpswd;
        cin.get();
        int choice;
        vspace(2);
        htab(9);
        cout << " Press any key for menu ...";
        cin >> choice;
        if (choice == 1)
        {
            main();
        }
        else
        {
            main();
        }
    }
    else
    {
        vspace(3);
        htab(8);
        cout << " Wrong Username , Please try again! ";
        cin.get();
        system("pause");
        system("CLS");
        forget_pswd();
    }
}

// Function created for showing all the available users
void UsersList()
{
    ifstream vausers("database.txt");
    string line = "  ";
    int i = 1;

    if (vausers.is_open())
    {
        htab(7);
        cout << "ID  "
                "Name  "
                "Surname  "
                "Age  "
                " ID  "
                "Budget  "
                "Username  "
                "Password  "
             << endl;
            vspace(2);

        while (getline(vausers, line))
        {
            htab(7);
            cout << (i++) << "." << "  " << line << "  " << endl;
            vspace(1);
        }

        vausers.close();
    }
}

int main()
{

    int choice;
    system("CLS");
    vspace(2);
    htab(8);
    cout << "****************************************************" << endl;
    htab(9);
    cout << "WELCOME TO THE VEHICLE RENTAL SYSTEM";
    vspace(1);
    htab(8);
    cout << "****************************************************" << endl;
    vspace(1);
    htab(10);
    cout << " OOPS MTE PROJECT " << endl;
    htab(10);
    cout << "******************" << endl;
    vspace(2);
    htab(10);
    cout << "M A I N    M E N U" << endl;
    htab(10);
    cout << "*******************" << endl;
    vspace(2);
    htab(7);
    cout << "1. Admin Login ";
    vspace(2);
    htab(7);
    cout << "2. Login to an existing Customer account ";
    vspace(2);
    htab(7);
    cout << "3. Add new customer / Register to a New account ";
    vspace(2);
    htab(7);
    cout << "4. Forgot Password ???";
    vspace(2);
    htab(7);
    cout << "5. Exit Program";
    vspace(2);
    htab(9);
    cout << " Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        adminLogin();
        break;

    case 2:
        customerLogin();
        break;

    case 3:
        system("cls");
        Func_registration();
        break;

    case 4:
        system("cls");
        forget_pswd();
        break;

    case 5:
    {
        system("CLS");
        string decide;
        vspace(1);
        htab(7);
        cout << "Do you want to really exit ??? ( yes / no ): ";
        cin >> decide;
        if (decide == "yes")
        {
            vspace(2);
            htab(6);
            cout << " Thank You For Shooping With Us !!! I Hope You'll Visit Us Again!!! " << endl;
            break;
        }
        else
        {
            system("CLS");
            main();
        }
    }
    default:
        vspace(2);
        htab(8);
        cout << " OOPS!!! Wrong Choice! Try Again please!" << endl;
        main();
    }
}