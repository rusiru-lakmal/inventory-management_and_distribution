#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define ENTER 13
#define BKSP 8
#define SPACE 32
void delay(int); //function prototype
int main();//function prototype
void user(char password[]);//function prototype
void arrngeItem();//function prototype
void addproduct();//function prototype
void uploading();//function prototype
void arrengesort();//function prototype
void loadLimit(char[],char[]);//function prototype
void checkInventryUnload(char[]);//function prototype
void vehiclCheckLoad(char[]);//function prototype
void checkInvenLoad(char[]);//function prototype
void checkDisto(char[]);//function prototype
void checkVehiclUnload(char[],char[]);//function prototype
void vehiclCheckUnload(char[]);//function prototype
void displayPass(char[],char[]);//function prototype
void creatdisplay(char[]);//function prototype
void displyChartitem();//function prototype
void unload();//function prototype
void additem();//function prototype
void disVehicle();//function prototype
void foward();//function prototype
void welcome();//function prototype
void head();//function prototype
void stroeView();//function prototype
void sellsView();//function prototype
void loadView();//function prototype
void vehiview();//function prototype
void deleVhicle();//function prototype
void report();//function prototype
void vehiManage();//function prototype
void last();//function prototype
void sotView();//function prototype
void gotoxy(int,int);//function prototype
void displyChart();//function prototype
void checkInput(int,int,int*);//function prototype
void checkFlotInput(float,int,float*);//function prototype
void changes();//function prototype
void changeIPrice();//function prototype
void changeCode();//function prototype
void changeQty();//function prototype
void serch();//function prototype
const int LENGTH=100;
int count=0;
int count1=0,counting=0;
struct distribute // structure of vehicle
{
    char vehicle[20];
    char name[20];
    char id[20];
    int telNo;
};
struct goods  // structure of goods
{
    char itemCode[20];
    char itemName[20];
    int quintity;
    float price;
    int sels;
    int load;
    float selling;
    struct distribute loading;//link with above structure for access

};
void addproduct()// add new product function
{
    struct goods add;
    struct goods chk;
    FILE *ptrAdd,*ptrcheck;
    int tst=0,press;
    add.load=0;
    head();
    gotoxy(53,4);printf("-ADD NEW PRODUCT-");
    ptrcheck=fopen("currentInventory.dat","r");// open inventory file to check whether  it is a new product
    gotoxy(32,6);printf("Enter product code     : ");
    scanf("%s",add.itemCode);
    while(fscanf(ptrcheck," %s %s %d %f ",chk.itemCode,chk.itemName,&chk.quintity,&chk.price)!=EOF)//get data from inventory file to structure veriables
    {
        int cmp=strcmp(chk.itemCode,add.itemCode);// after getting the data form file , check item code whether they are equal
        if(cmp==0)
        {
          tst=1;// assume tst =1 ,if they id are equal
        }
    }
    fclose(ptrcheck); //close inventory file
    if(tst==1) // if tst is 1, that product have  already in inventory, therefore increase that product quantity using id of item , in increase function
    {
        gotoxy(40,11);printf("THE PRODUCT ALREADY HAVE !!!!");
        gotoxy(39,13);printf("PLEASE INCREASE ITEAM USING ADD ITEM!");
        gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU  : ");
        scanf("%d",&press);
        if(press==1)
        {
            system("cls");// clear screen
            addproduct();// recall this function
        }
        else{
                system("cls");
            main();// call main function
        }


    }
    gotoxy(32,10);printf("Enter product name     : ");
    fflush(stdin);//that use because getting string input form user
    gets(add.itemName);// using gets , because get input user string separate string input with space key ,because it does not get using scanf
    fflush(stdin);
    gotoxy(32,14);printf("Enter product quintity : ");
    int check=scanf("%d",&add.quintity);
    if(check!=1.0)//if check quantity input user entered as charactor key of keyboard, give another enter it
    {
        gotoxy(32,14);printf("PLEASE ENTER THE VALID INPUTS !!!");
        gotoxy(32,15);printf("please renter : ");
        fflush(stdin);
        scanf("%d",&add.quintity);//get extra input that quantity
    }
    checkInput(add.quintity,14,&add.quintity);//calling function passing one veriable ,one address of veriable and passing one value of alignment

    gotoxy(32,18);printf("Enter product price    : ");
    int checks = scanf("%f",&add.price);
    if(checks!=1.0) //if check quantity input user entered as charactor key of keyboard, give another enter it
    {
        gotoxy(32,18);printf("PLEASE ENTER THE VALID INPUTS!!");
        gotoxy(32,19);printf("please renter : ");
        fflush(stdin);
        scanf("%f",&add.price);//get extra input that price
    }
    checkFlotInput(add.price,18,&add.price);//calling function passing one veriable ,one address of veriable and passing one value of alignment

    ptrAdd = fopen("currentInventory.dat","a+"); //open inventory file to write a new product or create inventory file to write a new product


       fprintf(ptrAdd," %s %s %d %f ",add.itemCode,add.itemName,add.quintity,add.price);// write to file this data this oder
    fclose(ptrAdd);//close file
    gotoxy(43,23);printf("ADDED SUSCESSFULLY!!!");
   foward();// calling foward function

}
void checkInput(int chk,int poss,int *id ) //check integer input function
{

    if(chk<0)  // check the integer input whether lesser than zero and give a new enter that integer as greater than zero
    {
        gotoxy(32,poss);printf("PLEASE ENTER THE VALID INPUTS!!");
        gotoxy(32,poss+1);printf("please renter : ");
        fflush(stdin);
        scanf("%d",id);
    }
}
void checkFlotInput(float chk,int poss,float*id)//check float input function
{
    if(chk<0) // check the float input whether lesser than zero and give a new enter that float as greater than zero
    {
        gotoxy(32,poss);printf("PLEASE ENTER THE VALID INPUTS!!");
        gotoxy(32,poss+1);printf("please renter : ");
        fflush(stdin);
        scanf("%f",id);


    }
}
void uploading()//function of load to vehicle
{
    ++count;
   char idVe[LENGTH],item[LENGTH];
   FILE*ptrReadVehiclSto,*ptrReadInventry,*ptrWriLoad,*ptrWriDuplicte,*ptrDisplay;
   struct goods geting;

   head();// calling to head function
   gotoxy(53,4);printf("-LOADING-");

   ptrReadVehiclSto=fopen("vehiclestore.dat","r"); // open vehicle store file to read data
   if(ptrReadVehiclSto==NULL)// check if the file is have  already
   {
       gotoxy(40,15);printf("THERE IS NO FILE TO OPEN ");
       gotoxy(40,17);printf("PLEASE INCLUDE A VEHICLE !");
       foward();// calling to foward funtion
   }
   fclose(ptrReadVehiclSto); //read  file closed


   gotoxy(25,6);printf("Enter product code : ");
   scanf("%s",item);
   checkInvenLoad(item);// calling to inventory load fountion to check this product id is in inventory file
   creatdisplay(item);
   gotoxy(25,9);printf("Enter vehicle ID : ");
   scanf("%s",idVe);

   vehiclCheckLoad(idVe);  // calling to vehicle check function and passing vehicle id to check this vehicle id is already have in vehicle store file

   loadLimit(item,idVe);// calling to load item  function to check this vehicle id and product id is in disto  file

   ptrReadInventry=fopen("currentInventory.dat","r"); //open inventory file to read data
   ptrWriDuplicte=fopen("duplicte.dat","w"); // open and write data  changing certain data
   ptrWriLoad=fopen("disto.dat","a+"); // write a new file or write load details this file
   ptrDisplay=fopen("display.dat","a+");//  write a new file or write vehicle id and product id only this file to display

   while(fscanf(ptrReadInventry," %s %s %d %f ",geting.itemCode,geting.itemName,&geting.quintity,&geting.price)!=EOF) // read data and getting this structure veriable form inventory file
   {
       int cmp2=strcmp(geting.itemCode,item);// compare input item code and gotten  codes whether they are equal
       if(cmp2==0)//check if there are qual
       {
           geting.load=10; // load to vehicle certain amount of item quantity input each product
           geting.quintity-=10; // load quantity subtraction from inventory quantity
           fprintf(ptrWriLoad," %s %s %d %f %d %s ",geting.itemCode,geting.itemName,geting.quintity,geting.price,geting.load,idVe);
           fprintf(ptrWriDuplicte," %s %s %d %f ",geting.itemCode,geting.itemName,geting.quintity,geting.price);// write duplicate inventory file saving changes one recod
           fprintf(ptrDisplay," %s %s ",idVe,geting.itemCode);
           gotoxy(25,13);printf("SUCESSFULY FILED THE VEHICLE!!!!!!");
       }
       else
       {
        fprintf(ptrWriDuplicte," %s %s %d %f ",geting.itemCode,geting.itemName,geting.quintity,geting.price);//write duplicate inventory file these records without changed record
       }
   }

   fclose(ptrReadInventry);
   fclose(ptrWriLoad);
   fclose(ptrWriDuplicte);
   fclose(ptrDisplay);

   remove("currentInventory.dat"); // remove inventory file form progaramm
   rename("duplicte.dat","currentInventory.dat"); //wrote duplicate file rename as inventory file

   foward();// calling to foward funtion
}
void creatdisplay(char item[LENGTH])
{
    struct goods getin;
    FILE *ptrDisplay;
    int no=0,i=0;
    char id[LENGTH][LENGTH];
    ptrDisplay=fopen("disto.dat","r");
   while(fscanf(ptrDisplay," %s %s %d %f %d %s ",getin.itemCode,getin.itemName,&getin.quintity,&getin.price,&getin.load,id[i])!=EOF)
   {
      int cmps=strcmp(getin.itemCode,item);
      if(cmps==0)
      {
         if(getin.load==10)
         {
            ++no;
            for(i=0;i<no;i++)
             {
                gotoxy(73,15+i);printf("%s",id[i]);
                gotoxy(95,15+i);printf("laoded");
            }
         }
      }
   }
   fclose(ptrDisplay);
   /*

     ""    goto(x,y) function is using for print frame outlings  and set alignment  which i want        "


 */

   gotoxy(80,9);printf("WAITING TO LOAD");
   gotoxy(73,12);printf("VEHICLE ID");
   gotoxy(95,12);printf("STATUS");
   gotoxy(65,11);printf("%c",201);
   gotoxy(65,14);printf("%c",204);
   gotoxy(65,12);printf("%c",186);
   gotoxy(65,13);printf("%c",186);
   for(i=66;i<=86;i++)
   {
       gotoxy(i,11); printf("%c",205);
       gotoxy(87,11); printf("%c",203);
       gotoxy(87,12); printf("%c",186);
       gotoxy(87,13); printf("%c",186);
   }
    for(i=88;i<=109;i++)
   {
       gotoxy(i,11); printf("%c",205);
   }
   gotoxy(110,11);printf("%c",187);
   gotoxy(110,12);printf("%c",186);
   gotoxy(110,13);printf("%c",186);
   gotoxy(110,14);printf("%c",185);
    for(i=66;i<=86;i++)
   {
       gotoxy(87,14);printf("%c",206);
       gotoxy(i,14);printf("%c",205);
       gotoxy(i,no+16);printf("%c",205);
   }
   for(i=88;i<=109;i++)
   {
       gotoxy(i,14);printf("%c",205);
       gotoxy(i,no+16);printf("%c",205);
   }
   for(i=15;i<=no+15;i++)
   {
       gotoxy(65,i);printf("%c",186);
       gotoxy(65,no+16);printf("%c",200);
   }
    for(i=15;i<=no+15;i++)
    {
        gotoxy(87,i);printf("%c",186);
    }
   gotoxy(87,no+16);printf("%c",202);//y=37
   gotoxy(110,no+16);printf("%c",188); //y=37

    for(i=15;i<=no+15;i++)
   {
       gotoxy(110,i);printf("%c",186);//y=36
   }

}
void vehiclCheckLoad(char id[LENGTH]) // vehicle check load function to check inputed vehicle id whether it is in vehicle store file
{
    FILE*ptrView;
    struct goods add;
    ptrView=fopen("vehiclestore.dat","r");//open vehicle store file to read data
    int testOne=0,press;
   while(fscanf(ptrView," %s %s %s %d ",add.loading.vehicle,add.loading.name,add.loading.id,&add.loading.telNo)!=EOF) // get data from vehicle store  file to structure veriables
   {
       int cmp=strcmp(add.loading.vehicle,id);//vehicle ids in  vehicle store  file compare with inputed vehicle id
       if(cmp==0)
       {
          testOne=1;//assume testOne is 1 ,if inputed vehicle id equal with certain store vehicle id
       }
   }

   fclose(ptrView);//close the opened file
   if(testOne==0)//check if the inputed vehicle id dose not match vehicle store  file ids
   {
       gotoxy(40,20);printf("THERE IS NO SUCH VEHICLE ID ");
       delay(30);
       gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
         system("cls");
        if(press==1)
        {
             uploading(); // calling to uploading function again
        }
        else{
            main(); // calling to main function
        }
   }


}
void loadLimit(char idNo[LENGTH],char idOfVehicle[LENGTH])// load limit function to check if certain item code and certain vehicle id in disto file ,does not input that item code again to that vehilce if is loadded full
{

    FILE*ptr;
    struct goods getin;
    int tst=0,press;
    ptr=fopen("disto.dat","r");// opento read disto file
    while(fscanf(ptr," %s %s %d %f %d %s ",getin.itemCode,getin.itemName,&getin.quintity,&getin.price,&getin.load,getin.loading.vehicle)!=EOF)
    {
        int cmpOne=strcmp(getin.itemCode,idNo);//item code  in  disto file compare with inputed item code
        int cmpTwo=strcmp(getin.loading.vehicle,idOfVehicle);//vehicle ids in  disto  file compare with inputed vehicle id
        if(cmpOne==0)
        {
            if(cmpTwo==0)
            {
              if(getin.load==10)
              {
                  tst=1; // assume that tst is 1, inputed vehicle id,item code is already in disto file , and load quantity is 10
              }
            }
        }
    }
  fclose(ptr);
  if(tst==1)
  {
      gotoxy(40,20);printf("THERE IS VEHICLE FULLED THIS PRODUCT!!!!");
      gotoxy(40,23);printf("PLEASE LOADED ANOTHE PRODUCT ITEM!!! ");
      delay(30);
      gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
         system("cls");
        if(press==1)
        {
            uploading();
        }
        else{
            main();
        }
  }

}
void vehiclCheckUnload(char id[LENGTH]) //to check inputed vehicle id is in vehicle inventory
{
   FILE*ptrView;
    struct goods add;
    ptrView=fopen("vehiclestore.dat","r");
    int testOne=0,press;

   while(fscanf(ptrView," %s %s %s %d ",add.loading.vehicle,add.loading.name,add.loading.id,&add.loading.telNo)!=EOF)//getting data from vehicle inventory
   {
       int cmp=strcmp(add.loading.vehicle,id);
       if(cmp==0)
       {
          testOne=1;
       }
   }

fclose(ptrView);
   if(testOne==0)
   {
       gotoxy(40,20);printf("THERE IS NO SUCH VEHICLE ID ");
       delay(30);
       gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
         system("cls");
        if(press==1)
        {
            unload();
        }
        else{
            main();
        }
   }


}
void checkInvenLoad(char itmId[LENGTH]) //to check inputed item code is in inventory and check quantity is above 10 before loading
{
   FILE*ptrRead;
   struct goods add;
   ptrRead=fopen("currentInventory.dat","r");
   int testTwo=0,testThree=0,press;
   if(ptrRead==NULL)
   {
       gotoxy(40,15);printf("THERE IS NO FILE TO OPEN ");
       system("cls");
       main();
   }

   while(fscanf(ptrRead," %s %s %d %f ",add.itemCode,add.itemName,&add.quintity,&add.price)!=EOF)
   {
       int cmp1=strcmp(add.itemCode,itmId);
       if(cmp1==0)
       {
          testTwo=1;
          if(add.quintity>=10)//to check inventory quantity above 10 before loading
          {
              testThree=1;
          }
       }
   }
fclose(ptrRead);
   if(testTwo==0)//when inputed item code dose not match in inventory file item codes
   {
       gotoxy(40,20);printf("THERE IS NO SUCH A PRODUCT CODE ");
       delay(100);
       gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
        system("cls");
        if(press==1)
        {
            uploading();
        }
        else{
            main();
        }
   }
   if(testThree==0)//when inputed item code dose not enough quantity to load
   {
       gotoxy(40,20);printf("LOWER STOCK!!! CAN NOT BE COMPLETED EVENT!!!!");
       delay(300);
      gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
        system("cls");
        if(press==1)
        {
            uploading();
        }
        else{

            main();
        }
   }
   fclose(ptrRead);


}
void checkInventryUnload(char itmId[LENGTH])  //to check inputed item code is in inventory for unload function
{

    FILE*ptrRead;
   struct goods add;
   ptrRead=fopen("currentInventory.dat","r");
   int testTwo=0,press;
   if(ptrRead==NULL)
   {
       gotoxy(40,20);printf("THERE IS NO FILE TO OPEN ");
       main();
   }

   while(fscanf(ptrRead," %s %s %d %f ",add.itemCode,add.itemName,&add.quintity,&add.price)!=EOF)
   {
       int cmp1=strcmp(add.itemCode,itmId);
       if(cmp1==0) // check inputed item code same at inventory code
       {
          testTwo=1;

       }
   }
   fclose(ptrRead);

   if(testTwo==0)//when the item code dose not match
   {
       gotoxy(40,20);printf("THERE IS NO SUCH A PRODUCT CODE ");
       delay(100);
       gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
        system("cls");
        if(press==1)
        {
            unload();
        }
        else{
            main();
        }
   }


}
void checkDisto(char item[LENGTH]) // to check inputed item code is in disto for unload ,and to see if that is in an vehicle this time
{
    FILE*ptrView;
    struct goods geting;
    int chkTwo=0,chkThree=0,press;
    ptrView=fopen("disto.dat","r");
    if(ptrView==NULL)
    {
         gotoxy(40,15);printf("THERE IS NO FILE TO OPEN ");

         delay(300);
         foward();
    }

     while(fscanf(ptrView," %s %s %d %f %d %s ",geting.itemCode,geting.itemName,&geting.quintity,&geting.price,&geting.load,geting.loading.vehicle)!=EOF)
    {
        int cmp1=strcmp(geting.itemCode,item);
        if(cmp1==0)// when item code is in disto file
        {
            chkTwo=1;
            if(geting.load==10)//to check that product is in vehicle this time
            {
                chkThree=1;
            }
        }
    }
    fclose(ptrView);
    if(chkTwo==0)
    {
      gotoxy(40,20);printf("THE ITEMS HAVE NOT LOADED TO VEHICAL YET !!!! ");
      delay(300);
      gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
        if(press==1)
        {
            system("cls");
            unload();
        }
        else{
            system("cls");
            main();
        }
    }
    if(chkThree==0)//when it is loaded an vehicle
    {
         gotoxy(40,20);printf("ITEMS NOT LOADED FULL !!!! ");
         delay(100);
         gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
        if(press==1)
        {
            system("cls");
            unload();
        }
        else{
            system("cls");
            main();
        }

    }

}
void checkVehiclUnload(char item[LENGTH],char vehicle[LENGTH])//to check loaded vehicle and item that those same in the unloading
{
    FILE*ptrRead;
    ptrRead=fopen("disto.dat","r");//open distribution file(disto file) to read data
    struct goods geting;
    int chkFor=0,chkFive=0,press;

    while(fscanf(ptrRead," %s %s %d %f %d %s ",geting.itemCode,geting.itemName,&geting.quintity,&geting.price,&geting.load,geting.loading.vehicle)!=EOF)
    {
        int cmp4=strcmp(geting.loading.vehicle,vehicle);//check inputed vehicle are is the loaded file
        int cmp5=strcmp(geting.itemCode,item);//check inputed item code is in the loaded file;
        if(cmp5==0)
        {
         if(cmp4==0)
         {
             chkFor=1;
            if(geting.load>=10) //to check unloading quantity above the loaded quantity
            {
                chkFive=1;
            }
         }
        }
    }
    fclose(ptrRead);
    if(chkFor==0)
    {
        gotoxy(40,20);printf("THE VEHICLE HAS NOT BEEN LOADED YET !!");
        delay(300);
        gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
        if(press==1)
        {
            system("cls");
            unload();
        }
        else{
            system("cls");
            main();
        }


    }
    if(chkFive==0)
    {
       gotoxy(40,20);printf("THERE IS NO ENOGPH GOODS TO DELEVERY!!");
       delay(100);
       gotoxy(1,30);printf("PRESS (1) Renter OR PRESS Any Key to go MENU ");
        scanf("%d",&press);
        if(press==1)
        {
            system("cls");
            unload();
        }
        else{
            system("cls");
            main();
        }
    }

}
void unload()// unloading function from vehicle
{
    char vehicle[LENGTH],item[LENGTH];
    int noOfItem,loding=0,i=0,no=0;
     struct goods getin;
     struct goods add;
     struct goods dup;
     char idItem[LENGTH][LENGTH],idVehicle[LENGTH][LENGTH];
    FILE*ptrChkIntry,*ptrWriteDup,*ptrSells,*ptrDupStore,*ptrOpStore,*ptrDupIn,*ptrReadDup,*ptrSot,* ptrItSot,*ptrDisplay;
    head();
    gotoxy(53,4);printf("-UNLOADING-");

    ptrDisplay=fopen("display.dat","r");//to open file to display on display interface loaded status
    while(fscanf(ptrDisplay," %s %s ",idVehicle[no],idItem[no])!=EOF)
    {
       no++;
    }
    fclose(ptrDisplay);
    for(i=0;i<=no;i++)
    {
        gotoxy(73,15+i);printf("%s",idVehicle[i]);
        gotoxy(95,15+i);printf("%s",idItem[i]);

    }
 /*

                            ""    goto(x,y) function is using for print frame  and set alignment  which i want        "


 */
   gotoxy(80,9);printf("WAITING TO UNLOAD"); //to align this statment
   gotoxy(73,12);printf("VEHICLE ID");
   gotoxy(95,12);printf("ITEM ID");
   gotoxy(65,11);printf("%c",201);
   gotoxy(65,14);printf("%c",204);
   gotoxy(65,12);printf("%c",186);
   gotoxy(65,13);printf("%c",186);
   for(i=66;i<=86;i++)
   {
       gotoxy(i,11); printf("%c",205);
       gotoxy(87,11); printf("%c",203);
       gotoxy(87,12); printf("%c",186);
       gotoxy(87,13); printf("%c",186);
   }
    for(i=88;i<=109;i++)
   {
       gotoxy(i,11); printf("%c",205);
   }
   gotoxy(110,11);printf("%c",187);
   gotoxy(110,12);printf("%c",186);
   gotoxy(110,13);printf("%c",186);
   gotoxy(110,14);printf("%c",185);
    for(i=66;i<=86;i++)
   {
       gotoxy(87,14);printf("%c",206);
       gotoxy(i,14);printf("%c",205);
       gotoxy(i,no+16);printf("%c",205);
   }
   for(i=88;i<=109;i++)
   {
       gotoxy(i,14);printf("%c",205);
       gotoxy(i,no+16);printf("%c",205);
   }
   for(i=15;i<=no+15;i++)
   {
       gotoxy(65,i);printf("%c",186);
       gotoxy(65,no+16);printf("%c",200);
   }
    for(i=15;i<=no+15;i++)
    {
        gotoxy(87,i);printf("%c",186);
    }
   gotoxy(87,no+16);printf("%c",202);
   gotoxy(110,no+16);printf("%c",188);

    for(i=15;i<=no+15;i++)
   {
       gotoxy(110,i);printf("%c",186);
   }
    gotoxy(20,6);printf("Enter item code           : ");
    scanf("%s",item);
    checkInventryUnload(item); // to check item code is in inventory file
    checkDisto(item); // to check item code is in disto file

    gotoxy(20,8);printf("Enter vehicle ID          : ");
    scanf("%s",vehicle);
    vehiclCheckUnload(vehicle); // to check this vehicle id is in vehicle store file,passing 1 veriables
    checkVehiclUnload(item,vehicle);// to check this vehicle id ,item code both  are  in disto file,passing 2 veriables

    gotoxy(20,10);printf("How many unloading items  : ");
    int test1=scanf("%d",&noOfItem);
    if(noOfItem>10||noOfItem<0)
    {
        gotoxy(20,10);printf(" invalid    input   !!!        ");
        gotoxy(20,11);printf("Renter How many unloading items  : ");
        scanf("%d",&noOfItem);
    }
    if(test1!=1.0)
    {
        gotoxy(20,10);printf(" invalid    input   !!!        ");
        gotoxy(20,11);printf("Renter How many unloading items  : ");
        scanf("%d",&noOfItem);

    }
    displayPass(vehicle,item);// to check and write display file  as sorted list to see this item loaded which vehicle , passing 2 veriables

        ptrChkIntry=fopen("currentInventory.dat","r");
        ptrWriteDup=fopen("duplicate.dat","a+");

        while(fscanf(ptrChkIntry," %s %s %d %f ",add.itemCode,add.itemName,&add.quintity,&add.price)!=EOF)
        {
            fprintf(ptrWriteDup," %s %s %d %f ",add.itemCode,add.itemName,add.quintity,add.price); // write inventory details to another file further use
        }
        fclose(ptrChkIntry);
        fclose(ptrWriteDup);


                 ptrOpStore=fopen("disto.dat","r");// read disto file to do changes
                 ptrDupStore=fopen("duplicatestore.dat","w");// write file to read disto file doing changes
                 ptrSells=fopen("sells.dat","a+");// write selling details
                 ptrDupIn=fopen("duplicateinventory.dat","w");//write file to read inventory  file doing changes
                 ptrSot=fopen("sort.dat","a+");//write file to draw a graph using sort details
                 ptrItSot=fopen("sortitem.dat","a+");//write file to draw a graph using sort details


     while(fscanf(ptrOpStore," %s %s %d %f %d %s ",getin.itemCode,getin.itemName,&getin.quintity,&getin.price,&getin.load,getin.loading.vehicle)!=EOF)
      {
        int cmps=strcmp(getin.itemCode,item); // check inputed to unload item code are same at disto file item codes
        int cmps1=strcmp(getin.loading.vehicle,vehicle);// check inputed to unload vehicle id are same at disto file vehicle id
        if(getin.load==10)
        {

           if(cmps==0)
            {
              if(cmps1==0)
              {
                getin.sels=(10-noOfItem);//in unloading,item quantity is subcraction form inventory file and disto file
                getin.quintity=getin.quintity+noOfItem;//in unloading,item quantity is addition to inventory file
                getin.selling=getin.price*getin.sels;//calculate the income in selling

                 loding=0;

                fprintf(ptrSells," %s %s %s %d %f",getin.itemCode,getin.itemName,getin.loading.vehicle,getin.sels,getin.selling);
                fprintf(ptrDupStore,"%s %s %d %f %d %s ",getin.itemCode,getin.itemName,getin.quintity,getin.price,loding,getin.loading.vehicle);
                fprintf(ptrDupIn," %s %s %d %f ",getin.itemCode,getin.itemName,getin.quintity,getin.price);
                fprintf(ptrSot," %s %d ",getin.loading.vehicle,getin.sels);
                fprintf(ptrItSot," %s %d ",getin.itemCode,getin.sels);
                printf("\n\n\n\t\t\t\t SUCESSFULY UNLOADING !!!!!!");
              }
              else
              {
                fprintf(ptrDupStore,"%s %s %d %f %d %s ",getin.itemCode,getin.itemName,getin.quintity,getin.price,getin.load,getin.loading.vehicle);
                fprintf(ptrDupIn," %s %s %d %f ",getin.itemCode,getin.itemName,getin.quintity,getin.price);
              }

           }
          else
          {
             fprintf(ptrDupStore,"%s %s %d %f %d %s ",getin.itemCode,getin.itemName,getin.quintity,getin.price,getin.load,getin.loading.vehicle);
             fprintf(ptrDupIn," %s %s %d %f ",getin.itemCode,getin.itemName,getin.quintity,getin.price);
          }

       }
       else
        {
          fprintf(ptrDupStore,"%s %s %d %f %d %s ",getin.itemCode,getin.itemName,getin.quintity,getin.price,getin.load,getin.loading.vehicle);
          fprintf(ptrDupIn," %s %s %d %f ",getin.itemCode,getin.itemName,getin.quintity,getin.price);
        }

    }

    fclose(ptrOpStore);
    fclose(ptrDupStore);
    fclose(ptrSells);
    fclose(ptrDupIn);
    fclose(ptrSot);
    fclose(ptrItSot);


    remove("disto.dat");
    rename("duplicatestore.dat","disto.dat");
    remove("currentInventory.dat");
    rename("duplicateinventory.dat","currentInventory.dat");

        ptrReadDup=fopen("duplicate.dat","r");//open the i wrote for further using inventory file in this function
        ptrWriteDup=fopen("merege.dat","a+");//above this function write only to inventory file if those are unload ,but this , write changed details and non changed details to inventory file
        while(fscanf(ptrReadDup," %s %s %d %f ",dup.itemCode,dup.itemName,&dup.quintity,&dup.price)!=EOF)
        {
            int cmpd=strcmp(dup.itemCode,item);
            if(cmpd==0)
            {
                dup.quintity=dup.quintity+noOfItem;
                fprintf(ptrWriteDup,"%s %s %d %f ",dup.itemCode,dup.itemName,dup.quintity,dup.price);
            }
            else
                {
                fprintf(ptrWriteDup,"%s %s %d %f ",dup.itemCode,dup.itemName,dup.quintity,dup.price);
                }
        }
        fclose(ptrReadDup);
        fclose(ptrWriteDup);

        remove("currentInventory.dat");
        remove("duplicate.dat");
        rename("merege.dat","currentInventory.dat");
        arrengesort();//calling the function to sort vehicle
        arrngeItem();//calling the function to sort item


foward();//calling the function
}
void displayPass(char idVehicle[LENGTH],char idItem[LENGTH])
{
    FILE*ptrview,*ptrcpy;
    struct goods view;
    ptrview=fopen("display.dat","r");//opening file to read data
    ptrcpy=fopen("copy.dat","w");// write file for updating  display file when it remove and rename
    while(fscanf(ptrview," %s %s ",view.loading.vehicle,view.itemCode)!=EOF)
    {
        int cmp=strcmp(view.loading.vehicle,idVehicle);
        int cmps=strcmp(view.itemCode,idItem);
        if(cmp==0)
        {
            if(cmps==0)
            {

            }
            else
            {
              fprintf(ptrcpy," %s %s ",view.loading.vehicle,view.itemCode);
            }
        }
        else
        {
             fprintf(ptrcpy," %s %s ",view.loading.vehicle,view.itemCode);
        }
    }
    fclose(ptrview);
    fclose(ptrcpy);
    remove("display.dat");
    rename("copy.dat","display.dat");

}
void arrengesort()// this function for sorting vehicle and each total quantity
{

    FILE*ptrView,*ptrWrite;
    char vehiID[LENGTH][LENGTH],temp[LENGTH];
    int sels[LENGTH],tempIn=0;
    int i=0;
    ptrView=fopen("sort.dat","r");
    if(ptrView==NULL)
    {
        gotoxy(49,15);printf("THERE IS NO FILE SUCH THAT!!");
        delay(100);
        system("cls");
        main(); //calling to main function
    }


    while(fscanf(ptrView," %s %d ",vehiID[i],&sels[i])!=EOF) //getting all vehicle id and sells
    {
        ++i;
    }

    for(int j=0;j<i;j++)  //this nested for loop for getting same id and their quantities in oder
    {
        for(int k=j+1;k<i;k++)
        {
            if(strcmp(vehiID[j],vehiID[k])>0)//for compare  character by character
               {
                   strcpy(temp,vehiID[j]);
                   strcpy(vehiID[j],vehiID[k]);
                   strcpy(vehiID[k],temp);
                   tempIn=sels[j];
                   sels[j]=sels[k];
                   sels[k]=tempIn;
               }

        }

   }
 ptrWrite=fopen("sorted.dat","w");//open a new file to write sort details
 for(int j=0;j<i;j++)
 {
    if(sels[j]!=-1)//for using , do not get sels=-1 values into following
     {
         if(strcmp(vehiID[j],vehiID[j+1])==0)// this use for same ids quantity adding into one id number
         {
                strcpy(vehiID[j+1],"");
                sels[j]=sels[j]+sels[j+1];
                sels[j+1]=-1;
                fprintf(ptrWrite," %s %d ",vehiID[j],sels[j]);
        }
         else
         {

            if(sels[j]!=-1)
            {
              fprintf(ptrWrite," %s %d ",vehiID[j],sels[j]);
            }

        }

    }

 }
 fclose(ptrView);
 fclose(ptrWrite);
 remove("sort.dat");
 rename("sorted.dat","sort.dat");

}
void arrngeItem()
{



    FILE*ptrView,*ptrWrite;
    char itemiID[LENGTH][LENGTH],temp[LENGTH];
    int sels[LENGTH],tempIn=0;
    int i=0;
    ptrView=fopen("sortitem.dat","r");
    if(ptrView==NULL)
    {
        gotoxy(49,15);printf("THERE IS NO FILE SUCH THAT!!");
        delay(100);
        system("cls");
        main();
    }


    while(fscanf(ptrView," %s %d ",itemiID[i],&sels[i])!=EOF)//getting all item code and sells
    {
        ++i;
    }

    for(int j=0;j<i;j++)//this nested for loop for getting same item code and their quantities in oder
    {
        for(int k=j+1;k<i;k++)
        {
            if(strcmp(itemiID[j],itemiID[k])>0)//for compare  character by character
               {
                   strcpy(temp,itemiID[j]);
                   strcpy(itemiID[j],itemiID[k]);
                   strcpy(itemiID[k],temp);
                   tempIn=sels[j];
                   sels[j]=sels[k];
                   sels[k]=tempIn;
               }

        }

   }
 ptrWrite=fopen("sorted2.dat","w");//open a new file to write sort details
 for(int j=0;j<i;j++)
 {
    if(sels[j]!=-1)//for using , do not get sels=-1 values into following
     {
         if(strcmp(itemiID[j],itemiID[j+1])==0)
         {
                strcpy(itemiID[j+1],"");
                sels[j]=sels[j]+sels[j+1];
                sels[j+1]=-1;
                fprintf(ptrWrite," %s %d ",itemiID[j],sels[j]);
        }
         else
         {

            if(sels[j]!=-1)
            {
              fprintf(ptrWrite," %s %d ",itemiID[j],sels[j]);
            }

        }

    }

 }
 fclose(ptrView);
 fclose(ptrWrite);
 remove("sortitem.dat");
 rename("sorted2.dat","sortitem.dat");

}
void additem()//this function use for if i have already added product code ,can be increase item quantity using this fountion
{
    struct goods geting;
    FILE*ptr,*ptrCopy;
    char code[LENGTH];
    int value,chek=0;
    head();
    gotoxy(53,4);printf("-INCREASING ITEAM-");
    ptr =fopen("currentInventory.dat","r");
    if(ptr==NULL)//for checking this file are already created
    {
        gotoxy(40,15);printf("CAN NOT OPEN THE FILE !!!!!");
        system("cls");
        main();
    }

    gotoxy(32,6);printf("Enter item code       : ");
    scanf("%s",code);
    gotoxy(32,11);printf("Enter item quintity  : ");
    scanf("%d",&value);
    if(value<0)
    {
        gotoxy(32,11);printf("please enter valid inputs  ");
        gotoxy(32,12);printf("renter the value: ");
        scanf("%d",&value);
    }


    ptrCopy =fopen("dupli.dat","w");

    while(fscanf(ptr," %s %s %d %f ",geting.itemCode,geting.itemName,&geting.quintity,&geting.price)!=EOF)
    {
        if(strcmp(geting.itemCode,code)==0)//check inputed item code are same inventory files ids
        {
            chek=1;
            gotoxy(32,16);printf("Item name is        : %s ",geting.itemName);
            geting.quintity+=value;
            gotoxy(32,21);printf("Now Avilible items  : %d ",geting.quintity);
            fprintf(ptrCopy," %s %s %d %f ",geting.itemCode,geting.itemName,geting.quintity,geting.price);
        }
        else
        {
           fprintf(ptrCopy," %s %s %d %f ",geting.itemCode,geting.itemName,geting.quintity,geting.price);
        }
    }
    fclose(ptr);
    fclose(ptrCopy);
    remove("currentInventory.dat");
    rename("dupli.dat","currentInventory.dat");

    if(chek==0)
    {
      gotoxy(40,18);printf("THERE IS NO THAT PRODUCT CODE !!");//this gotoxy it doing this statment  align by x axis 40 , and top to bottom y axis 18
    }

    foward();//calling to function

}
void disVehicle()//this function use for adding vehicle to vehicle store file
{
    struct goods dis;
    struct goods chk;
    FILE*fDistribute,*ptrCheck;
    int tst=0;
    head();
    gotoxy(53,4);printf("-VEHICLE STORE-");
    gotoxy(32,6);printf("Enter vehicle number : ");
    scanf("%s",dis.loading.vehicle);
    ptrCheck=fopen("vehiclestore.dat","r");
    while(fscanf(ptrCheck,"%s %s %s %d ",chk.loading.vehicle,chk.loading.name,chk.loading.id,&chk.loading.telNo)!=EOF)//for check adding vehicle is already in vehicle store file
    {
        int cmp=strcmp(chk.loading.vehicle,dis.loading.vehicle);
        if(cmp==0)
        {
            tst=1;
        }

    }
    fclose(ptrCheck);
    if(tst==1)
    {
        gotoxy(40,15);printf("THE VEHICLE NUMBER IS ALREADY IN SYSTEM !!!");
        delay(50);
        foward();
    }


    gotoxy(32,11);printf("Enter seller name     : ");
    scanf("%s",dis.loading.name);
    fflush(stdin);

    gotoxy(32,15);printf("Enter seller NIC No   : ");
    scanf("%s",dis.loading.id);

    gotoxy(32,19);printf("Enter seller Tel.NO   : ");
    int test=scanf("%d",&dis.loading.telNo);
    if(test!=1.0)//if check quantity input user entered as charactor key of keyboard, give another enter it
    {
        gotoxy(32,19);printf("PLEASE ENTER THE VALID INPUTS !!!");
        gotoxy(32,20);printf("please renter : ");
        fflush(stdin);
        scanf("%d",&dis.loading.telNo);//get extra input that telno
    }


    fDistribute = fopen("vehiclestore.dat","a+");
    fprintf(fDistribute," %s %s %s %d ",dis.loading.vehicle,dis.loading.name,dis.loading.id,dis.loading.telNo);

    fclose(fDistribute);
     gotoxy(43,23);printf("ADDED SUSCESSFULLY!!!");
    foward();

}

void last()// this function use for in exiting this progaram after display
{
    system("cls");
    head();

    gotoxy(50,15);printf("THANK YOU FOR USING");
    gotoxy(50,17);printf("HAVE A GOOD DAY");
    delay(150);

}
void head() // this function use for print outlines (out ling prame)
{
  int i;
   gotoxy(4,1);printf("%c",201);//1st t
   for(i=5;i<=115;i++)
   {
       gotoxy(i,1); printf("%c",205);
       gotoxy(115,1);printf("%c",187);
   }
   gotoxy(4,2);printf("%c",186);
   gotoxy(53,2);printf("XYZ DISTRIBUTORS");
   gotoxy(4,3);printf("%c",186);
   gotoxy(115,2);printf("%c",186);
   gotoxy(115,3);printf("%c",186);
   gotoxy(4,4);printf("%c",204);
   gotoxy(115,4);printf("%c",185);
   for(i=5;i<=114;i++)
   {
       gotoxy(i,4);printf("%c",205);
   }
   for(i=5;i<=29;i++)
   {
       gotoxy(4,i);printf("%c",186);
   }
   gotoxy(4,29);printf("%c",200);
   for(i=5;i<=114;i++)
   {
       gotoxy(i,29);printf("%c",205);
   }
   gotoxy(115,29);printf("%c",188);
    for(i=5;i<=28;i++)
   {
       gotoxy(115,i);printf("%c",186);
   }

}
void welcome()
{
   head();//calling to function
   int i;
   char pass[LENGTH],chart;
   gotoxy(53,4);printf("-WELCOME-");
   gotoxy(47,10);printf("INPUT SYSTEM PASSWORD");
   gotoxy(55,13);

    while(1) //this is use for the hide input system password
    {
        chart=getch();
        if(chart==ENTER)
        {
            pass[i]='\0';
            break;
        }
        else if(chart==BKSP)// when press the backspace key,you are able to clear a character
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if(chart==SPACE)
        {
            continue;
        }
        else
        {
            pass[i]=chart;
            i++;
            printf("*");
        }
    }
     user(pass);
    system("cls");//clear to console


}
void user(char password[LENGTH])// this function use for check system password is correct
{
   char pass[20]="usjp";// this is the system password
   if(strcmp(pass,password)==0)
   {
       Beep(800,800);//this function is use for the generate a beep sound
       Beep(700,800);//this function is use for the generate a beep sound
       gotoxy(49,20);printf("VALID PASSWORD!!!");

       delay(1000);//this function use for delay turn next step


   }
   else
    {
         gotoxy(47,25);printf("INVALID PASSWORD!!!");
         gotoxy(47,26);printf("PLEASE RENTER!!");
         delay(200);
         system("cls");//to clear console display
         main();//calling to function

    }

}
void menu()//this function use for use print main window
{
   head();
   gotoxy(53,4);printf("-MAIN MENU-");

  gotoxy(35,6);printf("[1].ADD NEW PROUDCT TO STORE ");
  gotoxy(35,8);printf("[2].MANAGE VEHICLE               ");
  gotoxy(35,10);printf("[3].ADD ITEMS TO PRODUCT         ");
  gotoxy(35,12);printf("[4].UPLOADING ITEMS TO VEHICLE   ");
  gotoxy(35,14);printf("[5].UNLOADING FROM VEHICLE       ");
  gotoxy(35,16);printf("[6].VIEW REPORTS                 ");
  gotoxy(35,18);printf("[7].MANAGE CHANGES               ");
  gotoxy(35,20);printf("[8].SEARCH SELLS MEN DETAILS               ");
  gotoxy(35,22);printf("[9].EXIT                         ");


}
int main()
{
int choice;

do{
    if(count1==0)//this is use for ,if count is 0,calling welcome function(you should enter system password)
    {
     welcome();
    }

    menu();//calling to function
    gotoxy(32,24);printf(" Enter Your Choice as number : ");
    int test=scanf("%d",&choice);
    if(test!=1)//this is use for checking inputed is int or character
    {
       ++count1;
       gotoxy(32,24);printf(" Renter Your Choice as number : ");//if character,we give to another enter
       fflush(stdin);
       scanf("%d",&choice);
    }

    system("cls");

  switch(choice)
  {
        case 1:
        {
          ++count1 ;//counting
          addproduct();//calling to function
          break;
        }
        case 2:
        {
            ++count1 ;//counting
        vehiManage();//calling to function
          break;
        }
        case 3:
        {
            ++count1 ;//counting
          additem();//calling to function
          break;
        }
        case 4:
        {
            ++count1 ;//counting
          uploading();//calling to function
          break;
        }
        case 5:
        {
            ++count1 ;//counting
          unload();//calling to function
          break;
        }
        case 6:
        {
            ++count1 ;
          report();//calling to function
          break;
        }
         case 7:
        {
            ++count1 ;//counting
          changes();//calling to function
          break;
        }
          case 8:
        {
            ++count1 ;//counting
          serch();
          break;
        }
   }
 }while(choice!=9);
 {
    last();
    exit(1);//exit to function
 }
return 0;
}
void stroeView()
{

    int num;
    FILE*ptrView;
    int i,j=0,qty[LENGTH];
    char name[LENGTH][LENGTH],id[LENGTH][LENGTH];
    float sum[LENGTH];
    ptrView =fopen("currentInventory.dat","r");//open the file
    while(fscanf(ptrView," %s %s %d %f ",id[j],name[j],&qty[j],&sum[j])!=EOF)//for read the inventory file to display inventory details
    {
     ++j;
    }
    fclose(ptrView);
    for(i=0;i<j;i++)//to print the details to report
    {
      gotoxy(6,i+5);printf("%s",id[i]);//to print the details to report
      gotoxy(30,i+5);printf("%s",name[i]);//to print the details to report
      gotoxy(58,i+5);printf("%d",qty[i]);//to print the details to report
      gotoxy(93,i+5);printf("Rs.%.1f",sum[i]);//to print the details to report
    }

   gotoxy(4,1);printf("%c",201);
   for(i=5;i<=28;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(28,1);printf("%c",203);//set the outlines using extended ascii code
       gotoxy(28,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(28,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(56,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(90,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(28,2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(28,3);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=29;i<=56;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(56,1);printf("%c",203);//set the outlines using extended ascii code
       gotoxy(56,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(56,2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(56,3);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=57;i<=90;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(90,1);printf("%c",203);//set the outlines using extended ascii code
       gotoxy(90,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(90,2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(90,3);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=91;i<=115;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(115,1);printf("%c",187);//set the outlines using extended ascii code
   }
   gotoxy(4,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(12,2);printf("ITEM CODE");//print this statment and it align with gotoxy function
   gotoxy(39,2);printf("ITEM NAME");//print this statment and it align with gotoxy function
   gotoxy(66,2);printf("STOCK QUANTITI");//print this statment and it align with gotoxy function
   gotoxy(97,2);printf("UNIT PRICE");//print this statment and it align with gotoxy function
   gotoxy(4,3);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(115,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(115,3);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(4,4);printf("%c",204);//set the outlines using extended ascii code
   gotoxy(115,4);printf("%c",185);//set the outlines using extended ascii code
   for(i=5;i<=27;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=29;i<=55;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=57;i<=89;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
   }
    for(i=91;i<=114;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=5;i<=28;i++)
   {
       gotoxy(4,i);printf("%c",186);//set the outlines using extended ascii code
   }
    for(i=5;i<=28;i++)
   {
       gotoxy(115,i);printf("%c",186);//set the outlines using extended ascii code
   }
    gotoxy(1,29);printf("Press '1'go to see other report or press any key go to main :");
    scanf("%d",&num);
    if(num==1)
    {
        system("cls");
        report();//calling to function
    }
    else
    {
        system("cls");
        main();//call to function
    }
}
void sellsView()//this function to the display sells report
{
    int num;
    head();
    gotoxy(53,4);printf("-SELLS REPORT-");
    FILE*ptrView;
    int i,j=0,qty[LENGTH],sum=0;
    float income[LENGTH],sumin=0;
    char name[LENGTH][LENGTH],id[LENGTH][LENGTH],vehicle[LENGTH][LENGTH];
    ptrView=fopen("sells.dat","r");
    while(fscanf(ptrView," %s %s %s %d %f ",id[j],name[j],vehicle[j],&qty[j],&income[j])!=EOF)//read data from sells file details
    {
        ++j;
    }
    fclose(ptrView);
    for(int t=0;t<j;t++)
    {
       sum=sum+qty[t];//for the calculate total sells quantity
       sumin=sumin+income[t];//for the calculate total sells income
    }
    for(i=0;i<j;i++)
   {
       gotoxy(5,i+5);printf("%s",id[i]);//set the outlines using extended ascii code
       gotoxy(27,i+5);printf("%s",name[i]);//set the outlines using extended ascii code
       gotoxy(52,i+5);printf("%s",vehicle[i]);//set the outlines using extended ascii code
       gotoxy(76,i+5);printf("%d",qty[i]);//set the outlines using extended ascii code
       gotoxy(94,i+5);printf("Rs.%.1f",income[i]);//set the outlines using extended ascii code

   }

   gotoxy(72,28);printf("%d",sum);//for the display total sells quantity
   gotoxy(94,28);printf("Rs.%.1f",sumin);//for the display total sells income

 gotoxy(4,1);printf("%c",201);//set the outlines using extended ascii code
   for(i=5;i<=25;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(22,1);printf("%c",203);//set the outlines using extended ascii code
       gotoxy(22,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(22,2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(22,3);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=26;i<=46;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(46,1);printf("%c",203);//set the outlines using extended ascii code
       gotoxy(46,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(46,2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(46,3);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=47;i<=70;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(70,1);printf("%c",203);//set the outlines using extended ascii code
       gotoxy(70,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(70,2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(70,3);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=71;i<=91;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(92,1); printf("%c",203);//set the outlines using extended ascii code
       gotoxy(92,2); printf("%c",186);//set the outlines using extended ascii code
       gotoxy(92,3); printf("%c",186);//set the outlines using extended ascii code
   }
    for(i=93;i<=114;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
   }
   gotoxy(115,1);printf("%c",187);//set the outlines using extended ascii code
   gotoxy(4,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(4,3);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(8,2);printf("ITEM CODE");
   gotoxy(29,2);printf("ITEM NAME");
   gotoxy(52,2);printf("VEHICAL ID");
   gotoxy(77,2);printf("SELLS");
   gotoxy(98,2);printf("INCOME");
   gotoxy(115,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(115,3);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(4,4);printf("%c",204);//set the outlines using extended ascii code
   gotoxy(115,4);printf("%c",185);//set the outlines using extended ascii code
   for(i=5;i<=21;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,27);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=23;i<=45;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,27);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=47;i<=69;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,27);printf("%c",205);//set the outlines using extended ascii code
   }
    for(i=71;i<=91;i++)
   {
       gotoxy(92,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,27);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,29);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=93;i<=114;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,27);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,29);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=5;i<=28;i++)
   {
       gotoxy(22,i-2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(46,i-2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(70,29);printf("%c",200);//set the outlines using extended ascii code
       gotoxy(92,29);printf("%c",202);//set the outlines using extended ascii code
       gotoxy(115,29);printf("%c",188);//set the outlines using extended ascii code
       gotoxy(70,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(92,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(4,i-2);printf("%c",186);//set the outlines using extended ascii code
   }
   gotoxy(4,27);printf("%c",200);//set the outlines using extended ascii code
   gotoxy(46,27);printf("%c",202);//set the outlines using extended ascii code
   gotoxy(22,27);printf("%c",202);//set the outlines using extended ascii code
   gotoxy(70,27);printf("%c",206);//set the outlines using extended ascii code
   gotoxy(92,27);printf("%c",206);//set the outlines using extended ascii code
   gotoxy(115,27);printf("%c",185);//set the outlines using extended ascii code

    for(i=5;i<=28;i++)
   {
       gotoxy(115,i);printf("%c",186);//set the outlines using extended ascii code
   }
     gotoxy(1,29);printf("Press '1'go to see other report or press any key go to main :");
    scanf("%d",&num);
    if(num==1)
    {
        system("cls");
        report();//calling to function
    }
    else
    {
        system("cls");
        main();//calling to function
    }
}
void loadView()
{
    FILE*ptrView;
    int i,j=0,qty[LENGTH],load[LENGTH],num;
    char name[LENGTH][LENGTH],id[LENGTH][LENGTH],vehi[LENGTH][LENGTH];
    float sum[LENGTH];
    ptrView=fopen("disto.dat","r");
    while(fscanf(ptrView," %s %s %d %f %d %s ",id[j],name[j],&qty[j],&sum[j],&load[j],vehi[j])!=EOF)//read data from disto file
    {
        ++j;
    }
    fclose(ptrView);

   gotoxy(4,1);printf("%c",201);//set the outlines using extended ascii code
   for(i=5;i<=25;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(22,1);printf("%c",203);//set the outlines using extended ascii code
       gotoxy(22,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(22,2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(22,3);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=26;i<=46;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(46,1);printf("%c",203);//set the outlines using extended ascii code
       gotoxy(46,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(46,2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(46,3);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=47;i<=70;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(70,1);printf("%c",203);//set the outlines using extended ascii code
       gotoxy(70,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(70,2);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(70,3);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=71;i<=91;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(92,1); printf("%c",203);//set the outlines using extended ascii code
       gotoxy(92,2); printf("%c",186);//set the outlines using extended ascii code
       gotoxy(92,3); printf("%c",186);//set the outlines using extended ascii code
   }
    for(i=93;i<=114;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
   }
   gotoxy(115,1);printf("%c",187);//set the outlines using extended ascii code
   gotoxy(4,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(4,3);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(8,2);printf("ITEM CODE");
   gotoxy(29,2);printf("ITEM NAME");
   gotoxy(50,2);printf("STORE QUANITY");
   gotoxy(71,2);printf("AVILABLE VEHICLE LOAD");
   gotoxy(96,2);printf("VEHICLE ID");
   gotoxy(115,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(115,3);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(4,4);printf("%c",204);//set the outlines using extended ascii code
   gotoxy(115,4);printf("%c",185);//set the outlines using extended ascii code
   for(i=0;i<j;i++)
   {
       gotoxy(5,i+5);printf("%s",id[i]);//set the outlines using extended ascii code
       gotoxy(27,i+5);printf("%s",name[i]);//set the outlines using extended ascii code
       gotoxy(52,i+5);printf("%d",qty[i]);//set the outlines using extended ascii code
       gotoxy(76,i+5);printf("%d",load[i]);//set the outlines using extended ascii code
       gotoxy(94,i+5);printf("%s",vehi[i]);//set the outlines using extended ascii code

   }
   for(i=5;i<=21;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=23;i<=45;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=47;i<=69;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
   }
    for(i=71;i<=91;i++)
   {
       gotoxy(92,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=93;i<=114;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=5;i<=28;i++)
   {
       gotoxy(22,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(46,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(70,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(92,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(4,i);printf("%c",186);//set the outlines using extended ascii code
   }
    for(i=5;i<=28;i++)
   {
       gotoxy(115,i);printf("%c",186);//set the outlines using extended ascii code
   }
   gotoxy(1,29);printf("Press '1'go to see other report or press any key go to main :");
    scanf("%d",&num);
    if(num==1)
    {
        system("cls");
        report();//calling to function
    }
    else
    {
        system("cls");
        main();//calling to function
    }

}
void vehiview()//this function to display vehicle store report
{
    int num,i=0,j=0,u;
    FILE*ptrView;
    struct goods getin;
    char name[LENGTH][LENGTH],vehi[LENGTH][LENGTH];
    ptrView=fopen("vehiclestore.dat","r");
    while(fscanf(ptrView," %s %s %s %d ",vehi[j],name[j],getin.loading.id,&getin.loading.telNo)!=EOF)
    {
      ++j;
    }
   fclose(ptrView);

    for(u=0;u<j;u++)
   {
       gotoxy(44,u+5);printf("%s",vehi[u]);//to print vehicle name one by one
       gotoxy(63,u+5);printf("%s",name[u]);//to print seller name one by one
   }

   gotoxy(45,2);printf("VEHICLE ID");
   gotoxy(65,2);printf("SELLER NAME");
   gotoxy(40,1);printf("%c",201);//set the outlines using extended ascii code
   gotoxy(40,4);printf("%c",204);//set the outlines using extended ascii code
   gotoxy(40,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(40,3);printf("%c",186);//set the outlines using extended ascii code
   for(i=41;i<=61;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(62,1); printf("%c",203);//set the outlines using extended ascii code
       gotoxy(62,2); printf("%c",186);//set the outlines using extended ascii code
       gotoxy(62,3); printf("%c",186);//set the outlines using extended ascii code
   }
    for(i=63;i<=84;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
   }
   gotoxy(85,1);printf("%c",187);//set the outlines using extended ascii code
   gotoxy(85,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(85,3);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(85,4);printf("%c",185);//set the outlines using extended ascii code
    for(i=41;i<=61;i++)
   {
       gotoxy(62,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,27);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=63;i<=84;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,27);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=5;i<=26;i++)
   {
       gotoxy(40,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(40,27);printf("%c",200);//set the outlines using extended ascii code
   }
    for(i=5;i<=26;i++)
    {
        gotoxy(62,i);printf("%c",186);//set the outlines using extended ascii code
    }
   gotoxy(62,27);printf("%c",202);//set the outlines using extended ascii code
   gotoxy(85,27);printf("%c",188);//set the outlines using extended ascii code

    for(i=5;i<=26;i++)
   {
       gotoxy(85,i);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=3;i<=27;i++)
   {
       gotoxy(10,i);printf("%c%c%c%c%c%c",177,177,177,177,177,177);// to print a bar
       gotoxy(105,i);printf("%c%c%c%c%c%c",177,177,177,177,177,177);// to print a bar
   }

    gotoxy(1,29);printf("Press '1'go to see other report or press any key go to main :");
    scanf("%d",&num);
    if(num==1)
    {
        system("cls");
        report();
    }
    else
    {
        system("cls");
        main();
    }

}
void deleVhicle()//this function to remove a vehicle from vehicle store file
{
    struct goods dele;
    struct goods remov;
    char delet[LENGTH];
    FILE*ptrDele,*ptrAdd;
    int test=0;
    head();
    gotoxy(53,4);printf("-REMOVE VEHICLE-");
    gotoxy(35,8);printf("Enter Vehicle ID to Remove : ");
    scanf("%s",delet);
    ptrDele=fopen("vehiclestore.dat","r+");

    while(fscanf(ptrDele," %s %s %s %d ",dele.loading.vehicle,dele.loading.name,dele.loading.id,&dele.loading.telNo)!=EOF)// for check inputed vehicle id is in vehicle store file
    {
     if(strcmp(dele.loading.vehicle,delet)==0)
     {
       test=1;
     }
    }
    fclose(ptrDele);
    if(test==0)//when the vehicle id is not vehicle store file
    {
        gotoxy(40,20);printf("this vehicle has not in vehicle store file !!!");
        foward();
    }

    ptrDele=fopen("vehiclestore.dat","r+");
    ptrAdd=fopen("Duplicate.dat","a+");

    while(fscanf(ptrDele," %s %s %s %d ",remov.loading.vehicle,remov.loading.name,remov.loading.id,&remov.loading.telNo)!=EOF)
    {
     if(strcmp(remov.loading.vehicle,delet)!=0)
     {
          fprintf(ptrAdd," %s %s %s %d ",remov.loading.vehicle,remov.loading.name,remov.loading.id,remov.loading.telNo);
        gotoxy(40,20);printf("THE VEHICLE HAS BEEN REMOVED SUCESSFULLY!!!");

     }
   }
    fclose(ptrDele);
    fclose(ptrAdd);

    remove("vehiclestore.dat");

    rename("Duplicate.dat","vehiclestore.dat");
    foward();
}
void report()//this function for display reports menu
{
    int num;
    head();
    gotoxy(53,4);printf("-REPORTS-");
    gotoxy(35,6);printf("[1]. View store report ");
    gotoxy(35,8);printf("[2]. View loaded report ");
    gotoxy(35,10);printf("[3]. View sells report ");
    gotoxy(35,12);printf("[4]. View vehicle store report ");
    gotoxy(35,14);printf("[5]. View sot selling report ");
    gotoxy(35,16);printf("[6]. View vehical sells Chart report ");
    gotoxy(35,18);printf("[7]. View product sells Chart report ");
    gotoxy(35,20);printf("[8]. Back ");
    gotoxy(32,24);printf("Enter your choice as number : ");
    int test=scanf("%d",&num);
    if(test!=1)
    {
       gotoxy(32,24);printf("Renter your choice as number : ");
       fflush(stdin);
       scanf("%d",&num);

    }
    system("cls");
    switch (num)
    {
    case 1:
        {
         stroeView();//calling to funtion
         break;
        }
    case 2:
        {
          loadView();//calling to function
           break;
        }
    case 3:
        {
            sellsView();//calling to function
             break;
        }
    case 4:
        {
          vehiview();//calling to function
           break;
        }
    case 5:
        {
          sotView();//calling to function
           break;
        }
    case 6:
        {
          displyChart();//calling to function
           break;
        }
   case 7:
        {
          displyChartitem();//calling to function
           break;
        }
  case 8:
        {
          main();//calling to function
           break;
        }
 default:
        {

        gotoxy(48,20);printf("INPUT IS UNAVILABLE !!!!");
        delay(100);
        system("cls");
        break;
        }
    }
}
void vehiManage()//this function use to display manage vehicle menu
{

    int num;
    head();
    gotoxy(53,4);printf("-MANAGE VEHICLE-");
    gotoxy(32,6);printf("[1]. Add vehicle to store ");
    gotoxy(32,9);printf("[2]. Remove vehicle");
    gotoxy(32,12);printf("[3]. Back");
    gotoxy(32,14);printf("Enter your choice as number : ");
    scanf("%d",&num);
    system("cls");
    switch (num)
    {
    case 1:
        {
         disVehicle();//calling to funtion
         break;
        }
    case 2:
        {
          deleVhicle();//calling to function
           break;
        }
    case 3:
        {
          main();//calling to man function
           break;
        }
         default :
            {
                gotoxy(49,18);printf("INPUT IS UNAVILABLE !!!!");
                break;
            }
    }
}
void delay(int i)//this function use for delay the next step to run
{
    int j=0;
    for(j=0;j<i;i++)
    {
    }
}
void foward()//this function use to ask end functions they want to do another task
{
   int press;
   gotoxy(1,30);printf("PRESS (1) to go MENU ");
  int test= scanf("%d",&press);
   if(test!=1)//this is use for checking inputed is int or character
    {
       ++count1;
       gotoxy(1,30);printf(" Renter PRESS (1) to go MENU : ");//if character,we give to another enter
       fflush(stdin);
       scanf("%d",&press);
    }
   if(press==1)
   {
       system("cls");
       system("color F");//tis function use  change color
       main();
   }
   else{
        system("cls");
        system("color F");
    foward();
   }

}
void sotView()//this function use to display sorted seller  progress
{


    int num,i=0,j=0,qty[LENGTH],sum=0,k=0,u=0;
    char name[LENGTH][LENGTH];
    FILE*ptrV;
    ptrV=fopen("sort.dat","r");
    if(ptrV==NULL)
    {
        gotoxy(48,20);printf("THREIS NO FILE!!");
        delay(100);
        system("cls");
        main();
    }
    while(fscanf(ptrV," %s %d ",name[j],&qty[j])!=EOF)
    {
      ++j;
    }
   fclose(ptrV);

   for(k=0;k<j;k++)
   {
       sum=sum+qty[k];// calculate total sells quantity for each vehicle
   }
   for(u=0;u<j;u++)
   {
       gotoxy(44,5+u);printf("%s",name[u]);//to print line by line vehicle id
       gotoxy(63,5+u);printf("%d",qty[u]);//to print line by line sells quantity
   }
   gotoxy(65,28);printf("%d",sum);

   gotoxy(45,2);printf("VEHICLE ID");
   gotoxy(65,2);printf("TOTAL QUANTITY");
   gotoxy(45,28);printf("TOTAL SELS->");
   gotoxy(40,1);printf("%c",201);//set the outlines using extended ascii code
   gotoxy(40,4);printf("%c",204);//set the outlines using extended ascii code
   gotoxy(40,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(40,3);printf("%c",186);//set the outlines using extended ascii code
   for(i=41;i<=61;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
       gotoxy(62,1); printf("%c",203);//set the outlines using extended ascii code
       gotoxy(62,2); printf("%c",186);//set the outlines using extended ascii code
       gotoxy(62,3); printf("%c",186);//set the outlines using extended ascii code
   }
    for(i=63;i<=84;i++)
   {
       gotoxy(i,1); printf("%c",205);//set the outlines using extended ascii code
   }
   gotoxy(85,1);printf("%c",187);//set the outlines using extended ascii code
   gotoxy(85,2);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(85,3);printf("%c",186);//set the outlines using extended ascii code
   gotoxy(85,4);printf("%c",185);//set the outlines using extended ascii code
    for(i=41;i<=61;i++)
   {
       gotoxy(62,4);printf("%c",206);//set the outlines using extended ascii code
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,27);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=63;i<=84;i++)
   {
       gotoxy(i,4);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,27);printf("%c",205);//set the outlines using extended ascii code
       gotoxy(i,29);printf("%c",205);//set the outlines using extended ascii code
   }
   for(i=5;i<=26;i++)
   {
       gotoxy(62,29);printf("%c",200);//set the outlines using extended ascii code
       gotoxy(85,29);printf("%c",188);//set the outlines using extended ascii code
       gotoxy(40,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(40,27);printf("%c",200);//set the outlines using extended ascii code
       gotoxy(40,85);printf("%c",200);//set the outlines using extended ascii code

   }
    for(i=5;i<=28;i++)
    {
        gotoxy(62,i);printf("%c",186);//set the outlines using extended ascii code
    }
   gotoxy(62,27);printf("%c",206);//set the outlines using extended ascii code
   gotoxy(85,27);printf("%c",185);//set the outlines using extended ascii code

    for(i=5;i<=26;i++)
   {
       gotoxy(85,i);printf("%c",186);//set the outlines using extended ascii code
       gotoxy(85,28);printf("%c",186);//set the outlines using extended ascii code
   }
   for(i=3;i<=27;i++)
   {
       gotoxy(10,i);printf("%c%c%c%c%c%c",177,177,177,177,177,177);
       gotoxy(105,i);printf("%c%c%c%c%c%c",177,177,177,177,177,177);
   }

gotoxy(1,29);printf("Press '1'go to see other report or press any key go to main :");
    scanf("%d",&num);
    if(num==1)
    {
        system("cls");
        report();
    }
    else
    {
        system("cls");
        main();
    }
}
void gotoxy(int x, int y) //this function use to control cursor position which i want by  accessing x axis and y axis
{
    COORD chart;
    chart.X=x;// to access x axis
    chart.Y=y;//to access y axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),chart);
}
void displyChart()// this function to display bar chart about progress of vehicles
{
    head();// calling to function
    gotoxy(52,4);printf("-PROGRESS OF VEHICLES-");
    system("color C");// to change color to red
    FILE*ptrView;
    char name[LENGTH][LENGTH];
    int qty[LENGTH],qty2[LENGTH],n=0,w=0,xassis=25;
    ptrView=fopen("sort.dat","r");
     while(fscanf(ptrView," %s %d ",name[w],&qty[w])!=EOF)// to get data from sort file
    {
      ++w;// count getting data
    }

    fclose(ptrView);
    for(n=0;w>n;n++)
    {

        qty2[n]=qty[n]/4; //  to convert a scale total quantity of each vehicle

           for(int k=25;k>(25-qty2[n]);k--)  // i put 25-qty[], because bar chart should start bottom to top  at same stage
           {
               gotoxy(xassis,k);// to put bar to bar same space
               printf("%c%c%c%c%c%c%c",178,178,178,178,178,178,178);//print bar
               for(int m=10;m<24;m++)
               {
                   gotoxy(m,(25-qty2[n]));//to print  stat
                   printf("%c",196);

               }
               gotoxy(10,(25-qty2[n]));
               printf("%d",qty[n]);
               gotoxy(10,26);
               printf("VEHICLE ID----->");
               gotoxy(xassis,26);
               printf("   %s",name[n]);// to print id of each vehicle
           }
           xassis+=10;
    }

    foward();// calling to function


}
void displyChartitem()// this function to display bar chart about progress of items
{
    head();// calling to  function
    gotoxy(52,4);printf("-PROGRESS OF ITEMS-");
     system("color C");// to change color to red
    FILE*ptrView;
    char name[LENGTH][LENGTH];
    int qty[LENGTH],qty2[LENGTH];
    int i=0,xassis=25;
    ptrView=fopen("sortitem.dat","r");
     while(fscanf(ptrView," %s %d ",name[i],&qty[i])!=EOF)// to get data from sortitem file
    {
      ++i;
    }

    fclose(ptrView);
    for(int n=0;i>n;n++)
    {


        qty2[n]=qty[n]/2;//  to convert a scale total quantity of each item

           for(int k=25;k>(25-qty2[n]);k--) // i put 25-qty[], because bar chart should start bottom to top  at same stage
           {
               gotoxy(xassis,k);
               printf("%c%c%c%c%c%c%c",178,178,178,178,178,178,178);//print bar
               for(int m=10;m<25;m++)
               {
                   gotoxy(m,(25-qty2[n]));
                   printf("%c",196);

               }
               gotoxy(5,(25-qty2[n]));
               printf("%d",qty[n]);
               gotoxy(5,26);
               printf("PRODUCT ID----->");
               gotoxy(xassis,26);
               printf("   %s",name[n]);// to print id of each item
           }
           xassis+=10;
    }

    foward();//calling to function

}
void changes()//this function for changing menu to selected changes wanted
{
    int num;
    head(); //calling to function
    gotoxy(53,4);printf("-CHANGE PROPERTIES-");
    gotoxy(32,6);printf("[1]. CHANGE ITEM PRICE ");;
    gotoxy(32,8);printf("[2]. CHANGE ITEM QUANTITY");
    gotoxy(32,10);printf("[3]. CHANGE ITEM CODE");
    gotoxy(32,12);printf("[4]. Back");

    gotoxy(32,14);printf("Enter your choice as number : ");
    scanf("%d",&num);
    system("cls");
    switch (num)
    {
    case 1:
        {
         changeIPrice();//calling to function
         break;
        }
    case 2:
        {
         changeQty();//calling to function
           break;
        }
   case 3:
        {
        changeCode();//calling to function
           break;
        }
  case 4:
        {
          main();//calling to function
           break;
        }
  default :
        {
            gotoxy(40,18);printf("INPUT IS UNAVILABLE !!!!");
            break;
        }
    }

}
void changeIPrice()// this function use for changing price at a product and change quantity from only inventory file
{
   head();// calling to function
   gotoxy(53,4);printf("-CHANGE PRICE-");
   char item[LENGTH];
   FILE*ptrOpen,*ptrNew;
   struct goods copy;
   float price=0;
   int test=0;
   ptrOpen=fopen("currentInventory.dat","r");
   if(ptrOpen==NULL)// check that file is in system
   {
       gotoxy(40,18);printf("CAN NOT OPEN FILE!!");
       delay(50);
       system("cls");
       main();
   }
   gotoxy(32,6);printf("Enter Item code :");
   scanf("%s",item);
   while(fscanf(ptrOpen," %s %s %d %f ",copy.itemCode,copy.itemName,&copy.quintity,&copy.price)!=EOF)
   {
       int cmps=strcmp(copy.itemCode,item);// to check  inputed item code is same at inventory file items
       if(cmps==0)
       {
         test=1;
       }
   }
   fclose(ptrOpen);
   if(test==0)//when the inputed item code does not match
   {
       gotoxy(40,18);printf("There is no that item code in inventory");
       foward();//calling to function
   }
   ptrOpen=fopen("currentInventory.dat","r");

   gotoxy(32,8);printf("Enter New Price :");
   float check=scanf("%f",&price);
   fflush(stdin);
   if(check!=1.0)
   {
       gotoxy(32,8);printf("invalid input   !!!!!");
       gotoxy(32,9);printf("Renter New Price :");
       fflush(stdin);
       scanf("%f",&price);

   }
   if(price<0)
   {
       gotoxy(32,8);printf("invalid input   !!!!!");
       gotoxy(32,9);printf("Renter New Price :");
       fflush(stdin);
       scanf("%f",&price);

   }
   checkFlotInput(check,8,&price);
   ptrNew=fopen("copy.dat","w");
   while(fscanf(ptrOpen," %s %s %d %f ",copy.itemCode,copy.itemName,&copy.quintity,&copy.price)!=EOF) // read data form inventory file
   {
       int cmps=strcmp(copy.itemCode,item);
       if(cmps==0)
       {
           gotoxy(32,10);printf("PREVIOUS PRICE : %.1f",copy.price);
           gotoxy(32,12);printf("ITEM NAME      : %s",copy.itemName);
           fprintf(ptrNew," %s %s %d %f ",copy.itemCode,copy.itemName,copy.quintity,price);
           gotoxy(40,20);printf("CHANGE ITEM PRICE SUCCESFULLY!!!");
       }
       else
       {
           fprintf(ptrNew," %s %s %d %f ",copy.itemCode,copy.itemName,copy.quintity,copy.price);
       }
   }
   fclose(ptrOpen);
   fclose(ptrNew);
   remove("currentInventory.dat");
   rename("copy.dat","currentInventory.dat");
   foward();
}
void changeQty() // this function use to  change item quantity and change quantity from only inventory file
{
    head(); // calling to function
    gotoxy(53,4);printf("-CHANGE QUANTITY-");
   char item[LENGTH];
   FILE*ptrOpen,*ptrNew;
   struct goods copy;
   int qty=0,test=0;
   ptrOpen=fopen("currentInventory.dat","r");
   if(ptrOpen==NULL) // check the file is in system
   {
       gotoxy(40,18);printf("CAN NOT OPEN FILE!!");
       delay(50);
       system("cls");
       main();
   }
   gotoxy(32,6);printf("Enter Item code :");
   scanf("%s",item);
   while(fscanf(ptrOpen," %s %s %d %f ",copy.itemCode,copy.itemName,&copy.quintity,&copy.price)!=EOF)
   {
       int cmps=strcmp(copy.itemCode,item); // for checking  inputed item code same at inventory
       if(cmps==0)
       {
         test=1;
       }
   }
   fclose(ptrOpen);
    if(test==0) // when inputed item code does not match inventory file item codes
   {
       gotoxy(40,18);printf("There is no that item code in inventory");
       foward();
   }
   ptrOpen=fopen("currentInventory.dat","r");
   gotoxy(32,8);printf("Enter New Quantity :");
   scanf("%d",&qty);
   ptrNew=fopen("copy.dat","w");
   while(fscanf(ptrOpen," %s %s %d %f ",copy.itemCode,copy.itemName,&copy.quintity,&copy.price)!=EOF)
   {
       int cmps=strcmp(copy.itemCode,item);
       if(cmps==0)
       {
           gotoxy(32,10);printf("PREVIOUS QUANTITY : %d ",copy.quintity);
           gotoxy(32,12);printf("ITEM   NAME       : %s",copy.itemName);
           fprintf(ptrNew," %s %s %d %f ",copy.itemCode,copy.itemName,qty,copy.price);
           gotoxy(40,20);printf("CHANGE ITEM QUANTITY SUCCESFULLY!!!");
       }
       else
       {
           fprintf(ptrNew," %s %s %d %f ",copy.itemCode,copy.itemName,copy.quintity,copy.price);
       }
   }
   fclose(ptrOpen);
   fclose(ptrNew);
   remove("currentInventory.dat");
   rename("copy.dat","currentInventory.dat");
   foward();

}
void changeCode() // this function for changing item code , and changed item code will be updated all of file that certain item code
{

   head();// calling to function
   gotoxy(53,4);printf("-CODE CHANGE-");
   char item[LENGTH],newcode[LENGTH];
   FILE*ptrOpen,*ptrNew,*ptrOpendis,*ptrNewdis;
   struct goods copy;
   struct goods geting;
   struct goods getin;
   struct goods disp;
   int test=0,test1=0;
   ptrOpen=fopen("currentInventory.dat","r");
   if(ptrOpen==NULL)// to check this file is in this system
   {
       gotoxy(40,18);printf("CAN NOT OPEN FILE!!");
       delay(50);
       system("cls");
       main();
   }
   gotoxy(32,6);printf("Enter Item code :");
   scanf("%s",item);

   gotoxy(32,9);printf("Enter New Item code :");
   scanf("%s",newcode);
   while(fscanf(ptrOpen," %s %s %d %f ",copy.itemCode,copy.itemName,&copy.quintity,&copy.price)!=EOF)
   {
       int cmps=strcmp(copy.itemCode,item);// to check inputed item code is in at inventory file
       int cmp=strcmp(copy.itemCode,newcode);// to check new inputed item code is in at inventory file
       if(cmps==0)
       {
         test=1;
       }
       else if(cmp==0)
       {
           test1=1;
       }
   }
   fclose(ptrOpen);
    if(test==0)
   {
       gotoxy(40,18);printf("There is no that item code in inventory");
       foward();
   }
   if(test1==1)
   {
       gotoxy(40,18);printf("There is an item code in inventory");
       foward();
   }
   ptrOpen=fopen("currentInventory.dat","r");
   ptrNew=fopen("copy.dat","w");
   while(fscanf(ptrOpen," %s %s %d %f ",copy.itemCode,copy.itemName,&copy.quintity,&copy.price)!=EOF)
   {
       int cmps=strcmp(copy.itemCode,item);
       if(cmps==0)
       {
           gotoxy(32,12);printf("ITEM   NAME       : %s",copy.itemName);
           fprintf(ptrNew," %s %s %d %f ",newcode,copy.itemName,copy.quintity,copy.price);
           gotoxy(40,20);printf("CHANGE ITEM CODE SUCCESFULLY!!!");
       }
       else
       {
           fprintf(ptrNew," %s %s %d %f ",copy.itemCode,copy.itemName,copy.quintity,copy.price);
       }
   }
   fclose(ptrOpen);
   fclose(ptrNew);
   remove("currentInventory.dat");
   rename("copy.dat","currentInventory.dat");

   ptrOpen=fopen("disto.dat","r");
   ptrNew=fopen("copy.dat","w");

   while(fscanf(ptrOpen," %s %s %d %f %d %s ",geting.itemCode,geting.itemName,&geting.quintity,&geting.price,&geting.load,geting.loading.vehicle)!=EOF)
   {
       int cmp1=strcmp(geting.itemCode,item);
       if(cmp1==0)
       {
           fprintf(ptrNew," %s %s %d %f %d %s ",newcode,geting.itemName,geting.quintity,geting.price,geting.load,geting.loading.vehicle);
       }
       else
       {
           fprintf(ptrNew," %s %s %d %f %d %s ",geting.itemCode,geting.itemName,geting.quintity,geting.price,geting.load,geting.loading.vehicle);
       }
   }
   fclose(ptrOpen);
   fclose(ptrNew);
   remove("disto.dat");
   rename("copy.dat","disto.dat");

   ptrOpen=fopen("sells.dat","r");
   ptrNew=fopen("copy.dat","w");

   while(fscanf(ptrOpen," %s %s %s %d %f",getin.itemCode,getin.itemName,getin.loading.vehicle,&getin.sels,&getin.selling)!=EOF)
   {
       int cmp2=strcmp(getin.itemCode,item);
       if(cmp2==0)
       {
           fprintf(ptrNew," %s %s %s %d %f",newcode,getin.itemName,getin.loading.vehicle,getin.sels,getin.selling);
       }
       else
       {
           fprintf(ptrNew," %s %s %s %d %f",getin.itemCode,getin.itemName,getin.loading.vehicle,getin.sels,getin.selling);
       }
   }
   fclose(ptrOpen);
   fclose(ptrNew);
   remove("sells.dat");
   rename("copy.dat","sells.dat");

   ptrOpendis=fopen("display.dat","r");
   ptrNewdis=fopen("copy1.dat","w");

   while(fscanf(ptrOpen," %s %s ",disp.loading.vehicle,disp.itemCode)!=EOF)
   {
       int cmp3=strcmp(disp.itemCode,item);
       if(cmp3==0)
       {
           fprintf(ptrNew," %s %s ",disp.loading.vehicle,newcode);
       }
       else
       {
           fprintf(ptrNew," %s %s ",disp.loading.vehicle,disp.itemCode);
       }

   }
   fclose(ptrOpendis);
   fclose(ptrNewdis);
   remove("display.dat");
   rename("copy1.dat","display.dat");

   ptrOpen=fopen("sortitem.dat","r");
   ptrNew=fopen("copy.dat","w");
   while(fscanf(ptrOpen," %s %d ",getin.itemCode,&getin.sels)!=EOF)
   {
       int cmp4=strcmp(getin.itemCode,item);
       if(cmp4==0)
       {
           fprintf(ptrNew," %s %d ",newcode,getin.sels);
       }
       else
       {
           fprintf(ptrNew," %s %d ",getin.itemCode,getin.sels);
       }
   }
   fclose(ptrOpen);
   fclose(ptrNew);
   remove("sortitem.dat");
   rename("copy.dat","sortitem.dat");
foward();

}
void serch()//this function for search vehicle to see their details
{
    head();
    gotoxy(53,4);printf("-SEARCH DETAIL-");
    FILE*ptrOpen1,*ptrOpen2;
    ptrOpen1=fopen("vehiclestore.dat","r");
    int test=0;
    if(ptrOpen1==NULL)
    {
        gotoxy(40,20);printf("THERE IS NO FILE TO OPEN");
        system("cls");
        main();
    }
    ptrOpen2=fopen("sort.dat","r");
    char idVehi1[LENGTH][LENGTH],idveh2[LENGTH][LENGTH],name[LENGTH][LENGTH],vehicle[LENGTH],id[LENGTH][LENGTH];
    int qty[LENGTH],i=0,p=0,telNo[LENGTH];
    gotoxy(32,6);printf("Enter vehicle Id : ");
    scanf("%s",vehicle);

    while(fscanf(ptrOpen1," %s %s %s %d ",idVehi1[i],name[i],id[i],&telNo[i])!=EOF)
    {

        ++i;
    }
    fclose(ptrOpen1);

    for(int j=0;j<=i;j++)
    {
        int cmp=strcmp(idVehi1[j],vehicle);
        if(cmp==0)
        {
            test=1;
             gotoxy(32,10);printf("SELLER NAME          : %s  ",name[j]);
             gotoxy(32,14);printf("SELLER NIC NO        : %s  ",id[j]);
             gotoxy(32,18);printf("SELLER TELEPHONE NO  : %d  ",telNo[j]);
        }
    }
    while(fscanf(ptrOpen2," %s %d ",idveh2[p],&qty[p])!=EOF)
    {
        ++p;
    }
     for(int k=0;k<=p;k++)
    {
        int cmp=strcmp(idveh2[k],vehicle);
        if(cmp==0)
        {
             gotoxy(32,22);printf("SELLER SELLS QUANTITY : %d ",qty[k]);

        }
    }

    fclose(ptrOpen1);
    fclose(ptrOpen2);
    if(test==0)
    {
      gotoxy(40,20);printf("THERE IS NO SELLER ON THAT ID");
      foward();
    }
    foward();
}



