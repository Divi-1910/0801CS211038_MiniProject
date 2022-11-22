//                                          PROGRAMMING PRACTICES MINI PROJECT
//                                                       IN C++
//                                                     PHONEBOOK
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
using namespace std;

#define MAX 1000 // the maximum number of persons whose data can be stored in the phonebook

struct Contacts{
    string contacts_Name;       //name of the person
    int contacts_Gender = 1;    //gender of the person
    int contacts_Age = 0;       //age of the person
    string contacts_Phone_number;      //phone number of the person
    string contacts_Address;        //address where the person lives
};;

struct Phonebook{
    Contacts contacts_array[MAX]; // array of contact which stores the person's information
    int phonebook_count = 0; // number of people whose information is stored in the phonebook
};

void AddContacts(Phonebook *pb){

    //checking whether the phonebook is full or not
    if(pb -> phonebook_count == MAX){
        cout << "The PhoneBook is full and more contacts cannot be added! " << endl;
        return;
    }
    else{
      // Adding name
      string name;
      cout << "\t enter the name :- ";
      cin.ignore();
      getline(cin,name);
      pb -> contacts_array[pb->phonebook_count].contacts_Name = name;

      // Adding gender
      int gender;
      cout << "\t enter the gender option - " << endl;
      cout << "\t 1 for male" << endl;
      cout << "\t 2 for female" << endl;
      cout << "\t enter - ";
      while(true){
        cin >> gender;
        if(gender == 1 || gender == 2){
            pb ->contacts_array[pb ->phonebook_count].contacts_Gender = gender;
            break;
        }
        cout << "\t Input error - Please re-enter! " << endl;
      }

       //Adding age
       int age;
       cout << "\t enter the age - ";
       cin >> age;
       pb ->contacts_array[pb->phonebook_count].contacts_Age = age;

       //Adding phonenumber
       string phone;
       cout << "\t enter the phone number - " ;
       cin.ignore();
       getline(cin,phone);
       pb ->contacts_array[pb->phonebook_count].contacts_Phone_number = phone;

       //Adding Address
       string address;
       cout << "\t enter the address - ";
       cin.ignore();
       getline(cin,address);
       pb ->contacts_array[pb->phonebook_count].contacts_Address = address;

       // increasing the phonebook count
       pb ->phonebook_count += 1;
       cout << "\t contact details added successfully!!" << endl;
       cout << endl;
       //clear screen
       system("pause");
       system("cls");
    }

}

// to check whether the name exists in the phonebook or not
int IsExit(Phonebook *pb , string name){
    for(int i=0 ; i<pb->phonebook_count ;i++){
        if(pb->contacts_array[i].contacts_Name == name){
            return i;
        }
    }
    return -1;
}

//function to delete contact
void DeleteContacts(Phonebook *pb){
    string name; //record the contact name whose details you want to delete
    cout <<"\t enter the name which you want to delete - ";
    cin.ignore();
    getline(cin,name);
    cout << endl;
    int index = IsExit(pb ,name); //to check whether the name of the contact exists

    if(index > -1){
        for(int i=index ; i < pb->phonebook_count - 1; i++){
            Contacts temp = pb ->contacts_array[i];
            pb->contacts_array[i] = pb->contacts_array[i+1];
            pb->contacts_array[i+1] = temp;
        }

        //reduce a record
        pb->phonebook_count--;
        cout << "\t delete successfull " << endl;
    }//when the name does not exists
    else{
            cout << "\t no such person found" << endl;
    }
    system("pause");
    system("cls");

}

//function to find contacts
void GetContacts(Phonebook *pb){
    string name; // name entered by the user to look for
    cout <<"\t enter the name you are looking for - " ;
    cin.ignore();
    getline(cin , name);
    // to check if the contact exists
    int index = IsExit(pb , name);
    if(index > -1){
        // if it exists
        cout << "\t Name - " << pb->contacts_array[index].contacts_Name << endl;
        cout << "\t Gender - "<< (pb->contacts_array[index].contacts_Gender!= 2 ? "Male" : "Female" ) << endl;
        cout << "\t Age - " << pb->contacts_array[index].contacts_Age << endl;
        cout << "\t Phone Number - " <<pb->contacts_array[index].contacts_Phone_number<<endl;
        cout << "\t Address - " << pb ->contacts_array[index].contacts_Address<<endl;
    }
    else{
        // if it doesnt exists
        cout << "\t no such person found "<< endl;
        cout << endl;
    }
    system("pause");
    system("cls");
}

//function to modify contacts
void ModifyContacts(Phonebook *pb){
    string name; // enter the name which needs to be modified
    cout << "\t enter the name which you want to modify - ";
    cin.ignore();
    getline(cin,name);
    //to check if the contact exists
    int index = IsExit(pb , name);
    if(index  > -1){
        //modify name
        string name; // if the name exists
        cout << "\t enter the modified name - ";
        cin.ignore();
        getline(cin,name);
        pb ->contacts_array[index].contacts_Name = name;
        cout << endl;

        //gender cannot be modified
        cout <<"\t gender cannot be modified " << endl;
        cout << endl;

        //modify age
        int age;
        cout << "\t enter the modified age - ";
        cin >> age;
        cout << endl;
        pb ->contacts_array[index].contacts_Age = age;

        //modify phone
        string phone;
        cout << "\t enter the modified phone number - ";
        cin >> phone;
        cout << endl;
        pb ->contacts_array[index].contacts_Phone_number = phone;

        //modify address
        string address;
        cout << "\t enter the modified address - ";
        cin.ignore();
        getline(cin , address);
        cout << endl;
        pb ->contacts_array[index].contacts_Address = address;
        cout << endl;
        cout << "\t modified details successfully! " << endl;
    }
    else{
        //does not exist
        cout << "\t No such person found " << endl;
    }
    system("pause");
    system("cls");

}

//function to clear contacts
void ClearContacts(Phonebook *pb){
    string choose ="N";
    cout << "\t Are you sure you want to clear the phone book? (Y to confirm/N to cancel)" << endl;
    cout << "\t";
    while(true){
        cin >> choose;
        if(choose =="Y" || choose =="N"){
            break;
        }
        else{
            cout << "\t input is wrong , please re enter!! " << endl;
        }
    }

    if(choose == "Y"){
        pb->phonebook_count = 0;
        cout << "\t Cleared Successfully !! " << endl;
    }
    else{
        cout << "\t Canceled" << endl;
    }
    system("pause");
    system("cls");

}


// function to show contacts
void ShowContacts(Phonebook * pb){
    if(pb ->phonebook_count == 0){
        cout << "\t No contacts,please add contacts first!" << endl << endl;
    }
    else{
        //to show all contacts
        for(int i=0 ; i < pb->phonebook_count; i++){
            cout << "Name - " << pb->contacts_array[i].contacts_Name << "| Gender - " << (pb->contacts_array[i].contacts_Gender != 2 ? " male " : " female ") << "| Age - " << pb->contacts_array[i].contacts_Age << "| PhoneNumber - " << pb->contacts_array[i].contacts_Phone_number << "| Address - " << pb->contacts_array[i].contacts_Address << endl;
        }
    }
    system("pause");
    system("cls");
}

void ShowTime(){
    time_t tt;
    struct tm * ti;
    time(&tt);
    ti = localtime(&tt);
    cout << asctime(ti);
}

// function to show the phonebook start page
void PhoneBook_Start(){
    cout << "   Welcome To This PHONEBOOK APPLICATION   " << endl;
    cout << "        enter your name - ";
    string owner_name;
    getline(cin,owner_name); // asking the user for his name
    cout << "current login time - " ;
    ShowTime();
    cout << endl << endl;

}

// function to show the menu of the phonebook
void ShowMenu(){
    cout << "\t PhoneBook System        " << endl << endl;
    cout << "\t 1.Add Contact           " << endl;
    cout << "\t 2.Show Contacts         " << endl;
    cout << "\t 3.Delete Contact        " << endl;
    cout << "\t 4.Find a COntact        " << endl;
    cout << "\t 5.Edit Contact          " << endl;
    cout << "\t 6.clear Contact         " << endl;
    cout << "\t 7.exit PhoneBook        " << endl << endl;
    cout << "\t \t \t -version 1.0" << endl;
}

// main function
int main(){
    PhoneBook_Start();
    int select_option = 0; // to select the option from the menu
    Phonebook pb; // creating a pb to store all the data
    pb.phonebook_count=0; // setting the current number of people in the phonebook to zero

    while(true){
        ShowMenu(); //to show main menu
        cout << endl << "Select an Option - ";
        cin >> select_option;

        switch(select_option){
        case 1: //to add contact
            AddContacts(&pb); //passing pb to the function
            break;
        case 2: //to show contacts
            ShowContacts(&pb); //passing pb to the function
            break;
        case 3: // to delete contacts
            DeleteContacts(&pb); //passing pb to the function
            break;
        case 4: // to find a contact
            GetContacts(&pb); //passing pb to the function
            break;
        case 5: // to modify a contact
            ModifyContacts(&pb);
            break;
        case 6: // to clear the contact
            ClearContacts(&pb);
            break;
        case 7: // to exit the phonebook
            cout <<"\t thank you for using , GoodBye! " << endl;
            return 0;
            break;
        default:
            cout << "\t please select a correct option " << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}
