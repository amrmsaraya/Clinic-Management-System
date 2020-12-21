#include "std_types.h"

typedef struct patient
{
    uint8 name[100];
    uint8 age;
    uint8 gender;
    uint32 id;
} pt;

typedef struct slots
{
    uint32 id;
    uint8 *slot;
} slt;

typedef enum checks
{
    ADMIN_MODE = 1,
    USER_MODE,
    WRONG_PASSWORD,
    RIGHT_PASSWORD,
    UNIQUE_ID,
    ID_EXIST,
    RECORD_ADDED_SUCCESSFULLY,
    SLOT_RESERVED_SUCCESSFULLY,
    SLOT_NOT_AVAILABLE,
    INCORRECT_ID,
    NO_RESERVATION,
    RESERVATION_CANCELLED,

} checks;

typedef enum actions
{
    ADD_RECORD = 1,
    EDIT_RECORD,
    RESERVE_SLOT,
    CANCEL_RESERVATION,
    VIEW_RECORDS,
    VIEW_RESERVATIONS,
    EXIT,
} actions;

/* Initialize records ids */
void PATIENT_vinitIds(pt *precords, uint32 u32size);
/* Initialize reservation slots */
void PATIENT_vinitSlots(slt *pslots);
/* Prints all available slots for reservation */
void PATIENT_vshowAvailSlots(slt *pslots);
/* Check Input Mode */
checks PATIENT_u32checkMode();
/* Check if password is right or Wrong */
checks PATIENT_u32checkPassword();
/* Prints and select options allowed to admin user */
uint32 PATIENT_u32selectAdminAction();
/* Prints and select options allowed to normal user */
uint32 PATIENT_u32selectUserAction();
/* Return the index of given id */
uint32 PATIENT_u32getIndex(pt *precords, uint32 u32idCpy, uint32 u32recordsSize);
/* Add new patient record */
uint32 PATIENT_u32addRecord(pt *precords, uint32 u32recordIndexCpy);
/* Edit exist patient record */
uint32 PATIENT_u32editRecord(pt *precords, uint32 u32idCpy, uint32 u32recordsSize);
/* Reserve a slot with doctor for a given id */
uint32 PATIENT_u32reserveSlot(pt *precords, slt *pslots, uint32 u32recordsSize, uint32 u32idCpy);
/* Cancel a reserved slot for a given id */
uint32 PATIENT_u32cancelReservation(slt *pslots, uint32 u32idCpy);
/* Print basic information for the patient */
uint32 PATIENT_u32viewRecord(pt *precords, uint32 u32idCpy, uint32 u32recordsSize);
/* Print all today's reservations with ID attached to it */
void PATIENT_vviewReservations(slt *pslots);
