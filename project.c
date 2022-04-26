#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void original_card(int num);
void work_card(int num);
void love_card(int num);
void money_card(int num);
void health_card(int num);
int random(int numbers);
int fill(int num1, int num2, int num3, int* n1, int* n2, int* n3);

int main()
{
    char name[1024], line[1024], type[256];
    int num1, num2, num3, n1, n2, n3;
    printf("---------------------------------------------------------------------------\n");
    printf("|                  Hello, I am the great fortune teller.                  |\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Plese tell me your name : ");
    scanf("%[^\n]", name);
    printf("OK, So your name is \"%s\" \n\n", name);

    printf("Now, I will tell you your fortune.\n\n");
    printf("What do you want to know?\n");
    printf("|  Love\\ Money\\ Health\\ Work\\ Others  |\n");
    scanf("%s", type);
    for (int i = 0; i < strlen(type); i++) {
        type[i] = tolower(type[i]);
    }

    if (strcmp(type, "love") == 0) {
        printf("------------|   Love   |------------\n");
        fill(num1, num2, num3, &n1, &n2, &n3);
    
        love_card(random(n1));
        love_card(random(n2));
        love_card(random(n3));
    }
    else if (strcmp(type, "money") == 0) {
        printf("------------|   Money   |------------\n");
        fill(num1, num2, num3, &n1, &n2, &n3);
    
        money_card(random(n1));
        money_card(random(n2));
        money_card(random(n3));
    }
    else if (strcmp(type, "work") == 0) {
        printf("------------|    Work   |------------\n");
        fill(num1, num2, num3, &n1, &n2, &n3);
    
        work_card(random(n1));
        work_card(random(n2));
        work_card(random(n3));
    }
    else if (strcmp(type, "health") == 0) {
        printf("------------|   Health   |------------\n");
        fill(num1, num2, num3, &n1, &n2, &n3);
    
        health_card(random(n1));
        health_card(random(n2));
        health_card(random(n3));
    }
    else {
        printf("------------|   Others   |------------\n");
        fill(num1, num2, num3, &n1, &n2, &n3);
    
        original_card(random(n1));
        original_card(random(n2));
        original_card(random(n3));
        }
    }

int fill(int num1, int num2, int num3, int* n1, int* n2, int* n3) {
    char line[1024];
    printf("\n-|Please select a number between 0 to 21.|-\n");
    printf("------------| First number |------------\n");
    while (fgets(line, sizeof(line), stdin))
    {
        if (sscanf(line, "%i ", &num1) != 1)
        {
            fprintf(stderr, "Please enter a number.\n");
            continue;
        }

        if (num1 < 0 || 21 < num1)
        {
            fprintf(stderr, "The number must be between 0 and 21.\n");
            continue;
        }

        break;
    }

    printf("------------|Second number |------------\n");
    while (fgets(line, sizeof(line), stdin))
    {
        if (sscanf(line, "%i ", &num2) != 1)
        {
            fprintf(stderr, "Please enter a number.\n");
            continue;
        }
    
        if (num1 == num2)
        {
            fprintf(stderr, "The number can't be same as number 1\n");
            continue;
        }

        if (num2 < 0 || 21 < num2)
        {
            fprintf(stderr, "The number must be between 0 and 21.\n");
            continue;
        }

        break;
    }

    printf("------------|Third number |------------\n");
    while (fgets(line, sizeof(line), stdin))
    {
        if (sscanf(line, "%i ", &num3) != 1)
        {
            fprintf(stderr, "Please enter a number.\n");
            continue;
        }

        if (num3 == num1 || num3 == num2)
        {
            fprintf(stderr, "The number can't be same as number 1 or number 2.\n");
            continue;
        }

        if (num3 < 0 || 21 < num3)
        {
            fprintf(stderr, "The number must be between 0 and 21.\n");
            continue;
        }

        break;
    }
    printf("===========================================================================\n");
    printf("#                     So you have choosen %d, %d and %d                     #\n", num1, num2, num3);
    printf("===========================================================================\n");
    *n1 = num1;
    *n2 = num2;
    *n3 = num3;
}
int random(int numbers)
{
    int lower = 0, upper = 21;
    srand(time(NULL));
    numbers += rand();

    numbers = numbers % (upper + 1 - lower ) + lower;
}

void original_card(int num)
{
 
    if (num == 0)
    {
        printf("                        You got \"The Fool\"\n");
        printf("               mean : innocence, new beginnings, free spirit");
    }
    else if (num == 1)
    {
        printf("                        You got \"The Emperor\"\n");
        printf("               mean : authority, structure, control");
    }
    else if (num == 2)
    {
        printf("                        You got \"The Lovers\"\n");
        printf("               mean : partnerships, duality, union");
    }
    else if (num == 3)
    {
        printf("                        You got \"The Empress\"\n");
        printf("               mean : motherhood, fertility, nature");
    }
    else if (num == 4)
    {
        printf("                        You got \"The Magician\"\n");
        printf("               mean : willpower, desire, creation, manifestation");
    }
    else if (num == 5)
    {
        printf("                        You got \"Strength\"\n");
        printf("               mean : inner strength, bravery, compassion, focus");
    }
    else if (num == 6)
    {
        printf("                        You got \"The High Priestess\"\n");
        printf("               mean : intuitive, unconscious, inner voice");
    }
    else if (num == 7)
    {
        printf("                        You got \"The Wheel of Fortune\"\n");
        printf("               mean : change, cycles, inevitable fate");
    }
    else if (num == 8)
    {
        printf("                        You got \"The Hierophant\"\n");
        printf("               mean : tradition, conformity, morality, ethics");
    }
    else if (num == 9)
    {
        printf("                        You got \"Justice\"\n");
        printf("               mean : cause and effect, clarity, truth");
    }
    else if (num == 10)
    {
        printf("                        You got \"The Chariot\"\n");
        printf("               mean : direction, control, willpower");
    }
    else if (num == 11)
    {
        printf("                        You got \"The Hermit\"\n");
        printf("               mean : contemplation, search for truth, inner guidance");
    }
    else if (num == 12)
    {
        printf("                        You got \"Death\"\n");
        printf("               mean : end of cycle, beginnings, change, metamorphosis");
    }
    else if (num == 13)
    {
        printf("                        You got \"The Hanged Man\"\n");
        printf("               mean : sacrifice, release, martyrdom");
    }
    else if (num == 14)
    {
        printf("                        You got \"Temperance\"\n");
        printf("               mean : middle path, patience, finding meaning");
    }
    else if (num == 15)
    {
        printf("                        You got \"The Moon\"\n");
        printf("               mean : unconscious, illusions, intuition");
    }
    else if (num == 16)
    {
        printf("                        You got \"The Tower\"\n");
        printf("               mean : sudden upheaval, broken pride, disaster");
    }
    else if (num == 17)
    {
        printf("                        You got \"The Star\"\n");
        printf("               mean : hope, faith, rejuvenation");
    }
    else if (num == 18)
    {
        printf("                        You got \"The Devil\"\n");
        printf("               mean : addiction, materialism, playfulness");
    }
    else if (num == 19)
    {
        printf("                        You got \"The World\"\n");
        printf("               mean : fulfillment, harmony, completion");
    }
    else if (num == 20)
    {
        printf("                        You got \"Judgement\"\n");
        printf("               mean : reflection, reckoning, awakening");
    }
    else if (num == 21)
    {
        printf("                        You got \"The Sun\"\n");
        printf("               mean : joy, success, celebration, positivity");
    }
    printf("\n---------------------------------------------------------------------------\n");
}

// forcast work
void work_card(int num)
{
    printf("\n---------------------------------------------------------------------------\n");
    if (num == 0)
    {
        printf("                        You got \"The Fool\"\n");
        printf("               mean :  ");
    }
    else if (num == 1)
    {
        printf("                        You got \"The Magician\"\n");
        printf("               mean :  ");
    }
    else if (num == 2)
    {
        printf("                        You got \"The High Priestress\"\n");
        printf("               mean :  ");
    }
    else if (num == 3)
    {
        printf("                        You got \"The Empress\"\n");
        printf("               mean :  ");
    }
    else if (num == 4)
    {
        printf("                        You got \"The Emperor\"\n");
        printf("               mean :  ");
    }
    else if (num == 5)
    {
        printf("                        You got \"The Hierophant\"\n");
        printf("               mean :  ");
    }
    else if (num == 6)
    {
        printf("                        You got \"The Lover\"\n");
        printf("               mean :  ");
    }
    else if (num == 7)
    {
        printf("                        You got \"The Chariot\"\n");
        printf("               mean :  ");
    }
    else if (num == 8)
    {
        printf("                        You got \"The Strength\"\n");
        printf("               mean :  ");
    }
    else if (num == 9)
    {
        printf("                        You got \"The Hermit\"\n");
        printf("               mean :  ");
    }
    else if (num == 10)
    {
        printf("                        You got \"The Wheel of Fortune\"\n");
        printf("               mean :  ");
    }
    else if (num == 11)
    {
        printf("                        You got \"Justice\"\n");
        printf("               mean :  ");
    }
    else if (num == 12)
    {
        printf("                        You got \"The Hanged Man\"\n");
        printf("               mean :  ");
    }
    else if (num == 13)
    {
        printf("                        You got \"Death\"\n");
        printf("               mean :  ");
    }
    else if (num == 14)
    {
        printf("                        You got \"Temperance\"\n");
        printf("               mean :  ");
    }
    else if (num == 15)
    {
        printf("                        You got \"The Devil\"\n");
        printf("               mean :  ");
    }
    else if (num == 16)
    {
        printf("                        You got \"The Star\"\n");
        printf("               mean :  ");
    }
    else if (num == 17)
    {
        printf("                        You got \"The Star\"\n");
        printf("               mean :  ");
    }
    else if (num == 18)
    {
        printf("                        You got \"The Moon\"\n");
        printf("               mean :  ");
    }
    else if (num == 19)
    {
        printf("                        You got \"The Sun\"\n");
        printf("               mean :  ");
    }
    else if (num == 20)
    {
        printf("                        You got \"Judgement\"\n");
        printf("               mean :  ");
    }
    else if (num == 21)
    {
        printf("                        You got \"The world\"\n");
        printf("               mean :  ");
    }
    printf("\n---------------------------------------------------------------------------\n");
}

void money_card(int num)
{
    printf("\n---------------------------------------------------------------------------\n");
    if (num == 0)
    {
        printf("                        You got \"The Fool\"\n");
        printf("               mean :  ");
    }
    else if (num == 1)
    {
        printf("                        You got \"The Magician\"\n");
        printf("               mean :  ");
    }
    else if (num == 2)
    {
        printf("                        You got \"The High Priestress\"\n");
        printf("               mean :  ");
    }
    else if (num == 3)
    {
        printf("                        You got \"The Empress\"\n");
        printf("               mean :  ");
    }
    else if (num == 4)
    {
        printf("                        You got \"The Emperor\"\n");
        printf("               mean :  ");
    }
    else if (num == 5)
    {
        printf("                        You got \"The Hierophant\"\n");
        printf("               mean :  ");
    }
    else if (num == 6)
    {
        printf("                        You got \"The Lover\"\n");
        printf("               mean :  ");
    }
    else if (num == 7)
    {
        printf("                        You got \"The Chariot\"\n");
        printf("               mean :  ");
    }
    else if (num == 8)
    {
        printf("                        You got \"The Strength\"\n");
        printf("               mean :  ");
    }
    else if (num == 9)
    {
        printf("                        You got \"The Hermit\"\n");
        printf("               mean :  ");
    }
    else if (num == 10)
    {
        printf("                        You got \"The Wheel of Fortune\"\n");
        printf("               mean :  ");
    }
    else if (num == 11)
    {
        printf("                        You got \"Justice\"\n");
        printf("               mean :  ");
    }
    else if (num == 12)
    {
        printf("                        You got \"The Hanged Man\"\n");
        printf("               mean :  ");
    }
    else if (num == 13)
    {
        printf("                        You got \"Death\"\n");
        printf("               mean :  ");
    }
    else if (num == 14)
    {
        printf("                        You got \"Temperance\"\n");
        printf("               mean :  ");
    }
    else if (num == 15)
    {
        printf("                        You got \"The Devil\"\n");
        printf("               mean :  ");
    }
    else if (num == 16)
    {
        printf("                        You got \"The Star\"\n");
        printf("               mean :  ");
    }
    else if (num == 17)
    {
        printf("                        You got \"The Star\"\n");
        printf("               mean :  ");
    }
    else if (num == 18)
    {
        printf("                        You got \"The Moon\"\n");
        printf("               mean :  ");
    }
    else if (num == 19)
    {
        printf("                        You got \"The Sun\"\n");
        printf("               mean :  ");
    }
    else if (num == 20)
    {
        printf("                        You got \"Judgement\"\n");
        printf("               mean :  ");
    }
    else if (num == 21)
    {
        printf("                        You got \"The world\"\n");
        printf("               mean :  ");
    }
    printf("\n---------------------------------------------------------------------------\n");
}

void love_card(int num)
{
    printf("\n---------------------------------------------------------------------------\n");
    if (num == 0)
    {
        printf("                        You got \"The Fool\"\n");
        printf("               mean :  ");
    }
    else if (num == 1)
    {
        printf("                        You got \"The Magician\"\n");
        printf("               mean :  ");
    }
    else if (num == 2)
    {
        printf("                        You got \"The High Priestress\"\n");
        printf("               mean :  ");
    }
    else if (num == 3)
    {
        printf("                        You got \"The Empress\"\n");
        printf("               mean :  ");
    }
    else if (num == 4)
    {
        printf("                        You got \"The Emperor\"\n");
        printf("               mean :  ");
    }
    else if (num == 5)
    {
        printf("                        You got \"The Hierophant\"\n");
        printf("               mean :  ");
    }
    else if (num == 6)
    {
        printf("                        You got \"The Lover\"\n");
        printf("               mean :  ");
    }
    else if (num == 7)
    {
        printf("                        You got \"The Chariot\"\n");
        printf("               mean :  ");
    }
    else if (num == 8)
    {
        printf("                        You got \"The Strength\"\n");
        printf("               mean :  ");
    }
    else if (num == 9)
    {
        printf("                        You got \"The Hermit\"\n");
        printf("               mean :  ");
    }
    else if (num == 10)
    {
        printf("                        You got \"The Wheel of Fortune\"\n");
        printf("               mean :  ");
    }
    else if (num == 11)
    {
        printf("                        You got \"Justice\"\n");
        printf("               mean :  ");
    }
    else if (num == 12)
    {
        printf("                        You got \"The Hanged Man\"\n");
        printf("               mean :  ");
    }
    else if (num == 13)
    {
        printf("                        You got \"Death\"\n");
        printf("               mean :  ");
    }
    else if (num == 14)
    {
        printf("                        You got \"Temperance\"\n");
        printf("               mean :  ");
    }
    else if (num == 15)
    {
        printf("                        You got \"The Devil\"\n");
        printf("               mean :  ");
    }
    else if (num == 16)
    {
        printf("                        You got \"The Star\"\n");
        printf("               mean :  ");
    }
    else if (num == 17)
    {
        printf("                        You got \"The Star\"\n");
        printf("               mean :  ");
    }
    else if (num == 18)
    {
        printf("                        You got \"The Moon\"\n");
        printf("               mean :  ");
    }
    else if (num == 19)
    {
        printf("                        You got \"The Sun\"\n");
        printf("               mean :  ");
    }
    else if (num == 20)
    {
        printf("                        You got \"Judgement\"\n");
        printf("               mean :  ");
    }
    else if (num == 21)
    {
        printf("                        You got \"The world\"\n");
        printf("               mean :  ");
    }
    printf("\n---------------------------------------------------------------------------\n");
}

void health_card(int num)
{
    printf("\n---------------------------------------------------------------------------\n");
    if (num == 0)
    {
        printf("                        You got \"The Fool\"\n");
        printf("               mean :  ");
    }
    else if (num == 1)
    {
        printf("                        You got \"The Magician\"\n");
        printf("               mean :  ");
    }
    else if (num == 2)
    {
        printf("                        You got \"The High Priestress\"\n");
        printf("               mean :  ");
    }
    else if (num == 3)
    {
        printf("                        You got \"The Empress\"\n");
        printf("               mean :  ");
    }
    else if (num == 4)
    {
        printf("                        You got \"The Emperor\"\n");
        printf("               mean :  ");
    }
    else if (num == 5)
    {
        printf("                        You got \"The Hierophant\"\n");
        printf("               mean :  ");
    }
    else if (num == 6)
    {
        printf("                        You got \"The Lover\"\n");
        printf("               mean :  ");
    }
    else if (num == 7)
    {
        printf("                        You got \"The Chariot\"\n");
        printf("               mean :  ");
    }
    else if (num == 8)
    {
        printf("                        You got \"The Strength\"\n");
        printf("               mean :  ");
    }
    else if (num == 9)
    {
        printf("                        You got \"The Hermit\"\n");
        printf("               mean :  ");
    }
    else if (num == 10)
    {
        printf("                        You got \"The Wheel of Fortune\"\n");
        printf("               mean :  ");
    }
    else if (num == 11)
    {
        printf("                        You got \"Justice\"\n");
        printf("               mean :  ");
    }
    else if (num == 12)
    {
        printf("                        You got \"The Hanged Man\"\n");
        printf("               mean :  ");
    }
    else if (num == 13)
    {
        printf("                        You got \"Death\"\n");
        printf("               mean :  ");
    }
    else if (num == 14)
    {
        printf("                        You got \"Temperance\"\n");
        printf("               mean :  ");
    }
    else if (num == 15)
    {
        printf("                        You got \"The Devil\"\n");
        printf("               mean :  ");
    }
    else if (num == 16)
    {
        printf("                        You got \"The Star\"\n");
        printf("               mean :  ");
    }
    else if (num == 17)
    {
        printf("                        You got \"The Star\"\n");
        printf("               mean :  ");
    }
    else if (num == 18)
    {
        printf("                        You got \"The Moon\"\n");
        printf("               mean :  ");
    }
    else if (num == 19)
    {
        printf("                        You got \"The Sun\"\n");
        printf("               mean :  ");
    }
    else if (num == 20)
    {
        printf("                        You got \"Judgement\"\n");
        printf("               mean :  ");
    }
    else if (num == 21)
    {
        printf("                        You got \"The world\"\n");
        printf("               mean :  ");
    }
    printf("\n---------------------------------------------------------------------------\n");
}