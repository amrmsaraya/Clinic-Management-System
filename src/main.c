#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "patient.h"

#define RECORDS_SIZE 1000

void main(void)
{
    pt recordsLoc[RECORDS_SIZE];
    slt slotsLoc[5];
    uint32 u32recordIndex = 0;
    uint32 u32idLoc;
    uint32 u32modeCheck;
    uint32 u32passCheck;
    uint32 u32actionCheck;

    PATIENT_vinitIds(recordsLoc, RECORDS_SIZE);
    PATIENT_vinitSlots(slotsLoc);

    u32modeCheck = PATIENT_u32checkMode();

    if (u32modeCheck == ADMIN_MODE)
    {
        u32passCheck = PATIENT_u32checkPassword();
    }

    while (1)
    {
        if (u32modeCheck == ADMIN_MODE)
        {
            u32actionCheck = PATIENT_u32selectAdminAction();
        }

        else if (u32modeCheck == USER_MODE)
        {
            u32actionCheck = PATIENT_u32selectUserAction();

            if (u32actionCheck != VIEW_RECORDS && u32actionCheck != VIEW_RESERVATIONS)
            {
                printf("Invalid Action!\n");
                continue;
            }
        }
        else
        {
            printf("Invalid Mode!\n");
            exit(0);
        }

        if (u32actionCheck == ADD_RECORD)
        {
            PATIENT_u32addRecord(recordsLoc, u32recordIndex++);
        }
        else if (u32actionCheck == EDIT_RECORD)
        {
            printf("\nID: ");
            scanf("%d", &u32idLoc);

            PATIENT_u32editRecord(recordsLoc, u32idLoc, RECORDS_SIZE);
        }
        else if (u32actionCheck == RESERVE_SLOT)
        {
            printf("\nID: ");
            scanf("%d", &u32idLoc);
            PATIENT_u32reserveSlot(recordsLoc, slotsLoc, RECORDS_SIZE, u32idLoc);
        }
        else if (u32actionCheck == CANCEL_RESERVATION)
        {
            printf("\nID: ");
            scanf("%d", &u32idLoc);
            PATIENT_u32cancelReservation(slotsLoc, u32idLoc);
        }
        else if (u32actionCheck == VIEW_RECORDS)
        {
            printf("\nID: ");
            scanf("%d", &u32idLoc);
            PATIENT_u32viewRecord(recordsLoc, u32idLoc, RECORDS_SIZE);
        }
        else if (u32actionCheck == VIEW_RESERVATIONS)
        {
            PATIENT_vviewReservations(slotsLoc);
        }
        else if (u32actionCheck == EXIT)
        {

            exit(0);
        }
        else
        {
            system("clear");
            printf("Invalid Action!\n");
        }
    }
}