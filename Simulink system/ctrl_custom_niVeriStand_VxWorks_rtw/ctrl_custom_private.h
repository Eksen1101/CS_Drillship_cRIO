/*
 * ctrl_custom_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_custom".
 *
 * Model version              : 1.101
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Sep 25 14:24:23 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_custom_private_h_
#define RTW_HEADER_ctrl_custom_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "ctrl_custom.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
int_T rt_WriteMat4FileHeader(FILE *fp,
  int32_T m,
  int32_T n,
  const char_T *name);
extern void ctrl_custom_MATLABFunction1(real_T rtu_h, const real_T rtu_eta[3],
  const real_T rtu_eta_prev[3], B_MATLABFunction1_ctrl_custom_T *localB);
extern void ctrl_custom_MATLABFunction2(real_T rtu_a, const real_T rtu_eta_dot[3],
  const real_T rtu_eta_dot_filtered_prev[3], B_MATLABFunction2_ctrl_custom_T
  *localB);
extern void ctrl_custom_diag(real_T rtu_w_d1, B_diag_ctrl_custom_T *localB);

/* private model entry point functions */
extern void ctrl_custom_derivatives(void);

#endif                                 /* RTW_HEADER_ctrl_custom_private_h_ */
