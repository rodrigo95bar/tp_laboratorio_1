#ifndef UTN_ARRAYS_H_INCLUDED
#define UTN_ARRAYS_H_INCLUDED

#include "validations.h"
int getString(char* pStr, char* msg, char*msgE);
int getInt (int *pNum, char* msg, char* msgE);
int getFloat (float *pNum, char* msg, char* msgE);

int getIntInRange (int *pNum,char *msg,char *msgE,int minimo,int maximo,int reintentos);
int cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgE);
int cargarArraySecuencialFloat(float* pArray,int len,char* msg, char* msgE);

int getStringLetras (char* pStr, char* msg, char* msgE, int reintentos);
int getStringNumeros (char* pStr, char* msg, char* msgE,int reintentos);
int getStringNumerosInt (char* pStr, char* msg, char* msgE,int reintentos);
int getStringAlphanumeric (char* pStr, char* msg, char* msgE,int reintentos);
int getTelephone (char* pStr, char* msg, char* msgE,int reintentos);
int getDni (char* pStr, char* msg, char* msgE,int reintentos);
int getCuit (char* pStr, char* msg, char* msgE,int reintentos);

int searchFreeSpace(char pArray[][20],int* pIndex,int len);
int saerchName(char* name, char parray[][20], int len, int* pIndex);
int ordenarArrayMayorMenor (char* pArray, int len,int limit);

int showArrayInt(int* pArray,int len);
int showArrayChar(char* pArray,int len);


#endif // UTN_ARRAYS_H_INCLUDED
