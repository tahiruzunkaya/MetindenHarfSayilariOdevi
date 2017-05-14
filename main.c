#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
void harfler_sifirla();

typedef struct{

    char harf;
    int adet;

}harfler;
void bubble_sort(harfler a[],int boyut);
harfler dizi[29];
int main()
{
    setlocale(LC_ALL,"turkish");
    harfler_sifirla();
    FILE *dosya;

    if((dosya=fopen("dosya.txt","r"))==NULL){

        printf("dosya açýlmadý");
        exit(1);

    }


    int i;
    char tmp_harf,tap;

        for( ; ; ){
            tmp_harf=fgetc(dosya);
            if(tmp_harf==EOF){
                break;
            }
            if(tmp_harf=='ý'){

                tap=73;

            }else{
                if(tmp_harf=='Ý'){
                    tmp_harf='i';
                }
                if(tmp_harf=='i'){
                    tap=106;
                }else{

                tap=toupper(tmp_harf);
                }
            }
            for(i=0;i<29;i++){
                if(tap==dizi[i].harf){

                    dizi[i].adet++;

                }
            }

        }


    fclose(dosya);
    bubble_sort(dizi,29);
    int toplam=0;
    for(i=0;i<29;i++){

        toplam=toplam+dizi[i].adet;


    }
    printf("toplam harf sayýsý = %d\n",toplam);
    for(i=0;i<29;i++){

        printf("%c --> %d\n",dizi[i].harf,dizi[i].adet);

    }


    return 0;
}

void harfler_sifirla(){

    dizi[0].harf='A';
    dizi[0].adet=0;
    dizi[1].harf='B';
    dizi[1].adet=0;
    dizi[2].harf='C';
    dizi[2].adet=0;
    dizi[3].harf=199;
    dizi[3].adet=0;
    dizi[4].harf='D';
    dizi[4].adet=0;
    dizi[5].harf='E';
    dizi[5].adet=0;
    dizi[6].harf='F';
    dizi[6].adet=0;
    dizi[7].harf='G';
    dizi[7].adet=0;
    dizi[8].harf=208;
    dizi[8].adet=0;
    dizi[9].harf='H';
    dizi[9].adet=0;
    dizi[10].harf=73;
    dizi[10].adet=0;
    dizi[11].harf=106;
    dizi[11].adet=0;
    dizi[12].harf='J';
    dizi[12].adet=0;
    dizi[13].harf='K';
    dizi[13].adet=0;
    dizi[14].harf='L';
    dizi[14].adet=0;
    dizi[15].harf='M';
    dizi[15].adet=0;
    dizi[16].harf='N';
    dizi[16].adet=0;
    dizi[17].harf='O';
    dizi[17].adet=0;
    dizi[18].harf=214;
    dizi[18].adet=0;
    dizi[19].harf='P';
    dizi[19].adet=0;
    dizi[20].harf='R';
    dizi[20].adet=0;
    dizi[21].harf='S';
    dizi[21].adet=0;
    dizi[22].harf=222;
    dizi[22].adet=0;
    dizi[23].harf='T';
    dizi[23].adet=0;
    dizi[24].harf='U';
    dizi[24].adet=0;
    dizi[25].harf=220;
    dizi[25].adet=0;
    dizi[26].harf='V';
    dizi[26].adet=0;
    dizi[27].harf='Y';
    dizi[27].adet=0;
    dizi[28].harf='Z';
    dizi[28].adet=0;


}
void bubble_sort(harfler a[],int boyut){

    harfler tmp;
    int i,j;
    for(i=0;i<boyut;i++){

        for(j=0;j<boyut-i-1;j++){
            if(dizi[j].adet<dizi[j+1].adet){

                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;

            }
        }

    }

}
