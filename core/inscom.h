   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*               CLIPS Version 6.24  06/05/06          */
   /*                                                     */
   /*                                                     */
   /*******************************************************/

/*************************************************************/
/* Purpose:                                                  */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Brian L. Dantes                                      */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*      6.23: Corrected compilation errors for files         */
/*            generated by constructs-to-c. DR0861           */
/*                                                           */
/*      6.24: Renamed BOOLEAN macro type to intBool.         */
/*                                                           */
/*************************************************************/

#ifndef _H_inscom
#define _H_inscom

#ifndef _H_object
#include "object.h"
#endif

#ifndef _H_insfun
#include "insfun.h"
#endif

#define INSTANCE_DATA 29

struct instanceData
  { 
   INSTANCE_TYPE DummyInstance;
   INSTANCE_TYPE **InstanceTable;
   int MaintainGarbageInstances;
   int MkInsMsgPass;
   int ChangesToInstances;
   IGARBAGE *InstanceGarbageList;
   struct patternEntityRecord InstanceInfo;
   INSTANCE_TYPE *InstanceList;  
   unsigned long GlobalNumberOfInstances;
   INSTANCE_TYPE *CurrentInstance;
   INSTANCE_TYPE *InstanceListBottom;
   intBool ObjectModDupMsgValid;
  };

#define InstanceData(theEnv,execStatus) ((struct instanceData *) GetEnvironmentData(theEnv,execStatus,INSTANCE_DATA))

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _INSCOM_SOURCE_
#define LOCALE
#else
#define LOCALE extern
#endif

#define CreateRawInstance(a,b) EnvCreateRawInstance(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define DeleteInstance(a) EnvDeleteInstance(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define DirectGetSlot(a,b,c) EnvDirectGetSlot(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c)
#define DirectPutSlot(a,b,c) EnvDirectPutSlot(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c)
#define FindInstance(a,b,c) EnvFindInstance(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c)
#define GetInstanceClass(a) EnvGetInstanceClass(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define GetInstancePPForm(a,b,c) EnvGetInstancePPForm(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c)
#define GetNextInstance(a) EnvGetNextInstance(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define GetNextInstanceInClass(a,b) EnvGetNextInstanceInClass(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define GetNextInstanceInClassAndSubclasses(a,b,c) EnvGetNextInstanceInClassAndSubclasses(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c)
#define Instances(a,b,c,d) EnvInstances(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c,d)
#define MakeInstance(a) EnvMakeInstance(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define UnmakeInstance(a) EnvUnmakeInstance(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define ValidInstanceAddress(a) EnvValidInstanceAddress(GetCurrentEnvironment(),getCurrentExecutionState(),a)

#if ALLOW_ENVIRONMENT_GLOBALS
   LOCALE char                          *GetInstanceName(void *,EXEC_STATUS);
#endif

LOCALE void SetupInstances(void *,EXEC_STATUS);
LOCALE intBool EnvDeleteInstance(void *,EXEC_STATUS,void *);
LOCALE intBool EnvUnmakeInstance(void *,EXEC_STATUS,void *);
#if DEBUGGING_FUNCTIONS
LOCALE void InstancesCommand(void *,EXEC_STATUS);
LOCALE void PPInstanceCommand(void *,EXEC_STATUS);
LOCALE void EnvInstances(void *,EXEC_STATUS,char *,void *,char *,int);
#endif
LOCALE void *EnvMakeInstance(void *,EXEC_STATUS,char *);
LOCALE void *EnvCreateRawInstance(void *,EXEC_STATUS,void *,char *);
LOCALE void *EnvFindInstance(void *,EXEC_STATUS,void *,char *,unsigned);
LOCALE int EnvValidInstanceAddress(void *,EXEC_STATUS,void *);
LOCALE void EnvDirectGetSlot(void *,EXEC_STATUS,void *,char *,DATA_OBJECT *);
LOCALE int EnvDirectPutSlot(void *,EXEC_STATUS,void *,char *,DATA_OBJECT *);
LOCALE char *EnvGetInstanceName(void *,EXEC_STATUS,void *);
LOCALE void *EnvGetInstanceClass(void *,EXEC_STATUS,void *);
LOCALE unsigned long GetGlobalNumberOfInstances(void *,EXEC_STATUS);
LOCALE void *EnvGetNextInstance(void *,EXEC_STATUS,void *);
LOCALE void *GetNextInstanceInScope(void *,EXEC_STATUS,void *);
LOCALE void *EnvGetNextInstanceInClass(void *,EXEC_STATUS,void *,void *);
LOCALE void *EnvGetNextInstanceInClassAndSubclasses(void *,EXEC_STATUS,void **,void *,DATA_OBJECT *);
LOCALE void EnvGetInstancePPForm(void *,EXEC_STATUS,char *,unsigned,void *);
LOCALE void ClassCommand(void *,EXEC_STATUS,DATA_OBJECT *);
LOCALE intBool DeleteInstanceCommand(void *,EXEC_STATUS);
LOCALE intBool UnmakeInstanceCommand(void *,EXEC_STATUS);
LOCALE void SymbolToInstanceName(void *,EXEC_STATUS,DATA_OBJECT *);
LOCALE void *InstanceNameToSymbol(void *,EXEC_STATUS);
LOCALE void InstanceAddressCommand(void *,EXEC_STATUS,DATA_OBJECT *);
LOCALE void InstanceNameCommand(void *,EXEC_STATUS,DATA_OBJECT *);
LOCALE intBool InstanceAddressPCommand(void *,EXEC_STATUS);
LOCALE intBool InstanceNamePCommand(void *,EXEC_STATUS);
LOCALE intBool InstancePCommand(void *,EXEC_STATUS);
LOCALE intBool InstanceExistPCommand(void *,EXEC_STATUS);
LOCALE intBool CreateInstanceHandler(void *,EXEC_STATUS);

#endif





