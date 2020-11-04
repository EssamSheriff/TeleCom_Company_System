#include <string>
#include <iostream>
using namespace std;

#define num_driver 2
#define num 2

//Compiler version g++ 6.3.
struct Date
{
    int day=0;
    int month=0;
    int year=0;
};
struct officer
{
    string name_street = {};
    Date DateOfDay = {};
    int SpeedOfCar = {};
    int SpeedOfstreet = {};
    int plat_number = {};
    int value_fines = 1;
}car[num] = {}, O1;
struct car1 {
    string model_car = {};
    int product_year = {};
    int plate_number{};
};
struct driver {
    string name;
    Date DateOfBirth={};
    string license_number = {};
    int number_car = {};
    car1 cars[num] = {};
    int sum=0;
}D[100];
void add_Data(officer& O)//add data from the officer in the first
{
    for (int i = 0; i < num ; i++)
    {
        cout << "enter the name street" << endl;
        cin >> car[i].name_street;
        cout << "enter the speed of street" << endl;
        cin >> car[i].SpeedOfstreet;
        cout << "enter the speed of car" << endl;
        cin >> car[i].SpeedOfCar;
        cout << "enter plat number of  the car " << endl;
        cin >> car[i].plat_number;
        cout << "enter the date of day" << endl;
        cin >> car[i].DateOfDay.day >> car[i].DateOfDay.month >> car[i].DateOfDay.year;

        cout << ".................................." << endl;
    }
}
void search_about_car ();
void violation_record(officer& O)
{
    float result;
    for (int i = 0; i < num; i++)
    {
        if (car[i].SpeedOfCar > car[i].SpeedOfstreet)  //To find the value of the fine
        {
            result = car[i].SpeedOfCar - car[i].SpeedOfstreet;
            car[i].value_fines = 2* result;

        }

}
}
void display_fines() // it displays the value of the fine and whether or not it is paid
{
    int plat_number;
    int money;
    cout << "enter the plat namber" << endl;
    cin >> plat_number;
    violation_record(O1);
    for (int i = 0; i <= num; i++)
    {
        if (plat_number == car[i].plat_number)
        {  if (car[i].SpeedOfCar > car[i].SpeedOfstreet)

             {
                 cout << "the value of fines\t" << car[i].value_fines << endl;
            cout << " If you want to pay the fine,please enter value of the money" << endl;
            cin >> money;
            cout<<"The amount of money you entered = " <<money<<endl;
            if (money >= car[i].value_fines) {

                cout << "The fine is paid" << endl;
                break;
            }
            else
              cout << "The fine is not paid " << endl;
             }
            else
               cout << "you don't have fines,the value of fines = 0" << endl;
        }
    }
}
void add_DataDriver() // add data from the driver
{ /*int num_driver;
    cout<<"How many drivers do you want to enter thier information :"<<endl;
    cin>>num_driver;*/
 for (int j = 0; j <num_driver ; j++)
    {
         cout << "enter the driver name number " << j+1<<": "<< endl;
        cin >> D[j].name;
        cout << "enter the  date of birth" << endl;
        cin >> D[j].DateOfBirth.day >> D[j].DateOfBirth.month >> D[j].DateOfBirth.year;
        cout << " enter the license number" << endl;
        cin >> D[j].license_number;
        cout << "enter number of the own  your cars, you should be not exceed 3 cars" << endl;
        cin >> D[j].number_car;
        if(D[j].number_car <=3)
        {for (int i = 0; i < D[j].number_car; i++)
        {
           cout << "enter plate number  the  car " << i+1<<": "<<endl;
            cin >> D[j].cars[i].plate_number;
            for (int i = 0; i <= num; i++)
               {


               if(D[j].cars[i].plate_number == car[i].plat_number)
                      { violation_record(O1);
                     D[j].sum += car[i].value_fines;

           }
           else
           {
           continue;
           }


            }
            cout << "enter the model car " << endl;
            cin >> D[j].cars[i].model_car;
            cout << "enter the product year" << endl;
            cin >> D[j].cars[i].product_year;
        }
        }
        else
        cout<<"error process"<<endl;
    }

}
   void display_total_fines(string name, int plat)  //show  the total of unpaid fines
    {

             add_DataDriver();
           for (int j = 0; j <num_driver ; j++)
          {
           for (int i = 0; i <num; i++)
         {

             if(name== D[j].name ||plat==car[i].plat_number)
              {
                 cout<<"total of finess"<<D[j].sum<<endl;

                }
           else

          {

                continue;


            }
         }
             }

     }


   /*void search(string name, int plat_number)
   {
     driver D;
     for (int i = 0; i <= num; i++)
     {
       if (plat_number == car[i].plat_number || name == name)
       {
         cout << "the model_car is" << D.model_car << endl;
         cout << "the product_year  is" << D.product_year << endl;
       }
     }
   */



int main()
{ int plat; string name;
    string x;

   // driver D[10];
    int money;
    int choose;
    cout << "The data must be entered first by the officer" << endl;
    add_Data(O1);

cout << "...................................." << endl;
    do
    {
        cout << " select one option below: " << endl;
        cout << "1:add data from driver " << endl;
        cout << "2:display fines" << endl;
        cout << "3:search about  cars" << endl;
        cout << "4: display total fines " << endl;
        cout << "5: exit the list " << endl;
        cout << "enter the option " << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            add_DataDriver();
            break;
        case 2:

            display_fines();
            break;
        case 3:
            search_about_car();
            break;
        case 4:
         cout<<"enter the driver name: "<<endl;
    cin>>name;
    cout<<"enter the plate number :"<<endl;
    cin>>plat;
            display_total_fines(name,plat);
            break;
        case 5:
           //exit(0);
        default:
            cout << "You are wrong,enter the correct number" << endl;
        }
        cout << "Do you want to select next option ,then press Y;" << "if you want to exit ,then press N" << endl;
        cin >> x;
        if (x == "N" || x == "n")
        {
          //  exit(0);
        }
    } while (x == "Y" || x == "y");
    return 0;
}
void search_about_car() {
    int plate;
    cout << "driver plate number:\n";
    cin >> plate;
    for(int i=0;i<num;++i)
    if (plate == car[i].plat_number) {
        cout << "violation location(street):" << car[i].name_street << endl;
        cout << "the street speed:" << car[i].SpeedOfstreet << endl;
        cout << "the car speed:" << car[i].SpeedOfCar << endl;
        violation_record(O1);
        cout << "the fine:"<< car[i].value_fines << endl;
        cout << "---------------------------------------------------------------\n";
    }

}
