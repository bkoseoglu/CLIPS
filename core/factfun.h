   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*             CLIPS Version 6.24  06/05/06            */
   /*                                                     */
   /*              FACT FUNCTIONS HEADER FILE             */
   /*******************************************************/

/*************************************************************/
/* Purpose:                                                  */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*      6.23: Corrected compilation errors for files         */
/*            generated by constructs-to-c. DR0861           */
/*                                                           */
/*      6.24: Added ppfact command.                          */
/*                                                           */
/*************************************************************/

#ifndef _H_factfun
#define _H_factfun

#ifndef _H_factmngr
#include "fact/fact_manager.h"
#endif

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _FACTFUN_SOURCE_
#define LOCALE
#else
#define LOCALE extern
#endif

#define FactDeftemplate(a) EnvFactDeftemplate(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define FactExistp(a) EnvFactExistp(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define FactSlotNames(a,b) EnvFactSlotNames(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define GetFactList(a,b) EnvGetFactList(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define PPFact(a,b,c) EnvPPFact(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c)

   LOCALE void                           FactFunctionDefinitions(void *,EXEC_STATUS);
   LOCALE void                          *FactRelationFunction(void *,EXEC_STATUS);
   LOCALE void                          *FactRelation(void *);
   LOCALE void                          *EnvFactDeftemplate(void *,EXEC_STATUS,void *);
   LOCALE int                            FactExistpFunction(void *,EXEC_STATUS);
   LOCALE int                            EnvFactExistp(void *,EXEC_STATUS,void *);
   LOCALE void                           FactSlotValueFunction(void *,EXEC_STATUS,DATA_OBJECT *);
   LOCALE void                           FactSlotValue(void *,EXEC_STATUS,void *,char *,DATA_OBJECT *);
   LOCALE void                           FactSlotNamesFunction(void *,EXEC_STATUS,DATA_OBJECT *);
   LOCALE void                           EnvFactSlotNames(void *,EXEC_STATUS,void *,DATA_OBJECT *);
   LOCALE void                           GetFactListFunction(void *,EXEC_STATUS,DATA_OBJECT *);
   LOCALE void                           EnvGetFactList(void *,EXEC_STATUS,DATA_OBJECT *,void *);
   LOCALE void                           PPFactFunction(void *,EXEC_STATUS);
   LOCALE void                           EnvPPFact(void *,EXEC_STATUS,void *,char *,int);
   LOCALE struct fact                   *GetFactAddressOrIndexArgument(void *,EXEC_STATUS,char *,int,int);

#endif

