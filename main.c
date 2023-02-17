#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototyping the functions
char AddMedicine();
char DeleteMedicine();
char UpdateMedicine();
char PrintMedicineInStock();
char GetMedicineInfo();
char SellMedicine();

//Defining Structures used in some of the functions
struct Update{
    char nid[150], nname[150], nquan[150], ncomp[150], nprice[150], nman[150], nexpire[150];
};
struct Add{
 char id[150], name[150], quan[150], comp[150], price[150], man[150], expire[150];
};
struct input{
    char inputname[150];
};
struct output{
    char oid[150], oname[150], oquan[150], ocomp[150], oprice[150], oman[150], oexpire[150];
};
struct output2{
    char ooid[150], ooname[150], ooquan[150], oocomp[150], ooprice[150], ooman[150], ooexpire[150];
};
struct output3{
    char oooid[150], oooname[150], oooquan[150], ooocomp[150], oooprice[150], oooman[150], oooexpire[150];
};


int main(void){
    int inp, a = 1;
    //Infinite loop to repeat the functions till the user exits
    while (a){
        printf("\nEnter 1 to Add Medicine:\n");
        printf("Enter 2 to Delete Medicine:\n");
        printf("Enter 3 to Update Medicine:\n");
        printf("Enter 4 to display the products in stock:\n");
        printf("Enter 5 to display the Medicines' info with entering a specific ID or a name:\n");
        printf("Enter 6 to buy a medicine:\n");
        printf("Enter 7 to exit:\n");
        scanf("%d", &inp);


        if(inp == 1){
                AddMedicine();
        }else if(inp == 2){
            DeleteMedicine();
        }
        else if(inp == 3){
            UpdateMedicine();
        }else if(inp == 4){
            PrintMedicineInStock();
        }else if(inp == 5){
            GetMedicineInfo();
        }else if(inp == 6){
            SellMedicine();
        }else if(inp == 7){
            a = 0;
            exit(0);
        }
    }
}
char AddMedicine(){
    FILE * fpointer;


    fpointer = fopen("MedicineData.txt", "a");
    struct Add ad; //Medicine Addition Structure.

    printf("Enter the Medicine Id:\n"); scanf("%s", ad.id); printf("Enter Medicine Name:\n"); scanf("%s", ad.name); printf("Enter Company Name:\n"); scanf("%s", ad.comp);
    printf("Enter Manufacturing Date:\n"); scanf("%s", ad.man); printf("Enter Expiry Date:\n"); scanf("%s", ad.expire); printf("Enter Quantity:\n"); scanf("%s", ad.quan);
    printf("Enter Price\n"); scanf("%s", ad.price);
    fprintf(fpointer, "id:%s ", ad.id); fprintf(fpointer, "name:%s ", ad.name); fprintf(fpointer, "quan:%s ", ad.quan); fprintf(fpointer, "comp:%s ", ad.comp);
    fprintf(fpointer, "price:%s ", ad.price); fprintf(fpointer, "man:%s ", ad.man); fprintf(fpointer, "expire:%s\n", ad.expire);

    //Saving the text file:
    fclose(fpointer);
    printf("\nThe file has been updated Successfully!");
}
char DeleteMedicine(){
    FILE * FPOINTER; struct input n; FILE * NFPOINTER;
    char line[150]; char str[150];
    int linecount = 0, linenum = 0;


    FPOINTER = fopen("MedicineData.txt", "r");
    NFPOINTER = fopen("MedicineData1.txt", "w");

    printf("Enter the name:\n");
    scanf("%s", n.inputname);

    //Finds in which line is the word.
    while(!feof(FPOINTER)){ //Keep looping till the end of the file (reading line by line and stores it in the pointer)
        fgets(line, 150, FPOINTER);
        linecount ++;
        if (strstr(line, strlwr(n.inputname))){
            break;
        }
    }
    //Writing the non-word lines in a new file
    rewind(FPOINTER);

    while(fgets(str, 149, FPOINTER) != NULL){ //storing the line in the
            linenum ++;
            if (linenum == linecount){
                    continue;



            }else{
                fputs(str, NFPOINTER);
            }
    }
    fclose(FPOINTER);
    fclose(NFPOINTER);
    remove("MedicineData.txt");
    rename("MedicineData1.txt", "MedicineData.txt");
    printf("\nThe Medicine has been deleted successfully!");
}
char UpdateMedicine(){
    FILE * UFPOINTER; FILE * NUFPOINTER;
    struct Add ad; struct Update u;
    char line[150]; char str[150]; char ID[100];
    int linecount = 0, linenum = 0;
    int tnum, nID, ninputID;
    printf("Please enter the ID Number:\n");
    scanf("%s", ID);
    UFPOINTER = fopen("MedicineData.txt","r");
    NUFPOINTER = fopen("MedicineData1.txt","w");



    while (!feof(UFPOINTER)){
        //Scans through the line the pointer points to //And be careful with the spacing the characters before the needed string to be read!
        fscanf(UFPOINTER,"   id:%s      name:%s      quan:%s     comp:%s      price:%s     man:%s       expire:%s", ad.id, ad.name,ad.quan, ad.comp,  ad.price, ad.man, ad.expire);

        //Changing the type of the ID from string to integer.
        ninputID = atoi (ID);
        nID = atoi(ad.id);

        if(nID == ninputID){
            //Changing the value of the info from NULL to the value of ad.id
            strcpy(u.nid, ad.id),strcpy(u.nname, ad.name), strcpy(u.nquan, ad.quan), strcpy(u.ncomp, ad.comp),strcpy(u.nprice, ad.price),strcpy(u.nman, ad.man), strcpy(u.nexpire, ad.expire);

        }
    }
    //Checking what data does the user want to modify
    printf("Enter 1 to change the Quantity\n");
    printf("Enter 2 to change the Price\n");
    printf("Enter 3 to change the Name\n");
    printf("Enter 4 to change the Company\n");
    printf("Enter 5 to change the Manufacturing Date\n");
    printf("Enter 6 to change the Expiry Date\n");
    scanf("%d", &tnum);
    if(tnum == 1){
        printf("Enter the new Quantity:\n");
        scanf("%s", u.nquan);
    }
    else if(tnum == 2){
        printf("Enter the new Price:\n");
        scanf("%s", u.nprice);
    }
    else if(tnum == 3){
        printf("Enter the new Name:\n");
        scanf("%s", u.nname);
    }
    else if(tnum == 4){
        printf("Enter the new Company name:\n");
        scanf("%s", u.ncomp);
    }
    else if(tnum == 5){
        printf("Enter the new Manufacturing Date:\n");
        scanf("%s", u.nman);
    }
    else if(tnum == 6){
        printf("Enter the new Expire Date:\n");
        scanf("%s", u.nexpire);
    }


    //returns the pointer to the first line in the file

    rewind(UFPOINTER);

    //Finds in which line is the word.
    while(!feof(UFPOINTER)){ //Keep looping till the end of the file (reading line by line and stores it in the pointer)
        fgets(line, 150, UFPOINTER);
        linecount ++;
        if (strstr(line, ID)){
            break;
        }
    }
    //Writing the non-word lines in a new file
    rewind(UFPOINTER);
    while(fgets(str, 149, UFPOINTER) != NULL){
            linenum ++;
            if (linenum == linecount){
                    fprintf(NUFPOINTER, "id:%s name:%s quan:%s comp:%s price:%s man:%s expire:%s \n", u.nid, u.nname, u.nquan, u.ncomp, u.nprice, u.nman, u.nexpire);




            }else{

                fputs(str, NUFPOINTER);
            }
    }
    fclose(UFPOINTER);
    fclose(NUFPOINTER);
    remove("MedicineData.txt");
    rename("MedicineData1.txt", "MedicineData.txt");
    printf("\nThe file has been updated Successfully!");
}
char PrintMedicineInStock(){

    FILE * pfpointer; struct output o;
    int stock;

    pfpointer = fopen ("MedicineData.txt", "r");
    printf("Currently displaying Medicine in Stock\n");
    printf("ID\tName\tQuantity\tCompany\tPrice\tManufacturing Date\tExpire Date\n");
    while(!feof(pfpointer)){

            fscanf(pfpointer,"   id:%s      name:%s      quan:%s     comp:%s      price:%s     man:%s       expire:%s", o.oid, o.oname, o.oquan, o.ocomp,  o.oprice, o.oman, o.oexpire);
            //changing the type of o.oquan to integer and storing it in a new array to validate the if condition
            stock = atoi(o.oquan);

            if(stock != 0){

                printf("%s\t%s\t%s\t\t%s\t%s\t%s\t\t%s\n", o.oid, o.oname, o.oquan, o.ocomp,  o.oprice, o.oman, o.oexpire);

            }


    }
    fclose(pfpointer);
}
char GetMedicineInfo(){

    FILE * ppfpointer; struct output2 oo;
    char INPUT[100];

    ppfpointer = fopen ("MedicineData.txt", "r");
    printf("Enter the Name or the ID you want to display its Info:\n");
    scanf("%s", INPUT);
    printf("Currently displaying Medicine with Name/ID you entered!\n");
    printf("ID\tName\tQuantity\tCompany\tPrice\tManufacturing Date\tExpire Date\n");
    while(!feof(ppfpointer)){

            fscanf(ppfpointer,"   id:%s      name:%s      quan:%s     comp:%s      price:%s     man:%s       expire:%s", oo.ooid, oo.ooname, oo.ooquan, oo.oocomp,  oo.ooprice, oo.ooman, oo.ooexpire);



            if(strstr(oo.ooid, INPUT) || strstr(oo.ooname, strlwr(INPUT))){

                printf("%s\t%s\t%s\t\t%s\t%s\t%s\t\t%s\n", oo.ooid, oo.ooname, oo.ooquan, oo.oocomp,  oo.ooprice, oo.ooman, oo.ooexpire);

            }


    }
    fclose(ppfpointer);
}
char SellMedicine(){

    FILE * ppfpointer; struct output3 ooo; FILE *PPFPOINTER;
    char INPUT[100];  char QUAN[150]; char TSQUAN[150];
    int tinput, cprice, CQUAN, nprice, IQUAN, TQUAN;

    ppfpointer = fopen ("MedicineData.txt", "r");
    PPFPOINTER = fopen ("MedicineData1.txt", "w");
    printf("Enter the Name or the ID you want to display its Info:\n");
    scanf("%s", INPUT);
    printf("Currently displaying Medicine with Name/ID you entered!\n");
    printf("ID\tName\tQuantity\tCompany\tPrice\tManufacturing Date\tExpire Date\n");
    while(!feof(ppfpointer)){

            fscanf(ppfpointer,"   id:%s      name:%s      quan:%s     comp:%s      price:%s     man:%s       expire:%s", ooo.oooid, ooo.oooname, ooo.oooquan, ooo.ooocomp,  ooo.oooprice, ooo.oooman, ooo.oooexpire);



            if(strstr(ooo.oooid, INPUT) || strstr(ooo.oooname, strlwr(INPUT))){

                printf("%s\t%s\t%s\t\t%s\t%s\t%s\t\t%s\n", ooo.oooid, ooo.oooname, ooo.oooquan, ooo.ooocomp,  ooo.oooprice, ooo.oooman, ooo.oooexpire);

                cprice = atoi(ooo.oooprice);
                CQUAN = atoi(ooo.oooquan);



            }
    }

    printf("If you want to buy this medicine, please enter 1.\n");
    scanf("%d", &tinput);
    rewind(ppfpointer);
    if (tinput == 1){
        printf("Please enter the Quantity:\n");
        scanf("%s", QUAN);
        IQUAN = atoi(QUAN);

        //Checking if the quantity is available.

        if (CQUAN >= IQUAN){
            nprice = IQUAN * cprice;
            TQUAN = CQUAN - IQUAN;
            itoa(TQUAN, TSQUAN, 10);
            printf("The total price equals: %d L.E\n", nprice);

            while(!feof(ppfpointer)){

            fscanf(ppfpointer,"   id:%s      name:%s      quan:%s     comp:%s      price:%s     man:%s       expire:%s", ooo.oooid, ooo.oooname, ooo.oooquan, ooo.ooocomp,  ooo.oooprice, ooo.oooman, ooo.oooexpire);

             if(strstr(ooo.oooid, INPUT) || strstr(ooo.oooname, strlwr(INPUT))){

                    fprintf(PPFPOINTER, "id:%s name:%s quan:%s comp:%s price:%s man:%s expire:%s \n", ooo.oooid, ooo.oooname, TSQUAN, ooo.ooocomp,  ooo.oooprice, ooo.oooman, ooo.oooexpire);
             }
             else{

                 fprintf(PPFPOINTER, "id:%s name:%s quan:%s comp:%s price:%s man:%s expire:%s \n", ooo.oooid, ooo.oooname, ooo.oooquan, ooo.ooocomp,  ooo.oooprice, ooo.oooman, ooo.oooexpire);
             }
        }
        }else{
            printf("Sorry! Only %d are available.", CQUAN);
        }

    }else{
        printf("Invalid Number!\n");
    }

    fclose(PPFPOINTER);
    fclose(ppfpointer);
    remove("MedicineData.txt");
    rename("MedicineData1.txt", "MedicineData.txt");
    printf("\nThe file has been updated Successfully!");

}
