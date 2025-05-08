#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int var;
    time_t czas;
    srand((unsigned int)time(&czas));
    start:
        printf("Chcesz zagrac z komputerem (0) czy zobaczy jak graja dwa komputery (1)?: ");
        scanf("%d", &var);
        switch (var){
            case 0:
                int gracz = 0, komputer = 0;
                while (1){
                    int n;
                    printf("0 = Kamien, 1 = Papier, 2 = Nozyce, 3 = Jaszczurka, 4 = Spock\n");
                    printf("Podaj ktora opcje chcesz wybrac: ");
                    scanf("%d", &n);
                    if (!(n == 0 || n == 1 || n == 2 || n == 3 || n == 4)){
                        printf("Podales nieprawidlowa opcje!\n");
                        return 1;
                    }
                    if (n == 0)    
                        printf("Wybrales kamien\n");
                    if (n == 1)
                        printf("Wybrales papier\n");
                    if (n == 2) 
                        printf("Wybrales nozyce\n");
                    if (n == 3) 
                        printf("Wybrales jaszczurke\n");
                    if (n == 4) 
                        printf("Wybrales Spocka\n");
                    int k = 0 + rand() % (4 - 0 + 1);
                    if (k == 0)    
                        printf("Komputer wybral kamien\n");
                    if (k == 1)
                        printf("Komputer wybral papier\n");
                    if (k == 2) 
                        printf("Komputer wybral nozyce\n");
                    if (k == 3) 
                        printf("Komputer wybral jaszczurke\n");
                    if (k == 4) 
                        printf("Komputer wybral Spocka\n");
                    if (n == k){
                        printf("Runda zakonczona remisem!\n");
                    }
                    if (n == 0 && (k == 2 || k == 3)){
                        printf("Wygrywasz ta runde!\n");
                        gracz++;
                    }
                    if (n == 0 && (k == 1 || k == 4)){
                        printf("Przegrywasz ta runde!\n");
                        komputer++;
                    }
                    if (n == 1 && (k == 0 || k == 4)){
                        printf("Wygrywasz ta runde!\n");
                        gracz++;
                    }
                    if (n == 1 && (k == 2 || k == 3)){
                        printf("Przegrywasz ta runde!\n");
                        komputer++;
                    }
                    if (n == 2 && (k == 1 || k == 3)){
                        printf("Wygrywasz ta runde!\n");
                        gracz++;
                    }
                    if (n == 2 && (k == 0 || k == 4)){
                        printf("Przegrywasz ta runde!\n");
                        komputer++;
                    }
                    if (n == 3 && (k == 1 || k == 4)){
                        printf("Wygrywasz ta runde!\n");
                        gracz++;
                    }
                    if (n == 3 && (k == 0 || k == 2)){
                        printf("Przegrywasz ta runde!\n");
                        komputer++;
                    }
                    if (n == 4 && (k == 0 || k == 2)){
                        printf("Wygrywasz ta runde!\n");
                        gracz++;
                    }
                    if (n == 4 && (k == 1 || k == 3)){
                        printf("Przegrywasz ta runde!\n");
                        komputer++;
                    }
                    int again0 = -1;
                    if (gracz == 3 || komputer == 3){
                            if (gracz > komputer){
                                printf("Wygrales gre %d-%d!\n", gracz, komputer);
                            }
                            else{
                                printf("Komputer wygral gre %d-%d!\n", komputer, gracz);
                            }   
                            while (1){
                                printf("Czy chcialbys zagrac ponownie?: (0 - nie, 1 - tak) ");
                                scanf("%d", &again0);
                                if (!(again0 == 0 || again0 == 1)){
                                    printf("Podales nieprawidlowa opcje! Sprobuj jeszcze raz\n");
                                    continue;
                                }
                                else{
                                    break;
                                }
                            }
                    }
                    if (again0 == 0)
                        break;
                    if (again0 == 1)
                        goto start;
                }           
                break;               
        case 1:
                int komputer1 = 0, komputer2 = 0;
                while (1){
                    int k1 = 0 + rand() % (4 - 0 + 1);
                    int k2 = 0 + rand() % (4 - 0 + 1);
                    if (k1 == 0)    
                        printf("Komputer nr 1 wybral kamien\n");
                    if (k1 == 1)
                        printf("Komputer nr 1 wybral papier\n");
                    if (k1 == 2) 
                        printf("Komputer nr 1 wybral nozyce\n");
                    if (k1 == 3) 
                        printf("Komputer nr 1 wybral jaszczurke\n");
                    if (k1 == 4) 
                        printf("Komputer nr 1 wybral Spocka\n");
                    if (k2 == 0)    
                        printf("Komputer nr 2 wybral kamien\n");
                    if (k2 == 1)
                        printf("Komputer nr 2 wybral papier\n");
                    if (k2 == 2) 
                        printf("Komputer nr 2 wybral nozyce\n");
                    if (k2 == 3) 
                        printf("Komputer nr 2 wybral jaszczurke\n");
                    if (k2 == 4) 
                        printf("Komputer nr 2 wybral Spocka\n");
                    if (k1 == k2){
                        printf("Runda zakonczona remisem!\n");
                    }
                    if (k1 == 0 && (k2 == 2 || k2 == 3)){
                        printf("Kompuer nr 1 wygral ta runde!\n");
                        komputer1++;
                    }
                    if (k1 == 0 && (k2 == 1 || k2 == 4)){
                        printf("Komputer nr 2 wygral ta runde!\n");
                        komputer2++;
                    }
                    if (k1 == 1 && (k2 == 0 || k2 == 4)){
                        printf("Komputer nr 1 wygral ta runde!\n");
                        komputer1++;
                    }
                    if (k1 == 1 && (k2 == 2 || k2 == 3)){
                        printf("Komputer nr 2 wygral ta runde!\n");
                        komputer2++;
                    }
                    if (k1 == 2 && (k2 == 1 || k2 == 3)){
                        printf("Komputer nr 1 wygral ta runde!\n");
                        komputer1++;
                    }
                    if (k1 == 2 && (k2 == 0 || k2 == 4)){
                        printf("Komputer nr 2 wygral ta runde!\n");
                        komputer2++;
                    }
                    if (k1 == 3 && (k2 == 1 || k2 == 4)){
                        printf("Komputer nr 1 wygral ta runde!\n");
                        komputer1++;
                    }
                    if (k1 == 3 && (k2 == 0 || k2 == 2)){
                        printf("Komputer nr 2 wygral ta runde!\n");
                        komputer2++;
                    }
                    if (k1 == 4 && (k2 == 0 || k2 == 2)){
                        printf("Komputer nr 1 wygral ta runde!\n");
                        komputer1++;
                    }
                    if (k1 == 4 && (k2 == 1 || k2 == 3)){
                        printf("Komputer nr 2 wygral ta runde!\n");
                        komputer2++;
                    }
                    int again1 =-1;
                    if (komputer1 == 3 || komputer2 == 3){
                            if (komputer1 > komputer2){
                                printf("Komputer nr 1 wygral gre %d-%d!\n", komputer1, komputer2);
                            }
                            else{
                                printf("Komputer nr 2 wygral gre %d-%d!\n", komputer2, komputer1);
                            }   
                            while (1){
                                printf("Czy chcialbys zagrac ponownie?: (0 - nie, 1 - tak) ");
                                scanf("%d", &again1);
                                if (!(again1 == 0 || again1 == 1)){
                                    printf("Podales nieprawidlowa opcje! Sprobuj jeszcze raz\n");
                                    continue;
                                }
                                else{
                                    break;
                                }
                            }
                    }
                    if (again1 == 0)
                        break;
                    if (again1 == 1)
                        goto start;
                }           
                break;           
        default: 
            printf("Podales nieprawidlowa opcje\n");
            return 1;
        }
    return 0;
}
