#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>



void main(){

char dirname[20];
printf("Enter the directory name: ");
scanf("%s",dirname);
mkdir(dirname);
printf("Directory created successfully");

create_file("akash.txt",dirname);
search_files("akash.txt",dirname);


display_files(dirname);
    }

    //function to create file in the directory
    void create_file(char *filename, char *dirname){
  
    FILE *fp;
    char path[100];
    sprintf(path, "%s/%s", dirname, filename);
    fp = fopen(path, "w");

    if(fp == NULL){
        printf("Error in creating file");
        exit(1);

    }
    printf("File created successfully");
    fclose(fp);
    }

    // fucnction to delete file from the directory
    void delete_file(char *filename, char *dirname){
    char path[100];
    sprintf(path, "%s/%s", dirname, filename);
    if(remove(path) == 0){
        printf("File deleted successfully");
    }
    else{
        printf("Error in deleting file");
    }
    }

    // function to search file in the directory
    // void search_file(char *filename, char *dirname){
    // char path[100];
    // sprintf(path, "%s/%s", dirname, filename);


    // // check if file exists
    // if(access(path, F_OK) != -1){
    //     printf("File exists");
    // }
    // else{
    //     printf("File does not exist");
    // }
    // }

    //display all files in the directory
    void display_files(char *dirname){
    DIR *dir;
    struct dirent *ent;

    if((dir = opendir(dirname)) != NULL){
        while((ent = readdir(dir)) != NULL){
            printf("%s, ", ent->d_name);
        }
        closedir(dir);
    }


 
    }

        void search_files(char *filename,char *dirname){
    DIR *dir;
    struct dirent *ent;

    if((dir = opendir(dirname)) != NULL){
        while((ent = readdir(dir)) != NULL){
            if(strcmp(ent->d_name,filename)==0){
                printf("File exists");
               return;
            }
          
        }
                        printf(" shedaFile does not exist");
        closedir(dir);
    }


 
    }


