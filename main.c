/*

Usar de preferencia el compilador gcc de mingw-64

Proyecto de Fundamentos de la Programacion

Jose Angel Preciado Delgadillo
Baruc Shemuel Gutierrez Fuentes
Juan Pablo Sandoval Lias
Fernando Martinez Rios

*/


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define THM "\e[48;2;19;0;44m\e[38;2;0;255;237m"
#define LED "\e[48;2;36;;m\e[38;2;237;255;m"
#define REG "\e[48;2;19;0;44m\e[38;2;255;;146m"
#define PLY "\e[48;2;13;58;36m\e[38;2;;255;55m"
#define RST "\e[m"

int gamestate = 0, player_num = 0, player, tmp = 100, in_points, repeated, num, theme = 1, idx;
int run = 1;
char str[50][100], abc[26];
int ldb[50];
char ans[50];
int menuopt, regopt, x;
int pasp_num[4];

char allq[2][11][200] = 
{{
"Soy un animal chico con una armadura natural, Cuando me siento en peligro, en una bola me hago total",
"De noche cazador soy con ojos bien abiertos, Mi vuelo es tan silencioso que no deja ni eco",
"Con crines al viento y patas de velocidad, He sido companero del hombre en toda la humanidad",
"Jugueton y saltarin en el agua vivo yo, Con silbidos y sonidos, a mis amigos llamo sin pudor",
"Soy gigante y tengo memoria prodigiosa, Con mi trompa tan versatil, ninguna tarea es tediosa",
"Mi plumaje rosa en el agua destaca, Con una pata en pie, en fila perfecta me hallas",
"Independiente y curioso, en la noche me veras, Con agilidad y sigilo, a los ratones cazaras",
"Aunque muy chica soy, muy trabajadora tambien, En colonias organizadas, mi fuerza te sorprendera bien",
"Con aspecto prehistorico y capacidad de camuflar, En climas calidos, al sol me encontraras",
"En la selva tropical soy un cazador astuto, Con pelaje manchado y habilidad para nadar, no me discuto"
}, {
"En Europa estoy situado, Por autos y cerveza soy destacado. Berlin es mi capital, Quien soy, cual es mi pais genial?",
"Soy el pais del carnaval, Con Rio de Janeiro y su festival. En Sudamerica me hallaras, Adivina quien soy, si puedes mas?",
"Con la Gran Muralla me reconoceras, Mi poblacion es la mayor, si no lo sabras. En Asia soy un gigante, Cual es mi nombre, acertante?",
"En el norte de Europa me encontraras, Con muchos cuentos de hadas me asociaras. Copenhague es mi ciudad central, Puedes decir mi nombre total?",
"Soy el hogar del flamenco y la paella, Con corridas de toros y Gaudi en su huella. Mi idioma se habla mundial, Cual es mi nombre internacional?",
"Con la Torre Eiffel mi ciudad brilla, El vino y el queso son mi maravilla. Paris es mi corazon, Sabes mi nombre, con razon?",
"Soy el pais de los dioses y mitos, Atenas es mi ciudad de hitos. En el mar Egeo me hallaras, Adivina mi nombre sin mas",
"Con Budapest y su rio Danubio, Soy conocido por mi goulash Fy rubio. En Europa Central yo estoy, quien soy yo, adivina, voy?",
"Mi forma es de una bota, Con Roma y su historia que flota. El arte y la moda son mi plan, Cual es mi pais, adivinaras tal vez tan?",
"Con samurais y tecnologia sin par, Tokio es mi ciudad que brilla sin parar. En Asia soy una isla nacion, quien soy yo, en esta ocasion?"
}},

allr[2][11][20] = 
{{
"ARMADILLO",
"BUHO",
"CABALLO",
"DELFIN",
"ELEFANTE",
"FLAMENCO",
"GATO",
"HORMIGA",
"IGUANA",
"JAGUAR"
},{
"ALEMANIA",
"BRASIL",
"CHINA",
"DINAMARCA",
"ESPANA",
"FRANCIA",
"GRECIA",
"HUNGRIA",
"ITALIA",
"JAPON"
}};


void fill_arr(){
    for(int i = 'A'; i <= 'J'; i++){
        abc[i-65] = i;
        //printf("\n%c",abc[i-65]);
    }

}

void dump_old_q(){
    for(int j = 0; j < 3; j++){
        pasp_num[j] = 0;
    }
}

void get_str(){
    system("cls");
    printf(REG
" ______   _______ _______ ___ _______ _______ ______   _______ \n"
"|    _ | |       |       |   |       |       |    _ | |       |\n"
"|   | || |    ___|    ___|   |  _____|_     _|   | || |   _   |\n"
"|   |_||_|   |___|   | __|   | |_____  |   | |   |_||_|  | |  |\n"
"|    __  |    ___|   ||  |   |_____  | |   | |    __  |  |_|  |\n"
"|   |  | |   |___|   |_| |   |_____| | |   | |   |  | |       |\n"
"|___|  |_|_______|_______|___|_______| |___| |___|  |_|_______|\n");
    printf("\nEscribe tu nombre, jugador %d: ",player_num+1);
    //printf("\nEspacio %d: ",player_num);
    //printf("\nis equal: %d",strcmp(str[num],str[i]));
    fgets(str[player_num],sizeof(str[player_num]),stdin);
    //printf("\nHello %s",str[player_num]);
    fflush(stdin);
    str[player_num][strcspn(str[player_num], "\n")] = 0;
    for(int i = 0; i < player_num;i++){
        if (strcmp(str[i],str[player_num]) == 0){
            printf("Este nombre ya existe\n");
            repeated = 1;
            //str[player_num] = "";
            //player_num--;
        }
    
    }
    if(repeated == 1){
        repeated = 0;
        system("pause");
        gamestate = 3;
    }else{
        player_num++;
        ldb[player_num] = 0;
    }
    system("pause");
    gamestate = 1;
}

void get_theme(){
    system("cls");
    printf(PLY
" _______ _______ _______ _______ _______ _______ ___     _______ _______ ______   _______ \n"
"|       |   _   |       |   _   |       |   _   |   |   |   _   |  _    |    _ | |   _   |\n"
"|    _  |  |_|  |  _____|  |_|  |    _  |  |_|  |   |   |  |_|  | |_|   |   | || |  |_|  |\n"
"|   |_| |       | |_____|       |   |_| |       |   |   |       |       |   |_||_|       |\n"
"|    ___|       |_____  |       |    ___|       |   |___|       |  _   ||    __  |       |\n"
"|   |   |   _   |_____| |   _   |   |   |   _   |       |   _   | |_|   |   |  | |   _   |\n"
"|___|   |__| |__|_______|__| |__|___|   |__| |__|_______|__| |__|_______|___|  |_|__| |__|\n");
    printf("1. Animales\n2. Paises\n");
    printf("Escribe el tema de tu preferencia: ");
    scanf("%d",&theme);
    if(theme < 0 || theme > 2){
        printf("Ese no es un tema disponible");
        system("pause");
        get_theme();
    }else{
        gamestate = 4;
    }
}

void select_play(){
    system("cls");
    printf(LED
"     ___ __   __ _______ _______ ______  _______ ______   _______ _______ \n"
"    |   |  | |  |       |   _   |      ||       |    _ | |       |       |\n"
"    |   |  | |  |    ___|  |_|  |  _    |   _   |   | || |    ___|  _____|\n"
"    |   |  |_|  |   | __|       | | |   |  | |  |   |_||_|   |___| |_____ \n"
" ___|   |       |   ||  |       | |_|   |  |_|  |    __  |    ___|_____  |\n"
"|       |       |   |_| |   _   |       |       |   |  | |   |___ _____| |\n"
"|_______|_______|_______|__| |__|______||_______|___|  |_|_______|_______|\n"
);
    for(int i = 0; i < player_num;i++) printf("\nJugador %d: %s tiene %d puntos\n",i+1,str[i],ldb[i]);
    printf("Escribe el numero de tu jugador: ");
    scanf("%d",&player);

    if (strcmp(str[player-1],"") == 0){
        printf("Este jugador no esta registrado, registra uno\n");
        system("pause");
        gamestate = 0;
    }else{gamestate = 6;}
}

void play(){
    printf("Reglas:\n1. Se te haran acertijos desde la A hasta la Z\n2. Tendras 3 comodines o pasapalabras, para hacerlo valido, no escribas nada\n3.Cada pasapalabras te dara otra oportunidad al final de las preguntas\n\n");
    system("pause");
    for(int i = -1;i < 10; i++){
        system("cls");
        printf(PLY
" _______ _______ _______ _______ _______ _______ ___     _______ _______ ______   _______ \n"
"|       |   _   |       |   _   |       |   _   |   |   |   _   |  _    |    _ | |   _   |\n"
"|    _  |  |_|  |  _____|  |_|  |    _  |  |_|  |   |   |  |_|  | |_|   |   | || |  |_|  |\n"
"|   |_| |       | |_____|       |   |_| |       |   |   |       |       |   |_||_|       |\n"
"|    ___|       |_____  |       |    ___|       |   |___|       |  _   ||    __  |       |\n"
"|   |   |   _   |_____| |   _   |   |   |   _   |       |   _   | |_|   |   |  | |   _   |\n"
"|___|   |__| |__|_______|__| |__|___|   |__| |__|_______|__| |__|_______|___|  |_|__| |__|\n");
        printf("Letra: %c\n%s ",abc[i],allq[theme-1][i]);
        printf("\nEscribe tu respuesta: ");
        //printf("\nis equal: %d",strcmp(str[num],str[i]));
        fgets(ans,sizeof(ans),stdin);
        //printf("\nHello %s",str[player_num]);
        fflush(stdin);
        ans[strcspn(ans, "\n")] = 0;
        ans[strcspn(ans, " ")] = 0;
        for (int j = 0;j < strlen(ans);j++){
            ans[j] = toupper(ans[j]);
        }
        printf("%s",ans);
        if(strcmp(ans,allr[theme-1][i]) == 0 && i >= 0){
            in_points += 15;
        }else if(strcmp(ans,"") == 0 && idx < 4){
            pasp_num[idx] = i;
            printf("index = %d, num = %d",idx,i);
            in_points -= 2;
            //system("pause");
            idx++;
        }
        //system("pause");
    }
    for(int k = 1; k < 4; k++){
        if(pasp_num[k] == 0) continue;
        else{
        system("cls");
        printf(PLY
" _______ _______ _______ _______ _______ _______ ___     _______ _______ ______   _______ \n"
"|       |   _   |       |   _   |       |   _   |   |   |   _   |  _    |    _ | |   _   |\n"
"|    _  |  |_|  |  _____|  |_|  |    _  |  |_|  |   |   |  |_|  | |_|   |   | || |  |_|  |\n"
"|   |_| |       | |_____|       |   |_| |       |   |   |       |       |   |_||_|       |\n"
"|    ___|       |_____  |       |    ___|       |   |___|       |  _   ||    __  |       |\n"
"|   |   |   _   |_____| |   _   |   |   |   _   |       |   _   | |_|   |   |  | |   _   |\n"
"|___|   |__| |__|_______|__| |__|___|   |__| |__|_______|__| |__|_______|___|  |_|__| |__|\n");
        printf("Aqui no hay pasapalabras, es la recta final\n");
        printf("Letra: %c\n%s ",abc[pasp_num[k]],allq[theme-1][pasp_num[k]]);
        printf("\nEscribe tu respuesta: ");
        //printf("\nis equal: %d",strcmp(str[num],str[i]));
        fgets(ans,sizeof(ans),stdin);
        //printf("\nHello %s",str[player_num]);
        fflush(stdin);
        ans[strcspn(ans, "\n")] = 0;
        ans[strcspn(ans, " ")] = 0;
        for (int j = 0;j < strlen(ans);j++){
            ans[j] = toupper(ans[j]);
        }
        printf("%s",ans);
        if(strcmp(ans,allr[theme-1][k]) == 0 && k >= 0){
            in_points += 15;
            }
        }
    }
    if(in_points == 150 && idx == 0) in_points *= 2;
    if(in_points == 150 && idx >= 0) in_points += 30;
    if (in_points > ldb[player-1]) ldb[player-1] = in_points;
    printf("\nSu puntuacion final fue: %d\n",ldb[player-1]);
    system("pause");
    in_points = 0;
    idx = 0;
    dump_old_q();
    gamestate = 0;
}

void bubble(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        for (int i = 0; i < size - step - 1; i++) {
            if (array[i] > array[i + 1]) {
            int temp = array[i];
            char temp2[100];
            strcpy(temp2,str[i]);
            strcpy(str[i],str[i+1]);
            strcpy(str[i+1],temp2); 
            array[i] = array[i + 1];
            array[i + 1] = temp;
      }
    }
  }
}

void lead(){
    system("cls");
    printf(LED
" _______ __   __ __    _ _______ _______ _______ \n"
"|       |  | |  |  |  | |       |       |       |\n"
"|    _  |  | |  |   |_| |_     _|   _   |  _____|\n"
"|   |_| |  |_|  |       | |   | |  | |  | |_____ \n"
"|    ___|       |  _    | |   | |  |_|  |_____  |\n"
"|   |   |       | | |   | |   | |       |_____| |\n"
"|___|   |_______|_|  |__| |___| |_______|_______|\n"
);
    bubble(ldb,player_num);
    printf("\n\n");
    for(int k = player_num - 1; k >= 0; k--){
        printf(" %d | %s tiene %d puntos\n",player_num - k,str[k],ldb[k]);
    }

    system("pause");
    tmp = 100;
    gamestate = 0;
}


void menu(){
    system("cls");
    printf(THM
" _______ _______ _______ _______ _______ _______ ___     _______ _______ ______   _______ \n"
"|       |   _   |       |   _   |       |   _   |   |   |   _   |  _    |    _ | |   _   |\n"
"|    _  |  |_|  |  _____|  |_|  |    _  |  |_|  |   |   |  |_|  | |_|   |   | || |  |_|  |\n"
"|   |_| |       | |_____|       |   |_| |       |   |   |       |       |   |_||_|       |\n"
"|    ___|       |_____  |       |    ___|       |   |___|       |  _   ||    __  |       |\n"
"|   |   |   _   |_____| |   _   |   |   |   _   |       |   _   | |_|   |   |  | |   _   |\n"
"|___|   |__| |__|_______|__| |__|___|   |__| |__|_______|__| |__|_______|___|  |_|__| |__|\n");
    printf("\n1. Registrar Jugadores\n2. Clasificacion\n3. Jugar\n4. Salir");
    printf("\nSelecciona una opcion: ");
    scanf("%d",&menuopt);
    fflush(stdin);
    switch (menuopt){
        case 1: gamestate = 1; break;
        case 2: gamestate = 2; break;
        case 3: gamestate = 5; break;
        case 4: printf("Buen dia\n"); system("pause"); run = 0; break;
        default: menu();
    }
}

void regist(){
    system("cls");
    printf(REG
" ______   _______ _______ ___ _______ _______ ______   _______ \n"
"|    _ | |       |       |   |       |       |    _ | |       |\n"
"|   | || |    ___|    ___|   |  _____|_     _|   | || |   _   |\n"
"|   |_||_|   |___|   | __|   | |_____  |   | |   |_||_|  | |  |\n"
"|    __  |    ___|   ||  |   |_____  | |   | |    __  |  |_|  |\n"
"|   |  | |   |___|   |_| |   |_____| | |   | |   |  | |       |\n"
"|___|  |_|_______|_______|___|_______| |___| |___|  |_|_______|\n");
    printf("\n1. Registrar Jugadores\n2. Salir");
    printf("\nSelecciona una opcion: ");
    scanf("%d",&regopt);
    fflush(stdin);
    switch (regopt){
        case 1: gamestate = 3; break;
        case 2: gamestate = 0; break;
        default: regist();
    }
}


void game(){
    switch (gamestate){
        case 0: menu(); break;
        case 1: regist(); break;
        case 2: lead(); break;
        case 3: get_str(); break;
        case 4: play(); break;
        case 5: select_play(); break;
        case 6: get_theme(); break;
        default: menu();
    }
}

void main(){
    fill_arr();
    dump_old_q();
    //system("pause");
    while(run){game();}
    printf(RST);
}