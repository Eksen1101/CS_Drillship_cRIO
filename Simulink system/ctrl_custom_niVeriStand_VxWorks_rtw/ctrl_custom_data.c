#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define ctrl_custom_P                  ctrl_custom_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_custom_data.c
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
#include "ctrl_custom.h"
#include "ctrl_custom_private.h"

/* Block parameters (auto storage) */
P_ctrl_custom_T ctrl_custom_P = {
  /*  Variable: T_pinv
   * Referenced by: '<S10>/Gain'
   */
  { 0.290140228409367, 0.0049618745516802846, 0.30038732539613983,
    0.0046670240844234939, 0.2915231516072464, 0.004517478324220228,
    0.43494048058922113, -0.00409922642319548, 0.37074227769966916,
    -0.0027253337061956774, 0.430012258763733, -0.0031734037820840681,
    0.0012802139234394129, 0.45458834267977311, -0.011706705864021153,
    0.45545287240157872, 0.013900860449174383, 0.44085876600573215,
    0.0019191301467238182, 0.29899274383846575, 0.025596560222822074,
    0.27962499960008025, -0.026002673611565979, 0.32559793660455272,
    0.0034478934521828728, 0.4429984076372469, -0.031528695131473945,
    0.41667402435721734, 0.0374380287894787, 0.40332251114402784,
    0.0051686332616964082, -0.36598079195798555, 0.0689370821351245,
    -0.24331902782910067, -0.070030833474847509, -0.28332292717420593 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Input to model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Input to model'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Input to model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Input to model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Input to model'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Input to model'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_ref'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_t'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_t'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_t'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_t'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_t'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_t'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_ref'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_t'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_t'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_t'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_t'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_t'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_t'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/reset'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S41>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S41>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S41>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S41>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S41>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S41>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S38>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S38>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S41>/psi_hat'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S6>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/v_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/v_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/v_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/r_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/r_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/r_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/x_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/x_m'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S11>/mm2m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/y_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/y_m'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S11>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/psi_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/psi_m'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S11>/deg2rad'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S11>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S11>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S11>/Gain6'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S11>/Constant1'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S39>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S39>/Constant'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S6>/Integrator2'
   */
  { 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant6'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant8'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/alpha_u'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/K1_u'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/K1_u'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/K1_u'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/K1_u'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/K1_u'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/K1_u'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/K1_r'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/K1_r'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/K1_r'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/K1_r'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/K1_r'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/K1_r'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/alpha_r'
                                        */
  124.658,                             /* Expression: 127.92-3.262
                                        * Referenced by: '<S1>/Constant'
                                        */
  99.03,                               /* Expression: 127.92-28.89
                                        * Referenced by: '<S1>/Constant1'
                                        */
  47.986999999999995,                  /* Expression: 61.967-13.98
                                        * Referenced by: '<S1>/Constant2'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/deg2rad'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0.008021948049864 0 0;0 0.010098125265799 1.104781662647098e-04;0 3.303823257820844e-05 0.020839338676560]
   * Referenced by: '<S6>/M^-1'
   */
  { 0.008021948049864, 0.0, 0.0, 0.0, 0.010098125265799, 3.303823257820844E-5,
    0.0, 0.0001104781662647098, 0.02083933867656 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */

  /*  Expression: [0 0 0 0 0 0]'
   * Referenced by: '<S9>/Memory4'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha3'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha6'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u2'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u3'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/u3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u4'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/u4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u5'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/u5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u6'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/u6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u6'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/deg2rad1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_t'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_t'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_t'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_t'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_t'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_t'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S24>/Constant'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S24>/Constant1'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S24>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  1.0                                  /* Expression: btype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.90
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Wed Sep 20 14:24:54 2017
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_custom_T_sizes[] DataSection(".NIVS.defaultparamsizes")
  = {
  { sizeof(P_ctrl_custom_T), 1 },

  { sizeof(real_T), 36, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
