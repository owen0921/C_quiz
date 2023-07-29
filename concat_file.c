#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// read mtcar1.txt and mtcars2.txt
// store them into "struct cars"
// extract the cars whose mpg is greater than 20

struct cars{
    char brand[20];
    char type[20];
    float mpg;
    int cyl;
    float disp;
    int hp;
};

void numOfRecords(FILE* fPtr){
    int count = 0;
    if(fPtr == NULL){
        printf("Error, the file mtcars.txt cannot be opened!\n");
    }
    else{
        printf("%10s %10s %6s %5s %6s %10s\n", "brand", "type", "mpg", "cyl", "disp", "hp");

        // feof:查看是否讀完檔案 Yes => return 1  No => return 0
        while(!feof(fPtr)){
            struct cars car = {"", "", 0.0, 0, 0.0, 0};
            fscanf(fPtr, "%s %s %f %d %f %d\n", car.brand, car.type, &car.mpg, &car.cyl, &car.disp, &car.hp);
            if(car.mpg > 20){
                printf("%10s %10s %6.1f %5d %6 %1f %5d\n", car.brand, car.type, car.mpg, car.cyl, car.disp, car.hp);
                count++;
            }
        }
        printf("There are %d car(s) whose mpg > 20.\n", count);
    }
}

int main(){
    // Open two files to be merged
    FILE* fp1 = fopen("mtcars1.txt", "r");
    FILE* fp2 = fopen("mtcars2.txt", "r");

    //Open file to store the result
    FILE* fp3 = fopen("mtcars.txt", "w");
    char c;

    if(fp1 == NULL || fp2 == NULL || fp3 == NULL){
        printf("Error, cannot open files!");
    }
    else{
        // Copy contents of fp1 to fp3
        while((c = fgetc(fp1)) != EOF){
            fputc(c, fp3);
        }

        // Copy contents of fp2 to fp3
        while((c = fgetc(fp2)) != EOF){
            fputc(c, fp3);
        }
        printf("Successfully merged mtcars1.txt and mtcars2.txt into mtcars.txt!\n\n");
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }

    // extract the cars whose mpg is greater than 20
    FILE* fMtcars = fopen("mtcars.txt", "r");
    if(fMtcars == NULL){
        printf("Error, cannot open mtcars.txt!");
    }
    else{
        numOfRecords(fMtcars);
        fclose(fMtcars);
    }
    return 0;
}
