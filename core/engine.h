   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*             CLIPS Version 6.30  10/19/06            */
   /*                                                     */
   /*                 ENGINE HEADER FILE                  */
   /*******************************************************/

/*************************************************************/
/* Purpose: Provides functionality primarily associated with */
/*   the run and focus commands.                             */
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
/*      6.24: Removed INCREMENTAL_RESET and                  */
/*            LOGICAL_DEPENDENCIES compilation flag.         */
/*                                                           */
/*            Renamed BOOLEAN macro type to intBool.         */
/*                                                           */
/*            Added access functions to the HaltRules flag.  */
/*                                                           */
/*            Added EnvGetNextFocus, EnvGetFocusChanged, and */
/*            EnvSetFocusChanged functions.                  */
/*                                                           */
/*      6.30: Added additional developer statistics to help  */
/*            analyze join network performance.              */
/*                                                           */
/*            Added context information for run functions.   */
/*                                                           */
/*************************************************************/

#ifndef _H_engine

#define _H_engine

#ifndef _H_lgcldpnd
#include "lgcldpnd.h"
#endif
#ifndef _H_ruledef
#include "ruledef.h"
#endif
#ifndef _H_network
#include "network.h"
#endif
#ifndef _H_moduldef
#include "moduldef.h"
#endif
#ifndef _H_retract
#include "retract.h"
#endif

struct focus
  {
   struct defmodule *theModule;
   struct defruleModule *theDefruleModule;
   struct focus *next;
  };
  
#define ENGINE_DATA 18

struct engineData
  { 
   struct defrule *ExecutingRule;
   intBool HaltRules;
   struct joinNode *TheLogicalJoin;
   struct partialMatch *TheLogicalBind;
   struct dependency *UnsupportedDataEntities;
   int alreadyEntered;
   struct callFunctionItem *ListOfRunFunctions;
   struct focus *CurrentFocus;
   int FocusChanged;
#if DEBUGGING_FUNCTIONS
   unsigned WatchStatistics;
   unsigned WatchFocus;
#endif
   intBool IncrementalResetInProgress;
   intBool IncrementalResetFlag;
   intBool JoinOperationInProgress;
   struct partialMatch *GlobalLHSBinds;
   struct partialMatch *GlobalRHSBinds;
   struct joinNode *GlobalJoin;
   struct partialMatch *GarbagePartialMatches;
   struct alphaMatch *GarbageAlphaMatches;
   int AlreadyRunning;
#if DEVELOPER
   long leftToRightComparisons;
   long rightToLeftComparisons;
   long leftToRightSucceeds;
   long rightToLeftSucceeds;
   long leftToRightLoops;
   long rightToLeftLoops;
   long findNextConflictingComparisons;
   long betaHashHTSkips;
   long betaHashListSkips;
   long unneededMarkerCompare;
#endif
  };

#define EngineData(theEnv,execStatus) ((struct engineData *) GetEnvironmentData(theEnv,execStatus,ENGINE_DATA))

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _ENGINE_SOURCE_
#define LOCALE
#else
#define LOCALE extern
#endif

/**************************************************************/
/* The GetFocus function is remapped under certain conditions */
/* because it conflicts with a Windows 3.1 function.          */
/**************************************************************/
/*
#if ! ((GENERIC || IBM) && WINDOW_INTERFACE)
#define WRGetFocus GetFocus
#endif
*/
#define MAX_PATTERNS_CHECKED 64

#define ClearFocusStack() EnvClearFocusStack(GetCurrentEnvironment(),getCurrentExecutionState())
#define DefruleHasBreakpoint(a) EnvDefruleHasBreakpoint(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define Focus(a) EnvFocus(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define GetFocus() EnvGetFocus(GetCurrentEnvironment(),getCurrentExecutionState())
#define GetFocusChanged() EnvGetFocusChanged(GetCurrentEnvironment(),getCurrentExecutionState())
#define GetFocusStack(a) EnvGetFocusStack(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define GetNextFocus(a) EnvGetNextFocus(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define Halt() EnvHalt(GetCurrentEnvironment(),getCurrentExecutionState())
#define ListFocusStack(a) EnvListFocusStack(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define PopFocus() EnvPopFocus(GetCurrentEnvironment(),getCurrentExecutionState())
#define RemoveBreak(a) EnvRemoveBreak(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define RemoveRunFunction(a) EnvRemoveRunFunction(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define SetBreak(a) EnvSetBreak(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define SetFocusChanged(a) EnvSetFocusChanged(GetCurrentEnvironment(),getCurrentExecutionState(),a)
#define ShowBreaks(a,b) EnvShowBreaks(GetCurrentEnvironment(),getCurrentExecutionState(),a,b)

#if ALLOW_ENVIRONMENT_GLOBALS
   LOCALE long long               Run(long long);
#endif

   LOCALE long long               EnvRun(void *,EXEC_STATUS,long long);
   LOCALE intBool                 EnvAddRunFunction(void *,EXEC_STATUS,char *,
                                                    void (*)(void *),int);
   LOCALE intBool                 EnvAddRunFunctionWithContext(void *,EXEC_STATUS,char *,
                                                               void (*)(void *),int,void *);
   LOCALE intBool                 AddRunFunction(char *,void (*)(void),int);
   LOCALE intBool                 EnvRemoveRunFunction(void *,EXEC_STATUS,char *);
   LOCALE void                    InitializeEngine(void *,EXEC_STATUS);
   LOCALE void                    EnvSetBreak(void *,EXEC_STATUS,void *);
   LOCALE void                    EnvHalt(void *,EXEC_STATUS);
   LOCALE intBool                 EnvRemoveBreak(void *,EXEC_STATUS,void *);
   LOCALE void                    RemoveAllBreakpoints(void *,EXEC_STATUS);
   LOCALE void                    EnvShowBreaks(void *,EXEC_STATUS,char *,void *);
   LOCALE intBool                 EnvDefruleHasBreakpoint(void *,EXEC_STATUS,void *);
   LOCALE void                    RunCommand        (void *,EXEC_STATUS);
   LOCALE void                    SetBreakCommand   (void *,EXEC_STATUS);
   LOCALE void                    RemoveBreakCommand(void *,EXEC_STATUS);
   LOCALE void                    ShowBreaksCommand (void *,EXEC_STATUS);
   LOCALE void                    HaltCommand       (void *,EXEC_STATUS);
   LOCALE int                     FocusCommand      (void *,EXEC_STATUS);
   LOCALE void                    ClearFocusStackCommand(void *,EXEC_STATUS);
   LOCALE void                    EnvClearFocusStack(void *,EXEC_STATUS);
   LOCALE void                   *EnvGetNextFocus(void *,EXEC_STATUS,void *);
   LOCALE void                    EnvFocus(void *,EXEC_STATUS,void *);
   LOCALE int                     EnvGetFocusChanged(void *,EXEC_STATUS);
   LOCALE void                    EnvSetFocusChanged(void *,EXEC_STATUS,int);
   LOCALE void                    ListFocusStackCommand(void *,EXEC_STATUS);
   LOCALE void                    EnvListFocusStack(void *,EXEC_STATUS,char *);
   LOCALE void                    GetFocusStackFunction(void *,EXEC_STATUS,DATA_OBJECT_PTR);
   LOCALE void                    EnvGetFocusStack(void *,EXEC_STATUS,DATA_OBJECT_PTR);
   LOCALE void                   *PopFocusFunction(void *,EXEC_STATUS);
   LOCALE void                   *GetFocusFunction(void *,EXEC_STATUS);
   LOCALE void                   *EnvPopFocus(void *,EXEC_STATUS);
   LOCALE void                   *EnvGetFocus(void *,EXEC_STATUS);
   LOCALE intBool                 EnvGetHaltRules(void *,EXEC_STATUS);
   LOCALE void                    EnvSetHaltRules(void *,EXEC_STATUS,intBool);

#endif






