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
int fill(int num1, int num2, int num3, int *n1, int *n2, int *n3);

struct Info
{
    char name[512], type[24], repeat[10];
    int num1, num2, num3, n1, n2, n3;
};

int main()
{
    struct Info info;
    printf("---------------------------------------------------------------------------\n");
    printf("|                     Hello, I am the great horoscope.                     |\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Plese tell me your name : ");
    scanf("%[^\n]", info.name);
    printf("OK, So your name is \"%s\" \n\n", info.name);

    printf("Now, I will tell you your fortune.\n\n");

    while (1)
    {
        printf("What do you want to know?\n");
        printf("|  Love\\ Money\\ Health\\ Work\\ Others  |\n");
        scanf("%s", info.type);
        strlwr(info.type);
        if (strcmp(info.type, "love") == 0)
        {
            printf("------------|   Love   |------------\n");
            fill(info.num1, info.num2, info.num3, &info.n1, &info.n2, &info.n3);

            love_card(random(info.n1));
            love_card(random(info.n2));
            love_card(random(info.n3));
        }
        else if (strcmp(info.type, "money") == 0)
        {
            printf("------------|   Money   |------------\n");
            fill(info.num1, info.num2, info.num3, &info.n1, &info.n2, &info.n3);

            money_card(random(info.n1));
            money_card(random(info.n2));
            money_card(random(info.n3));
        }
        else if (strcmp(info.type, "work") == 0)
        {
            printf("------------|    Work   |------------\n");
            fill(info.num1, info.num2, info.num3, &info.n1, &info.n2, &info.n3);

            work_card(random(info.n1));
            work_card(random(info.n2));
            work_card(random(info.n3));
        }
        else if (strcmp(info.type, "health") == 0)
        {
            printf("------------|   Health   |------------\n");
            fill(info.num1, info.num2, info.num3, &info.n1, &info.n2, &info.n3);

            health_card(random(info.n1));
            health_card(random(info.n2));
            health_card(random(info.n3));
        }
        else
        {
            printf("------------|   Others   |------------\n");
            fill(info.num1, info.num2, info.num3, &info.n1, &info.n2, &info.n3);

            original_card(random(info.n1));
            original_card(random(info.n2));
            original_card(random(info.n3));
        }
        printf("\n===========================================================================\n");
        printf("| Do you want to see another horoscope? |\n");
        printf("[Y/N] : ");
        while (1)
        {
            scanf("%s", info.repeat);
            strlwr(info.repeat);
            if (strcmp(info.repeat, "y") == 0 || strcmp(info.repeat, "n") == 0) {
                break;
            }
            printf("Please enter [Y/N] : ");
        }
        if (strcmp(info.repeat, "n") == 0)
        {
            break;
        }
        printf("\n");
    }
}

int fill(int num1, int num2, int num3, int *n1, int *n2, int *n3)
{
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

    printf("------------| Second number |------------\n");
    printf("Please enter a number.\n");
    while (fgets(line, sizeof(line), stdin))
    {
        if (sscanf(line, "%i ", &num2) != 1)
        {
            fprintf(stderr, "Please enter a number.\n");
            continue;
        }

        if (num1 == num2)
        {
            fprintf(stderr, "The number can't be same as number 1.\n");
            continue;
        }

        if (num2 < 0 || 21 < num2)
        {
            fprintf(stderr, "The number must be between 0 and 21.\n");
            continue;
        }

        break;
    }

    printf("------------| Third number |------------\n");
    printf("Please enter a number.\n");
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

    numbers = numbers % (upper + 1 - lower) + lower;
}

void original_card(int num)
{

    if (num == 0)
    {
        printf("You got \"The Fool\"\n");
        printf("mean : innocence, new beginnings, free spirit");
    }
    else if (num == 1)
    {
        printf("You got \"The Emperor\"\n");
        printf("mean : authority, structure, control");
    }
    else if (num == 2)
    {
        printf("You got \"The Lovers\"\n");
        printf("mean : partnerships, duality, union");
    }
    else if (num == 3)
    {
        printf("You got \"The Empress\"\n");
        printf("mean : motherhood, fertility, nature");
    }
    else if (num == 4)
    {
        printf("You got \"The Magician\"\n");
        printf("mean : willpower, desire, creation, manifestation");
    }
    else if (num == 5)
    {
        printf("You got \"Strength\"\n");
        printf("mean : inner strength, bravery, compassion, focus");
    }
    else if (num == 6)
    {
        printf("You got \"The High Priestess\"\n");
        printf("mean : intuitive, unconscious, inner voice");
    }
    else if (num == 7)
    {
        printf("You got \"The Wheel of Fortune\"\n");
        printf("mean : change, cycles, inevitable fate");
    }
    else if (num == 8)
    {
        printf("You got \"The Hierophant\"\n");
        printf("mean : tradition, conformity, morality, ethics");
    }
    else if (num == 9)
    {
        printf("You got \"Justice\"\n");
        printf("mean : cause and effect, clarity, truth");
    }
    else if (num == 10)
    {
        printf("You got \"The Chariot\"\n");
        printf("mean : direction, control, willpower");
    }
    else if (num == 11)
    {
        printf("You got \"The Hermit\"\n");
        printf("mean : contemplation, search for truth, inner guidance");
    }
    else if (num == 12)
    {
        printf("You got \"Death\"\n");
        printf("mean : end of cycle, beginnings, change, metamorphosis");
    }
    else if (num == 13)
    {
        printf("You got \"The Hanged Man\"\n");
        printf("mean : sacrifice, release, martyrdom");
    }
    else if (num == 14)
    {
        printf("You got \"Temperance\"\n");
        printf("mean : middle path, patience, finding meaning");
    }
    else if (num == 15)
    {
        printf("You got \"The Moon\"\n");
        printf("mean : unconscious, illusions, intuition");
    }
    else if (num == 16)
    {
        printf("You got \"The Tower\"\n");
        printf("mean : sudden upheaval, broken pride, disaster");
    }
    else if (num == 17)
    {
        printf("You got \"The Star\"\n");
        printf("mean : hope, faith, rejuvenation");
    }
    else if (num == 18)
    {
        printf("You got \"The Devil\"\n");
        printf("mean : addiction, materialism, playfulness");
    }
    else if (num == 19)
    {
        printf("You got \"The World\"\n");
        printf("mean : fulfillment, harmony, completion");
    }
    else if (num == 20)
    {
        printf("You got \"Judgement\"\n");
        printf("mean : reflection, reckoning, awakening");
    }
    else if (num == 21)
    {
        printf("You got \"The Sun\"\n");
        printf("mean : joy, success, celebration, positivity");
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
        printf("mean : New Beginning of a new business, also meaning of boring about your job.");
    }
    else if (num == 1)
    {
        printf("You got \"The Magician\"\n");
        printf("mean : Suitable for jobs that involve many people, for example, DJ or Teacher.");
    }
    else if (num == 2)
    {
        printf("You got \"The High Priestress\"\n");
        printf("mean : Your business will be slow at first, best with artist or investigative work.");
    }
    else if (num == 3)
    {
        printf("You got \"The Empress\"\n");
        printf("mean : Suitable at decoration or electronic trading.");
    }
    else if (num == 4)
    {
        printf("You got \"The Emperor\"\n");
        printf("mean : A large corporate structure company or a job involving foreigners. will prosper in science, modern technology, politics, and governance. if there is negotiation benefit sharing will go smoothly.");
    }
    else if (num == 5)
    {
        printf("You got \"The Hierophant\"\n");
        printf("mean : You may have a fussy problem at work, or someone is fussy at you. suitable career. Often served as government officials, doctors, teachers.");
    }
    else if (num == 6)
    {
        printf("You got \"The Lover\"\n");
        printf("mean : You may have to change your jobs. You'll have a better partner or new, better path to take.");
    }
    else if (num == 7)
    {
        printf("You got \"The Chariot\"\n");
        printf("mean : Suitable for all types of transportation related tasks, steward or air hostess usually gets this card. Also have a meaning of working with foreigners so foreign language is also required.");
    }
    else if (num == 8)
    {
        printf("You got \"The Strength\"\n");
        printf("mean : You may be rewarded for success in perseverance. or work related to beauty care.");
    }
    else if (num == 9)
    {
        printf("You got \"The Hermit\"\n");
        printf("mean : The work done is suitable for long-term projects. If referring to your current jobs, It's usually better later. If referring to a career, it is suitable for doctors, teachers, writers, academics.");
    }
    else if (num == 10)
    {
        printf("You got \"The Wheel of Fortune\"\n");
        printf("mean : You aren't very satisfied with the matter of the job. You may want to make it better. Refers to working related to the house and land.");
    }
    else if (num == 11)
    {
        printf("You got \"Justice\"\n");
        printf("mean : You will receive justice from the people around you. Suitable to work on government or state enterprises.");
    }
    else if (num == 12)
    {
        printf("You got \"The Hanged Man\"\n");
        printf("mean : It is a period that requires patience with the working conditions. running business may start to show its problem. This card must be matched with jobs, doctors, nurses or people working in the illusion industry, journalists.");
    }
    else if (num == 13)
    {
        printf("You got \"Death\"\n");
        printf("mean : There may be failures, disappointments, and partnerships will break up with each other. This card is suitable for professions such as doctors, nurses, insurance, life insurance, police or military, or chemical companies.");
    }
    else if (num == 14)
    {
        printf("You got \"Temperance\"\n");
        printf("mean : You have quite a high chance that you need to relocate or leave your work. Or may have a trip to meet people to negotiate a business deal.");
    }
    else if (num == 15)
    {
        printf("You got \"The Devil\"\n");
        printf("mean : This card will give good results to those who work in all vices such as opening a casino, selling liquor, beer, opening a pub, bar, massage parlor, etc. In normal worker, there is usually a part time job coming in.");
    }
    else if (num == 16)
    {
        printf("You got \"The Star\"\n");
        printf("mean : What you thought it was going well will unexpectedly collapse. Problems often arise suddenly and unexpectedly.");
    }
    else if (num == 17)
    {
        printf("You got \"The Star\"\n");
        printf("mean : You need to continue to improve yourself. Work related to beauty, art will be very good, including construction of houses. building materials or home decorations.");
    }
    else if (num == 18)
    {
        printf("You got \"The Moon\"\n");
        printf("mean : You need control over your emotions. Someone may be harassing you at work. Be careful about document issues.");
    }
    else if (num == 19)
    {
        printf("You got \"The Sun\"\n");
        printf("mean : You will get a new job if you are unemployed. Personal business will be streamlined, working with older people will go smoothly.");
    }
    else if (num == 20)
    {
        printf("You got \"Judgement\"\n");
        printf("mean : If you just quit your job, you'll get a new job in no time. Those new jobs often come from your friend's advice.");
    }
    else if (num == 21)
    {
        printf("You got \"The world\"\n");
        printf("mean : Your work that has been done for a long time will be successful as expected, especially in the field of artwork. Land brokers are also good as well.");
    }
    printf("\n---------------------------------------------------------------------------\n");
}

void money_card(int num)
{
    printf("\n---------------------------------------------------------------------------\n");
    if (num == 0)
    {
        printf("You got \"The Fool\"\n");
        printf("mean : Your finances will be unstable.");
    }
    else if (num == 1)
    {
        printf("You got \"The Magician\"\n");
        printf("mean : Your financial condition will be better.");
    }
    else if (num == 2)
    {
        printf("You got \"The High Priestress\"\n");
        printf("mean : Your financial condition will be slow.");
    }
    else if (num == 3)
    {
        printf("You got \"The Empress\"\n");
        printf("mean : You are guaranteed to have Income, but it will be slow.");
    }
    else if (num == 4)
    {
        printf("You got \"The Emperor\"\n");
        printf("mean : Be careful, you are probably going to spend extravagantly. You are probably Running out of money so often but that money will be obtained in a timely manner.");
    }
    else if (num == 5)
    {
        printf("You got \"The Hierophant\"\n");
        printf("mean : You'll be making a new financial plan, but don't be so strict. All your savings will be gone if you can't hold back.");
    }
    else if (num == 6)
    {
        printf("You got \"The Lover\"\n");
        printf("mean : You will earn income easily.");
    }
    else if (num == 7)
    {
        printf("You got \"The Chariot\"\n");
        printf("mean : You must face financial problems, but all the problems can be passed. need to be conflicting to get that money.");
    }
    else if (num == 8)
    {
        printf("You got \"The Strength\"\n");
        printf("mean : The expected money will come. All financial difficulties will be resolved.");
    }
    else if (num == 9)
    {
        printf("You got \"The Hermit\"\n");
        printf("mean : Money will keep coming in and out.");
    }
    else if (num == 10)
    {
        printf("You got \"The Wheel of Fortune\"\n");
        printf("mean : There will be enough money to spend, so you don't have to worry about it too much.");
    }
    else if (num == 11)
    {
        printf("You got \"Justice\"\n");
        printf("mean : The financial situation is fast paced.");
    }
    else if (num == 12)
    {
        printf("You got \"The Hanged Man\"\n");
        printf("mean : You will have financial problems. Someone will come to take advantage of your money. People who are in debt tend to mostly get this card. So better be careful of guarantees.");
    }
    else if (num == 13)
    {
        printf("You got \"Death\"\n");
        printf("mean : Your Earnings are very bad. Income has dropped significantly. Be careful, your money can be lost or looted.");
    }
    else if (num == 14)
    {
        printf("You got \"Temperance\"\n");
        printf("mean : You're going to have a lot of money management during this period.");
    }
    else if (num == 15)
    {
        printf("You got \"The Devil\"\n");
        printf("mean : You may have very hard work. If you are running your own business, it will get very little profit.");
    }
    else if (num == 16)
    {
        printf("You got \"The Star\"\n");
        printf("mean : You may lose a large amount of money.");
    }
    else if (num == 17)
    {
        printf("You got \"The Star\"\n");
        printf("mean : Predicting anything about finances is often as expected.");
    }
    else if (num == 18)
    {
        printf("You got \"The Moon\"\n");
        printf("mean : Be careful, someone may be cheated on your money to take advantage. Be careful with the documentation.");
    }
    else if (num == 19)
    {
        printf("You got \"The Sun\"\n");
        printf("mean : If you are waiting for any news, you will receive good news, usually having a reputation for working first. The money will be received later.");
    }
    else if (num == 20)
    {
        printf("You got \"Judgement\"\n");
        printf("mean : Your financial matters began to change for the better. Your investment will get a pretty good return.");
    }
    else if (num == 21)
    {
        printf("You got \"The world\"\n");
        printf("mean : That money will come in many ways, mostly from what you have been doing for a long time.");
    }
    printf("\n---------------------------------------------------------------------------\n");
}

void love_card(int num)
{
    printf("\n---------------------------------------------------------------------------\n");
    if (num == 0)
    {
        printf("You got \"The Fool\"\n");
        printf("mean : You are flirtatious.");
    }
    else if (num == 1)
    {
        printf("You got \"The Magician\"\n");
        printf("mean : Your loved one will come for you in the time You didn't need them, you have no luck on love.");
    }
    else if (num == 2)
    {
        printf("You got \"The High Priestress\"\n");
        printf("mean : You will find the charming one, he/she may be one side love or flirtatious one.");
    }
    else if (num == 3)
    {
        printf("You got \"The Empress\"\n");
        printf("mean : You will have fulfilled one's hope and may end up with marriage with your loved one, also meaning of pregnancy or jealousy.");
    }
    else if (num == 4)
    {
        printf("You got \"The Emperor\"\n");
        printf("mean : Love means meeting soulmates. or feel missing your loved one.");
    }
    else if (num == 5)
    {
        printf("You got \"The Hierophant\"\n");
        printf("mean : If you are a woman, it means your marriage will come a long time soon or you're going to marry a much older couple and they will perform the ceremony properly according to tradition if they are married.");
    }
    else if (num == 6)
    {
        printf("You got \"The Lover\"\n");
        printf("mean : If you are a woman, it means your marriage will come a long time soon or you're going to marry a much older couple and they will perform the ceremony properly according to tradition if they are married.");
    }
    else if (num == 7)
    {
        printf("You got \"The Chariot\"\n");
        printf("mean : If you are single, you may find love with strangers. People who are in love may have problems that need to separate for a while and reconcile.");
    }
    else if (num == 8)
    {
        printf("You got \"The Strength\"\n");
        printf("mean : If you just met someone you love, time will help strengthen your love. If you haven't found your love yet, you are not ready to love someone because of your past.");
    }
    else if (num == 9)
    {
        printf("You got \"The Hermit\"\n");
        printf("mean : Money will keep coming in and out.");
    }
    else if (num == 10)
    {
        printf("You got \"The Wheel of Fortune\"\n");
        printf("mean : If there is already a relationship, it means that they are comfortable and not jealous of each other. and may have an ex-lover come back into your life again. If you are single, it is more likely that you will meet someone among the masses.");
    }
    else if (num == 11)
    {
        printf("You got \"Justice\"\n");
        printf("mean : If the opposite sex is courting and has a crush on you. You must be very careful; they'll just stick around with you for a while and then leave.");
    }
    else if (num == 12)
    {
        printf("You got \"The Hanged Man\"\n");
        printf("mean : If you're single, it means you are seeking for love. You are a sensitive one so if you just started dating relentlessly, don't direct all of your feelings to your loved one just yet.");
    }
    else if (num == 13)
    {
        printf("You got \"Death\"\n");
        printf("mean : If there are lovers, there will be problems and may lead to break up. If you are singles, it means that you will meet someone who is very attractive.");
    }
    else if (num == 14)
    {
        printf("You got \"Temperance\"\n");
        printf("mean : If you are having problems with your lover, you may want to break up. The breakup one will come back to you, or single people or friends may recommend someone to you.");
    }
    else if (num == 15)
    {
        printf("You got \"The Devil\"\n");
        printf("mean : There will be an irresistible attraction between each other. After the strong desire has passed, they may find out that they have nothing the same as each other, causing them to break up.");
    }
    else if (num == 16)
    {
        printf("You got \"The Star\"\n");
        printf("mean : You may be heartbroken, or divorce. If you're single and you have another good love meaning's card next to it, it means you'll find love suddenly.");
    }
    else if (num == 17)
    {
        printf("You got \"The Star\"\n");
        printf("mean : Most of those who got this card were usually single. spending most of their time with their friends.");
    }
    else if (num == 18)
    {
        printf("You got \"The Moon\"\n");
        printf("mean : If you have a lover, you may be deceived by lovers. If you are single, it means you are starving for love.");
    }
    else if (num == 19)
    {
        printf("You got \"The Sun\"\n");
        printf("mean : You will have a good partner and help promote each other to prosper. If there is no lover yet, it is slow but sure there will be one to come for you.");
    }
    else if (num == 20)
    {
        printf("You got \"Judgement\"\n");
        printf("mean : Love is meant to be a decision, because your old lover has returned.");
    }
    else if (num == 21)
    {
        printf("You got \"The world\"\n");
        printf("mean : If you have Empress and The Sun cards together means you are going to having children.");
    }
    printf("\n---------------------------------------------------------------------------\n");
}

void health_card(int num)
{
    printf("\n---------------------------------------------------------------------------\n");
    if (num == 0)
    {
        printf("You got \"The Fool\"\n");
        printf("mean : You will have problems with your respiratory system and will have peripheral neuropathy.");
    }
    else if (num == 1)
    {
        printf("You got \"The Magician\"\n");
        printf("mean : You will have problems with your respiratory system and will have peripheral neuropathy.");
    }
    else if (num == 2)
    {
        printf("You got \"The High Priestress\"\n");
        printf("mean : You will have problems with your digestive system and urinary system.");
    }
    else if (num == 3)
    {
        printf("You got \"The Empress\"\n");
        printf("mean : You will have problems with your reproductive system.");
    }
    else if (num == 4)
    {
        printf("You got \"The Emperor\"\n");
        printf("mean : You will have problems with your head, headache for example.");
    }
    else if (num == 5)
    {
        printf("You got \"The Hierophant\"\n");
        printf("mean : You will have problems with your digestive system like flatulence and indigestion.");
    }
    else if (num == 6)
    {
        printf("You got \"The Lover\"\n");
        printf("mean : Do beware of colic.");
    }
    else if (num == 7)
    {
        printf("You got \"The Chariot\"\n");
        printf("mean : You may have problems often related to the digestive system.");
    }
    else if (num == 8)
    {
        printf("You got \"The Strength\"\n");
        printf("mean : You are perfectly healthy, or you will be recovering from discomfort.");
    }
    else if (num == 9)
    {
        printf("You got \"The Hermit\"\n");
        printf("mean : You may have problems with depression.");
    }
    else if (num == 10)
    {
        printf("You got \"The Wheel of Fortune\"\n");
        printf("mean : Watch out for stomach disease like stomach, liver or kidney.");
    }
    else if (num == 11)
    {
        printf("You got \"Justice\"\n");
        printf("mean : You mostly have no problem with your health.");
    }
    else if (num == 12)
    {
        printf("You got \"The Hanged Man\"\n");
        printf("mean : You may have a problem with diabetes. In women, be careful about the uterus.");
    }
    else if (num == 13)
    {
        printf("You got \"Death\"\n");
        printf("mean : You may get suddenly Severely ill and have to go to the hospital.");
    }
    else if (num == 14)
    {
        printf("You got \"Temperance\"\n");
        printf("mean : You may be physically weak due to work without a break.");
    }
    else if (num == 15)
    {
        printf("You got \"The Devil\"\n");
        printf("mean : There is a chance that it is related to a sexually transmitted disease.");
    }
    else if (num == 16)
    {
        printf("You got \"The Star\"\n");
        printf("mean : Beware of sudden illnesses or accidents.");
    }
    else if (num == 17)
    {
        printf("You got \"The Star\"\n");
        printf("mean : Good news! It usually means that you are going to recover from an illness.");
    }
    else if (num == 18)
    {
        printf("You got \"The Moon\"\n");
        printf("mean : You may have problems with the blood system, lymphatic system and the uterus.");
    }
    else if (num == 19)
    {
        printf("You got \"The Sun\"\n");
        printf("mean : You are healthy but better be careful about blood pressure for sure.");
    }
    else if (num == 20)
    {
        printf("You got \"Judgement\"\n");
        printf("mean : Your sickness often recovers, but if you are going to get sick, you often are going to have the same disease that you used to have.");
    }
    else if (num == 21)
    {
        printf("You got \"The world\"\n");
        printf("mean : You are healthy, no problems at all.");
    }
    printf("\n---------------------------------------------------------------------------\n");
}