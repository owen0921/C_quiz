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

    //�ϥ� fseek �禡�N�ɮ׫��в��ʨ��ɮת����ݡA�H�p���ɮפ����h�֭� Score ���c����ơC
    //�o�̱N�����q�]�� 0�A�ҥH�ɮ׫��з|���ʨ��ɮת����ݡC
    fseek(fPtr, 0, SEEK_END);

    //�ϥ� ftell �禡���o�ɮ׫��Ъ���m�A�M�ᰣ�H Score ���c���j�p�A�p��X��Ƶ��ơA
    //�]���ɮ׫��Фw�g�b�W�@�B�������ɮק��ݡA�ҥH�o�̥i�H�o���Ƶ���
    numOfRecord = ftell(fPtr) / sizeof(Score);

    //�ϥ� rewind �禡�N�ɮ׫��Э��s���ʨ��ɮת��}�Y�A��Ū����ư��ǳ�
    rewind(fPtr);

    Score data[numOfRecord];

    //�ϥ� fread �禡�q�ɮפ�Ū�� numOfRecord �� Score ���c����ơA�ñN����x�s�� data �}�C��
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
