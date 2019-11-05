#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<conio.h>


#define MAX    100


using namespace std;

class itemEntry{ //declare class
public:
    //declare attributes
    char name[30];
    int quantity;
    char typeOfFood[30];
};

class Food{ //declare class
public:
    //declare attributes
    int numItem;
    itemEntry database[MAX];

    Store(){
        numItem = 0;
    }
void insertItem( char itemName[], char type[],int q);
void deleteItem( char itemName[]);



};
void Food::insertItem(char itemName[], char type[],int q){

    strcpy( database[numItem].name, itemName); //copy string
    strcpy( database[numItem].typeOfFood, type); //copy string
    database[numItem].quantity = q; //copy string

    cout << "Item Inserted Successfully.\n";
    ++numItem; //increase numItem +1

}


void Food::deleteItem( char itemName[]){ //delete function

    for(int i = 0; i < numItem; i++){
        if( strcmp( itemName, database[i].name) == 0){ //check if there object with that name
            database[i] = {}; //reset the values - for user this will be as deleted
            cout << "Item Deleted Successfully.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}


int main(){
    Food foo; //declare object
    char option, name[30], typeOfFood[30];
    char quantity[10];
    while( option != 'e' ){ //if e - quit
        cout << "\n----------->Enter your choice:<------------\n";
        cout << "I for insert\n";
        cout << "D for delete\n";
        cout << "S for search\n";
        cout << "E for exit\n";


        cin.getline( name, 80); //get input
        option = name[0];

        switch( option){ // switch case

            case 'i':
            cout << "Enter Name of Food"<<endl;
            cin.getline( name, 80); //get input from user
            cout<<"Enter Type of Food(Drink/Food/Spice/Fruit)"<<endl;
            cin.getline(typeOfFood, 80); //get input from user
            cout<<"Please enter quantity"<<endl;
            cin.getline(quantity, 80); //get input from user
            foo.insertItem( name, typeOfFood, atoi(quantity)); //insert the values into object
            break;

          case 'd':
            cout << "Enter name of your item:\n";
            cin.getline(name, 80); //get input from user
            foo.deleteItem(name); //call delete function and pass the value of name
            break;

          case 's':
            cout << "Enter Type of your Item(Drink/Food/Spice/Fruit)\n"<<endl;
            cin.getline(typeOfFood, 80); //get input from user
            itemEntry temp; //temp variable for sorting
            cout<<"---------------->Searching Result<---------------------" <<endl;
            for(int i = 0; i < foo.numItem; i++){ //bubble sort
                for(int j = 0; j < foo.numItem; j++){
                    if(foo.database[i].name < foo.database[j].name){ //if true swtich places

                            temp = foo.database[i];
                            foo.database[i] = foo.database[j];
                            foo.database[j] = temp;

                    }
                }
            }

            for(int i = 0; i < foo.numItem; i++){ //print values based on type of food
                if( strcmp( typeOfFood, foo.database[i].typeOfFood) == 0){ //compare if the objects have the same type of food

                    cout<<i<<". "<< foo.database[i].name<<endl; //print the names
                }
            }
        }
    }
}
