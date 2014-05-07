/* monsters.c - monster abilities and vulnerabilities.
 *
 * Kyle Hughes 2/07/14
 */

#include <stdio.h>

/* MONSTER ATTACKS */
#define  FIRE    0x01
#define  BITE    0x02
#define  CLAW    0x04
#define  ACID    0x08
#define  FROST   0x10
#define  POISON  0x20

/* MONSTER TYPES */
#define WOLF    BITE
#define COUGAR  BITE | CLAW
#define TIGER   BITE | CLAW
#define COBRA   BITE | POISON
#define DRAGON  FIRE | BITE | CLAW
#define YETI    BITE | CLAW | FROST
#define ALIEN   BITE | ACID

/* DEFENSES */
#define  NONE        0x00
#define  INSULATION  FIRE | FROST
#define  ARMOR       BITE | CLAW
#define  AMULET      POISON | ACID


int main()
{
    // prototype for the "report_danger" function.
    void report_danger(int, int);
    int  equipment;
    int  monster;

    printf("Testing report_danger() function.\n");

    printf("Test  1: ");
    equipment = NONE;
    monster   = WOLF;
    report_danger(equipment, monster);

    printf("Test  2: ");
    equipment = ARMOR;
    monster   = WOLF;
    report_danger(equipment, monster);

    printf("Test  3: ");
    equipment = ARMOR;
    monster   = DRAGON;
    report_danger(equipment, monster);

    printf("Test  4: ");
    equipment = INSULATION;
    monster   = ALIEN;
    report_danger(equipment, monster);

    printf("Test  5: ");
    equipment = ARMOR;
    monster   = TIGER;
    report_danger(equipment, monster);

    printf("Test  6: ");
    equipment = ARMOR | AMULET | INSULATION;
    monster   = DRAGON;
    report_danger(equipment, monster);

    printf("Test  7: ");
    equipment = NONE;
    monster   = DRAGON;
    report_danger(equipment, monster);

    printf("Test  8: ");
    equipment = INSULATION;
    monster   = DRAGON;
    report_danger(equipment, monster);

    printf("Test  9: ");
    equipment = INSULATION;
    monster   = COBRA;
    report_danger(equipment, monster);

    printf("Test 10: ");
    equipment = AMULET;
    monster   = ALIEN;
    report_danger(equipment, monster);

    return 0;
}



/* void function - does not return anything
 *
 * report_danger takes two arguments:
 *   1) What defenses the user has
 *   2) What kind of monster it is (which attacks it has)
 *
 * report_danger should print out what things the
 * user has to worry about.
 */

void report_danger(int defenses, int monster)
{
    int def = defenses;
    int monst = monster;
    int strongAgainst;
    int weakAgainst;
    int theBit = 0;
    int i;
    printf("Beware of: ");

    // Only gets what the player doesnt have defense for
    strongAgainst = def & monst;
    weakAgainst = strongAgainst ^ monst;   

    for (i = 31; i >=0; i--) {
        if(theBit = weakAgainst & (1 << i)) {

            if(theBit == 0x01) {
                printf("FIRE ");

            }
            if(theBit == 0x02) {
                printf("BITE ");

            }
            if(theBit == 0x04) {
                printf("CLAW ");

            }
            if(theBit == 0x08) {
                printf("ACID ");

            }
            if(theBit == 0x10) {
                printf("FROST");

            }
            if(theBit == 0x20) {
                printf("POISON ");

            }

        } else {
            ;
        }
    }
    printf("\n");
    
    return;
}
