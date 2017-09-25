/*
 * ctrl_custom.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_custom".
 *
 * Model version              : 1.93
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Sep 25 10:58:13 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_custom.h"
#include "ctrl_custom_private.h"

const real_T ctrl_custom_RGND = 0.0;   /* real_T ground */

/* Block signals (auto storage) */
B_ctrl_custom_T ctrl_custom_B;

/* Continuous states */
X_ctrl_custom_T ctrl_custom_X;

/* Block states (auto storage) */
DW_ctrl_custom_T ctrl_custom_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_custom_T ctrl_custom_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_custom_T ctrl_custom_M_;
RT_MODEL_ctrl_custom_T *const ctrl_custom_M = &ctrl_custom_M_;

/* Forward declaration for local functions */
static real_T ctrl_custom_norm_a(const real_T x[2]);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_custom_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S45>/MATLAB Function1'
 *    '<S45>/MATLAB Function8'
 */
void ctrl_custom_MATLABFunction1(real_T rtu_h, const real_T rtu_eta[3], const
  real_T rtu_eta_prev[3], B_MATLABFunction1_ctrl_custom_T *localB)
{
  /* MATLAB Function 'Subsystem/Derivative filter_WO_count/MATLAB Function1': '<S49>:1' */
  /* '<S49>:1:3' */
  /* '<S49>:1:4' */
  localB->eta_dot[0] = (rtu_eta[0] - rtu_eta_prev[0]) / rtu_h;
  localB->eta_dot[1] = (rtu_eta[1] - rtu_eta_prev[1]) / rtu_h;
  localB->eta_dot[2] = (rtu_eta[2] - rtu_eta_prev[2]) / rtu_h;
  if (localB->eta_dot[2] > 5.0) {
    /* '<S49>:1:6' */
    /* '<S49>:1:7' */
    localB->eta_dot[2] = 5.0;
  } else {
    if (localB->eta_dot[2] < -5.0) {
      /* '<S49>:1:8' */
      /* '<S49>:1:9' */
      localB->eta_dot[2] = -5.0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S45>/MATLAB Function2'
 *    '<S45>/MATLAB Function7'
 */
void ctrl_custom_MATLABFunction2(real_T rtu_a, const real_T rtu_eta_dot[3],
  const real_T rtu_eta_dot_filtered_prev[3], B_MATLABFunction2_ctrl_custom_T
  *localB)
{
  /* MATLAB Function 'Subsystem/Derivative filter_WO_count/MATLAB Function2': '<S50>:1' */
  /* '<S50>:1:3' */
  localB->eta_dot_filtered[0] = (1.0 - rtu_a) * rtu_eta_dot_filtered_prev[0] +
    rtu_a * rtu_eta_dot[0];
  localB->eta_dot_filtered[1] = (1.0 - rtu_a) * rtu_eta_dot_filtered_prev[1] +
    rtu_a * rtu_eta_dot[1];
  localB->eta_dot_filtered[2] = (1.0 - rtu_a) * rtu_eta_dot_filtered_prev[2] +
    rtu_a * rtu_eta_dot[2];
}

/*
 * Output and update for atomic system:
 *    '<Root>/diag'
 *    '<Root>/diag1'
 */
void ctrl_custom_diag(real_T rtu_w_d1, B_diag_ctrl_custom_T *localB)
{
  /* MATLAB Function 'diag': '<S12>:1' */
  /* '<S12>:1:4' */
  memset(&localB->w_d[0], 0, 9U * sizeof(real_T));
  localB->w_d[0] = rtu_w_d1;
  localB->w_d[4] = rtu_w_d1;
  localB->w_d[8] = rtu_w_d1;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S11>/MATLAB Function11' */
static real_T ctrl_custom_norm_a(const real_T x[2])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void ctrl_custom_output(void)
{
  /* local block i/o variables */
  real_T rtb_eta_ref[3];
  ZCEventType zcEvent;
  real_T angle_tilde;
  real_T R[9];
  static const real_T a[9] = { 124.658, 0.0, 0.0, 0.0, 99.03, -0.157, 0.0,
    -0.525, 47.986999999999995 };

  real_T x[9];
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  real_T rtb_Gain;
  real_T rtb_u_e[12];
  real_T rtb_K_p_c[9];
  real_T rtb_K_p[9];
  int32_T i;
  real_T rtb_K_p_j[9];
  real_T tmp[9];
  real_T tmp_0[3];
  real_T rtb_K_p_j_0[3];
  real_T rtb_K_p_j_1[9];
  real_T tmp_1[3];
  real_T tmp_2[9];
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  real_T tmp_6[3];
  real_T tmp_7[3];
  real_T rtb_TmpSignalConversionAtMatr_0;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* set solver stop time */
    if (!(ctrl_custom_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_custom_M->solverInfo,
                            ((ctrl_custom_M->Timing.clockTickH0 + 1) *
        ctrl_custom_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_custom_M->solverInfo,
                            ((ctrl_custom_M->Timing.clockTick0 + 1) *
        ctrl_custom_M->Timing.stepSize0 + ctrl_custom_M->Timing.clockTickH0 *
        ctrl_custom_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_custom_M)) {
    ctrl_custom_M->Timing.t[0] = rtsiGetT(&ctrl_custom_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S9>/Memory4' */
    for (i = 0; i < 6; i++) {
      ctrl_custom_B.Memory4[i] = ctrl_custom_DW.Memory4_PreviousInput[i];
    }

    /* End of Memory: '<S9>/Memory4' */
  }

  /* Gain: '<S14>/mm2m' */
  ctrl_custom_B.mm2m = ctrl_custom_P.mm2m_Gain * ctrl_custom_B.x_m;

  /* Gain: '<S14>/Gain1' */
  ctrl_custom_B.Gain1 = ctrl_custom_P.Gain1_Gain * ctrl_custom_B.y_m;

  /* Gain: '<S14>/deg2rad' */
  rtb_Gain = ctrl_custom_P.deg2rad_Gain * ctrl_custom_B.u80180deg;

  /* Saturate: '<S14>/Saturation' */
  if (rtb_Gain > ctrl_custom_P.Saturation_UpperSat) {
    rtb_Gain = ctrl_custom_P.Saturation_UpperSat;
  } else {
    if (rtb_Gain < ctrl_custom_P.Saturation_LowerSat) {
      rtb_Gain = ctrl_custom_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* Signum: '<S14>/Sign' */
  if (rtb_Gain < 0.0) {
    angle_tilde = -1.0;
  } else if (rtb_Gain > 0.0) {
    angle_tilde = 1.0;
  } else if (rtb_Gain == 0.0) {
    angle_tilde = 0.0;
  } else {
    angle_tilde = rtb_Gain;
  }

  /* End of Signum: '<S14>/Sign' */

  /* Gain: '<S14>/Gain6' */
  angle_tilde *= ctrl_custom_P.Gain6_Gain;

  /* Sum: '<S14>/Sum1' */
  rtb_Gain += angle_tilde;

  /* Math: '<S14>/Math Function' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  rtb_Gain = rt_remd_snf(rtb_Gain, ctrl_custom_P.Constant1_Value);

  /* Sum: '<S14>/Sum' */
  ctrl_custom_B.Sum = rtb_Gain - angle_tilde;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S10>/Memory2' */
    ctrl_custom_B.Memory2[0] = ctrl_custom_DW.Memory2_PreviousInput[0];
    ctrl_custom_B.Memory2[1] = ctrl_custom_DW.Memory2_PreviousInput[1];
    ctrl_custom_B.Memory2[2] = ctrl_custom_DW.Memory2_PreviousInput[2];
  }

  /* Product: '<S10>/Product of Elements' incorporates:
   *  Sum: '<S10>/Sum4'
   */
  angle_tilde = (ctrl_custom_B.mm2m - ctrl_custom_B.Memory2[0]) *
    (ctrl_custom_B.Gain1 - ctrl_custom_B.Memory2[1]) * (ctrl_custom_B.Sum -
    ctrl_custom_B.Memory2[2]);

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant11'
   *  Constant: '<S10>/Constant12'
   */
  if (angle_tilde != 0.0) {
    ctrl_custom_B.Switch1 = ctrl_custom_P.Constant11_Value;
  } else {
    ctrl_custom_B.Switch1 = ctrl_custom_P.Constant12_Value;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Integrator: '<S10>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator_Reset_ZCE,
                       (ctrl_custom_B.Switch1));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (ctrl_custom_DW.Integrator_IWORK != 0)) {
      ctrl_custom_X.Integrator_CSTATE[0] = ctrl_custom_B.mm2m;
      ctrl_custom_X.Integrator_CSTATE[1] = ctrl_custom_B.Gain1;
      ctrl_custom_X.Integrator_CSTATE[2] = ctrl_custom_B.Sum;
    }
  }

  /* Switch: '<S10>/Switch' incorporates:
   *  Integrator: '<S10>/Integrator'
   */
  if (angle_tilde != 0.0) {
    ctrl_custom_B.Switch[0] = ctrl_custom_B.mm2m;
    ctrl_custom_B.Switch[1] = ctrl_custom_B.Gain1;
    ctrl_custom_B.Switch[2] = ctrl_custom_B.Sum;
  } else {
    ctrl_custom_B.Switch[0] = ctrl_custom_X.Integrator_CSTATE[0];
    ctrl_custom_B.Switch[1] = ctrl_custom_X.Integrator_CSTATE[1];
    ctrl_custom_B.Switch[2] = ctrl_custom_X.Integrator_CSTATE[2];
  }

  /* End of Switch: '<S10>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S10>/Memory6' */
    ctrl_custom_B.Memory6[0] = ctrl_custom_DW.Memory6_PreviousInput[0];
    ctrl_custom_B.Memory6[1] = ctrl_custom_DW.Memory6_PreviousInput[1];
    ctrl_custom_B.Memory6[2] = ctrl_custom_DW.Memory6_PreviousInput[2];

    /* Memory: '<S10>/Memory7' */
    ctrl_custom_B.Memory7 = ctrl_custom_DW.Memory7_PreviousInput;
  }

  /* MATLAB Function: '<S10>/wraphandle' */
  /* MATLAB Function 'Subsystem/wraphandle': '<S47>:1' */
  /* '<S47>:1:3' */
  rtb_Gain = ctrl_custom_B.Switch[2] * 180.0 / 3.1415926535897931;

  /* +count*360; */
  /* '<S47>:1:4' */
  /* +count*360; */
  /* '<S47>:1:6' */
  angle_tilde = rtb_Gain - ctrl_custom_B.Memory6[2] * 180.0 / 3.1415926535897931;
  if (fabs(angle_tilde) > 300.0) {
    /* '<S47>:1:8' */
    /* '<S47>:1:9' */
    if (angle_tilde < 0.0) {
      angle_tilde = -1.0;
    } else if (angle_tilde > 0.0) {
      angle_tilde = 1.0;
    } else {
      if (angle_tilde == 0.0) {
        angle_tilde = 0.0;
      }
    }

    angle_tilde = -angle_tilde + ctrl_custom_B.Memory7;

    /* '<S47>:1:10' */
    rtb_Gain += angle_tilde * 360.0;
  } else {
    /* '<S47>:1:12' */
    angle_tilde = ctrl_custom_B.Memory7;

    /* '<S47>:1:13' */
    rtb_Gain += ctrl_custom_B.Memory7 * 360.0;
  }

  /* '<S47>:1:16' */
  /* '<S47>:1:17' */
  rtb_TmpSignalConversionAtMatr_0 = rtb_Gain * 3.1415926535897931 / 180.0;
  ctrl_custom_B.count_out = angle_tilde;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S45>/Memory6' */
    ctrl_custom_B.Memory6_n[0] = ctrl_custom_DW.Memory6_PreviousInput_c[0];
    ctrl_custom_B.Memory6_n[1] = ctrl_custom_DW.Memory6_PreviousInput_c[1];
    ctrl_custom_B.Memory6_n[2] = ctrl_custom_DW.Memory6_PreviousInput_c[2];

    /* Memory: '<S45>/Memory7' */
    ctrl_custom_B.Memory7_p = ctrl_custom_DW.Memory7_PreviousInput_n;
  }

  /* MATLAB Function: '<S45>/MATLAB Function4' incorporates:
   *  SignalConversion: '<S52>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Subsystem/Derivative filter_WO_count/MATLAB Function4': '<S52>:1' */
  /* '<S52>:1:3' */
  rtb_Gain = ctrl_custom_B.Sum * 180.0 / 3.1415926535897931;

  /* +count*360; */
  /* '<S52>:1:4' */
  /* +count*360; */
  /* '<S52>:1:6' */
  angle_tilde = rtb_Gain - ctrl_custom_B.Memory6_n[2] * 180.0 /
    3.1415926535897931;
  if (fabs(angle_tilde) > 300.0) {
    /* '<S52>:1:8' */
    /* '<S52>:1:9' */
    if (angle_tilde < 0.0) {
      angle_tilde = -1.0;
    } else if (angle_tilde > 0.0) {
      angle_tilde = 1.0;
    } else {
      if (angle_tilde == 0.0) {
        angle_tilde = 0.0;
      }
    }

    angle_tilde = -angle_tilde + ctrl_custom_B.Memory7_p;

    /* '<S52>:1:10' */
    rtb_Gain += angle_tilde * 360.0;
  } else {
    /* '<S52>:1:12' */
    angle_tilde = ctrl_custom_B.Memory7_p;

    /* '<S52>:1:13' */
    rtb_Gain += ctrl_custom_B.Memory7_p * 360.0;
  }

  /* '<S52>:1:16' */
  /* '<S52>:1:17' */
  ctrl_custom_B.count_out_c = angle_tilde;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S45>/Memory2' */
    ctrl_custom_B.Memory2_n[0] = ctrl_custom_DW.Memory2_PreviousInput_m[0];

    /* Memory: '<S45>/Memory5' */
    ctrl_custom_B.Memory5[0] = ctrl_custom_DW.Memory5_PreviousInput[0];

    /* Memory: '<S45>/Memory2' */
    ctrl_custom_B.Memory2_n[1] = ctrl_custom_DW.Memory2_PreviousInput_m[1];

    /* Memory: '<S45>/Memory5' */
    ctrl_custom_B.Memory5[1] = ctrl_custom_DW.Memory5_PreviousInput[1];

    /* Memory: '<S45>/Memory2' */
    ctrl_custom_B.Memory2_n[2] = ctrl_custom_DW.Memory2_PreviousInput_m[2];

    /* Memory: '<S45>/Memory5' */
    ctrl_custom_B.Memory5[2] = ctrl_custom_DW.Memory5_PreviousInput[2];
  }

  /* MATLAB Function: '<S45>/MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant2'
   *  MATLAB Function: '<S45>/MATLAB Function4'
   *  SignalConversion: '<S52>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Subsystem/Derivative filter_WO_count/MATLAB Function': '<S48>:1' */
  /* '<S48>:1:7' */
  ctrl_custom_B.eta_filtered[0] = (1.0 - ctrl_custom_P.Constant2_Value) *
    ctrl_custom_B.Memory2_n[0] + ctrl_custom_P.Constant2_Value *
    ctrl_custom_B.mm2m;
  ctrl_custom_B.eta_filtered[1] = (1.0 - ctrl_custom_P.Constant2_Value) *
    ctrl_custom_B.Memory2_n[1] + ctrl_custom_P.Constant2_Value *
    ctrl_custom_B.Gain1;
  ctrl_custom_B.eta_filtered[2] = rtb_Gain * 3.1415926535897931 / 180.0 *
    ctrl_custom_P.Constant2_Value + (1.0 - ctrl_custom_P.Constant2_Value) *
    ctrl_custom_B.Memory2_n[2];

  /* MATLAB Function: '<S45>/MATLAB Function1' incorporates:
   *  Constant: '<S45>/Stepsize'
   */
  ctrl_custom_MATLABFunction1(ctrl_custom_P.Stepsize_Value,
    ctrl_custom_B.eta_filtered, ctrl_custom_B.Memory2_n,
    &ctrl_custom_B.sf_MATLABFunction1);
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S45>/Memory3' */
    ctrl_custom_B.Memory3[0] = ctrl_custom_DW.Memory3_PreviousInput[0];
    ctrl_custom_B.Memory3[1] = ctrl_custom_DW.Memory3_PreviousInput[1];
    ctrl_custom_B.Memory3[2] = ctrl_custom_DW.Memory3_PreviousInput[2];
  }

  /* MATLAB Function: '<S45>/MATLAB Function2' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  ctrl_custom_MATLABFunction2(ctrl_custom_P.Constant3_Value,
    ctrl_custom_B.sf_MATLABFunction1.eta_dot, ctrl_custom_B.Memory3,
    &ctrl_custom_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S45>/Memory4' */
    ctrl_custom_B.Memory4_p[0] = ctrl_custom_DW.Memory4_PreviousInput_l[0];

    /* Memory: '<S45>/Memory1' */
    ctrl_custom_B.Memory1[0] = ctrl_custom_DW.Memory1_PreviousInput[0];

    /* Memory: '<S45>/Memory4' */
    ctrl_custom_B.Memory4_p[1] = ctrl_custom_DW.Memory4_PreviousInput_l[1];

    /* Memory: '<S45>/Memory1' */
    ctrl_custom_B.Memory1[1] = ctrl_custom_DW.Memory1_PreviousInput[1];

    /* Memory: '<S45>/Memory4' */
    ctrl_custom_B.Memory4_p[2] = ctrl_custom_DW.Memory4_PreviousInput_l[2];

    /* Memory: '<S45>/Memory1' */
    ctrl_custom_B.Memory1[2] = ctrl_custom_DW.Memory1_PreviousInput[2];
  }

  /* MATLAB Function: '<S45>/MATLAB Function3' incorporates:
   *  Fcn: '<S45>/Fcn'
   *  SignalConversion: '<S51>/TmpSignal ConversionAt SFunction Inport3'
   */
  /* MATLAB Function 'Subsystem/Derivative filter_WO_count/MATLAB Function3': '<S51>:1' */
  /* '<S51>:1:14' */
  if ((ctrl_custom_B.Memory4_p[0] == ctrl_custom_B.mm2m) ||
      (ctrl_custom_B.Memory4_p[1] == ctrl_custom_B.Gain1) ||
      (ctrl_custom_B.Memory4_p[2] == ctrl_custom_B.Sum)) {
    /* '<S51>:1:4' */
    /* '<S51>:1:5' */
    ctrl_custom_B.nu[0] = ctrl_custom_B.Memory1[0];
    ctrl_custom_B.nu[1] = ctrl_custom_B.Memory1[1];
    ctrl_custom_B.nu[2] = ctrl_custom_B.Memory1[2];

    /* '<S51>:1:6' */
  } else {
    /* if count == 1 */
    /* nu = prev_nu; */
    /* count_out = 0; */
    /* else */
    /* '<S51>:1:12' */
    /* '<S51>:1:15' */
    x[0] = cos(ctrl_custom_B.Sum);
    x[3] = sin(ctrl_custom_B.Sum);
    x[6] = 0.0;
    x[1] = -sin(ctrl_custom_B.Sum);
    x[4] = cos(ctrl_custom_B.Sum);
    x[7] = 0.0;
    x[2] = 0.0;
    x[5] = 0.0;
    x[8] = 1.0;
    for (i = 0; i < 3; i++) {
      ctrl_custom_B.nu[i] = 0.0;
      ctrl_custom_B.nu[i] += x[i] *
        ctrl_custom_B.sf_MATLABFunction2.eta_dot_filtered[0];
      ctrl_custom_B.nu[i] += x[i + 3] *
        ctrl_custom_B.sf_MATLABFunction2.eta_dot_filtered[1];
      ctrl_custom_B.nu[i] += x[i + 6] *
        ctrl_custom_B.sf_MATLABFunction2.eta_dot_filtered[2];
    }

    /* '<S51>:1:16' */
    /* end */
  }

  /* End of MATLAB Function: '<S45>/MATLAB Function3' */

  /* MATLAB Function: '<S1>/MATLAB Function' */
  /* MATLAB Function 'Control/MATLAB Function': '<S16>:1' */
  /* '<S16>:1:4' */
  memset(&rtb_K_p_c[0], 0, 9U * sizeof(real_T));

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  memset(&rtb_K_p[0], 0, 9U * sizeof(real_T));

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  SignalConversion: '<S16>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_K_p_c[0] = ctrl_custom_B.K1_u;
  rtb_K_p_c[4] = ctrl_custom_B.K1_u;
  rtb_K_p_c[8] = ctrl_custom_B.K1_r;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product1'
   *  Product: '<S1>/Product2'
   */
  /* MATLAB Function 'Control/MATLAB Function1': '<S17>:1' */
  /* '<S17>:1:4' */
  rtb_K_p[0] = ctrl_custom_P.Constant_Value * ctrl_custom_B.alpha_u;
  rtb_K_p[4] = ctrl_custom_B.alpha_u * ctrl_custom_P.Constant1_Value_b;
  rtb_K_p[8] = ctrl_custom_B.alpha_r * ctrl_custom_P.Constant2_Value_c;

  /* Gain: '<Root>/deg2rad' */
  ctrl_custom_B.deg2rad = ctrl_custom_P.deg2rad_Gain_d *
    ctrl_custom_B.psi_refdeg;

  /* MATLAB Function: '<S1>/MATLAB Function4' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLAB Function: '<S10>/wraphandle'
   *  SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport3'
   */
  /* MATLAB Function 'Control/MATLAB Function4': '<S18>:1' */
  /* '<S18>:1:109' */
  /*   [ tau,theta ] = Adaptiv_controller(Eta,nu,nu_dot,phi,theta_t,Eta_d,Eta_dtheta,Eta_dtheta2,v_s,v_stheta,v_st,h) */
  /* UNTITLED6 Summary of this function goes here Skjetne */
  /*    Detailed explanation goes here */
  /* kan være den må løses på en smartere måte */
  /* include Model_c to path */
  if ((!ctrl_custom_DW.PHI_not_empty) || (!ctrl_custom_DW.OMEGA_N_not_empty)) {
    /* '<S18>:1:12' */
    /* '<S18>:1:13' */
    ctrl_custom_DW.PHI_not_empty = true;

    /* '<S18>:1:14' */
    ctrl_custom_DW.OMEGA_N_not_empty = true;

    /* '<S18>:1:15' */
    /* '<S18>:1:16' */
    /* '<S18>:1:17' */
    /* '<S18>:1:18' */
    /* '<S18>:1:19' */
    /* '<S18>:1:20' */
    /* '<S18>:1:21' */
    /* '<S18>:1:22' */
    /* '<S18>:1:23' */
    /* '<S18>:1:24' */
    /* '<S18>:1:25' */
  }

  /* 14.79; */
  /* 0.0375; */
  /* 1.7600;   */
  /* -2.0;											% Table B.1 */
  /* -10.0; */
  /* -0.0;		% Table B.1 */
  /*   -0.0; */
  /* -1.0;		% Table B.1 */
  /*     */
  /*  Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S18>:1:49' */
  /* -0.6555;		X_v		= 0; */
  /* '<S18>:1:50' */
  /* 0.3545;		X_vv	= -2.443; */
  /* '<S18>:1:51' */
  /* -3.787;		X_vvv	= 0; */
  /* '<S18>:1:53' */
  /* -1.33; 			Y_r		= -7.250; % Y_r */
  /* '<S18>:1:54' */
  /* -2.776;			Y_rr	= -3.450; % Y_rr */
  /* '<S18>:1:55' */
  /* -64.91;			Y_rrr	= 0; */
  /* '<S18>:1:57' */
  /* -7.250; % Y_r */
  /* '<S18>:1:58' */
  /* -3.450; % Y_rr */
  /* '<S18>:1:59' */
  /* Y_rv	= -0.805;			Y_vr	= -0.845; % Y_rv, Y_vr */
  /* '<S18>:1:64' */
  /* N_r		= -1.900; % N_r */
  /* '<S18>:1:65' */
  /* N_rr	= -0.750; % N_rr */
  /* '<S18>:1:66' */
  /* N_rrr	= 0; */
  /* '<S18>:1:68' */
  /* -1.900; % N_r */
  /* '<S18>:1:69' */
  /* -0.750; % N_rr */
  /* '<S18>:1:70' */
  /* 0; */
  /* N_rv	= 0.130;			N_vr	= 0.080; % N_rv, N_vr */
  /* '<S18>:1:75' */
  /* '<S18>:1:194' */
  /* {       */
  /* function [ d ] = G_d(nu) */
  /*       %#codegen */
  /* X_u		= -0.6555; */
  /* Y_v		= -1.33; */
  /* N_v		= 0; */
  /*  */
  /*     v=[nu(1) nu(2) 0]'; */
  /*  */
  /*       D_L_uv=[-X_u    0  0 ; */
  /*             0     -Y_v 0; */
  /*             0     -N_v 0]; */
  /*       d=(D_L_uv+D_NL_uv(v))*v; */
  /*  */
  /* end */
  /*  */
  /* function matrix = D_NL_uv(V) */
  /*       %#codegen */
  /*  */
  /*   */
  /* 	 */
  /* X_uu 	= 0.3545;		X_vv	= -2.443; */
  /* X_uuu 	= -3.787;	 */
  /*  */
  /* 			 */
  /* Y_vv	= -2.776;			 */
  /* Y_vvv	= -64.91; */
  /*  */
  /* N_vv	= -0.2088;	 */
  /*  */
  /*     u=V(1); */
  /*     v=V(2); */
  /*      */
  /*      matrix=[-X_uu*abs(u)-X_uuu*u^2 0 0; */
  /*             0 -Y_vv*abs(v)-Y_vvv*v^2 0; */
  /*             0 -N_vv*abs(v) 0]; */
  /* end */
  /* } */
  /* '<S18>:1:191' */
  /* '<S18>:1:192' */
  R[0] = cos(rtb_TmpSignalConversionAtMatr_0);
  R[3] = -sin(rtb_TmpSignalConversionAtMatr_0);
  R[6] = 0.0;
  R[1] = sin(rtb_TmpSignalConversionAtMatr_0);
  R[4] = cos(rtb_TmpSignalConversionAtMatr_0);
  R[7] = 0.0;

  /* '<S18>:1:77' */
  /* '<S18>:1:78' */
  /* '<S18>:1:79' */
  /* '<S18>:1:81' */
  /* '<S18>:1:82' */
  /* - Y_rv*abs(r); */
  /* '<S18>:1:83' */
  /* - N_vr*abs(v); % using abs(r) */
  /* -X_v - X_vv*v - X_vvv*v^2; */
  /* '<S18>:1:86' */
  /*  - Y_vr*abs(v); */
  /* '<S18>:1:87' */
  /*  - N_rv*abs(r); */
  /* '<S18>:1:89' */
  /*  controlsignaler */
  /* '<S18>:1:94' */
  /* '<S18>:1:95' */
  /* '<S18>:1:96' */
  /* %%%%%%%%%%%%%%%%%%%%% */
  /*  New Controller */
  /* '<S18>:1:99' */
  R[2] = 0.0;
  rtb_Gain = ctrl_custom_B.Switch[0] - ctrl_custom_B.x_ref;
  R[5] = 0.0;
  angle_tilde = ctrl_custom_B.Switch[1] - ctrl_custom_B.y_ref;
  R[8] = 1.0;
  rtb_TmpSignalConversionAtMatr_0 -= ctrl_custom_B.deg2rad;

  /* '<S18>:1:101' */
  /* '<S18>:1:102' */
  for (i = 0; i < 3; i++) {
    ctrl_custom_B.z_1[i] = 0.0;
    ctrl_custom_B.z_1[i] += R[3 * i] * rtb_Gain;
    rtb_K_p_j[3 * i] = -rtb_K_p_c[3 * i];
    ctrl_custom_B.z_1[i] += R[3 * i + 1] * angle_tilde;
    rtb_K_p_j[1 + 3 * i] = -rtb_K_p_c[3 * i + 1];
    ctrl_custom_B.z_1[i] += R[3 * i + 2] * rtb_TmpSignalConversionAtMatr_0;
    rtb_K_p_j[2 + 3 * i] = -rtb_K_p_c[3 * i + 2];
  }

  /* '<S18>:1:104' */
  /* { */
  /* function R_d = Rot_dot(nu,eta) */
  /*  takes in the nu vector  */
  /*       %#codegen */
  /*  */
  /* R_d=S([0 0 nu(3)])*Rot([0 0 eta(3)]); */
  /*  */
  /* end */
  /* } */
  /* UNTITLED2 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /* '<S18>:1:211' */
  /* { */
  /* function [ phi ] = Phi( nu ) */
  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*       %#codegen */
  /*  */
  /* v=nu(2); */
  /* IvI=abs(v); */
  /* r=nu(3); */
  /* IrI=abs(r); */
  /*  */
  /* phi=[0 0 0 0 0 0 0 0; */
  /*      -IrI*v -r -IvI*r -IrI*r 0 0 0 0; */
  /*      0 0 0 0 -IrI*v -r -IvI*r -IrI*r]; */
  /*  */
  /* end */
  /* } */
  /* '<S18>:1:105' */
  /* { */
  /* function R_d = Rot_dot(nu,eta) */
  /*  takes in the nu vector  */
  /*       %#codegen */
  /*  */
  /* R_d=S([0 0 nu(3)])*Rot([0 0 eta(3)]); */
  /*  */
  /* end */
  /* } */
  /* UNTITLED2 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /* '<S18>:1:211' */
  /* { */
  /* function [ phi ] = Phi( nu ) */
  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*       %#codegen */
  /*  */
  /* v=nu(2); */
  /* IvI=abs(v); */
  /* r=nu(3); */
  /* IrI=abs(r); */
  /*  */
  /* phi=[0 0 0 0 0 0 0 0; */
  /*      -IrI*v -r -IvI*r -IrI*r 0 0 0 0; */
  /*      0 0 0 0 -IrI*v -r -IvI*r -IrI*r]; */
  /*  */
  /* end */
  /* } */
  /*  TAU  */
  /* tau=C_c(nu)*nu+D*nu+M_c*Alpha_1dot-K_d*z_2; */
  /* '<S18>:1:109' */
  /* '<S18>:1:110' */
  tmp[0] = 0.0;
  tmp[1] = -ctrl_custom_B.nu[2];
  tmp[2] = ctrl_custom_B.nu[1];
  tmp[3] = ctrl_custom_B.nu[2];
  tmp[4] = 0.0;
  tmp[5] = -ctrl_custom_B.nu[0];
  tmp[6] = -ctrl_custom_B.nu[1];
  tmp[7] = ctrl_custom_B.nu[0];
  tmp[8] = 0.0;
  tmp_2[0] = 0.0;
  tmp_2[1] = -ctrl_custom_B.nu[2];
  tmp_2[2] = ctrl_custom_B.nu[1];
  tmp_2[3] = ctrl_custom_B.nu[2];
  tmp_2[4] = 0.0;
  tmp_2[5] = -ctrl_custom_B.nu[0];
  tmp_2[6] = -ctrl_custom_B.nu[1];
  tmp_2[7] = ctrl_custom_B.nu[0];
  tmp_2[8] = 0.0;
  for (i = 0; i < 3; i++) {
    ctrl_custom_B.z_2[i] = ctrl_custom_B.nu[i] - ((rtb_K_p_j[i + 6] *
      ctrl_custom_B.z_1[2] + (rtb_K_p_j[i + 3] * ctrl_custom_B.z_1[1] +
      rtb_K_p_j[i] * ctrl_custom_B.z_1[0])) + (R[3 * i + 2] *
      ctrl_custom_P.Constant_Value_e[2] + (R[3 * i + 1] *
      ctrl_custom_P.Constant_Value_e[1] + R[3 * i] *
      ctrl_custom_P.Constant_Value_e[0])));
    tmp_0[i] = 0.0;
    rtb_K_p_j_0[i] = 0.0;
    for (p2 = 0; p2 < 3; p2++) {
      rtb_K_p_j_1[p2 + 3 * i] = -rtb_K_p_c[3 * i + p2];
      x[i + 3 * p2] = 0.0;
      x[i + 3 * p2] += tmp_2[i] * R[p2];
      x[i + 3 * p2] += tmp_2[i + 3] * R[p2 + 3];
      x[i + 3 * p2] += tmp_2[i + 6] * R[p2 + 6];
      tmp_0[i] += tmp[3 * p2 + i] * ctrl_custom_B.z_1[p2];
      rtb_K_p_j_0[i] += rtb_K_p_c[3 * p2 + i] * ctrl_custom_B.z_1[p2];
    }

    tmp_1[i] = (tmp_0[i] - rtb_K_p_j_0[i]) + ctrl_custom_B.z_2[i];
  }

  for (i = 0; i < 3; i++) {
    rtb_K_p_j_0[i] = ((R[3 * i + 1] * ctrl_custom_P.Constant_Value_e[1] + R[3 *
                       i] * ctrl_custom_P.Constant_Value_e[0]) + R[3 * i + 2] *
                      ctrl_custom_P.Constant_Value_e[2]) + ((rtb_K_p_j_1[i + 6] *
      tmp_1[2] + (rtb_K_p_j_1[i + 3] * tmp_1[1] + rtb_K_p_j_1[i] * tmp_1[0])) +
      (x[i + 6] * ctrl_custom_P.Constant_Value_e[2] + (x[i + 3] *
      ctrl_custom_P.Constant_Value_e[1] + x[i] * ctrl_custom_P.Constant_Value_e
      [0])));
  }

  for (i = 0; i < 3; i++) {
    ctrl_custom_B.tau1[i] = (a[i + 6] * rtb_K_p_j_0[2] + (a[i + 3] *
      rtb_K_p_j_0[1] + a[i] * rtb_K_p_j_0[0])) - (rtb_K_p[i + 6] *
      ctrl_custom_B.z_2[2] + (rtb_K_p[i + 3] * ctrl_custom_B.z_2[1] + rtb_K_p[i]
      * ctrl_custom_B.z_2[0]));
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function4' */

  /* Gain: '<S11>/Gain' */
  /*  */
  /* '<S18>:1:113' */
  /* '<S18>:1:114' */
  /* Coreolis matrix */
  /* '<S18>:1:120' */
  /* '<S18>:1:124' */
  /* 14.79; */
  /* '<S18>:1:125' */
  /* 0.0375; */
  /* 1.7600;   */
  /* '<S18>:1:127' */
  /* '<S18>:1:128' */
  /* '<S18>:1:129' */
  /* '<S18>:1:130' */
  /* '<S18>:1:136' */
  /* -2.0;											% Table B.1 */
  /* '<S18>:1:137' */
  /* -10.0; */
  /* '<S18>:1:138' */
  /* -0.0;		% Table B.1 */
  /* '<S18>:1:139' */
  /*   -0.0; */
  /* -1.0;		% Table B.1 */
  /* '<S18>:1:142' */
  /* '<S18>:1:143' */
  /* '<S18>:1:144' */
  /* '<S18>:1:145' */
  for (i = 0; i < 12; i++) {
    rtb_u_e[i] = ctrl_custom_P.T_pinv[i + 24] * ctrl_custom_B.tau1[2] +
      (ctrl_custom_P.T_pinv[i + 12] * ctrl_custom_B.tau1[1] +
       ctrl_custom_P.T_pinv[i] * ctrl_custom_B.tau1[0]);
  }

  /* End of Gain: '<S11>/Gain' */

  /* MATLAB Function: '<S11>/MATLAB Function11' */
  /* MATLAB Function 'Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11': '<S55>:1' */
  /* '<S55>:1:2' */
  rtb_Gain = ctrl_custom_norm_a(&rtb_u_e[0]);
  angle_tilde = ctrl_custom_norm_a(&rtb_u_e[2]);
  rtb_TmpSignalConversionAtMatr_0 = ctrl_custom_norm_a(&rtb_u_e[4]);
  tmp_3 = ctrl_custom_norm_a(&rtb_u_e[6]);
  tmp_4 = ctrl_custom_norm_a(&rtb_u_e[8]);
  tmp_5 = ctrl_custom_norm_a(&rtb_u_e[10]);
  ctrl_custom_B.u[0] = rtb_Gain;
  ctrl_custom_B.u[1] = angle_tilde;
  ctrl_custom_B.u[2] = rtb_TmpSignalConversionAtMatr_0;
  ctrl_custom_B.u[3] = tmp_3;
  ctrl_custom_B.u[4] = tmp_4;
  ctrl_custom_B.u[5] = tmp_5;

  /* '<S55>:1:10' */
  ctrl_custom_B.alpha[0] = rt_atan2d_snf(rtb_u_e[1], rtb_u_e[0]);
  ctrl_custom_B.alpha[1] = rt_atan2d_snf(rtb_u_e[3], rtb_u_e[2]);
  ctrl_custom_B.alpha[2] = rt_atan2d_snf(rtb_u_e[5], rtb_u_e[4]);
  ctrl_custom_B.alpha[3] = rt_atan2d_snf(rtb_u_e[7], rtb_u_e[6]);
  ctrl_custom_B.alpha[4] = rt_atan2d_snf(rtb_u_e[9], rtb_u_e[8]);
  ctrl_custom_B.alpha[5] = rt_atan2d_snf(rtb_u_e[11], rtb_u_e[10]);

  /* MATLAB Function: '<S9>/MATLAB Function11' */
  /* MATLAB Function 'Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11': '<S44>:1' */
  /* '<S44>:1:1' */
  /* '<S44>:1:4' */
  for (i = 0; i < 6; i++) {
    /* '<S44>:1:4' */
    /*  current rotation */
    /* '<S44>:1:6' */
    /* '<S44>:1:8' */
    if (ctrl_custom_B.Memory4[i] < 0.0) {
      rtb_Gain = -1.0;
    } else if (ctrl_custom_B.Memory4[i] > 0.0) {
      rtb_Gain = 1.0;
    } else if (ctrl_custom_B.Memory4[i] == 0.0) {
      rtb_Gain = 0.0;
    } else {
      rtb_Gain = ctrl_custom_B.Memory4[i];
    }

    ctrl_custom_B.alpha_infinf[i] = floor((fabs(ctrl_custom_B.Memory4[i]) +
      3.1415926535897931) / 6.2831853071795862) * rtb_Gain * 6.2831853071795862
      + ctrl_custom_B.alpha[i];

    /* '<S44>:1:10' */
    rtb_Gain = ctrl_custom_B.alpha_infinf[i] - ctrl_custom_B.Memory4[i];

    /*  Shortest rotation */
    if (fabs(rtb_Gain) > 3.1415926535897931) {
      /* '<S44>:1:13' */
      /* '<S44>:1:14' */
      if (rtb_Gain < 0.0) {
        rtb_Gain = -1.0;
      } else if (rtb_Gain > 0.0) {
        rtb_Gain = 1.0;
      } else {
        if (rtb_Gain == 0.0) {
          rtb_Gain = 0.0;
        }
      }

      ctrl_custom_B.alpha_infinf[i] -= rtb_Gain * 2.0 * 3.1415926535897931;
    }
  }

  /* End of MATLAB Function: '<S9>/MATLAB Function11' */

  /* Gain: '<Root>/deg2rad1' */
  ctrl_custom_B.deg2rad1 = ctrl_custom_P.deg2rad1_Gain * ctrl_custom_B.deg2rad;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* ToFile: '<Root>/To File' */
    {
      if (!(++ctrl_custom_DW.ToFile_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile_IWORK.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.tau1[0];
          u[2] = ctrl_custom_B.tau1[1];
          u[3] = ctrl_custom_B.tau1[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M, "Error writing to MAT-file tau.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile_IWORK.Count) * (3 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file tau.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++ctrl_custom_DW.ToFile1_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile1_IWORK.Count * (6 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[6 + 1];
          ctrl_custom_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.u[0];
          u[2] = ctrl_custom_B.u[1];
          u[3] = ctrl_custom_B.u[2];
          u[4] = ctrl_custom_B.u[3];
          u[5] = ctrl_custom_B.u[4];
          u[6] = ctrl_custom_B.u[5];
          if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
            rtmSetErrorStatus(ctrl_custom_M, "Error writing to MAT-file u.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile1_IWORK.Count) * (6 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file u.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File2' */
    {
      if (!(++ctrl_custom_DW.ToFile2_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile2_IWORK.Count * (6 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile2_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[6 + 1];
          ctrl_custom_DW.ToFile2_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.alpha_infinf[0];
          u[2] = ctrl_custom_B.alpha_infinf[1];
          u[3] = ctrl_custom_B.alpha_infinf[2];
          u[4] = ctrl_custom_B.alpha_infinf[3];
          u[5] = ctrl_custom_B.alpha_infinf[4];
          u[6] = ctrl_custom_B.alpha_infinf[5];
          if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file alpha_infinf.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile2_IWORK.Count) * (6 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file alpha_infinf.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File3' */
    {
      if (!(++ctrl_custom_DW.ToFile3_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile3_IWORK.Count * (6 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[6 + 1];
          ctrl_custom_DW.ToFile3_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.alpha[0];
          u[2] = ctrl_custom_B.alpha[1];
          u[3] = ctrl_custom_B.alpha[2];
          u[4] = ctrl_custom_B.alpha[3];
          u[5] = ctrl_custom_B.alpha[4];
          u[6] = ctrl_custom_B.alpha[5];
          if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file alpha_pipi.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile3_IWORK.Count) * (6 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file alpha_pipi.mat.\n");
          }
        }
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo File4Inport1' */
    ctrl_custom_B.TmpSignalConversionAtToFile4Inp[0] = ctrl_custom_B.mm2m;
    ctrl_custom_B.TmpSignalConversionAtToFile4Inp[1] = ctrl_custom_B.Gain1;
    ctrl_custom_B.TmpSignalConversionAtToFile4Inp[2] = ctrl_custom_B.Sum;

    /* ToFile: '<Root>/To File4' */
    {
      if (!(++ctrl_custom_DW.ToFile4_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile4_IWORK.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile4_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile4_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.TmpSignalConversionAtToFile4Inp[0];
          u[2] = ctrl_custom_B.TmpSignalConversionAtToFile4Inp[1];
          u[3] = ctrl_custom_B.TmpSignalConversionAtToFile4Inp[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M, "Error writing to MAT-file eta.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile4_IWORK.Count) * (3 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file eta.mat.\n");
          }
        }
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo File5Inport1' */
    rtb_eta_ref[0] = ctrl_custom_B.x_ref;
    rtb_eta_ref[1] = ctrl_custom_B.y_ref;
    rtb_eta_ref[2] = ctrl_custom_B.deg2rad;

    /* ToFile: '<Root>/To File5' */
    {
      if (!(++ctrl_custom_DW.ToFile5_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile5_IWORK.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile5_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile5_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = rtb_eta_ref[0];
          u[2] = rtb_eta_ref[1];
          u[3] = rtb_eta_ref[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file eta_ref.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile5_IWORK.Count) * (3 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file eta_ref.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File6' */
    {
      if (!(++ctrl_custom_DW.ToFile6_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile6_IWORK.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile6_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile6_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.nu[0];
          u[2] = ctrl_custom_B.nu[1];
          u[3] = ctrl_custom_B.nu[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M, "Error writing to MAT-file nu.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile6_IWORK.Count) * (3 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file nu.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<S1>/To File' */
    {
      if (!(++ctrl_custom_DW.ToFile_IWORK_m.Decimation % 1) &&
          (ctrl_custom_DW.ToFile_IWORK_m.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile_PWORK_l.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile_IWORK_m.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.z_1[0];
          u[2] = ctrl_custom_B.z_1[1];
          u[3] = ctrl_custom_B.z_1[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M, "Error writing to MAT-file Z1.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile_IWORK_m.Count) * (3 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Z1.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<S1>/To File1' */
    {
      if (!(++ctrl_custom_DW.ToFile1_IWORK_i.Decimation % 1) &&
          (ctrl_custom_DW.ToFile1_IWORK_i.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile1_PWORK_l.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile1_IWORK_i.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.z_2[0];
          u[2] = ctrl_custom_B.z_2[1];
          u[3] = ctrl_custom_B.z_2[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M, "Error writing to MAT-file Z2.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile1_IWORK_i.Count) * (3 + 1))+1 >=
              100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Z2.mat.\n");
          }
        }
      }
    }
  }

  /* Integrator: '<S19>/Integrator1' incorporates:
   *  Integrator: '<S19>/Integrator2'
   *  Integrator: '<S19>/Integrator3'
   */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator1_Reset_ZCE,
                       (ctrl_custom_B.reset));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (ctrl_custom_DW.Integrator1_IWORK != 0)) {
      ctrl_custom_X.Integrator1_CSTATE[0] = 0.0;
      ctrl_custom_X.Integrator1_CSTATE[1] = 0.0;
      ctrl_custom_X.Integrator1_CSTATE[2] = 0.0;
    }

    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator2_Reset_ZCE,
                       (ctrl_custom_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator2_CSTATE[0] = ctrl_custom_P.Integrator2_IC;
      ctrl_custom_X.Integrator2_CSTATE[1] = ctrl_custom_P.Integrator2_IC;
      ctrl_custom_X.Integrator2_CSTATE[2] = ctrl_custom_P.Integrator2_IC;
    }

    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator3_Reset_ZCE,
                       (ctrl_custom_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator3_CSTATE[0] = ctrl_custom_P.Integrator3_IC;
      ctrl_custom_X.Integrator3_CSTATE[1] = ctrl_custom_P.Integrator3_IC;
      ctrl_custom_X.Integrator3_CSTATE[2] = ctrl_custom_P.Integrator3_IC;
    }
  }

  /* Integrator: '<S19>/Integrator3' */
  ctrl_custom_B.Integrator3[0] = ctrl_custom_X.Integrator3_CSTATE[0];
  ctrl_custom_B.Integrator3[1] = ctrl_custom_X.Integrator3_CSTATE[1];
  ctrl_custom_B.Integrator3[2] = ctrl_custom_X.Integrator3_CSTATE[2];
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* MATLAB Function: '<Root>/diag' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    ctrl_custom_diag(ctrl_custom_P.Constant1_Value_p, &ctrl_custom_B.sf_diag);

    /* MATLAB Function: '<S19>/w_d^3' */
    /* MATLAB Function 'Guidance1/Reference model/w_d^3': '<S24>:1' */
    /* '<S24>:1:4' */
    for (i = 0; i < 3; i++) {
      for (p2 = 0; p2 < 3; p2++) {
        x[p2 + 3 * i] = 0.0;
        x[p2 + 3 * i] += ctrl_custom_B.sf_diag.w_d[3 * i] *
          ctrl_custom_B.sf_diag.w_d[p2];
        x[p2 + 3 * i] += ctrl_custom_B.sf_diag.w_d[3 * i + 1] *
          ctrl_custom_B.sf_diag.w_d[p2 + 3];
        x[p2 + 3 * i] += ctrl_custom_B.sf_diag.w_d[3 * i + 2] *
          ctrl_custom_B.sf_diag.w_d[p2 + 6];
      }
    }

    /* MATLAB Function 'Guidance1/Reference model/w_d^-2': '<S23>:1' */
    /* '<S23>:1:4' */
    for (i = 0; i < 3; i++) {
      /* MATLAB Function: '<S19>/w_d^-2' */
      for (p2 = 0; p2 < 3; p2++) {
        ctrl_custom_B.y[p2 + 3 * i] = 0.0;
        R[p2 + 3 * i] = 0.0;
        ctrl_custom_B.y[p2 + 3 * i] += x[3 * i] * ctrl_custom_B.sf_diag.w_d[p2];
        R[p2 + 3 * i] += ctrl_custom_B.sf_diag.w_d[3 * i] *
          ctrl_custom_B.sf_diag.w_d[p2];
        ctrl_custom_B.y[p2 + 3 * i] += x[3 * i + 1] *
          ctrl_custom_B.sf_diag.w_d[p2 + 3];
        R[p2 + 3 * i] += ctrl_custom_B.sf_diag.w_d[3 * i + 1] *
          ctrl_custom_B.sf_diag.w_d[p2 + 3];
        ctrl_custom_B.y[p2 + 3 * i] += x[3 * i + 2] *
          ctrl_custom_B.sf_diag.w_d[p2 + 6];
        R[p2 + 3 * i] += ctrl_custom_B.sf_diag.w_d[3 * i + 2] *
          ctrl_custom_B.sf_diag.w_d[p2 + 6];
      }
    }

    /* End of MATLAB Function: '<S19>/w_d^3' */

    /* MATLAB Function: '<S19>/w_d^-2' */
    memcpy(&x[0], &R[0], 9U * sizeof(real_T));
    i = 0;
    p2 = 3;
    p3 = 6;
    rtb_Gain = fabs(R[0]);
    angle_tilde = fabs(R[1]);
    rtb_TmpSignalConversionAtMatr_0 = fabs(R[2]);
    if ((angle_tilde > rtb_Gain) && (angle_tilde >
         rtb_TmpSignalConversionAtMatr_0)) {
      i = 3;
      p2 = 0;
      x[0] = R[1];
      x[1] = R[0];
      x[3] = R[4];
      x[4] = R[3];
      x[6] = R[7];
      x[7] = R[6];
    } else {
      if (rtb_TmpSignalConversionAtMatr_0 > rtb_Gain) {
        i = 6;
        p3 = 0;
        x[0] = R[2];
        x[2] = R[0];
        x[3] = R[5];
        x[5] = R[3];
        x[6] = R[8];
        x[8] = R[6];
      }
    }

    rtb_Gain = x[1] / x[0];
    x[1] /= x[0];
    angle_tilde = x[2] / x[0];
    x[2] /= x[0];
    x[4] -= rtb_Gain * x[3];
    x[5] -= angle_tilde * x[3];
    x[7] -= rtb_Gain * x[6];
    x[8] -= angle_tilde * x[6];
    if (fabs(x[5]) > fabs(x[4])) {
      itmp = p2;
      p2 = p3;
      p3 = itmp;
      x[1] = angle_tilde;
      x[2] = rtb_Gain;
      rtb_Gain = x[4];
      x[4] = x[5];
      x[5] = rtb_Gain;
      rtb_Gain = x[7];
      x[7] = x[8];
      x[8] = rtb_Gain;
    }

    rtb_Gain = x[5] / x[4];
    x[5] /= x[4];
    x[8] -= rtb_Gain * x[7];
    rtb_Gain = (x[5] * x[1] - x[2]) / x[8];
    angle_tilde = -(x[7] * rtb_Gain + x[1]) / x[4];
    ctrl_custom_B.y_g[i] = ((1.0 - x[3] * angle_tilde) - x[6] * rtb_Gain) / x[0];
    ctrl_custom_B.y_g[i + 1] = angle_tilde;
    ctrl_custom_B.y_g[i + 2] = rtb_Gain;
    rtb_Gain = -x[5] / x[8];
    angle_tilde = (1.0 - x[7] * rtb_Gain) / x[4];
    ctrl_custom_B.y_g[p2] = -(x[3] * angle_tilde + x[6] * rtb_Gain) / x[0];
    ctrl_custom_B.y_g[p2 + 1] = angle_tilde;
    ctrl_custom_B.y_g[p2 + 2] = rtb_Gain;
    rtb_Gain = 1.0 / x[8];
    angle_tilde = -x[7] * rtb_Gain / x[4];
    ctrl_custom_B.y_g[p3] = -(x[3] * angle_tilde + x[6] * rtb_Gain) / x[0];
    ctrl_custom_B.y_g[p3 + 1] = angle_tilde;
    ctrl_custom_B.y_g[p3 + 2] = rtb_Gain;
  }

  /* Sum: '<S19>/Sum3' */
  tmp_6[0] = ctrl_custom_B.x_ref;
  tmp_6[1] = ctrl_custom_B.y_ref;
  tmp_6[2] = ctrl_custom_B.deg2rad;
  tmp_7[0] = ctrl_custom_B.mm2m;
  tmp_7[1] = ctrl_custom_B.Gain1;
  tmp_7[2] = ctrl_custom_B.Sum;

  /* Sum: '<S19>/Sum' incorporates:
   *  Integrator: '<S19>/Integrator2'
   *  Product: '<S19>/Matrix Multiply'
   *  Product: '<S19>/Matrix Multiply1'
   *  Sum: '<S19>/Sum3'
   */
  for (i = 0; i < 3; i++) {
    tmp_0[i] = (tmp_6[i] - tmp_7[i]) - ((ctrl_custom_B.y_g[i + 3] *
      ctrl_custom_X.Integrator2_CSTATE[1] + ctrl_custom_B.y_g[i] *
      ctrl_custom_X.Integrator2_CSTATE[0]) + ctrl_custom_B.y_g[i + 6] *
      ctrl_custom_X.Integrator2_CSTATE[2]);
  }

  /* End of Sum: '<S19>/Sum' */

  /* Product: '<S19>/Matrix Multiply' */
  for (i = 0; i < 3; i++) {
    ctrl_custom_B.MatrixMultiply[i] = 0.0;
    ctrl_custom_B.MatrixMultiply[i] += ctrl_custom_B.y[i] * tmp_0[0];
    ctrl_custom_B.MatrixMultiply[i] += ctrl_custom_B.y[i + 3] * tmp_0[1];
    ctrl_custom_B.MatrixMultiply[i] += ctrl_custom_B.y[i + 6] * tmp_0[2];
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* MATLAB Function: '<S19>/w_d*w_d' */
    /* MATLAB Function 'Guidance1/Reference model/w_d*w_d': '<S21>:1' */
    /* '<S21>:1:4' */
    for (i = 0; i < 3; i++) {
      for (p2 = 0; p2 < 3; p2++) {
        ctrl_custom_B.y_c[p2 + 3 * i] = 0.0;
        ctrl_custom_B.y_c[p2 + 3 * i] += ctrl_custom_B.sf_diag.w_d[3 * i] *
          ctrl_custom_B.sf_diag.w_d[p2];
        ctrl_custom_B.y_c[p2 + 3 * i] += ctrl_custom_B.sf_diag.w_d[3 * i + 1] *
          ctrl_custom_B.sf_diag.w_d[p2 + 3];
        ctrl_custom_B.y_c[p2 + 3 * i] += ctrl_custom_B.sf_diag.w_d[3 * i + 2] *
          ctrl_custom_B.sf_diag.w_d[p2 + 6];
      }
    }

    /* End of MATLAB Function: '<S19>/w_d*w_d' */
  }

  /* Saturate: '<S20>/Saturation' incorporates:
   *  Integrator: '<S19>/Integrator1'
   */
  if (ctrl_custom_X.Integrator1_CSTATE[2] > ctrl_custom_P.Saturation_UpperSat_e)
  {
    angle_tilde = ctrl_custom_P.Saturation_UpperSat_e;
  } else if (ctrl_custom_X.Integrator1_CSTATE[2] <
             ctrl_custom_P.Saturation_LowerSat_i) {
    angle_tilde = ctrl_custom_P.Saturation_LowerSat_i;
  } else {
    angle_tilde = ctrl_custom_X.Integrator1_CSTATE[2];
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* Signum: '<S20>/Sign' */
  if (angle_tilde < 0.0) {
    rtb_Gain = -1.0;
  } else if (angle_tilde > 0.0) {
    rtb_Gain = 1.0;
  } else if (angle_tilde == 0.0) {
    rtb_Gain = 0.0;
  } else {
    rtb_Gain = angle_tilde;
  }

  /* End of Signum: '<S20>/Sign' */

  /* Gain: '<S20>/Gain' */
  rtb_Gain *= ctrl_custom_P.Gain_Gain;

  /* Sum: '<S20>/Sum1' */
  angle_tilde += rtb_Gain;

  /* Math: '<S20>/Math Function' incorporates:
   *  Constant: '<S20>/Constant'
   */
  angle_tilde = rt_remd_snf(angle_tilde, ctrl_custom_P.Constant_Value_g);

  /* Sum: '<S20>/Sum' */
  angle_tilde -= rtb_Gain;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* MATLAB Function: '<Root>/diag1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    ctrl_custom_diag(ctrl_custom_P.Constant2_Value_f, &ctrl_custom_B.sf_diag1);

    /* MATLAB Function: '<S19>/w_d*w_d1' */
    /* MATLAB Function 'Guidance1/Reference model/w_d*w_d1': '<S22>:1' */
    /* '<S22>:1:4' */
    for (i = 0; i < 3; i++) {
      for (p2 = 0; p2 < 3; p2++) {
        ctrl_custom_B.y_gl[p2 + 3 * i] = 0.0;
        ctrl_custom_B.y_gl[p2 + 3 * i] += 2.0 * ctrl_custom_B.sf_diag1.w_d[p2] *
          ctrl_custom_B.sf_diag.w_d[3 * i];
        ctrl_custom_B.y_gl[p2 + 3 * i] += ctrl_custom_B.sf_diag1.w_d[p2 + 3] *
          2.0 * ctrl_custom_B.sf_diag.w_d[3 * i + 1];
        ctrl_custom_B.y_gl[p2 + 3 * i] += ctrl_custom_B.sf_diag1.w_d[p2 + 6] *
          2.0 * ctrl_custom_B.sf_diag.w_d[3 * i + 2];
      }
    }

    /* End of MATLAB Function: '<S19>/w_d*w_d1' */
  }

  for (i = 0; i < 3; i++) {
    /* Sum: '<S19>/Sum5' incorporates:
     *  Integrator: '<S19>/Integrator1'
     *  Integrator: '<S19>/Integrator2'
     *  Product: '<S19>/Matrix Multiply2'
     *  Product: '<S19>/Matrix Multiply5'
     *  SignalConversion: '<S19>/TmpSignal ConversionAtMatrix Multiply2Inport2'
     *  Sum: '<S19>/Sum2'
     */
    ctrl_custom_B.Sum5[i] = (ctrl_custom_X.Integrator2_CSTATE[i] -
      ((ctrl_custom_B.y_c[i + 3] * ctrl_custom_X.Integrator1_CSTATE[1] +
        ctrl_custom_B.y_c[i] * ctrl_custom_X.Integrator1_CSTATE[0]) +
       ctrl_custom_B.y_c[i + 6] * angle_tilde)) - (ctrl_custom_B.y_gl[i + 6] *
      ctrl_custom_B.Integrator3[2] + (ctrl_custom_B.y_gl[i + 3] *
      ctrl_custom_B.Integrator3[1] + ctrl_custom_B.y_gl[i] *
      ctrl_custom_B.Integrator3[0]));
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S45>/Memory10' */
    ctrl_custom_B.Memory10[0] = ctrl_custom_DW.Memory10_PreviousInput[0];
    ctrl_custom_B.Memory10[1] = ctrl_custom_DW.Memory10_PreviousInput[1];
    ctrl_custom_B.Memory10[2] = ctrl_custom_DW.Memory10_PreviousInput[2];
  }

  /* MATLAB Function: '<S45>/MATLAB Function8' incorporates:
   *  Constant: '<S45>/Stepsize1'
   */
  ctrl_custom_MATLABFunction1(ctrl_custom_P.Stepsize1_Value, ctrl_custom_B.nu,
    ctrl_custom_B.Memory10, &ctrl_custom_B.sf_MATLABFunction8);
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S45>/Memory9' */
    ctrl_custom_B.Memory9[0] = ctrl_custom_DW.Memory9_PreviousInput[0];
    ctrl_custom_B.Memory9[1] = ctrl_custom_DW.Memory9_PreviousInput[1];
    ctrl_custom_B.Memory9[2] = ctrl_custom_DW.Memory9_PreviousInput[2];
  }

  /* MATLAB Function: '<S45>/MATLAB Function7' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  ctrl_custom_MATLABFunction2(ctrl_custom_P.Constant3_Value,
    ctrl_custom_B.sf_MATLABFunction8.eta_dot, ctrl_custom_B.Memory9,
    &ctrl_custom_B.sf_MATLABFunction7);

  /* Fcn: '<S46>/Fcn' */
  ctrl_custom_B.x_dot = cos(ctrl_custom_B.Sum) * ctrl_custom_B.nu[0] - sin
    (ctrl_custom_B.Sum) * ctrl_custom_B.nu[1];

  /* Fcn: '<S46>/Fcn1' */
  ctrl_custom_B.y_dot = sin(ctrl_custom_B.Sum) * ctrl_custom_B.nu[0] + cos
    (ctrl_custom_B.Sum) * ctrl_custom_B.nu[1];

  /* Fcn: '<S46>/Fcn2' */
  ctrl_custom_B.psi_dot = ctrl_custom_B.nu[2];
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }
}

/* Model update function */
void ctrl_custom_update(void)
{
  int32_T i;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Update for Memory: '<S9>/Memory4' */
    for (i = 0; i < 6; i++) {
      ctrl_custom_DW.Memory4_PreviousInput[i] = ctrl_custom_B.alpha_infinf[i];
    }

    /* End of Update for Memory: '<S9>/Memory4' */

    /* Update for Memory: '<S10>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput[0] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[0];
    ctrl_custom_DW.Memory2_PreviousInput[1] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[1];
    ctrl_custom_DW.Memory2_PreviousInput[2] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[2];

    /* Update for Memory: '<S10>/Memory7' */
    ctrl_custom_DW.Memory7_PreviousInput = ctrl_custom_B.count_out;

    /* Update for Memory: '<S45>/Memory7' */
    ctrl_custom_DW.Memory7_PreviousInput_n = ctrl_custom_B.count_out_c;

    /* Update for Memory: '<S10>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput[0] = ctrl_custom_B.Switch[0];

    /* Update for Memory: '<S45>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput_c[0] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[0];

    /* Update for Memory: '<S45>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_m[0] = ctrl_custom_B.eta_filtered[0];

    /* Update for Memory: '<S45>/Memory5' */
    ctrl_custom_DW.Memory5_PreviousInput[0] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[0];

    /* Update for Memory: '<S45>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput[0] =
      ctrl_custom_B.sf_MATLABFunction2.eta_dot_filtered[0];

    /* Update for Memory: '<S45>/Memory4' */
    ctrl_custom_DW.Memory4_PreviousInput_l[0] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[0];

    /* Update for Memory: '<S45>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[0] = ctrl_custom_B.nu[0];

    /* Update for Memory: '<S10>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput[1] = ctrl_custom_B.Switch[1];

    /* Update for Memory: '<S45>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput_c[1] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[1];

    /* Update for Memory: '<S45>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_m[1] = ctrl_custom_B.eta_filtered[1];

    /* Update for Memory: '<S45>/Memory5' */
    ctrl_custom_DW.Memory5_PreviousInput[1] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[1];

    /* Update for Memory: '<S45>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput[1] =
      ctrl_custom_B.sf_MATLABFunction2.eta_dot_filtered[1];

    /* Update for Memory: '<S45>/Memory4' */
    ctrl_custom_DW.Memory4_PreviousInput_l[1] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[1];

    /* Update for Memory: '<S45>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[1] = ctrl_custom_B.nu[1];

    /* Update for Memory: '<S10>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput[2] = ctrl_custom_B.Switch[2];

    /* Update for Memory: '<S45>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput_c[2] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[2];

    /* Update for Memory: '<S45>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_m[2] = ctrl_custom_B.eta_filtered[2];

    /* Update for Memory: '<S45>/Memory5' */
    ctrl_custom_DW.Memory5_PreviousInput[2] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[2];

    /* Update for Memory: '<S45>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput[2] =
      ctrl_custom_B.sf_MATLABFunction2.eta_dot_filtered[2];

    /* Update for Memory: '<S45>/Memory4' */
    ctrl_custom_DW.Memory4_PreviousInput_l[2] =
      ctrl_custom_B.TmpSignalConversionAtToFile4Inp[2];

    /* Update for Memory: '<S45>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[2] = ctrl_custom_B.nu[2];
  }

  /* Update for Integrator: '<S10>/Integrator' */
  ctrl_custom_DW.Integrator_IWORK = 0;

  /* Update for Integrator: '<S19>/Integrator1' */
  ctrl_custom_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Update for Memory: '<S45>/Memory10' */
    ctrl_custom_DW.Memory10_PreviousInput[0] = ctrl_custom_B.nu[0];

    /* Update for Memory: '<S45>/Memory9' */
    ctrl_custom_DW.Memory9_PreviousInput[0] =
      ctrl_custom_B.sf_MATLABFunction7.eta_dot_filtered[0];

    /* Update for Memory: '<S45>/Memory10' */
    ctrl_custom_DW.Memory10_PreviousInput[1] = ctrl_custom_B.nu[1];

    /* Update for Memory: '<S45>/Memory9' */
    ctrl_custom_DW.Memory9_PreviousInput[1] =
      ctrl_custom_B.sf_MATLABFunction7.eta_dot_filtered[1];

    /* Update for Memory: '<S45>/Memory10' */
    ctrl_custom_DW.Memory10_PreviousInput[2] = ctrl_custom_B.nu[2];

    /* Update for Memory: '<S45>/Memory9' */
    ctrl_custom_DW.Memory9_PreviousInput[2] =
      ctrl_custom_B.sf_MATLABFunction7.eta_dot_filtered[2];
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_custom_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_custom_M->Timing.clockTick0)) {
    ++ctrl_custom_M->Timing.clockTickH0;
  }

  ctrl_custom_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_custom_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_custom_M->Timing.clockTick1)) {
      ++ctrl_custom_M->Timing.clockTickH1;
    }

    ctrl_custom_M->Timing.t[1] = ctrl_custom_M->Timing.clockTick1 *
      ctrl_custom_M->Timing.stepSize1 + ctrl_custom_M->Timing.clockTickH1 *
      ctrl_custom_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_custom_derivatives(void)
{
  XDot_ctrl_custom_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_custom_T *) ctrl_custom_M->derivs);

  /* Derivatives for Integrator: '<S10>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_custom_B.x_dot;
  _rtXdot->Integrator_CSTATE[1] = ctrl_custom_B.y_dot;
  _rtXdot->Integrator_CSTATE[2] = ctrl_custom_B.psi_dot;

  /* Derivatives for Integrator: '<S19>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_custom_B.Integrator3[0];

  /* Derivatives for Integrator: '<S19>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_custom_B.MatrixMultiply[0];

  /* Derivatives for Integrator: '<S19>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = ctrl_custom_B.Sum5[0];

  /* Derivatives for Integrator: '<S19>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = ctrl_custom_B.Integrator3[1];

  /* Derivatives for Integrator: '<S19>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = ctrl_custom_B.MatrixMultiply[1];

  /* Derivatives for Integrator: '<S19>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[1] = ctrl_custom_B.Sum5[1];

  /* Derivatives for Integrator: '<S19>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = ctrl_custom_B.Integrator3[2];

  /* Derivatives for Integrator: '<S19>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[2] = ctrl_custom_B.MatrixMultiply[2];

  /* Derivatives for Integrator: '<S19>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[2] = ctrl_custom_B.Sum5[2];
}

/* Model initialize function */
void ctrl_custom_initialize(void)
{
  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "tau.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file tau.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file tau.mat");
      return;
    }

    ctrl_custom_DW.ToFile_IWORK.Count = 0;
    ctrl_custom_DW.ToFile_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "u.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file u.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file u.mat");
      return;
    }

    ctrl_custom_DW.ToFile1_IWORK.Count = 0;
    ctrl_custom_DW.ToFile1_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "alpha_infinf.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error creating .mat file alpha_infinf.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file alpha_infinf.mat");
      return;
    }

    ctrl_custom_DW.ToFile2_IWORK.Count = 0;
    ctrl_custom_DW.ToFile2_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile2_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File3' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "alpha_pipi.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file alpha_pipi.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file alpha_pipi.mat");
      return;
    }

    ctrl_custom_DW.ToFile3_IWORK.Count = 0;
    ctrl_custom_DW.ToFile3_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile3_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File4' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "eta.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file eta.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file eta.mat");
      return;
    }

    ctrl_custom_DW.ToFile4_IWORK.Count = 0;
    ctrl_custom_DW.ToFile4_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile4_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File5' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "eta_ref.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file eta_ref.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file eta_ref.mat");
      return;
    }

    ctrl_custom_DW.ToFile5_IWORK.Count = 0;
    ctrl_custom_DW.ToFile5_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile5_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File6' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "nu.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file nu.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file nu.mat");
      return;
    }

    ctrl_custom_DW.ToFile6_IWORK.Count = 0;
    ctrl_custom_DW.ToFile6_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile6_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<S1>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Z1.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file Z1.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file Z1.mat");
      return;
    }

    ctrl_custom_DW.ToFile_IWORK_m.Count = 0;
    ctrl_custom_DW.ToFile_IWORK_m.Decimation = -1;
    ctrl_custom_DW.ToFile_PWORK_l.FilePtr = fp;
  }

  /* Start for ToFile: '<S1>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Z2.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file Z2.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file Z2.mat");
      return;
    }

    ctrl_custom_DW.ToFile1_IWORK_i.Count = 0;
    ctrl_custom_DW.ToFile1_IWORK_i.Decimation = -1;
    ctrl_custom_DW.ToFile1_PWORK_l.FilePtr = fp;
  }

  ctrl_custom_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S9>/Memory4' */
    for (i = 0; i < 6; i++) {
      ctrl_custom_DW.Memory4_PreviousInput[i] = ctrl_custom_P.Memory4_X0[i];
    }

    /* End of InitializeConditions for Memory: '<S9>/Memory4' */

    /* InitializeConditions for Memory: '<S10>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput[0] = ctrl_custom_P.Memory2_X0[0];
    ctrl_custom_DW.Memory2_PreviousInput[1] = ctrl_custom_P.Memory2_X0[1];
    ctrl_custom_DW.Memory2_PreviousInput[2] = ctrl_custom_P.Memory2_X0[2];

    /* InitializeConditions for Integrator: '<S10>/Integrator' incorporates:
     *  InitializeConditions for Integrator: '<S19>/Integrator1'
     */
    if (rtmIsFirstInitCond(ctrl_custom_M)) {
      ctrl_custom_X.Integrator_CSTATE[0] = 0.0;
      ctrl_custom_X.Integrator_CSTATE[1] = 0.0;
      ctrl_custom_X.Integrator_CSTATE[2] = 0.0;
      ctrl_custom_X.Integrator1_CSTATE[0] = 0.0;
      ctrl_custom_X.Integrator1_CSTATE[1] = 0.0;
      ctrl_custom_X.Integrator1_CSTATE[2] = 0.0;
    }

    ctrl_custom_DW.Integrator_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S10>/Integrator' */

    /* InitializeConditions for Memory: '<S10>/Memory7' */
    ctrl_custom_DW.Memory7_PreviousInput = ctrl_custom_P.Memory7_X0;

    /* InitializeConditions for Memory: '<S45>/Memory7' */
    ctrl_custom_DW.Memory7_PreviousInput_n = ctrl_custom_P.Memory7_X0_f;

    /* InitializeConditions for Memory: '<S10>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput[0] = ctrl_custom_P.Memory6_X0[0];

    /* InitializeConditions for Memory: '<S45>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput_c[0] = ctrl_custom_P.Memory6_X0_o[0];

    /* InitializeConditions for Memory: '<S45>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_m[0] = ctrl_custom_P.Memory2_X0_f[0];

    /* InitializeConditions for Memory: '<S45>/Memory5' */
    ctrl_custom_DW.Memory5_PreviousInput[0] = ctrl_custom_P.Memory5_X0[0];

    /* InitializeConditions for Memory: '<S45>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput[0] = ctrl_custom_P.Memory3_X0[0];

    /* InitializeConditions for Memory: '<S45>/Memory4' */
    ctrl_custom_DW.Memory4_PreviousInput_l[0] = ctrl_custom_P.Memory4_X0_n[0];

    /* InitializeConditions for Memory: '<S45>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[0] = ctrl_custom_P.Memory1_X0[0];

    /* InitializeConditions for Memory: '<S10>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput[1] = ctrl_custom_P.Memory6_X0[1];

    /* InitializeConditions for Memory: '<S45>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput_c[1] = ctrl_custom_P.Memory6_X0_o[1];

    /* InitializeConditions for Memory: '<S45>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_m[1] = ctrl_custom_P.Memory2_X0_f[1];

    /* InitializeConditions for Memory: '<S45>/Memory5' */
    ctrl_custom_DW.Memory5_PreviousInput[1] = ctrl_custom_P.Memory5_X0[1];

    /* InitializeConditions for Memory: '<S45>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput[1] = ctrl_custom_P.Memory3_X0[1];

    /* InitializeConditions for Memory: '<S45>/Memory4' */
    ctrl_custom_DW.Memory4_PreviousInput_l[1] = ctrl_custom_P.Memory4_X0_n[1];

    /* InitializeConditions for Memory: '<S45>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[1] = ctrl_custom_P.Memory1_X0[1];

    /* InitializeConditions for Memory: '<S10>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput[2] = ctrl_custom_P.Memory6_X0[2];

    /* InitializeConditions for Memory: '<S45>/Memory6' */
    ctrl_custom_DW.Memory6_PreviousInput_c[2] = ctrl_custom_P.Memory6_X0_o[2];

    /* InitializeConditions for Memory: '<S45>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_m[2] = ctrl_custom_P.Memory2_X0_f[2];

    /* InitializeConditions for Memory: '<S45>/Memory5' */
    ctrl_custom_DW.Memory5_PreviousInput[2] = ctrl_custom_P.Memory5_X0[2];

    /* InitializeConditions for Memory: '<S45>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput[2] = ctrl_custom_P.Memory3_X0[2];

    /* InitializeConditions for Memory: '<S45>/Memory4' */
    ctrl_custom_DW.Memory4_PreviousInput_l[2] = ctrl_custom_P.Memory4_X0_n[2];

    /* InitializeConditions for Memory: '<S45>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[2] = ctrl_custom_P.Memory1_X0[2];

    /* InitializeConditions for Integrator: '<S19>/Integrator1' */
    ctrl_custom_DW.Integrator1_IWORK = 1;

    /* InitializeConditions for Integrator: '<S19>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE[0] = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S19>/Integrator3' */
    ctrl_custom_X.Integrator3_CSTATE[0] = ctrl_custom_P.Integrator3_IC;

    /* InitializeConditions for Memory: '<S45>/Memory10' */
    ctrl_custom_DW.Memory10_PreviousInput[0] = ctrl_custom_P.Memory10_X0[0];

    /* InitializeConditions for Memory: '<S45>/Memory9' */
    ctrl_custom_DW.Memory9_PreviousInput[0] = ctrl_custom_P.Memory9_X0[0];

    /* InitializeConditions for Integrator: '<S19>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE[1] = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S19>/Integrator3' */
    ctrl_custom_X.Integrator3_CSTATE[1] = ctrl_custom_P.Integrator3_IC;

    /* InitializeConditions for Memory: '<S45>/Memory10' */
    ctrl_custom_DW.Memory10_PreviousInput[1] = ctrl_custom_P.Memory10_X0[1];

    /* InitializeConditions for Memory: '<S45>/Memory9' */
    ctrl_custom_DW.Memory9_PreviousInput[1] = ctrl_custom_P.Memory9_X0[1];

    /* InitializeConditions for Integrator: '<S19>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE[2] = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S19>/Integrator3' */
    ctrl_custom_X.Integrator3_CSTATE[2] = ctrl_custom_P.Integrator3_IC;

    /* InitializeConditions for Memory: '<S45>/Memory10' */
    ctrl_custom_DW.Memory10_PreviousInput[2] = ctrl_custom_P.Memory10_X0[2];

    /* InitializeConditions for Memory: '<S45>/Memory9' */
    ctrl_custom_DW.Memory9_PreviousInput[2] = ctrl_custom_P.Memory9_X0[2];

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function4' */
    ctrl_custom_DW.PHI_not_empty = false;
    ctrl_custom_DW.OMEGA_N_not_empty = false;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_custom_M)) {
      rtmSetFirstInitCond(ctrl_custom_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_custom_terminate(void)
{
  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "tau.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file tau.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file tau.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file tau.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file tau.mat");
        return;
      }

      ctrl_custom_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "u.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file u.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file u.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1, ctrl_custom_DW.ToFile1_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file u.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file u.mat");
        return;
      }

      ctrl_custom_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "alpha_infinf.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file alpha_infinf.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error reopening MAT-file alpha_infinf.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1, ctrl_custom_DW.ToFile2_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file alpha_infinf.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file alpha_infinf.mat");
        return;
      }

      ctrl_custom_DW.ToFile2_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File3' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "alpha_pipi.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file alpha_pipi.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error reopening MAT-file alpha_pipi.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1, ctrl_custom_DW.ToFile3_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file alpha_pipi.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file alpha_pipi.mat");
        return;
      }

      ctrl_custom_DW.ToFile3_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File4' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile4_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "eta.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file eta.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile4_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file eta.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta.mat");
        return;
      }

      ctrl_custom_DW.ToFile4_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File5' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile5_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "eta_ref.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta_ref.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file eta_ref.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile5_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file eta_ref.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta_ref.mat");
        return;
      }

      ctrl_custom_DW.ToFile5_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File6' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile6_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "nu.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file nu.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file nu.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile6_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file nu.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file nu.mat");
        return;
      }

      ctrl_custom_DW.ToFile6_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S1>/To File' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile_PWORK_l.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Z1.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file Z1.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file Z1.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile_IWORK_m.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file Z1.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file Z1.mat");
        return;
      }

      ctrl_custom_DW.ToFile_PWORK_l.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S1>/To File1' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile1_PWORK_l.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Z2.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file Z2.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file Z2.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile1_IWORK_i.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file Z2.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file Z2.mat");
        return;
      }

      ctrl_custom_DW.ToFile1_PWORK_l.FilePtr = (NULL);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_custom_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_custom_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_custom_initialize();
}

void MdlTerminate(void)
{
  ctrl_custom_terminate();
}

/* Registration function */
RT_MODEL_ctrl_custom_T *ctrl_custom(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_custom_M, 0,
                sizeof(RT_MODEL_ctrl_custom_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_custom_M->solverInfo,
                          &ctrl_custom_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_custom_M->solverInfo, &rtmGetTPtr(ctrl_custom_M));
    rtsiSetStepSizePtr(&ctrl_custom_M->solverInfo,
                       &ctrl_custom_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_custom_M->solverInfo, &ctrl_custom_M->derivs);
    rtsiSetContStatesPtr(&ctrl_custom_M->solverInfo, (real_T **)
                         &ctrl_custom_M->contStates);
    rtsiSetNumContStatesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ctrl_custom_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_custom_M)));
    rtsiSetRTModelPtr(&ctrl_custom_M->solverInfo, ctrl_custom_M);
  }

  rtsiSetSimTimeStep(&ctrl_custom_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_custom_M->intgData.y = ctrl_custom_M->odeY;
  ctrl_custom_M->intgData.f[0] = ctrl_custom_M->odeF[0];
  ctrl_custom_M->intgData.f[1] = ctrl_custom_M->odeF[1];
  ctrl_custom_M->intgData.f[2] = ctrl_custom_M->odeF[2];
  ctrl_custom_M->intgData.f[3] = ctrl_custom_M->odeF[3];
  ctrl_custom_M->contStates = ((real_T *) &ctrl_custom_X);
  rtsiSetSolverData(&ctrl_custom_M->solverInfo, (void *)&ctrl_custom_M->intgData);
  rtsiSetSolverName(&ctrl_custom_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_custom_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_custom_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_custom_M->Timing.sampleTimes = (&ctrl_custom_M->
      Timing.sampleTimesArray[0]);
    ctrl_custom_M->Timing.offsetTimes = (&ctrl_custom_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_custom_M->Timing.sampleTimes[0] = (0.0);
    ctrl_custom_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_custom_M->Timing.offsetTimes[0] = (0.0);
    ctrl_custom_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_custom_M, &ctrl_custom_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_custom_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_custom_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_custom_M, -1);
  ctrl_custom_M->Timing.stepSize0 = 0.01;
  ctrl_custom_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_custom_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ctrl_custom_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_custom_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_custom_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_custom_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_custom_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_custom_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_custom_M->rtwLogInfo, (NULL));
  }

  ctrl_custom_M->solverInfoPtr = (&ctrl_custom_M->solverInfo);
  ctrl_custom_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_custom_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_custom_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_custom_M->blockIO = ((void *) &ctrl_custom_B);
  (void) memset(((void *) &ctrl_custom_B), 0,
                sizeof(B_ctrl_custom_T));

  /* parameters */
  ctrl_custom_M->defaultParam = ((real_T *)&ctrl_custom_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_custom_X;
    ctrl_custom_M->contStates = (x);
    (void) memset((void *)&ctrl_custom_X, 0,
                  sizeof(X_ctrl_custom_T));
  }

  /* states (dwork) */
  ctrl_custom_M->dwork = ((void *) &ctrl_custom_DW);
  (void) memset((void *)&ctrl_custom_DW, 0,
                sizeof(DW_ctrl_custom_T));

  /* Initialize Sizes */
  ctrl_custom_M->Sizes.numContStates = (12);/* Number of continuous states */
  ctrl_custom_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_custom_M->Sizes.numY = (0);     /* Number of model outputs */
  ctrl_custom_M->Sizes.numU = (0);     /* Number of model inputs */
  ctrl_custom_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_custom_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_custom_M->Sizes.numBlocks = (181);/* Number of blocks */
  ctrl_custom_M->Sizes.numBlockIO = (74);/* Number of block outputs */
  ctrl_custom_M->Sizes.numBlockPrms = (370);/* Sum of parameter "widths" */
  return ctrl_custom_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.93
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Mon Sep 25 10:58:12 2017
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_custom
#include "ni_modelframework_ex.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;

/*========================================================================*
 * Function: NIRT_GetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the source
 *      subindex : index value if vector
 *      type   : the source's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
double NIRT_GetValueByDataType(void* ptr, int32_t subindex, int32_t type,
  int32_t Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,10,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return (( double *)ptr)[subindex];

   case 35:
    return (( double *)ptr)[subindex];

   case 36:
    return (( double *)ptr)[subindex];

   case 37:
    return (( double *)ptr)[subindex];

   case 38:
    return (( double *)ptr)[subindex];

   case 39:
    return (( double *)ptr)[subindex];

   case 40:
    return (( double *)ptr)[subindex];

   case 41:
    return (( double *)ptr)[subindex];

   case 42:
    return (( double *)ptr)[subindex];

   case 43:
    return (( double *)ptr)[subindex];

   case 44:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 45:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

/*========================================================================*
 * Function: NIRT_SetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the destination
 *      subindex : index value if vector
 *      value : value to set on the destination
 *      type   : the destination's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NIRT_SetValueByDataType(void* ptr, int32_t subindex, double value,
  int32_t type, int32_t Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 17:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 10, Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 34:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 35:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 36:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 37:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 38:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 39:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 40:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 41:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 42:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 43:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 44:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 45:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_custom_rtModel *S;
extern _SITexportglobals SITexportglobals;

/*========================================================================*
 * Function: SetExternalInputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalInputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_custom/Input to model
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Inputtomodel, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/x_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.x_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/y_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.y_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/eta_QTM/x_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.x_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/eta_QTM/y_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.y_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/eta_QTM/psi_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.u80180deg, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/psi_ref [deg]
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.psi_refdeg, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control/alpha_u
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.alpha_u, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control/K1_u
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K1_u, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control/K1_r
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K1_r, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control/alpha_r
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.alpha_r, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_z
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_z
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/Control Gains/K_p_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/Control Gains/K_p_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/Control Gains/K_p_psi
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/Control Gains/K_i_psi
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/Control Gains/K_i_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/Control Gains/K_i_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/Control Gains/K_d_psi
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/Control Gains/K_d_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Input1/Control Gains/K_d_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 27;
}

int32_t NumOutputPorts(void)
{
  return 16;
}

double ni_extout[16];

/*========================================================================*
 * Function: SetExternalOutputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalOutputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_custom/Output to Workspace: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_custom_RGND, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/x_t: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.x_ref, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/y_t: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.y_ref, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 0,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 1,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 2,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 3,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 4,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 5,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 0, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 1, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 2, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 3, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 4, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 5, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/psi_t: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.deg2rad1, 0, 0,
      0);
  } else {
    index += 1;
  }

  if (data != NULL) {
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
  }

  UNUSED_PARAMETER(count);
}

/*========================================================================*
 * Function: NI_InitExternalOutputs
 *
 * Abstract:
 *		Initialize model ports
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // ctrl_custom/Output to Workspace: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_custom_RGND, 0, 0,
    0);

  // ctrl_custom/x_t: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.x_ref, 0, 0, 0);

  // ctrl_custom/y_t: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.y_ref, 0, 0, 0);

  // ctrl_custom/Output/alpha1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 0,
    22, 0);

  // ctrl_custom/Output/alpha2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 1,
    22, 0);

  // ctrl_custom/Output/alpha3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 2,
    22, 0);

  // ctrl_custom/Output/alpha4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 3,
    22, 0);

  // ctrl_custom/Output/alpha5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 4,
    22, 0);

  // ctrl_custom/Output/alpha6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 5,
    22, 0);

  // ctrl_custom/Output/u1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 0, 22, 0);

  // ctrl_custom/Output/u2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 1, 22, 0);

  // ctrl_custom/Output/u3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 2, 22, 0);

  // ctrl_custom/Output/u4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 3, 22, 0);

  // ctrl_custom/Output/u5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 4, 22, 0);

  // ctrl_custom/Output/u6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 5, 22, 0);

  // ctrl_custom/psi_t: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.deg2rad1, 0, 0, 0);
  UNUSED_PARAMETER(count);
  return NI_OK;
}

/* Undefine parameter macros. The undef allows us to access the real declarations.
   In the Simulink(R) generated code, the parameters are redefined to be the read-side of rtParameter.*/
#define _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/Gain/Gain",
    offsetof(P_ctrl_custom_T, T_pinv), 29, 36, 2, 0, 0 },

  { 1,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/X0",
    offsetof(P_ctrl_custom_T, Memory4_X0), 30, 6, 2, 2, 0 },

  { 2, "ctrl_custom/eta_QTM/mm2m/Gain", offsetof(P_ctrl_custom_T, mm2m_Gain), 44,
    1, 2, 4, 0 },

  { 3, "ctrl_custom/eta_QTM/Gain1/Gain", offsetof(P_ctrl_custom_T, Gain1_Gain),
    44, 1, 2, 6, 0 },

  { 4, "ctrl_custom/eta_QTM/deg2rad/Gain", offsetof(P_ctrl_custom_T,
    deg2rad_Gain), 44, 1, 2, 8, 0 },

  { 5, "ctrl_custom/eta_QTM/Saturation/UpperLimit", offsetof(P_ctrl_custom_T,
    Saturation_UpperSat), 44, 1, 2, 10, 0 },

  { 6, "ctrl_custom/eta_QTM/Saturation/LowerLimit", offsetof(P_ctrl_custom_T,
    Saturation_LowerSat), 44, 1, 2, 12, 0 },

  { 7, "ctrl_custom/eta_QTM/Gain6/Gain", offsetof(P_ctrl_custom_T, Gain6_Gain),
    44, 1, 2, 14, 0 },

  { 8, "ctrl_custom/eta_QTM/Constant1/Value", offsetof(P_ctrl_custom_T,
    Constant1_Value), 44, 1, 2, 16, 0 },

  { 9, "ctrl_custom/Subsystem/Memory2/X0", offsetof(P_ctrl_custom_T, Memory2_X0),
    31, 3, 2, 18, 0 },

  { 10, "ctrl_custom/Subsystem/Constant11/Value", offsetof(P_ctrl_custom_T,
    Constant11_Value), 44, 1, 2, 20, 0 },

  { 11, "ctrl_custom/Subsystem/Constant12/Value", offsetof(P_ctrl_custom_T,
    Constant12_Value), 44, 1, 2, 22, 0 },

  { 12, "ctrl_custom/Subsystem/Memory6/X0", offsetof(P_ctrl_custom_T, Memory6_X0),
    31, 3, 2, 24, 0 },

  { 13, "ctrl_custom/Subsystem/Memory7/X0", offsetof(P_ctrl_custom_T, Memory7_X0),
    44, 1, 2, 26, 0 },

  { 14, "ctrl_custom/Subsystem/Constant3/Value", offsetof(P_ctrl_custom_T,
    Constant3_Value), 44, 1, 2, 28, 0 },

  { 15, "ctrl_custom/Subsystem/Derivative filter_WO_count/Stepsize/Value",
    offsetof(P_ctrl_custom_T, Stepsize_Value), 44, 1, 2, 30, 0 },

  { 16, "ctrl_custom/Subsystem/Constant2/Value", offsetof(P_ctrl_custom_T,
    Constant2_Value), 44, 1, 2, 32, 0 },

  { 17, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory6/X0", offsetof
    (P_ctrl_custom_T, Memory6_X0_o), 31, 3, 2, 34, 0 },

  { 18, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory7/X0", offsetof
    (P_ctrl_custom_T, Memory7_X0_f), 44, 1, 2, 36, 0 },

  { 19, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory2/X0", offsetof
    (P_ctrl_custom_T, Memory2_X0_f), 31, 3, 2, 38, 0 },

  { 20, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory5/X0", offsetof
    (P_ctrl_custom_T, Memory5_X0), 31, 3, 2, 40, 0 },

  { 21, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory3/X0", offsetof
    (P_ctrl_custom_T, Memory3_X0), 31, 3, 2, 42, 0 },

  { 22, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory4/X0", offsetof
    (P_ctrl_custom_T, Memory4_X0_n), 31, 3, 2, 44, 0 },

  { 23, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory1/X0", offsetof
    (P_ctrl_custom_T, Memory1_X0), 31, 3, 2, 46, 0 },

  { 24, "ctrl_custom/Control/Constant/Value", offsetof(P_ctrl_custom_T,
    Constant_Value), 44, 1, 2, 48, 0 },

  { 25, "ctrl_custom/Control/Constant1/Value", offsetof(P_ctrl_custom_T,
    Constant1_Value_b), 44, 1, 2, 50, 0 },

  { 26, "ctrl_custom/Control/Constant2/Value", offsetof(P_ctrl_custom_T,
    Constant2_Value_c), 44, 1, 2, 52, 0 },

  { 27, "ctrl_custom/deg2rad/Gain", offsetof(P_ctrl_custom_T, deg2rad_Gain_d),
    44, 1, 2, 54, 0 },

  { 28, "ctrl_custom/Constant/Value", offsetof(P_ctrl_custom_T,
    Constant_Value_e[0]), 31, 3, 2, 56, 0 },

  { 29, "ctrl_custom/deg2rad1/Gain", offsetof(P_ctrl_custom_T, deg2rad1_Gain),
    44, 1, 2, 58, 0 },

  { 30, "ctrl_custom/Guidance1/Reference model/Integrator2/InitialCondition",
    offsetof(P_ctrl_custom_T, Integrator2_IC), 44, 1, 2, 60, 0 },

  { 31, "ctrl_custom/Guidance1/Reference model/Integrator3/InitialCondition",
    offsetof(P_ctrl_custom_T, Integrator3_IC), 44, 1, 2, 62, 0 },

  { 32, "ctrl_custom/Constant1/Value", offsetof(P_ctrl_custom_T,
    Constant1_Value_p), 44, 1, 2, 64, 0 },

  { 33,
    "ctrl_custom/Guidance1/Reference model/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_custom_T, Saturation_UpperSat_e), 44, 1, 2, 66, 0 },

  { 34,
    "ctrl_custom/Guidance1/Reference model/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_custom_T, Saturation_LowerSat_i), 44, 1, 2, 68, 0 },

  { 35,
    "ctrl_custom/Guidance1/Reference model/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_custom_T, Gain_Gain), 44, 1, 2, 70, 0 },

  { 36,
    "ctrl_custom/Guidance1/Reference model/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_custom_T, Constant_Value_g), 44, 1, 2, 72, 0 },

  { 37, "ctrl_custom/Constant2/Value", offsetof(P_ctrl_custom_T,
    Constant2_Value_f), 44, 1, 2, 74, 0 },

  { 38, "ctrl_custom/Subsystem/Derivative filter_WO_count/Stepsize1/Value",
    offsetof(P_ctrl_custom_T, Stepsize1_Value), 44, 1, 2, 76, 0 },

  { 39, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory10/X0", offsetof
    (P_ctrl_custom_T, Memory10_X0), 31, 3, 2, 78, 0 },

  { 40, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory9/X0", offsetof
    (P_ctrl_custom_T, Memory9_X0), 31, 3, 2, 80, 0 },

  { 41, "ctrl_custom/Input1/Observer Gains/Constant/Value", offsetof
    (P_ctrl_custom_T, Constant_Value_h), 44, 1, 2, 82, 0 },

  { 42, "ctrl_custom/Input1/Observer Gains/Constant1/Value", offsetof
    (P_ctrl_custom_T, Constant1_Value_b3), 44, 1, 2, 84, 0 },

  { 43, "ctrl_custom/Input1/Observer Gains/Constant2/Value", offsetof
    (P_ctrl_custom_T, Constant2_Value_h), 44, 1, 2, 86, 0 },

  { 44, "ctrl_custom/Input1/Observer Gains/Constant3/Value", offsetof
    (P_ctrl_custom_T, Constant3_Value_f), 44, 1, 2, 88, 0 },

  { 45, "ctrl_custom/Input1/Observer Gains/Constant4/Value", offsetof
    (P_ctrl_custom_T, Constant4_Value), 44, 1, 2, 90, 0 },

  { 46, "ctrl_custom/Input1/Observer Gains/Constant5/Value", offsetof
    (P_ctrl_custom_T, Constant5_Value), 44, 1, 2, 92, 0 },

  { 47, "ctrl_custom/Input1/Observer Gains/Constant6/Value", offsetof
    (P_ctrl_custom_T, Constant6_Value), 44, 1, 2, 94, 0 },

  { 48, "ctrl_custom/Input1/Observer Gains/Constant7/Value", offsetof
    (P_ctrl_custom_T, Constant7_Value), 44, 1, 2, 96, 0 },

  { 49, "ctrl_custom/Input1/Observer Gains/Constant8/Value", offsetof
    (P_ctrl_custom_T, Constant8_Value), 44, 1, 2, 98, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 50;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  12, 3,                               /* Parameter at index 0 */
  6, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 3,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 3,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 3,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 3,                                /* Parameter at index 19 */
  1, 3,                                /* Parameter at index 20 */
  1, 3,                                /* Parameter at index 21 */
  1, 3,                                /* Parameter at index 22 */
  1, 3,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 3,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 3,                                /* Parameter at index 39 */
  1, 3,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 1,                                /* Parameter at index 43 */
  1, 1,                                /* Parameter at index 44 */
  1, 1,                                /* Parameter at index 45 */
  1, 1,                                /* Parameter at index 46 */
  1, 1,                                /* Parameter at index 47 */
  1, 1,                                /* Parameter at index 48 */
  1, 1,                                /* Parameter at index 49 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_custom/Input to model", 0, "", offsetof(B_ctrl_custom_T,
    Inputtomodel) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_custom/x_ref", 0, "", offsetof(B_ctrl_custom_T, x_ref) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_custom/y_ref", 0, "", offsetof(B_ctrl_custom_T, y_ref) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 1)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (0*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 4,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 2)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (1*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 5,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 3)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (2*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 6,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 4)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (3*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 7,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 5)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (4*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 8,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 6)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (5*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 9, "ctrl_custom/eta_QTM/x_m", 0, "", offsetof(B_ctrl_custom_T, x_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_custom/eta_QTM/mm2m", 0, "", offsetof(B_ctrl_custom_T, mm2m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_custom/eta_QTM/y_m", 0, "", offsetof(B_ctrl_custom_T, y_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_custom/eta_QTM/Gain1", 0, "", offsetof(B_ctrl_custom_T, Gain1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_custom/eta_QTM/psi_m", 0, "[-180,180] [deg]", offsetof
    (B_ctrl_custom_T, u80180deg) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 14, "ctrl_custom/eta_QTM/Sum", 0, "", offsetof(B_ctrl_custom_T, Sum) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_custom/Subsystem/Memory2/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Memory2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 16, "ctrl_custom/Subsystem/Memory2/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Memory2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 17, "ctrl_custom/Subsystem/Memory2/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Memory2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 18, "ctrl_custom/Subsystem/Switch1", 0, "", offsetof(B_ctrl_custom_T,
    Switch1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_custom/Subsystem/Switch/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Switch) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 20, "ctrl_custom/Subsystem/Switch/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Switch) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 21, "ctrl_custom/Subsystem/Switch/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Switch) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 22, "ctrl_custom/Subsystem/Memory6/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Memory6) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 23, "ctrl_custom/Subsystem/Memory6/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Memory6) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 24, "ctrl_custom/Subsystem/Memory6/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Memory6) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 25, "ctrl_custom/Subsystem/Memory7", 0, "", offsetof(B_ctrl_custom_T,
    Memory7) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 26, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory6/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, Memory6_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 27, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory6/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, Memory6_n) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 28, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory6/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, Memory6_n) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 29, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory7", 0, "",
    offsetof(B_ctrl_custom_T, Memory7_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 30, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory2/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, Memory2_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 31, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory2/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, Memory2_n) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 32, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory2/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, Memory2_n) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 33, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory5/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, Memory5) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 34, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory5/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, Memory5) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 35, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory5/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, Memory5) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 36, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory3/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, Memory3) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 37, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory3/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, Memory3) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 38, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory3/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, Memory3) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 39, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory4/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, Memory4_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 40, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory4/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, Memory4_p) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 41, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory4/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, Memory4_p) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 42, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory1/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, Memory1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 43, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory1/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, Memory1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 44, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory1/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, Memory1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 45, "ctrl_custom/psi_ref [deg]", 0, "", offsetof(B_ctrl_custom_T, psi_refdeg)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 46, "ctrl_custom/Control/alpha_u", 0, "", offsetof(B_ctrl_custom_T, alpha_u)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 47, "ctrl_custom/Control/K1_u", 0, "", offsetof(B_ctrl_custom_T, K1_u) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 48, "ctrl_custom/Control/K1_r", 0, "", offsetof(B_ctrl_custom_T, K1_r) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 49, "ctrl_custom/Control/alpha_r", 0, "", offsetof(B_ctrl_custom_T, alpha_r)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 50, "ctrl_custom/deg2rad", 0, "", offsetof(B_ctrl_custom_T, deg2rad) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 51, "ctrl_custom/deg2rad1", 0, "", offsetof(B_ctrl_custom_T, deg2rad1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 52, "ctrl_custom/Input1/reset", 0, "", offsetof(B_ctrl_custom_T, reset) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 53, "ctrl_custom/Guidance1/Reference model/Integrator3/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, Integrator3) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 54, "ctrl_custom/Guidance1/Reference model/Integrator3/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, Integrator3) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 55, "ctrl_custom/Guidance1/Reference model/Integrator3/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, Integrator3) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 56, "ctrl_custom/Guidance1/Reference model/Matrix Multiply/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, MatrixMultiply) + (0*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 57, "ctrl_custom/Guidance1/Reference model/Matrix Multiply/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, MatrixMultiply) + (1*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 58, "ctrl_custom/Guidance1/Reference model/Matrix Multiply/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, MatrixMultiply) + (2*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 59, "ctrl_custom/Guidance1/Reference model/Sum5/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 60, "ctrl_custom/Guidance1/Reference model/Sum5/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Sum5) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 61, "ctrl_custom/Guidance1/Reference model/Sum5/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Sum5) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 62, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory10/(1, 1)", 0,
    "", offsetof(B_ctrl_custom_T, Memory10) + (0*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 63, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory10/(1, 2)", 0,
    "", offsetof(B_ctrl_custom_T, Memory10) + (1*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 64, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory10/(1, 3)", 0,
    "", offsetof(B_ctrl_custom_T, Memory10) + (2*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 65, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory9/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, Memory9) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 66, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory9/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, Memory9) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 67, "ctrl_custom/Subsystem/Derivative filter_WO_count/Memory9/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, Memory9) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 68, "ctrl_custom/Subsystem/Rotation matrix in yaw 1/Fcn", 0, "x_dot",
    offsetof(B_ctrl_custom_T, x_dot) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 69, "ctrl_custom/Subsystem/Rotation matrix in yaw 1/Fcn1", 0, "y_dot",
    offsetof(B_ctrl_custom_T, y_dot) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 70, "ctrl_custom/Subsystem/Rotation matrix in yaw 1/Fcn2", 0, "psi_dot",
    offsetof(B_ctrl_custom_T, psi_dot) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 71, "ctrl_custom/IMU/Acc_x", 0, "", offsetof(B_ctrl_custom_T, Acc_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 72, "ctrl_custom/IMU/Acc_y", 0, "", offsetof(B_ctrl_custom_T, Acc_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 73, "ctrl_custom/IMU/Acc_z", 0, "", offsetof(B_ctrl_custom_T, Acc_z) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 74, "ctrl_custom/IMU/Gyro_x", 0, "", offsetof(B_ctrl_custom_T, Gyro_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 75, "ctrl_custom/IMU/Gyro_y", 0, "", offsetof(B_ctrl_custom_T, Gyro_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 76, "ctrl_custom/IMU/Gyro_z", 0, "", offsetof(B_ctrl_custom_T, Gyro_z) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 77, "ctrl_custom/Input1/Control Gains/K_p_x", 0, "", offsetof
    (B_ctrl_custom_T, K_p_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 78, "ctrl_custom/Input1/Control Gains/K_p_y", 0, "", offsetof
    (B_ctrl_custom_T, K_p_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 79, "ctrl_custom/Input1/Control Gains/K_p_psi", 0, "", offsetof
    (B_ctrl_custom_T, K_p_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 80, "ctrl_custom/Input1/Control Gains/K_i_psi", 0, "", offsetof
    (B_ctrl_custom_T, K_i_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 81, "ctrl_custom/Input1/Control Gains/K_i_x", 0, "", offsetof
    (B_ctrl_custom_T, K_i_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 82, "ctrl_custom/Input1/Control Gains/K_i_y", 0, "", offsetof
    (B_ctrl_custom_T, K_i_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 83, "ctrl_custom/Input1/Control Gains/K_d_psi", 0, "", offsetof
    (B_ctrl_custom_T, K_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 84, "ctrl_custom/Input1/Control Gains/K_d_x", 0, "", offsetof
    (B_ctrl_custom_T, K_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 85, "ctrl_custom/Input1/Control Gains/K_d_y", 0, "", offsetof
    (B_ctrl_custom_T, K_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 86,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 1)", offsetof(B_ctrl_custom_T, u) + (0*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 87,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 2)", offsetof(B_ctrl_custom_T, u) + (1*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 88,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 3)", offsetof(B_ctrl_custom_T, u) + (2*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 89,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 4)", offsetof(B_ctrl_custom_T, u) + (3*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 90,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 5)", offsetof(B_ctrl_custom_T, u) + (4*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 91,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 6)", offsetof(B_ctrl_custom_T, u) + (5*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 92,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 1)", offsetof(B_ctrl_custom_T, alpha) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 93,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 2)", offsetof(B_ctrl_custom_T, alpha) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 94,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 3)", offsetof(B_ctrl_custom_T, alpha) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 95,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 4)", offsetof(B_ctrl_custom_T, alpha) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 96,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 5)", offsetof(B_ctrl_custom_T, alpha) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 97,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 6)", offsetof(B_ctrl_custom_T, alpha) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 98, "ctrl_custom/Subsystem/wraphandle", 1, "", offsetof(B_ctrl_custom_T,
    count_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 99, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function4", 1,
    "", offsetof(B_ctrl_custom_T, count_out_c) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 100, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function3", 0,
    "(1, 1)", offsetof(B_ctrl_custom_T, nu) + (0*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 101, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function3", 0,
    "(1, 2)", offsetof(B_ctrl_custom_T, nu) + (1*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 102, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function3", 0,
    "(1, 3)", offsetof(B_ctrl_custom_T, nu) + (2*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 103, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function", 0,
    "(1, 1)", offsetof(B_ctrl_custom_T, eta_filtered) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 104, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function", 0,
    "(1, 2)", offsetof(B_ctrl_custom_T, eta_filtered) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 105, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function", 0,
    "(1, 3)", offsetof(B_ctrl_custom_T, eta_filtered) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 106,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 1)", offsetof(B_ctrl_custom_T, alpha_infinf) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 107,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 2)", offsetof(B_ctrl_custom_T, alpha_infinf) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 108,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 3)", offsetof(B_ctrl_custom_T, alpha_infinf) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 109,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 4)", offsetof(B_ctrl_custom_T, alpha_infinf) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 110,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 5)", offsetof(B_ctrl_custom_T, alpha_infinf) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 111,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 6)", offsetof(B_ctrl_custom_T, alpha_infinf) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 112, "ctrl_custom/Guidance1/Reference model/w_d^3", 0, "(1, 1)", offsetof
    (B_ctrl_custom_T, y) + (0*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 113, "ctrl_custom/Guidance1/Reference model/w_d^3", 0, "(2, 1)", offsetof
    (B_ctrl_custom_T, y) + (1*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 114, "ctrl_custom/Guidance1/Reference model/w_d^3", 0, "(3, 1)", offsetof
    (B_ctrl_custom_T, y) + (2*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 115, "ctrl_custom/Guidance1/Reference model/w_d^3", 0, "(1, 2)", offsetof
    (B_ctrl_custom_T, y) + (3*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 116, "ctrl_custom/Guidance1/Reference model/w_d^3", 0, "(2, 2)", offsetof
    (B_ctrl_custom_T, y) + (4*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 117, "ctrl_custom/Guidance1/Reference model/w_d^3", 0, "(3, 2)", offsetof
    (B_ctrl_custom_T, y) + (5*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 118, "ctrl_custom/Guidance1/Reference model/w_d^3", 0, "(1, 3)", offsetof
    (B_ctrl_custom_T, y) + (6*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 119, "ctrl_custom/Guidance1/Reference model/w_d^3", 0, "(2, 3)", offsetof
    (B_ctrl_custom_T, y) + (7*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 120, "ctrl_custom/Guidance1/Reference model/w_d^3", 0, "(3, 3)", offsetof
    (B_ctrl_custom_T, y) + (8*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 121, "ctrl_custom/Guidance1/Reference model/w_d^-2", 0, "(1, 1)", offsetof
    (B_ctrl_custom_T, y_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 122, "ctrl_custom/Guidance1/Reference model/w_d^-2", 0, "(2, 1)", offsetof
    (B_ctrl_custom_T, y_g) + (1*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 123, "ctrl_custom/Guidance1/Reference model/w_d^-2", 0, "(3, 1)", offsetof
    (B_ctrl_custom_T, y_g) + (2*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 124, "ctrl_custom/Guidance1/Reference model/w_d^-2", 0, "(1, 2)", offsetof
    (B_ctrl_custom_T, y_g) + (3*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 125, "ctrl_custom/Guidance1/Reference model/w_d^-2", 0, "(2, 2)", offsetof
    (B_ctrl_custom_T, y_g) + (4*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 126, "ctrl_custom/Guidance1/Reference model/w_d^-2", 0, "(3, 2)", offsetof
    (B_ctrl_custom_T, y_g) + (5*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 127, "ctrl_custom/Guidance1/Reference model/w_d^-2", 0, "(1, 3)", offsetof
    (B_ctrl_custom_T, y_g) + (6*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 128, "ctrl_custom/Guidance1/Reference model/w_d^-2", 0, "(2, 3)", offsetof
    (B_ctrl_custom_T, y_g) + (7*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 129, "ctrl_custom/Guidance1/Reference model/w_d^-2", 0, "(3, 3)", offsetof
    (B_ctrl_custom_T, y_g) + (8*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 130, "ctrl_custom/Guidance1/Reference model/w_d*w_d1", 0, "(1, 1)", offsetof
    (B_ctrl_custom_T, y_gl) + (0*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 131, "ctrl_custom/Guidance1/Reference model/w_d*w_d1", 0, "(2, 1)", offsetof
    (B_ctrl_custom_T, y_gl) + (1*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 132, "ctrl_custom/Guidance1/Reference model/w_d*w_d1", 0, "(3, 1)", offsetof
    (B_ctrl_custom_T, y_gl) + (2*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 133, "ctrl_custom/Guidance1/Reference model/w_d*w_d1", 0, "(1, 2)", offsetof
    (B_ctrl_custom_T, y_gl) + (3*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 134, "ctrl_custom/Guidance1/Reference model/w_d*w_d1", 0, "(2, 2)", offsetof
    (B_ctrl_custom_T, y_gl) + (4*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 135, "ctrl_custom/Guidance1/Reference model/w_d*w_d1", 0, "(3, 2)", offsetof
    (B_ctrl_custom_T, y_gl) + (5*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 136, "ctrl_custom/Guidance1/Reference model/w_d*w_d1", 0, "(1, 3)", offsetof
    (B_ctrl_custom_T, y_gl) + (6*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 137, "ctrl_custom/Guidance1/Reference model/w_d*w_d1", 0, "(2, 3)", offsetof
    (B_ctrl_custom_T, y_gl) + (7*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 138, "ctrl_custom/Guidance1/Reference model/w_d*w_d1", 0, "(3, 3)", offsetof
    (B_ctrl_custom_T, y_gl) + (8*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 139, "ctrl_custom/Guidance1/Reference model/w_d*w_d", 0, "(1, 1)", offsetof
    (B_ctrl_custom_T, y_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 140, "ctrl_custom/Guidance1/Reference model/w_d*w_d", 0, "(2, 1)", offsetof
    (B_ctrl_custom_T, y_c) + (1*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 141, "ctrl_custom/Guidance1/Reference model/w_d*w_d", 0, "(3, 1)", offsetof
    (B_ctrl_custom_T, y_c) + (2*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 142, "ctrl_custom/Guidance1/Reference model/w_d*w_d", 0, "(1, 2)", offsetof
    (B_ctrl_custom_T, y_c) + (3*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 143, "ctrl_custom/Guidance1/Reference model/w_d*w_d", 0, "(2, 2)", offsetof
    (B_ctrl_custom_T, y_c) + (4*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 144, "ctrl_custom/Guidance1/Reference model/w_d*w_d", 0, "(3, 2)", offsetof
    (B_ctrl_custom_T, y_c) + (5*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 145, "ctrl_custom/Guidance1/Reference model/w_d*w_d", 0, "(1, 3)", offsetof
    (B_ctrl_custom_T, y_c) + (6*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 146, "ctrl_custom/Guidance1/Reference model/w_d*w_d", 0, "(2, 3)", offsetof
    (B_ctrl_custom_T, y_c) + (7*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 147, "ctrl_custom/Guidance1/Reference model/w_d*w_d", 0, "(3, 3)", offsetof
    (B_ctrl_custom_T, y_c) + (8*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 148, "ctrl_custom/Control/MATLAB Function4", 0, "(1, 1)", offsetof
    (B_ctrl_custom_T, tau1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 149, "ctrl_custom/Control/MATLAB Function4", 0, "(1, 2)", offsetof
    (B_ctrl_custom_T, tau1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 150, "ctrl_custom/Control/MATLAB Function4", 0, "(1, 3)", offsetof
    (B_ctrl_custom_T, tau1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 151, "ctrl_custom/Control/MATLAB Function4", 1, "(1, 1)", offsetof
    (B_ctrl_custom_T, z_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 152, "ctrl_custom/Control/MATLAB Function4", 1, "(1, 2)", offsetof
    (B_ctrl_custom_T, z_1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 153, "ctrl_custom/Control/MATLAB Function4", 1, "(1, 3)", offsetof
    (B_ctrl_custom_T, z_1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 154, "ctrl_custom/Control/MATLAB Function4", 5, "(1, 1)", offsetof
    (B_ctrl_custom_T, z_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 155, "ctrl_custom/Control/MATLAB Function4", 5, "(1, 2)", offsetof
    (B_ctrl_custom_T, z_2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 156, "ctrl_custom/Control/MATLAB Function4", 5, "(1, 3)", offsetof
    (B_ctrl_custom_T, z_2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 157, "ctrl_custom/diag1", 0, "(1, 1)", offsetof(B_ctrl_custom_T,
    sf_diag1.w_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 158, "ctrl_custom/diag1", 0, "(2, 1)", offsetof(B_ctrl_custom_T,
    sf_diag1.w_d) + (1*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 159, "ctrl_custom/diag1", 0, "(3, 1)", offsetof(B_ctrl_custom_T,
    sf_diag1.w_d) + (2*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 160, "ctrl_custom/diag1", 0, "(1, 2)", offsetof(B_ctrl_custom_T,
    sf_diag1.w_d) + (3*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 161, "ctrl_custom/diag1", 0, "(2, 2)", offsetof(B_ctrl_custom_T,
    sf_diag1.w_d) + (4*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 162, "ctrl_custom/diag1", 0, "(3, 2)", offsetof(B_ctrl_custom_T,
    sf_diag1.w_d) + (5*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 163, "ctrl_custom/diag1", 0, "(1, 3)", offsetof(B_ctrl_custom_T,
    sf_diag1.w_d) + (6*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 164, "ctrl_custom/diag1", 0, "(2, 3)", offsetof(B_ctrl_custom_T,
    sf_diag1.w_d) + (7*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 165, "ctrl_custom/diag1", 0, "(3, 3)", offsetof(B_ctrl_custom_T,
    sf_diag1.w_d) + (8*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 166, "ctrl_custom/diag", 0, "(1, 1)", offsetof(B_ctrl_custom_T, sf_diag.w_d)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 167, "ctrl_custom/diag", 0, "(2, 1)", offsetof(B_ctrl_custom_T, sf_diag.w_d)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 168, "ctrl_custom/diag", 0, "(3, 1)", offsetof(B_ctrl_custom_T, sf_diag.w_d)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 169, "ctrl_custom/diag", 0, "(1, 2)", offsetof(B_ctrl_custom_T, sf_diag.w_d)
    + (3*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 170, "ctrl_custom/diag", 0, "(2, 2)", offsetof(B_ctrl_custom_T, sf_diag.w_d)
    + (4*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 171, "ctrl_custom/diag", 0, "(3, 2)", offsetof(B_ctrl_custom_T, sf_diag.w_d)
    + (5*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 172, "ctrl_custom/diag", 0, "(1, 3)", offsetof(B_ctrl_custom_T, sf_diag.w_d)
    + (6*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 173, "ctrl_custom/diag", 0, "(2, 3)", offsetof(B_ctrl_custom_T, sf_diag.w_d)
    + (7*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 174, "ctrl_custom/diag", 0, "(3, 3)", offsetof(B_ctrl_custom_T, sf_diag.w_d)
    + (8*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 175, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function8", 0,
    "(1, 1)", offsetof(B_ctrl_custom_T, sf_MATLABFunction8.eta_dot) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 176, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function8", 0,
    "(1, 2)", offsetof(B_ctrl_custom_T, sf_MATLABFunction8.eta_dot) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 177, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function8", 0,
    "(1, 3)", offsetof(B_ctrl_custom_T, sf_MATLABFunction8.eta_dot) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 178, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function7", 0,
    "(1, 1)", offsetof(B_ctrl_custom_T, sf_MATLABFunction7.eta_dot_filtered) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 179, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function7", 0,
    "(1, 2)", offsetof(B_ctrl_custom_T, sf_MATLABFunction7.eta_dot_filtered) +
    (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 180, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function7", 0,
    "(1, 3)", offsetof(B_ctrl_custom_T, sf_MATLABFunction7.eta_dot_filtered) +
    (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 181, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function2", 0,
    "(1, 1)", offsetof(B_ctrl_custom_T, sf_MATLABFunction2.eta_dot_filtered) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 182, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function2", 0,
    "(1, 2)", offsetof(B_ctrl_custom_T, sf_MATLABFunction2.eta_dot_filtered) +
    (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 183, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function2", 0,
    "(1, 3)", offsetof(B_ctrl_custom_T, sf_MATLABFunction2.eta_dot_filtered) +
    (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 184, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function1", 0,
    "(1, 1)", offsetof(B_ctrl_custom_T, sf_MATLABFunction1.eta_dot) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 185, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function1", 0,
    "(1, 2)", offsetof(B_ctrl_custom_T, sf_MATLABFunction1.eta_dot) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 186, "ctrl_custom/Subsystem/Derivative filter_WO_count/MATLAB Function1", 0,
    "(1, 3)", offsetof(B_ctrl_custom_T, sf_MATLABFunction1.eta_dot) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 187;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 43;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Input to model", 1, EXT_IN, 1, 1, 1 },

  { 2, "x_ref", 0, EXT_IN, 1, 1, 1 },

  { 3, "y_ref", 0, EXT_IN, 1, 1, 1 },

  { 4, "eta_QTM/x_m", 0, EXT_IN, 1, 1, 1 },

  { 5, "eta_QTM/y_m", 0, EXT_IN, 1, 1, 1 },

  { 6, "eta_QTM/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 7, "psi_ref [deg]", 0, EXT_IN, 1, 1, 1 },

  { 8, "Control/alpha_u", 0, EXT_IN, 1, 1, 1 },

  { 9, "Control/K1_u", 0, EXT_IN, 1, 1, 1 },

  { 10, "Control/K1_r", 0, EXT_IN, 1, 1, 1 },

  { 11, "Control/alpha_r", 0, EXT_IN, 1, 1, 1 },

  { 12, "Input1/reset", 0, EXT_IN, 1, 1, 1 },

  { 13, "IMU/Acc_x", 1, EXT_IN, 1, 1, 1 },

  { 14, "IMU/Acc_y", 1, EXT_IN, 1, 1, 1 },

  { 15, "IMU/Acc_z", 1, EXT_IN, 1, 1, 1 },

  { 16, "IMU/Gyro_x", 1, EXT_IN, 1, 1, 1 },

  { 17, "IMU/Gyro_y", 1, EXT_IN, 1, 1, 1 },

  { 18, "IMU/Gyro_z", 1, EXT_IN, 1, 1, 1 },

  { 19, "Input1/Control Gains/K_p_x", 1, EXT_IN, 1, 1, 1 },

  { 20, "Input1/Control Gains/K_p_y", 1, EXT_IN, 1, 1, 1 },

  { 21, "Input1/Control Gains/K_p_psi", 1, EXT_IN, 1, 1, 1 },

  { 22, "Input1/Control Gains/K_i_psi", 1, EXT_IN, 1, 1, 1 },

  { 23, "Input1/Control Gains/K_i_x", 1, EXT_IN, 1, 1, 1 },

  { 24, "Input1/Control Gains/K_i_y", 1, EXT_IN, 1, 1, 1 },

  { 25, "Input1/Control Gains/K_d_psi", 1, EXT_IN, 1, 1, 1 },

  { 26, "Input1/Control Gains/K_d_x", 1, EXT_IN, 1, 1, 1 },

  { 27, "Input1/Control Gains/K_d_y", 1, EXT_IN, 1, 1, 1 },

  { 1, "Output to Workspace", 1, EXT_OUT, 1, 1, 1 },

  { 2, "x_t", 0, EXT_OUT, 1, 1, 1 },

  { 3, "y_t", 0, EXT_OUT, 1, 1, 1 },

  { 4, "Output/alpha1", 0, EXT_OUT, 1, 1, 1 },

  { 5, "Output/alpha2", 0, EXT_OUT, 1, 1, 1 },

  { 6, "Output/alpha3", 0, EXT_OUT, 1, 1, 1 },

  { 7, "Output/alpha4", 0, EXT_OUT, 1, 1, 1 },

  { 8, "Output/alpha5", 0, EXT_OUT, 1, 1, 1 },

  { 9, "Output/alpha6", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Output/u1", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Output/u2", 0, EXT_OUT, 1, 1, 1 },

  { 12, "Output/u3", 0, EXT_OUT, 1, 1, 1 },

  { 13, "Output/u4", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Output/u5", 0, EXT_OUT, 1, 1, 1 },

  { 15, "Output/u6", 0, EXT_OUT, 1, 1, 1 },

  { 16, "psi_t", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int32_t NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static const char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_custom";
static const char* NI_CompiledModelVersion = "1.93";
static const char* NI_CompiledModelDateTime = "Mon Sep 25 10:58:12 2017";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2017.0.0.143 (2017) for Simulink Coder 8.11 (R2016b)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2017.0.0.143";

/*========================================================================*
 * Function: NIRT_GetBuildInfo
 *
 * Abstract:
 *	Get the DLL versioning etc information.
 *
 * Output Parameters:
 *	detail	: String containing model build information.
 *	len		: the build info string length. If a value of "-1" is specified, the minimum buffer size of "detail" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetBuildInfo(char* detail, int32_t* len)
{
  int32_t msgLength = 0;
  char *msgBuffer = NULL;

  /* Message */
  const char msg[] =
    "%s\nModel Name: %s\nModel Version: %s\nVeriStand Model Framework Version: %s\nCompiled On: %s";

  /* There are no console properties to set for VxWorks, because the console is simply serial output data.
     Just do printf for VxWorks and ignore all console properties. */
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  /* Print to screen */
  printf("\n*******************************************************************************\n");
  msgLength = printf(msg, NI_builder, NI_CompiledModelName,
                     NI_CompiledModelVersion, NI_BuilderVersion,
                     NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len == -1) {
    /* Return the required minimum buffer size */
    *len = msgLength;
  } else {
    /* allocate the buffer */
    msgBuffer = (char*)calloc(msgLength + 1, sizeof(char));
    sprintf (msgBuffer, msg, NI_builder, NI_CompiledModelName,
             NI_CompiledModelVersion, NI_BuilderVersion,
             NI_CompiledModelDateTime);
    if (*len >= msgLength) {
      *len = msgLength + 1;
    }

    /* Copy into external buffer */
    strncpy(detail, msgBuffer, *len);

    /* Release memory */
    free(msgBuffer);
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSignalSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	index		: index of the signal (in/out)
 *	ID			: ID of signal to be looked up (in), ID of signal at index (out)
 *	ID_len		: length of input ID(in), length of ID (out)
 *	bnlen		: length of buffer blkname (in), length of output blkname (out)
 *	snlen		: length of buffer signame (in), length of output signame (out)
 *
 * Output Parameters:
 *	blkname		: Name of the source block for the signal
 *	portnum		: port number of the block that is the source of the signal (0 indexed)
 *	signame		: Name of the signal
 *	datatype	: same as with parameters. Currently assuming all data to be double.
 *	dims		: The port's dimension of length 'numdims'.
 *	numdims		: the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error(if sigidx == -1, number of signals)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSignalSpec(int32_t* sidx, char* ID, int32_t* ID_len,
  char* blkname, int32_t *bnlen,
  int32_t *portnum, char* signame, int32_t *snlen, int32_t *dattype, int32_t*
  dims, int32_t* numdim)
{
  int32_t sigidx = *sidx;
  int32_t i = 0;
  char *addr = NULL;
  char *IDblk = 0;
  int32_t IDport = 0;
  if (sigidx < 0) {
    /* check if ID has been specified. */
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0)) {
      /* parse ID into blkname and port */
      addr = strrchr(ID, ':');
      if (addr == NULL) {
        return NI_SigListSize;
      }

      /* Calculate the char offset into the string after the port */
      i = addr - ID;

      /* malformed ID */
      if (i<=0) {
        return NI_SigListSize;
      }

      IDblk = ID;
      IDport = atoi(ID+i+1);

      /* lookup the table for matching ID */
      for (i=0; i<NI_SigListSize; i++) {
        /* 11 to accomodate ':','/', port number and null character */
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname) + 11, sizeof(char));
        if (strlen(NI_SigList[i].signalname)>0) {
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        } else {
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        }

        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1)) {
          break;
        }

        free(tempID);
      }

      if (i < NI_SigListSize) {
        sigidx = *sidx = i;
      } else {
        return NI_SigListSize;
      }
    } else {
      // no index or ID specified.
      return NI_SigListSize;
    }
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID != NULL) {
      // no need for return string to be null terminated!
      /* 11 to accomodate ':','/', port number and null character */
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0) {
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      } else {
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      }

      if ((int32_t)strlen(tempID)<*ID_len) {
        *ID_len = strlen(tempID);
      }

      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].blockname)<*bnlen) {
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      }

      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].signalname)<*snlen) {
        *snlen = strlen(NI_SigList[sigidx].signalname);
      }

      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum != NULL) {
      *portnum = NI_SigList[sigidx].portno;
    }

    if (dattype != NULL) {
      *dattype = NI_SigList[sigidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_SigList[sigidx].numofdims;
      } else if (dims != NULL) {
        for (i=0;i < *numdim; i++) {
          dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
        }
      }
    }

    return NI_OK;
  }

  return NI_SigListSize;
}

/*========================================================================*
 * Function: NIRT_GetParameterIndices
 *
 * Abstract:
 *	Returns an array of indices to tunable parameters
 *
 * Output Parameters:
 *	indices	: buffer to store the parameter indices of length "len"
 *	len		: returns the number of indices. If a value of "-1" is specified, the minimum buffer size of "indices" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterIndices(int32_t* indices, int32_t* len)
{
  int32_t i;
  if ((len == NULL) || (indices == NULL)) {
    return NI_ERROR;
  }

  if (*len == -1) {
    *len = NI_ParamListSize;
  } else {
    for (i=0; (i < NI_ParamListSize) && (i < *len); i++) {
      indices[i] = NI_ParamList[i].idx;
    }

    *len = i;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetParameterSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	paramidx	: index of the parameter(in/out). If a value of "-1" is specified, the parameter's ID is used instead
 *	ID			: ID of parameter to be looked up (in), ID of parameter at index (out)
 *	ID_len		: length of input ID (in), length of ID (out)
 *	pnlen		: length of buffer paramname(in), length of the returned paramname (out)
 *	numdim		: length of buffer dimension(in), length of output dimension (out). If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value
 *
 * Output Parameters:
 *	paramname	: Name of the parameter
 *	datatype	: datatype of the parameter (currently assuming 0: double, .. )
 *	dims		: array of dimensions with length 'numdim'
 *
 * Returns:
 *	NI_OK if no error (if paramidx == -1, number of tunable parameters)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterSpec(int32_t* pidx, char* ID, int32_t*
  ID_len, char* paramname, int32_t *pnlen,
  int32_t *dattype, int32_t* dims, int32_t* numdim)
{
  int32_t i = 0;
  int32_t paramidx = *pidx;
  if (paramidx < 0) {
    // check if ID has been specified.
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0) ) {
      // lookup the table for matching ID
      for (i=0; i < NI_ParamListSize; i++) {
        if (strcmp(ID,NI_ParamList[i].paramname) == 0) {
          /* found matching string */
          break;
        }
      }

      if (i < NI_ParamListSize) {
        /* note the index into the rtParamAttribs */
        paramidx = *pidx = i;
      } else {
        return NI_ParamListSize;
      }
    } else {
      // no index or ID specified.
      return NI_ParamListSize;
    }
  }

  if ((paramidx >= 0) && (paramidx<NI_ParamListSize)) {
    if (ID != NULL) {
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *ID_len) {
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname != NULL) {
      /* no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *pnlen) {
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype != NULL) {
      *dattype = NI_ParamList[paramidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_ParamList[paramidx].numofdims;
      } else if (dims != NULL) {
        for (i = 0; i < *numdim; i++) {
          dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset + i];
        }
      }
    }

    return NI_OK;
  }

  return NI_ParamListSize;
}

/*========================================================================*
 * Function: NIRT_GetExtIOSpec
 *
 * Abstract:
 *	Returns the model's inport or outport specification
 *
 * Input Parameters:
 *	index	: index of the task
 *
 * Output Parameters:
 *	idx		: idx of the IO.
 *	name	: Name of the IO block
 *	tid		: task id
 *	type	: EXT_IN or EXT_OUT
 *	dims	: The port's dimension of length 'numdims'.
 *	numdims : the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns
 *	NI_OK if no error. (if index == -1, return number of tasks in the model)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetExtIOSpec(int32_t index, int32_t *idx, char* name,
  int32_t* tid, int32_t *type, int32_t *dims, int32_t* numdims)
{
  if (index == -1) {
    return NI_ExtListSize;
  }

  if (idx != NULL) {
    *idx = NI_ExtList[index].idx;
  }

  if (name != NULL) {
    int32_t sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid != NULL) {
    *tid = NI_ExtList[index].TID;
  }

  if (type != NULL) {
    *type = NI_ExtList[index].type;
  }

  if (numdims != NULL) {
    if (*numdims == -1) {
      *numdims = 2;
    } else if (numdims != NULL) {
      /* Return port dimensions */
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    }
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NI_ProbeOneSignal
 *
 * Abstract:
 *		Helper function to probe one signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: Returns the last index value probed in a vector signal
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
    SetSITErrorMessage("NI_ProbeOneSignal: Received request to probe a virtual signal, but was expecting a ground source. Ignoring virtual signal probe. Report this behavior to National Instruments.",
                       0);
    return 0;
  } else {
    char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ? S->blockIO :
                        S->inputs) + (uintptr_t)NI_SigList[idx].addr;
    int32_t subindex = (vLength == -1) ? 0 : vOffset;
    int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
      vOffset);
    while ((subindex < sublength) && (*count < len))
      value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++,
        NI_SigList[idx].datatype, NI_SigList[idx].IsComplex);
    return *count;
  }
}

/*========================================================================*
 * Function: NIRT_ProbeSignals
 *
 * Abstract:
 *	returns the latest signal values.
 *
 * Input Parameters:
 *	sigindices	: list of signal indices to be probed.
 *	numsigs		: length of sigindices array.
 *
 *		NOTE: (Implementation detail) the sigindices array that is passed in is delimited by a value of -1.
 *		Thus the # of valid indices in the sigindices table is min(numsigs, index of value -1) - 1.
 *		Reason for subtracting 1, the first index in the array is used for bookkeeping and should be copied
 *		into the 0th index in the signal values buffer.
 *		Also, the 1st index in the signal values buffer should contain the current timestamp. Hence valid
 *		signal data should be filled in starting from index 2. Any non-scalar signals should be added to the
 *		buffer in row-order.
 *
 * Input/Output Parameters
 *	num			: (in) length of sigvalues buffer (out) number of values returned in the buffer
 *
 * Output Parameters:
 *	value		: array of signal values
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_ProbeSignals(int32_t* sigindices, int32_t numsigs,
  double* value, int32_t* len)
{
  int32_t i = 0;
  int32_t idx = 0;
  int32_t count = 0;
  if (!SITexportglobals.inCriticalSection) {
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  }

  /* Get the index to the first signal */
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  /* Get the second and other signals */
  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0) {
      break;
    }

    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        int32_t vidx = NI_VirtualBlockSources[NI_SigList[idx].addr];
        NI_ProbeOneSignal(vidx, value, *len, &count, 0, -1);
      } else {
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
      }
    }
  }

  *len = count;
  return count;
}

int32_t NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_custom_P, sizeof(P_ctrl_custom_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_custom_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_custom_T));
  return NI_OK;
}

static int32_t NI_SetParamTxStatus = NI_OK;

/*========================================================================*
 * Function: NIRT_SetParameter
 *
 * Abstract:
 *	Set parameter value. Called either in scheduler loop or a background loop.
 *
 * Input Parameters:
 *	index	: index of the parameter (as specified in Parameter Information)
 *	subindex: index in the flattened array, if parameter is n-D array
 *	val		: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  char* ptr = NULL;

  /* Check bounds */
  if (index >= NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_custom_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0) {
        /* No values to commit */
        return NI_OK;
      } else {
        SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                           1);
        WriteSideDirtyFlag = 0;
        return NI_ERROR;
      }
    }

    /* If an error occurred and we have values to commit, then save to the write side and return error */
    if (NI_SetParamTxStatus == NI_ERROR) {
      // fail the transaction.
      // copy old list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1) {
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_custom_T));
      }

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      // Copy back the newly set parameters to the writeside.
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_custom_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex >= NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_custom_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, value, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_SetVectorParameter
 *
 * Abstract:
 *	Sets the value to a parameter array.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	paramvalues	: array of values to set
 *	paramlength	: Length of parameter values.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetVectorParameter( uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  uint32_t i = 0;
  int32_t retval = NI_OK;
  char* ptr = NULL;

  /* verify that index is within bounds*/
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_custom_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char*)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  while (i < paramlength) {
    /* Convert the incoming double datatype to the parameter's internal datatype and update value */
    retval = retval & NIRT_SetValueByDataType(ptr, i, paramvalues[i],
      NI_ParamList[index].datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

/*========================================================================*
 * Function: NIRT_SetScalarParameterInline
 *
 * Abstract:
 *	Sets the value to a parameter immediately without the need of a commit request.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	subindex	: offset of the element within the parameter
 *	paramvalue	: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetScalarParameterInline( uint32_t index, uint32_t
  subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, paramvalue, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_GetParameter
 *
 * Abstract:
 *	Get the current value of a parameter.
 *
 * Input Parameters:
 *	index	: index of the parameter
 *	subindex: element index into the flattened array if an array
 *
 * Output Parameters:
 *	val		: value of the parameter
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  char* ptr = NULL;

  /* Check index boundaries */
  if (index >= NI_ParamListSize || index < 0 || (subindex>=NI_ParamList[index].
       width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;

  /* Convert the parameter's internal datatype to double and return its value */
  *value = NIRT_GetValueByDataType(ptr, subindex, NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetVectorParameter
 *
 * Abstract:
 *	Get the current value of a vector parameter.
 *
 * Input Parameters:
 *	index: index of the parameter
 *	paramLength: length of the parameter
 *
 * Output Parameters:
 *	paramValues: an array of the parameter's value
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  char* ptr = NULL;
  uint32_t i = 0;
  if (index >= (uint32_t)NI_ParamListSize || index < 0 || (paramlength !=
       (uint32_t)NI_ParamList[index].width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  while (i<paramlength) {
    /* Convert the parameter's internal datatype to double and return its value */
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSimState(int32_t* numContStates, char
  * contStatesNames, double* contStates, int32_t* numDiscStates, char
  * discStatesNames, double* discStates, int32_t* numClockTicks, char
  * clockTicksNames, int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 12;
      *numDiscStates = 627;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator3_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator3_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator3_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Inputtomodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Inputtomodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.OutputtoWorkspace_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.OutputtoWorkspace_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_t_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_t_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_t_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_t_DWORK1");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.Memory4_PreviousInput, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.Memory4_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory6_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory6_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory6_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory6_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory6_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory6_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory7_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory7_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory6_PreviousInput_c, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory6_PreviousInput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory6_PreviousInput_c, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory6_PreviousInput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory6_PreviousInput_c, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory6_PreviousInput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory7_PreviousInput_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory7_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput_m, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput_m, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput_m, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory5_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory5_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory5_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory3_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory3_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory3_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory4_PreviousInput_l, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory4_PreviousInput_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory4_PreviousInput_l, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory4_PreviousInput_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory4_PreviousInput_l, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory4_PreviousInput_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_refdeg_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_refdeg_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha_u_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha_u_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K1_u_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K1_u_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K1_r_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K1_r_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha_r_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha_r_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_t_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_t_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.reset_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory10_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory10_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory10_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory10_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory10_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory10_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory9_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory9_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory9_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory9_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory9_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory9_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_p_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_p_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_p_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_i_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_i_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_i_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_i_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_d_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_d_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_d_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile1_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile1_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile2_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile2_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile3_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile4_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile4_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile5_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile5_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile6_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile6_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile_PWORK_l, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile_PWORK_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile1_PWORK_l, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile1_PWORK_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Scope1_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Scope1_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile_IWORK.Count,
      0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile1_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile1_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile1_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile1_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile2_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile2_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile2_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile2_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile4_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile4_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile4_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile4_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile5_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile5_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile5_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile5_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile6_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile6_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile6_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile6_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile_IWORK_m.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile_IWORK_m.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile_IWORK_m.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile_IWORK_m.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile1_IWORK_i.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile1_IWORK_i.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile1_IWORK_i.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile1_IWORK_i.Decimation");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.Inputtomodel_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.Inputtomodel_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.OutputtoWorkspace_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.OutputtoWorkspace_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_ref_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_t_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_t_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_ref_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_t_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_t_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.psi_refdeg_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.psi_refdeg_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha_u_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha_u_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K1_u_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K1_u_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K1_r_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K1_r_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha_r_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha_r_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha3_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha4_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha5_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha6_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u1_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u2_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u3_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u4_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u5_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u6_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_t_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_t_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.reset_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.reset_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_z_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_z_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_p_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_p_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_p_psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_i_psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_i_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_i_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_d_psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_d_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.K_d_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.K_d_y_DWORK2");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.PHI_not_empty, 0,
      8, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.PHI_not_empty");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.OMEGA_N_not_empty,
      0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.OMEGA_N_not_empty");
  }

  if ((clockTicks != NULL) && (clockTicksNames != NULL)) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_SetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetSimState(double* contStates, double* discStates,
  int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if (contStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator3_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator3_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator3_CSTATE), 2,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_custom_DW.Inputtomodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.OutputtoWorkspace_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.x_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.x_t_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.y_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.y_t_DWORK1, 0, discStates[idx++], 0,
      0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Memory4_PreviousInput, count,
        discStates[idx++], 22, 0);
    }

    NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory6_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory6_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory6_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory7_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory6_PreviousInput_c, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory6_PreviousInput_c, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory6_PreviousInput_c, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory7_PreviousInput_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput_m, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput_m, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput_m, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory5_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory5_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory5_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory3_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory3_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory3_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory4_PreviousInput_l, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory4_PreviousInput_l, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory4_PreviousInput_l, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.psi_refdeg_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_u_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K1_u_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K1_r_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_r_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.psi_t_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.reset_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory10_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory10_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory10_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory9_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory9_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory9_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K_p_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K_p_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K_p_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K_i_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K_i_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K_i_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K_d_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K_d_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.K_d_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile1_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile2_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile4_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile5_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile6_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile_PWORK_l, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile1_PWORK_l, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Scope1_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile1_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile1_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile2_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile2_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile4_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile4_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile5_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile5_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile6_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile6_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile_IWORK_m.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile_IWORK_m.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile1_IWORK_i.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile1_IWORK_i.Decimation, 0,
      discStates[idx++], 21, 0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Inputtomodel_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.OutputtoWorkspace_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.x_ref_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.x_t_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.y_ref_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.y_t_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.psi_refdeg_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_u_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K1_u_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K1_r_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_r_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha3_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha4_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha5_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha6_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u1_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u2_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u3_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u4_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u5_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u6_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.psi_t_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.reset_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K_p_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K_p_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K_p_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K_i_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K_i_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K_i_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K_d_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K_d_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.K_d_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    NIRT_SetValueByDataType(&ctrl_custom_DW.PHI_not_empty, 0, discStates[idx++],
      8, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.OMEGA_N_not_empty, 0, discStates[idx
      ++], 8, 0);
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_custom
