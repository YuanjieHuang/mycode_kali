#include <stdio.h>
#include <stdlib.h>
long openSrcFile(char **buffer)
{
    FILE *myfiel_src;
    char filename[20];
    long file_size;
    printf("Input the path and filename\n");
    scanf("%s",filename);
    if(!(myfiel_src = fopen(filename,"rb")))
    {
        perror("open file error:");
    }
    fseek(myfiel_src,0,SEEK_END);
    file_size = ftell(myfiel_src);
    *buffer = (char *) malloc(file_size);
    fread(*buffer,1,file_size,myfiel_src);
    fclose(myfiel_src);
    return file_size;
}

void encryption(char buffer[], long file_size, int key)
{
    for(long i=0; i < file_size; i++)
    {
        buffer[i] = buffer[i] + key;
    }
}
void dencryption(char buffer[], int file_size, int key)
{
    for(int i=0; i < file_size; i++)
    {
        buffer[i] = buffer[i] - key;
    }
}

void saveDestFile(char *buffer, long file_size)
{
    FILE *myfile_dst;
    char filename[20];
    printf("Input the path and filename to save\n");
    scanf("%s",filename);
    if(!(myfile_dst = fopen(filename,"wb")))
    {
        perror("open file error:\n");
    }
    fwrite(buffer,1,file_size,myfile_dst);
    fwrite(stdout,1,file_size,myfile_dst);
    printf("save file sucess.\n");
    fclose(myfile_dst);
}

void process(int a)
{
    char *buffer;
    long file_size;
    int key;
    file_size = openSrcFile(&buffer);
    printf("Input the key\n");
    scanf("%d", &key);

    if(a == 0)
    {
        encryption(buffer,file_size,key);
    }
    else
    {
        dencryption(buffer,file_size,key);
    }
    saveDestFile(buffer,file_size);

}

void menu()
{
    printf("*********************************\n");
    printf("=====A simple encyption and decyption system.\n");
    printf("    Encrption press 'E' Decryption press 'D'\n");
    printf("*********************************\n");
}

int main()
{
    char flag = getchar();
    menu();
    while (flag != 'Q')
    {
        switch (flag)
        {
        case 'E':
            process(0);
            break;
        case 'D':
            process(1);
            break;
        }
        flag = getchar();
    }
    
}