/*
 * Torque_Vectoring_Controller_dSpace_RTI1401.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Vectoring_Controller_dSpace_RTI1401".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Wed Apr 26 00:19:42 2017
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_Vectoring_Controller_dSpace_RTI1401_trc_ptr.h"
#include "Torque_Vectoring_Controller_dSpace_RTI1401.h"
#include "Torque_Vectoring_Controller_dSpace_RTI1401_private.h"

/* Block signals (auto storage) */
B_Torque_Vectoring_Controller_T Torque_Vectoring_Controller_d_B;

/* Block states (auto storage) */
DW_Torque_Vectoring_Controlle_T Torque_Vectoring_Controller__DW;

/* Real-time model */
RT_MODEL_Torque_Vectoring_Con_T Torque_Vectoring_Controller__M_;
RT_MODEL_Torque_Vectoring_Con_T *const Torque_Vectoring_Controller__M =
  &Torque_Vectoring_Controller__M_;

/* Forward declaration for local functions */
static real_T Torque_Vectoring_Controller_sum(const real_T x[4]);
static void Torque_Vectoring_Contr_mldivide(const real_T A[16], real_T B[4]);
static void Torque_Vectoring_Co_Distributor(real_T settings_Fsens, real_T
  settings_Fxsens, const struct_NZF8CyDbFf22HYyIBv7HBG *b_car, real_T Mz, real_T
  Fdes, real_T Fxmax[4], real_T Fxmin[4], real_T Fx[4]);
static real_T Torque_Vectoring_Controll_xnrm2(int32_T n, const real_T x[12],
  int32_T ix0);
static void Torque_Vectoring_Control_xgeqp3(real_T A[12], real_T tau[2], int32_T
  jpvt[2]);
static void Torque_Vectoring_Contro_polyfit(const real_T x[6], const real_T y[6],
  real_T p[2]);

/*
 * Output and update for action system:
 *    '<S43>/Action: One'
 *    '<S44>/Action: One'
 *    '<S45>/Action: One'
 *    '<S46>/Action: One'
 *    '<S47>/Action: One'
 */
void Torque_Vectoring_Cont_ActionOne(real_T *rty_Out1,
  P_ActionOne_Torque_Vectoring__T *localP)
{
  /* SignalConversion: '<S98>/OutportBufferForOut1' incorporates:
   *  Constant: '<S98>/One'
   */
  *rty_Out1 = localP->One_Value;
}

/*
 * Output and update for action system:
 *    '<S43>/Action: u1'
 *    '<S44>/Action: u1'
 *    '<S45>/Action: u1'
 *    '<S46>/Action: u1'
 *    '<S47>/Action: u1'
 */
void Torque_Vectoring_Contr_Actionu1(real_T rtu_u1, real_T *rty_u2)
{
  /* Inport: '<S99>/u1' */
  *rty_u2 = rtu_u1;
}

/*
 * Output and update for action system:
 *    '<S108>/If Action Subsystem'
 *    '<S108>/If Action Subsystem2'
 *    '<S109>/If Action Subsystem'
 *    '<S109>/If Action Subsystem2'
 *    '<S110>/If Action Subsystem'
 *    '<S110>/If Action Subsystem2'
 *    '<S111>/If Action Subsystem'
 *    '<S111>/If Action Subsystem2'
 *    '<S112>/If Action Subsystem'
 *    '<S112>/If Action Subsystem2'
 *    ...
 */
void Torque_Vector_IfActionSubsystem(real_T *rty_Out1,
  P_IfActionSubsystem_Torque_Ve_T *localP)
{
  /* SignalConversion: '<S113>/OutportBufferForOut1' incorporates:
   *  Constant: '<S113>/0'
   */
  *rty_Out1 = localP->u_Value;
}

/*
 * Output and update for action system:
 *    '<S108>/If Action Subsystem1'
 *    '<S109>/If Action Subsystem1'
 *    '<S110>/If Action Subsystem1'
 *    '<S111>/If Action Subsystem1'
 *    '<S112>/If Action Subsystem1'
 *    '<S133>/If Action Subsystem1'
 *    '<S134>/If Action Subsystem1'
 *    '<S135>/If Action Subsystem1'
 *    '<S136>/If Action Subsystem1'
 *    '<S137>/If Action Subsystem1'
 *    ...
 */
void Torque_Vecto_IfActionSubsystem1(real_T rtu_x, real_T *rty_Out1,
  B_IfActionSubsystem1_Torque_V_T *localB, real_T rtp_a, real_T rtp_b)
{
  /* Sum: '<S114>/Sum' incorporates:
   *  Constant: '<S114>/a'
   */
  localB->xa = rtu_x - rtp_a;

  /* Sum: '<S114>/Sum1' incorporates:
   *  Constant: '<S114>/a'
   *  Constant: '<S114>/b'
   */
  localB->ba = rtp_b - rtp_a;

  /* Product: '<S114>/Product ab (trimf)' */
  *rty_Out1 = localB->xa / localB->ba;
}

/*
 * Output and update for action system:
 *    '<S108>/If Action Subsystem3'
 *    '<S109>/If Action Subsystem3'
 *    '<S110>/If Action Subsystem3'
 *    '<S111>/If Action Subsystem3'
 *    '<S112>/If Action Subsystem3'
 *    '<S133>/If Action Subsystem3'
 *    '<S134>/If Action Subsystem3'
 *    '<S135>/If Action Subsystem3'
 *    '<S136>/If Action Subsystem3'
 *    '<S137>/If Action Subsystem3'
 *    ...
 */
void Torque_Vecto_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  B_IfActionSubsystem3_Torque_V_T *localB, real_T rtp_c, real_T rtp_d)
{
  /* Sum: '<S116>/Sum2' incorporates:
   *  Constant: '<S116>/c'
   *  Constant: '<S116>/d'
   */
  localB->dc = rtp_d - rtp_c;

  /* Sum: '<S116>/Sum3' incorporates:
   *  Constant: '<S116>/d'
   */
  localB->dx = rtp_d - rtu_x;

  /* Product: '<S116>/Product cd (trimf)' */
  *rty_Out1 = 1.0 / localB->dc * localB->dx;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T Torque_Vectoring_Controller_sum(const real_T x[4])
{
  real_T y;
  y = x[0];
  y += x[1];
  y += x[2];
  y += x[3];
  return y;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void Torque_Vectoring_Contr_mldivide(const real_T A[16], real_T B[4])
{
  real_T temp;
  real_T b_A[16];
  int8_T ipiv[4];
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T k;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T b_kAcol;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    b_kAcol = j * 5;
    iy = 0;
    ix = b_kAcol;
    temp = fabs(b_A[b_kAcol]);
    for (k = 2; k <= 4 - j; k++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > temp) {
        iy = k - 1;
        temp = s;
      }
    }

    if (b_A[b_kAcol + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (int8_T)((j + iy) + 1);
        ix = j;
        iy += j;
        temp = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = temp;
        ix += 4;
        iy += 4;
        temp = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = temp;
        ix += 4;
        iy += 4;
        temp = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = temp;
        ix += 4;
        iy += 4;
        temp = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = temp;
      }

      iy = (b_kAcol - j) + 4;
      for (ix = b_kAcol + 1; ix + 1 <= iy; ix++) {
        b_A[ix] /= b_A[b_kAcol];
      }
    }

    iy = b_kAcol + 5;
    ix = b_kAcol + 4;
    for (k = 1; k <= 3 - j; k++) {
      temp = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = b_kAcol + 1;
        d = (iy - j) + 3;
        for (ijA = iy; ijA + 1 <= d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -temp;
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  if (ipiv[0] != 1) {
    temp = B[0];
    B[0] = B[ipiv[0] - 1];
    B[ipiv[0] - 1] = temp;
  }

  if (ipiv[1] != 2) {
    temp = B[1];
    B[1] = B[ipiv[1] - 1];
    B[ipiv[1] - 1] = temp;
  }

  if (ipiv[2] != 3) {
    temp = B[2];
    B[2] = B[ipiv[2] - 1];
    B[ipiv[2] - 1] = temp;
  }

  if (B[0] != 0.0) {
    for (iy = 1; iy + 1 < 5; iy++) {
      B[iy] -= B[0] * b_A[iy];
    }
  }

  if (B[1] != 0.0) {
    for (iy = 2; iy + 1 < 5; iy++) {
      B[iy] -= b_A[iy + 4] * B[1];
    }
  }

  if (B[2] != 0.0) {
    for (iy = 3; iy + 1 < 5; iy++) {
      B[iy] -= b_A[iy + 8] * B[2];
    }
  }

  if (B[3] != 0.0) {
    B[3] /= b_A[15];
    for (iy = 0; iy + 1 < 4; iy++) {
      B[iy] -= b_A[iy + 12] * B[3];
    }
  }

  if (B[2] != 0.0) {
    B[2] /= b_A[10];
    for (iy = 0; iy + 1 < 3; iy++) {
      B[iy] -= b_A[iy + 8] * B[2];
    }
  }

  if (B[1] != 0.0) {
    B[1] /= b_A[5];
    for (iy = 0; iy + 1 < 2; iy++) {
      B[iy] -= b_A[iy + 4] * B[1];
    }
  }

  if (B[0] != 0.0) {
    B[0] /= b_A[0];
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void Torque_Vectoring_Co_Distributor(real_T settings_Fsens, real_T
  settings_Fxsens, const struct_NZF8CyDbFf22HYyIBv7HBG *b_car, real_T Mz, real_T
  Fdes, real_T Fxmax[4], real_T Fxmin[4], real_T Fx[4])
{
  real_T A2[4];
  int32_T Fxcheckmax1;
  int32_T Fxcheckmin1;
  real_T diffAray[4];
  real_T moment;
  real_T DiffsumFxFdes;
  real_T fracDiff;
  real_T distrRLRR;
  boolean_T x[4];
  int32_T c_ixstart;
  int32_T e_ix;
  boolean_T exitg5;
  boolean_T guard1;
  real_T b_car_0[4];
  real_T tmp[16];
  real_T tmp_0[16];
  int8_T maxsurpass_data[4];
  int8_T ii_data[4];
  real_T b_x_idx_3;

  /* VERSION: testDistributor_170118 */
  /* DISTRIBUTOR Solves the KKT conditions */
  /*    Based on sensitivity paramterers, KKT conditions */
  /*    are worked out to find an optimal balance between */
  /*    the desired Fx and the desired Mz */
  /*    Mz = desired yaw moment [1x1] */
  /*    Fdes = desired traction force [1x1] */
  /*    Fxmax = available grip per wheel [4x1] */
  /*    Fxmin = available neg grip per wheel [4x1] */
  /*    TODO: variables or settings? */
  /* TO DO */
  /* Rekening houden met situaties waarbij 3 waarden de maxima overstijgen */
  /* dit gebeurt enkel indien 3 van de maxima extreem laag zijn. */
  /* Ervoor zorgen dat indien op het einde van de berekeningen het moment */
  /* groter is dan het gewenste moment dat er een veiligheid in werking treed */
  /* om dit tegen te gaan. */
  /* value between 0 and 100 */
  /*  100 --> Fdes is really important */
  /*  0 --> Mdes is really important */
  /* value between 0 and 100 */
  /* Avoid dividing by 0 */
  moment = Fxmin[0];
  DiffsumFxFdes = Fxmax[0];
  if (DiffsumFxFdes == 0.0) {
    DiffsumFxFdes = 1.0;
  }

  if (moment == 0.0) {
    moment = -1.0;
  }

  Fxmax[0] = DiffsumFxFdes;
  Fxmin[0] = moment;
  moment = Fxmin[1];
  DiffsumFxFdes = Fxmax[1];
  if (DiffsumFxFdes == 0.0) {
    DiffsumFxFdes = 1.0;
  }

  if (moment == 0.0) {
    moment = -1.0;
  }

  Fxmax[1] = DiffsumFxFdes;
  Fxmin[1] = moment;
  moment = Fxmin[2];
  DiffsumFxFdes = Fxmax[2];
  if (DiffsumFxFdes == 0.0) {
    DiffsumFxFdes = 1.0;
  }

  if (moment == 0.0) {
    moment = -1.0;
  }

  Fxmax[2] = DiffsumFxFdes;
  Fxmin[2] = moment;
  moment = Fxmin[3];
  DiffsumFxFdes = Fxmax[3];
  if (DiffsumFxFdes == 0.0) {
    DiffsumFxFdes = 1.0;
  }

  if (moment == 0.0) {
    moment = -1.0;
  }

  Fxmax[3] = DiffsumFxFdes;
  Fxmin[3] = moment;
  if (Fdes > Torque_Vectoring_Controller_sum(Fxmax)) {
    Fdes = Torque_Vectoring_Controller_sum(Fxmax);
  } else {
    if (Fdes < Torque_Vectoring_Controller_sum(Fxmin)) {
      Fdes = Torque_Vectoring_Controller_sum(Fxmin);
    }
  }

  A2[0] = -b_car->tw / 2.0;
  A2[1] = b_car->tw / 2.0;
  A2[2] = -b_car->tw / 2.0;
  A2[3] = b_car->tw / 2.0;
  moment = settings_Fxsens / 100.0;
  tmp_0[0] = 1.0 / Fxmax[0];
  tmp_0[4] = 0.0;
  tmp_0[8] = 0.0;
  tmp_0[12] = 0.0;
  tmp_0[1] = 0.0;
  tmp_0[5] = 1.0 / Fxmax[1];
  tmp_0[9] = 0.0;
  tmp_0[13] = 0.0;
  tmp_0[2] = 0.0;
  tmp_0[6] = 0.0;
  tmp_0[10] = 1.0 / Fxmax[2];
  tmp_0[14] = 0.0;
  tmp_0[3] = 0.0;
  tmp_0[7] = 0.0;
  tmp_0[11] = 0.0;
  tmp_0[15] = 1.0 / Fxmax[3];
  for (c_ixstart = 0; c_ixstart < 4; c_ixstart++) {
    Fx[c_ixstart] = A2[c_ixstart] * Mz + Fdes;
    DiffsumFxFdes = A2[c_ixstart] * A2[0];
    tmp[c_ixstart] = (1.0 + DiffsumFxFdes) + tmp_0[c_ixstart] * moment;
    DiffsumFxFdes = A2[c_ixstart] * A2[1];
    tmp[c_ixstart + 4] = tmp_0[c_ixstart + 4] * moment + (1.0 + DiffsumFxFdes);
    DiffsumFxFdes = A2[c_ixstart] * A2[2];
    tmp[c_ixstart + 8] = tmp_0[c_ixstart + 8] * moment + (1.0 + DiffsumFxFdes);
    DiffsumFxFdes = A2[c_ixstart] * A2[3];
    tmp[c_ixstart + 12] = tmp_0[c_ixstart + 12] * moment + (1.0 + DiffsumFxFdes);
  }

  Torque_Vectoring_Contr_mldivide(tmp, Fx);
  Fxcheckmax1 = 0;
  Fxcheckmin1 = 0;
  if (Fx[0] > Fxmax[0]) {
    Fxcheckmax1 = 1;
  } else {
    if (Fx[0] < Fxmin[0]) {
      Fxcheckmin1 = 1;
    }
  }

  if (Fx[1] > Fxmax[1]) {
    Fxcheckmax1 = 1;
  } else {
    if (Fx[1] < Fxmin[1]) {
      Fxcheckmin1 = 1;
    }
  }

  if (Fx[2] > Fxmax[2]) {
    Fxcheckmax1 = 1;
  } else {
    if (Fx[2] < Fxmin[2]) {
      Fxcheckmin1 = 1;
    }
  }

  if (Fx[3] > Fxmax[3]) {
    Fxcheckmax1 = 1;
  } else {
    if (Fx[3] < Fxmin[3]) {
      Fxcheckmin1 = 1;
    }
  }

  if ((Fxcheckmax1 == 1) || (Fxcheckmin1 == 1)) {
    /* Check if one value of Former Fx surpasses the maximum value */
    /* Mdes = Mz*(Msens/MsensMax); */
    if (Fxcheckmax1 == 1) {
      /* positive value if Fx > Fxmax */
      moment = Fx[0] - Fxmax[0];
      moment *= (real_T)(moment > 0.0);
      diffAray[0] = moment;
      moment = Fx[1] - Fxmax[1];
      moment *= (real_T)(moment > 0.0);
      diffAray[1] = moment;
      moment = Fx[2] - Fxmax[2];
      moment *= (real_T)(moment > 0.0);
      diffAray[2] = moment;
      moment = Fx[3] - Fxmax[3];
      moment *= (real_T)(moment > 0.0);
      diffAray[3] = moment;

      /* Filter values bigger than Fxmax */
      Fxcheckmin1 = 1;
      moment = diffAray[0];
      Fxcheckmax1 = -5;
      if (rtIsNaN(diffAray[0])) {
        c_ixstart = 1;
        exitg5 = false;
        while ((!exitg5) && (c_ixstart + 1 < 5)) {
          Fxcheckmin1 = c_ixstart + 1;
          if (!rtIsNaN(diffAray[c_ixstart])) {
            moment = diffAray[c_ixstart];
            Fxcheckmax1 = c_ixstart - 5;
            exitg5 = true;
          } else {
            c_ixstart++;
          }
        }
      }

      if (Fxcheckmin1 < 4) {
        while (Fxcheckmin1 + 1 < 5) {
          if (diffAray[Fxcheckmin1] > moment) {
            moment = diffAray[Fxcheckmin1];
            Fxcheckmax1 = Fxcheckmin1 - 5;
          }

          Fxcheckmin1++;
        }
      }

      Fxcheckmin1 = 1;
      moment = diffAray[0];
      if (rtIsNaN(diffAray[0])) {
        c_ixstart = 2;
        exitg5 = false;
        while ((!exitg5) && (c_ixstart < 5)) {
          Fxcheckmin1 = c_ixstart;
          if (!rtIsNaN(diffAray[c_ixstart - 1])) {
            moment = diffAray[c_ixstart - 1];
            exitg5 = true;
          } else {
            c_ixstart++;
          }
        }
      }

      if (Fxcheckmin1 < 4) {
        while (Fxcheckmin1 + 1 < 5) {
          if (diffAray[Fxcheckmin1] > moment) {
            moment = diffAray[Fxcheckmin1];
          }

          Fxcheckmin1++;
        }
      }

      DiffsumFxFdes = Fx[0];
      DiffsumFxFdes -= moment;
      x[0] = (DiffsumFxFdes < Fxmin[0]);
      Fx[0] = DiffsumFxFdes;
      DiffsumFxFdes = Fx[1];
      DiffsumFxFdes -= moment;
      x[1] = (DiffsumFxFdes < Fxmin[1]);
      Fx[1] = DiffsumFxFdes;
      DiffsumFxFdes = Fx[2];
      DiffsumFxFdes -= moment;
      x[2] = (DiffsumFxFdes < Fxmin[2]);
      Fx[2] = DiffsumFxFdes;
      DiffsumFxFdes = Fx[3];
      DiffsumFxFdes -= moment;
      x[3] = (DiffsumFxFdes < Fxmin[3]);
      Fx[3] = DiffsumFxFdes;
      Fxcheckmin1 = 0;
      c_ixstart = 1;
      exitg5 = false;
      while ((!exitg5) && (c_ixstart < 5)) {
        guard1 = false;
        if (x[c_ixstart - 1]) {
          Fxcheckmin1++;
          ii_data[Fxcheckmin1 - 1] = (int8_T)c_ixstart;
          if (Fxcheckmin1 >= 4) {
            exitg5 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          c_ixstart++;
        }
      }

      if (1 > Fxcheckmin1) {
        Fxcheckmin1 = 0;
      }

      for (c_ixstart = 0; c_ixstart < Fxcheckmin1; c_ixstart++) {
        maxsurpass_data[c_ixstart] = ii_data[c_ixstart];
      }

      for (c_ixstart = 0; c_ixstart < Fxcheckmin1; c_ixstart++) {
        Fx[maxsurpass_data[c_ixstart] - 1] = Fxmin[maxsurpass_data[c_ixstart] -
          1];
      }

      diffAray[0] = Fxmax[0] - Fx[0];
      diffAray[1] = Fxmax[1] - Fx[1];
      diffAray[2] = Fxmax[2] - Fx[2];
      diffAray[3] = Fxmax[3] - Fx[3];

      /* moment = sum([-car.tw/2; car.tw/2; -car.tw/2; car.tw/2].*Fx); */
      if ((Fxcheckmax1 + 6 == 3) || (Fxcheckmax1 + 6 == 4)) {
        Fxcheckmin1 = 1;
        moment = diffAray[0];
        c_ixstart = -5;
        if (rtIsNaN(diffAray[0])) {
          e_ix = 2;
          exitg5 = false;
          while ((!exitg5) && (e_ix < 3)) {
            Fxcheckmin1 = 2;
            if (!rtIsNaN(diffAray[1])) {
              moment = diffAray[1];
              c_ixstart = -4;
              exitg5 = true;
            } else {
              e_ix = 3;
            }
          }
        }

        if ((Fxcheckmin1 < 2) && (diffAray[1] < moment)) {
          moment = diffAray[1];
          c_ixstart = -4;
        }

        Fxcheckmin1 = c_ixstart;
        DiffsumFxFdes = Fx[0];
        DiffsumFxFdes += moment;
        Fx[0] = DiffsumFxFdes;
        DiffsumFxFdes = Fx[1];
        DiffsumFxFdes += moment;
        Fx[1] = DiffsumFxFdes;
      } else {
        c_ixstart = 1;
        moment = diffAray[2];
        Fxcheckmin1 = -3;
        if (rtIsNaN(diffAray[2])) {
          e_ix = 2;
          exitg5 = false;
          while ((!exitg5) && (e_ix < 3)) {
            c_ixstart = 2;
            if (!rtIsNaN(diffAray[3])) {
              moment = diffAray[3];
              Fxcheckmin1 = -2;
              exitg5 = true;
            } else {
              e_ix = 3;
            }
          }
        }

        if ((c_ixstart < 2) && (diffAray[3] < moment)) {
          moment = diffAray[3];
          Fxcheckmin1 = -2;
        }

        Fx[2] += moment;
        Fx[3] += moment;
      }

      moment = -b_car->tw / 2.0;
      DiffsumFxFdes = b_car->tw / 2.0;
      fracDiff = -b_car->tw / 2.0;
      distrRLRR = b_car->tw / 2.0;
      diffAray[0] = Fxmax[0] - Fx[0];
      b_car_0[0] = moment * Fx[0];
      diffAray[1] = Fxmax[1] - Fx[1];
      b_car_0[1] = DiffsumFxFdes * Fx[1];
      diffAray[2] = Fxmax[2] - Fx[2];
      b_car_0[2] = fracDiff * Fx[2];
      diffAray[3] = Fxmax[3] - Fx[3];
      b_car_0[3] = distrRLRR * Fx[3];
      moment = Torque_Vectoring_Controller_sum(b_car_0);
      DiffsumFxFdes = Fdes - Torque_Vectoring_Controller_sum(Fx);
      if (Fxcheckmax1 + 6 > 2) {
        if (diffAray[-Fxcheckmax1] == 0.0) {
          diffAray[-Fxcheckmax1] = 0.1;
        }

        fracDiff = diffAray[-4 - Fxcheckmin1] / diffAray[-Fxcheckmax1];
        distrRLRR = -moment / (A2[-4 - Fxcheckmin1] * fracDiff + A2[-Fxcheckmax1]);
        moment = (-moment - distrRLRR * A2[-Fxcheckmax1]) / A2[-4 - Fxcheckmin1];
        if (distrRLRR + moment > 0.0) {
          if (moment + distrRLRR > DiffsumFxFdes) {
            moment = DiffsumFxFdes / (1.0 + fracDiff);
            distrRLRR = moment * fracDiff;
          }

          Fx[-4 - Fxcheckmin1] += settings_Fsens / 100.0 * moment;
          Fx[-Fxcheckmax1] += settings_Fsens / 100.0 * distrRLRR;
        }
      } else {
        if (diffAray[-Fxcheckmin1] == 0.0) {
          diffAray[-Fxcheckmin1] = 0.1;
        }

        fracDiff = diffAray[-4 - Fxcheckmax1] / diffAray[-Fxcheckmin1];
        distrRLRR = -moment / (A2[-4 - Fxcheckmax1] * fracDiff + A2[-Fxcheckmin1]);
        moment = (-moment - distrRLRR * A2[-Fxcheckmin1]) / A2[-4 - Fxcheckmax1];
        if (distrRLRR + moment > 0.0) {
          if (moment + distrRLRR > DiffsumFxFdes) {
            moment = DiffsumFxFdes / (1.0 + fracDiff);
            distrRLRR = moment * fracDiff;
          }

          Fx[-Fxcheckmin1] += settings_Fsens / 100.0 * moment;
          Fx[-4 - Fxcheckmax1] += settings_Fsens / 100.0 * distrRLRR;
        }
      }

      /* ------------------------------------------------------------------------- */
    } else {
      /* negative value if Fx < Fxmin */
      moment = Fx[0] - Fxmin[0];
      moment *= (real_T)(moment < 0.0);
      diffAray[0] = moment;
      moment = Fx[1] - Fxmin[1];
      moment *= (real_T)(moment < 0.0);
      diffAray[1] = moment;
      moment = Fx[2] - Fxmin[2];
      moment *= (real_T)(moment < 0.0);
      diffAray[2] = moment;
      moment = Fx[3] - Fxmin[3];
      moment *= (real_T)(moment < 0.0);
      diffAray[3] = moment;

      /* Filter values smaller than Fxmin */
      Fxcheckmin1 = 1;
      moment = diffAray[0];
      Fxcheckmax1 = -5;
      if (rtIsNaN(diffAray[0])) {
        c_ixstart = 1;
        exitg5 = false;
        while ((!exitg5) && (c_ixstart + 1 < 5)) {
          Fxcheckmin1 = c_ixstart + 1;
          if (!rtIsNaN(diffAray[c_ixstart])) {
            moment = diffAray[c_ixstart];
            Fxcheckmax1 = c_ixstart - 5;
            exitg5 = true;
          } else {
            c_ixstart++;
          }
        }
      }

      if (Fxcheckmin1 < 4) {
        while (Fxcheckmin1 + 1 < 5) {
          if (diffAray[Fxcheckmin1] < moment) {
            moment = diffAray[Fxcheckmin1];
            Fxcheckmax1 = Fxcheckmin1 - 5;
          }

          Fxcheckmin1++;
        }
      }

      /* [diffValue2,pos2]= max(diffAray.*(diffAray<max(diffAray))); */
      /* nonZero=length(find(diffAray)); */
      Fxcheckmin1 = 1;
      moment = diffAray[0];
      if (rtIsNaN(diffAray[0])) {
        c_ixstart = 2;
        exitg5 = false;
        while ((!exitg5) && (c_ixstart < 5)) {
          Fxcheckmin1 = c_ixstart;
          if (!rtIsNaN(diffAray[c_ixstart - 1])) {
            moment = diffAray[c_ixstart - 1];
            exitg5 = true;
          } else {
            c_ixstart++;
          }
        }
      }

      if (Fxcheckmin1 < 4) {
        while (Fxcheckmin1 + 1 < 5) {
          if (diffAray[Fxcheckmin1] < moment) {
            moment = diffAray[Fxcheckmin1];
          }

          Fxcheckmin1++;
        }
      }

      DiffsumFxFdes = Fx[0];
      DiffsumFxFdes -= moment;
      x[0] = (DiffsumFxFdes > Fxmax[0]);
      Fx[0] = DiffsumFxFdes;
      DiffsumFxFdes = Fx[1];
      DiffsumFxFdes -= moment;
      x[1] = (DiffsumFxFdes > Fxmax[1]);
      Fx[1] = DiffsumFxFdes;
      DiffsumFxFdes = Fx[2];
      DiffsumFxFdes -= moment;
      x[2] = (DiffsumFxFdes > Fxmax[2]);
      Fx[2] = DiffsumFxFdes;
      DiffsumFxFdes = Fx[3];
      DiffsumFxFdes -= moment;
      x[3] = (DiffsumFxFdes > Fxmax[3]);
      Fx[3] = DiffsumFxFdes;
      Fxcheckmin1 = 0;
      c_ixstart = 1;
      exitg5 = false;
      while ((!exitg5) && (c_ixstart < 5)) {
        guard1 = false;
        if (x[c_ixstart - 1]) {
          Fxcheckmin1++;
          ii_data[Fxcheckmin1 - 1] = (int8_T)c_ixstart;
          if (Fxcheckmin1 >= 4) {
            exitg5 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          c_ixstart++;
        }
      }

      if (1 > Fxcheckmin1) {
        Fxcheckmin1 = 0;
      }

      for (c_ixstart = 0; c_ixstart < Fxcheckmin1; c_ixstart++) {
        maxsurpass_data[c_ixstart] = ii_data[c_ixstart];
      }

      for (c_ixstart = 0; c_ixstart < Fxcheckmin1; c_ixstart++) {
        Fx[maxsurpass_data[c_ixstart] - 1] = Fxmax[maxsurpass_data[c_ixstart] -
          1];
      }

      diffAray[0] = Fxmin[0] - Fx[0];
      diffAray[1] = Fxmin[1] - Fx[1];
      diffAray[2] = Fxmin[2] - Fx[2];
      diffAray[3] = Fxmin[3] - Fx[3];
      if ((Fxcheckmax1 + 6 == 3) || (Fxcheckmax1 + 6 == 4)) {
        Fxcheckmin1 = 1;
        moment = diffAray[0];
        c_ixstart = -5;
        if (rtIsNaN(diffAray[0])) {
          e_ix = 2;
          exitg5 = false;
          while ((!exitg5) && (e_ix < 3)) {
            Fxcheckmin1 = 2;
            if (!rtIsNaN(diffAray[1])) {
              moment = diffAray[1];
              c_ixstart = -4;
              exitg5 = true;
            } else {
              e_ix = 3;
            }
          }
        }

        if ((Fxcheckmin1 < 2) && (diffAray[1] > moment)) {
          moment = diffAray[1];
          c_ixstart = -4;
        }

        Fxcheckmin1 = c_ixstart;
        DiffsumFxFdes = Fx[0];
        DiffsumFxFdes += moment;
        Fx[0] = DiffsumFxFdes;
        DiffsumFxFdes = Fx[1];
        DiffsumFxFdes += moment;
        Fx[1] = DiffsumFxFdes;
      } else {
        c_ixstart = 1;
        moment = diffAray[2];
        Fxcheckmin1 = -3;
        if (rtIsNaN(diffAray[2])) {
          e_ix = 2;
          exitg5 = false;
          while ((!exitg5) && (e_ix < 3)) {
            c_ixstart = 2;
            if (!rtIsNaN(diffAray[3])) {
              moment = diffAray[3];
              Fxcheckmin1 = -2;
              exitg5 = true;
            } else {
              e_ix = 3;
            }
          }
        }

        if ((c_ixstart < 2) && (diffAray[3] > moment)) {
          moment = diffAray[3];
          Fxcheckmin1 = -2;
        }

        Fx[2] += moment;
        Fx[3] += moment;
      }

      diffAray[0] = Fxmin[0] - Fx[0];
      diffAray[1] = Fxmin[1] - Fx[1];
      diffAray[2] = Fxmin[2] - Fx[2];
      diffAray[3] = Fxmin[3] - Fx[3];
      moment = -b_car->tw / 2.0 * Fx[0];
      fracDiff = b_car->tw / 2.0 * Fx[1];
      distrRLRR = -b_car->tw / 2.0 * Fx[2];
      b_x_idx_3 = b_car->tw / 2.0 * Fx[3];
      DiffsumFxFdes = Fx[0];
      moment += fracDiff;
      DiffsumFxFdes += Fx[1];
      moment += distrRLRR;
      DiffsumFxFdes += Fx[2];
      moment += b_x_idx_3;
      DiffsumFxFdes += Fx[3];
      DiffsumFxFdes = Fdes - DiffsumFxFdes;
      if (Fxcheckmax1 + 6 > 2) {
        /*          diffFLFR = Fx(posMinDiff)-Fx(3-posMinDiff) */
        /*          diffRLRR = Fx(pos1)-Fx(7-pos1) */
        /*          Fx(3-posMinDiff)=Fx(3-posMinDiff)+diffFLFR*(Fsens/FsensMax); */
        /*          Fx(7-pos1)=Fx(7-pos1)+diffRLRR*(Fsens/FsensMax); */
        if (diffAray[-Fxcheckmax1] == 0.0) {
          diffAray[-Fxcheckmax1] = -0.1;
        }

        fracDiff = diffAray[-4 - Fxcheckmin1] / diffAray[-Fxcheckmax1];
        distrRLRR = -moment / (A2[-4 - Fxcheckmin1] * fracDiff + A2[-Fxcheckmax1]);
        moment = (-moment - distrRLRR * A2[-Fxcheckmax1]) / A2[-4 - Fxcheckmin1];
        if (distrRLRR + moment < 0.0) {
          if (moment + distrRLRR < DiffsumFxFdes) {
            moment = DiffsumFxFdes / (1.0 + fracDiff);
            distrRLRR = moment * fracDiff;
          }

          Fx[-4 - Fxcheckmin1] += settings_Fsens / 100.0 * moment;
          Fx[-Fxcheckmax1] += settings_Fsens / 100.0 * distrRLRR;
        }
      } else {
        if (diffAray[-Fxcheckmin1] == 0.0) {
          diffAray[-Fxcheckmin1] = -0.1;
        }

        fracDiff = diffAray[-4 - Fxcheckmax1] / diffAray[-Fxcheckmin1];
        distrRLRR = -moment / (A2[-4 - Fxcheckmax1] * fracDiff + A2[-Fxcheckmin1]);
        moment = (-moment - distrRLRR * A2[-Fxcheckmin1]) / A2[-4 - Fxcheckmax1];
        if (distrRLRR + moment < 0.0) {
          if (moment + distrRLRR < DiffsumFxFdes) {
            moment = DiffsumFxFdes / (1.0 + fracDiff);
            distrRLRR = moment * fracDiff;
          }

          Fx[-Fxcheckmin1] += settings_Fsens / 100.0 * moment;
          Fx[-4 - Fxcheckmax1] += settings_Fsens / 100.0 * distrRLRR;
        }
      }
    }
  }

  DiffsumFxFdes = Fx[0];
  DiffsumFxFdes /= b_car->gearRatio;
  Fx[0] = DiffsumFxFdes;
  DiffsumFxFdes = Fx[1];
  DiffsumFxFdes /= b_car->gearRatio;
  Fx[1] = DiffsumFxFdes;
  DiffsumFxFdes = Fx[2];
  DiffsumFxFdes /= b_car->gearRatio;
  Fx[2] = DiffsumFxFdes;
  DiffsumFxFdes = Fx[3];
  DiffsumFxFdes /= b_car->gearRatio;
  Fx[3] = DiffsumFxFdes;

  /*  tolerance = 1; */
  /*   */
  /*  maxvaluecheck =  Fxmin - tolerance <Fx & Fx<Fxmax + tolerance; */
  /*  A = find(maxvaluecheck==0); */
  /*  FxminA=0; */
  /*   */
  /*  if isempty(A) == 0 */
  /*      A1=A(1); */
  /*      if Fdes > 0 */
  /*          if Fx(A1) > Fxmax(A1) */
  /*              diff=Fx(A1)-Fxmax(A1); */
  /*              Fx(A1)=Fxmax(A1); */
  /*              if A1 == 3 || A1 == 4 */
  /*                  if (Fxmax(A1-2) - Fx(A1-2))>=diff; */
  /*                      Fx(A1-2)=Fx(A1-2)+diff; */
  /*                  else */
  /*                      diff2=Fxmax(A1-2)-Fx(A1-2); */
  /*                      Fx(A1-2)=Fxmax(A1-2); */
  /*                      Fx(7-A1)=Fx(7-A1)-(diff-diff2); */
  /*                      %Fx(7-A1)=Fx(7-A1)-(diff-diff2)/2; */
  /*                      %Fx(5-A1)=Fx(5-A1)-(diff-diff2)/2; */
  /*                  end */
  /*              else */
  /*                  if (Fxmax(A1+2) - Fx(A1+2))>=diff */
  /*                      Fx(A1+2)=Fx(A1+2)+diff; */
  /*                  else */
  /*                      diff2=Fxmax(A1+2)-Fx(A1+2); */
  /*                      Fx(A1+2)=Fxmax(A1+2); */
  /*                      Fx(3-A1)=Fx(3-A1)-(diff-diff2); */
  /*                      %Fx(3-A1)=Fx(3-A1)-(diff-diff2)/2; */
  /*                      %Fx(5-A1)=Fx(5-A1)-(diff-diff2)/2; */
  /*                  end */
  /*              end */
  /*          else %Fx(A1) < Fxmin(A1) */
  /*              diff=Fxmin(A1)-Fx(A1); %positive value */
  /*              Fx(A1)=FxminA(A1); */
  /*              if A1 == 1 || A1 == 2 */
  /*                  if Fx(A1+2) < 0 */
  /*                      diff2=Fx(A1+2)-Fxmin(A1+2); %positive value */
  /*                      if diff2>diff */
  /*                          Fx(A1+2)=Fx(A1+2)-diff; */
  /*                      else */
  /*                          Fx(A1+2)=Fxmin(A1+2); */
  /*                      end */
  /*                  else %Fx(A1+2) > 0 */
  /*                      Fx(A1+2) = Fx(A1+2)-diff; */
  /*                  end */
  /*              else */
  /*                  if Fx(A1-2) < 0 */
  /*                      diff2=Fx(A1-2)-Fxmin(A1-2); %positive value */
  /*                      if diff2>diff */
  /*                          Fx(A1-2)=Fx(A1-2)-diff; */
  /*                      else */
  /*                          Fx(A1-2)=Fxmin(A1-2); */
  /*                      end */
  /*                  else %Fx(A1-2) > 0 */
  /*                      Fx(A1-2) = Fx(A1-2)-diff; */
  /*                  end */
  /*              end */
  /*          end */
  /*           */
  /*      else %if Fdes <= 0 */
  /*          if Fx(A1) < Fxmin(A1) */
  /*              diff=Fxmin(A1)-Fx(A1); %postive value */
  /*              Fx(A1)=Fxmin(A1); */
  /*              if A1 == 3 || A1 == 4 */
  /*                  if (Fx(A1-2) - Fxmin(A1-2))>=diff */
  /*                      Fx(A1-2)=Fx(A1-2)-diff; */
  /*                  else */
  /*                      diff2=Fx(A1-2)-Fxmin(A1-2); */
  /*                      Fx(A1-2)=Fxmin(A1-2); */
  /*                      Fx(7-A1)=Fx(7-A1)+(diff-diff2); */
  /*                      %Fx(7-A1)=Fx(7-A1)+(diff-diff2)/2; */
  /*                      %Fx(5-A1)=Fx(5-A1)+(diff-diff2)/2; */
  /*                  end */
  /*              else %A1 == 1 | A1 == 2 */
  /*                  if (Fx(A1+2)-Fxmin(A1+2))>=diff */
  /*                      Fx(A1+2)=Fx(A1+2)-diff; */
  /*                  else */
  /*                      diff2=Fx(A1+2)-Fxmin(A1+2); */
  /*                      Fx(A1+2)=Fxmin(A1+2); */
  /*                      Fx(3-A1)=Fx(3-A1)+(diff-diff2); */
  /*                      %Fx(3-A1)=Fx(3-A1)+(diff-diff2)/2; */
  /*                      %Fx(5-A1)=Fx(5-A1)+(diff-diff2)/2; */
  /*                  end */
  /*              end */
  /*          else %Fx(A1) > Fxmax(A1) */
  /*              diff=Fx(A1)-Fxmax(A1); %positive value */
  /*              Fx(A1)=Fxmax(A1); */
  /*              if A1 == 1 || A1 == 2 */
  /*                  if Fx(A1+2) > 0 */
  /*                      diff2=Fxmax(A1+2)-Fx(A1+2); %positive value */
  /*                      if diff2>diff */
  /*                          Fx(A1+2)=Fx(A1+2)+diff; */
  /*                      else */
  /*                          Fx(A1+2)=Fxmax(A1+2); */
  /*                      end */
  /*                  else %Fx(A1+2) < 0 */
  /*                      Fx(A1+2) = Fx(A1+2)+diff; */
  /*                  end */
  /*              else %A1 == 3 | A1 == 4 */
  /*                  if Fx(A1-2) > 0 */
  /*                      diff2=Fxmax(A1-2)-Fx(A1-2); %positive value */
  /*                      if diff2>diff */
  /*                          Fx(A1-2)=Fx(A1-2)-diff; */
  /*                      else */
  /*                          Fx(A1-2)=Fxmax(A1-2); */
  /*                      end */
  /*                  else %Fx(A1-2) > 0 */
  /*                      Fx(A1-2) = Fx(A1-2)+diff; */
  /*                  end */
  /*              end */
  /*          end */
  /*      end  */
  /*  end */
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S5>/Traction Control' */
static real_T Torque_Vectoring_Controll_xnrm2(int32_T n, const real_T x[12],
  int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S5>/Traction Control' */
static void Torque_Vectoring_Control_xgeqp3(real_T A[12], real_T tau[2], int32_T
  jpvt[2])
{
  real_T work[2];
  real_T vn1[2];
  real_T vn2[2];
  int32_T k;
  int32_T i_i;
  int32_T pvt;
  real_T b_atmp;
  int32_T ix;
  int32_T iy;
  real_T xnorm;
  real_T b_c;
  int32_T jy;
  int32_T c_ix;
  int32_T f;
  int32_T ijA;
  real_T t;
  boolean_T exitg2;
  jpvt[0] = 1;
  work[0] = 0.0;
  b_atmp = 0.0;
  b_c = 2.2250738585072014E-308;
  for (pvt = 1; pvt < 7; pvt++) {
    xnorm = fabs(A[pvt - 1]);
    if (xnorm > b_c) {
      t = b_c / xnorm;
      b_atmp = b_atmp * t * t + 1.0;
      b_c = xnorm;
    } else {
      t = xnorm / b_c;
      b_atmp += t * t;
    }
  }

  b_atmp = b_c * sqrt(b_atmp);
  vn1[0] = b_atmp;
  vn2[0] = vn1[0];
  jpvt[1] = 2;
  work[1] = 0.0;
  b_atmp = 0.0;
  b_c = 2.2250738585072014E-308;
  while (pvt <= 12) {
    xnorm = fabs(A[pvt - 1]);
    if (xnorm > b_c) {
      t = b_c / xnorm;
      b_atmp = b_atmp * t * t + 1.0;
      b_c = xnorm;
    } else {
      t = xnorm / b_c;
      b_atmp += t * t;
    }

    pvt++;
  }

  b_atmp = b_c * sqrt(b_atmp);
  vn1[1] = b_atmp;
  vn2[1] = vn1[1];
  for (k = 0; k < 2; k++) {
    i_i = k * 6 + k;
    pvt = 0;
    if ((2 - k > 1) && (vn1[1] > vn1[k])) {
      pvt = 1;
    }

    pvt += k;
    if (pvt + 1 != k + 1) {
      ix = 6 * pvt;
      iy = 6 * k;
      for (jy = 0; jy < 6; jy++) {
        b_atmp = A[ix];
        A[ix] = A[iy];
        A[iy] = b_atmp;
        ix++;
        iy++;
      }

      ix = jpvt[pvt];
      jpvt[pvt] = jpvt[k];
      jpvt[k] = ix;
      vn1[pvt] = vn1[k];
      vn2[pvt] = vn2[k];
    }

    b_atmp = A[i_i];
    b_c = 0.0;
    xnorm = Torque_Vectoring_Controll_xnrm2(5 - k, A, i_i + 2);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(A[i_i], xnorm);
      if (A[i_i] >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        pvt = 0;
        do {
          pvt++;
          ix = (i_i - k) + 6;
          for (iy = i_i + 1; iy + 1 <= ix; iy++) {
            A[iy] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          b_atmp *= 9.9792015476736E+291;
        } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

        xnorm = Torque_Vectoring_Controll_xnrm2(5 - k, A, i_i + 2);
        xnorm = rt_hypotd_snf(b_atmp, xnorm);
        if (b_atmp >= 0.0) {
          xnorm = -xnorm;
        }

        b_c = (xnorm - b_atmp) / xnorm;
        b_atmp = 1.0 / (b_atmp - xnorm);
        ix = (i_i - k) + 6;
        for (iy = i_i + 1; iy + 1 <= ix; iy++) {
          A[iy] *= b_atmp;
        }

        for (ix = 1; ix <= pvt; ix++) {
          xnorm *= 1.0020841800044864E-292;
        }

        b_atmp = xnorm;
      } else {
        b_c = (xnorm - A[i_i]) / xnorm;
        b_atmp = 1.0 / (A[i_i] - xnorm);
        pvt = (i_i - k) + 6;
        for (ix = i_i + 1; ix + 1 <= pvt; ix++) {
          A[ix] *= b_atmp;
        }

        b_atmp = xnorm;
      }
    }

    tau[k] = b_c;
    A[i_i] = b_atmp;
    if (k + 1 < 2) {
      b_atmp = A[i_i];
      A[i_i] = 1.0;
      if (tau[0] != 0.0) {
        pvt = 12;
        ix = i_i + 5;
        while ((pvt - 6 > 0) && (A[ix] == 0.0)) {
          pvt--;
          ix--;
        }

        ix = 1;
        exitg2 = false;
        while ((!exitg2) && (ix > 0)) {
          iy = 7;
          do {
            jy = 0;
            if (iy <= pvt) {
              if (A[iy - 1] != 0.0) {
                jy = 1;
              } else {
                iy++;
              }
            } else {
              ix = 0;
              jy = 2;
            }
          } while (jy == 0);

          if (jy == 1) {
            exitg2 = true;
          }
        }
      } else {
        pvt = 6;
        ix = 0;
      }

      if (pvt - 6 > 0) {
        if (ix != 0) {
          iy = i_i;
          b_c = 0.0;
          for (jy = 7; jy <= pvt; jy++) {
            b_c += A[jy - 1] * A[iy];
            iy++;
          }

          work[0] = b_c;
        }

        if (!(-tau[0] == 0.0)) {
          iy = 0;
          jy = 0;
          c_ix = 1;
          while (c_ix <= ix) {
            if (work[jy] != 0.0) {
              b_c = work[jy] * -tau[0];
              c_ix = i_i;
              f = pvt + iy;
              for (ijA = iy + 6; ijA + 1 <= f; ijA++) {
                A[ijA] += A[c_ix] * b_c;
                c_ix++;
              }
            }

            jy++;
            iy += 6;
            c_ix = 2;
          }
        }
      }

      A[i_i] = b_atmp;
    }

    i_i = k + 2;
    while (i_i < 3) {
      if (vn1[1] != 0.0) {
        b_atmp = fabs(A[6 + k]) / vn1[1];
        b_atmp = 1.0 - b_atmp * b_atmp;
        if (b_atmp < 0.0) {
          b_atmp = 0.0;
        }

        b_c = vn1[1] / vn2[1];
        b_c = b_c * b_c * b_atmp;
        if (b_c <= 1.4901161193847656E-8) {
          b_atmp = 0.0;
          b_c = 2.2250738585072014E-308;
          for (i_i = k + 7; i_i + 1 < 13; i_i++) {
            xnorm = fabs(A[i_i]);
            if (xnorm > b_c) {
              t = b_c / xnorm;
              b_atmp = b_atmp * t * t + 1.0;
              b_c = xnorm;
            } else {
              t = xnorm / b_c;
              b_atmp += t * t;
            }
          }

          b_atmp = b_c * sqrt(b_atmp);
          vn1[1] = b_atmp;
          vn2[1] = b_atmp;
        } else {
          vn1[1] *= sqrt(b_atmp);
        }
      }

      i_i = 3;
    }
  }
}

/* Function for MATLAB Function: '<S5>/Traction Control' */
static void Torque_Vectoring_Contro_polyfit(const real_T x[6], const real_T y[6],
  real_T p[2])
{
  real_T V[12];
  real_T p1[2];
  real_T tau[2];
  int32_T jpvt[2];
  real_T B[6];
  real_T wj;
  int32_T i;
  for (i = 0; i < 6; i++) {
    V[6 + i] = 1.0;
    V[i] = x[i];
  }

  Torque_Vectoring_Control_xgeqp3(V, tau, jpvt);
  p1[0] = 0.0;
  p1[1] = 0.0;
  for (i = 0; i < 6; i++) {
    B[i] = y[i];
  }

  if (tau[0] != 0.0) {
    wj = B[0];
    for (i = 1; i + 1 < 7; i++) {
      wj += V[i] * B[i];
    }

    wj *= tau[0];
    if (wj != 0.0) {
      B[0] -= wj;
      for (i = 1; i + 1 < 7; i++) {
        B[i] -= V[i] * wj;
      }
    }
  }

  if (tau[1] != 0.0) {
    wj = B[1];
    for (i = 2; i + 1 < 7; i++) {
      wj += V[i + 6] * B[i];
    }

    wj *= tau[1];
    if (wj != 0.0) {
      B[1] -= wj;
      for (i = 2; i + 1 < 7; i++) {
        B[i] -= V[i + 6] * wj;
      }
    }
  }

  p1[jpvt[0] - 1] = B[0];
  p1[jpvt[1] - 1] = B[1];
  p1[jpvt[1] - 1] /= V[7];
  i = 1;
  while (i <= 1) {
    p1[jpvt[0] - 1] -= p1[jpvt[1] - 1] * V[6];
    i = 2;
  }

  p1[jpvt[0] - 1] /= V[0];
  p[0] = p1[0];
  p[1] = p1[1];
}

/* Model output function */
void Torque_Vectoring_Controller_dSpace_RTI1401_output(void)
{
  real_T PmaxTyre;
  real_T limit[4];
  real_T vRFR_COG;
  real_T vRRL_COG;
  real_T vRRR_COG;
  int32_T ixstart;
  boolean_T exitg2;
  real_T dist[12];
  real_T vWheel_m[12];
  boolean_T x[4];
  real_T dFds[4];
  real_T p1[2];
  real_T p2[2];
  boolean_T guard1;
  int32_T i;
  real_T tmp[4];
  real_T tmp_0[4];
  real_T tmp_1[24];
  real_T tmp_2[24];
  int8_T checkFxmax_data[4];
  int8_T ii_data[4];
  real_T c_idx_0;
  real_T c_idx_1;
  real_T u0;

  /* MATLAB Function: '<S3>/Sensors' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   */
  /* MATLAB Function 'Vehicle Sensors/Sensors': '<S221>:1' */
  /* '<S221>:1:3' */
  Torque_Vectoring_Controller_d_B.sensors.ax = 0.0;

  /* '<S221>:1:4' */
  Torque_Vectoring_Controller_d_B.sensors.ay = 0.0;

  /* '<S221>:1:5' */
  Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0] = 0.0;
  Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1] = 0.0;
  Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2] = 0.0;
  Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3] = 0.0;

  /* '<S221>:1:6' */
  Torque_Vectoring_Controller_d_B.sensors.yawRate = 0.0;

  /* '<S221>:1:7' */
  Torque_Vectoring_Controller_d_B.sensors.steerAngle = 0.0;

  /* '<S221>:1:8' */
  Torque_Vectoring_Controller_d_B.sensors.wheelAngles[0] = 0.0;
  Torque_Vectoring_Controller_d_B.sensors.wheelAngles[1] = 0.0;
  Torque_Vectoring_Controller_d_B.sensors.wheelAngles[2] = 0.0;
  Torque_Vectoring_Controller_d_B.sensors.wheelAngles[3] = 0.0;

  /* '<S221>:1:9' */
  Torque_Vectoring_Controller_d_B.sensors.throttle = 0.0;

  /* '<S221>:1:10' */
  Torque_Vectoring_Controller_d_B.sensors.brake = 0.0;

  /* '<S221>:1:11' */
  Torque_Vectoring_Controller_d_B.sensors.torque[0] = 0.0;
  Torque_Vectoring_Controller_d_B.sensors.torque[1] = 0.0;
  Torque_Vectoring_Controller_d_B.sensors.torque[2] = 0.0;
  Torque_Vectoring_Controller_d_B.sensors.torque[3] = 0.0;

  /* '<S221>:1:12' */
  Torque_Vectoring_Controller_d_B.sensors.ax_error =
    Torque_Vectoring_Controller_d_P.Constant_Value;

  /* '<S221>:1:13' */
  Torque_Vectoring_Controller_d_B.sensors.ay_error =
    Torque_Vectoring_Controller_d_P.Constant1_Value;

  /* '<S221>:1:14' */
  Torque_Vectoring_Controller_d_B.sensors.yawRate_error =
    Torque_Vectoring_Controller_d_P.Constant2_Value;

  /* '<S221>:1:15' */
  Torque_Vectoring_Controller_d_B.sensors.knob1 =
    Torque_Vectoring_Controller_d_P.Constant3_Value;

  /* '<S221>:1:16' */
  Torque_Vectoring_Controller_d_B.sensors.knob2 =
    Torque_Vectoring_Controller_d_P.Constant4_Value;

  /* '<S221>:1:17' */
  Torque_Vectoring_Controller_d_B.sensors.P_elec = 0.0;

  /* MATLAB Function: '<S6>/Controller Settings' */
  /* MATLAB Function 'Controls/Controller Settings/Controller Settings': '<S20>:1' */
  /* % Settings */
  /* '<S20>:1:4' */
  /* '<S20>:1:10' */
  /* if sensors.knob1 == 1 */
  /* '<S20>:1:14' */
  /* end */
  /* if sensors.knob1 == 1 */
  /* '<S20>:1:18' */
  /* Change distributor mode */
  /* end */
  /* if sensors.knob2 == 1 */
  /* '<S20>:1:22' */
  /* '<S20>:1:23' */
  /* '<S20>:1:24' */
  /* '<S20>:1:25' */
  /* end */
  /* if sensors.knob2 == 2 */
  /* YRCMode_Temp = 2; */
  /* end */
  /* % Variables */
  /* '<S20>:1:33' */
  /* % Declaration Settings */
  /* '<S20>:1:38' */
  Torque_Vectoring_Controller_d_B.settings.velocityEstimation = 1.0;

  /* '<S20>:1:39' */
  Torque_Vectoring_Controller_d_B.settings.torqueMode = 2.0;

  /* '<S20>:1:40' */
  Torque_Vectoring_Controller_d_B.settings.YRC = 1.0;

  /* '<S20>:1:41' */
  Torque_Vectoring_Controller_d_B.settings.YRCMode = 1.0;

  /* '<S20>:1:42' */
  Torque_Vectoring_Controller_d_B.settings.distributorMode = 0.0;

  /* '<S20>:1:44' */
  Torque_Vectoring_Controller_d_B.settings.Fsens = 50.0;

  /* value between 0 and 100 */
  /*  100 --> Fdes is really important */
  /*  0 --> Mdes is really important */
  /* '<S20>:1:48' */
  Torque_Vectoring_Controller_d_B.settings.Fxsens = 1.0;

  /* '<S20>:1:50' */
  Torque_Vectoring_Controller_d_B.settings.TC = 0.0;

  /* '<S20>:1:51' */
  Torque_Vectoring_Controller_d_B.settings.unlimitedFx = 0.0;

  /* '<S20>:1:52' */
  Torque_Vectoring_Controller_d_B.settings.TV_bypass = 0.0;

  /* '<S20>:1:53' */
  Torque_Vectoring_Controller_d_B.settings.effEstimation = 2.0;

  /* % Declaration Variables */
  /* '<S20>:1:56' */
  Torque_Vectoring_Controller_d_B.variables.TD_percentage = 1.0;

  /* MATLAB Function: '<S4>/MATLAB Function' */
  /* MATLAB Function 'Controls/Bypass/MATLAB Function': '<S9>:1' */
  /* '<S9>:1:2' */
  PmaxTyre = Torque_Vectoring_Controller_d_P.car.Pmax_bypass * 0.25;

  /* '<S9>:1:7' */
  Torque_Vectoring_Controller_d_B.torqueBypass[0] =
    Torque_Vectoring_Controller_d_P.car.motor.Tmax[0] * 0.5 *
    Torque_Vectoring_Controller_d_P.car.gearRatio *
    Torque_Vectoring_Controller_d_B.sensors.throttle;
  Torque_Vectoring_Controller_d_B.torqueBypass[1] =
    Torque_Vectoring_Controller_d_P.car.motor.Tmax[1] * 0.5 *
    Torque_Vectoring_Controller_d_P.car.gearRatio *
    Torque_Vectoring_Controller_d_B.sensors.throttle;
  Torque_Vectoring_Controller_d_B.torqueBypass[2] =
    Torque_Vectoring_Controller_d_P.car.motor.Tmax[2] * 0.5 *
    Torque_Vectoring_Controller_d_P.car.gearRatio *
    Torque_Vectoring_Controller_d_B.sensors.throttle;
  Torque_Vectoring_Controller_d_B.torqueBypass[3] =
    Torque_Vectoring_Controller_d_P.car.motor.Tmax[3] * 0.5 *
    Torque_Vectoring_Controller_d_P.car.gearRatio *
    Torque_Vectoring_Controller_d_B.sensors.throttle;
  if (Torque_Vectoring_Controller_d_B.sensors.throttle > 0.0) {
    /* '<S9>:1:9' */
    /* '<S9>:1:10' */
    Torque_Vectoring_Controller_d_B.rpmBypass[0] =
      Torque_Vectoring_Controller_d_P.car.motor.rpmMax[0];
    Torque_Vectoring_Controller_d_B.rpmBypass[1] =
      Torque_Vectoring_Controller_d_P.car.motor.rpmMax[1];
    Torque_Vectoring_Controller_d_B.rpmBypass[2] =
      Torque_Vectoring_Controller_d_P.car.motor.rpmMax[2];
    Torque_Vectoring_Controller_d_B.rpmBypass[3] =
      Torque_Vectoring_Controller_d_P.car.motor.rpmMax[3];
  } else {
    /* '<S9>:1:12' */
    Torque_Vectoring_Controller_d_B.rpmBypass[0] = 0.0;
    Torque_Vectoring_Controller_d_B.rpmBypass[1] = 0.0;
    Torque_Vectoring_Controller_d_B.rpmBypass[2] = 0.0;
    Torque_Vectoring_Controller_d_B.rpmBypass[3] = 0.0;
  }

  /* % Power limiter */
  /* '<S9>:1:16' */
  /* '<S9>:1:17' */
  vRFR_COG = Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0];
  if (!(vRFR_COG >= 1.0)) {
    vRFR_COG = 1.0;
  }

  vRFR_COG = PmaxTyre / vRFR_COG;
  u0 = Torque_Vectoring_Controller_d_B.torqueBypass[0];
  if (!((u0 <= vRFR_COG) || rtIsNaN(vRFR_COG))) {
    u0 = vRFR_COG;
  }

  dFds[0] = u0;
  vRFR_COG = -vRFR_COG;
  limit[0] = vRFR_COG;
  vRFR_COG = Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1];
  if (!(vRFR_COG >= 1.0)) {
    vRFR_COG = 1.0;
  }

  vRFR_COG = PmaxTyre / vRFR_COG;
  u0 = Torque_Vectoring_Controller_d_B.torqueBypass[1];
  if (!((u0 <= vRFR_COG) || rtIsNaN(vRFR_COG))) {
    u0 = vRFR_COG;
  }

  dFds[1] = u0;
  vRFR_COG = -vRFR_COG;
  limit[1] = vRFR_COG;
  vRFR_COG = Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2];
  if (!(vRFR_COG >= 1.0)) {
    vRFR_COG = 1.0;
  }

  vRFR_COG = PmaxTyre / vRFR_COG;
  u0 = Torque_Vectoring_Controller_d_B.torqueBypass[2];
  if (!((u0 <= vRFR_COG) || rtIsNaN(vRFR_COG))) {
    u0 = vRFR_COG;
  }

  dFds[2] = u0;
  vRFR_COG = -vRFR_COG;
  limit[2] = vRFR_COG;
  vRFR_COG = Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3];
  if (!(vRFR_COG >= 1.0)) {
    vRFR_COG = 1.0;
  }

  vRFR_COG = PmaxTyre / vRFR_COG;
  u0 = Torque_Vectoring_Controller_d_B.torqueBypass[3];
  if (!((u0 <= vRFR_COG) || rtIsNaN(vRFR_COG))) {
    u0 = vRFR_COG;
  }

  dFds[3] = u0;
  vRFR_COG = -vRFR_COG;
  limit[3] = vRFR_COG;
  u0 = dFds[0];
  vRRR_COG = limit[0];
  if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
    vRRR_COG = u0;
  }

  Torque_Vectoring_Controller_d_B.torqueBypass[0] = vRRR_COG;
  u0 = dFds[1];
  vRRR_COG = limit[1];
  if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
    vRRR_COG = u0;
  }

  Torque_Vectoring_Controller_d_B.torqueBypass[1] = vRRR_COG;
  u0 = dFds[2];
  vRRR_COG = limit[2];
  if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
    vRRR_COG = u0;
  }

  Torque_Vectoring_Controller_d_B.torqueBypass[2] = vRRR_COG;
  u0 = dFds[3];
  vRRR_COG = limit[3];
  if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
    vRRR_COG = u0;
  }

  Torque_Vectoring_Controller_d_B.torqueBypass[3] = vRRR_COG;

  /* End of MATLAB Function: '<S4>/MATLAB Function' */

  /* BusCreator: '<S5>/BusConversion_InsertedFor_Yaw Rate Control_at_inport_0' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_YawRa =
    Torque_Vectoring_Controller_d_B.sensors;

  /* BusCreator: '<S5>/BusConversion_InsertedFor_Yaw Rate Control_at_inport_1' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_p =
    Torque_Vectoring_Controller_d_B.settings;

  /* Memory: '<S32>/Memory1' */
  Torque_Vectoring_Controller_d_B.Memory1 =
    Torque_Vectoring_Controller__DW.Memory1_PreviousInput;

  /* MATLAB Function: '<S32>/fuzzyParam' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Velocity Estimator/Fuzzy Velocity/fuzzyParam': '<S41>:1' */
  /* '<S41>:1:2' */
  /* '<S41>:1:3' */
  PmaxTyre = ((Torque_Vectoring_Controller_d_P.car.tw / 2.0 -
               Torque_Vectoring_Controller_d_P.car.lf * 0.0) *
              Torque_Vectoring_Controller_d_B.sensors.yawRate +
              Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0] *
              Torque_Vectoring_Controller_d_P.car.tireRadius) * cos
    (Torque_Vectoring_Controller_d_B.sensors.wheelAngles[0]);

  /* '<S41>:1:6' */
  vRFR_COG = (Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1] *
              Torque_Vectoring_Controller_d_P.car.tireRadius -
              (Torque_Vectoring_Controller_d_P.car.tw / 2.0 +
               Torque_Vectoring_Controller_d_P.car.lf * 0.0) *
              Torque_Vectoring_Controller_d_B.sensors.yawRate) * cos
    (Torque_Vectoring_Controller_d_B.sensors.wheelAngles[1]);

  /* '<S41>:1:9' */
  vRRL_COG = (Torque_Vectoring_Controller_d_P.car.tw / 2.0 +
              Torque_Vectoring_Controller_d_P.car.lr * 0.0) *
    Torque_Vectoring_Controller_d_B.sensors.yawRate +
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2] *
    Torque_Vectoring_Controller_d_P.car.tireRadius;

  /* '<S41>:1:12' */
  vRRR_COG = Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3] *
    Torque_Vectoring_Controller_d_P.car.tireRadius -
    (Torque_Vectoring_Controller_d_P.car.tw / 2.0 -
     Torque_Vectoring_Controller_d_P.car.lr * 0.0) *
    Torque_Vectoring_Controller_d_B.sensors.yawRate;

  /* '<S41>:1:15' */
  limit[0] = PmaxTyre;
  limit[1] = vRFR_COG;
  limit[2] = vRRL_COG;
  limit[3] = vRRR_COG;

  /* '<S41>:1:17' */
  Torque_Vectoring_Controller_d_B.deltaVFL = PmaxTyre -
    Torque_Vectoring_Controller_d_B.Memory1;

  /* '<S41>:1:18' */
  Torque_Vectoring_Controller_d_B.deltaVFR = vRFR_COG -
    Torque_Vectoring_Controller_d_B.Memory1;

  /* '<S41>:1:19' */
  Torque_Vectoring_Controller_d_B.deltaVRL = vRRL_COG -
    Torque_Vectoring_Controller_d_B.Memory1;

  /* '<S41>:1:20' */
  Torque_Vectoring_Controller_d_B.deltaVRR = vRRR_COG -
    Torque_Vectoring_Controller_d_B.Memory1;

  /* '<S41>:1:22' */
  ixstart = 1;
  PmaxTyre = limit[0];
  if (rtIsNaN(limit[0])) {
    i = 2;
    exitg2 = false;
    while ((!exitg2) && (i < 5)) {
      ixstart = i;
      if (!rtIsNaN(limit[i - 1])) {
        PmaxTyre = limit[i - 1];
        exitg2 = true;
      } else {
        i++;
      }
    }
  }

  if (ixstart < 4) {
    while (ixstart + 1 < 5) {
      if (limit[ixstart] > PmaxTyre) {
        PmaxTyre = limit[ixstart];
      }

      ixstart++;
    }
  }

  ixstart = 1;
  vRFR_COG = limit[0];
  if (rtIsNaN(limit[0])) {
    i = 2;
    exitg2 = false;
    while ((!exitg2) && (i < 5)) {
      ixstart = i;
      if (!rtIsNaN(limit[i - 1])) {
        vRFR_COG = limit[i - 1];
        exitg2 = true;
      } else {
        i++;
      }
    }
  }

  if (ixstart < 4) {
    while (ixstart + 1 < 5) {
      if (limit[ixstart] < vRFR_COG) {
        vRFR_COG = limit[ixstart];
      }

      ixstart++;
    }
  }

  Torque_Vectoring_Controller_d_B.maxDeltaV = fabs
    (Torque_Vectoring_Controller_d_B.Memory1 - PmaxTyre) + fabs
    (Torque_Vectoring_Controller_d_B.Memory1 - vRFR_COG);

  /* End of MATLAB Function: '<S32>/fuzzyParam' */

  /* DataTypeConversion: '<S88>/DataConv' */
  Torque_Vectoring_Controller_d_B.DataConv =
    Torque_Vectoring_Controller_d_B.deltaVFL;

  /* If: '<S110>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv < -2.50192752505783) ||
      (Torque_Vectoring_Controller_d_B.DataConv > 2.49807247494217)) {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv >= -1.25192752505783) &&
             (Torque_Vectoring_Controller_d_B.DataConv <= 1.24807247494217)) {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv < -1.25192752505783) {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1,
      Torque_Vectoring_Controller_d_P.in1mf3_a,
      Torque_Vectoring_Controller_d_P.in1mf3_b);

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3,
      Torque_Vectoring_Controller_d_P.in1mf3_c,
      Torque_Vectoring_Controller_d_P.in1mf3_d);

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem3' */
  }

  /* End of If: '<S110>/If' */

  /* DataTypeConversion: '<S97>/DataConv' */
  Torque_Vectoring_Controller_d_B.DataConv_l =
    Torque_Vectoring_Controller_d_B.maxDeltaV;

  /* If: '<S209>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_l < -0.176638396299152) ||
      (Torque_Vectoring_Controller_d_B.DataConv_l > 0.423361603700848)) {
    /* Outputs for IfAction SubSystem: '<S209>/If Action Subsystem' incorporates:
     *  ActionPort: '<S214>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_o,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_b);

    /* End of Outputs for SubSystem: '<S209>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_l >= -0.00163839629915194)
             && (Torque_Vectoring_Controller_d_B.DataConv_l <= 0.248361603700848))
  {
    /* Outputs for IfAction SubSystem: '<S209>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S216>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_o,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_j);

    /* End of Outputs for SubSystem: '<S209>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_l < -0.00163839629915194)
  {
    /* Outputs for IfAction SubSystem: '<S209>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S215>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_l,
      &Torque_Vectoring_Controller_d_B.Merge_o,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_p,
      Torque_Vectoring_Controller_d_P.small_a,
      Torque_Vectoring_Controller_d_P.small_b);

    /* End of Outputs for SubSystem: '<S209>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S209>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S217>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_l,
      &Torque_Vectoring_Controller_d_B.Merge_o,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_o,
      Torque_Vectoring_Controller_d_P.small_c,
      Torque_Vectoring_Controller_d_P.small_d);

    /* End of Outputs for SubSystem: '<S209>/If Action Subsystem3' */
  }

  /* End of If: '<S209>/If' */

  /* MinMax: '<S48>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod = PmaxTyre;

  /* End of MinMax: '<S48>/andorMethod' */

  /* Product: '<S48>/Weighting' incorporates:
   *  Constant: '<S48>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting =
    Torque_Vectoring_Controller_d_P.Weight_Value *
    Torque_Vectoring_Controller_d_B.andorMethod;

  /* MinMax: '<S48>/impMethod' incorporates:
   *  Constant: '<S92>/big'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S48>/impMethod' */

  /* If: '<S109>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv < -4.76626060138782) ||
      (Torque_Vectoring_Controller_d_B.DataConv > -1.02026060138782)) {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_d,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_i);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv >= -3.51626060138782) &&
             (Torque_Vectoring_Controller_d_B.DataConv <= -2.26626060138782)) {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_d,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_k);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv < -3.51626060138782) {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge_d,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_b,
      Torque_Vectoring_Controller_d_P.in1mf2_a,
      Torque_Vectoring_Controller_d_P.in1mf2_b);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge_d,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_g,
      Torque_Vectoring_Controller_d_P.in1mf2_c,
      Torque_Vectoring_Controller_d_P.in1mf2_d);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem3' */
  }

  /* End of If: '<S109>/If' */

  /* MinMax: '<S59>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_d;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_h = PmaxTyre;

  /* End of MinMax: '<S59>/andorMethod' */

  /* Product: '<S59>/Weighting' incorporates:
   *  Constant: '<S59>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_g =
    Torque_Vectoring_Controller_d_P.Weight_Value_o *
    Torque_Vectoring_Controller_d_B.andorMethod_h;

  /* MinMax: '<S59>/impMethod' incorporates:
   *  Constant: '<S92>/middle'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_g;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_g;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_g;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_g;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_g;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_a[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S59>/impMethod' */

  /* If: '<S112>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv < 1.03199537393986) ||
      (Torque_Vectoring_Controller_d_B.DataConv > 4.77799537393986)) {
    /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_c,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_it);

    /* End of Outputs for SubSystem: '<S112>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv >= 2.28199537393986) &&
             (Torque_Vectoring_Controller_d_B.DataConv <= 3.53199537393986)) {
    /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_c,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_j3);

    /* End of Outputs for SubSystem: '<S112>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv < 2.28199537393986) {
    /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge_c,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_d,
      Torque_Vectoring_Controller_d_P.in1mf5_a,
      Torque_Vectoring_Controller_d_P.in1mf5_b);

    /* End of Outputs for SubSystem: '<S112>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S132>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge_c,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_g5,
      Torque_Vectoring_Controller_d_P.in1mf5_c,
      Torque_Vectoring_Controller_d_P.in1mf5_d);

    /* End of Outputs for SubSystem: '<S112>/If Action Subsystem3' */
  }

  /* End of If: '<S112>/If' */

  /* MinMax: '<S70>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_c;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_o = PmaxTyre;

  /* End of MinMax: '<S70>/andorMethod' */

  /* Product: '<S70>/Weighting' incorporates:
   *  Constant: '<S70>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_k =
    Torque_Vectoring_Controller_d_P.Weight_Value_k *
    Torque_Vectoring_Controller_d_B.andorMethod_o;

  /* MinMax: '<S70>/impMethod' incorporates:
   *  Constant: '<S92>/middle'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_l[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S70>/impMethod' */

  /* If: '<S108>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv < -25.0) ||
      (Torque_Vectoring_Controller_d_B.DataConv > -3.567)) {
    /* Outputs for IfAction SubSystem: '<S108>/If Action Subsystem' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_g,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_g);

    /* End of Outputs for SubSystem: '<S108>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv >= -20.0) &&
             (Torque_Vectoring_Controller_d_B.DataConv <= -4.817)) {
    /* Outputs for IfAction SubSystem: '<S108>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_g,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_o);

    /* End of Outputs for SubSystem: '<S108>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv < -20.0) {
    /* Outputs for IfAction SubSystem: '<S108>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge_g,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_g,
      Torque_Vectoring_Controller_d_P.in1mf1_a,
      Torque_Vectoring_Controller_d_P.in1mf1_b);

    /* End of Outputs for SubSystem: '<S108>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S108>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge_g,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_l,
      Torque_Vectoring_Controller_d_P.in1mf1_c,
      Torque_Vectoring_Controller_d_P.in1mf1_d);

    /* End of Outputs for SubSystem: '<S108>/If Action Subsystem3' */
  }

  /* End of If: '<S108>/If' */

  /* MinMax: '<S81>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_g;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_g = PmaxTyre;

  /* End of MinMax: '<S81>/andorMethod' */

  /* Product: '<S81>/Weighting' incorporates:
   *  Constant: '<S81>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_b =
    Torque_Vectoring_Controller_d_P.Weight_Value_m *
    Torque_Vectoring_Controller_d_B.andorMethod_g;

  /* MinMax: '<S81>/impMethod' incorporates:
   *  Constant: '<S92>/small'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_b;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_b;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_b;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_b;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_b;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_n[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S81>/impMethod' */

  /* If: '<S111>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv < 3.46858134155744) ||
      (Torque_Vectoring_Controller_d_B.DataConv > 20.7185813415574)) {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_k,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_c);

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv >= 4.71858134155744) &&
             (Torque_Vectoring_Controller_d_B.DataConv <= 15.3785813415574)) {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_k,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_d);

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv < 4.71858134155744) {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge_k,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_pc,
      Torque_Vectoring_Controller_d_P.in1mf4_a,
      Torque_Vectoring_Controller_d_P.in1mf4_b);

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv,
      &Torque_Vectoring_Controller_d_B.Merge_k,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_i,
      Torque_Vectoring_Controller_d_P.in1mf4_c,
      Torque_Vectoring_Controller_d_P.in1mf4_d);

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem3' */
  }

  /* End of If: '<S111>/If' */

  /* MinMax: '<S83>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_k;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_h1 = PmaxTyre;

  /* End of MinMax: '<S83>/andorMethod' */

  /* Product: '<S83>/Weighting' incorporates:
   *  Constant: '<S83>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_p =
    Torque_Vectoring_Controller_d_P.Weight_Value_d *
    Torque_Vectoring_Controller_d_B.andorMethod_h1;

  /* MinMax: '<S83>/impMethod' incorporates:
   *  Constant: '<S92>/small'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_g[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S83>/impMethod' */

  /* If: '<S208>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_l < 0.2661) ||
      (Torque_Vectoring_Controller_d_B.DataConv_l > 25.0)) {
    /* Outputs for IfAction SubSystem: '<S208>/If Action Subsystem' incorporates:
     *  ActionPort: '<S210>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_h,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_l);

    /* End of Outputs for SubSystem: '<S208>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_l >= 0.4611) &&
             (Torque_Vectoring_Controller_d_B.DataConv_l <= 1.241)) {
    /* Outputs for IfAction SubSystem: '<S208>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S212>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_h,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_m);

    /* End of Outputs for SubSystem: '<S208>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_l < 0.4611) {
    /* Outputs for IfAction SubSystem: '<S208>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S211>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_l,
      &Torque_Vectoring_Controller_d_B.Merge_h,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_pp,
      Torque_Vectoring_Controller_d_P.big_a,
      Torque_Vectoring_Controller_d_P.big_b);

    /* End of Outputs for SubSystem: '<S208>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S208>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S213>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_l,
      &Torque_Vectoring_Controller_d_B.Merge_h,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_a,
      Torque_Vectoring_Controller_d_P.big_c,
      Torque_Vectoring_Controller_d_P.big_d);

    /* End of Outputs for SubSystem: '<S208>/If Action Subsystem3' */
  }

  /* End of If: '<S208>/If' */

  /* MinMax: '<S84>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_d = PmaxTyre;

  /* End of MinMax: '<S84>/andorMethod' */

  /* Product: '<S84>/Weighting' incorporates:
   *  Constant: '<S84>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_pe =
    Torque_Vectoring_Controller_d_P.Weight_Value_e *
    Torque_Vectoring_Controller_d_B.andorMethod_d;

  /* MinMax: '<S84>/impMethod' incorporates:
   *  Constant: '<S92>/big'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/middle'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pe;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pe;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pe;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pe;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pe;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_o[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_e[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S84>/impMethod' */

  /* MinMax: '<S85>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_c;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_di = PmaxTyre;

  /* End of MinMax: '<S85>/andorMethod' */

  /* Product: '<S85>/Weighting' incorporates:
   *  Constant: '<S85>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_c =
    Torque_Vectoring_Controller_d_P.Weight_Value_p *
    Torque_Vectoring_Controller_d_B.andorMethod_di;

  /* MinMax: '<S85>/impMethod' incorporates:
   *  Constant: '<S92>/big'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_c;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_c;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_c;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_c;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_c;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_o[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S85>/impMethod' */

  /* MinMax: '<S86>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_d;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_h3 = PmaxTyre;

  /* End of MinMax: '<S86>/andorMethod' */

  /* Product: '<S86>/Weighting' incorporates:
   *  Constant: '<S86>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_ch =
    Torque_Vectoring_Controller_d_P.Weight_Value_m4 *
    Torque_Vectoring_Controller_d_B.andorMethod_h3;

  /* MinMax: '<S86>/impMethod' incorporates:
   *  Constant: '<S92>/big'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ch;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ch;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ch;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ch;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ch;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_b[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S86>/impMethod' */

  /* MinMax: '<S87>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_g;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_f = PmaxTyre;

  /* End of MinMax: '<S87>/andorMethod' */

  /* Product: '<S87>/Weighting' incorporates:
   *  Constant: '<S87>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_bn =
    Torque_Vectoring_Controller_d_P.Weight_Value_a *
    Torque_Vectoring_Controller_d_B.andorMethod_f;

  /* MinMax: '<S87>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bn;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bn;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bn;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bn;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bn;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_i[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S87>/impMethod' */

  /* MinMax: '<S49>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_k;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_a = PmaxTyre;

  /* End of MinMax: '<S49>/andorMethod' */

  /* Product: '<S49>/Weighting' incorporates:
   *  Constant: '<S49>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_f =
    Torque_Vectoring_Controller_d_P.Weight_Value_m1 *
    Torque_Vectoring_Controller_d_B.andorMethod_a;

  /* MinMax: '<S49>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_f;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_f;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_f;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_f;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_f;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_ox[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S49>/impMethod' */

  /* DataTypeConversion: '<S89>/DataConv' */
  Torque_Vectoring_Controller_d_B.DataConv_g =
    Torque_Vectoring_Controller_d_B.deltaVFR;

  /* If: '<S135>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_g < -2.502) ||
      (Torque_Vectoring_Controller_d_B.DataConv_g > 2.498)) {
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem' incorporates:
     *  ActionPort: '<S146>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_j,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_o);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_g >= -1.252) &&
             (Torque_Vectoring_Controller_d_B.DataConv_g <= 1.248)) {
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S148>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_j,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_mv);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_g < -1.252) {
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S147>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_j,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_a,
      Torque_Vectoring_Controller_d_P.in2mf3_a,
      Torque_Vectoring_Controller_d_P.in2mf3_b);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S149>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_j,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_h,
      Torque_Vectoring_Controller_d_P.in2mf3_c,
      Torque_Vectoring_Controller_d_P.in2mf3_d);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem3' */
  }

  /* End of If: '<S135>/If' */

  /* MinMax: '<S50>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_j;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_l = PmaxTyre;

  /* End of MinMax: '<S50>/andorMethod' */

  /* Product: '<S50>/Weighting' incorporates:
   *  Constant: '<S50>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_h =
    Torque_Vectoring_Controller_d_P.Weight_Value_f *
    Torque_Vectoring_Controller_d_B.andorMethod_l;

  /* MinMax: '<S50>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/big'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_h[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_f[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S50>/impMethod' */

  /* If: '<S136>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_g < 1.032) ||
      (Torque_Vectoring_Controller_d_B.DataConv_g > 4.778)) {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_e,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_h);

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_g >= 2.282) &&
             (Torque_Vectoring_Controller_d_B.DataConv_g <= 3.532)) {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_e,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_e);

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_g < 2.282) {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_e,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_h,
      Torque_Vectoring_Controller_d_P.in2mf4_a,
      Torque_Vectoring_Controller_d_P.in2mf4_b);

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_e,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_k,
      Torque_Vectoring_Controller_d_P.in2mf4_c,
      Torque_Vectoring_Controller_d_P.in2mf4_d);

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem3' */
  }

  /* End of If: '<S136>/If' */

  /* MinMax: '<S51>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_e;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_hj = PmaxTyre;

  /* End of MinMax: '<S51>/andorMethod' */

  /* Product: '<S51>/Weighting' incorporates:
   *  Constant: '<S51>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_a =
    Torque_Vectoring_Controller_d_P.Weight_Value_g *
    Torque_Vectoring_Controller_d_B.andorMethod_hj;

  /* MinMax: '<S51>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/middle'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_a;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_a;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_d[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_a;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_a;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_a;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_no[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S51>/impMethod' */

  /* If: '<S134>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_g < -4.766) ||
      (Torque_Vectoring_Controller_d_B.DataConv_g > -1.02)) {
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_b,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_ch);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_g >= -3.516) &&
             (Torque_Vectoring_Controller_d_B.DataConv_g <= -2.266)) {
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S144>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_b,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_of);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_g < -3.516) {
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_b,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_m,
      Torque_Vectoring_Controller_d_P.in2mf2_a,
      Torque_Vectoring_Controller_d_P.in2mf2_b);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S145>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_b,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_f,
      Torque_Vectoring_Controller_d_P.in2mf2_c,
      Torque_Vectoring_Controller_d_P.in2mf2_d);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem3' */
  }

  /* End of If: '<S134>/If' */

  /* MinMax: '<S52>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_b;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_p = PmaxTyre;

  /* End of MinMax: '<S52>/andorMethod' */

  /* Product: '<S52>/Weighting' incorporates:
   *  Constant: '<S52>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_gu =
    Torque_Vectoring_Controller_d_P.Weight_Value_fk *
    Torque_Vectoring_Controller_d_B.andorMethod_p;

  /* MinMax: '<S52>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/middle'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gu;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gu;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_d[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gu;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gu;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gu;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_h[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S52>/impMethod' */

  /* If: '<S133>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_g < -25.0) ||
      (Torque_Vectoring_Controller_d_B.DataConv_g > -3.567)) {
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
     *  ActionPort: '<S138>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_p,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_oz);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_g >= -20.0) &&
             (Torque_Vectoring_Controller_d_B.DataConv_g <= -4.817)) {
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_p,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_h);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_g < -20.0) {
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S139>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_p,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_al,
      Torque_Vectoring_Controller_d_P.in2mf1_a,
      Torque_Vectoring_Controller_d_P.in2mf1_b);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_p,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_c,
      Torque_Vectoring_Controller_d_P.in2mf1_c,
      Torque_Vectoring_Controller_d_P.in2mf1_d);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem3' */
  }

  /* End of If: '<S133>/If' */

  /* MinMax: '<S53>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_p;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_j = PmaxTyre;

  /* End of MinMax: '<S53>/andorMethod' */

  /* Product: '<S53>/Weighting' incorporates:
   *  Constant: '<S53>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_h4 =
    Torque_Vectoring_Controller_d_P.Weight_Value_i *
    Torque_Vectoring_Controller_d_B.andorMethod_j;

  /* MinMax: '<S53>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/small'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h4;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h4;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h4;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h4;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_h4;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_d[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S53>/impMethod' */

  /* If: '<S137>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_g < 3.469) ||
      (Torque_Vectoring_Controller_d_B.DataConv_g > 20.72)) {
    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_h2,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_j);

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_g >= 4.719) &&
             (Torque_Vectoring_Controller_d_B.DataConv_g <= 15.38)) {
    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_h2,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_b);

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_g < 4.719) {
    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_h2,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_o,
      Torque_Vectoring_Controller_d_P.in2mf5_a,
      Torque_Vectoring_Controller_d_P.in2mf5_b);

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_g,
      &Torque_Vectoring_Controller_d_B.Merge_h2,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_k2,
      Torque_Vectoring_Controller_d_P.in2mf5_c,
      Torque_Vectoring_Controller_d_P.in2mf5_d);

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem3' */
  }

  /* End of If: '<S137>/If' */

  /* MinMax: '<S54>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_h2;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_dq = PmaxTyre;

  /* End of MinMax: '<S54>/andorMethod' */

  /* Product: '<S54>/Weighting' incorporates:
   *  Constant: '<S54>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_d =
    Torque_Vectoring_Controller_d_P.Weight_Value_md *
    Torque_Vectoring_Controller_d_B.andorMethod_dq;

  /* MinMax: '<S54>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/small'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_d;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_d;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_d;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_d;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_d;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_fm[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S54>/impMethod' */

  /* MinMax: '<S55>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_j;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_e = PmaxTyre;

  /* End of MinMax: '<S55>/andorMethod' */

  /* Product: '<S55>/Weighting' incorporates:
   *  Constant: '<S55>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_k2 =
    Torque_Vectoring_Controller_d_P.Weight_Value_f1 *
    Torque_Vectoring_Controller_d_B.andorMethod_e;

  /* MinMax: '<S55>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/big'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/middle'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k2;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k2;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_h[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k2;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k2;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_k2;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_o[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_ou[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S55>/impMethod' */

  /* MinMax: '<S56>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_b;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_n = PmaxTyre;

  /* End of MinMax: '<S56>/andorMethod' */

  /* Product: '<S56>/Weighting' incorporates:
   *  Constant: '<S56>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_ca =
    Torque_Vectoring_Controller_d_P.Weight_Value_h *
    Torque_Vectoring_Controller_d_B.andorMethod_n;

  /* MinMax: '<S56>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/small'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ca;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ca;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ca;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ca;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ca;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_oa[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S56>/impMethod' */

  /* MinMax: '<S57>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_e;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_ls = PmaxTyre;

  /* End of MinMax: '<S57>/andorMethod' */

  /* Product: '<S57>/Weighting' incorporates:
   *  Constant: '<S57>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_fo =
    Torque_Vectoring_Controller_d_P.Weight_Value_pp *
    Torque_Vectoring_Controller_d_B.andorMethod_ls;

  /* MinMax: '<S57>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/small'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fo;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fo;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fo;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fo;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fo;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_i5[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S57>/impMethod' */

  /* MinMax: '<S58>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_p;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_de = PmaxTyre;

  /* End of MinMax: '<S58>/andorMethod' */

  /* Product: '<S58>/Weighting' incorporates:
   *  Constant: '<S58>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_o =
    Torque_Vectoring_Controller_d_P.Weight_Value_l *
    Torque_Vectoring_Controller_d_B.andorMethod_de;

  /* MinMax: '<S58>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_o;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_o;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_o;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_o;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_o;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_iy[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S58>/impMethod' */

  /* MinMax: '<S60>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_h2;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_i = PmaxTyre;

  /* End of MinMax: '<S60>/andorMethod' */

  /* Product: '<S60>/Weighting' incorporates:
   *  Constant: '<S60>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_i =
    Torque_Vectoring_Controller_d_P.Weight_Value_lj *
    Torque_Vectoring_Controller_d_B.andorMethod_i;

  /* MinMax: '<S60>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_i;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_i;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_i;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_i;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_i;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_c[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S60>/impMethod' */

  /* DataTypeConversion: '<S90>/DataConv' */
  Torque_Vectoring_Controller_d_B.DataConv_n =
    Torque_Vectoring_Controller_d_B.deltaVRL;

  /* If: '<S160>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_n < -2.502) ||
      (Torque_Vectoring_Controller_d_B.DataConv_n > 2.498)) {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_gd,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_a);

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_n >= -1.252) &&
             (Torque_Vectoring_Controller_d_B.DataConv_n <= 1.248)) {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S173>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_gd,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_n);

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_n < -1.252) {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S172>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_gd,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_gh,
      Torque_Vectoring_Controller_d_P.in3mf3_a,
      Torque_Vectoring_Controller_d_P.in3mf3_b);

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S174>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_gd,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_m,
      Torque_Vectoring_Controller_d_P.in3mf3_c,
      Torque_Vectoring_Controller_d_P.in3mf3_d);

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem3' */
  }

  /* End of If: '<S160>/If' */

  /* MinMax: '<S61>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_gd;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_lx = PmaxTyre;

  /* End of MinMax: '<S61>/andorMethod' */

  /* Product: '<S61>/Weighting' incorporates:
   *  Constant: '<S61>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_pj =
    Torque_Vectoring_Controller_d_P.Weight_Value_n *
    Torque_Vectoring_Controller_d_B.andorMethod_lx;

  /* MinMax: '<S61>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/big'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pj;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pj;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pj;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_o[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pj;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pj;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_ec[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S61>/impMethod' */

  /* If: '<S159>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_n < -4.766) ||
      (Torque_Vectoring_Controller_d_B.DataConv_n > -1.02)) {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_l,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_aw);

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_n >= -3.516) &&
             (Torque_Vectoring_Controller_d_B.DataConv_n <= -2.266)) {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_l,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_g);

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_n < -3.516) {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S168>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_l,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_j,
      Torque_Vectoring_Controller_d_P.in3mf2_a,
      Torque_Vectoring_Controller_d_P.in3mf2_b);

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S170>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_l,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_e,
      Torque_Vectoring_Controller_d_P.in3mf2_c,
      Torque_Vectoring_Controller_d_P.in3mf2_d);

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem3' */
  }

  /* End of If: '<S159>/If' */

  /* MinMax: '<S62>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_l;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_nr = PmaxTyre;

  /* End of MinMax: '<S62>/andorMethod' */

  /* Product: '<S62>/Weighting' incorporates:
   *  Constant: '<S62>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_kq =
    Torque_Vectoring_Controller_d_P.Weight_Value_c *
    Torque_Vectoring_Controller_d_B.andorMethod_nr;

  /* MinMax: '<S62>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/middle'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kq;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kq;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kq;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_ox[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kq;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kq;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_k[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S62>/impMethod' */

  /* If: '<S161>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_n < 1.032) ||
      (Torque_Vectoring_Controller_d_B.DataConv_n > 4.778)) {
    /* Outputs for IfAction SubSystem: '<S161>/If Action Subsystem' incorporates:
     *  ActionPort: '<S175>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_es,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_ca);

    /* End of Outputs for SubSystem: '<S161>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_n >= 2.282) &&
             (Torque_Vectoring_Controller_d_B.DataConv_n <= 3.532)) {
    /* Outputs for IfAction SubSystem: '<S161>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_es,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_ds);

    /* End of Outputs for SubSystem: '<S161>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_n < 2.282) {
    /* Outputs for IfAction SubSystem: '<S161>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S176>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_es,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_n,
      Torque_Vectoring_Controller_d_P.in3mf4_a,
      Torque_Vectoring_Controller_d_P.in3mf4_b);

    /* End of Outputs for SubSystem: '<S161>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S161>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_es,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_fi,
      Torque_Vectoring_Controller_d_P.in3mf4_c,
      Torque_Vectoring_Controller_d_P.in3mf4_d);

    /* End of Outputs for SubSystem: '<S161>/If Action Subsystem3' */
  }

  /* End of If: '<S161>/If' */

  /* MinMax: '<S63>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_es;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_fe = PmaxTyre;

  /* End of MinMax: '<S63>/andorMethod' */

  /* Product: '<S63>/Weighting' incorporates:
   *  Constant: '<S63>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_ov =
    Torque_Vectoring_Controller_d_P.Weight_Value_gu *
    Torque_Vectoring_Controller_d_B.andorMethod_fe;

  /* MinMax: '<S63>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/middle'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ov;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ov;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ov;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_ox[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ov;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ov;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_fh[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S63>/impMethod' */

  /* If: '<S158>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_n < -25.0) ||
      (Torque_Vectoring_Controller_d_B.DataConv_n > -3.567)) {
    /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem' incorporates:
     *  ActionPort: '<S163>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_f,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_d);

    /* End of Outputs for SubSystem: '<S158>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_n >= -20.0) &&
             (Torque_Vectoring_Controller_d_B.DataConv_n <= -4.817)) {
    /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_f,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_js);

    /* End of Outputs for SubSystem: '<S158>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_n < -20.0) {
    /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_f,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_gu,
      Torque_Vectoring_Controller_d_P.in3mf1_a,
      Torque_Vectoring_Controller_d_P.in3mf1_b);

    /* End of Outputs for SubSystem: '<S158>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S166>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_f,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_ey,
      Torque_Vectoring_Controller_d_P.in3mf1_c,
      Torque_Vectoring_Controller_d_P.in3mf1_d);

    /* End of Outputs for SubSystem: '<S158>/If Action Subsystem3' */
  }

  /* End of If: '<S158>/If' */

  /* MinMax: '<S64>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_f;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_m = PmaxTyre;

  /* End of MinMax: '<S64>/andorMethod' */

  /* Product: '<S64>/Weighting' incorporates:
   *  Constant: '<S64>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_e =
    Torque_Vectoring_Controller_d_P.Weight_Value_oo *
    Torque_Vectoring_Controller_d_B.andorMethod_m;

  /* MinMax: '<S64>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/small'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_e;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_e;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_e;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_b[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_e;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_e;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_bl[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S64>/impMethod' */

  /* If: '<S162>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_n < 3.469) ||
      (Torque_Vectoring_Controller_d_B.DataConv_n > 20.72)) {
    /* Outputs for IfAction SubSystem: '<S162>/If Action Subsystem' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_k1,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_p);

    /* End of Outputs for SubSystem: '<S162>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_n >= 4.719) &&
             (Torque_Vectoring_Controller_d_B.DataConv_n <= 15.38)) {
    /* Outputs for IfAction SubSystem: '<S162>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_k1,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_gt);

    /* End of Outputs for SubSystem: '<S162>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_n < 4.719) {
    /* Outputs for IfAction SubSystem: '<S162>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_k1,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_l,
      Torque_Vectoring_Controller_d_P.in3mf5_a,
      Torque_Vectoring_Controller_d_P.in3mf5_b);

    /* End of Outputs for SubSystem: '<S162>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S162>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_n,
      &Torque_Vectoring_Controller_d_B.Merge_k1,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_ms,
      Torque_Vectoring_Controller_d_P.in3mf5_c,
      Torque_Vectoring_Controller_d_P.in3mf5_d);

    /* End of Outputs for SubSystem: '<S162>/If Action Subsystem3' */
  }

  /* End of If: '<S162>/If' */

  /* MinMax: '<S65>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_k1;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_jj = PmaxTyre;

  /* End of MinMax: '<S65>/andorMethod' */

  /* Product: '<S65>/Weighting' incorporates:
   *  Constant: '<S65>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_p3 =
    Torque_Vectoring_Controller_d_P.Weight_Value_hr *
    Torque_Vectoring_Controller_d_B.andorMethod_jj;

  /* MinMax: '<S65>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/small'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p3;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p3;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p3;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_b[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p3;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_p3;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_bb[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S65>/impMethod' */

  /* MinMax: '<S66>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_gd;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_c = PmaxTyre;

  /* End of MinMax: '<S66>/andorMethod' */

  /* Product: '<S66>/Weighting' incorporates:
   *  Constant: '<S66>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_n =
    Torque_Vectoring_Controller_d_P.Weight_Value_ll *
    Torque_Vectoring_Controller_d_B.andorMethod_c;

  /* MinMax: '<S66>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/big'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/middle'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_n;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_n;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_n;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_o[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_n;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_n;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_o[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_la[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S66>/impMethod' */

  /* MinMax: '<S67>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_l;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_i2 = PmaxTyre;

  /* End of MinMax: '<S67>/andorMethod' */

  /* Product: '<S67>/Weighting' incorporates:
   *  Constant: '<S67>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_bb =
    Torque_Vectoring_Controller_d_P.Weight_Value_c0 *
    Torque_Vectoring_Controller_d_B.andorMethod_i2;

  /* MinMax: '<S67>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/small'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_b[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_ds[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S67>/impMethod' */

  /* MinMax: '<S68>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_es;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_fo = PmaxTyre;

  /* End of MinMax: '<S68>/andorMethod' */

  /* Product: '<S68>/Weighting' incorporates:
   *  Constant: '<S68>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_ow =
    Torque_Vectoring_Controller_d_P.Weight_Value_cp *
    Torque_Vectoring_Controller_d_B.andorMethod_fo;

  /* MinMax: '<S68>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/small'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ow;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ow;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ow;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_b[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ow;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ow;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_m[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S68>/impMethod' */

  /* MinMax: '<S69>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_f;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_og = PmaxTyre;

  /* End of MinMax: '<S69>/andorMethod' */

  /* Product: '<S69>/Weighting' incorporates:
   *  Constant: '<S69>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_ev =
    Torque_Vectoring_Controller_d_P.Weight_Value_ca *
    Torque_Vectoring_Controller_d_B.andorMethod_og;

  /* MinMax: '<S69>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ev;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ev;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ev;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ev;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ev;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_lh[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S69>/impMethod' */

  /* MinMax: '<S71>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_k1;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_k = PmaxTyre;

  /* End of MinMax: '<S71>/andorMethod' */

  /* Product: '<S71>/Weighting' incorporates:
   *  Constant: '<S71>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_ed =
    Torque_Vectoring_Controller_d_P.Weight_Value_it *
    Torque_Vectoring_Controller_d_B.andorMethod_k;

  /* MinMax: '<S71>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ed;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ed;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ed;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ed;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ed;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_j[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S71>/impMethod' */

  /* DataTypeConversion: '<S91>/DataConv' */
  Torque_Vectoring_Controller_d_B.DataConv_a =
    Torque_Vectoring_Controller_d_B.deltaVRR;

  /* If: '<S185>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_a < -2.502) ||
      (Torque_Vectoring_Controller_d_B.DataConv_a > 2.498)) {
    /* Outputs for IfAction SubSystem: '<S185>/If Action Subsystem' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_gr,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_pe);

    /* End of Outputs for SubSystem: '<S185>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_a >= -1.252) &&
             (Torque_Vectoring_Controller_d_B.DataConv_a <= 1.248)) {
    /* Outputs for IfAction SubSystem: '<S185>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S198>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_gr,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_a);

    /* End of Outputs for SubSystem: '<S185>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_a < -1.252) {
    /* Outputs for IfAction SubSystem: '<S185>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S197>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_gr,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_ni,
      Torque_Vectoring_Controller_d_P.in4mf3_a,
      Torque_Vectoring_Controller_d_P.in4mf3_b);

    /* End of Outputs for SubSystem: '<S185>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S185>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S199>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_gr,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_h4,
      Torque_Vectoring_Controller_d_P.in4mf3_c,
      Torque_Vectoring_Controller_d_P.in4mf3_d);

    /* End of Outputs for SubSystem: '<S185>/If Action Subsystem3' */
  }

  /* End of If: '<S185>/If' */

  /* MinMax: '<S72>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_gr;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_b = PmaxTyre;

  /* End of MinMax: '<S72>/andorMethod' */

  /* Product: '<S72>/Weighting' incorporates:
   *  Constant: '<S72>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_gb =
    Torque_Vectoring_Controller_d_P.Weight_Value_b *
    Torque_Vectoring_Controller_d_B.andorMethod_b;

  /* MinMax: '<S72>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/big'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_gb;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_ji[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S72>/impMethod' */

  /* If: '<S184>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_a < -4.766) ||
      (Torque_Vectoring_Controller_d_B.DataConv_a > -1.02)) {
    /* Outputs for IfAction SubSystem: '<S184>/If Action Subsystem' incorporates:
     *  ActionPort: '<S192>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_je,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_f);

    /* End of Outputs for SubSystem: '<S184>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_a >= -3.516) &&
             (Torque_Vectoring_Controller_d_B.DataConv_a <= -2.266)) {
    /* Outputs for IfAction SubSystem: '<S184>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S194>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_je,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_d0);

    /* End of Outputs for SubSystem: '<S184>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_a < -3.516) {
    /* Outputs for IfAction SubSystem: '<S184>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S193>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_je,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_px,
      Torque_Vectoring_Controller_d_P.in4mf2_a,
      Torque_Vectoring_Controller_d_P.in4mf2_b);

    /* End of Outputs for SubSystem: '<S184>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S184>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S195>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_je,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_fd,
      Torque_Vectoring_Controller_d_P.in4mf2_c,
      Torque_Vectoring_Controller_d_P.in4mf2_d);

    /* End of Outputs for SubSystem: '<S184>/If Action Subsystem3' */
  }

  /* End of If: '<S184>/If' */

  /* MinMax: '<S73>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_je;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_nz = PmaxTyre;

  /* End of MinMax: '<S73>/andorMethod' */

  /* Product: '<S73>/Weighting' incorporates:
   *  Constant: '<S73>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_j =
    Torque_Vectoring_Controller_d_P.Weight_Value_nf *
    Torque_Vectoring_Controller_d_B.andorMethod_nz;

  /* MinMax: '<S73>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/middle'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_j;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_j;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_j;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_j;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_ou[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_j;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_c2[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S73>/impMethod' */

  /* If: '<S186>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_a < 1.032) ||
      (Torque_Vectoring_Controller_d_B.DataConv_a > 4.778)) {
    /* Outputs for IfAction SubSystem: '<S186>/If Action Subsystem' incorporates:
     *  ActionPort: '<S200>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_i,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_di);

    /* End of Outputs for SubSystem: '<S186>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_a >= 2.282) &&
             (Torque_Vectoring_Controller_d_B.DataConv_a <= 3.532)) {
    /* Outputs for IfAction SubSystem: '<S186>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S202>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_i,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_ej);

    /* End of Outputs for SubSystem: '<S186>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_a < 2.282) {
    /* Outputs for IfAction SubSystem: '<S186>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S201>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_i,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_f,
      Torque_Vectoring_Controller_d_P.in4mf4_a,
      Torque_Vectoring_Controller_d_P.in4mf4_b);

    /* End of Outputs for SubSystem: '<S186>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S186>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S203>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_i,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_n,
      Torque_Vectoring_Controller_d_P.in4mf4_c,
      Torque_Vectoring_Controller_d_P.in4mf4_d);

    /* End of Outputs for SubSystem: '<S186>/If Action Subsystem3' */
  }

  /* End of If: '<S186>/If' */

  /* MinMax: '<S74>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_i;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_os = PmaxTyre;

  /* End of MinMax: '<S74>/andorMethod' */

  /* Product: '<S74>/Weighting' incorporates:
   *  Constant: '<S74>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_bg =
    Torque_Vectoring_Controller_d_P.Weight_Value_f4 *
    Torque_Vectoring_Controller_d_B.andorMethod_os;

  /* MinMax: '<S74>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/middle'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_ou[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_bg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_hg[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S74>/impMethod' */

  /* If: '<S183>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_a < -25.0) ||
      (Torque_Vectoring_Controller_d_B.DataConv_a > -3.567)) {
    /* Outputs for IfAction SubSystem: '<S183>/If Action Subsystem' incorporates:
     *  ActionPort: '<S188>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_m,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_n);

    /* End of Outputs for SubSystem: '<S183>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_a >= -20.0) &&
             (Torque_Vectoring_Controller_d_B.DataConv_a <= -4.817)) {
    /* Outputs for IfAction SubSystem: '<S183>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S190>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_m,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_mo);

    /* End of Outputs for SubSystem: '<S183>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_a < -20.0) {
    /* Outputs for IfAction SubSystem: '<S183>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S189>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_m,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_mg,
      Torque_Vectoring_Controller_d_P.in4mf1_a,
      Torque_Vectoring_Controller_d_P.in4mf1_b);

    /* End of Outputs for SubSystem: '<S183>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S183>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S191>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_m,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_j,
      Torque_Vectoring_Controller_d_P.in4mf1_c,
      Torque_Vectoring_Controller_d_P.in4mf1_d);

    /* End of Outputs for SubSystem: '<S183>/If Action Subsystem3' */
  }

  /* End of If: '<S183>/If' */

  /* MinMax: '<S75>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_m;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_jy = PmaxTyre;

  /* End of MinMax: '<S75>/andorMethod' */

  /* Product: '<S75>/Weighting' incorporates:
   *  Constant: '<S75>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_oh =
    Torque_Vectoring_Controller_d_P.Weight_Value_cz *
    Torque_Vectoring_Controller_d_B.andorMethod_jy;

  /* MinMax: '<S75>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/small'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_oh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_oh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_oh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_oh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_ak[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_oh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_at[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S75>/impMethod' */

  /* If: '<S187>/If' */
  if ((Torque_Vectoring_Controller_d_B.DataConv_a < 3.469) ||
      (Torque_Vectoring_Controller_d_B.DataConv_a > 20.72)) {
    /* Outputs for IfAction SubSystem: '<S187>/If Action Subsystem' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_ov,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem_fz);

    /* End of Outputs for SubSystem: '<S187>/If Action Subsystem' */
  } else if ((Torque_Vectoring_Controller_d_B.DataConv_a >= 4.719) &&
             (Torque_Vectoring_Controller_d_B.DataConv_a <= 15.38)) {
    /* Outputs for IfAction SubSystem: '<S187>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S206>/Action Port'
     */
    Torque_Vector_IfActionSubsystem(&Torque_Vectoring_Controller_d_B.Merge_ov,
      (P_IfActionSubsystem_Torque_Ve_T *)
      &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_ae);

    /* End of Outputs for SubSystem: '<S187>/If Action Subsystem2' */
  } else if (Torque_Vectoring_Controller_d_B.DataConv_a < 4.719) {
    /* Outputs for IfAction SubSystem: '<S187>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S205>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem1(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_ov,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_on,
      Torque_Vectoring_Controller_d_P.in4mf5_a,
      Torque_Vectoring_Controller_d_P.in4mf5_b);

    /* End of Outputs for SubSystem: '<S187>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S187>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S207>/Action Port'
     */
    Torque_Vecto_IfActionSubsystem3(Torque_Vectoring_Controller_d_B.DataConv_a,
      &Torque_Vectoring_Controller_d_B.Merge_ov,
      &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_ne,
      Torque_Vectoring_Controller_d_P.in4mf5_c,
      Torque_Vectoring_Controller_d_P.in4mf5_d);

    /* End of Outputs for SubSystem: '<S187>/If Action Subsystem3' */
  }

  /* End of If: '<S187>/If' */

  /* MinMax: '<S76>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_ov;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_o;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_g1 = PmaxTyre;

  /* End of MinMax: '<S76>/andorMethod' */

  /* Product: '<S76>/Weighting' incorporates:
   *  Constant: '<S76>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_pg =
    Torque_Vectoring_Controller_d_P.Weight_Value_ly *
    Torque_Vectoring_Controller_d_B.andorMethod_g1;

  /* MinMax: '<S76>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/small'
   *  Constant: '<S96>/zero'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_ak[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_pg;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_a[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_eq[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S76>/impMethod' */

  /* MinMax: '<S77>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_gr;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_pg = PmaxTyre;

  /* End of MinMax: '<S77>/andorMethod' */

  /* Product: '<S77>/Weighting' incorporates:
   *  Constant: '<S77>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_fw =
    Torque_Vectoring_Controller_d_P.Weight_Value_pt *
    Torque_Vectoring_Controller_d_B.andorMethod_pg;

  /* MinMax: '<S77>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/big'
   *  Constant: '<S96>/middle'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fw;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fw;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fw;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fw;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fw;
    vRRR_COG = Torque_Vectoring_Controller_d_P.middle_Value_o[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_lai[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S77>/impMethod' */

  /* MinMax: '<S78>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_je;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_ex = PmaxTyre;

  /* End of MinMax: '<S78>/andorMethod' */

  /* Product: '<S78>/Weighting' incorporates:
   *  Constant: '<S78>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_fl =
    Torque_Vectoring_Controller_d_P.Weight_Value_j *
    Torque_Vectoring_Controller_d_B.andorMethod_ex;

  /* MinMax: '<S78>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/small'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fl;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fl;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fl;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fl;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_ak[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_fl;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_atx[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S78>/impMethod' */

  /* MinMax: '<S79>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_i;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_jr = PmaxTyre;

  /* End of MinMax: '<S79>/andorMethod' */

  /* Product: '<S79>/Weighting' incorporates:
   *  Constant: '<S79>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_ig =
    Torque_Vectoring_Controller_d_P.Weight_Value_fy *
    Torque_Vectoring_Controller_d_B.andorMethod_jr;

  /* MinMax: '<S79>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/small'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ig;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ig;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ig;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ig;
    vRRR_COG = Torque_Vectoring_Controller_d_P.small_Value_ak[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_ig;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_bu[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S79>/impMethod' */

  /* MinMax: '<S80>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_m;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_o1 = PmaxTyre;

  /* End of MinMax: '<S80>/andorMethod' */

  /* Product: '<S80>/Weighting' incorporates:
   *  Constant: '<S80>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_kh =
    Torque_Vectoring_Controller_d_P.Weight_Value_czv *
    Torque_Vectoring_Controller_d_B.andorMethod_o1;

  /* MinMax: '<S80>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_kh;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_dx[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S80>/impMethod' */

  /* MinMax: '<S82>/andorMethod' */
  u0 = Torque_Vectoring_Controller_d_B.Merge_ov;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Merge_h;
  PmaxTyre = u0;
  if (!((PmaxTyre <= vRRR_COG) || rtIsNaN(vRRR_COG))) {
    PmaxTyre = vRRR_COG;
  }

  Torque_Vectoring_Controller_d_B.andorMethod_h5 = PmaxTyre;

  /* End of MinMax: '<S82>/andorMethod' */

  /* Product: '<S82>/Weighting' incorporates:
   *  Constant: '<S82>/Weight'
   */
  Torque_Vectoring_Controller_d_B.Weighting_cv =
    Torque_Vectoring_Controller_d_P.Weight_Value_i1 *
    Torque_Vectoring_Controller_d_B.andorMethod_h5;

  /* MinMax: '<S82>/impMethod' incorporates:
   *  Constant: '<S92>/zero'
   *  Constant: '<S93>/zero'
   *  Constant: '<S94>/zero'
   *  Constant: '<S95>/zero'
   *  Constant: '<S96>/big'
   */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.Weighting_cv;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_e[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_cv;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 101] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_cv;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_i[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 202] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_cv;
    vRRR_COG = Torque_Vectoring_Controller_d_P.zero_Value_p[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 303] = vRRR_COG;
    u0 = Torque_Vectoring_Controller_d_B.Weighting_cv;
    vRRR_COG = Torque_Vectoring_Controller_d_P.big_Value_j[i];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller_d_B.minV[i + 404] = vRRR_COG;
  }

  memcpy(&Torque_Vectoring_Controller_d_B.impMethod_oh[0],
         &Torque_Vectoring_Controller_d_B.minV[0], 505U * sizeof(real_T));

  /* End of MinMax: '<S82>/impMethod' */

  /* MinMax: '<S42>/AggMethod1' */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.impMethod[i];
    vRRR_COG = Torque_Vectoring_Controller_d_B.impMethod_a[i];
    if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_l[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_n[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_g[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_e[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_o[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_b[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ox[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_f[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_no[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_h[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_d[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fm[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ou[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oa[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i5[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_iy[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ec[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_k[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fh[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bl[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bb[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_la[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ds[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_m[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lh[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_j[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ji[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c2[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_hg[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_at[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_eq[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lai[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_atx[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bu[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_dx[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oh[i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    Torque_Vectoring_Controller_d_B.AggMethod1[i] = vRRR_COG;
  }

  /* End of MinMax: '<S42>/AggMethod1' */

  /* Sum: '<S43>/Sum1' */
  PmaxTyre = Torque_Vectoring_Controller_d_B.AggMethod1[0];
  for (i = 0; i < 100; i++) {
    ixstart = i + 1;
    PmaxTyre += Torque_Vectoring_Controller_d_B.AggMethod1[ixstart];
  }

  Torque_Vectoring_Controller_d_B.Sum1 = PmaxTyre;

  /* End of Sum: '<S43>/Sum1' */

  /* If: '<S43>/If' */
  if (Torque_Vectoring_Controller_d_B.Sum1 <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S43>/Action: One' incorporates:
     *  ActionPort: '<S98>/Action Port'
     */
    Torque_Vectoring_Cont_ActionOne(&Torque_Vectoring_Controller_d_B.Merge_f1,
      (P_ActionOne_Torque_Vectoring__T *)
      &Torque_Vectoring_Controller_d_P.ActionOne);

    /* End of Outputs for SubSystem: '<S43>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S43>/Action: u1' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    Torque_Vectoring_Contr_Actionu1(Torque_Vectoring_Controller_d_B.Sum1,
      &Torque_Vectoring_Controller_d_B.Merge_f1);

    /* End of Outputs for SubSystem: '<S43>/Action: u1' */
  }

  /* End of If: '<S43>/If' */

  /* MinMax: '<S42>/AggMethod2' */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.impMethod[i + 101];
    vRRR_COG = Torque_Vectoring_Controller_d_B.impMethod_a[i + 101];
    if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_l[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_n[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_g[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_e[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_o[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_b[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ox[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_f[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_no[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_h[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_d[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fm[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ou[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oa[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i5[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_iy[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ec[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_k[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fh[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bl[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bb[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_la[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ds[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_m[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lh[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_j[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ji[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c2[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_hg[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_at[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_eq[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lai[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_atx[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bu[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_dx[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oh[101 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    Torque_Vectoring_Controller_d_B.AggMethod2[i] = vRRR_COG;
  }

  /* End of MinMax: '<S42>/AggMethod2' */

  /* Sum: '<S44>/Sum1' */
  PmaxTyre = Torque_Vectoring_Controller_d_B.AggMethod2[0];
  for (i = 0; i < 100; i++) {
    ixstart = i + 1;
    PmaxTyre += Torque_Vectoring_Controller_d_B.AggMethod2[ixstart];
  }

  Torque_Vectoring_Controller_d_B.Sum1_c = PmaxTyre;

  /* End of Sum: '<S44>/Sum1' */

  /* If: '<S44>/If' */
  if (Torque_Vectoring_Controller_d_B.Sum1_c <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S44>/Action: One' incorporates:
     *  ActionPort: '<S100>/Action Port'
     */
    Torque_Vectoring_Cont_ActionOne(&Torque_Vectoring_Controller_d_B.Merge_lt,
      (P_ActionOne_Torque_Vectoring__T *)
      &Torque_Vectoring_Controller_d_P.ActionOne_c);

    /* End of Outputs for SubSystem: '<S44>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S44>/Action: u1' incorporates:
     *  ActionPort: '<S101>/Action Port'
     */
    Torque_Vectoring_Contr_Actionu1(Torque_Vectoring_Controller_d_B.Sum1_c,
      &Torque_Vectoring_Controller_d_B.Merge_lt);

    /* End of Outputs for SubSystem: '<S44>/Action: u1' */
  }

  /* End of If: '<S44>/If' */

  /* MinMax: '<S42>/AggMethod3' */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.impMethod[i + 202];
    vRRR_COG = Torque_Vectoring_Controller_d_B.impMethod_a[i + 202];
    if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_l[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_n[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_g[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_e[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_o[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_b[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ox[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_f[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_no[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_h[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_d[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fm[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ou[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oa[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i5[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_iy[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ec[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_k[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fh[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bl[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bb[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_la[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ds[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_m[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lh[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_j[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ji[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c2[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_hg[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_at[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_eq[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lai[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_atx[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bu[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_dx[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oh[202 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    Torque_Vectoring_Controller_d_B.AggMethod3[i] = vRRR_COG;
  }

  /* End of MinMax: '<S42>/AggMethod3' */

  /* Sum: '<S45>/Sum1' */
  PmaxTyre = Torque_Vectoring_Controller_d_B.AggMethod3[0];
  for (i = 0; i < 100; i++) {
    ixstart = i + 1;
    PmaxTyre += Torque_Vectoring_Controller_d_B.AggMethod3[ixstart];
  }

  Torque_Vectoring_Controller_d_B.Sum1_f = PmaxTyre;

  /* End of Sum: '<S45>/Sum1' */

  /* If: '<S45>/If' */
  if (Torque_Vectoring_Controller_d_B.Sum1_f <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S45>/Action: One' incorporates:
     *  ActionPort: '<S102>/Action Port'
     */
    Torque_Vectoring_Cont_ActionOne(&Torque_Vectoring_Controller_d_B.Merge_pz,
      (P_ActionOne_Torque_Vectoring__T *)
      &Torque_Vectoring_Controller_d_P.ActionOne_cn);

    /* End of Outputs for SubSystem: '<S45>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S45>/Action: u1' incorporates:
     *  ActionPort: '<S103>/Action Port'
     */
    Torque_Vectoring_Contr_Actionu1(Torque_Vectoring_Controller_d_B.Sum1_f,
      &Torque_Vectoring_Controller_d_B.Merge_pz);

    /* End of Outputs for SubSystem: '<S45>/Action: u1' */
  }

  /* End of If: '<S45>/If' */

  /* MinMax: '<S42>/AggMethod4' */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.impMethod[i + 303];
    vRRR_COG = Torque_Vectoring_Controller_d_B.impMethod_a[i + 303];
    if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_l[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_n[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_g[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_e[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_o[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_b[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ox[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_f[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_no[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_h[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_d[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fm[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ou[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oa[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i5[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_iy[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ec[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_k[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fh[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bl[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bb[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_la[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ds[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_m[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lh[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_j[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ji[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c2[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_hg[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_at[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_eq[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lai[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_atx[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bu[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_dx[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oh[303 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    Torque_Vectoring_Controller_d_B.AggMethod4[i] = vRRR_COG;
  }

  /* End of MinMax: '<S42>/AggMethod4' */

  /* Sum: '<S46>/Sum1' */
  PmaxTyre = Torque_Vectoring_Controller_d_B.AggMethod4[0];
  for (i = 0; i < 100; i++) {
    ixstart = i + 1;
    PmaxTyre += Torque_Vectoring_Controller_d_B.AggMethod4[ixstart];
  }

  Torque_Vectoring_Controller_d_B.Sum1_ct = PmaxTyre;

  /* End of Sum: '<S46>/Sum1' */

  /* If: '<S46>/If' */
  if (Torque_Vectoring_Controller_d_B.Sum1_ct <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S46>/Action: One' incorporates:
     *  ActionPort: '<S104>/Action Port'
     */
    Torque_Vectoring_Cont_ActionOne(&Torque_Vectoring_Controller_d_B.Merge_ca,
      (P_ActionOne_Torque_Vectoring__T *)
      &Torque_Vectoring_Controller_d_P.ActionOne_o);

    /* End of Outputs for SubSystem: '<S46>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S46>/Action: u1' incorporates:
     *  ActionPort: '<S105>/Action Port'
     */
    Torque_Vectoring_Contr_Actionu1(Torque_Vectoring_Controller_d_B.Sum1_ct,
      &Torque_Vectoring_Controller_d_B.Merge_ca);

    /* End of Outputs for SubSystem: '<S46>/Action: u1' */
  }

  /* End of If: '<S46>/If' */

  /* MinMax: '<S42>/AggMethod5' */
  for (i = 0; i < 101; i++) {
    u0 = Torque_Vectoring_Controller_d_B.impMethod[i + 404];
    vRRR_COG = Torque_Vectoring_Controller_d_B.impMethod_a[i + 404];
    if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_l[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_n[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_g[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_e[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_o[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_b[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ox[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_f[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_no[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_h[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_d[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fm[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ou[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oa[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_i5[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_iy[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ec[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_k[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_fh[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bl[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bb[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_la[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ds[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_m[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lh[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_j[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_ji[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_c2[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_hg[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_at[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_eq[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_lai[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_atx[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_bu[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_dx[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    c_idx_0 = Torque_Vectoring_Controller_d_B.impMethod_oh[404 + i];
    if (!((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0))) {
      vRRR_COG = c_idx_0;
    }

    Torque_Vectoring_Controller_d_B.AggMethod5[i] = vRRR_COG;
  }

  /* End of MinMax: '<S42>/AggMethod5' */

  /* Sum: '<S47>/Sum1' */
  PmaxTyre = Torque_Vectoring_Controller_d_B.AggMethod5[0];
  for (i = 0; i < 100; i++) {
    ixstart = i + 1;
    PmaxTyre += Torque_Vectoring_Controller_d_B.AggMethod5[ixstart];
  }

  Torque_Vectoring_Controller_d_B.Sum1_p = PmaxTyre;

  /* End of Sum: '<S47>/Sum1' */

  /* If: '<S47>/If' */
  if (Torque_Vectoring_Controller_d_B.Sum1_p <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S47>/Action: One' incorporates:
     *  ActionPort: '<S106>/Action Port'
     */
    Torque_Vectoring_Cont_ActionOne(&Torque_Vectoring_Controller_d_B.Merge_ca4,
      (P_ActionOne_Torque_Vectoring__T *)
      &Torque_Vectoring_Controller_d_P.ActionOne_c4);

    /* End of Outputs for SubSystem: '<S47>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S47>/Action: u1' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    Torque_Vectoring_Contr_Actionu1(Torque_Vectoring_Controller_d_B.Sum1_p,
      &Torque_Vectoring_Controller_d_B.Merge_ca4);

    /* End of Outputs for SubSystem: '<S47>/Action: u1' */
  }

  /* End of If: '<S47>/If' */

  /* Sum: '<S42>/Total Firing Strength' */
  Torque_Vectoring_Controller_d_B.TotalFiringStrength =
    ((((((((((((((((((((((((((((((((((((((Torque_Vectoring_Controller_d_B.Weighting
    + Torque_Vectoring_Controller_d_B.Weighting_g) +
    Torque_Vectoring_Controller_d_B.Weighting_k) +
    Torque_Vectoring_Controller_d_B.Weighting_b) +
    Torque_Vectoring_Controller_d_B.Weighting_p) +
    Torque_Vectoring_Controller_d_B.Weighting_pe) +
    Torque_Vectoring_Controller_d_B.Weighting_c) +
    Torque_Vectoring_Controller_d_B.Weighting_ch) +
    Torque_Vectoring_Controller_d_B.Weighting_bn) +
    Torque_Vectoring_Controller_d_B.Weighting_f) +
    Torque_Vectoring_Controller_d_B.Weighting_h) +
    Torque_Vectoring_Controller_d_B.Weighting_a) +
    Torque_Vectoring_Controller_d_B.Weighting_gu) +
    Torque_Vectoring_Controller_d_B.Weighting_h4) +
    Torque_Vectoring_Controller_d_B.Weighting_d) +
    Torque_Vectoring_Controller_d_B.Weighting_k2) +
    Torque_Vectoring_Controller_d_B.Weighting_ca) +
    Torque_Vectoring_Controller_d_B.Weighting_fo) +
    Torque_Vectoring_Controller_d_B.Weighting_o) +
    Torque_Vectoring_Controller_d_B.Weighting_i) +
                       Torque_Vectoring_Controller_d_B.Weighting_pj) +
                      Torque_Vectoring_Controller_d_B.Weighting_kq) +
                     Torque_Vectoring_Controller_d_B.Weighting_ov) +
                    Torque_Vectoring_Controller_d_B.Weighting_e) +
                   Torque_Vectoring_Controller_d_B.Weighting_p3) +
                  Torque_Vectoring_Controller_d_B.Weighting_n) +
                 Torque_Vectoring_Controller_d_B.Weighting_bb) +
                Torque_Vectoring_Controller_d_B.Weighting_ow) +
               Torque_Vectoring_Controller_d_B.Weighting_ev) +
              Torque_Vectoring_Controller_d_B.Weighting_ed) +
             Torque_Vectoring_Controller_d_B.Weighting_gb) +
            Torque_Vectoring_Controller_d_B.Weighting_j) +
           Torque_Vectoring_Controller_d_B.Weighting_bg) +
          Torque_Vectoring_Controller_d_B.Weighting_oh) +
         Torque_Vectoring_Controller_d_B.Weighting_pg) +
        Torque_Vectoring_Controller_d_B.Weighting_fw) +
       Torque_Vectoring_Controller_d_B.Weighting_fl) +
      Torque_Vectoring_Controller_d_B.Weighting_ig) +
     Torque_Vectoring_Controller_d_B.Weighting_kh) +
    Torque_Vectoring_Controller_d_B.Weighting_cv;

  /* RelationalOperator: '<S42>/Zero Firing Strength?' incorporates:
   *  Constant: '<S42>/Zero'
   */
  Torque_Vectoring_Controller_d_B.ZeroFiringStrength =
    (Torque_Vectoring_Controller_d_B.TotalFiringStrength >
     Torque_Vectoring_Controller_d_P.Zero_Value);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/MidRange'
   */
  if (Torque_Vectoring_Controller_d_B.ZeroFiringStrength >=
      Torque_Vectoring_Controller_d_P.Switch_Threshold) {
    /* Product: '<S43>/Product (COA)' incorporates:
     *  Constant: '<S43>/x data'
     */
    for (i = 0; i < 101; i++) {
      Torque_Vectoring_Controller_d_B.ProductCOA[i] =
        Torque_Vectoring_Controller_d_P.xdata_Value[i] *
        Torque_Vectoring_Controller_d_B.AggMethod1[i];
    }

    /* End of Product: '<S43>/Product (COA)' */

    /* Sum: '<S43>/Sum' */
    PmaxTyre = Torque_Vectoring_Controller_d_B.ProductCOA[0];
    for (i = 0; i < 100; i++) {
      ixstart = i + 1;
      PmaxTyre += Torque_Vectoring_Controller_d_B.ProductCOA[ixstart];
    }

    Torque_Vectoring_Controller_d_B.Sum = PmaxTyre;

    /* End of Sum: '<S43>/Sum' */

    /* Product: '<S43>/Averaging (COA)' */
    Torque_Vectoring_Controller_d_B.AveragingCOA =
      Torque_Vectoring_Controller_d_B.Sum /
      Torque_Vectoring_Controller_d_B.Merge_f1;

    /* Product: '<S44>/Product (COA)' incorporates:
     *  Constant: '<S44>/x data'
     */
    for (i = 0; i < 101; i++) {
      Torque_Vectoring_Controller_d_B.ProductCOA_a[i] =
        Torque_Vectoring_Controller_d_P.xdata_Value_p[i] *
        Torque_Vectoring_Controller_d_B.AggMethod2[i];
    }

    /* End of Product: '<S44>/Product (COA)' */

    /* Sum: '<S44>/Sum' */
    PmaxTyre = Torque_Vectoring_Controller_d_B.ProductCOA_a[0];
    for (i = 0; i < 100; i++) {
      ixstart = i + 1;
      PmaxTyre += Torque_Vectoring_Controller_d_B.ProductCOA_a[ixstart];
    }

    Torque_Vectoring_Controller_d_B.Sum_h = PmaxTyre;

    /* End of Sum: '<S44>/Sum' */

    /* Product: '<S44>/Averaging (COA)' */
    Torque_Vectoring_Controller_d_B.AveragingCOA_f =
      Torque_Vectoring_Controller_d_B.Sum_h /
      Torque_Vectoring_Controller_d_B.Merge_lt;

    /* Product: '<S45>/Product (COA)' incorporates:
     *  Constant: '<S45>/x data'
     */
    for (i = 0; i < 101; i++) {
      Torque_Vectoring_Controller_d_B.ProductCOA_h[i] =
        Torque_Vectoring_Controller_d_P.xdata_Value_f[i] *
        Torque_Vectoring_Controller_d_B.AggMethod3[i];
    }

    /* End of Product: '<S45>/Product (COA)' */

    /* Sum: '<S45>/Sum' */
    PmaxTyre = Torque_Vectoring_Controller_d_B.ProductCOA_h[0];
    for (i = 0; i < 100; i++) {
      ixstart = i + 1;
      PmaxTyre += Torque_Vectoring_Controller_d_B.ProductCOA_h[ixstart];
    }

    Torque_Vectoring_Controller_d_B.Sum_n = PmaxTyre;

    /* End of Sum: '<S45>/Sum' */

    /* Product: '<S45>/Averaging (COA)' */
    Torque_Vectoring_Controller_d_B.AveragingCOA_l =
      Torque_Vectoring_Controller_d_B.Sum_n /
      Torque_Vectoring_Controller_d_B.Merge_pz;

    /* Product: '<S46>/Product (COA)' incorporates:
     *  Constant: '<S46>/x data'
     */
    for (i = 0; i < 101; i++) {
      Torque_Vectoring_Controller_d_B.ProductCOA_d[i] =
        Torque_Vectoring_Controller_d_P.xdata_Value_g[i] *
        Torque_Vectoring_Controller_d_B.AggMethod4[i];
    }

    /* End of Product: '<S46>/Product (COA)' */

    /* Sum: '<S46>/Sum' */
    PmaxTyre = Torque_Vectoring_Controller_d_B.ProductCOA_d[0];
    for (i = 0; i < 100; i++) {
      ixstart = i + 1;
      PmaxTyre += Torque_Vectoring_Controller_d_B.ProductCOA_d[ixstart];
    }

    Torque_Vectoring_Controller_d_B.Sum_hi = PmaxTyre;

    /* End of Sum: '<S46>/Sum' */

    /* Product: '<S46>/Averaging (COA)' */
    Torque_Vectoring_Controller_d_B.AveragingCOA_h =
      Torque_Vectoring_Controller_d_B.Sum_hi /
      Torque_Vectoring_Controller_d_B.Merge_ca;

    /* Product: '<S47>/Product (COA)' incorporates:
     *  Constant: '<S47>/x data'
     */
    for (i = 0; i < 101; i++) {
      Torque_Vectoring_Controller_d_B.ProductCOA_k[i] =
        Torque_Vectoring_Controller_d_P.xdata_Value_j[i] *
        Torque_Vectoring_Controller_d_B.AggMethod5[i];
    }

    /* End of Product: '<S47>/Product (COA)' */

    /* Sum: '<S47>/Sum' */
    PmaxTyre = Torque_Vectoring_Controller_d_B.ProductCOA_k[0];
    for (i = 0; i < 100; i++) {
      ixstart = i + 1;
      PmaxTyre += Torque_Vectoring_Controller_d_B.ProductCOA_k[ixstart];
    }

    Torque_Vectoring_Controller_d_B.Sum_h1 = PmaxTyre;

    /* End of Sum: '<S47>/Sum' */

    /* Product: '<S47>/Averaging (COA)' */
    Torque_Vectoring_Controller_d_B.AveragingCOA_e =
      Torque_Vectoring_Controller_d_B.Sum_h1 /
      Torque_Vectoring_Controller_d_B.Merge_ca4;
    Torque_Vectoring_Controller_d_B.Switch[0] =
      Torque_Vectoring_Controller_d_B.AveragingCOA;
    Torque_Vectoring_Controller_d_B.Switch[1] =
      Torque_Vectoring_Controller_d_B.AveragingCOA_f;
    Torque_Vectoring_Controller_d_B.Switch[2] =
      Torque_Vectoring_Controller_d_B.AveragingCOA_l;
    Torque_Vectoring_Controller_d_B.Switch[3] =
      Torque_Vectoring_Controller_d_B.AveragingCOA_h;
    Torque_Vectoring_Controller_d_B.Switch[4] =
      Torque_Vectoring_Controller_d_B.AveragingCOA_e;
  } else {
    for (i = 0; i < 5; i++) {
      Torque_Vectoring_Controller_d_B.Switch[i] =
        Torque_Vectoring_Controller_d_P.MidRange_Value[i];
    }
  }

  /* End of Switch: '<S42>/Switch' */

  /* MATLAB Function: '<S32>/FuzzyVelicityGenerator' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Velocity Estimator/Fuzzy Velocity/FuzzyVelicityGenerator': '<S39>:1' */
  /* '<S39>:1:5' */
  /* '<S39>:1:8' */
  /* '<S39>:1:11' */
  /* '<S39>:1:14' */
  /* '<S39>:1:17' */
  /* '<S39>:1:20' */
  /* '<S39>:1:22' */
  limit[0] = ((Torque_Vectoring_Controller_d_P.car.tw / 2.0 -
               Torque_Vectoring_Controller_d_P.car.lf * 0.0) *
              Torque_Vectoring_Controller_d_B.sensors.yawRate +
              Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0] *
              Torque_Vectoring_Controller_d_P.car.tireRadius) * cos
    (Torque_Vectoring_Controller_d_B.sensors.wheelAngles[0]) *
    Torque_Vectoring_Controller_d_B.Switch[0];
  limit[1] = (Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1] *
              Torque_Vectoring_Controller_d_P.car.tireRadius -
              (Torque_Vectoring_Controller_d_P.car.tw / 2.0 +
               Torque_Vectoring_Controller_d_P.car.lf * 0.0) *
              Torque_Vectoring_Controller_d_B.sensors.yawRate) * cos
    (Torque_Vectoring_Controller_d_B.sensors.wheelAngles[1]) *
    Torque_Vectoring_Controller_d_B.Switch[1];
  limit[2] = ((Torque_Vectoring_Controller_d_P.car.tw / 2.0 +
               Torque_Vectoring_Controller_d_P.car.lr * 0.0) *
              Torque_Vectoring_Controller_d_B.sensors.yawRate +
              Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2] *
              Torque_Vectoring_Controller_d_P.car.tireRadius) *
    Torque_Vectoring_Controller_d_B.Switch[2];
  limit[3] = (Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3] *
              Torque_Vectoring_Controller_d_P.car.tireRadius -
              (Torque_Vectoring_Controller_d_P.car.tw / 2.0 -
               Torque_Vectoring_Controller_d_P.car.lr * 0.0) *
              Torque_Vectoring_Controller_d_B.sensors.yawRate) *
    Torque_Vectoring_Controller_d_B.Switch[3];
  vRRL_COG = limit[0];
  vRRL_COG += limit[1];
  vRRL_COG += limit[2];
  vRRL_COG += limit[3];
  Torque_Vectoring_Controller_d_B.vFuzzy =
    ((Torque_Vectoring_Controller_d_P.car.dt *
      Torque_Vectoring_Controller_d_B.sensors.ax +
      Torque_Vectoring_Controller__DW.vFuzzyPrev) *
     Torque_Vectoring_Controller_d_B.Switch[4] + vRRL_COG) /
    ((((Torque_Vectoring_Controller_d_B.Switch[0] +
        Torque_Vectoring_Controller_d_B.Switch[1]) +
       Torque_Vectoring_Controller_d_B.Switch[2]) +
      Torque_Vectoring_Controller_d_B.Switch[3]) +
     Torque_Vectoring_Controller_d_B.Switch[4]);

  /* '<S39>:1:25' */
  Torque_Vectoring_Controller__DW.vFuzzyPrev =
    Torque_Vectoring_Controller_d_B.vFuzzy;

  /* MATLAB Function: '<S30>/MATLAB Function' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Velocity Estimator/MATLAB Function': '<S34>:1' */
  /* '<S34>:1:4' */
  Torque_Vectoring_Controller_d_B.v = Torque_Vectoring_Controller_d_B.vFuzzy;

  /* Memory: '<S8>/Memory' */
  Torque_Vectoring_Controller_d_B.Memory =
    Torque_Vectoring_Controller__DW.Memory_PreviousInput;

  /* Memory: '<S8>/Memory3' */
  Torque_Vectoring_Controller_d_B.Memory3 =
    Torque_Vectoring_Controller__DW.Memory3_PreviousInput;

  /* MATLAB Function: '<S8>/Aerodynamic forces' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Aerodynamic forces': '<S22>:1' */
  /*  === from dataCar.m === */
  /*  car.Cl = 3.84;      %[-]   %Lift coefficient */
  /*  car.Cd = 1.44;      %[-]   %Drag coefficient */
  /*  car.AFront = 1.3;   %[m^2] %Frontal area */
  /*  car.rhoAir = 1.225; %[kg/m^3] %air density */
  /* '<S22>:1:9' */
  Torque_Vectoring_Controller_d_B.aero.FD = 0.5 *
    Torque_Vectoring_Controller_d_P.car.Cd *
    Torque_Vectoring_Controller_d_P.car.AFront *
    Torque_Vectoring_Controller_d_P.car.rhoAir *
    (Torque_Vectoring_Controller_d_B.Memory3 *
     Torque_Vectoring_Controller_d_B.Memory3);

  /* drag force, pointing rearward [N] */
  /* '<S22>:1:10' */
  Torque_Vectoring_Controller_d_B.aero.FL = 0.5 *
    Torque_Vectoring_Controller_d_P.car.Cl *
    Torque_Vectoring_Controller_d_P.car.AFront *
    Torque_Vectoring_Controller_d_P.car.rhoAir *
    (Torque_Vectoring_Controller_d_B.Memory3 *
     Torque_Vectoring_Controller_d_B.Memory3);

  /* lift force, pointing upward [N] */
  /* '<S22>:1:11' */
  /* distance from the COG to the point of application of the drag [m] */
  /* '<S22>:1:12' */
  Torque_Vectoring_Controller_d_B.aero.lever_FD[0] = -0.1;
  Torque_Vectoring_Controller_d_B.aero.lever_FL[0] = -0.1;
  Torque_Vectoring_Controller_d_B.aero.lever_FD[1] = 0.1;
  Torque_Vectoring_Controller_d_B.aero.lever_FL[1] = 0.1;

  /* MATLAB Function: '<S8>/Fz Estimator ' */
  /* distance from the COG to the point of application of the lift [m] */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Fz Estimator ': '<S27>:1' */
  /* Dynamical loads  */
  /* Without taking suspension into account */
  /* '<S27>:1:7' */
  PmaxTyre = ((Torque_Vectoring_Controller_d_P.car.g *
               Torque_Vectoring_Controller_d_P.car.mass *
               Torque_Vectoring_Controller_d_P.car.lr /
               Torque_Vectoring_Controller_d_P.car.wb -
               Torque_Vectoring_Controller_d_P.car.h /
               Torque_Vectoring_Controller_d_P.car.wb *
               (Torque_Vectoring_Controller_d_P.car.mass *
                Torque_Vectoring_Controller_d_B.sensors.ax)) -
              (Torque_Vectoring_Controller_d_P.car.h +
               Torque_Vectoring_Controller_d_B.aero.lever_FD[1]) /
              Torque_Vectoring_Controller_d_P.car.wb *
              Torque_Vectoring_Controller_d_B.aero.FD) -
    (Torque_Vectoring_Controller_d_P.car.lr -
     Torque_Vectoring_Controller_d_B.aero.lever_FL[0]) /
    Torque_Vectoring_Controller_d_P.car.wb *
    Torque_Vectoring_Controller_d_B.aero.FL;

  /* dyn load Front Axle */
  /* '<S27>:1:8' */
  vRFR_COG = ((Torque_Vectoring_Controller_d_P.car.g *
               Torque_Vectoring_Controller_d_P.car.mass *
               Torque_Vectoring_Controller_d_P.car.lf /
               Torque_Vectoring_Controller_d_P.car.wb +
               Torque_Vectoring_Controller_d_P.car.h /
               Torque_Vectoring_Controller_d_P.car.wb *
               (Torque_Vectoring_Controller_d_P.car.mass *
                Torque_Vectoring_Controller_d_B.sensors.ax)) +
              (Torque_Vectoring_Controller_d_P.car.h +
               Torque_Vectoring_Controller_d_B.aero.lever_FD[1]) /
              Torque_Vectoring_Controller_d_P.car.wb *
              Torque_Vectoring_Controller_d_B.aero.FD) -
    (Torque_Vectoring_Controller_d_P.car.lf +
     Torque_Vectoring_Controller_d_B.aero.lever_FL[0]) /
    Torque_Vectoring_Controller_d_P.car.wb *
    Torque_Vectoring_Controller_d_B.aero.FL;

  /* dyn load Rear Axle */
  /* '<S27>:1:11' */
  /* '<S27>:1:12' */
  /* '<S27>:1:13' */
  /* '<S27>:1:14' */
  /* '<S27>:1:17' */
  Torque_Vectoring_Controller_d_B.Fzi[0] = PmaxTyre / 2.0 -
    Torque_Vectoring_Controller_d_P.car.h / (2.0 *
    Torque_Vectoring_Controller_d_P.car.tw) *
    (Torque_Vectoring_Controller_d_P.car.mass *
     Torque_Vectoring_Controller_d_B.sensors.ay);
  Torque_Vectoring_Controller_d_B.Fzi[1] = Torque_Vectoring_Controller_d_P.car.h
    / (2.0 * Torque_Vectoring_Controller_d_P.car.tw) *
    (Torque_Vectoring_Controller_d_P.car.mass *
     Torque_Vectoring_Controller_d_B.sensors.ay) + PmaxTyre / 2.0;
  Torque_Vectoring_Controller_d_B.Fzi[2] = vRFR_COG / 2.0 -
    Torque_Vectoring_Controller_d_P.car.h / (2.0 *
    Torque_Vectoring_Controller_d_P.car.tw) *
    (Torque_Vectoring_Controller_d_P.car.mass *
     Torque_Vectoring_Controller_d_B.sensors.ay);
  Torque_Vectoring_Controller_d_B.Fzi[3] = Torque_Vectoring_Controller_d_P.car.h
    / (2.0 * Torque_Vectoring_Controller_d_P.car.tw) *
    (Torque_Vectoring_Controller_d_P.car.mass *
     Torque_Vectoring_Controller_d_B.sensors.ay) + vRFR_COG / 2.0;

  /* Memory: '<S8>/Memory1' */
  Torque_Vectoring_Controller_d_B.Memory1_o =
    Torque_Vectoring_Controller__DW.Memory1_PreviousInput_c;

  /* MATLAB Function: '<S8>/Fx Estimator ' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Fx Estimator ': '<S25>:1' */
  /* OPM: gearratio zit al verwerkt in sensors.torque (= wheelTorque) */
  if (!Torque_Vectoring_Controller__DW.inertia_not_empty) {
    /* '<S25>:1:5' */
    Torque_Vectoring_Controller__DW.inertia =
      Torque_Vectoring_Controller_d_P.car.tireInertia;
    Torque_Vectoring_Controller__DW.inertia_not_empty = true;
  }

  /* '<S25>:1:7' */
  /* '<S25>:1:8' */
  /* wheelTorque = car.gearRatio*sensors.torque -(car.motor.Inertia*car.gearRatio^2 - car.tireInertia)*alpha; */
  /* to be used if only motor torque is known (real scenario) */
  /* Fxi_est = (wheelTorque - alpha*inertia)/car.tireRadius; */
  /* '<S25>:1:14' */
  /* Fxi_est = (sensors.torque)/car.tireRadius; */
  /* '<S25>:1:18' */
  /* '<S25>:1:23' */
  Torque_Vectoring_Controller_d_B.alpha[0] =
    (Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0] -
     Torque_Vectoring_Controller__DW.wheelspeedPrev[0]) /
    Torque_Vectoring_Controller_d_P.car.dt;
  Torque_Vectoring_Controller_d_B.Fxi[0] =
    (Torque_Vectoring_Controller_d_B.sensors.torque[0] -
     Torque_Vectoring_Controller_d_B.alpha[0] *
     Torque_Vectoring_Controller__DW.inertia) /
    Torque_Vectoring_Controller_d_P.car.tireRadius;
  Torque_Vectoring_Controller__DW.wheelspeedPrev[0] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0];
  Torque_Vectoring_Controller_d_B.alpha[1] =
    (Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1] -
     Torque_Vectoring_Controller__DW.wheelspeedPrev[1]) /
    Torque_Vectoring_Controller_d_P.car.dt;
  Torque_Vectoring_Controller_d_B.Fxi[1] =
    (Torque_Vectoring_Controller_d_B.sensors.torque[1] -
     Torque_Vectoring_Controller_d_B.alpha[1] *
     Torque_Vectoring_Controller__DW.inertia) /
    Torque_Vectoring_Controller_d_P.car.tireRadius;
  Torque_Vectoring_Controller__DW.wheelspeedPrev[1] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1];
  Torque_Vectoring_Controller_d_B.alpha[2] =
    (Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2] -
     Torque_Vectoring_Controller__DW.wheelspeedPrev[2]) /
    Torque_Vectoring_Controller_d_P.car.dt;
  Torque_Vectoring_Controller_d_B.Fxi[2] =
    (Torque_Vectoring_Controller_d_B.sensors.torque[2] -
     Torque_Vectoring_Controller_d_B.alpha[2] *
     Torque_Vectoring_Controller__DW.inertia) /
    Torque_Vectoring_Controller_d_P.car.tireRadius;
  Torque_Vectoring_Controller__DW.wheelspeedPrev[2] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2];
  Torque_Vectoring_Controller_d_B.alpha[3] =
    (Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3] -
     Torque_Vectoring_Controller__DW.wheelspeedPrev[3]) /
    Torque_Vectoring_Controller_d_P.car.dt;
  Torque_Vectoring_Controller_d_B.Fxi[3] =
    (Torque_Vectoring_Controller_d_B.sensors.torque[3] -
     Torque_Vectoring_Controller_d_B.alpha[3] *
     Torque_Vectoring_Controller__DW.inertia) /
    Torque_Vectoring_Controller_d_P.car.tireRadius;
  Torque_Vectoring_Controller__DW.wheelspeedPrev[3] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3];

  /* '<S25>:1:24' */
  Torque_Vectoring_Controller_d_B.inertiaOut =
    Torque_Vectoring_Controller__DW.inertia;

  /* End of MATLAB Function: '<S8>/Fx Estimator ' */

  /* MATLAB Function: '<S8>/Fy Estimator ' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Fy Estimator ': '<S26>:1' */
  /* '<S26>:1:39' */
  /* '<S26>:1:38' */
  if (!Torque_Vectoring_Controller__DW.yawRatePrev_not_empty) {
    /* '<S26>:1:4' */
    Torque_Vectoring_Controller__DW.yawRatePrev =
      Torque_Vectoring_Controller_d_B.sensors.yawRate;
    Torque_Vectoring_Controller__DW.yawRatePrev_not_empty = true;
  }

  if (!Torque_Vectoring_Controller__DW.FzRatioFront_not_empty) {
    /* '<S26>:1:8' */
    Torque_Vectoring_Controller__DW.FzRatioFront_not_empty = true;
  }

  if (!Torque_Vectoring_Controller__DW.FzRatioRear_not_empty) {
    /* '<S26>:1:9' */
    Torque_Vectoring_Controller__DW.FzRatioRear_not_empty = true;
  }

  /* '<S26>:1:13' */
  /* '<S26>:1:15' */
  PmaxTyre = (Torque_Vectoring_Controller_d_B.sensors.wheelAngles[0] +
              Torque_Vectoring_Controller_d_B.sensors.wheelAngles[1]) / 2.0;

  /* Calculate contributions to the moment from lateral forces through the */
  /* total yaw moment and moment of the longitudinal forces. */
  /* '<S26>:1:19' */
  /* '<S26>:1:20' */
  /* '<S26>:1:23' */
  /* Distribution of lateral force on front and rear axle */
  /* NOTE %sin(steerinAngle) deel wordt momenteel verwaarloosd */
  /*      %--> FyFR - FyFL =~ 0 */
  /* '<S26>:1:28' */
  vRFR_COG = Torque_Vectoring_Controller_d_P.car.mass *
    Torque_Vectoring_Controller_d_B.sensors.ay;

  /* '<S26>:1:29' */
  PmaxTyre = (cos(PmaxTyre) * Torque_Vectoring_Controller_d_P.car.lf * vRFR_COG
              - ((Torque_Vectoring_Controller_d_B.sensors.yawRate -
                  Torque_Vectoring_Controller__DW.yawRatePrev) *
                 Torque_Vectoring_Controller_d_P.car.fECU *
                 Torque_Vectoring_Controller_d_P.car.yawInertia -
                 ((Torque_Vectoring_Controller_d_P.car.tw / 2.0 * cos(PmaxTyre) *
                   (Torque_Vectoring_Controller_d_B.Fxi[0] -
                    Torque_Vectoring_Controller_d_B.Fxi[1]) +
                   Torque_Vectoring_Controller_d_P.car.lf * sin(PmaxTyre) *
                   (Torque_Vectoring_Controller_d_B.Fxi[0] +
                    Torque_Vectoring_Controller_d_B.Fxi[1])) +
                  Torque_Vectoring_Controller_d_P.car.tw / 2.0 *
                  (Torque_Vectoring_Controller_d_B.Fxi[2] -
                   Torque_Vectoring_Controller_d_B.Fxi[3])))) / (cos(PmaxTyre) *
    Torque_Vectoring_Controller_d_P.car.lf +
    Torque_Vectoring_Controller_d_P.car.lr);

  /* '<S26>:1:31' */
  vRFR_COG -= PmaxTyre;

  /* Distribution of lateral force on left and right tire by using the normal */
  /* force distribution. */
  /* Use of a scale factor  */
  /* '<S26>:1:38' */
  vRRL_COG = Torque_Vectoring_Controller_d_B.Fzi[0] +
    Torque_Vectoring_Controller_d_B.Fzi[1];
  u0 = Torque_Vectoring_Controller_d_B.Fzi[0] / vRRL_COG;
  vRRR_COG = Torque_Vectoring_Controller_d_B.Fzi[1] / vRRL_COG;

  /* '<S26>:1:38' */
  Torque_Vectoring_Controller__DW.FzRatioFront_not_empty = true;

  /* '<S26>:1:39' */
  vRRL_COG = Torque_Vectoring_Controller_d_B.Fzi[2] +
    Torque_Vectoring_Controller_d_B.Fzi[3];
  c_idx_0 = Torque_Vectoring_Controller_d_B.Fzi[2] / vRRL_COG;
  c_idx_1 = Torque_Vectoring_Controller_d_B.Fzi[3] / vRRL_COG;

  /* '<S26>:1:39' */
  Torque_Vectoring_Controller__DW.FzRatioRear_not_empty = true;

  /* '<S26>:1:43' */
  vRRL_COG = (u0 - vRRR_COG) *
    Torque_Vectoring_Controller_d_P.optPar.scaleFactorFy / 2.0;

  /* '<S26>:1:44' */
  /* '<S26>:1:45' */
  /* '<S26>:1:46' */
  vRRR_COG = (c_idx_0 - c_idx_1) *
    Torque_Vectoring_Controller_d_P.optPar.scaleFactorFy / 2.0;

  /* '<S26>:1:47' */
  /* '<S26>:1:48' */
  /* '<S26>:1:50' */
  Torque_Vectoring_Controller_d_B.Fyi[0] = vRFR_COG / 2.0 + vRRL_COG * vRFR_COG;
  Torque_Vectoring_Controller_d_B.Fyi[1] = vRFR_COG / 2.0 - vRRL_COG * vRFR_COG;
  Torque_Vectoring_Controller_d_B.Fyi[2] = PmaxTyre / 2.0 + vRRR_COG * PmaxTyre;
  Torque_Vectoring_Controller_d_B.Fyi[3] = PmaxTyre / 2.0 - vRRR_COG * PmaxTyre;

  /* '<S26>:1:52' */
  Torque_Vectoring_Controller__DW.yawRatePrev =
    Torque_Vectoring_Controller_d_B.sensors.yawRate;

  /* End of MATLAB Function: '<S8>/Fy Estimator ' */

  /* Memory: '<S8>/Memory2' */
  Torque_Vectoring_Controller_d_B.Memory2 =
    Torque_Vectoring_Controller__DW.Memory2_PreviousInput;

  /* MATLAB Function: '<S8>/Yaw Rate Reference' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Yaw Rate Reference': '<S31>:1' */
  /* Ackermann */
  /* '<S31>:1:4' */
  /* '<S31>:1:5' */
  Torque_Vectoring_Controller_d_B.rref =
    (Torque_Vectoring_Controller_d_B.sensors.wheelAngles[0] +
     Torque_Vectoring_Controller_d_B.sensors.wheelAngles[1]) / 2.0 *
    Torque_Vectoring_Controller_d_B.Memory2 /
    Torque_Vectoring_Controller_d_P.car.wb;

  /* Memory: '<S8>/Memory4' */
  /*   */
  /*  des_yaw_rate = vx*steering_angle / ... */
  /*      (L_f + L_r + ... */
  /*      m_chassis*vx^2*(L_r*(C_x_alpha_RL+C_x_alpha_RR)-L_f*(C_x_alpha_FL+C_x_alpha_FR))/... */
  /*      ((C_x_alpha_RL+C_x_alpha_RR)*(C_x_alpha_FL+C_x_alpha_FR)*L)); */
  Torque_Vectoring_Controller_d_B.Memory4 =
    Torque_Vectoring_Controller__DW.Memory4_PreviousInput;

  /* MATLAB Function: '<S8>/Mu&Slip Estimator' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Mu&Slip Estimator': '<S28>:1' */
  /* '<S28>:1:6' */
  /* '<S28>:1:16' */
  /* '<S28>:1:3' */
  PmaxTyre = Torque_Vectoring_Controller_d_B.sensors.yawRate;

  /* '<S28>:1:4' */
  dist[0] = Torque_Vectoring_Controller_d_P.car.lf;
  dist[3] = Torque_Vectoring_Controller_d_P.car.lf;
  dist[6] = -Torque_Vectoring_Controller_d_P.car.lr;
  dist[9] = -Torque_Vectoring_Controller_d_P.car.lr;
  dist[1] = Torque_Vectoring_Controller_d_P.car.tw / 2.0;
  dist[4] = -Torque_Vectoring_Controller_d_P.car.tw / 2.0;
  dist[7] = Torque_Vectoring_Controller_d_P.car.tw / 2.0;
  dist[10] = -Torque_Vectoring_Controller_d_P.car.tw / 2.0;

  /* '<S28>:1:9' */
  Torque_Vectoring_Controller_d_B.mu[0] = Torque_Vectoring_Controller_d_P.car.mu;
  Torque_Vectoring_Controller_d_B.mu[1] = Torque_Vectoring_Controller_d_P.car.mu;
  Torque_Vectoring_Controller_d_B.mu[2] = Torque_Vectoring_Controller_d_P.car.mu;
  Torque_Vectoring_Controller_d_B.mu[3] = Torque_Vectoring_Controller_d_P.car.mu;

  /* '<S28>:1:11' */
  /* '<S28>:1:13' */
  /* '<S28>:1:12' */
  /* '<S28>:1:15' */
  for (ixstart = 0; ixstart < 4; ixstart++) {
    dist[2 + 3 * ixstart] = 0.0;
    Torque_Vectoring_Controller_d_B.slip[ixstart] =
      Torque_Vectoring_Controller_d_B.sensors.wheelspeed[ixstart] *
      Torque_Vectoring_Controller_d_P.car.tireRadius;

    /* '<S28>:1:15' */
    /* '<S28>:1:16' */
    /* '<S28>:1:17' */
    vRFR_COG = Torque_Vectoring_Controller_d_B.Memory4;
    vRRL_COG = dist[3 * ixstart + 2] * 0.0 - dist[3 * ixstart + 1] * PmaxTyre;
    u0 = dist[3 * ixstart] * PmaxTyre - dist[3 * ixstart + 2] * 0.0;
    vRRR_COG = dist[3 * ixstart + 1] * 0.0 - dist[3 * ixstart] * 0.0;
    vWheel_m[3 * ixstart] = vRFR_COG + vRRL_COG;
    vWheel_m[1 + 3 * ixstart] = u0;
    vWheel_m[2 + 3 * ixstart] = vRRR_COG;

    /* '<S28>:1:18' */
    limit[ixstart] = sqrt(vWheel_m[3 * ixstart + 1] * vWheel_m[3 * ixstart + 1]
                          + vWheel_m[3 * ixstart] * vWheel_m[3 * ixstart]);

    /* '<S28>:1:15' */
  }

  /* state.slipRatio = (sensor.omegaiWheel * car.wheelRadius - wvi)./max((sensor.omegaiWheel * car.wheelRadius),1); */
  if (Torque_Vectoring_Controller_d_B.sensors.ax > 0.0) {
    /* '<S28>:1:23' */
    /* '<S28>:1:24' */
    Torque_Vectoring_Controller_d_B.slip[0] =
      (Torque_Vectoring_Controller_d_B.slip[0] - limit[0]) /
      Torque_Vectoring_Controller_d_B.slip[0];
    Torque_Vectoring_Controller_d_B.slip[1] =
      (Torque_Vectoring_Controller_d_B.slip[1] - limit[1]) /
      Torque_Vectoring_Controller_d_B.slip[1];
    Torque_Vectoring_Controller_d_B.slip[2] =
      (Torque_Vectoring_Controller_d_B.slip[2] - limit[2]) /
      Torque_Vectoring_Controller_d_B.slip[2];
    Torque_Vectoring_Controller_d_B.slip[3] =
      (Torque_Vectoring_Controller_d_B.slip[3] - limit[3]) /
      Torque_Vectoring_Controller_d_B.slip[3];
  } else if (Torque_Vectoring_Controller_d_B.sensors.ax < 0.0) {
    /* '<S28>:1:25' */
    /* '<S28>:1:26' */
    Torque_Vectoring_Controller_d_B.slip[0] =
      (Torque_Vectoring_Controller_d_B.slip[0] - limit[0]) / limit[0];
    Torque_Vectoring_Controller_d_B.slip[1] =
      (Torque_Vectoring_Controller_d_B.slip[1] - limit[1]) / limit[1];
    Torque_Vectoring_Controller_d_B.slip[2] =
      (Torque_Vectoring_Controller_d_B.slip[2] - limit[2]) / limit[2];
    Torque_Vectoring_Controller_d_B.slip[3] =
      (Torque_Vectoring_Controller_d_B.slip[3] - limit[3]) / limit[3];
  } else {
    /* '<S28>:1:28' */
    Torque_Vectoring_Controller_d_B.slip[0] = 0.0;
    Torque_Vectoring_Controller_d_B.slip[1] = 0.0;
    Torque_Vectoring_Controller_d_B.slip[2] = 0.0;
    Torque_Vectoring_Controller_d_B.slip[3] = 0.0;
  }

  /* End of MATLAB Function: '<S8>/Mu&Slip Estimator' */

  /* MATLAB Function: '<S8>/Efficiency Estimator' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Efficiency Estimator': '<S23>:1' */
  /* P_elec * eff = P_mech */
  /* '<S23>:1:7' */
  vRFR_COG = Torque_Vectoring_Controller_d_P.car.Pmax -
    Torque_Vectoring_Controller_d_P.car.PC.safetyMargin;

  /* [W] */
  /* '<S23>:1:9' */
  limit[0] = Torque_Vectoring_Controller_d_B.sensors.torque[0] *
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0];
  limit[1] = Torque_Vectoring_Controller_d_B.sensors.torque[1] *
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1];
  limit[2] = Torque_Vectoring_Controller_d_B.sensors.torque[2] *
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2];
  limit[3] = Torque_Vectoring_Controller_d_B.sensors.torque[3] *
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3];
  PmaxTyre = limit[0];
  PmaxTyre += limit[1];
  PmaxTyre += limit[2];
  PmaxTyre += limit[3];

  /* *car.gearRatio */
  /* '<S23>:1:10' */
  /* '<S23>:1:11' */
  if (Torque_Vectoring_Controller_d_B.settings.effEstimation == 1.0) {
    /* '<S23>:1:13' */
    if (Torque_Vectoring_Controller_d_B.sensors.P_elec > 1.0) {
      /* '<S23>:1:15' */
      /* '<S23>:1:16' */
      /* '<S23>:1:17' */
      u0 = PmaxTyre / Torque_Vectoring_Controller_d_B.sensors.P_elec;
      vRRR_COG = Torque_Vectoring_Controller_d_P.car.PC.minEff;
      if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      c_idx_0 = Torque_Vectoring_Controller_d_P.car.PC.maxEff;
      if ((vRRR_COG <= c_idx_0) || rtIsNaN(c_idx_0)) {
        c_idx_0 = vRRR_COG;
      }

      Torque_Vectoring_Controller__DW.effTemp =
        Torque_Vectoring_Controller__DW.effTemp * 0.2 + 0.8 * c_idx_0;
    } else {
      if (Torque_Vectoring_Controller_d_B.sensors.P_elec < 1.0) {
        /* '<S23>:1:19' */
        /* '<S23>:1:20' */
        /* '<S23>:1:21' */
        if (PmaxTyre <= -1.0) {
          vRRL_COG = PmaxTyre;
        } else {
          vRRL_COG = -1.0;
        }

        u0 = Torque_Vectoring_Controller_d_B.sensors.P_elec / vRRL_COG;
        vRRR_COG = Torque_Vectoring_Controller_d_P.car.PC.minEff;
        if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
          vRRR_COG = u0;
        }

        c_idx_0 = Torque_Vectoring_Controller_d_P.car.PC.maxEff;
        if ((vRRR_COG <= c_idx_0) || rtIsNaN(c_idx_0)) {
          c_idx_0 = vRRR_COG;
        }

        Torque_Vectoring_Controller__DW.effTemp =
          Torque_Vectoring_Controller__DW.effTemp * 0.2 + 0.8 * c_idx_0;

        /* mogelijkheid tot uitbreiding: Pmax variable ifv van batterij voor tijdens */
        /* indurance */
      }
    }
  }

  if (Torque_Vectoring_Controller_d_B.settings.effEstimation == 2.0) {
    /* '<S23>:1:30' */
    if ((Torque_Vectoring_Controller_d_B.sensors.P_elec > vRFR_COG * 0.3) &&
        (Torque_Vectoring_Controller_d_B.sensors.throttle > 0.0)) {
      /* '<S23>:1:32' */
      /*  only positive power limit */
      /* '<S23>:1:34' */
      vRFR_COG = (vRFR_COG - Torque_Vectoring_Controller_d_B.sensors.P_elec) /
        vRFR_COG;
      if (vRFR_COG < 0.0) {
        /* '<S23>:1:35' */
        /*  P_elec > Pmax */
        /* '<S23>:1:36' */
        vRFR_COG *= 2.0;
      }

      /* '<S23>:1:39' */
      Torque_Vectoring_Controller__DW.errorInt += vRFR_COG *
        Torque_Vectoring_Controller_d_P.car.dt;

      /* '<S23>:1:40' */
      u0 = Torque_Vectoring_Controller__DW.errorInt;
      if (!(u0 <= 0.2)) {
        u0 = 0.2;
      }

      if (u0 >= -0.2) {
        Torque_Vectoring_Controller__DW.errorInt = u0;
      } else {
        Torque_Vectoring_Controller__DW.errorInt = -0.2;
      }

      /* '<S23>:1:42' */
      /* more fitting variable name would be powerReductionFactor as this is not anymore an efficiency as Pelec * eff = Pmech */
      /* make car.PC.Kp velocity dependend? */
      /* '<S23>:1:45' */
      u0 = (Torque_Vectoring_Controller_d_P.car.PC.Kp * vRFR_COG +
            Torque_Vectoring_Controller_d_P.car.PC.Ki *
            Torque_Vectoring_Controller__DW.errorInt) +
        Torque_Vectoring_Controller__DW.effTemp;
      vRRR_COG = Torque_Vectoring_Controller_d_P.car.PC.maxEff;
      if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      c_idx_0 = Torque_Vectoring_Controller_d_P.car.PC.minEff;
      if ((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0)) {
        Torque_Vectoring_Controller__DW.effTemp = vRRR_COG;
      } else {
        Torque_Vectoring_Controller__DW.effTemp = c_idx_0;
      }
    } else if (Torque_Vectoring_Controller_d_B.sensors.P_elec > 5000.0) {
      /* '<S23>:1:48' */
      /* '<S23>:1:49' */
      /* '<S23>:1:50' */
      u0 = PmaxTyre / Torque_Vectoring_Controller_d_B.sensors.P_elec;
      vRRR_COG = Torque_Vectoring_Controller_d_P.car.PC.minEff;
      if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      c_idx_0 = Torque_Vectoring_Controller_d_P.car.PC.maxEff;
      if ((vRRR_COG <= c_idx_0) || rtIsNaN(c_idx_0)) {
        c_idx_0 = vRRR_COG;
      }

      Torque_Vectoring_Controller__DW.effTemp =
        Torque_Vectoring_Controller__DW.effTemp * 0.2 + 0.8 * c_idx_0;
    } else {
      if (Torque_Vectoring_Controller_d_B.sensors.P_elec < -5000.0) {
        /* '<S23>:1:51' */
        /* '<S23>:1:52' */
        /* '<S23>:1:53' */
        if (PmaxTyre <= -1.0) {
          vRRL_COG = PmaxTyre;
        } else {
          vRRL_COG = -1.0;
        }

        u0 = Torque_Vectoring_Controller_d_B.sensors.P_elec / vRRL_COG;
        vRRR_COG = Torque_Vectoring_Controller_d_P.car.PC.minEff;
        if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
          vRRR_COG = u0;
        }

        c_idx_0 = Torque_Vectoring_Controller_d_P.car.PC.maxEff;
        if ((vRRR_COG <= c_idx_0) || rtIsNaN(c_idx_0)) {
          c_idx_0 = vRRR_COG;
        }

        Torque_Vectoring_Controller__DW.effTemp =
          Torque_Vectoring_Controller__DW.effTemp * 0.2 + 0.8 * c_idx_0;
      }
    }
  } else {
    /* '<S23>:1:59' */
  }

  /* '<S23>:1:64' */
  Torque_Vectoring_Controller_d_B.eff = Torque_Vectoring_Controller__DW.effTemp;

  /* '<S23>:1:65' */
  Torque_Vectoring_Controller_d_B.effnotcontrolled = PmaxTyre /
    Torque_Vectoring_Controller_d_B.sensors.P_elec;
  Torque_Vectoring_Controller_d_B.P_elec_j =
    Torque_Vectoring_Controller_d_B.sensors.P_elec;
  Torque_Vectoring_Controller_d_B.P_mech = PmaxTyre;

  /* End of MATLAB Function: '<S8>/Efficiency Estimator' */

  /* MATLAB Function: '<S8>/Estim Par' */
  /* MATLAB Function 'Controls/Vehicle Estimated Parameters/Estim Par': '<S24>:1' */
  /* '<S24>:1:3' */
  Torque_Vectoring_Controller_d_B.estimPar.v = Torque_Vectoring_Controller_d_B.v;

  /* '<S24>:1:4' */
  /* '<S24>:1:5' */
  /* '<S24>:1:6' */
  /* '<S24>:1:7' */
  Torque_Vectoring_Controller_d_B.estimPar.rref =
    Torque_Vectoring_Controller_d_B.rref;

  /* '<S24>:1:8' */
  /* '<S24>:1:9' */
  Torque_Vectoring_Controller_d_B.estimPar.Fzi[0] =
    Torque_Vectoring_Controller_d_B.Fzi[0];
  Torque_Vectoring_Controller_d_B.estimPar.Fxi[0] =
    Torque_Vectoring_Controller_d_B.Fxi[0];
  Torque_Vectoring_Controller_d_B.estimPar.Fyi[0] =
    Torque_Vectoring_Controller_d_B.Fyi[0];
  Torque_Vectoring_Controller_d_B.estimPar.mu[0] =
    Torque_Vectoring_Controller_d_B.mu[0];
  Torque_Vectoring_Controller_d_B.estimPar.slip[0] =
    Torque_Vectoring_Controller_d_B.slip[0];
  Torque_Vectoring_Controller_d_B.estimPar.Fzi[1] =
    Torque_Vectoring_Controller_d_B.Fzi[1];
  Torque_Vectoring_Controller_d_B.estimPar.Fxi[1] =
    Torque_Vectoring_Controller_d_B.Fxi[1];
  Torque_Vectoring_Controller_d_B.estimPar.Fyi[1] =
    Torque_Vectoring_Controller_d_B.Fyi[1];
  Torque_Vectoring_Controller_d_B.estimPar.mu[1] =
    Torque_Vectoring_Controller_d_B.mu[1];
  Torque_Vectoring_Controller_d_B.estimPar.slip[1] =
    Torque_Vectoring_Controller_d_B.slip[1];
  Torque_Vectoring_Controller_d_B.estimPar.Fzi[2] =
    Torque_Vectoring_Controller_d_B.Fzi[2];
  Torque_Vectoring_Controller_d_B.estimPar.Fxi[2] =
    Torque_Vectoring_Controller_d_B.Fxi[2];
  Torque_Vectoring_Controller_d_B.estimPar.Fyi[2] =
    Torque_Vectoring_Controller_d_B.Fyi[2];
  Torque_Vectoring_Controller_d_B.estimPar.mu[2] =
    Torque_Vectoring_Controller_d_B.mu[2];
  Torque_Vectoring_Controller_d_B.estimPar.slip[2] =
    Torque_Vectoring_Controller_d_B.slip[2];
  Torque_Vectoring_Controller_d_B.estimPar.Fzi[3] =
    Torque_Vectoring_Controller_d_B.Fzi[3];
  Torque_Vectoring_Controller_d_B.estimPar.Fxi[3] =
    Torque_Vectoring_Controller_d_B.Fxi[3];
  Torque_Vectoring_Controller_d_B.estimPar.Fyi[3] =
    Torque_Vectoring_Controller_d_B.Fyi[3];
  Torque_Vectoring_Controller_d_B.estimPar.mu[3] =
    Torque_Vectoring_Controller_d_B.mu[3];
  Torque_Vectoring_Controller_d_B.estimPar.slip[3] =
    Torque_Vectoring_Controller_d_B.slip[3];

  /* '<S24>:1:10' */
  Torque_Vectoring_Controller_d_B.estimPar.eff =
    Torque_Vectoring_Controller_d_B.eff;

  /* BusCreator: '<S5>/BusConversion_InsertedFor_Yaw Rate Control_at_inport_2' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_b =
    Torque_Vectoring_Controller_d_B.estimPar;

  /* MATLAB Function: '<S5>/Yaw Rate Control' */
  /* MATLAB Function 'Controls/Control Systems/Yaw Rate Control': '<S15>:1' */
  /* Function that controls the moment around the z-axis */
  /* INPUTS: */
  /* OUTPUT: Moment of the car around Z-axis [Nm] */
  /* '<S15>:1:12' */
  PmaxTyre =
    (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_YawRa.wheelAngles[
     0] +
     Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_YawRa.wheelAngles[
     1]) / 2.0;

  /* For analyzation */
  /* if settings.YRCMode == 1 */
  /* '<S15>:1:30' */
  vRFR_COG =
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_b.rref -
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_YawRa.yawRate;

  /* '<S15>:1:31' */
  Torque_Vectoring_Controller__DW.errorInt_a += vRFR_COG *
    Torque_Vectoring_Controller_d_P.car.dt;

  /* '<S15>:1:32' */
  u0 = Torque_Vectoring_Controller__DW.errorInt_a;
  vRRR_COG = -Torque_Vectoring_Controller_d_P.car.YRC.intLimit;
  if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
    vRRR_COG = u0;
  }

  c_idx_0 = Torque_Vectoring_Controller_d_P.car.YRC.intLimit;
  if ((vRRR_COG <= c_idx_0) || rtIsNaN(c_idx_0)) {
    Torque_Vectoring_Controller__DW.errorInt_a = vRRR_COG;
  } else {
    Torque_Vectoring_Controller__DW.errorInt_a = c_idx_0;
  }

  /* '<S15>:1:33' */
  vRRL_COG = (vRFR_COG - Torque_Vectoring_Controller__DW.prevError) /
    Torque_Vectoring_Controller_d_P.car.dt;

  /* '<S15>:1:34' */
  /* '<S15>:1:35' */
  /* '<S15>:1:37' */
  /* '<S15>:1:39' */
  /* '<S15>:1:41' */
  /* '<S15>:1:42' */
  u0 = 1.0 - (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_b.v
              - Torque_Vectoring_Controller_d_P.car.YRC.changeVelocity) *
    Torque_Vectoring_Controller_d_P.car.YRC.slope;
  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  if (!(u0 <= 1.0)) {
    u0 = 1.0;
  }

  u0 *= (((Torque_Vectoring_Controller_d_P.car.YRC.Kp * vRFR_COG +
           Torque_Vectoring_Controller_d_P.car.YRC.Ki *
           Torque_Vectoring_Controller__DW.errorInt_a) +
          Torque_Vectoring_Controller_d_P.car.YRC.Kd * vRRL_COG) + (PmaxTyre -
          Torque_Vectoring_Controller__DW.prevWheelAngle) /
         Torque_Vectoring_Controller_d_P.car.dt *
         Torque_Vectoring_Controller_d_P.car.YRC.Ks) +
    (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_b.rref -
     Torque_Vectoring_Controller__DW.prevRref) /
    Torque_Vectoring_Controller_d_P.car.dt *
    Torque_Vectoring_Controller_d_P.car.YRC.Kr;
  vRRR_COG = Torque_Vectoring_Controller_d_P.car.YRC.maxValue;
  if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
    vRRR_COG = u0;
  }

  c_idx_0 = -Torque_Vectoring_Controller_d_P.car.YRC.maxValue;
  if ((vRRR_COG >= c_idx_0) || rtIsNaN(c_idx_0)) {
    c_idx_0 = vRRR_COG;
  }

  Torque_Vectoring_Controller__DW.Mz_memory += c_idx_0;

  /* '<S15>:1:44' */
  /* '<S15>:1:45' */
  /* '<S15>:1:46' */
  /* '<S15>:1:47' */
  /* '<S15>:1:48' */
  /* '<S15>:1:50' */
  Torque_Vectoring_Controller_d_B.actions[0] =
    Torque_Vectoring_Controller_d_P.car.YRC.Kp * vRFR_COG;
  Torque_Vectoring_Controller_d_B.actions[1] =
    Torque_Vectoring_Controller_d_P.car.YRC.Ki *
    Torque_Vectoring_Controller__DW.errorInt_a;
  Torque_Vectoring_Controller_d_B.actions[2] =
    Torque_Vectoring_Controller_d_P.car.YRC.Kd * vRRL_COG;
  Torque_Vectoring_Controller_d_B.actions[3] =
    Torque_Vectoring_Controller_d_P.car.YRC.Ks * PmaxTyre;
  Torque_Vectoring_Controller_d_B.actions[4] =
    Torque_Vectoring_Controller_d_P.car.YRC.Kr *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_b.rref;

  /* '<S15>:1:51' */
  Torque_Vectoring_Controller__DW.prevError = vRFR_COG;

  /* '<S15>:1:52' */
  Torque_Vectoring_Controller__DW.prevWheelAngle = PmaxTyre;

  /* '<S15>:1:53' */
  Torque_Vectoring_Controller__DW.prevRref =
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_b.rref;

  /* end */
  /*  if settings.YRCMode == 2 */
  /*      error = estimPar.rref - sensors.yawRate; */
  /*      integral = integral + error*car.dt; */
  /*      derivative = (error - prevError)/car.dt; */
  /*  */
  /*      Mz_temp = car.YRC.Kp*error + car.YRC.Ki*integral + car.YRC.Kd*derivative... */
  /*          +car.YRC.Ks*wheelAngle + car.YRC.Kr*estimPar.rref; */
  /*      Mz_temp = max(min(Mz_temp,car.YRC.maxValue),-car.YRC.maxValue); */
  /*  */
  /*      prevError = error; */
  /*  end */
  /* YRC enabled */
  if (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_p.YRC == 1.0)
  {
    /* '<S15>:1:74' */
    /* '<S15>:1:75' */
    Torque_Vectoring_Controller_d_B.Mz =
      Torque_Vectoring_Controller__DW.Mz_memory;

    /* YRC disabled */
  } else {
    /* '<S15>:1:79' */
    Torque_Vectoring_Controller_d_B.Mz = 0.0;
  }

  if (Torque_Vectoring_Controller_d_P.car.YRC.minV >
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_b.v) {
    /* '<S15>:1:82' */
    /* '<S15>:1:83' */
    Torque_Vectoring_Controller_d_B.Mz = 0.0;

    /* if speed is too low, don't activate yaw rate control */
    /* '<S15>:1:84' */
    Torque_Vectoring_Controller__DW.errorInt_a = 0.0;

    /* '<S15>:1:85' */
    Torque_Vectoring_Controller__DW.prevError = 0.0;
  }

  /* '<S15>:1:90' */
  Torque_Vectoring_Controller_d_B.rref_c =
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_b.rref;
  Torque_Vectoring_Controller_d_B.error = vRFR_COG;

  /* End of MATLAB Function: '<S5>/Yaw Rate Control' */

  /* BusCreator: '<S5>/BusConversion_InsertedFor_Traction Control_at_inport_0' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tract =
    Torque_Vectoring_Controller_d_B.sensors;

  /* BusCreator: '<S5>/BusConversion_InsertedFor_Traction Control_at_inport_1' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_g =
    Torque_Vectoring_Controller_d_B.settings;

  /* BusCreator: '<S5>/BusConversion_InsertedFor_Traction Control_at_inport_2' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p =
    Torque_Vectoring_Controller_d_B.estimPar;

  /* BusCreator: '<S10>/BusConversion_InsertedFor_MATLAB Function_at_inport_0' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MATLA =
    Torque_Vectoring_Controller_d_B.sensors;

  /* BusCreator: '<S10>/BusConversion_InsertedFor_MATLAB Function_at_inport_1' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_c =
    Torque_Vectoring_Controller_d_B.settings;

  /* BusCreator: '<S10>/BusConversion_InsertedFor_MATLAB Function_at_inport_2' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_k =
    Torque_Vectoring_Controller_d_B.estimPar;

  /* BusCreator: '<S10>/BusConversion_InsertedFor_MATLAB Function_at_inport_3' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_e =
    Torque_Vectoring_Controller_d_B.variables;

  /* BusCreator: '<S17>/BusConversion_InsertedFor_MATLAB Function1_at_inport_0' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_f =
    Torque_Vectoring_Controller_d_B.sensors;

  /* BusCreator: '<S17>/BusConversion_InsertedFor_MATLAB Function1_at_inport_1' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MA_cc =
    Torque_Vectoring_Controller_d_B.settings;

  /* BusCreator: '<S17>/BusConversion_InsertedFor_MATLAB Function1_at_inport_2' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_a =
    Torque_Vectoring_Controller_d_B.estimPar;

  /* BusCreator: '<S17>/BusConversion_InsertedFor_MATLAB Function1_at_inport_3' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_b =
    Torque_Vectoring_Controller_d_B.variables;

  /* MATLAB Function: '<S17>/MATLAB Function1' */
  /* MATLAB Function 'Controls/Control Systems/Distributor/Torque//Brake analyzer/MATLAB Function1': '<S18>:1' */
  /* Fdes = 11*4* min(car.motor.Tmax)*variables.TD_percentage*sensors.throttle/car.tireRadius; */
  /* if sensors.throttle > 0 */
  /* Fdes = sum(car.motor.Tmax)*variables.TD_percentage*sensors.throttle/car.tireRadius; % *4 because four motors */
  /* Fdes = Fdes*car.gearRatio; */
  /* '<S18>:1:10' */
  PmaxTyre =
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_f.throttle *
    1.5;
  vRFR_COG = 0.5 * Torque_Vectoring_Controller_d_P.car.rhoAir *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_a.v *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_a.v *
    Torque_Vectoring_Controller_d_P.car.Cl *
    Torque_Vectoring_Controller_d_P.car.AFront +
    Torque_Vectoring_Controller_d_P.car.mass *
    Torque_Vectoring_Controller_d_P.car.g;
  limit[0] = PmaxTyre *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_a.mu[0] *
    vRFR_COG;
  limit[1] = PmaxTyre *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_a.mu[1] *
    vRFR_COG;
  limit[2] = PmaxTyre *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_a.mu[2] *
    vRFR_COG;
  limit[3] = PmaxTyre *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_a.mu[3] *
    vRFR_COG;
  Torque_Vectoring_Controller_d_B.Fdes = limit[0];
  Torque_Vectoring_Controller_d_B.Fdes += limit[1];
  Torque_Vectoring_Controller_d_B.Fdes += limit[2];
  Torque_Vectoring_Controller_d_B.Fdes += limit[3];
  if (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_f.brake >
      0.0) {
    /* '<S18>:1:12' */
    /* '<S18>:1:13' */
    vRRL_COG = Torque_Vectoring_Controller_d_P.car.motor.Tmax[0];
    vRRL_COG += Torque_Vectoring_Controller_d_P.car.motor.Tmax[1];
    vRRL_COG += Torque_Vectoring_Controller_d_P.car.motor.Tmax[2];
    vRRL_COG += Torque_Vectoring_Controller_d_P.car.motor.Tmax[3];
    Torque_Vectoring_Controller_d_B.Fdes = -vRRL_COG *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_b.TD_percentage
      * Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_f.brake /
      Torque_Vectoring_Controller_d_P.car.tireRadius;

    /* '<S18>:1:14' */
    Torque_Vectoring_Controller_d_B.Fdes *=
      Torque_Vectoring_Controller_d_P.car.gearRatio;
  }

  /* End of MATLAB Function: '<S17>/MATLAB Function1' */

  /* MATLAB Function: '<S10>/MATLAB Function' */
  /* Fdes= 5000; */
  /* end */
  /*      Fdes = Fdes*1; */
  /*      Fdes = 800; */
  /*      Fdes = sensors.throttle*mean(estimPar.mu)*(car.mass*car.g + 0.5*car.rhoAir*estimPar.v*estimPar.v*car.Cl*car.AFront ); */
  /*      Fdes = Fdes; */
  Torque_Vectoring_Controller_d_B.Fdes_g = Torque_Vectoring_Controller_d_B.Fdes;

  /* MATLAB Function 'Controls/Control Systems/Distributor/MATLAB Function': '<S16>:1' */
  /* '<S16>:1:16' */
  /* '<S16>:1:1' */
  PmaxTyre = Torque_Vectoring_Controller_d_B.Fdes_g;

  /* ,Fdes,sumFx,Fxmax,Fxmaxsum */
  /* '<S16>:1:4' */
  /* '<S16>:1:5' */
  /* '<S16>:1:8' */
  vRFR_COG = 0.0;

  /* '<S16>:1:9' */
  /* '<S16>:1:10' */
  vRRL_COG = 0.0;

  /* '<S16>:1:11' */
  Torque_Vectoring_Controller_d_B.torqueDistribution[0] = 0.0;
  Torque_Vectoring_Controller_d_B.slipSet[0] = 0.0;
  Torque_Vectoring_Controller_d_B.Fxmax[0] = 0.0;
  Torque_Vectoring_Controller_d_B.Fx[0] = 0.0;
  Torque_Vectoring_Controller_d_B.torqueDistribution[1] = 0.0;
  Torque_Vectoring_Controller_d_B.slipSet[1] = 0.0;
  Torque_Vectoring_Controller_d_B.Fxmax[1] = 0.0;
  Torque_Vectoring_Controller_d_B.Fx[1] = 0.0;
  Torque_Vectoring_Controller_d_B.torqueDistribution[2] = 0.0;
  Torque_Vectoring_Controller_d_B.slipSet[2] = 0.0;
  Torque_Vectoring_Controller_d_B.Fxmax[2] = 0.0;
  Torque_Vectoring_Controller_d_B.Fx[2] = 0.0;
  Torque_Vectoring_Controller_d_B.torqueDistribution[3] = 0.0;
  Torque_Vectoring_Controller_d_B.slipSet[3] = 0.0;
  Torque_Vectoring_Controller_d_B.Fxmax[3] = 0.0;
  Torque_Vectoring_Controller_d_B.Fx[3] = 0.0;
  if (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_c.torqueMode
      == 1.0) {
    /* '<S16>:1:12' */
    /* '<S16>:1:14' */
    vRRR_COG = 0.25 * Torque_Vectoring_Controller_d_B.Mz /
      (Torque_Vectoring_Controller_d_P.car.tw * 0.5) *
      Torque_Vectoring_Controller_d_P.car.tireRadius;

    /* '<S16>:1:15' */
    /* '<S16>:1:16' */
    /* '<S16>:1:1' */
    /* '<S16>:1:18' */
    Torque_Vectoring_Controller_d_B.torqueDistribution[0] =
      Torque_Vectoring_Controller_d_P.car.motor.Tmax[0] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_e.TD_percentage
      * Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MATLA.throttle
      + -vRRR_COG;

    /* '<S16>:1:18' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[0] > 0.0) {
      /* '<S16>:1:19' */
      /* '<S16>:1:20' */
      Torque_Vectoring_Controller_d_B.slipSet[0] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetAcc;
    } else {
      /* '<S16>:1:22' */
      Torque_Vectoring_Controller_d_B.slipSet[0] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetBrake;
    }

    /* '<S16>:1:18' */
    Torque_Vectoring_Controller_d_B.torqueDistribution[1] =
      Torque_Vectoring_Controller_d_P.car.motor.Tmax[1] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_e.TD_percentage
      * Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MATLA.throttle
      + vRRR_COG;

    /* '<S16>:1:18' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[1] > 0.0) {
      /* '<S16>:1:19' */
      /* '<S16>:1:20' */
      Torque_Vectoring_Controller_d_B.slipSet[1] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetAcc;
    } else {
      /* '<S16>:1:22' */
      Torque_Vectoring_Controller_d_B.slipSet[1] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetBrake;
    }

    /* '<S16>:1:18' */
    Torque_Vectoring_Controller_d_B.torqueDistribution[2] =
      Torque_Vectoring_Controller_d_P.car.motor.Tmax[2] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_e.TD_percentage
      * Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MATLA.throttle
      + -vRRR_COG;

    /* '<S16>:1:18' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[2] > 0.0) {
      /* '<S16>:1:19' */
      /* '<S16>:1:20' */
      Torque_Vectoring_Controller_d_B.slipSet[2] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetAcc;
    } else {
      /* '<S16>:1:22' */
      Torque_Vectoring_Controller_d_B.slipSet[2] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetBrake;
    }

    /* '<S16>:1:18' */
    Torque_Vectoring_Controller_d_B.torqueDistribution[3] =
      Torque_Vectoring_Controller_d_P.car.motor.Tmax[3] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_e.TD_percentage
      * Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MATLA.throttle
      + vRRR_COG;

    /* '<S16>:1:18' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[3] > 0.0) {
      /* '<S16>:1:19' */
      /* '<S16>:1:20' */
      Torque_Vectoring_Controller_d_B.slipSet[3] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetAcc;
    } else {
      /* '<S16>:1:22' */
      Torque_Vectoring_Controller_d_B.slipSet[3] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetBrake;
    }

    /* '<S16>:1:18' */
  }

  /* Test torque mode: only Fx, no steeringAngle */
  if (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_c.torqueMode
      == 2.0) {
    /* '<S16>:1:33' */
    /* minForce = 2*car.Cd*car.AFront*0.5*car.rhoAir*estimPar.v*estimPar.v*0.25; %2* of niet? en met Cd? */
    /* FyReduceFactor = 0.1; */
    /* Fxmax = (max((estimPar.mu .* estimPar.Fzi).^2-FyReduceFactor*estimPar.Fyi.^2,0).^0.5); %Kamm's circle */
    /* '<S16>:1:45' */
    /* '<S16>:1:47' */
    /* '<S16>:1:49' */
    /* make sure the max torque of the motor isn't surpassed */
    /* '<S16>:1:50' */
    vRFR_COG =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_k.mu[0] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_k.Fzi[0];
    if (!(vRFR_COG >= 0.0)) {
      vRFR_COG = 0.0;
    }

    Torque_Vectoring_Controller_d_B.Fxmax[0] = vRFR_COG;
    vRFR_COG = Torque_Vectoring_Controller_d_P.car.gearRatio *
      Torque_Vectoring_Controller_d_P.car.motor.Tmax[0] /
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    x[0] = (Torque_Vectoring_Controller_d_B.Fxmax[0] > vRFR_COG);
    limit[0] = vRFR_COG;
    vRFR_COG =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_k.mu[1] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_k.Fzi[1];
    if (!(vRFR_COG >= 0.0)) {
      vRFR_COG = 0.0;
    }

    Torque_Vectoring_Controller_d_B.Fxmax[1] = vRFR_COG;
    vRFR_COG = Torque_Vectoring_Controller_d_P.car.gearRatio *
      Torque_Vectoring_Controller_d_P.car.motor.Tmax[1] /
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    x[1] = (Torque_Vectoring_Controller_d_B.Fxmax[1] > vRFR_COG);
    limit[1] = vRFR_COG;
    vRFR_COG =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_k.mu[2] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_k.Fzi[2];
    if (!(vRFR_COG >= 0.0)) {
      vRFR_COG = 0.0;
    }

    Torque_Vectoring_Controller_d_B.Fxmax[2] = vRFR_COG;
    vRFR_COG = Torque_Vectoring_Controller_d_P.car.gearRatio *
      Torque_Vectoring_Controller_d_P.car.motor.Tmax[2] /
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    x[2] = (Torque_Vectoring_Controller_d_B.Fxmax[2] > vRFR_COG);
    limit[2] = vRFR_COG;
    vRFR_COG =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_k.mu[3] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_k.Fzi[3];
    if (!(vRFR_COG >= 0.0)) {
      vRFR_COG = 0.0;
    }

    Torque_Vectoring_Controller_d_B.Fxmax[3] = vRFR_COG;
    vRFR_COG = Torque_Vectoring_Controller_d_P.car.gearRatio *
      Torque_Vectoring_Controller_d_P.car.motor.Tmax[3] /
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    x[3] = (Torque_Vectoring_Controller_d_B.Fxmax[3] > vRFR_COG);
    limit[3] = vRFR_COG;
    ixstart = 0;
    i = 1;
    exitg2 = false;
    while ((!exitg2) && (i < 5)) {
      guard1 = false;
      if (x[i - 1]) {
        ixstart++;
        ii_data[ixstart - 1] = (int8_T)i;
        if (ixstart >= 4) {
          exitg2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        i++;
      }
    }

    if (1 > ixstart) {
      ixstart = 0;
    }

    for (i = 0; i < ixstart; i++) {
      checkFxmax_data[i] = ii_data[i];
    }

    /* '<S16>:1:51' */
    for (i = 0; i < ixstart; i++) {
      Torque_Vectoring_Controller_d_B.Fxmax[checkFxmax_data[i] - 1] =
        limit[checkFxmax_data[i] - 1];
    }

    if (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_c.unlimitedFx
        == 1.0) {
      /* '<S16>:1:53' */
      /* Surpass the tire grip limits in case if the driver feels to restricted with this. */
      /* '<S16>:1:54' */
      Torque_Vectoring_Controller_d_B.Fxmax[0] = limit[0];
      Torque_Vectoring_Controller_d_B.Fxmax[1] = limit[1];
      Torque_Vectoring_Controller_d_B.Fxmax[2] = limit[2];
      Torque_Vectoring_Controller_d_B.Fxmax[3] = limit[3];
    }

    /* '<S16>:1:57' */
    vRRL_COG = Torque_Vectoring_Controller_d_B.Fxmax[0];
    vRRL_COG += Torque_Vectoring_Controller_d_B.Fxmax[1];
    vRRL_COG += Torque_Vectoring_Controller_d_B.Fxmax[2];
    vRRL_COG += Torque_Vectoring_Controller_d_B.Fxmax[3];

    /* '<S16>:1:58' */
    /* '<S16>:1:63' */
    tmp[0] = Torque_Vectoring_Controller_d_B.Fxmax[0];
    tmp_0[0] = -Torque_Vectoring_Controller_d_B.Fxmax[0];
    tmp[1] = Torque_Vectoring_Controller_d_B.Fxmax[1];
    tmp_0[1] = -Torque_Vectoring_Controller_d_B.Fxmax[1];
    tmp[2] = Torque_Vectoring_Controller_d_B.Fxmax[2];
    tmp_0[2] = -Torque_Vectoring_Controller_d_B.Fxmax[2];
    tmp[3] = Torque_Vectoring_Controller_d_B.Fxmax[3];
    tmp_0[3] = -Torque_Vectoring_Controller_d_B.Fxmax[3];
    Torque_Vectoring_Co_Distributor
      (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_c.Fsens,
       Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_c.Fxsens,
       &Torque_Vectoring_Controller_d_P.car, Torque_Vectoring_Controller_d_B.Mz,
       Torque_Vectoring_Controller_d_B.Fdes_g, tmp, tmp_0,
       Torque_Vectoring_Controller_d_B.Fx);

    /* '<S16>:1:65' */
    /* torque of motor, NOT of wheels (as IPG expects this as input) */
    /* '<S16>:1:1' */
    /* '<S16>:1:67' */
    Torque_Vectoring_Controller_d_B.torqueDistribution[0] =
      Torque_Vectoring_Controller_d_P.car.tireRadius *
      Torque_Vectoring_Controller_d_B.Fx[0];

    /* '<S16>:1:67' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[0] > 0.0) {
      /* '<S16>:1:68' */
      /* '<S16>:1:69' */
      Torque_Vectoring_Controller_d_B.slipSet[0] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetAcc;
    } else {
      /* '<S16>:1:71' */
      Torque_Vectoring_Controller_d_B.slipSet[0] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetBrake;
    }

    /* '<S16>:1:67' */
    Torque_Vectoring_Controller_d_B.torqueDistribution[1] =
      Torque_Vectoring_Controller_d_P.car.tireRadius *
      Torque_Vectoring_Controller_d_B.Fx[1];

    /* '<S16>:1:67' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[1] > 0.0) {
      /* '<S16>:1:68' */
      /* '<S16>:1:69' */
      Torque_Vectoring_Controller_d_B.slipSet[1] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetAcc;
    } else {
      /* '<S16>:1:71' */
      Torque_Vectoring_Controller_d_B.slipSet[1] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetBrake;
    }

    /* '<S16>:1:67' */
    Torque_Vectoring_Controller_d_B.torqueDistribution[2] =
      Torque_Vectoring_Controller_d_P.car.tireRadius *
      Torque_Vectoring_Controller_d_B.Fx[2];

    /* '<S16>:1:67' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[2] > 0.0) {
      /* '<S16>:1:68' */
      /* '<S16>:1:69' */
      Torque_Vectoring_Controller_d_B.slipSet[2] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetAcc;
    } else {
      /* '<S16>:1:71' */
      Torque_Vectoring_Controller_d_B.slipSet[2] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetBrake;
    }

    /* '<S16>:1:67' */
    Torque_Vectoring_Controller_d_B.torqueDistribution[3] =
      Torque_Vectoring_Controller_d_P.car.tireRadius *
      Torque_Vectoring_Controller_d_B.Fx[3];

    /* '<S16>:1:67' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[3] > 0.0) {
      /* '<S16>:1:68' */
      /* '<S16>:1:69' */
      Torque_Vectoring_Controller_d_B.slipSet[3] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetAcc;
    } else {
      /* '<S16>:1:71' */
      Torque_Vectoring_Controller_d_B.slipSet[3] =
        Torque_Vectoring_Controller_d_P.car.TC.slipSetBrake;
    }

    /* '<S16>:1:67' */
    /* '<S16>:1:75' */
    vRFR_COG = Torque_Vectoring_Controller_d_B.Fx[0];
    vRFR_COG += Torque_Vectoring_Controller_d_B.Fx[1];
    vRFR_COG += Torque_Vectoring_Controller_d_B.Fx[2];
    vRFR_COG += Torque_Vectoring_Controller_d_B.Fx[3];
  }

  Torque_Vectoring_Controller_d_B.Fdes_g = PmaxTyre;
  Torque_Vectoring_Controller_d_B.sumFx = vRFR_COG;
  Torque_Vectoring_Controller_d_B.Fxmaxsum = vRRL_COG;

  /* End of MATLAB Function: '<S10>/MATLAB Function' */

  /* MATLAB Function: '<S5>/Traction Control' */
  /* MATLAB Function 'Controls/Control Systems/Traction Control': '<S14>:1' */
  /* '<S14>:1:48' */
  /* '<S14>:1:38' */
  /* '<S14>:1:3' */
  Torque_Vectoring_Controller_d_B.error_b[0] = 0.0;
  Torque_Vectoring_Controller_d_B.error_b[1] = 0.0;
  Torque_Vectoring_Controller_d_B.error_b[2] = 0.0;
  Torque_Vectoring_Controller_d_B.error_b[3] = 0.0;

  /* persistent wi_prev; if isempty(wi_prev); wi_prev=[0 0 0 0]'; end */
  /* persistent SR_expected; if isempty(SR_expected); SR_expected=zeros(4, 8); end */
  /* persistent wvi_prev; if isempty(wvi_prev); wvi_prev=[0 0 0 0]'; end */
  /* '<S14>:1:18' */
  if (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_g.TC == 1.0)
  {
    /* '<S14>:1:20' */
    /* '<S14>:1:23' */
    vRRL_COG =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[0];
    vRRL_COG +=
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[1];
    vRRL_COG +=
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[2];
    vRRL_COG +=
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[3];

    /* '<S14>:1:25' */
    /* '<S14>:1:26' */
    /* '<S14>:1:27' */
    /* '<S14>:1:31' */
    /* '<S14>:1:32' */
    /* normal non linear torque control */
    /* '<S14>:1:35' */
    /* '<S14>:1:37' */
    /* '<S14>:1:38' */
    Torque_Vectoring_Controller__DW.Ti2[0] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[0] /
      vRRL_COG;
    Torque_Vectoring_Controller_d_B.error_b[0] =
      Torque_Vectoring_Controller_d_B.slipSet[0] -
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.slip[0];
    Torque_Vectoring_Controller__DW.errorInt_j[0] +=
      Torque_Vectoring_Controller_d_B.error_b[0] *
      Torque_Vectoring_Controller_d_P.car.dt;
    u0 = Torque_Vectoring_Controller__DW.errorInt_j[0];
    if (!(u0 >= -0.001)) {
      u0 = -0.001;
    }

    limit[0] = u0;
    Torque_Vectoring_Controller__DW.Ti2[1] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[1] /
      vRRL_COG;
    Torque_Vectoring_Controller_d_B.error_b[1] =
      Torque_Vectoring_Controller_d_B.slipSet[1] -
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.slip[1];
    Torque_Vectoring_Controller__DW.errorInt_j[1] +=
      Torque_Vectoring_Controller_d_B.error_b[1] *
      Torque_Vectoring_Controller_d_P.car.dt;
    u0 = Torque_Vectoring_Controller__DW.errorInt_j[1];
    if (!(u0 >= -0.001)) {
      u0 = -0.001;
    }

    limit[1] = u0;
    Torque_Vectoring_Controller__DW.Ti2[2] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[2] /
      vRRL_COG;
    Torque_Vectoring_Controller_d_B.error_b[2] =
      Torque_Vectoring_Controller_d_B.slipSet[2] -
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.slip[2];
    Torque_Vectoring_Controller__DW.errorInt_j[2] +=
      Torque_Vectoring_Controller_d_B.error_b[2] *
      Torque_Vectoring_Controller_d_P.car.dt;
    u0 = Torque_Vectoring_Controller__DW.errorInt_j[2];
    if (!(u0 >= -0.001)) {
      u0 = -0.001;
    }

    limit[2] = u0;
    Torque_Vectoring_Controller__DW.Ti2[3] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[3] /
      vRRL_COG;
    Torque_Vectoring_Controller_d_B.error_b[3] =
      Torque_Vectoring_Controller_d_B.slipSet[3] -
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.slip[3];
    Torque_Vectoring_Controller__DW.errorInt_j[3] +=
      Torque_Vectoring_Controller_d_B.error_b[3] *
      Torque_Vectoring_Controller_d_P.car.dt;
    u0 = Torque_Vectoring_Controller__DW.errorInt_j[3];
    if (!(u0 >= -0.001)) {
      u0 = -0.001;
    }

    limit[3] = u0;

    /* '<S14>:1:39' */
    u0 = limit[0];
    if (!(u0 <= 0.003)) {
      u0 = 0.003;
    }

    Torque_Vectoring_Controller__DW.errorInt_j[0] = u0;
    Torque_Vectoring_Controller__DW.errorD[0] =
      (Torque_Vectoring_Controller_d_B.error_b[0] -
       Torque_Vectoring_Controller__DW.errorPrev[0]) * 0.9 /
      Torque_Vectoring_Controller_d_P.car.dt +
      Torque_Vectoring_Controller__DW.errorD[0] * 0.1;
    u0 = limit[1];
    if (!(u0 <= 0.003)) {
      u0 = 0.003;
    }

    Torque_Vectoring_Controller__DW.errorInt_j[1] = u0;
    Torque_Vectoring_Controller__DW.errorD[1] =
      (Torque_Vectoring_Controller_d_B.error_b[1] -
       Torque_Vectoring_Controller__DW.errorPrev[1]) * 0.9 /
      Torque_Vectoring_Controller_d_P.car.dt +
      Torque_Vectoring_Controller__DW.errorD[1] * 0.1;
    u0 = limit[2];
    if (!(u0 <= 0.003)) {
      u0 = 0.003;
    }

    Torque_Vectoring_Controller__DW.errorInt_j[2] = u0;
    Torque_Vectoring_Controller__DW.errorD[2] =
      (Torque_Vectoring_Controller_d_B.error_b[2] -
       Torque_Vectoring_Controller__DW.errorPrev[2]) * 0.9 /
      Torque_Vectoring_Controller_d_P.car.dt +
      Torque_Vectoring_Controller__DW.errorD[2] * 0.1;
    u0 = limit[3];
    if (!(u0 <= 0.003)) {
      u0 = 0.003;
    }

    Torque_Vectoring_Controller__DW.errorInt_j[3] = u0;
    Torque_Vectoring_Controller__DW.errorD[3] =
      (Torque_Vectoring_Controller_d_B.error_b[3] -
       Torque_Vectoring_Controller__DW.errorPrev[3]) * 0.9 /
      Torque_Vectoring_Controller_d_P.car.dt +
      Torque_Vectoring_Controller__DW.errorD[3] * 0.1;
    u0 = Torque_Vectoring_Controller__DW.errorD[0];
    if (!(u0 >= -25.0)) {
      u0 = -25.0;
    }

    limit[0] = u0;
    u0 = Torque_Vectoring_Controller__DW.errorD[1];
    if (!(u0 >= -25.0)) {
      u0 = -25.0;
    }

    limit[1] = u0;
    u0 = Torque_Vectoring_Controller__DW.errorD[2];
    if (!(u0 >= -25.0)) {
      u0 = -25.0;
    }

    limit[2] = u0;
    u0 = Torque_Vectoring_Controller__DW.errorD[3];
    if (!(u0 >= -25.0)) {
      u0 = -25.0;
    }

    limit[3] = u0;

    /* '<S14>:1:40' */
    /* '<S14>:1:41' */
    u0 = Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.v;
    if (!(u0 >= 0.0)) {
      u0 = 0.0;
    }

    PmaxTyre = rt_powd_snf(u0, 0.7);

    /* '<S14>:1:42' */
    /* optimum seeking */
    /* '<S14>:1:45' */
    /* '<S14>:1:115' */
    /* '<S14>:1:109' */
    /* '<S14>:1:110' */
    u0 = limit[0];
    if (!(u0 <= 25.0)) {
      u0 = 25.0;
    }

    Torque_Vectoring_Controller__DW.errorD[0] = u0;
    Torque_Vectoring_Controller__DW.Ti[0] =
      Torque_Vectoring_Controller_d_B.torqueDistribution[0];
    vRFR_COG = Torque_Vectoring_Controller__DW.Ti[0];
    if (vRFR_COG < 0.0) {
      vRFR_COG = -1.0;
    } else if (vRFR_COG > 0.0) {
      vRFR_COG = 1.0;
    } else {
      if (vRFR_COG == 0.0) {
        vRFR_COG = 0.0;
      }
    }

    Torque_Vectoring_Controller__DW.Ti[0] = vRFR_COG;
    Torque_Vectoring_Controller__DW.Ti[0] = ((100.0 *
      Torque_Vectoring_Controller__DW.Ti2[0] * 10.0 *
      Torque_Vectoring_Controller_d_B.error_b[0] + 40.0 *
      Torque_Vectoring_Controller__DW.Ti2[0] * 1000.0 *
      Torque_Vectoring_Controller__DW.errorInt_j[0]) + 0.0 *
      Torque_Vectoring_Controller__DW.Ti2[0] / 100.0 *
      Torque_Vectoring_Controller__DW.errorD[0]) *
      Torque_Vectoring_Controller_d_P.car.tireInertia * PmaxTyre /
      Torque_Vectoring_Controller_d_P.car.tireRadius +
      Torque_Vectoring_Controller__DW.Ti[0] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[0] *
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    Torque_Vectoring_Controller__DW.Ti[0] /=
      Torque_Vectoring_Controller_d_P.car.gearRatio;
    Torque_Vectoring_Controller__DW.FxVector[0] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fxi[0];
    Torque_Vectoring_Controller__DW.slipVector[0] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.slip[0];
    u0 = limit[1];
    if (!(u0 <= 25.0)) {
      u0 = 25.0;
    }

    Torque_Vectoring_Controller__DW.errorD[1] = u0;
    Torque_Vectoring_Controller__DW.Ti[1] =
      Torque_Vectoring_Controller_d_B.torqueDistribution[1];
    vRFR_COG = Torque_Vectoring_Controller__DW.Ti[1];
    if (vRFR_COG < 0.0) {
      vRFR_COG = -1.0;
    } else if (vRFR_COG > 0.0) {
      vRFR_COG = 1.0;
    } else {
      if (vRFR_COG == 0.0) {
        vRFR_COG = 0.0;
      }
    }

    Torque_Vectoring_Controller__DW.Ti[1] = vRFR_COG;
    Torque_Vectoring_Controller__DW.Ti[1] = ((100.0 *
      Torque_Vectoring_Controller__DW.Ti2[1] * 10.0 *
      Torque_Vectoring_Controller_d_B.error_b[1] + 40.0 *
      Torque_Vectoring_Controller__DW.Ti2[1] * 1000.0 *
      Torque_Vectoring_Controller__DW.errorInt_j[1]) + 0.0 *
      Torque_Vectoring_Controller__DW.Ti2[1] / 100.0 *
      Torque_Vectoring_Controller__DW.errorD[1]) *
      Torque_Vectoring_Controller_d_P.car.tireInertia * PmaxTyre /
      Torque_Vectoring_Controller_d_P.car.tireRadius +
      Torque_Vectoring_Controller__DW.Ti[1] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[1] *
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    Torque_Vectoring_Controller__DW.Ti[1] /=
      Torque_Vectoring_Controller_d_P.car.gearRatio;
    Torque_Vectoring_Controller__DW.FxVector[6] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fxi[1];
    Torque_Vectoring_Controller__DW.slipVector[6] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.slip[1];
    u0 = limit[2];
    if (!(u0 <= 25.0)) {
      u0 = 25.0;
    }

    Torque_Vectoring_Controller__DW.errorD[2] = u0;
    Torque_Vectoring_Controller__DW.Ti[2] =
      Torque_Vectoring_Controller_d_B.torqueDistribution[2];
    vRFR_COG = Torque_Vectoring_Controller__DW.Ti[2];
    if (vRFR_COG < 0.0) {
      vRFR_COG = -1.0;
    } else if (vRFR_COG > 0.0) {
      vRFR_COG = 1.0;
    } else {
      if (vRFR_COG == 0.0) {
        vRFR_COG = 0.0;
      }
    }

    Torque_Vectoring_Controller__DW.Ti[2] = vRFR_COG;
    Torque_Vectoring_Controller__DW.Ti[2] = ((100.0 *
      Torque_Vectoring_Controller__DW.Ti2[2] * 10.0 *
      Torque_Vectoring_Controller_d_B.error_b[2] + 40.0 *
      Torque_Vectoring_Controller__DW.Ti2[2] * 1000.0 *
      Torque_Vectoring_Controller__DW.errorInt_j[2]) + 0.0 *
      Torque_Vectoring_Controller__DW.Ti2[2] / 100.0 *
      Torque_Vectoring_Controller__DW.errorD[2]) *
      Torque_Vectoring_Controller_d_P.car.tireInertia * PmaxTyre /
      Torque_Vectoring_Controller_d_P.car.tireRadius +
      Torque_Vectoring_Controller__DW.Ti[2] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[2] *
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    Torque_Vectoring_Controller__DW.Ti[2] /=
      Torque_Vectoring_Controller_d_P.car.gearRatio;
    Torque_Vectoring_Controller__DW.FxVector[12] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fxi[2];
    Torque_Vectoring_Controller__DW.slipVector[12] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.slip[2];
    u0 = limit[3];
    if (!(u0 <= 25.0)) {
      u0 = 25.0;
    }

    Torque_Vectoring_Controller__DW.errorD[3] = u0;
    Torque_Vectoring_Controller__DW.Ti[3] =
      Torque_Vectoring_Controller_d_B.torqueDistribution[3];
    vRFR_COG = Torque_Vectoring_Controller__DW.Ti[3];
    if (vRFR_COG < 0.0) {
      vRFR_COG = -1.0;
    } else if (vRFR_COG > 0.0) {
      vRFR_COG = 1.0;
    } else {
      if (vRFR_COG == 0.0) {
        vRFR_COG = 0.0;
      }
    }

    Torque_Vectoring_Controller__DW.Ti[3] = vRFR_COG;
    Torque_Vectoring_Controller__DW.Ti[3] = ((100.0 *
      Torque_Vectoring_Controller__DW.Ti2[3] * 10.0 *
      Torque_Vectoring_Controller_d_B.error_b[3] + 40.0 *
      Torque_Vectoring_Controller__DW.Ti2[3] * 1000.0 *
      Torque_Vectoring_Controller__DW.errorInt_j[3]) + 0.0 *
      Torque_Vectoring_Controller__DW.Ti2[3] / 100.0 *
      Torque_Vectoring_Controller__DW.errorD[3]) *
      Torque_Vectoring_Controller_d_P.car.tireInertia * PmaxTyre /
      Torque_Vectoring_Controller_d_P.car.tireRadius +
      Torque_Vectoring_Controller__DW.Ti[3] *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[3] *
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    Torque_Vectoring_Controller__DW.Ti[3] /=
      Torque_Vectoring_Controller_d_P.car.gearRatio;
    Torque_Vectoring_Controller__DW.FxVector[18] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fxi[3];
    Torque_Vectoring_Controller__DW.slipVector[18] =
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.slip[3];

    /* '<S14>:1:102' */
    /* '<S14>:1:114' */
    /* '<S14>:1:115' */
    Torque_Vectoring_Contro_polyfit(&Torque_Vectoring_Controller__DW.slipVector
      [0], &Torque_Vectoring_Controller__DW.FxVector[0], p1);

    /* '<S14>:1:116' */
    Torque_Vectoring_Contro_polyfit(&Torque_Vectoring_Controller__DW.FxVector[0],
      &Torque_Vectoring_Controller__DW.slipVector[0], p2);

    /* '<S14>:1:118' */
    /* '<S14>:1:119' */
    PmaxTyre = 1.0 / p2[0];

    /* '<S14>:1:121' */
    /* '<S14>:1:123' */
    u0 = fabs(p1[0]);
    vRRR_COG = fabs(PmaxTyre);
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    u0 = fabs(p1[0]);
    c_idx_0 = fabs(PmaxTyre);
    if ((u0 <= c_idx_0) || rtIsNaN(c_idx_0)) {
      c_idx_0 = u0;
    }

    if (vRRR_COG > 0.0) {
      vRRR_COG = 1.0;
    } else {
      if (vRRR_COG == 0.0) {
        vRRR_COG = 0.0;
      }
    }

    u0 = vRRR_COG * c_idx_0;
    if (!(u0 <= 20000.0)) {
      u0 = 20000.0;
    }

    dFds[0] = u0;

    /* '<S14>:1:114' */
    /* '<S14>:1:115' */
    Torque_Vectoring_Contro_polyfit(&Torque_Vectoring_Controller__DW.slipVector
      [6], &Torque_Vectoring_Controller__DW.FxVector[6], p1);

    /* '<S14>:1:116' */
    Torque_Vectoring_Contro_polyfit(&Torque_Vectoring_Controller__DW.FxVector[6],
      &Torque_Vectoring_Controller__DW.slipVector[6], p2);

    /* '<S14>:1:118' */
    /* '<S14>:1:119' */
    PmaxTyre = 1.0 / p2[0];

    /* '<S14>:1:121' */
    /* '<S14>:1:123' */
    u0 = fabs(p1[0]);
    vRRR_COG = fabs(PmaxTyre);
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    u0 = fabs(p1[0]);
    c_idx_0 = fabs(PmaxTyre);
    if ((u0 <= c_idx_0) || rtIsNaN(c_idx_0)) {
      c_idx_0 = u0;
    }

    if (vRRR_COG > 0.0) {
      vRRR_COG = 1.0;
    } else {
      if (vRRR_COG == 0.0) {
        vRRR_COG = 0.0;
      }
    }

    u0 = vRRR_COG * c_idx_0;
    if (!(u0 <= 20000.0)) {
      u0 = 20000.0;
    }

    dFds[1] = u0;

    /* '<S14>:1:114' */
    /* '<S14>:1:115' */
    Torque_Vectoring_Contro_polyfit(&Torque_Vectoring_Controller__DW.slipVector
      [12], &Torque_Vectoring_Controller__DW.FxVector[12], p1);

    /* '<S14>:1:116' */
    Torque_Vectoring_Contro_polyfit(&Torque_Vectoring_Controller__DW.FxVector[12],
      &Torque_Vectoring_Controller__DW.slipVector[12], p2);

    /* '<S14>:1:118' */
    /* '<S14>:1:119' */
    PmaxTyre = 1.0 / p2[0];

    /* '<S14>:1:121' */
    /* '<S14>:1:123' */
    u0 = fabs(p1[0]);
    vRRR_COG = fabs(PmaxTyre);
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    u0 = fabs(p1[0]);
    c_idx_0 = fabs(PmaxTyre);
    if ((u0 <= c_idx_0) || rtIsNaN(c_idx_0)) {
      c_idx_0 = u0;
    }

    if (vRRR_COG > 0.0) {
      vRRR_COG = 1.0;
    } else {
      if (vRRR_COG == 0.0) {
        vRRR_COG = 0.0;
      }
    }

    u0 = vRRR_COG * c_idx_0;
    if (!(u0 <= 20000.0)) {
      u0 = 20000.0;
    }

    dFds[2] = u0;

    /* '<S14>:1:114' */
    /* '<S14>:1:115' */
    Torque_Vectoring_Contro_polyfit(&Torque_Vectoring_Controller__DW.slipVector
      [18], &Torque_Vectoring_Controller__DW.FxVector[18], p1);

    /* '<S14>:1:116' */
    Torque_Vectoring_Contro_polyfit(&Torque_Vectoring_Controller__DW.FxVector[18],
      &Torque_Vectoring_Controller__DW.slipVector[18], p2);

    /* '<S14>:1:118' */
    /* '<S14>:1:119' */
    PmaxTyre = 1.0 / p2[0];

    /* '<S14>:1:121' */
    /* '<S14>:1:123' */
    u0 = fabs(p1[0]);
    vRRR_COG = fabs(PmaxTyre);
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    u0 = fabs(p1[0]);
    c_idx_0 = fabs(PmaxTyre);
    if ((u0 <= c_idx_0) || rtIsNaN(c_idx_0)) {
      c_idx_0 = u0;
    }

    if (vRRR_COG > 0.0) {
      vRRR_COG = 1.0;
    } else {
      if (vRRR_COG == 0.0) {
        vRRR_COG = 0.0;
      }
    }

    u0 = vRRR_COG * c_idx_0;
    if (!(u0 <= 20000.0)) {
      u0 = 20000.0;
    }

    dFds[3] = u0;

    /* '<S14>:1:114' */
    /*  shift list one */
    /* '<S14>:1:127' */
    /* '<S14>:1:128' */
    tmp_1[0] = 0.0;
    tmp_1[6] = 0.0;
    tmp_1[12] = 0.0;
    tmp_1[18] = 0.0;
    for (i = 0; i < 4; i++) {
      for (ixstart = 0; ixstart < 5; ixstart++) {
        tmp_1[(ixstart + 6 * i) + 1] = Torque_Vectoring_Controller__DW.FxVector
          [6 * i + ixstart];
      }
    }

    /* '<S14>:1:129' */
    /* '<S14>:1:130' */
    for (i = 0; i < 4; i++) {
      for (ixstart = 0; ixstart < 6; ixstart++) {
        Torque_Vectoring_Controller__DW.FxVector[ixstart + 6 * i] = tmp_1[6 * i
          + ixstart];
      }

      tmp_2[6 * i] = 0.0;
    }

    for (i = 0; i < 4; i++) {
      for (ixstart = 0; ixstart < 5; ixstart++) {
        tmp_2[(ixstart + 6 * i) + 1] =
          Torque_Vectoring_Controller__DW.slipVector[6 * i + ixstart];
      }
    }

    /* '<S14>:1:46' */
    /* '<S14>:1:47' */
    /* '<S14>:1:48' */
    for (ixstart = 0; ixstart < 4; ixstart++) {
      for (i = 0; i < 6; i++) {
        Torque_Vectoring_Controller__DW.slipVector[i + 6 * ixstart] = tmp_2[6 *
          ixstart + i];
      }

      Torque_Vectoring_Controller__DW.errorInt2[ixstart] += dFds[ixstart] *
        Torque_Vectoring_Controller_d_P.car.dt;
      u0 = Torque_Vectoring_Controller__DW.errorInt2[ixstart];
      if (!(u0 >= -500.0)) {
        u0 = -500.0;
      }

      limit[ixstart] = u0;
    }

    /* '<S14>:1:49' */
    /* '<S14>:1:50' */
    u0 = Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.v;
    if (!(u0 >= 0.0)) {
      u0 = 0.0;
    }

    PmaxTyre = rt_powd_snf(u0, 0.7);

    /* '<S14>:1:51' */
    /* '<S14>:1:53' */
    u0 = limit[0];
    if (!(u0 <= 500.0)) {
      u0 = 500.0;
    }

    Torque_Vectoring_Controller__DW.errorInt2[0] = u0;
    vRFR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[0];
    if (vRFR_COG < 0.0) {
      vRFR_COG = -1.0;
    } else if (vRFR_COG > 0.0) {
      vRFR_COG = 1.0;
    } else {
      if (vRFR_COG == 0.0) {
        vRFR_COG = 0.0;
      }
    }

    Torque_Vectoring_Controller__DW.Ti2[0] = (20.0 *
      Torque_Vectoring_Controller__DW.Ti2[0] / 1000.0 * dFds[0] + 40.0 *
      Torque_Vectoring_Controller__DW.Ti2[0] / 1000.0 *
      Torque_Vectoring_Controller__DW.errorInt2[0]) *
      Torque_Vectoring_Controller_d_P.car.tireInertia * PmaxTyre /
      Torque_Vectoring_Controller_d_P.car.tireRadius + vRFR_COG *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[0] *
      Torque_Vectoring_Controller_d_P.car.TC_mu *
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    Torque_Vectoring_Controller__DW.Ti2[0] /=
      Torque_Vectoring_Controller_d_P.car.gearRatio;

    /* '<S14>:1:53' */
    if (fabs(Torque_Vectoring_Controller_d_B.error_b[0]) < 0.05) {
      /* '<S14>:1:54' */
      /* '<S14>:1:55' */
      Torque_Vectoring_Controller__DW.Ti[0] =
        Torque_Vectoring_Controller__DW.Ti2[0];
    }

    /* '<S14>:1:53' */
    u0 = limit[1];
    if (!(u0 <= 500.0)) {
      u0 = 500.0;
    }

    Torque_Vectoring_Controller__DW.errorInt2[1] = u0;
    vRFR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[1];
    if (vRFR_COG < 0.0) {
      vRFR_COG = -1.0;
    } else if (vRFR_COG > 0.0) {
      vRFR_COG = 1.0;
    } else {
      if (vRFR_COG == 0.0) {
        vRFR_COG = 0.0;
      }
    }

    Torque_Vectoring_Controller__DW.Ti2[1] = (20.0 *
      Torque_Vectoring_Controller__DW.Ti2[1] / 1000.0 * dFds[1] + 40.0 *
      Torque_Vectoring_Controller__DW.Ti2[1] / 1000.0 *
      Torque_Vectoring_Controller__DW.errorInt2[1]) *
      Torque_Vectoring_Controller_d_P.car.tireInertia * PmaxTyre /
      Torque_Vectoring_Controller_d_P.car.tireRadius + vRFR_COG *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[1] *
      Torque_Vectoring_Controller_d_P.car.TC_mu *
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    Torque_Vectoring_Controller__DW.Ti2[1] /=
      Torque_Vectoring_Controller_d_P.car.gearRatio;

    /* '<S14>:1:53' */
    if (fabs(Torque_Vectoring_Controller_d_B.error_b[1]) < 0.05) {
      /* '<S14>:1:54' */
      /* '<S14>:1:55' */
      Torque_Vectoring_Controller__DW.Ti[1] =
        Torque_Vectoring_Controller__DW.Ti2[1];
    }

    /* '<S14>:1:53' */
    u0 = limit[2];
    if (!(u0 <= 500.0)) {
      u0 = 500.0;
    }

    Torque_Vectoring_Controller__DW.errorInt2[2] = u0;
    vRFR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[2];
    if (vRFR_COG < 0.0) {
      vRFR_COG = -1.0;
    } else if (vRFR_COG > 0.0) {
      vRFR_COG = 1.0;
    } else {
      if (vRFR_COG == 0.0) {
        vRFR_COG = 0.0;
      }
    }

    Torque_Vectoring_Controller__DW.Ti2[2] = (20.0 *
      Torque_Vectoring_Controller__DW.Ti2[2] / 1000.0 * dFds[2] + 40.0 *
      Torque_Vectoring_Controller__DW.Ti2[2] / 1000.0 *
      Torque_Vectoring_Controller__DW.errorInt2[2]) *
      Torque_Vectoring_Controller_d_P.car.tireInertia * PmaxTyre /
      Torque_Vectoring_Controller_d_P.car.tireRadius + vRFR_COG *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[2] *
      Torque_Vectoring_Controller_d_P.car.TC_mu *
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    Torque_Vectoring_Controller__DW.Ti2[2] /=
      Torque_Vectoring_Controller_d_P.car.gearRatio;

    /* '<S14>:1:53' */
    if (fabs(Torque_Vectoring_Controller_d_B.error_b[2]) < 0.05) {
      /* '<S14>:1:54' */
      /* '<S14>:1:55' */
      Torque_Vectoring_Controller__DW.Ti[2] =
        Torque_Vectoring_Controller__DW.Ti2[2];
    }

    /* '<S14>:1:53' */
    u0 = limit[3];
    if (!(u0 <= 500.0)) {
      u0 = 500.0;
    }

    Torque_Vectoring_Controller__DW.errorInt2[3] = u0;
    vRFR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[3];
    if (vRFR_COG < 0.0) {
      vRFR_COG = -1.0;
    } else if (vRFR_COG > 0.0) {
      vRFR_COG = 1.0;
    } else {
      if (vRFR_COG == 0.0) {
        vRFR_COG = 0.0;
      }
    }

    Torque_Vectoring_Controller__DW.Ti2[3] = (20.0 *
      Torque_Vectoring_Controller__DW.Ti2[3] / 1000.0 * dFds[3] + 40.0 *
      Torque_Vectoring_Controller__DW.Ti2[3] / 1000.0 *
      Torque_Vectoring_Controller__DW.errorInt2[3]) *
      Torque_Vectoring_Controller_d_P.car.tireInertia * PmaxTyre /
      Torque_Vectoring_Controller_d_P.car.tireRadius + vRFR_COG *
      Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.Fzi[3] *
      Torque_Vectoring_Controller_d_P.car.TC_mu *
      Torque_Vectoring_Controller_d_P.car.tireRadius;
    Torque_Vectoring_Controller__DW.Ti2[3] /=
      Torque_Vectoring_Controller_d_P.car.gearRatio;

    /* '<S14>:1:53' */
    if (fabs(Torque_Vectoring_Controller_d_B.error_b[3]) < 0.05) {
      /* '<S14>:1:54' */
      /* '<S14>:1:55' */
      Torque_Vectoring_Controller__DW.Ti[3] =
        Torque_Vectoring_Controller__DW.Ti2[3];
    }

    /* '<S14>:1:53' */
    if (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tra_p.v <
        0.27777777777777779) {
      /* '<S14>:1:59' */
      /* Ti = [80 80 180 180]'; */
      /* '<S14>:1:61' */
      Torque_Vectoring_Controller__DW.errorInt_j[0] = 0.0;
      Torque_Vectoring_Controller__DW.errorInt_j[1] = 0.0;
      Torque_Vectoring_Controller__DW.errorInt_j[2] = 0.0;
      Torque_Vectoring_Controller__DW.errorInt_j[3] = 0.0;
    }

    if (Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Tract.throttle
        < 0.1) {
      /* '<S14>:1:64' */
      /* '<S14>:1:65' */
      Torque_Vectoring_Controller__DW.errorInt_j[0] = 0.0;
      Torque_Vectoring_Controller__DW.errorInt_j[1] = 0.0;
      Torque_Vectoring_Controller__DW.errorInt_j[2] = 0.0;
      Torque_Vectoring_Controller__DW.errorInt_j[3] = 0.0;
    }

    /* '<S14>:1:68' */
    vRRL_COG = 100.0 / Torque_Vectoring_Controller_d_P.car.gearRatio;

    /* '<S14>:1:69' */
    PmaxTyre = 100.0 / Torque_Vectoring_Controller_d_P.car.gearRatio;

    /* '<S14>:1:71' */
    vRFR_COG = Torque_Vectoring_Controller__DW.TiPrev[0] - vRRL_COG;
    Torque_Vectoring_Controller__DW.TiPrev[0] += PmaxTyre;
    u0 = Torque_Vectoring_Controller__DW.Ti[0];
    if ((u0 >= vRFR_COG) || rtIsNaN(vRFR_COG)) {
      vRFR_COG = u0;
    }

    limit[0] = vRFR_COG;
    vRFR_COG = Torque_Vectoring_Controller__DW.TiPrev[1] - vRRL_COG;
    Torque_Vectoring_Controller__DW.TiPrev[1] += PmaxTyre;
    u0 = Torque_Vectoring_Controller__DW.Ti[1];
    if ((u0 >= vRFR_COG) || rtIsNaN(vRFR_COG)) {
      vRFR_COG = u0;
    }

    limit[1] = vRFR_COG;
    vRFR_COG = Torque_Vectoring_Controller__DW.TiPrev[2] - vRRL_COG;
    Torque_Vectoring_Controller__DW.TiPrev[2] += PmaxTyre;
    u0 = Torque_Vectoring_Controller__DW.Ti[2];
    if ((u0 >= vRFR_COG) || rtIsNaN(vRFR_COG)) {
      vRFR_COG = u0;
    }

    limit[2] = vRFR_COG;
    vRFR_COG = Torque_Vectoring_Controller__DW.TiPrev[3] - vRRL_COG;
    Torque_Vectoring_Controller__DW.TiPrev[3] += PmaxTyre;
    u0 = Torque_Vectoring_Controller__DW.Ti[3];
    if ((u0 >= vRFR_COG) || rtIsNaN(vRFR_COG)) {
      vRFR_COG = u0;
    }

    limit[3] = vRFR_COG;

    /* '<S14>:1:73' */
    /* '<S14>:1:74' */
    /* '<S14>:1:76' */
    /* '<S14>:1:77' */
    u0 = limit[0];
    vRRR_COG = Torque_Vectoring_Controller__DW.TiPrev[0];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller__DW.Ti[0] = vRRR_COG;
    Torque_Vectoring_Controller__DW.TiPrev[0] =
      Torque_Vectoring_Controller__DW.Ti[0];
    Torque_Vectoring_Controller__DW.errorPrev[0] =
      Torque_Vectoring_Controller_d_B.error_b[0];
    Torque_Vectoring_Controller_d_B.Torques[0] =
      Torque_Vectoring_Controller__DW.Ti[0];

    /* '<S14>:1:77' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[0] > 0.0) {
      /* '<S14>:1:78' */
      /* '<S14>:1:79' */
      u0 = Torque_Vectoring_Controller_d_B.Torques[0];
      vRRR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[0];
      if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      if (!(vRRR_COG >= 0.0)) {
        vRRR_COG = 0.0;
      }

      Torque_Vectoring_Controller_d_B.Torques[0] = vRRR_COG;
    } else {
      /* '<S14>:1:81' */
      u0 = Torque_Vectoring_Controller_d_B.Torques[0];
      vRRR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[0];
      if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      if (!(vRRR_COG <= 0.0)) {
        vRRR_COG = 0.0;
      }

      Torque_Vectoring_Controller_d_B.Torques[0] = vRRR_COG;
    }

    /* '<S14>:1:77' */
    u0 = limit[1];
    vRRR_COG = Torque_Vectoring_Controller__DW.TiPrev[1];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller__DW.Ti[1] = vRRR_COG;
    Torque_Vectoring_Controller__DW.TiPrev[1] =
      Torque_Vectoring_Controller__DW.Ti[1];
    Torque_Vectoring_Controller__DW.errorPrev[1] =
      Torque_Vectoring_Controller_d_B.error_b[1];
    Torque_Vectoring_Controller_d_B.Torques[1] =
      Torque_Vectoring_Controller__DW.Ti[1];

    /* '<S14>:1:77' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[1] > 0.0) {
      /* '<S14>:1:78' */
      /* '<S14>:1:79' */
      u0 = Torque_Vectoring_Controller_d_B.Torques[1];
      vRRR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[1];
      if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      if (!(vRRR_COG >= 0.0)) {
        vRRR_COG = 0.0;
      }

      Torque_Vectoring_Controller_d_B.Torques[1] = vRRR_COG;
    } else {
      /* '<S14>:1:81' */
      u0 = Torque_Vectoring_Controller_d_B.Torques[1];
      vRRR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[1];
      if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      if (!(vRRR_COG <= 0.0)) {
        vRRR_COG = 0.0;
      }

      Torque_Vectoring_Controller_d_B.Torques[1] = vRRR_COG;
    }

    /* '<S14>:1:77' */
    u0 = limit[2];
    vRRR_COG = Torque_Vectoring_Controller__DW.TiPrev[2];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller__DW.Ti[2] = vRRR_COG;
    Torque_Vectoring_Controller__DW.TiPrev[2] =
      Torque_Vectoring_Controller__DW.Ti[2];
    Torque_Vectoring_Controller__DW.errorPrev[2] =
      Torque_Vectoring_Controller_d_B.error_b[2];
    Torque_Vectoring_Controller_d_B.Torques[2] =
      Torque_Vectoring_Controller__DW.Ti[2];

    /* '<S14>:1:77' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[2] > 0.0) {
      /* '<S14>:1:78' */
      /* '<S14>:1:79' */
      u0 = Torque_Vectoring_Controller_d_B.Torques[2];
      vRRR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[2];
      if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      if (!(vRRR_COG >= 0.0)) {
        vRRR_COG = 0.0;
      }

      Torque_Vectoring_Controller_d_B.Torques[2] = vRRR_COG;
    } else {
      /* '<S14>:1:81' */
      u0 = Torque_Vectoring_Controller_d_B.Torques[2];
      vRRR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[2];
      if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      if (!(vRRR_COG <= 0.0)) {
        vRRR_COG = 0.0;
      }

      Torque_Vectoring_Controller_d_B.Torques[2] = vRRR_COG;
    }

    /* '<S14>:1:77' */
    u0 = limit[3];
    vRRR_COG = Torque_Vectoring_Controller__DW.TiPrev[3];
    if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
      vRRR_COG = u0;
    }

    Torque_Vectoring_Controller__DW.Ti[3] = vRRR_COG;
    Torque_Vectoring_Controller__DW.TiPrev[3] =
      Torque_Vectoring_Controller__DW.Ti[3];
    Torque_Vectoring_Controller__DW.errorPrev[3] =
      Torque_Vectoring_Controller_d_B.error_b[3];
    Torque_Vectoring_Controller_d_B.Torques[3] =
      Torque_Vectoring_Controller__DW.Ti[3];

    /* '<S14>:1:77' */
    if (Torque_Vectoring_Controller_d_B.torqueDistribution[3] > 0.0) {
      /* '<S14>:1:78' */
      /* '<S14>:1:79' */
      u0 = Torque_Vectoring_Controller_d_B.Torques[3];
      vRRR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[3];
      if ((u0 <= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      if (!(vRRR_COG >= 0.0)) {
        vRRR_COG = 0.0;
      }

      Torque_Vectoring_Controller_d_B.Torques[3] = vRRR_COG;
    } else {
      /* '<S14>:1:81' */
      u0 = Torque_Vectoring_Controller_d_B.Torques[3];
      vRRR_COG = Torque_Vectoring_Controller_d_B.torqueDistribution[3];
      if ((u0 >= vRRR_COG) || rtIsNaN(vRRR_COG)) {
        vRRR_COG = u0;
      }

      if (!(vRRR_COG <= 0.0)) {
        vRRR_COG = 0.0;
      }

      Torque_Vectoring_Controller_d_B.Torques[3] = vRRR_COG;
    }

    /* '<S14>:1:77' */
  } else {
    /* '<S14>:1:87' */
    Torque_Vectoring_Controller_d_B.Torques[0] =
      Torque_Vectoring_Controller_d_B.torqueDistribution[0];
    Torque_Vectoring_Controller_d_B.Torques[1] =
      Torque_Vectoring_Controller_d_B.torqueDistribution[1];
    Torque_Vectoring_Controller_d_B.Torques[2] =
      Torque_Vectoring_Controller_d_B.torqueDistribution[2];
    Torque_Vectoring_Controller_d_B.Torques[3] =
      Torque_Vectoring_Controller_d_B.torqueDistribution[3];
  }

  /* '<S14>:1:90' */
  x[0] = (Torque_Vectoring_Controller_d_B.Torques[0] >
          Torque_Vectoring_Controller_d_P.car.motor.Tmax[0]);
  x[1] = (Torque_Vectoring_Controller_d_B.Torques[1] >
          Torque_Vectoring_Controller_d_P.car.motor.Tmax[1]);
  x[2] = (Torque_Vectoring_Controller_d_B.Torques[2] >
          Torque_Vectoring_Controller_d_P.car.motor.Tmax[2]);
  x[3] = (Torque_Vectoring_Controller_d_B.Torques[3] >
          Torque_Vectoring_Controller_d_P.car.motor.Tmax[3]);
  ixstart = 0;
  i = 1;
  exitg2 = false;
  while ((!exitg2) && (i < 5)) {
    guard1 = false;
    if (x[i - 1]) {
      ixstart++;
      ii_data[ixstart - 1] = (int8_T)i;
      if (ixstart >= 4) {
        exitg2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      i++;
    }
  }

  if (1 > ixstart) {
    ixstart = 0;
  }

  for (i = 0; i < ixstart; i++) {
    checkFxmax_data[i] = ii_data[i];
  }

  /* Limit torques to max torque */
  /* '<S14>:1:91' */
  for (i = 0; i < ixstart; i++) {
    Torque_Vectoring_Controller_d_B.Torques[checkFxmax_data[i] - 1] =
      Torque_Vectoring_Controller_d_P.car.motor.Tmax[checkFxmax_data[i] - 1];
  }

  /* wi_prev = sensors.wheelspeed; */
  /* wvi_prev = sensors.wheelspeedi; */
  /* '<S14>:1:98' */
  Torque_Vectoring_Controller_d_B.TiTi2[0] = Torque_Vectoring_Controller__DW.Ti
    [0];
  Torque_Vectoring_Controller_d_B.TiTi2[4] =
    Torque_Vectoring_Controller__DW.Ti2[0];
  Torque_Vectoring_Controller_d_B.rpmSet[0] = 20000.0;
  Torque_Vectoring_Controller_d_B.TiTi2[1] = Torque_Vectoring_Controller__DW.Ti
    [1];
  Torque_Vectoring_Controller_d_B.TiTi2[5] =
    Torque_Vectoring_Controller__DW.Ti2[1];
  Torque_Vectoring_Controller_d_B.rpmSet[1] = 20000.0;
  Torque_Vectoring_Controller_d_B.TiTi2[2] = Torque_Vectoring_Controller__DW.Ti
    [2];
  Torque_Vectoring_Controller_d_B.TiTi2[6] =
    Torque_Vectoring_Controller__DW.Ti2[2];
  Torque_Vectoring_Controller_d_B.rpmSet[2] = 20000.0;
  Torque_Vectoring_Controller_d_B.TiTi2[3] = Torque_Vectoring_Controller__DW.Ti
    [3];
  Torque_Vectoring_Controller_d_B.TiTi2[7] =
    Torque_Vectoring_Controller__DW.Ti2[3];
  Torque_Vectoring_Controller_d_B.rpmSet[3] = 20000.0;

  /* End of MATLAB Function: '<S5>/Traction Control' */

  /* Product: '<S13>/Product2' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  Torque_Vectoring_Controller_d_B.Product2[0] =
    Torque_Vectoring_Controller_d_B.Torques[0] *
    Torque_Vectoring_Controller_d_P.car.gearRatio;
  Torque_Vectoring_Controller_d_B.Product2[1] =
    Torque_Vectoring_Controller_d_B.Torques[1] *
    Torque_Vectoring_Controller_d_P.car.gearRatio;
  Torque_Vectoring_Controller_d_B.Product2[2] =
    Torque_Vectoring_Controller_d_B.Torques[2] *
    Torque_Vectoring_Controller_d_P.car.gearRatio;
  Torque_Vectoring_Controller_d_B.Product2[3] =
    Torque_Vectoring_Controller_d_B.Torques[3] *
    Torque_Vectoring_Controller_d_P.car.gearRatio;

  /* BusCreator: '<S11>/BusConversion_InsertedFor_Power checker_at_inport_0' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Power =
    Torque_Vectoring_Controller_d_B.sensors;

  /* BusCreator: '<S11>/BusConversion_InsertedFor_Power checker_at_inport_1' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Pow_a =
    Torque_Vectoring_Controller_d_B.settings;

  /* BusCreator: '<S11>/BusConversion_InsertedFor_Power checker_at_inport_2' */
  Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Pow_h =
    Torque_Vectoring_Controller_d_B.estimPar;

  /* MATLAB Function: '<S11>/Power checker' */
  /* MATLAB Function 'Controls/Control Systems/Power Checker/Power checker': '<S19>:1' */
  /* % Power limiter according to FS rules */
  /* '<S19>:1:5' */
  limit[0] = Torque_Vectoring_Controller_d_B.Torques[0] *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Power.wheelspeed[0]
    * Torque_Vectoring_Controller_d_P.car.gearRatio;
  limit[1] = Torque_Vectoring_Controller_d_B.Torques[1] *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Power.wheelspeed[1]
    * Torque_Vectoring_Controller_d_P.car.gearRatio;
  limit[2] = Torque_Vectoring_Controller_d_B.Torques[2] *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Power.wheelspeed[2]
    * Torque_Vectoring_Controller_d_P.car.gearRatio;
  limit[3] = Torque_Vectoring_Controller_d_B.Torques[3] *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Power.wheelspeed[3]
    * Torque_Vectoring_Controller_d_P.car.gearRatio;
  PmaxTyre = limit[0];
  PmaxTyre += limit[1];
  PmaxTyre += limit[2];
  PmaxTyre += limit[3];

  /* [Nm*rad/s][W] */
  /* '<S19>:1:7' */
  vRFR_COG = (Torque_Vectoring_Controller_d_P.car.Pmax -
              Torque_Vectoring_Controller_d_P.car.PC.safetyMargin) *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Pow_h.eff;

  /* '<S19>:1:8' */
  vRRL_COG = 0.0;
  if (PmaxTyre > vRFR_COG) {
    /* '<S19>:1:10' */
    /* '<S19>:1:11' */
    vRRL_COG = PmaxTyre - vRFR_COG;
  }

  if (fabs(PmaxTyre) > 0.1) {
    /* '<S19>:1:14' */
    /* '<S19>:1:15' */
    vRRR_COG = vRRL_COG / PmaxTyre;
  } else {
    /* '<S19>:1:17' */
    vRRR_COG = 0.0;
  }

  /* '<S19>:1:20' */
  u0 = 1.0 - vRRR_COG;
  if (!(u0 <= 1.0)) {
    u0 = 1.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* '<S19>:1:21' */
  Torque_Vectoring_Controller_d_B.CheckedTorque[0] =
    Torque_Vectoring_Controller_d_B.Torques[0] * u0;
  limit[0] = Torque_Vectoring_Controller_d_B.CheckedTorque[0] *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Power.wheelspeed[0]
    * Torque_Vectoring_Controller_d_P.car.gearRatio;
  Torque_Vectoring_Controller_d_B.CheckedTorque[1] =
    Torque_Vectoring_Controller_d_B.Torques[1] * u0;
  limit[1] = Torque_Vectoring_Controller_d_B.CheckedTorque[1] *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Power.wheelspeed[1]
    * Torque_Vectoring_Controller_d_P.car.gearRatio;
  Torque_Vectoring_Controller_d_B.CheckedTorque[2] =
    Torque_Vectoring_Controller_d_B.Torques[2] * u0;
  limit[2] = Torque_Vectoring_Controller_d_B.CheckedTorque[2] *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Power.wheelspeed[2]
    * Torque_Vectoring_Controller_d_P.car.gearRatio;
  Torque_Vectoring_Controller_d_B.CheckedTorque[3] =
    Torque_Vectoring_Controller_d_B.Torques[3] * u0;
  limit[3] = Torque_Vectoring_Controller_d_B.CheckedTorque[3] *
    Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Power.wheelspeed[3]
    * Torque_Vectoring_Controller_d_P.car.gearRatio;
  u0 = limit[0];
  u0 += limit[1];
  u0 += limit[2];
  u0 += limit[3];

  /* [Nm*rad/s][W] */
  Torque_Vectoring_Controller_d_B.P_mech_e = PmaxTyre;
  Torque_Vectoring_Controller_d_B.maxMechPower = vRFR_COG;
  Torque_Vectoring_Controller_d_B.power2beReduced = vRRL_COG;
  Torque_Vectoring_Controller_d_B.part2beReduced = vRRR_COG;
  Torque_Vectoring_Controller_d_B.CheckedP_mech = u0;

  /* End of MATLAB Function: '<S11>/Power checker' */

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Constant'
   */
  /* MATLAB Function 'Controls/Subsystem/MATLAB Function': '<S21>:1' */
  /* '<S21>:1:4' */
  /* '<S21>:1:5' */
  Torque_Vectoring_Controller_d_B.Product[0] =
    Torque_Vectoring_Controller_d_B.torqueDistribution[0] *
    Torque_Vectoring_Controller_d_P.car.gearRatio;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  Torque_Vectoring_Controller_d_B.torques[0] = 0.0;
  Torque_Vectoring_Controller_d_B.rpmRef[0] = 0.0;

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Constant'
   */
  Torque_Vectoring_Controller_d_B.Product[1] =
    Torque_Vectoring_Controller_d_B.torqueDistribution[1] *
    Torque_Vectoring_Controller_d_P.car.gearRatio;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  Torque_Vectoring_Controller_d_B.torques[1] = 0.0;
  Torque_Vectoring_Controller_d_B.rpmRef[1] = 0.0;

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Constant'
   */
  Torque_Vectoring_Controller_d_B.Product[2] =
    Torque_Vectoring_Controller_d_B.torqueDistribution[2] *
    Torque_Vectoring_Controller_d_P.car.gearRatio;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  Torque_Vectoring_Controller_d_B.torques[2] = 0.0;
  Torque_Vectoring_Controller_d_B.rpmRef[2] = 0.0;

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Constant'
   */
  Torque_Vectoring_Controller_d_B.Product[3] =
    Torque_Vectoring_Controller_d_B.torqueDistribution[3] *
    Torque_Vectoring_Controller_d_P.car.gearRatio;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  Torque_Vectoring_Controller_d_B.torques[3] = 0.0;
  Torque_Vectoring_Controller_d_B.rpmRef[3] = 0.0;
  if (Torque_Vectoring_Controller_d_B.settings.TV_bypass == 0.0) {
    /* '<S21>:1:7' */
    /* '<S21>:1:9' */
    /* '<S21>:1:10' */
    Torque_Vectoring_Controller_d_B.torques[0] =
      Torque_Vectoring_Controller_d_B.CheckedTorque[0];
    Torque_Vectoring_Controller_d_B.rpmRef[0] =
      Torque_Vectoring_Controller_d_B.rpmSet[0];
    Torque_Vectoring_Controller_d_B.torques[1] =
      Torque_Vectoring_Controller_d_B.CheckedTorque[1];
    Torque_Vectoring_Controller_d_B.rpmRef[1] =
      Torque_Vectoring_Controller_d_B.rpmSet[1];
    Torque_Vectoring_Controller_d_B.torques[2] =
      Torque_Vectoring_Controller_d_B.CheckedTorque[2];
    Torque_Vectoring_Controller_d_B.rpmRef[2] =
      Torque_Vectoring_Controller_d_B.rpmSet[2];
    Torque_Vectoring_Controller_d_B.torques[3] =
      Torque_Vectoring_Controller_d_B.CheckedTorque[3];
    Torque_Vectoring_Controller_d_B.rpmRef[3] =
      Torque_Vectoring_Controller_d_B.rpmSet[3];
  } else {
    if (Torque_Vectoring_Controller_d_B.settings.TV_bypass == 1.0) {
      /* '<S21>:1:12' */
      /* '<S21>:1:14' */
      /* '<S21>:1:15' */
      Torque_Vectoring_Controller_d_B.torques[0] =
        Torque_Vectoring_Controller_d_B.torqueBypass[0];
      Torque_Vectoring_Controller_d_B.rpmRef[0] =
        Torque_Vectoring_Controller_d_B.rpmBypass[0];
      Torque_Vectoring_Controller_d_B.torques[1] =
        Torque_Vectoring_Controller_d_B.torqueBypass[1];
      Torque_Vectoring_Controller_d_B.rpmRef[1] =
        Torque_Vectoring_Controller_d_B.rpmBypass[1];
      Torque_Vectoring_Controller_d_B.torques[2] =
        Torque_Vectoring_Controller_d_B.torqueBypass[2];
      Torque_Vectoring_Controller_d_B.rpmRef[2] =
        Torque_Vectoring_Controller_d_B.rpmBypass[2];
      Torque_Vectoring_Controller_d_B.torques[3] =
        Torque_Vectoring_Controller_d_B.torqueBypass[3];
      Torque_Vectoring_Controller_d_B.rpmRef[3] =
        Torque_Vectoring_Controller_d_B.rpmBypass[3];
    }
  }

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector_at_outport_0' */
  Torque_Vectoring_Controller_d_B.ax =
    Torque_Vectoring_Controller_d_B.sensors.ax;

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector_at_outport_1' */
  Torque_Vectoring_Controller_d_B.ay =
    Torque_Vectoring_Controller_d_B.sensors.ay;

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector1_at_outport_0' */
  Torque_Vectoring_Controller_d_B.ax_g =
    Torque_Vectoring_Controller_d_B.sensors.ax;

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector1_at_outport_1' */
  Torque_Vectoring_Controller_d_B.wheelspeed[0] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0];

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector1_at_outport_2' */
  Torque_Vectoring_Controller_d_B.torque[0] =
    Torque_Vectoring_Controller_d_B.sensors.torque[0];

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector1_at_outport_1' */
  Torque_Vectoring_Controller_d_B.wheelspeed[1] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1];

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector1_at_outport_2' */
  Torque_Vectoring_Controller_d_B.torque[1] =
    Torque_Vectoring_Controller_d_B.sensors.torque[1];

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector1_at_outport_1' */
  Torque_Vectoring_Controller_d_B.wheelspeed[2] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2];

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector1_at_outport_2' */
  Torque_Vectoring_Controller_d_B.torque[2] =
    Torque_Vectoring_Controller_d_B.sensors.torque[2];

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector1_at_outport_1' */
  Torque_Vectoring_Controller_d_B.wheelspeed[3] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3];

  /* SignalConversion: '<S29>/SigConversion_InsertedFor_Bus Selector1_at_outport_2' */
  Torque_Vectoring_Controller_d_B.torque[3] =
    Torque_Vectoring_Controller_d_B.sensors.torque[3];

  /* Product: '<S29>/Product' incorporates:
   *  Constant: '<S29>/tireRadius'
   */
  Torque_Vectoring_Controller_d_B.omegaR[0] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0] *
    Torque_Vectoring_Controller_d_P.car.tireRadius;
  Torque_Vectoring_Controller_d_B.omegaR[1] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1] *
    Torque_Vectoring_Controller_d_P.car.tireRadius;
  Torque_Vectoring_Controller_d_B.omegaR[2] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2] *
    Torque_Vectoring_Controller_d_P.car.tireRadius;
  Torque_Vectoring_Controller_d_B.omegaR[3] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3] *
    Torque_Vectoring_Controller_d_P.car.tireRadius;

  /* Constant: '<S96>/small' */
  memcpy(&Torque_Vectoring_Controller_d_B.small[0],
         &Torque_Vectoring_Controller_d_P.small_Value_k[0], 101U * sizeof(real_T));

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector1_at_outport_0' */
  Torque_Vectoring_Controller_d_B.torque_a[0] =
    Torque_Vectoring_Controller_d_B.sensors.torque[0];
  Torque_Vectoring_Controller_d_B.torque_a[1] =
    Torque_Vectoring_Controller_d_B.sensors.torque[1];
  Torque_Vectoring_Controller_d_B.torque_a[2] =
    Torque_Vectoring_Controller_d_B.sensors.torque[2];
  Torque_Vectoring_Controller_d_B.torque_a[3] =
    Torque_Vectoring_Controller_d_B.sensors.torque[3];

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector2_at_outport_0' */
  Torque_Vectoring_Controller_d_B.P_elec =
    Torque_Vectoring_Controller_d_B.sensors.P_elec;

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_0' */
  Torque_Vectoring_Controller_d_B.ax_gy =
    Torque_Vectoring_Controller_d_B.sensors.ax;

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_1' */
  Torque_Vectoring_Controller_d_B.ay_f =
    Torque_Vectoring_Controller_d_B.sensors.ay;

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_3' */
  Torque_Vectoring_Controller_d_B.yawRate =
    Torque_Vectoring_Controller_d_B.sensors.yawRate;

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_2' */
  Torque_Vectoring_Controller_d_B.wheelspeed_c[0] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[0];

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_4' */
  Torque_Vectoring_Controller_d_B.wheelAngles[0] =
    Torque_Vectoring_Controller_d_B.sensors.wheelAngles[0];

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_2' */
  Torque_Vectoring_Controller_d_B.wheelspeed_c[1] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[1];

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_4' */
  Torque_Vectoring_Controller_d_B.wheelAngles[1] =
    Torque_Vectoring_Controller_d_B.sensors.wheelAngles[1];

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_2' */
  Torque_Vectoring_Controller_d_B.wheelspeed_c[2] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[2];

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_4' */
  Torque_Vectoring_Controller_d_B.wheelAngles[2] =
    Torque_Vectoring_Controller_d_B.sensors.wheelAngles[2];

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_2' */
  Torque_Vectoring_Controller_d_B.wheelspeed_c[3] =
    Torque_Vectoring_Controller_d_B.sensors.wheelspeed[3];

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_4' */
  Torque_Vectoring_Controller_d_B.wheelAngles[3] =
    Torque_Vectoring_Controller_d_B.sensors.wheelAngles[3];

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_5' */
  Torque_Vectoring_Controller_d_B.throttle =
    Torque_Vectoring_Controller_d_B.sensors.throttle;

  /* SignalConversion: '<S222>/SigConversion_InsertedFor_Bus Selector_at_outport_6' */
  Torque_Vectoring_Controller_d_B.brake =
    Torque_Vectoring_Controller_d_B.sensors.brake;
}

/* Model update function */
void Torque_Vectoring_Controller_dSpace_RTI1401_update(void)
{
  /* Update for Memory: '<S32>/Memory1' */
  Torque_Vectoring_Controller__DW.Memory1_PreviousInput =
    Torque_Vectoring_Controller_d_B.vFuzzy;

  /* Update for Memory: '<S8>/Memory' */
  Torque_Vectoring_Controller__DW.Memory_PreviousInput =
    Torque_Vectoring_Controller_d_B.v;

  /* Update for Memory: '<S8>/Memory3' */
  Torque_Vectoring_Controller__DW.Memory3_PreviousInput =
    Torque_Vectoring_Controller_d_B.v;

  /* Update for Memory: '<S8>/Memory1' */
  Torque_Vectoring_Controller__DW.Memory1_PreviousInput_c =
    Torque_Vectoring_Controller_d_B.v;

  /* Update for Memory: '<S8>/Memory2' */
  Torque_Vectoring_Controller__DW.Memory2_PreviousInput =
    Torque_Vectoring_Controller_d_B.v;

  /* Update for Memory: '<S8>/Memory4' */
  Torque_Vectoring_Controller__DW.Memory4_PreviousInput =
    Torque_Vectoring_Controller_d_B.v;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Torque_Vectoring_Controller__M->Timing.clockTick0)) {
    ++Torque_Vectoring_Controller__M->Timing.clockTickH0;
  }

  Torque_Vectoring_Controller__M->Timing.taskTime0 =
    Torque_Vectoring_Controller__M->Timing.clockTick0 *
    Torque_Vectoring_Controller__M->Timing.stepSize0 +
    Torque_Vectoring_Controller__M->Timing.clockTickH0 *
    Torque_Vectoring_Controller__M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Torque_Vectoring_Controller_dSpace_RTI1401_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Torque_Vectoring_Controller__M, 0,
                sizeof(RT_MODEL_Torque_Vectoring_Con_T));
  Torque_Vectoring_Controller__M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &Torque_Vectoring_Controller_d_B), 0,
                sizeof(B_Torque_Vectoring_Controller_T));

  /* states (dwork) */
  (void) memset((void *)&Torque_Vectoring_Controller__DW, 0,
                sizeof(DW_Torque_Vectoring_Controlle_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Torque_Vectoring_Controller_dSpace_RTI1401_rti_init_trc_pointers();
  }

  /* InitializeConditions for Memory: '<S32>/Memory1' */
  Torque_Vectoring_Controller__DW.Memory1_PreviousInput =
    Torque_Vectoring_Controller_d_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S8>/Memory' */
  Torque_Vectoring_Controller__DW.Memory_PreviousInput =
    Torque_Vectoring_Controller_d_P.Memory_X0;

  /* InitializeConditions for Memory: '<S8>/Memory3' */
  Torque_Vectoring_Controller__DW.Memory3_PreviousInput =
    Torque_Vectoring_Controller_d_P.Memory3_X0;

  /* InitializeConditions for Memory: '<S8>/Memory1' */
  Torque_Vectoring_Controller__DW.Memory1_PreviousInput_c =
    Torque_Vectoring_Controller_d_P.Memory1_X0_k;

  /* InitializeConditions for Memory: '<S8>/Memory2' */
  Torque_Vectoring_Controller__DW.Memory2_PreviousInput =
    Torque_Vectoring_Controller_d_P.Memory2_X0;

  /* InitializeConditions for Memory: '<S8>/Memory4' */
  Torque_Vectoring_Controller__DW.Memory4_PreviousInput =
    Torque_Vectoring_Controller_d_P.Memory4_X0;

  /* SystemInitialize for MATLAB Function: '<S32>/FuzzyVelicityGenerator' */
  Torque_Vectoring_Controller__DW.vFuzzyPrev = 0.0;

  /* SystemInitialize for MATLAB Function: '<S8>/Fx Estimator ' */
  Torque_Vectoring_Controller__DW.inertia_not_empty = false;
  Torque_Vectoring_Controller__DW.wheelspeedPrev[0] = 0.0;
  Torque_Vectoring_Controller__DW.wheelspeedPrev[1] = 0.0;
  Torque_Vectoring_Controller__DW.wheelspeedPrev[2] = 0.0;
  Torque_Vectoring_Controller__DW.wheelspeedPrev[3] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S8>/Fy Estimator ' */
  Torque_Vectoring_Controller__DW.yawRatePrev_not_empty = false;
  Torque_Vectoring_Controller__DW.FzRatioFront_not_empty = false;
  Torque_Vectoring_Controller__DW.FzRatioRear_not_empty = false;

  /* SystemInitialize for MATLAB Function: '<S8>/Efficiency Estimator' */
  Torque_Vectoring_Controller__DW.effTemp = 0.7;
  Torque_Vectoring_Controller__DW.errorInt = 0.0;

  /* SystemInitialize for MATLAB Function: '<S5>/Yaw Rate Control' */
  Torque_Vectoring_Controller__DW.Mz_memory = 0.0;
  Torque_Vectoring_Controller__DW.errorInt_a = 0.0;
  Torque_Vectoring_Controller__DW.prevError = 0.0;
  Torque_Vectoring_Controller__DW.prevWheelAngle = 0.0;
  Torque_Vectoring_Controller__DW.prevRref = 0.0;

  /* SystemInitialize for MATLAB Function: '<S5>/Traction Control' */
  memset(&Torque_Vectoring_Controller__DW.slipVector[0], 0, 24U * sizeof(real_T));
  memset(&Torque_Vectoring_Controller__DW.FxVector[0], 0, 24U * sizeof(real_T));
  Torque_Vectoring_Controller__DW.errorInt_j[0] = 0.0;
  Torque_Vectoring_Controller__DW.errorD[0] = 0.0;
  Torque_Vectoring_Controller__DW.errorPrev[0] = 0.0;
  Torque_Vectoring_Controller__DW.TiPrev[0] = 0.0;
  Torque_Vectoring_Controller__DW.errorInt2[0] = 0.0;
  Torque_Vectoring_Controller__DW.Ti[0] = 0.0;
  Torque_Vectoring_Controller__DW.Ti2[0] = 0.0;
  Torque_Vectoring_Controller__DW.errorInt_j[1] = 0.0;
  Torque_Vectoring_Controller__DW.errorD[1] = 0.0;
  Torque_Vectoring_Controller__DW.errorPrev[1] = 0.0;
  Torque_Vectoring_Controller__DW.TiPrev[1] = 0.0;
  Torque_Vectoring_Controller__DW.errorInt2[1] = 0.0;
  Torque_Vectoring_Controller__DW.Ti[1] = 0.0;
  Torque_Vectoring_Controller__DW.Ti2[1] = 0.0;
  Torque_Vectoring_Controller__DW.errorInt_j[2] = 0.0;
  Torque_Vectoring_Controller__DW.errorD[2] = 0.0;
  Torque_Vectoring_Controller__DW.errorPrev[2] = 0.0;
  Torque_Vectoring_Controller__DW.TiPrev[2] = 0.0;
  Torque_Vectoring_Controller__DW.errorInt2[2] = 0.0;
  Torque_Vectoring_Controller__DW.Ti[2] = 0.0;
  Torque_Vectoring_Controller__DW.Ti2[2] = 0.0;
  Torque_Vectoring_Controller__DW.errorInt_j[3] = 0.0;
  Torque_Vectoring_Controller__DW.errorD[3] = 0.0;
  Torque_Vectoring_Controller__DW.errorPrev[3] = 0.0;
  Torque_Vectoring_Controller__DW.TiPrev[3] = 0.0;
  Torque_Vectoring_Controller__DW.errorInt2[3] = 0.0;
  Torque_Vectoring_Controller__DW.Ti[3] = 0.0;
  Torque_Vectoring_Controller__DW.Ti2[3] = 0.0;
}

/* Model terminate function */
void Torque_Vectoring_Controller_dSpace_RTI1401_terminate(void)
{
  /* (no terminate code required) */
}
