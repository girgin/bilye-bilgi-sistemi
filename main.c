#include <stdio.h>
#include <stdlib.h>

int main()
{
    int kutuSayac = 0;//kutu sayisini tutuyor
    int bilyeSayisi;
    int i;
    int ilkBilye, ikinciBilye;
    int ilkSayac, ikinciSayac;
    int agirlik;//bilyeler,n agirligi
    char devam;
    int hataliKutu = 0, toplamKutu = 0;
    int toplamKabul = 0, toplamIade = 0;
    int esitSayac = 0, buyukSayac = 0, kucukSayac = 0;//esit sayac tum girilen degrler esit ,buyuk sayac girilen farkli degr digerlerinden buyuk,kucuk sayac farkli degr digerlerinden kucuk.
    int hataVar;
    int agirlik_farki=0;//buyuk ise yari farkini tutar
   int agirlik_farki2=0;//kucuk ise sayi farkini tutar
   int en_buyuk=0;
   int en_buyugun_agirligi=0;//girilen en buyuk agrlik
   int en_kucuk=0;
   int en_kucuk_agirligi=0;//girilen en kucuk agirlik
   int toplam_agirlik=0;//girilen butun agirliklerin toplami
    do
    {


        hataVar = 0;
        ilkSayac = 0;
        ikinciSayac = 0;
        kutuSayac++;
        printf("%d. kutudaki bilye sayisi: ",kutuSayac);
        scanf("%d",&bilyeSayisi);
        while (bilyeSayisi < 10)
        {
            printf("Yeniden girin: ");
            scanf("%d",&bilyeSayisi);
        }


        ilkBilye = 0;
        ikinciBilye = 0;
        for (i=0;i<bilyeSayisi;i++)
        {
            do
            {
                printf("%d. bilyenin agirligi: ",i+1);
                scanf("%d",&agirlik);//butun girilen degrleri agirlik  degiskeni tutar
            } while (agirlik <= 0);

            if (ilkBilye == 0)
            {
                ilkBilye = agirlik;//ilk girilen degeri bu saca tutar
                ilkSayac++;
            }
            else if (ikinciBilye == 0 && agirlik != ilkBilye)//ilk sayactan farkli ise ikinci sayac tutması icin if dongusune girer
            {
                ikinciBilye = agirlik;
                ikinciSayac++;//birinciden farli girilen bilye agirligi varsa ikinci sayacı tutar
            }

            else if (agirlik == ilkBilye)//iki deger girildkten sonra girilen degere bakılır ve uygun sayaca atılır
            {
                ilkSayac++;
                if (ilkSayac>1 && ikinciSayac>1)
                {
                    hataVar = 1;//dongu hatali ise 1 donfuruyor
                    toplamIade += bilyeSayisi;
                    hataliKutu++;
                    printf("Kutu hatali!\n");
                    break; // hatalý giriþ
                }
            }
            else if (agirlik == ikinciBilye)//ilk girilen degerlerden farklı degr girilmisse if dongusune girer
            {
                ikinciSayac++;
                if (ilkSayac>1 && ikinciSayac>1)
                {
                    hataVar = 1;//dongu hatali ise 1 donfuruyor
                    toplamIade += bilyeSayisi;
                    hataliKutu++;//hata li girilen durumları tutar
                    printf("Kutu hatali!\n");
                    break; // hatalý girildi
                }
            }
            else
            {
                hataVar = 1;//dongu hatali ise 1 donfuruyor
                toplamIade += bilyeSayisi;
                hataliKutu++;//hata li girilen durumları tutar
                printf("Kutu hatali!\n");
                break; // hatalý girildi
            }

            toplam_agirlik+=agirlik;

        }







        if (hataVar == 0)
        {
            if (ikinciBilye == 0)//girilen ikinci deger o ise donguye girer
            {
                esitSayac++;//girilrn butun bilyeler esit agirlikte ise

               if(esitSayac==1)
               {
                   en_buyuk=bilyeSayisi;
                   en_kucuk=bilyeSayisi;
               }

                if(en_buyuk<bilyeSayisi)
                {

                    en_buyuk=0;
                    en_buyugun_agirligi=0;
                    en_buyuk=bilyeSayisi;
                    en_buyugun_agirligi=agirlik;
                }
                else
                {
                    en_kucuk=0;
                    en_kucuk_agirligi=0;
                    en_kucuk=bilyeSayisi;
                    en_kucuk_agirligi=agirlik;
                }

            }
            else if ((ikinciBilye > ilkBilye && ikinciSayac == 1) || (ikinciBilye < ilkBilye && ilkSayac == 1))
            {

                buyukSayac++;//girilen deger diger girilenlerden farlı ve buyuk ise bu sayac tutar
                if(ikinciSayac>ilkSayac)
                {
                    agirlik_farki+=ikinciBilye-ilkBilye;//farkli olan bilyenin buyuk olma durumunda farki alır ve agirlik farki sayacında tutar
                }
                else
                    {


                      agirlik_farki+=ilkBilye-ikinciBilye;//farkli olan bilyenin buyuk olma durumunda farki alır ve agirlik farki sayacında tutar

                    }






            }
            else
            {
                 if(ikinciSayac>ilkSayac)
                {
                     agirlik_farki2+=ikinciBilye-ilkBilye;//farkli olan bilyenn kucuk olma durumunda farki alır
                }
                else
                    {



                      agirlik_farki2+=ilkBilye-ikinciBilye;//farkli olan bilyenn kucuk olma durumunda farki alır
                    }


                kucukSayac++;//girilen farkli deger diger girilenlerden kucuk ve farklı ise bu sayac artar
            }
            toplamKabul += bilyeSayisi;
        }

        toplamKutu++;//toplam kisini girdigi dongu
        printf("Baska kutu var mi (E=Evet, H=Hayir): ");//devam drumu nu sectirir
        scanf(" %c",&devam);

    } while (devam == 'e' || devam == 'E');

    printf("Hatalilarin Toplama Gore Yuzdesi = %%%.2f\n",(float)100*hataliKutu/toplamKutu);
    printf("Iade edilen bilyeler = %d\n",toplamIade);
    printf("Kabul edilen bilyeler = %d\n",toplamKabul);
    printf("Tum bilyelerin esit agirlikta oldugu kutu sayisi= %d, Hatasiz kutulara gore yuzdesi= %%%.2f\n",esitSayac,(float)100*esitSayac/(toplamKutu-hataliKutu));
    printf("Farkli bilyenin daha agir oldugu kutu sayisi= %d, Hatasiz kutulara gore yuzdesi= %%%.2f\n",buyukSayac,(float)100*buyukSayac/(toplamKutu-hataliKutu));
    printf("Farkli bilyenin daha hafif oldugu kutu sayisi= %d, Hatasiz kutulara gore yuzdesi= %%%.2f\n",kucukSayac,(float)100*kucukSayac/(toplamKutu-hataliKutu));
    printf("Bir bilyenin digerlerinden daha agir oldugu deger %d yuzdesi %%%.2f\n",agirlik_farki,(float)100*agirlik_farki/toplam_agirlik);
    printf("Bir bilyenin digerlerinden daha hafif oldugu deger %d yuzdesi %%%.2f\n",agirlik_farki2,(float)100*agirlik_farki2/toplam_agirlik);
    printf("bilyelerin esit agirlikte oldugu kutular icinde bilye sayisi encok:%d kadardir o kutudaki bir bilyenin agirligi:%d\n",en_buyuk,en_buyugun_agirligi);
    printf("bilyelerin esit agirlikte oldugu kutular icinde bilye sayisi enaz:%d  kadardir  o kutudaki bir bilyenin agirligi:%d\n",en_kucuk,en_kucuk_agirligi);



    return 0;




}
