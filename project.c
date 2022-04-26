#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void original_card(int num);
void word_card(int num);
int random(int numbers);

int main()
{
    char name[1024], line[1024];
    int num1, num2, num3;
    printf("---------------------------------------------------------------------------\n");
    printf("|                  Hello, I am the great fortune teller.                  |\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Plese tell me your name : ");
    scanf("%[^\n]", name);
    printf("OK, So your name is \"%s\" \n\n", name);

    printf("Now, I will tell you your fortune.\n");
    printf("\n");
    printf("Please enter a number between 0 to 21.\n");
    printf("|   First number   |\n");
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

    printf("|   Second number   |\n");
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

    printf("|   Third number   |\n");
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

    printf("---------------------------------------------------------------------------\n");
    printf("|                    So you have choosen %d, %d and %d                     |\n", num1, num2, num3);
    printf("---------------------------------------------------------------------------\n");

    // printf("%d %d %d", random(num1), random(num2), random(num3));
    original_card(random(num1));
    original_card(random(num2));
    original_card(random(num3));
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
    printf("\n---------------------------------------------------------------------------\n");
    if (num == 0)
    {
        printf("You got \"The Fool\"\n");
        printf("mean : innocence, new beginnings, free spirit");
    }
    else if (num == 1)
    {
        printf("You got \"The Emperor\"\n");
        printf("authority, structure, control");
    }
    else if (num == 2)
    {
        printf("You got \"The Lovers\"\n");
        printf("partnerships, duality, union");
    }
    else if (num == 3)
    {
        printf("You got \"The Empress\"\n");
        printf("motherhood, fertility, nature");
    }
    else if (num == 4)
    {
        printf("You got \"The Magician\"\n");
        printf("willpower, desire, creation, manifestation");
    }
    else if (num == 5)
    {
        printf("You got \"Strength\"\n");
        printf("inner strength, bravery, compassion, focus");
    }
    else if (num == 6)
    {
        printf("You got \"The High Priestess\"\n");
        printf("intuitive, unconscious, inner voice");
    }
    else if (num == 7)
    {
        printf("You got \"The Wheel of Fortune\"\n");
        printf("change, cycles, inevitable fate");
    }
    else if (num == 8)
    {
        printf("You got \"The Hierophant\"\n");
        printf("tradition, conformity, morality, ethics");
    }
    else if (num == 9)
    {
        printf("You got \"Justice\"\n");
        printf("cause and effect, clarity, truth");
    }
    else if (num == 10)
    {
        printf("You got \"The Chariot\"\n");
        printf("direction, control, willpower");
    }
    else if (num == 11)
    {
        printf("You got \"The Hermit\"\n");
        printf("contemplation, search for truth, inner guidance");
    }
    else if (num == 12)
    {
        printf("You got \"Death\"\n");
        printf("end of cycle, beginnings, change, metamorphosis");
    }
    else if (num == 13)
    {
        printf("You got \"The Hanged Man\"\n");
        printf("sacrifice, release, martyrdom");
    }
    else if (num == 14)
    {
        printf("You got \"Temperance\"\n");
        printf("middle path, patience, finding meaning");
    }
    else if (num == 15)
    {
        printf("You got \"The Moon\"\n");
        printf("unconscious, illusions, intuition");
    }
    else if (num == 16)
    {
        printf("You got \"The Tower\"\n");
        printf("sudden upheaval, broken pride, disaster");
    }
    else if (num == 17)
    {
        printf("You got \"The Star\"\n");
        printf("hope, faith, rejuvenation");
    }
    else if (num == 18)
    {
        printf("You got \"The Devil\"\n");
        printf("addiction, materialism, playfulness");
    }
    else if (num == 19)
    {
        printf("You got \"The World\"\n");
        printf("fulfillment, harmony, completion");
    }
    else if (num == 20)
    {
        printf("You got \"Judgement\"\n");
        printf("reflection, reckoning, awakening");
    }
    else if (num == 21)
    {
        printf("You got \"The Sun\"\n");
        printf("joy, success, celebration, positivity");
    }
    printf("\n---------------------------------------------------------------------------\n");
}

// forcast work
void work_card(int num)
{
    printf("\n---------------------------------------------------------------------------\n");
    if (num == 0)
    {
        printf("You got \"The Fool\"\n");
        printf(" ");
    }
    else if (num == 1)
    {
        printf("You got \"The Magician\"\n");
        printf(" ");
    }
    else if (num == 2)
    {
        printf("You got \"The High Priestress\"\n");
        printf(" ");
    }
    else if (num == 3)
    {
        printf("You got \"The Empress\"\n");
        printf(" ");
    }
    else if (num == 4)
    {
        printf("You got \"The Emperor\"\n");
        printf(" ");
    }
    else if (num == 5)
    {
        printf("You got \"The Hierophant\"\n");
        printf(" ");
    }
    else if (num == 6)
    {
        printf("You got \"The Lover\"\n");
        printf(" ");
    }
    else if (num == 7)
    {
        printf("You got \"The Chariot\"\n");
        printf(" ");
    }
    else if (num == 8)
    {
        printf("You got \"The Strength\"\n");
        printf(" ");
    }
    else if (num == 9)
    {
        printf("You got \"The Hermit\"\n");
        printf(" ");
    }
    else if (num == 10)
    {
        printf("You got \"The Wheel of Fortune\"\n");
        printf(" ");
    }
    else if (num == 11)
    {
        printf("You got \"Justice\"\n");
        printf(" ");
    }
    else if (num == 12)
    {
        printf("You got \"The Hanged Man\"\n");
        printf(" ");
    }
    else if (num == 13)
    {
        printf("You got \"Death\"\n");
        printf(" ");
    }
    else if (num == 14)
    {
        printf("You got \"Temperance\"\n");
        printf(" ");
    }
    else if (num == 15)
    {
        printf("You got \"The Devil\"\n");
        printf(" ");
    }
    else if (num == 16)
    {
        printf("You got \"The Star\"\n");
        printf(" ");
    }
    else if (num == 17)
    {
        printf("You got \"The Star\"\n");
        printf(" ");
    }
    else if (num == 18)
    {
        printf("You got \"The Moon\"\n");
        printf(" ");
    }
    else if (num == 19)
    {
        printf("You got \"The Sun\"\n");
        printf(" ");
    }
    else if (num == 20)
    {
        printf("You got \"Judgement\"\n");
        printf(" ");
    }
    else if (num == 21)
    {
        printf("You got \"The world\"\n");
        printf(" ");
    }
    printf("\n---------------------------------------------------------------------------\n");
}