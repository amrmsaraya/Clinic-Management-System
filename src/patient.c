#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

void PATIENT_vinitIds(pt *precords, uint32 u32size)
{
    uint32 u32counterLoc;

    for (u32counterLoc = 0; u32counterLoc < u32size; u32counterLoc++)
    {
        precords[u32counterLoc].id = -1;
    }
}

void PATIENT_vinitSlots(slt *pslots)
{
    uint32 u32counterLoc;

    for (u32counterLoc = 0; u32counterLoc < 5; u32counterLoc++)
    {
        pslots[u32counterLoc].id = -1;
    }

    pslots[0].slot = "2:00 - 2:30 PM";
    pslots[1].slot = "2:30 - 3:00 PM";
    pslots[2].slot = "3:00 - 3:30 PM";
    pslots[3].slot = "4:00 - 4:30 PM";
    pslots[4].slot = "4:30 - 5:00 PM";
}

void PATIENT_vshowAvailSlots(slt *pslots)
{
    uint32 u32counterLoc;
    system("clear");
    printf("\n* Available Slots *\n");
    printf("-------------------\n");

    for (u32counterLoc = 0; u32counterLoc < 5; u32counterLoc++)
    {
        if (pslots[u32counterLoc].id == -1)
        {
            printf("[%d] %s\n", u32counterLoc, pslots[u32counterLoc].slot);
        }
    }

    printf("-------------------\n");
}

uint32 PATIENT_u32getIndex(pt *precords, uint32 u32idCpy, uint32 u32recordsSize)
{
    uint32 u32counterLoc;
    uint32 u32idIndexLoc = -1;

    for (u32counterLoc = 0; u32counterLoc < u32recordsSize; u32counterLoc++)
    {
        if (precords[u32counterLoc].id == u32idCpy)
        {
            u32idIndexLoc = u32counterLoc;
            break;
        }
    }
    return u32idIndexLoc;
}

checks PATIENT_u32checkMode()
{
    checks modeLoc;

    printf("\n* Mode Selection *\n");
    printf("------------------\n");
    printf("[%d] Admin Mode\n", ADMIN_MODE);
    printf("[%d] USER Mode\n", USER_MODE);
    printf("------------------\n");

    printf("Mode [?]: ");
    scanf("%d", &modeLoc);

    if (modeLoc == ADMIN_MODE)
    {
        return ADMIN_MODE;
    }
    else if (modeLoc == USER_MODE)
    {
        system("clear");
        return USER_MODE;
    }
    else
    {
        return 10;
    }
}

checks PATIENT_u32checkPassword()
{
    uint32 u32passLoc;
    checks passCheck;
    uint32 u32worngPass = 1;

    while (1)
    {
        printf("Password: ");
        scanf("%d", &u32passLoc);

        if (u32passLoc == 1234)
        {
            passCheck = RIGHT_PASSWORD;
            system("clear");
            break;
        }
        else if (passCheck != 1234 && u32worngPass < 3)
        {
            printf("Wrong Password!(%d/3)\n", u32worngPass);
            u32worngPass++;
            passCheck = WRONG_PASSWORD;
            continue;
        }
        else
        {
            printf("Wrong Password!(%d/3)!\n", u32worngPass);
            printf("Program is terminating!\n");
            exit(0);
        }
    }

    return passCheck;
}

uint32 PATIENT_u32selectAdminAction()
{
    uint32 u32actionLoc;

    printf("\n* Admin Mode Actions *\n");
    printf("----------------------\n");
    printf("[%d] Add new patient record\n", ADD_RECORD);
    printf("[%d] Edit patient record\n", EDIT_RECORD);
    printf("[%d] Reserve a slot with the doctor\n", RESERVE_SLOT);
    printf("[%d] Cancel reservation\n", CANCEL_RESERVATION);
    printf("[%d] View patient record\n", VIEW_RECORDS);
    printf("[%d] View today's reservations\n", VIEW_RESERVATIONS);
    printf("[%d] Exit\n", EXIT);
    printf("----------------------\n");

    printf("Action [?]: ");
    scanf("%d", &u32actionLoc);

    return u32actionLoc;
}

uint32 PATIENT_u32selectUserAction()
{
    uint32 u32actionLoc;

    printf("\n* User Mode Actions *\n");
    printf("---------------------\n");
    printf("[%d] View patient record\n", VIEW_RECORDS);
    printf("[%d] View today's reservations\n", VIEW_RESERVATIONS);
    printf("[%d] Exit\n", EXIT);
    printf("---------------------\n");

    printf("Action [?]: ");
    scanf("%d", &u32actionLoc);

    if (u32actionLoc == VIEW_RECORDS || u32actionLoc == VIEW_RESERVATIONS)
    {
        return u32actionLoc;
    }
}

uint32 PATIENT_u32addRecord(pt *precords, uint32 u32recordIndexCpy)
{
    uint32 u32idLoc;
    uint32 u32counterLoc;
    uint8 u8idFlgLoc = 1;
    checks u32isUnqLoc;

    system("clear");
    printf("\n* Add Patient Information *\n");
    printf("---------------------------\n");

    printf("ID: ");
    scanf("%d", &u32idLoc);

    for (u32counterLoc = 0; u32counterLoc <= u32recordIndexCpy; u32counterLoc++)
    {
        if (precords[u32recordIndexCpy].id == u32idLoc)
        {
            u8idFlgLoc = 0;
            break;
        }
    }

    if (u8idFlgLoc == 1)
    {
        precords[u32recordIndexCpy].id = u32idLoc;
        u32isUnqLoc = UNIQUE_ID;
    }
    else
    {
        system("clear");
        printf("Record Rejected, ID Already Exists!\n");
        return ID_EXIST;
    }

    printf("Name: ");
    scanf(" %[^\n]", &precords[u32recordIndexCpy].name);

    printf("Age: ");
    scanf("%d", &precords[u32recordIndexCpy].age);

    printf("Gender [m/f]: ");
    scanf(" %c", &precords[u32recordIndexCpy].gender);

    printf("---------------------------\n");

    system("clear");
    printf("Record Added Successfully!\n");
    return RECORD_ADDED_SUCCESSFULLY;
}

uint32 PATIENT_u32editRecord(pt *precords, uint32 u32idCpy, uint32 u32recordsSize)
{
    uint32 u32idLoc;
    uint32 u32counterLoc;
    uint32 u32idIndexLoc = -1;

    u32idIndexLoc = PATIENT_u32getIndex(precords, u32idCpy, u32recordsSize);
    system("clear");
    if (u32idIndexLoc != -1)
    {
        PATIENT_u32addRecord(precords, u32idIndexLoc);
        return RECORD_ADDED_SUCCESSFULLY;
    }
    else
    {
        system("clear");
        printf("Incorrect ID!\n");
        return INCORRECT_ID;
    }
}

uint32 PATIENT_u32reserveSlot(pt *precords, slt *pslots, uint32 u32recordsSize, uint32 u32idCpy)
{
    uint32 u32idIndexLoc;
    uint8 u8slot;

    PATIENT_vshowAvailSlots(pslots);

    u32idIndexLoc = PATIENT_u32getIndex(precords, u32idCpy, u32recordsSize);

    if (u32idIndexLoc != -1)
    {
        printf("Slot [?]: ");
        scanf("%d", &u8slot);

        if (pslots[u8slot].id == -1)
        {
            pslots[u8slot].id = u32idCpy;
            system("clear");
            printf("[%s] has been reserved successfully!\n", pslots[u8slot].slot);
            return SLOT_RESERVED_SUCCESSFULLY;
        }
        else
        {
            system("clear");
            printf("This slot isn't available!\n");
            return SLOT_NOT_AVAILABLE;
        }
    }
    else
    {
        system("clear");
        printf("Incorrect ID!\n");
        return INCORRECT_ID;
    }
}

uint32 PATIENT_u32cancelReservation(slt *pslots, uint32 u32idCpy)
{
    uint32 u32counterLoc;

    for (u32counterLoc = 0; u32counterLoc < 5; u32counterLoc++)
    {
        if (pslots[u32counterLoc].id == u32idCpy)
        {
            pslots[u32counterLoc].id = -1;
            system("clear");
            printf("Reservation has been cancelled!\n");
            return RESERVATION_CANCELLED;
        }
        else if (pslots[u32counterLoc].id == -1)
        {
            continue;
        }
        else
        {
            system("clear");
            printf("Reservation doesn't exist!\n");
            return NO_RESERVATION;
        }
    }
}

uint32 PATIENT_u32viewRecord(pt *precords, uint32 u32idCpy, uint32 u32recordsSize)
{
    uint32 u32idIndexLoc;

    system("clear");

    u32idIndexLoc = PATIENT_u32getIndex(precords, u32idCpy, u32recordsSize);

    if (u32idIndexLoc != -1)
    {
        printf("\n* Patient Information *\n");
        printf("-----------------------\n");
        printf("ID: %d\n", precords[u32idIndexLoc].id);
        printf("Name: %s\n", precords[u32idIndexLoc].name);
        printf("Age: %d\n", precords[u32idIndexLoc].age);
        if (precords[u32idIndexLoc].gender == 'm')
        {
            printf("Gender: Male\n");
        }
        else if (precords[u32idIndexLoc].gender == 'f')
        {
            printf("Gender: Female\n");
        }
        printf("-----------------------\n");

        return ID_EXIST;
    }
    else
    {
        system("clear");
        printf("Incorrect ID!\n");
        return INCORRECT_ID;
    }
}

void PATIENT_vviewReservations(slt *pslots)
{
    uint32 u32counterLoc;
    uint8 u8flgLoc = 0;
    system("clear");

    printf("\n* Today's Reservations *\n");
    printf("------------------------\n");
    for (u32counterLoc = 0; u32counterLoc < 5; u32counterLoc++)
    {
        if (pslots[u32counterLoc].id != -1)
        {
            printf("ID: %d  [%s]\n", pslots[u32counterLoc].id, pslots[u32counterLoc].slot);
            u8flgLoc++;
        }
    }
    if (u8flgLoc == 0)
    {
        system("clear");
        printf("No reservations for today!\n");
    }
}
