//mostly pasted code that is just for the programm to be able to load the dll



#include "include.h"

#define LINECOUNTER    6
#define MAX_BLOCK      10
#define CODE_MEMORY    0
#define DATA_MEMORY    1
#define USERROW_MEMORY 2
#define ID_MEMORY      3
int TestValue = 0;

typedef struct STRUCOPERATORTag{
	int     nCount;
	char    SerialRecord[512];     
	UINT    MemoryType[MAX_BLOCK];
	UINT    StartAddr[MAX_BLOCK];
	UINT    Len[MAX_BLOCK];

}STRUCOPERATOR, * pSTRUCOPERATOR;
STRUCOPERATOR OprateResult;
typedef struct ICINFORMATIONTag
{
    char      IcName[50];
    int       NoteCount;
    char      MemoryType[LINECOUNTER][100];
}ICINFORMATION, * pICINFORMATION;

ICINFORMATION IcInformation ={
     "NotAValidChip",


LINECOUNTER,
"[Xgpro Patcher]",
"Loaded DLL",
"[Description]",
"The Code for this part is all",
"pasted (I have no clue what it does)",
"but it works :)",
};

extern "C" __declspec(dllexport) pSTRUCOPERATOR GetSerial(unsigned char* pCode, unsigned char* pEEdata, unsigned char* pUserRow, unsigned char* pID, char* pSerial, unsigned char* pUniqueKey, unsigned char* pConfig) {
	int i;

	int  SerialNumber;
	SerialNumber = atoi(pSerial);
	
	UINT Code_StartAdd = 0x3545;       
	TestValue++;
	for (i = 0; i < 32; i++)pCode[Code_StartAdd + i] = TestValue;

	srand((unsigned)time(NULL)); //seed

	for (i = 0; i < 64; i++)pEEdata[i] = (unsigned char)(rand() & 0xFF);

	for (i = 0; i < 8; i++)pID[i] = pSerial[i];

	for (i = 0; i < 32; i++)pCode[i] = (TestValue + i);
	
	OprateResult.nCount = 4;  

	OprateResult.MemoryType[0] = CODE_MEMORY;       
	OprateResult.StartAddr[0] = Code_StartAdd;     
	OprateResult.Len[0] = 32;
	OprateResult.MemoryType[1] = DATA_MEMORY;
	OprateResult.StartAddr[1] = 0;                 
	OprateResult.Len[1] = 64;                

	OprateResult.MemoryType[2] = ID_MEMORY;         
	OprateResult.StartAddr[2] = 0;                 
	OprateResult.Len[2] = 8;                 

	OprateResult.MemoryType[3] = CODE_MEMORY;      
	OprateResult.StartAddr[3] = 0;                
	OprateResult.Len[3] = 32;               

	sprintf_s(OprateResult.SerialRecord, "%.8d", SerialNumber);

	SerialNumber++;
	sprintf_s(pSerial, 9, "%.8d", SerialNumber);


	return &OprateResult;  
}
extern "C" __declspec(dllexport) pICINFORMATION GetCurrentIcInfo(void) {
    return &IcInformation;
}

extern "C" __declspec(dllexport) int EndProgAccess() {
    return 0;
}
