/***************************************************************************

   Source file Torque_Vectoring_Controller_dSpace_RTI1401_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 7.7 (02-Nov-2016)
   Wed Apr 26 00:19:42 2017

   Copyright 2017, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "Torque_Vectoring_Controller_dSpace_RTI1401_trc_ptr.h"
#include "Torque_Vectoring_Controller_dSpace_RTI1401.h"
#include "Torque_Vectoring_Controller_dSpace_RTI1401_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_0 = NULL;
volatile sensorBus *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_sensorBus_1 =
  NULL;
volatile estimParBus
  *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_estimParBus_2 = NULL;
volatile settingBus *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_settingBus_3
  = NULL;
volatile aeroBus *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_aeroBus_4 =
  NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_5 = NULL;
volatile variableBus
  *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_variableBus_6 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_7 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_8 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_9 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_10 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_11 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_12 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_13 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_14 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_15 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_16 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_17 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_18 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_19 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_20 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_21 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_22 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_23 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_24 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_25 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_26 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_27 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_28 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_29 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_30 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_31 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_32 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_33 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_34 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_35 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_36 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_37 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_38 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_39 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_40 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_41 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_42 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_43 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_44 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_45 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_46 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_47 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_48 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_49 = NULL;
volatile real_T *p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_50 = NULL;
volatile struct_NZF8CyDbFf22HYyIBv7HBG
  *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_struct_NZF8CyDbFf22HYyIBv7HBG_0
  = NULL;
volatile struct_87V4bcTafp6scUX7wj9nvD
  *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_struct_87V4bcTafp6scUX7wj9nvD_1
  = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_2 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_3 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_4 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_5 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_6 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_7 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_8 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_9 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_10 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_11 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_12 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_13 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_14 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_15 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_16 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_17 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_18 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_19 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_20 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_21 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_22 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_23 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_24 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_25 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_26 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_27 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_28 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_29 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_30 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_31 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_32 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_33 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_34 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_35 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_36 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_37 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_38 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_39 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_40 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_41 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_42 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_43 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_44 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_45 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_46 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_47 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_48 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_49 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_50 = NULL;
volatile real_T *p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_51 = NULL;
volatile real_T *p_2_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_0 = NULL;
volatile boolean_T *p_2_Torque_Vectoring_Controller_dSpace_RTI1401_boolean_T_2 =
  NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_0 =
    &Torque_Vectoring_Controller_d_B.impMethod_f[0];
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_sensorBus_1 =
    &Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_YawRa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_estimParBus_2 =
    &Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_b;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_settingBus_3 =
    &Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_Yaw_p;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_aeroBus_4 =
    &Torque_Vectoring_Controller_d_B.aero;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_5 =
    &Torque_Vectoring_Controller_d_B.Memory1;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_variableBus_6 =
    &Torque_Vectoring_Controller_d_B.BusConversion_InsertedFor_MAT_e;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_7 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_o.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_8 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_p.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_9 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_a.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_10 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_pp.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_11 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_ne.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_12 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_on.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_13 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_n.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_14 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_f.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_15 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_h4.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_16 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_ni.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_17 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_fd.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_18 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_px.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_19 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_j.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_20 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_mg.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_21 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_ms.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_22 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_l.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_23 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_fi.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_24 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_n.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_25 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_m.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_26 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_gh.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_27 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_e.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_28 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_j.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_29 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_ey.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_30 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_gu.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_31 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_k2.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_32 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_o.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_33 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_k.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_34 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_h.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_35 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_h.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_36 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_a.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_37 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_f.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_38 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_m.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_39 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_c.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_40 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_al.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_41 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_g5.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_42 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_d.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_43 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_i.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_44 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_pc.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_45 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_46 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_47 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_g.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_48 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_b.xa;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_49 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem3_l.dc;
  p_0_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_50 =
    &Torque_Vectoring_Controller_d_B.IfActionSubsystem1_g.xa;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_struct_NZF8CyDbFf22HYyIBv7HBG_0
    = &Torque_Vectoring_Controller_d_P.car;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_struct_87V4bcTafp6scUX7wj9nvD_1
    = &Torque_Vectoring_Controller_d_P.optPar;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_2 =
    &Torque_Vectoring_Controller_d_P.in1mf3_a;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_3 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_j.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_4 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_b.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_5 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_m.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_6 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_l.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_7 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_ae.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_8 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_fz.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_9 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_ej.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_10 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_di.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_11 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_a.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_12 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_pe.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_13 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_d0.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_14 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_f.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_15 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_mo.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_16 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_n.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_17 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_gt.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_18 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_p.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_19 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_ds.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_20 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_ca.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_21 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_n.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_22 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_a.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_23 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_g.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_24 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_aw.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_25 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_js.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_26 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_d.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_27 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_b.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_28 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_j.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_29 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_e.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_30 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_h.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_31 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_mv.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_32 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_o.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_33 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_of.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_34 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_ch.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_35 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_h.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_36 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_oz.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_37 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_j3.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_38 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_it.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_39 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_d.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_40 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_c.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_41 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_42 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_43 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_k.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_44 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_i.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_45 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem2_o.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_46 =
    &Torque_Vectoring_Controller_d_P.IfActionSubsystem_g.u_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_47 =
    &Torque_Vectoring_Controller_d_P.ActionOne_c4.One_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_48 =
    &Torque_Vectoring_Controller_d_P.ActionOne_o.One_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_49 =
    &Torque_Vectoring_Controller_d_P.ActionOne_cn.One_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_50 =
    &Torque_Vectoring_Controller_d_P.ActionOne_c.One_Value;
  p_1_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_51 =
    &Torque_Vectoring_Controller_d_P.ActionOne.One_Value;
  p_2_Torque_Vectoring_Controller_dSpace_RTI1401_real_T_0 =
    &Torque_Vectoring_Controller__DW.Memory1_PreviousInput;
  p_2_Torque_Vectoring_Controller_dSpace_RTI1401_boolean_T_2 =
    &Torque_Vectoring_Controller__DW.yawRatePrev_not_empty;
}

void Torque_Vectoring_Controller_dSpace_RTI1401_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
