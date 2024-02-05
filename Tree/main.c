#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 30
struct node{
    char kelime[51];
    int sayac;
    struct node* solbag;
    struct node* sagbag;
};
bool say=false,kontrol=false;
struct node *dugumOlustur(char *dizi){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));//bellekten yeni bir düğüm için yer ayırdık.
    strcpy(newNode->kelime,dizi);
    newNode->sayac=0;
    newNode->sagbag=NULL;
    newNode->solbag=NULL;
    return newNode;
}

struct node* ekle(struct node *root,char *dizi){
    if(root==NULL) //kök boşsa
        root=dugumOlustur(dizi);// root'u yeni düğüme eşitledik.
    if(root!=NULL){
        if(strcmp(root->kelime,dizi) == 0)
            root->sayac++;
        
        // Aranan kelime, kök düğümdeki kelimeden küçükse sol alt ağaca git
        else if (strcmp(dizi,root->kelime) < 0)
            root->solbag=ekle(root->solbag,dizi);
     
        // Aranan kelime, kök düğümdeki kelimeden büyükse sağ alt ağaca git
        else
            root->sagbag=ekle(root->sagbag,dizi);
    }
    return root;
  
    
}

void inorder(struct node *root){
    if (root == NULL)
           return;

    inorder(root->solbag);
    printf("root:%s frekans:%d\n",root->kelime,root->sayac);
    inorder(root->sagbag);
}

// İkili arama ağacında kelime arama
void ara(struct node* root,char* dizi){
    if(root!=NULL){
        if(strcmp(root->kelime,dizi) == 0)
            kontrol=true;
       
        // Aranan kelime, kök düğümdeki kelimeden küçükse sol alt ağaca git
        else if (strcmp(dizi,root->kelime) < 0)
            ara(root->solbag,dizi);
     
        // Aranan kelime, kök düğümdeki kelimeden büyükse sağ alt ağaca git
        else
            ara(root->sagbag,dizi);
    }
}

void sırala(struct node* root,int* enbuyuk,char* kelime){
    if (root == NULL)
           return;
    sırala(root->solbag,enbuyuk,kelime);
    if(root->sayac>*enbuyuk){
        strcpy(kelime,root->kelime);
        *enbuyuk=root->sayac;
        say=true;}
    sırala(root->sagbag,enbuyuk,kelime);
    
}

void dosyaOku(struct node **root){
    FILE *p;
    char dizi[51];
    p=fopen("/Users/gizem/desktop/agac1.txt","r");
    if(p==NULL)
        printf("dosya boş!\n");
    else{
        while(!feof(p)){
            fscanf(p,"%s",dizi);
            *root=ekle(*root,dizi);
        }
    }
    fclose(p);
}
struct node* kucukDugum(struct node* dugum) {
    struct node* kucukNode = dugum;
    while (kucukNode->solbag != NULL)
        kucukNode = kucukNode->solbag;
    return kucukNode;
}

struct node* sil(struct node* root, char* dizi) {
    if (root == NULL)
        return root;
    if (strcmp(dizi, root->kelime) < 0)
        root->solbag = sil(root->solbag, dizi);
    else if (strcmp(dizi, root->kelime) > 0)
        root->sagbag = sil(root->sagbag, dizi);
    else {
        if (root->solbag == NULL) {
            struct node* temp = root->sagbag;
            free(root);
            return temp;
            }
        else if (root->sagbag == NULL) {
            struct node* temp = root->solbag;
            free(root);
            return temp;
            }
        struct node* kucukNode = kucukDugum(root->sagbag);
        strcpy(root->kelime, kucukNode->kelime);
        root->sagbag = sil(root->sagbag, kucukNode->kelime);
        
    }
    return root;
}


int main(){
    struct node* root = NULL;
    struct node* root2=NULL;
    int enbuyuk;
    char kr;
    char aranan[30],kelime[30];
    char dizi[N],silinen[N];
    while(1){
        printf("\nMENU\n");
        printf("Bir İşlem Seçin:Eklemek(E),Aramak(A),Yazdır(Y),EnCokGecenKelimeBul(B),Dosyadan Oku(D),Sil(S),Çıkış(0)\n");
        scanf(" %c",&kr);
        if(kr=='E'){
            printf("eklemek istediğiniz kelimeyi girin:\n");
            scanf("%s",dizi);
            root=ekle(root,dizi);
            
            printf("eklendi...\n");
            inorder(root);
        }
        else if(kr=='A'){
            printf("aranacak kelimeyi girin:\n");
            scanf("%s",aranan);
            kontrol=false;
            ara(root,aranan);
            if(kontrol==false)
                printf("aranan bulunamadı!\n");
            else
                printf("aranan bulundu!\n");
            
        }
        else if(kr=='Y'){
            printf("inorder dolaşma...\n");
            inorder(root);
            
        }
        else if(kr=='B'){
            enbuyuk=0;
            say=false;
            sırala(root,&enbuyuk,kelime);
            if(say==true)
                printf("en çok geçen kelime:%s-%d\n",kelime,enbuyuk);
        }
        else if(kr=='0'){
            printf("çıkış yapıldı\n");
            break;
        }
        else if(kr=='D'){
            printf("dosya okunuyor...\n");
            dosyaOku(&root2);
            inorder(root2);
        }
        else if(kr=='S'){
            printf("silmek istediğiniz kelimeyi girin:\n");
            scanf("%s",silinen);
            root=sil(root,silinen);
            printf("silindi...\n");
            inorder(root);
            
        }
        else
            printf("yanlış karakter yeniden deneyin\n");
        
    }
    
  
    
    
    
    
    
    
    
}


   

