#include <stdio.h>
#include <string.h>
#define BUF_SIZE 100
typedef struct StudentStruct{
    int UIN;
    char netid[BUF_SIZE];
    float GPA;
}student;

int loadFile(char filename[], student s[]);
void printStudents(student s[], int num);
void swapStudent(student *s1, student *s2);
void sortGPA(student *s, int num);
int main(){
    student s[100];
    int numStudent;
    char filename[20];
    printf("Enter file name: ");
    scanf("%s", filename);

    numStudent = loadFile(filename, s);
    printStudents(s, numStudent);
    
    sortGPA(s, numStudent);
    printStudents(s, numStudent);
    return 0;
}
//int loadFile(char *filename, student *s){
// return the number student in the file
int loadFile(char filename[], student s[]){
    FILE *fp;

    if( (fp = fopen(filename, "r")) == NULL){
        printf("Cannot open %s.\n", filename);
        return -1;
    }

    char buffer[BUF_SIZE];
    int num = 0;

    fgets(buffer, BUF_SIZE, fp);//skip header

    /*
    while( (fgets(buffer, BUF_SIZE, fp)) !=NULL){
        sscanf(buffer, "%d %s %f", &(s[num].UIN), s[num].netid, &(s[num].GPA));
        num++;
    }
    */
    while( fscanf(fp , "%d %s %f", &(s[num].UIN), s[num].netid, &(s[num].GPA)) != EOF){
                num++;
    }

    fclose(fp);

    return num;

}
// print student array
void printStudents(student s[], int num){
    int i;
    printf("UIN netid GPA\n");
    for(i=0;i<num;i++)
        printf("%d %s %f\n", s[i].UIN, s[i].netid, s[i].GPA);

}
// swap two students
void swapStudent(student *s1, student *s2){
    student temp;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
// sort students by GPA (descending)
void sortGPA(student *s, int num){
    int is_swap, i;
    printf("%f\n", s->GPA);
    printf("%f\n", (s+1)->GPA);

    do{
        is_swap = 0;
        for(i=0;i<num-1;i++){
            if( s[i].GPA < s[i+1].GPA){
                swapStudent(&s[i], &s[i+1]);
                is_swap = 1;
            }
        }
    }while(is_swap!=0);
}
