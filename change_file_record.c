#include<stdio.h>
#include<math.h>

typedef struct{
    char name[50];
    int chinese;
    int english;
    int math;
}Score;

void printScore(FILE* fPtr){
    printf("Name\tChinese\tEnglist\tMath\t\n");
    int numOfRecord = 0;

    //使用 fseek 函式將檔案指標移動到檔案的尾端，以計算檔案中有多少個 Score 結構的資料。
    //這裡將偏移量設為 0，所以檔案指標會移動到檔案的尾端。
    fseek(fPtr, 0, SEEK_END);

    //使用 ftell 函式取得檔案指標的位置，然後除以 Score 結構的大小，計算出資料筆數，
    //因為檔案指標已經在上一步中移到檔案尾端，所以這裡可以得到資料筆數
    numOfRecord = ftell(fPtr) / sizeof(Score);

    //使用 rewind 函式將檔案指標重新移動到檔案的開頭，為讀取資料做準備
    rewind(fPtr);

    Score data[numOfRecord];

    //使用 fread 函式從檔案中讀取 numOfRecord 個 Score 結構的資料，並將資料儲存到 data 陣列中
    fread(data, sizeof(Score), numOfRecord, fPtr);

    for(int i = 0; i < numOfRecord; i++){
        printf("%s\t%d\t%d\t%d\t\n", data[i].name, data[i].chinese, data[i].english, data[i].math);
    }
}

void adjustScore(FILE* fp, FILE* fp_adj){
    int numOfRecords = 0;
    int numOfRecord = 0;

    fseek(fp, 0, SEEK_END);
    numOfRecord = ftell(fp) / sizeof(Score);
    rewind(fp);

    Score data[numOfRecord];
    fread(data, sizeof(Score), numOfRecord, fp);

    // Update the score with 10 * sqrt(score)
    for(int i = 0; i < numOfRecord; i++){
        data[i].chinese = (int)(sqrt(data[i].chinese) * 10);
        data[i].english = (int)(sqrt(data[i].english) * 10);
        data[i].math = (int)(sqrt(data[i].math) * 10);
    }

    // Write to the new file
    fwrite(data, sizeof(Score), sizeof(data) / sizeof(Score), fp_adj);
}


int main(){
    FILE* fp = fopen("FinalExam.dat", "rb+");
    FILE* fp_adj = fopen("FinalExam_adjusted.dat", "wb+");

    if(fp == NULL || fp_adj == NULL){
        printf("Error, cannot open file!");
    }
    else{
        printf("Original score:\n\n");
        printScore(fp);
        adjustScore(fp, fp_adj);
        printf("\nAdjusted score:\n\n");
        printScore(fp_adj);

        fclose(fp);
        fclose(fp_adj);
    }
    return 0;
}
