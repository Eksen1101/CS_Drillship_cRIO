/*
 * ctrl_custom.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_custom".
 *
 * Model version              : 1.90
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Sep 20 14:24:54 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_custom_h_
#define RTW_HEADER_ctrl_custom_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef ctrl_custom_COMMON_INCLUDES_
# define ctrl_custom_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_custom_COMMON_INCLUDES_ */

#include "ctrl_custom_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ctrl_custom_rtModel            RT_MODEL_ctrl_custom_T

/* Block signals for system '<S22>/MATLAB Function' */
typedef struct {
  real_T y[9];                         /* '<S22>/MATLAB Function' */
} B_MATLABFunction_ctrl_custom_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Inputtomodel;                 /* '<Root>/Input to model' */
  real_T x_ref;                        /* '<Root>/x_ref' */
  real_T y_ref;                        /* '<Root>/y_ref' */
  real_T reset;                        /* '<S4>/reset' */
  real_T Integrator[3];                /* '<S6>/Integrator' */
  real_T Sum;                          /* '<S38>/Sum' */
  real_T Integrator1[3];               /* '<S6>/Integrator1' */
  real_T x_m;                          /* '<S11>/x_m' */
  real_T mm2m;                         /* '<S11>/mm2m' */
  real_T y_m;                          /* '<S11>/y_m' */
  real_T Gain1;                        /* '<S11>/Gain1' */
  real_T u80180deg;                    /* '<S11>/psi_m' */
  real_T Sum_f;                        /* '<S11>/Sum' */
  real_T Integrator2[3];               /* '<S6>/Integrator2' */
  real_T psi_refdeg;                   /* '<Root>/psi_ref [deg]' */
  real_T alpha_u;                      /* '<S1>/alpha_u' */
  real_T K1_u;                         /* '<S1>/K1_u' */
  real_T K1_r;                         /* '<S1>/K1_r' */
  real_T alpha_r;                      /* '<S1>/alpha_r' */
  real_T deg2rad;                      /* '<Root>/deg2rad' */
  real_T M1[3];                        /* '<S6>/M^-1' */
  real_T Memory4[6];                   /* '<S9>/Memory4' */
  real_T deg2rad1;                     /* '<Root>/deg2rad1' */
  real_T MatrixMultiply1[3];           /* '<S6>/Matrix Multiply1' */
  real_T Sum1[3];                      /* '<S6>/Sum1' */
  real_T Acc_x;                        /* '<S3>/Acc_x' */
  real_T Acc_y;                        /* '<S3>/Acc_y' */
  real_T Acc_z;                        /* '<S3>/Acc_z' */
  real_T Gyro_x;                       /* '<S3>/Gyro_x' */
  real_T Gyro_y;                       /* '<S3>/Gyro_y' */
  real_T Gyro_z;                       /* '<S3>/Gyro_z' */
  real_T K_p_x;                        /* '<S22>/K_p_x' */
  real_T K_p_y;                        /* '<S22>/K_p_y' */
  real_T K_p_psi;                      /* '<S22>/K_p_psi' */
  real_T K_i_psi;                      /* '<S22>/K_i_psi' */
  real_T K_i_x;                        /* '<S22>/K_i_x' */
  real_T K_i_y;                        /* '<S22>/K_i_y' */
  real_T K_d_psi;                      /* '<S22>/K_d_psi' */
  real_T K_d_x;                        /* '<S22>/K_d_x' */
  real_T K_d_y;                        /* '<S22>/K_d_y' */
  real_T w_d_x;                        /* '<S23>/w_d_x' */
  real_T w_d_y;                        /* '<S23>/w_d_y' */
  real_T w_d_psi;                      /* '<S23>/w_d_psi' */
  real_T zeta_psi;                     /* '<S23>/zeta_psi' */
  real_T zeta_x;                       /* '<S23>/zeta_x' */
  real_T zeta_y;                       /* '<S23>/zeta_y' */
  real_T u[6];                         /* '<S10>/MATLAB Function11' */
  real_T alpha[6];                     /* '<S10>/MATLAB Function11' */
  real_T alpha_infinf[6];              /* '<S9>/MATLAB Function11' */
  real_T tau1[3];                      /* '<S1>/MATLAB Function4' */
  real_T z_1[3];                       /* '<S1>/MATLAB Function4' */
  real_T z_2[3];                       /* '<S1>/MATLAB Function4' */
  B_MATLABFunction_ctrl_custom_T sf_MATLABFunction2;/* '<S24>/MATLAB Function2' */
  B_MATLABFunction_ctrl_custom_T sf_MATLABFunction1_g;/* '<S24>/MATLAB Function1' */
  B_MATLABFunction_ctrl_custom_T sf_MATLABFunction_k;/* '<S24>/MATLAB Function' */
  B_MATLABFunction_ctrl_custom_T sf_MATLABFunction1_l;/* '<S23>/MATLAB Function1' */
  B_MATLABFunction_ctrl_custom_T sf_MATLABFunction_m;/* '<S23>/MATLAB Function' */
  B_MATLABFunction_ctrl_custom_T sf_MATLABFunction2_d;/* '<S22>/MATLAB Function2' */
  B_MATLABFunction_ctrl_custom_T sf_MATLABFunction1_h;/* '<S22>/MATLAB Function1' */
  B_MATLABFunction_ctrl_custom_T sf_MATLABFunction_ki;/* '<S22>/MATLAB Function' */
} B_ctrl_custom_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Inputtomodel_DWORK1;          /* '<Root>/Input to model' */
  real_T OutputtoWorkspace_DWORK1;     /* '<Root>/Output to Workspace' */
  real_T x_ref_DWORK1;                 /* '<Root>/x_ref' */
  real_T x_t_DWORK1;                   /* '<Root>/x_t' */
  real_T y_ref_DWORK1;                 /* '<Root>/y_ref' */
  real_T y_t_DWORK1;                   /* '<Root>/y_t' */
  real_T reset_DWORK1;                 /* '<S4>/reset' */
  real_T x_hat_DWORK1;                 /* '<S41>/x_hat' */
  real_T y_hat_DWORK1;                 /* '<S41>/y_hat' */
  real_T psi_hat_DWORK1;               /* '<S41>/psi_hat' */
  real_T u_hat_DWORK1;                 /* '<S43>/u_hat' */
  real_T v_hat_DWORK1;                 /* '<S43>/v_hat' */
  real_T r_hat_DWORK1;                 /* '<S43>/r_hat' */
  real_T x_m_DWORK1;                   /* '<S11>/x_m' */
  real_T y_m_DWORK1;                   /* '<S11>/y_m' */
  real_T psi_m_DWORK1;                 /* '<S11>/psi_m' */
  real_T psi_refdeg_DWORK1;            /* '<Root>/psi_ref [deg]' */
  real_T alpha_u_DWORK1;               /* '<S1>/alpha_u' */
  real_T K1_u_DWORK1;                  /* '<S1>/K1_u' */
  real_T K1_r_DWORK1;                  /* '<S1>/K1_r' */
  real_T alpha_r_DWORK1;               /* '<S1>/alpha_r' */
  real_T u_dot_hat_DWORK1;             /* '<S42>/u_dot_hat' */
  real_T v_dot_hat_DWORK1;             /* '<S42>/v_dot_hat' */
  real_T r_dot_hat_DWORK1;             /* '<S42>/r_dot_hat' */
  real_T b_x_hat_DWORK1;               /* '<S40>/b_x_hat' */
  real_T b_y_hat_DWORK1;               /* '<S40>/b_y_hat' */
  real_T b_psi_hat_DWORK1;             /* '<S40>/b_psi_hat' */
  real_T Memory4_PreviousInput[6];     /* '<S9>/Memory4' */
  real_T alpha1_DWORK1;                /* '<S8>/alpha1' */
  real_T alpha2_DWORK1;                /* '<S8>/alpha2' */
  real_T alpha3_DWORK1;                /* '<S8>/alpha3' */
  real_T alpha4_DWORK1;                /* '<S8>/alpha4' */
  real_T alpha5_DWORK1;                /* '<S8>/alpha5' */
  real_T alpha6_DWORK1;                /* '<S8>/alpha6' */
  real_T u1_DWORK1;                    /* '<S8>/u1' */
  real_T u2_DWORK1;                    /* '<S8>/u2' */
  real_T u3_DWORK1;                    /* '<S8>/u3' */
  real_T u4_DWORK1;                    /* '<S8>/u4' */
  real_T u5_DWORK1;                    /* '<S8>/u5' */
  real_T u6_DWORK1;                    /* '<S8>/u6' */
  real_T psi_t_DWORK1;                 /* '<Root>/psi_t' */
  real_T Acc_x_DWORK1;                 /* '<S3>/Acc_x' */
  real_T Acc_y_DWORK1;                 /* '<S3>/Acc_y' */
  real_T Acc_z_DWORK1;                 /* '<S3>/Acc_z' */
  real_T Gyro_x_DWORK1;                /* '<S3>/Gyro_x' */
  real_T Gyro_y_DWORK1;                /* '<S3>/Gyro_y' */
  real_T Gyro_z_DWORK1;                /* '<S3>/Gyro_z' */
  real_T K_p_x_DWORK1;                 /* '<S22>/K_p_x' */
  real_T K_p_y_DWORK1;                 /* '<S22>/K_p_y' */
  real_T K_p_psi_DWORK1;               /* '<S22>/K_p_psi' */
  real_T K_i_psi_DWORK1;               /* '<S22>/K_i_psi' */
  real_T K_i_x_DWORK1;                 /* '<S22>/K_i_x' */
  real_T K_i_y_DWORK1;                 /* '<S22>/K_i_y' */
  real_T K_d_psi_DWORK1;               /* '<S22>/K_d_psi' */
  real_T K_d_x_DWORK1;                 /* '<S22>/K_d_x' */
  real_T K_d_y_DWORK1;                 /* '<S22>/K_d_y' */
  real_T w_d_x_DWORK1;                 /* '<S23>/w_d_x' */
  real_T w_d_y_DWORK1;                 /* '<S23>/w_d_y' */
  real_T w_d_psi_DWORK1;               /* '<S23>/w_d_psi' */
  real_T zeta_psi_DWORK1;              /* '<S23>/zeta_psi' */
  real_T zeta_x_DWORK1;                /* '<S23>/zeta_x' */
  real_T zeta_y_DWORK1;                /* '<S23>/zeta_y' */
  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<Root>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<Root>/To File1' */

  struct {
    void *FilePtr;
  } ToFile2_PWORK;                     /* '<Root>/To File2' */

  struct {
    void *FilePtr;
  } ToFile3_PWORK;                     /* '<Root>/To File3' */

  struct {
    void *FilePtr;
  } ToFile4_PWORK;                     /* '<Root>/To File4' */

  struct {
    void *FilePtr;
  } ToFile5_PWORK;                     /* '<Root>/To File5' */

  struct {
    void *FilePtr;
  } ToFile_PWORK_l;                    /* '<S1>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK_l;                   /* '<S1>/To File1' */

  int_T Integrator_IWORK;              /* '<S6>/Integrator' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<Root>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<Root>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile2_IWORK;                     /* '<Root>/To File2' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile3_IWORK;                     /* '<Root>/To File3' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile4_IWORK;                     /* '<Root>/To File4' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile5_IWORK;                     /* '<Root>/To File5' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK_m;                    /* '<S1>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK_i;                   /* '<S1>/To File1' */

  uint8_T Inputtomodel_DWORK2[12];     /* '<Root>/Input to model' */
  uint8_T OutputtoWorkspace_DWORK2[12];/* '<Root>/Output to Workspace' */
  uint8_T x_ref_DWORK2[12];            /* '<Root>/x_ref' */
  uint8_T x_t_DWORK2[12];              /* '<Root>/x_t' */
  uint8_T y_ref_DWORK2[12];            /* '<Root>/y_ref' */
  uint8_T y_t_DWORK2[12];              /* '<Root>/y_t' */
  uint8_T reset_DWORK2[12];            /* '<S4>/reset' */
  uint8_T x_hat_DWORK2[12];            /* '<S41>/x_hat' */
  uint8_T y_hat_DWORK2[12];            /* '<S41>/y_hat' */
  uint8_T psi_hat_DWORK2[12];          /* '<S41>/psi_hat' */
  uint8_T u_hat_DWORK2[12];            /* '<S43>/u_hat' */
  uint8_T v_hat_DWORK2[12];            /* '<S43>/v_hat' */
  uint8_T r_hat_DWORK2[12];            /* '<S43>/r_hat' */
  uint8_T x_m_DWORK2[12];              /* '<S11>/x_m' */
  uint8_T y_m_DWORK2[12];              /* '<S11>/y_m' */
  uint8_T psi_m_DWORK2[12];            /* '<S11>/psi_m' */
  uint8_T psi_refdeg_DWORK2[12];       /* '<Root>/psi_ref [deg]' */
  uint8_T alpha_u_DWORK2[12];          /* '<S1>/alpha_u' */
  uint8_T K1_u_DWORK2[12];             /* '<S1>/K1_u' */
  uint8_T K1_r_DWORK2[12];             /* '<S1>/K1_r' */
  uint8_T alpha_r_DWORK2[12];          /* '<S1>/alpha_r' */
  uint8_T u_dot_hat_DWORK2[12];        /* '<S42>/u_dot_hat' */
  uint8_T v_dot_hat_DWORK2[12];        /* '<S42>/v_dot_hat' */
  uint8_T r_dot_hat_DWORK2[12];        /* '<S42>/r_dot_hat' */
  uint8_T b_x_hat_DWORK2[12];          /* '<S40>/b_x_hat' */
  uint8_T b_y_hat_DWORK2[12];          /* '<S40>/b_y_hat' */
  uint8_T b_psi_hat_DWORK2[12];        /* '<S40>/b_psi_hat' */
  uint8_T alpha1_DWORK2[12];           /* '<S8>/alpha1' */
  uint8_T alpha2_DWORK2[12];           /* '<S8>/alpha2' */
  uint8_T alpha3_DWORK2[12];           /* '<S8>/alpha3' */
  uint8_T alpha4_DWORK2[12];           /* '<S8>/alpha4' */
  uint8_T alpha5_DWORK2[12];           /* '<S8>/alpha5' */
  uint8_T alpha6_DWORK2[12];           /* '<S8>/alpha6' */
  uint8_T u1_DWORK2[12];               /* '<S8>/u1' */
  uint8_T u2_DWORK2[12];               /* '<S8>/u2' */
  uint8_T u3_DWORK2[12];               /* '<S8>/u3' */
  uint8_T u4_DWORK2[12];               /* '<S8>/u4' */
  uint8_T u5_DWORK2[12];               /* '<S8>/u5' */
  uint8_T u6_DWORK2[12];               /* '<S8>/u6' */
  uint8_T psi_t_DWORK2[12];            /* '<Root>/psi_t' */
  uint8_T Acc_x_DWORK2[12];            /* '<S3>/Acc_x' */
  uint8_T Acc_y_DWORK2[12];            /* '<S3>/Acc_y' */
  uint8_T Acc_z_DWORK2[12];            /* '<S3>/Acc_z' */
  uint8_T Gyro_x_DWORK2[12];           /* '<S3>/Gyro_x' */
  uint8_T Gyro_y_DWORK2[12];           /* '<S3>/Gyro_y' */
  uint8_T Gyro_z_DWORK2[12];           /* '<S3>/Gyro_z' */
  uint8_T K_p_x_DWORK2[12];            /* '<S22>/K_p_x' */
  uint8_T K_p_y_DWORK2[12];            /* '<S22>/K_p_y' */
  uint8_T K_p_psi_DWORK2[12];          /* '<S22>/K_p_psi' */
  uint8_T K_i_psi_DWORK2[12];          /* '<S22>/K_i_psi' */
  uint8_T K_i_x_DWORK2[12];            /* '<S22>/K_i_x' */
  uint8_T K_i_y_DWORK2[12];            /* '<S22>/K_i_y' */
  uint8_T K_d_psi_DWORK2[12];          /* '<S22>/K_d_psi' */
  uint8_T K_d_x_DWORK2[12];            /* '<S22>/K_d_x' */
  uint8_T K_d_y_DWORK2[12];            /* '<S22>/K_d_y' */
  uint8_T w_d_x_DWORK2[12];            /* '<S23>/w_d_x' */
  uint8_T w_d_y_DWORK2[12];            /* '<S23>/w_d_y' */
  uint8_T w_d_psi_DWORK2[12];          /* '<S23>/w_d_psi' */
  uint8_T zeta_psi_DWORK2[12];         /* '<S23>/zeta_psi' */
  uint8_T zeta_x_DWORK2[12];           /* '<S23>/zeta_x' */
  uint8_T zeta_y_DWORK2[12];           /* '<S23>/zeta_y' */
  boolean_T PHI_not_empty;             /* '<S1>/MATLAB Function4' */
  boolean_T OMEGA_N_not_empty;         /* '<S1>/MATLAB Function4' */
} DW_ctrl_custom_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S6>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S6>/Integrator2' */
} X_ctrl_custom_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S6>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S6>/Integrator2' */
} XDot_ctrl_custom_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S6>/Integrator' */
  boolean_T Integrator1_CSTATE[3];     /* '<S6>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<S6>/Integrator2' */
} XDis_ctrl_custom_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S6>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S6>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S6>/Integrator2' */
} PrevZCX_ctrl_custom_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_custom_B
#define BlockIO                        B_ctrl_custom_T
#define rtX                            ctrl_custom_X
#define ContinuousStates               X_ctrl_custom_T
#define rtXdot                         ctrl_custom_XDot
#define StateDerivatives               XDot_ctrl_custom_T
#define tXdis                          ctrl_custom_XDis
#define StateDisabled                  XDis_ctrl_custom_T
#define rtP                            ctrl_custom_P
#define Parameters                     P_ctrl_custom_T
#define rtDWork                        ctrl_custom_DW
#define D_Work                         DW_ctrl_custom_T
#define rtPrevZCSigState               ctrl_custom_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_custom_T

/* Parameters (auto storage) */
struct P_ctrl_custom_T_ {
  real_T T_pinv[36];                   /* Variable: T_pinv
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Inputtomodel_P1;              /* Expression: width
                                        * Referenced by: '<Root>/Input to model'
                                        */
  real_T Inputtomodel_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/Input to model'
                                        */
  real_T Inputtomodel_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/Input to model'
                                        */
  real_T Inputtomodel_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/Input to model'
                                        */
  real_T Inputtomodel_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/Input to model'
                                        */
  real_T Inputtomodel_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/Input to model'
                                        */
  real_T OutputtoWorkspace_P1;         /* Expression: width
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  real_T OutputtoWorkspace_P2;         /* Expression: dtype
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  real_T OutputtoWorkspace_P3;         /* Expression: portnum
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  real_T OutputtoWorkspace_P4;         /* Expression: stime
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  real_T OutputtoWorkspace_P5;         /* Expression: stype
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  real_T OutputtoWorkspace_P6;         /* Expression: btype
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  real_T x_ref_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T x_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T x_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T x_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T x_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T x_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T x_t_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/x_t'
                                        */
  real_T x_t_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/x_t'
                                        */
  real_T x_t_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/x_t'
                                        */
  real_T x_t_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/x_t'
                                        */
  real_T x_t_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/x_t'
                                        */
  real_T x_t_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/x_t'
                                        */
  real_T y_ref_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T y_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T y_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T y_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T y_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T y_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T y_t_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/y_t'
                                        */
  real_T y_t_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/y_t'
                                        */
  real_T y_t_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/y_t'
                                        */
  real_T y_t_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/y_t'
                                        */
  real_T y_t_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/y_t'
                                        */
  real_T y_t_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/y_t'
                                        */
  real_T reset_P1;                     /* Expression: width
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P4;                     /* Expression: stime
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P5;                     /* Expression: stype
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P6;                     /* Expression: btype
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T x_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T y_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: pi
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T psi_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T u_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T v_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T r_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T x_m_P1;                       /* Expression: width
                                        * Referenced by: '<S11>/x_m'
                                        */
  real_T x_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S11>/x_m'
                                        */
  real_T x_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S11>/x_m'
                                        */
  real_T x_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S11>/x_m'
                                        */
  real_T x_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S11>/x_m'
                                        */
  real_T x_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S11>/x_m'
                                        */
  real_T mm2m_Gain;                    /* Expression: 1/1000
                                        * Referenced by: '<S11>/mm2m'
                                        */
  real_T y_m_P1;                       /* Expression: width
                                        * Referenced by: '<S11>/y_m'
                                        */
  real_T y_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S11>/y_m'
                                        */
  real_T y_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S11>/y_m'
                                        */
  real_T y_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S11>/y_m'
                                        */
  real_T y_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S11>/y_m'
                                        */
  real_T y_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S11>/y_m'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T psi_m_P1;                     /* Expression: width
                                        * Referenced by: '<S11>/psi_m'
                                        */
  real_T psi_m_P2;                     /* Expression: dtype
                                        * Referenced by: '<S11>/psi_m'
                                        */
  real_T psi_m_P3;                     /* Expression: portnum
                                        * Referenced by: '<S11>/psi_m'
                                        */
  real_T psi_m_P4;                     /* Expression: stime
                                        * Referenced by: '<S11>/psi_m'
                                        */
  real_T psi_m_P5;                     /* Expression: stype
                                        * Referenced by: '<S11>/psi_m'
                                        */
  real_T psi_m_P6;                     /* Expression: btype
                                        * Referenced by: '<S11>/psi_m'
                                        */
  real_T deg2rad_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S11>/deg2rad'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 1e10
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: -1e10
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Gain6_Gain;                   /* Expression: pi
                                        * Referenced by: '<S11>/Gain6'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Gain_Gain_a;                  /* Expression: pi
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 2*pi
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Integrator2_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant8'
                                        */
  real_T psi_refdeg_P1;                /* Expression: width
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  real_T alpha_u_P1;                   /* Expression: width
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  real_T alpha_u_P2;                   /* Expression: dtype
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  real_T alpha_u_P3;                   /* Expression: portnum
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  real_T alpha_u_P4;                   /* Expression: stime
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  real_T alpha_u_P5;                   /* Expression: stype
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  real_T alpha_u_P6;                   /* Expression: btype
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  real_T K1_u_P1;                      /* Expression: width
                                        * Referenced by: '<S1>/K1_u'
                                        */
  real_T K1_u_P2;                      /* Expression: dtype
                                        * Referenced by: '<S1>/K1_u'
                                        */
  real_T K1_u_P3;                      /* Expression: portnum
                                        * Referenced by: '<S1>/K1_u'
                                        */
  real_T K1_u_P4;                      /* Expression: stime
                                        * Referenced by: '<S1>/K1_u'
                                        */
  real_T K1_u_P5;                      /* Expression: stype
                                        * Referenced by: '<S1>/K1_u'
                                        */
  real_T K1_u_P6;                      /* Expression: btype
                                        * Referenced by: '<S1>/K1_u'
                                        */
  real_T K1_r_P1;                      /* Expression: width
                                        * Referenced by: '<S1>/K1_r'
                                        */
  real_T K1_r_P2;                      /* Expression: dtype
                                        * Referenced by: '<S1>/K1_r'
                                        */
  real_T K1_r_P3;                      /* Expression: portnum
                                        * Referenced by: '<S1>/K1_r'
                                        */
  real_T K1_r_P4;                      /* Expression: stime
                                        * Referenced by: '<S1>/K1_r'
                                        */
  real_T K1_r_P5;                      /* Expression: stype
                                        * Referenced by: '<S1>/K1_r'
                                        */
  real_T K1_r_P6;                      /* Expression: btype
                                        * Referenced by: '<S1>/K1_r'
                                        */
  real_T alpha_r_P1;                   /* Expression: width
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  real_T alpha_r_P2;                   /* Expression: dtype
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  real_T alpha_r_P3;                   /* Expression: portnum
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  real_T alpha_r_P4;                   /* Expression: stime
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  real_T alpha_r_P5;                   /* Expression: stype
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  real_T alpha_r_P6;                   /* Expression: btype
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  real_T Constant_Value_fn;            /* Expression: 127.92-3.262
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 127.92-28.89
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 61.967-13.98
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T deg2rad_Gain_d;               /* Expression: pi/180
                                        * Referenced by: '<Root>/deg2rad'
                                        */
  real_T Constant_Value_e[3];          /* Expression: [0 0 0]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T M1_Gain[9];                   /* Expression: [0.008021948049864 0 0;0 0.010098125265799 1.104781662647098e-04;0 3.303823257820844e-05 0.020839338676560]
                                        * Referenced by: '<S6>/M^-1'
                                        */
  real_T u_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T v_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T r_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T b_x_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_y_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_psi_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T Memory4_X0[6];                /* Expression: [0 0 0 0 0 0]'
                                        * Referenced by: '<S9>/Memory4'
                                        */
  real_T alpha1_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/alpha1'
                                        */
  real_T alpha1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/alpha1'
                                        */
  real_T alpha1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/alpha1'
                                        */
  real_T alpha1_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/alpha1'
                                        */
  real_T alpha1_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/alpha1'
                                        */
  real_T alpha1_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/alpha1'
                                        */
  real_T alpha2_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/alpha2'
                                        */
  real_T alpha2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/alpha2'
                                        */
  real_T alpha2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/alpha2'
                                        */
  real_T alpha2_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/alpha2'
                                        */
  real_T alpha2_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/alpha2'
                                        */
  real_T alpha2_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/alpha2'
                                        */
  real_T alpha3_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/alpha3'
                                        */
  real_T alpha3_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/alpha3'
                                        */
  real_T alpha3_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/alpha3'
                                        */
  real_T alpha3_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/alpha3'
                                        */
  real_T alpha3_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/alpha3'
                                        */
  real_T alpha3_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/alpha3'
                                        */
  real_T alpha4_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/alpha4'
                                        */
  real_T alpha4_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/alpha4'
                                        */
  real_T alpha4_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/alpha4'
                                        */
  real_T alpha4_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/alpha4'
                                        */
  real_T alpha4_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/alpha4'
                                        */
  real_T alpha4_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/alpha4'
                                        */
  real_T alpha5_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/alpha5'
                                        */
  real_T alpha5_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/alpha5'
                                        */
  real_T alpha5_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/alpha5'
                                        */
  real_T alpha5_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/alpha5'
                                        */
  real_T alpha5_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/alpha5'
                                        */
  real_T alpha5_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/alpha5'
                                        */
  real_T alpha6_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/alpha6'
                                        */
  real_T alpha6_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/alpha6'
                                        */
  real_T alpha6_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/alpha6'
                                        */
  real_T alpha6_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/alpha6'
                                        */
  real_T alpha6_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/alpha6'
                                        */
  real_T alpha6_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/alpha6'
                                        */
  real_T u1_P1;                        /* Expression: width
                                        * Referenced by: '<S8>/u1'
                                        */
  real_T u1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S8>/u1'
                                        */
  real_T u1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S8>/u1'
                                        */
  real_T u1_P4;                        /* Expression: stime
                                        * Referenced by: '<S8>/u1'
                                        */
  real_T u1_P5;                        /* Expression: stype
                                        * Referenced by: '<S8>/u1'
                                        */
  real_T u1_P6;                        /* Expression: btype
                                        * Referenced by: '<S8>/u1'
                                        */
  real_T u2_P1;                        /* Expression: width
                                        * Referenced by: '<S8>/u2'
                                        */
  real_T u2_P2;                        /* Expression: dtype
                                        * Referenced by: '<S8>/u2'
                                        */
  real_T u2_P3;                        /* Expression: portnum
                                        * Referenced by: '<S8>/u2'
                                        */
  real_T u2_P4;                        /* Expression: stime
                                        * Referenced by: '<S8>/u2'
                                        */
  real_T u2_P5;                        /* Expression: stype
                                        * Referenced by: '<S8>/u2'
                                        */
  real_T u2_P6;                        /* Expression: btype
                                        * Referenced by: '<S8>/u2'
                                        */
  real_T u3_P1;                        /* Expression: width
                                        * Referenced by: '<S8>/u3'
                                        */
  real_T u3_P2;                        /* Expression: dtype
                                        * Referenced by: '<S8>/u3'
                                        */
  real_T u3_P3;                        /* Expression: portnum
                                        * Referenced by: '<S8>/u3'
                                        */
  real_T u3_P4;                        /* Expression: stime
                                        * Referenced by: '<S8>/u3'
                                        */
  real_T u3_P5;                        /* Expression: stype
                                        * Referenced by: '<S8>/u3'
                                        */
  real_T u3_P6;                        /* Expression: btype
                                        * Referenced by: '<S8>/u3'
                                        */
  real_T u4_P1;                        /* Expression: width
                                        * Referenced by: '<S8>/u4'
                                        */
  real_T u4_P2;                        /* Expression: dtype
                                        * Referenced by: '<S8>/u4'
                                        */
  real_T u4_P3;                        /* Expression: portnum
                                        * Referenced by: '<S8>/u4'
                                        */
  real_T u4_P4;                        /* Expression: stime
                                        * Referenced by: '<S8>/u4'
                                        */
  real_T u4_P5;                        /* Expression: stype
                                        * Referenced by: '<S8>/u4'
                                        */
  real_T u4_P6;                        /* Expression: btype
                                        * Referenced by: '<S8>/u4'
                                        */
  real_T u5_P1;                        /* Expression: width
                                        * Referenced by: '<S8>/u5'
                                        */
  real_T u5_P2;                        /* Expression: dtype
                                        * Referenced by: '<S8>/u5'
                                        */
  real_T u5_P3;                        /* Expression: portnum
                                        * Referenced by: '<S8>/u5'
                                        */
  real_T u5_P4;                        /* Expression: stime
                                        * Referenced by: '<S8>/u5'
                                        */
  real_T u5_P5;                        /* Expression: stype
                                        * Referenced by: '<S8>/u5'
                                        */
  real_T u5_P6;                        /* Expression: btype
                                        * Referenced by: '<S8>/u5'
                                        */
  real_T u6_P1;                        /* Expression: width
                                        * Referenced by: '<S8>/u6'
                                        */
  real_T u6_P2;                        /* Expression: dtype
                                        * Referenced by: '<S8>/u6'
                                        */
  real_T u6_P3;                        /* Expression: portnum
                                        * Referenced by: '<S8>/u6'
                                        */
  real_T u6_P4;                        /* Expression: stime
                                        * Referenced by: '<S8>/u6'
                                        */
  real_T u6_P5;                        /* Expression: stype
                                        * Referenced by: '<S8>/u6'
                                        */
  real_T u6_P6;                        /* Expression: btype
                                        * Referenced by: '<S8>/u6'
                                        */
  real_T deg2rad1_Gain;                /* Expression: 180/pi
                                        * Referenced by: '<Root>/deg2rad1'
                                        */
  real_T psi_t_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/psi_t'
                                        */
  real_T psi_t_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/psi_t'
                                        */
  real_T psi_t_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/psi_t'
                                        */
  real_T psi_t_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/psi_t'
                                        */
  real_T psi_t_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/psi_t'
                                        */
  real_T psi_t_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/psi_t'
                                        */
  real_T Constant_Value_h;             /* Expression: 50
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant1_Value_b3;           /* Expression: 50
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 50
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant5'
                                        */
  real_T Acc_x_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  real_T Acc_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  real_T Acc_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  real_T Acc_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  real_T Acc_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  real_T Acc_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  real_T Acc_y_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  real_T Acc_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  real_T Acc_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  real_T Acc_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  real_T Acc_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  real_T Acc_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  real_T Acc_z_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  real_T Acc_z_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  real_T Acc_z_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  real_T Acc_z_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  real_T Acc_z_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  real_T Acc_z_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  real_T Gyro_x_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  real_T Gyro_x_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  real_T Gyro_x_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  real_T Gyro_x_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  real_T Gyro_x_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  real_T Gyro_x_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  real_T Gyro_y_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  real_T Gyro_y_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  real_T Gyro_y_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  real_T Gyro_y_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  real_T Gyro_y_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  real_T Gyro_y_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  real_T Gyro_z_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  real_T Gyro_z_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  real_T Gyro_z_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  real_T Gyro_z_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  real_T Gyro_z_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  real_T Gyro_z_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  real_T K_p_x_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_y_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_i_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_x_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_y_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T w_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T zeta_psi_P1;                  /* Expression: width
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P2;                  /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P3;                  /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P4;                  /* Expression: stime
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P5;                  /* Expression: stype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P6;                  /* Expression: btype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_x_P1;                    /* Expression: width
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P2;                    /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P3;                    /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P4;                    /* Expression: stime
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P5;                    /* Expression: stype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P6;                    /* Expression: btype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_y_P1;                    /* Expression: width
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P2;                    /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P3;                    /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P4;                    /* Expression: stime
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P5;                    /* Expression: stype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P6;                    /* Expression: btype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_custom_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[9];
  real_T odeF[4][9];
  ODE4_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ctrl_custom_T ctrl_custom_P;

/* Block signals (auto storage) */
extern B_ctrl_custom_T ctrl_custom_B;

/* Continuous states (auto storage) */
extern X_ctrl_custom_T ctrl_custom_X;

/* Block states (auto storage) */
extern DW_ctrl_custom_T ctrl_custom_DW;

/* External data declarations for dependent source files */
extern const real_T ctrl_custom_RGND;  /* real_T ground */

/* Model entry point functions */
extern void ctrl_custom_initialize(void);
extern void ctrl_custom_output(void);
extern void ctrl_custom_update(void);
extern void ctrl_custom_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_custom_rtModel *ctrl_custom(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_custom_T *const ctrl_custom_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ctrl_custom'
 * '<S1>'   : 'ctrl_custom/Control'
 * '<S2>'   : 'ctrl_custom/Guidance'
 * '<S3>'   : 'ctrl_custom/IMU'
 * '<S4>'   : 'ctrl_custom/Input1'
 * '<S5>'   : 'ctrl_custom/Model Info'
 * '<S6>'   : 'ctrl_custom/Nonlinear Passisve Observer'
 * '<S7>'   : 'ctrl_custom/Observer output '
 * '<S8>'   : 'ctrl_custom/Output'
 * '<S9>'   : 'ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation'
 * '<S10>'  : 'ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix'
 * '<S11>'  : 'ctrl_custom/eta_QTM'
 * '<S12>'  : 'ctrl_custom/Control/DP Controller'
 * '<S13>'  : 'ctrl_custom/Control/MATLAB Function'
 * '<S14>'  : 'ctrl_custom/Control/MATLAB Function1'
 * '<S15>'  : 'ctrl_custom/Control/MATLAB Function4'
 * '<S16>'  : 'ctrl_custom/Guidance/Reference model'
 * '<S17>'  : 'ctrl_custom/Guidance/Reference model/[-inf inf] to [-pi pi]1'
 * '<S18>'  : 'ctrl_custom/Guidance/Reference model/w_d*w_d'
 * '<S19>'  : 'ctrl_custom/Guidance/Reference model/w_d*w_d1'
 * '<S20>'  : 'ctrl_custom/Guidance/Reference model/w_d^-2'
 * '<S21>'  : 'ctrl_custom/Guidance/Reference model/w_d^3'
 * '<S22>'  : 'ctrl_custom/Input1/Control Gains'
 * '<S23>'  : 'ctrl_custom/Input1/Guidance gains'
 * '<S24>'  : 'ctrl_custom/Input1/Observer Gains'
 * '<S25>'  : 'ctrl_custom/Input1/Control Gains/MATLAB Function'
 * '<S26>'  : 'ctrl_custom/Input1/Control Gains/MATLAB Function1'
 * '<S27>'  : 'ctrl_custom/Input1/Control Gains/MATLAB Function2'
 * '<S28>'  : 'ctrl_custom/Input1/Guidance gains/MATLAB Function'
 * '<S29>'  : 'ctrl_custom/Input1/Guidance gains/MATLAB Function1'
 * '<S30>'  : 'ctrl_custom/Input1/Observer Gains/MATLAB Function'
 * '<S31>'  : 'ctrl_custom/Input1/Observer Gains/MATLAB Function1'
 * '<S32>'  : 'ctrl_custom/Input1/Observer Gains/MATLAB Function2'
 * '<S33>'  : 'ctrl_custom/Nonlinear Passisve Observer/C(nu)*nu'
 * '<S34>'  : 'ctrl_custom/Nonlinear Passisve Observer/D(nu)*nu'
 * '<S35>'  : 'ctrl_custom/Nonlinear Passisve Observer/Rotation matrix in yaw 1'
 * '<S36>'  : 'ctrl_custom/Nonlinear Passisve Observer/Transpose Rotation Matrix'
 * '<S37>'  : 'ctrl_custom/Nonlinear Passisve Observer/Transpose Rotation matrix'
 * '<S38>'  : 'ctrl_custom/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]'
 * '<S39>'  : 'ctrl_custom/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1'
 * '<S40>'  : 'ctrl_custom/Observer output /b_hat output'
 * '<S41>'  : 'ctrl_custom/Observer output /eta_hat output'
 * '<S42>'  : 'ctrl_custom/Observer output /nu_dot_hat output'
 * '<S43>'  : 'ctrl_custom/Observer output /nu_hat output'
 * '<S44>'  : 'ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11'
 * '<S45>'  : 'ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11'
 */
#endif                                 /* RTW_HEADER_ctrl_custom_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.90
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Wed Sep 20 14:24:54 2017
 *========================================================================*/
#if !defined(NI_HEADER_ctrl_custom_h_)
#define NI_HEADER_ctrl_custom_h_
#ifdef NI_ROOTMODEL_ctrl_custom

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* ctrl_custom.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_ctrl_custom_T rtParameter[NUMST+!TID01EQ];
P_ctrl_custom_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_ctrl_custom_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_ctrl_custom_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_ctrl_custom_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
#endif                                 /* NI_HEADER_ctrl_custom_h_ */
