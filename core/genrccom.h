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

#ifndef _H_genrccom
#define _H_genrccom

#define EnvGetDefgenericName(theEnv,execStatus,x) GetConstructNameString((struct constructHeader *) x)
#define EnvGetDefgenericPPForm(theEnv,execStatus,x) GetConstructPPForm(theEnv,execStatus,(struct constructHeader *) x)

#define SetNextDefgeneric(g,t) SetNextConstruct((struct constructHeader *) g, \
                                                (struct constructHeader *) t)
#define GetDefgenericNamePointer(x) GetConstructNamePointer((struct constructHeader *) x)
#define SetDefgenericPPForm(g,ppf) SetConstructPPForm(theEnv,execStatus,(struct constructHeader *) g,ppf)

#define EnvDefgenericModule(theEnv,execStatus,x) GetConstructModuleName((struct constructHeader *) x)

#ifndef _H_constrct
#include "constrct.h"
#endif
#ifndef _H_cstrccom
#include "cstrccom.h"
#endif
#ifndef _H_evaluatn
#include "evaluatn.h"
#endif
#ifndef _H_moduldef
#include "moduldef.h"
#endif
#ifndef _H_genrcfun
#include "genrcfun.h"
#endif
#ifndef _H_symbol
#include "symbol.h"
#endif

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _GENRCCOM_SOURCE_
#define LOCALE
#else
#define LOCALE extern
#endif

#define DefgenericModule(x) GetConstructModuleName((struct constructHeader *) x)
#define FindDefgeneric(a) EnvFindDefgeneric(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define GetDefgenericList(a,b) EnvGetDefgenericList(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define GetDefgenericName(x) GetConstructNameString((struct constructHeader *) x)
#define GetDefgenericPPForm(x) GetConstructPPForm(GetCurrentEnvironment(),getCurrentExecutionState(),(struct constructHeader *) x)
#define GetDefgenericWatch(a) EnvGetDefgenericWatch(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define GetNextDefgeneric(a) EnvGetNextDefgeneric(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define IsDefgenericDeletable(a) EnvIsDefgenericDeletable(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define ListDefgenerics(a,b) EnvListDefgenerics(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define SetDefgenericWatch(a,b) EnvSetDefgenericWatch(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define Undefgeneric(a) EnvUndefgeneric(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define GetDefmethodDescription(a,b,c,d) EnvGetDefmethodDescription(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c,d)
#define GetDefmethodList(a,b) EnvGetDefmethodList(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define GetDefmethodPPForm(a,b) EnvGetDefmethodPPForm(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define GetDefmethodWatch(a,b) EnvGetDefmethodWatch(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define GetMethodRestrictions(a,b,c) EnvGetMethodRestrictions(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c)
#define GetNextDefmethod(a,b) EnvGetNextDefmethod(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define IsDefmethodDeletable(a,b) EnvIsDefmethodDeletable(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define ListDefmethods(a,b) EnvListDefmethods(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)
#define SetDefmethodWatch(a,b,c) EnvSetDefmethodWatch(GetCurrentEnvironment(),getCurrentExecutionState(),a,b,c)
#define Undefmethod(a,b) EnvUndefmethod(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)

LOCALE void SetupGenericFunctions(void *,EXEC_STATUS);
LOCALE void *EnvFindDefgeneric(void *,EXEC_STATUS,char *);
LOCALE DEFGENERIC *LookupDefgenericByMdlOrScope(void *,EXEC_STATUS,char *);
LOCALE DEFGENERIC *LookupDefgenericInScope(void *,EXEC_STATUS,char *);
LOCALE void *EnvGetNextDefgeneric(void *,EXEC_STATUS,void *);
LOCALE long EnvGetNextDefmethod(void *,EXEC_STATUS,void *,long);
LOCALE int EnvIsDefgenericDeletable(void *,EXEC_STATUS,void *);
LOCALE int EnvIsDefmethodDeletable(void *,EXEC_STATUS,void *,long);
LOCALE void UndefgenericCommand(void *,EXEC_STATUS);
LOCALE void *GetDefgenericModuleCommand(void *,EXEC_STATUS);
LOCALE void UndefmethodCommand(void *,EXEC_STATUS);
LOCALE DEFMETHOD *GetDefmethodPointer(void *,long);

LOCALE intBool EnvUndefgeneric(void *,EXEC_STATUS,void *);
LOCALE intBool EnvUndefmethod(void *,EXEC_STATUS,void *,long);

#if ! OBJECT_SYSTEM
LOCALE void TypeCommand(void *,EXEC_STATUS,DATA_OBJECT *);
#endif

#if DEBUGGING_FUNCTIONS
LOCALE void EnvGetDefmethodDescription(void *,EXEC_STATUS,char *,int,void *,long);
LOCALE unsigned EnvGetDefgenericWatch(void *,EXEC_STATUS,void *);
LOCALE void EnvSetDefgenericWatch(void *,EXEC_STATUS,unsigned,void *);
LOCALE unsigned EnvGetDefmethodWatch(void *,EXEC_STATUS,void *,long);
LOCALE void EnvSetDefmethodWatch(void *,EXEC_STATUS,unsigned,void *,long);
LOCALE void PPDefgenericCommand(void *,EXEC_STATUS);
LOCALE void PPDefmethodCommand(void *,EXEC_STATUS);
LOCALE void ListDefmethodsCommand(void *,EXEC_STATUS);
LOCALE char *EnvGetDefmethodPPForm(void *,EXEC_STATUS,void *,long);
LOCALE void ListDefgenericsCommand(void *,EXEC_STATUS);
LOCALE void EnvListDefgenerics(void *,EXEC_STATUS,char *,struct defmodule *);
LOCALE void EnvListDefmethods(void *,EXEC_STATUS,char *,void *);
#endif

LOCALE void GetDefgenericListFunction(void *,EXEC_STATUS,DATA_OBJECT *);
globle void EnvGetDefgenericList(void *,EXEC_STATUS,DATA_OBJECT *,struct defmodule *);
LOCALE void GetDefmethodListCommand(void *,EXEC_STATUS,DATA_OBJECT *);
LOCALE void EnvGetDefmethodList(void *,EXEC_STATUS,void *,DATA_OBJECT *);
LOCALE void GetMethodRestrictionsCommand(void *,EXEC_STATUS,DATA_OBJECT *);
LOCALE void EnvGetMethodRestrictions(void *,EXEC_STATUS,void *,long,DATA_OBJECT *);

#endif





