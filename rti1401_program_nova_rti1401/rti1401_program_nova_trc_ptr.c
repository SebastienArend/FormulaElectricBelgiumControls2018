/***************************************************************************

   Source file rti1401_program_nova_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 7.7 (02-Nov-2016)
   Wed Jul 12 12:30:48 2017

   Copyright 2017, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "rti1401_program_nova_trc_ptr.h"
#include "rti1401_program_nova.h"
#include "rti1401_program_nova_private.h"

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
volatile real_T *p_0_rti1401_program_nova_real_T_0 = NULL;
volatile sensorBus *p_0_rti1401_program_nova_sensorBus_1 = NULL;
volatile estimParBus *p_0_rti1401_program_nova_estimParBus_2 = NULL;
volatile settingBus *p_0_rti1401_program_nova_settingBus_3 = NULL;
volatile aeroBus *p_0_rti1401_program_nova_aeroBus_4 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_5 = NULL;
volatile uint32_T *p_0_rti1401_program_nova_uint32_T_6 = NULL;
volatile int16_T *p_0_rti1401_program_nova_int16_T_7 = NULL;
volatile uint16_T *p_0_rti1401_program_nova_uint16_T_8 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_9 = NULL;
volatile boolean_T *p_0_rti1401_program_nova_boolean_T_10 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_11 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_12 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_13 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_14 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_15 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_16 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_17 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_18 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_19 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_20 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_21 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_22 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_23 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_24 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_25 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_26 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_27 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_28 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_29 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_30 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_31 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_32 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_33 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_34 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_35 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_36 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_37 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_38 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_39 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_40 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_41 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_42 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_43 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_44 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_45 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_46 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_47 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_48 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_49 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_50 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_51 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_52 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_53 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_54 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_55 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_56 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_57 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_58 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_59 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_60 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_61 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_62 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_63 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_64 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_65 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_66 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_67 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_68 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_69 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_70 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_71 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_72 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_73 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_74 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_75 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_76 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_77 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_78 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_79 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_80 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_81 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_82 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_83 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_84 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_85 = NULL;
volatile real_T *p_0_rti1401_program_nova_real_T_86 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_87 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_88 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_89 = NULL;
volatile uint8_T *p_0_rti1401_program_nova_uint8_T_90 = NULL;
volatile uint16_T *p_0_rti1401_program_nova_uint16_T_91 = NULL;
volatile uint16_T *p_0_rti1401_program_nova_uint16_T_92 = NULL;
volatile struct_AvVMk63fJe4OGQBCiX9pXB
  *p_1_rti1401_program_nova_struct_AvVMk63fJe4OGQBCiX9pXB_0 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_1 = NULL;
volatile uint16_T *p_1_rti1401_program_nova_uint16_T_2 = NULL;
volatile boolean_T *p_1_rti1401_program_nova_boolean_T_3 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_4 = NULL;
volatile uint32_T *p_1_rti1401_program_nova_uint32_T_5 = NULL;
volatile uint16_T *p_1_rti1401_program_nova_uint16_T_6 = NULL;
volatile uint8_T *p_1_rti1401_program_nova_uint8_T_7 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_8 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_9 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_10 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_11 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_12 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_13 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_14 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_15 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_16 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_17 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_18 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_19 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_20 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_21 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_22 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_23 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_24 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_25 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_26 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_27 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_28 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_29 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_30 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_31 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_32 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_33 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_34 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_35 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_36 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_37 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_38 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_39 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_40 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_41 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_42 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_43 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_44 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_45 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_46 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_47 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_48 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_49 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_50 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_51 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_52 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_53 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_54 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_55 = NULL;
volatile real_T *p_1_rti1401_program_nova_real_T_56 = NULL;
volatile real_T *p_2_rti1401_program_nova_real_T_0 = NULL;
volatile int_T *p_2_rti1401_program_nova_int_T_1 = NULL;
volatile uint8_T *p_2_rti1401_program_nova_uint8_T_2 = NULL;
volatile boolean_T *p_2_rti1401_program_nova_boolean_T_3 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_rti1401_program_nova_real_T_0 = &rti1401_program_nova_B.impMethod_j[0];
  p_0_rti1401_program_nova_sensorBus_1 =
    &rti1401_program_nova_B.BusConversion_InsertedFor_Power;
  p_0_rti1401_program_nova_estimParBus_2 =
    &rti1401_program_nova_B.BusConversion_InsertedFor_Pow_h;
  p_0_rti1401_program_nova_settingBus_3 =
    &rti1401_program_nova_B.BusConversion_InsertedFor_Pow_a;
  p_0_rti1401_program_nova_aeroBus_4 = &rti1401_program_nova_B.aero;
  p_0_rti1401_program_nova_real_T_5 = &rti1401_program_nova_B.throttle;
  p_0_rti1401_program_nova_uint32_T_6 = &rti1401_program_nova_B.SFunction1_o2_j;
  p_0_rti1401_program_nova_int16_T_7 = &rti1401_program_nova_B.SFunction1_o2_i;
  p_0_rti1401_program_nova_uint16_T_8 = &rti1401_program_nova_B.SFunction1_o1_a;
  p_0_rti1401_program_nova_uint8_T_9 =
    &rti1401_program_nova_B.DataTypeConversion;
  p_0_rti1401_program_nova_boolean_T_10 =
    &rti1401_program_nova_B.LogicalOperator;
  p_0_rti1401_program_nova_uint8_T_11 = &rti1401_program_nova_B.BitSlice9.y;
  p_0_rti1401_program_nova_uint8_T_12 = &rti1401_program_nova_B.BitSlice8.y;
  p_0_rti1401_program_nova_uint8_T_13 = &rti1401_program_nova_B.BitSlice7.y;
  p_0_rti1401_program_nova_uint8_T_14 = &rti1401_program_nova_B.BitSlice6.y;
  p_0_rti1401_program_nova_uint8_T_15 = &rti1401_program_nova_B.BitSlice5.y;
  p_0_rti1401_program_nova_uint8_T_16 = &rti1401_program_nova_B.BitSlice4.y;
  p_0_rti1401_program_nova_uint8_T_17 = &rti1401_program_nova_B.BitSlice31.y;
  p_0_rti1401_program_nova_uint8_T_18 = &rti1401_program_nova_B.BitSlice30.y;
  p_0_rti1401_program_nova_uint8_T_19 = &rti1401_program_nova_B.BitSlice3.y;
  p_0_rti1401_program_nova_uint8_T_20 = &rti1401_program_nova_B.BitSlice29.y;
  p_0_rti1401_program_nova_uint8_T_21 = &rti1401_program_nova_B.BitSlice28.y;
  p_0_rti1401_program_nova_uint8_T_22 = &rti1401_program_nova_B.BitSlice27.y;
  p_0_rti1401_program_nova_uint8_T_23 = &rti1401_program_nova_B.BitSlice26.y;
  p_0_rti1401_program_nova_uint8_T_24 = &rti1401_program_nova_B.BitSlice25.y;
  p_0_rti1401_program_nova_uint8_T_25 = &rti1401_program_nova_B.BitSlice24.y;
  p_0_rti1401_program_nova_uint8_T_26 = &rti1401_program_nova_B.BitSlice23.y;
  p_0_rti1401_program_nova_uint8_T_27 = &rti1401_program_nova_B.BitSlice22.y;
  p_0_rti1401_program_nova_uint8_T_28 = &rti1401_program_nova_B.BitSlice21.y;
  p_0_rti1401_program_nova_uint8_T_29 = &rti1401_program_nova_B.BitSlice20.y;
  p_0_rti1401_program_nova_uint8_T_30 = &rti1401_program_nova_B.BitSlice2.y;
  p_0_rti1401_program_nova_uint8_T_31 = &rti1401_program_nova_B.BitSlice19.y;
  p_0_rti1401_program_nova_uint8_T_32 = &rti1401_program_nova_B.BitSlice18.y;
  p_0_rti1401_program_nova_uint8_T_33 = &rti1401_program_nova_B.BitSlice17.y;
  p_0_rti1401_program_nova_uint8_T_34 = &rti1401_program_nova_B.BitSlice16.y;
  p_0_rti1401_program_nova_uint8_T_35 = &rti1401_program_nova_B.BitSlice15.y;
  p_0_rti1401_program_nova_uint8_T_36 = &rti1401_program_nova_B.BitSlice14.y;
  p_0_rti1401_program_nova_uint8_T_37 = &rti1401_program_nova_B.BitSlice13.y;
  p_0_rti1401_program_nova_uint8_T_38 = &rti1401_program_nova_B.BitSlice12.y;
  p_0_rti1401_program_nova_uint8_T_39 = &rti1401_program_nova_B.BitSlice11.y;
  p_0_rti1401_program_nova_uint8_T_40 = &rti1401_program_nova_B.BitSlice10.y;
  p_0_rti1401_program_nova_uint8_T_41 = &rti1401_program_nova_B.BitSlice1.y;
  p_0_rti1401_program_nova_uint8_T_42 = &rti1401_program_nova_B.BitSlice.y;
  p_0_rti1401_program_nova_real_T_43 =
    &rti1401_program_nova_B.IfActionSubsystem3_b.dc;
  p_0_rti1401_program_nova_real_T_44 =
    &rti1401_program_nova_B.IfActionSubsystem1_a.xa;
  p_0_rti1401_program_nova_real_T_45 =
    &rti1401_program_nova_B.IfActionSubsystem3_nz.dc;
  p_0_rti1401_program_nova_real_T_46 =
    &rti1401_program_nova_B.IfActionSubsystem1_f.xa;
  p_0_rti1401_program_nova_real_T_47 =
    &rti1401_program_nova_B.IfActionSubsystem3_o.dc;
  p_0_rti1401_program_nova_real_T_48 =
    &rti1401_program_nova_B.IfActionSubsystem1_gg.xa;
  p_0_rti1401_program_nova_real_T_49 =
    &rti1401_program_nova_B.IfActionSubsystem3_er.dc;
  p_0_rti1401_program_nova_real_T_50 =
    &rti1401_program_nova_B.IfActionSubsystem1_jz.xa;
  p_0_rti1401_program_nova_real_T_51 =
    &rti1401_program_nova_B.IfActionSubsystem3_ki.dc;
  p_0_rti1401_program_nova_real_T_52 =
    &rti1401_program_nova_B.IfActionSubsystem1_ea.xa;
  p_0_rti1401_program_nova_real_T_53 =
    &rti1401_program_nova_B.IfActionSubsystem3_hb.dc;
  p_0_rti1401_program_nova_real_T_54 =
    &rti1401_program_nova_B.IfActionSubsystem1_c3.xa;
  p_0_rti1401_program_nova_real_T_55 =
    &rti1401_program_nova_B.IfActionSubsystem3_bfu.dc;
  p_0_rti1401_program_nova_real_T_56 =
    &rti1401_program_nova_B.IfActionSubsystem1_ic.xa;
  p_0_rti1401_program_nova_real_T_57 =
    &rti1401_program_nova_B.IfActionSubsystem3_h2.dc;
  p_0_rti1401_program_nova_real_T_58 =
    &rti1401_program_nova_B.IfActionSubsystem1_oq.xa;
  p_0_rti1401_program_nova_real_T_59 =
    &rti1401_program_nova_B.IfActionSubsystem3_bf.dc;
  p_0_rti1401_program_nova_real_T_60 =
    &rti1401_program_nova_B.IfActionSubsystem1_b.xa;
  p_0_rti1401_program_nova_real_T_61 =
    &rti1401_program_nova_B.IfActionSubsystem3_i.dc;
  p_0_rti1401_program_nova_real_T_62 =
    &rti1401_program_nova_B.IfActionSubsystem1_j.xa;
  p_0_rti1401_program_nova_real_T_63 =
    &rti1401_program_nova_B.IfActionSubsystem3_h.dc;
  p_0_rti1401_program_nova_real_T_64 =
    &rti1401_program_nova_B.IfActionSubsystem1_g.xa;
  p_0_rti1401_program_nova_real_T_65 =
    &rti1401_program_nova_B.IfActionSubsystem3_bs.dc;
  p_0_rti1401_program_nova_real_T_66 =
    &rti1401_program_nova_B.IfActionSubsystem1_k.xa;
  p_0_rti1401_program_nova_real_T_67 =
    &rti1401_program_nova_B.IfActionSubsystem3_f.dc;
  p_0_rti1401_program_nova_real_T_68 =
    &rti1401_program_nova_B.IfActionSubsystem1_e.xa;
  p_0_rti1401_program_nova_real_T_69 =
    &rti1401_program_nova_B.IfActionSubsystem3_k.dc;
  p_0_rti1401_program_nova_real_T_70 =
    &rti1401_program_nova_B.IfActionSubsystem1_nx.xa;
  p_0_rti1401_program_nova_real_T_71 =
    &rti1401_program_nova_B.IfActionSubsystem3_e.dc;
  p_0_rti1401_program_nova_real_T_72 =
    &rti1401_program_nova_B.IfActionSubsystem1_c.xa;
  p_0_rti1401_program_nova_real_T_73 =
    &rti1401_program_nova_B.IfActionSubsystem3_n1.dc;
  p_0_rti1401_program_nova_real_T_74 =
    &rti1401_program_nova_B.IfActionSubsystem1_d.xa;
  p_0_rti1401_program_nova_real_T_75 =
    &rti1401_program_nova_B.IfActionSubsystem3_l.dc;
  p_0_rti1401_program_nova_real_T_76 =
    &rti1401_program_nova_B.IfActionSubsystem1_h.xa;
  p_0_rti1401_program_nova_real_T_77 =
    &rti1401_program_nova_B.IfActionSubsystem3_d.dc;
  p_0_rti1401_program_nova_real_T_78 =
    &rti1401_program_nova_B.IfActionSubsystem1_n.xa;
  p_0_rti1401_program_nova_real_T_79 =
    &rti1401_program_nova_B.IfActionSubsystem3_bo.dc;
  p_0_rti1401_program_nova_real_T_80 =
    &rti1401_program_nova_B.IfActionSubsystem1_o.xa;
  p_0_rti1401_program_nova_real_T_81 =
    &rti1401_program_nova_B.IfActionSubsystem3.dc;
  p_0_rti1401_program_nova_real_T_82 =
    &rti1401_program_nova_B.IfActionSubsystem1.xa;
  p_0_rti1401_program_nova_real_T_83 =
    &rti1401_program_nova_B.IfActionSubsystem3_n.dc;
  p_0_rti1401_program_nova_real_T_84 =
    &rti1401_program_nova_B.IfActionSubsystem1_l.xa;
  p_0_rti1401_program_nova_real_T_85 =
    &rti1401_program_nova_B.IfActionSubsystem3_nu.dc;
  p_0_rti1401_program_nova_real_T_86 =
    &rti1401_program_nova_B.IfActionSubsystem1_i.xa;
  p_0_rti1401_program_nova_uint8_T_87 =
    &rti1401_program_nova_B.sf_Merge_bits3.AMK_Control;
  p_0_rti1401_program_nova_uint8_T_88 =
    &rti1401_program_nova_B.sf_Merge_bits2.AMK_Control;
  p_0_rti1401_program_nova_uint8_T_89 =
    &rti1401_program_nova_B.sf_Merge_bits1.AMK_Control;
  p_0_rti1401_program_nova_uint8_T_90 =
    &rti1401_program_nova_B.sf_Merge_bits.AMK_Control;
  p_0_rti1401_program_nova_uint16_T_91 = &rti1401_program_nova_B.sf_Brake2perc.y;
  p_0_rti1401_program_nova_uint16_T_92 = &rti1401_program_nova_B.sf_Brake1perc.y;
  p_1_rti1401_program_nova_struct_AvVMk63fJe4OGQBCiX9pXB_0 =
    &rti1401_program_nova_P.car;
  p_1_rti1401_program_nova_real_T_1 = &rti1401_program_nova_P.Throttle_limits[0];
  p_1_rti1401_program_nova_uint16_T_2 =
    &rti1401_program_nova_P.CompareToConstant_const_b;
  p_1_rti1401_program_nova_boolean_T_3 =
    &rti1401_program_nova_P.CompareToConstant3_const;
  p_1_rti1401_program_nova_real_T_4 = &rti1401_program_nova_P.MidRange_Value[0];
  p_1_rti1401_program_nova_uint32_T_5 =
    &rti1401_program_nova_P.Delay_DelayLength;
  p_1_rti1401_program_nova_uint16_T_6 = &rti1401_program_nova_P.Throttle2_Value;
  p_1_rti1401_program_nova_uint8_T_7 = &rti1401_program_nova_P.TV_Value;
  p_1_rti1401_program_nova_real_T_8 =
    &rti1401_program_nova_P.IfActionSubsystem2_j.u_Value;
  p_1_rti1401_program_nova_real_T_9 =
    &rti1401_program_nova_P.IfActionSubsystem_h.u_Value;
  p_1_rti1401_program_nova_real_T_10 =
    &rti1401_program_nova_P.IfActionSubsystem2_js.u_Value;
  p_1_rti1401_program_nova_real_T_11 =
    &rti1401_program_nova_P.IfActionSubsystem_b.u_Value;
  p_1_rti1401_program_nova_real_T_12 =
    &rti1401_program_nova_P.IfActionSubsystem2_lh.u_Value;
  p_1_rti1401_program_nova_real_T_13 =
    &rti1401_program_nova_P.IfActionSubsystem_nt.u_Value;
  p_1_rti1401_program_nova_real_T_14 =
    &rti1401_program_nova_P.IfActionSubsystem2_li.u_Value;
  p_1_rti1401_program_nova_real_T_15 =
    &rti1401_program_nova_P.IfActionSubsystem_aa.u_Value;
  p_1_rti1401_program_nova_real_T_16 =
    &rti1401_program_nova_P.IfActionSubsystem2_pi.u_Value;
  p_1_rti1401_program_nova_real_T_17 =
    &rti1401_program_nova_P.IfActionSubsystem_c.u_Value;
  p_1_rti1401_program_nova_real_T_18 =
    &rti1401_program_nova_P.IfActionSubsystem2_p2.u_Value;
  p_1_rti1401_program_nova_real_T_19 =
    &rti1401_program_nova_P.IfActionSubsystem_cw.u_Value;
  p_1_rti1401_program_nova_real_T_20 =
    &rti1401_program_nova_P.IfActionSubsystem2_am.u_Value;
  p_1_rti1401_program_nova_real_T_21 =
    &rti1401_program_nova_P.IfActionSubsystem_ny.u_Value;
  p_1_rti1401_program_nova_real_T_22 =
    &rti1401_program_nova_P.IfActionSubsystem2_l.u_Value;
  p_1_rti1401_program_nova_real_T_23 =
    &rti1401_program_nova_P.IfActionSubsystem_hm.u_Value;
  p_1_rti1401_program_nova_real_T_24 =
    &rti1401_program_nova_P.IfActionSubsystem2_d.u_Value;
  p_1_rti1401_program_nova_real_T_25 =
    &rti1401_program_nova_P.IfActionSubsystem_oz.u_Value;
  p_1_rti1401_program_nova_real_T_26 =
    &rti1401_program_nova_P.IfActionSubsystem2_f.u_Value;
  p_1_rti1401_program_nova_real_T_27 =
    &rti1401_program_nova_P.IfActionSubsystem_e5.u_Value;
  p_1_rti1401_program_nova_real_T_28 =
    &rti1401_program_nova_P.IfActionSubsystem2_fc.u_Value;
  p_1_rti1401_program_nova_real_T_29 =
    &rti1401_program_nova_P.IfActionSubsystem_js.u_Value;
  p_1_rti1401_program_nova_real_T_30 =
    &rti1401_program_nova_P.IfActionSubsystem2_n.u_Value;
  p_1_rti1401_program_nova_real_T_31 =
    &rti1401_program_nova_P.IfActionSubsystem_l.u_Value;
  p_1_rti1401_program_nova_real_T_32 =
    &rti1401_program_nova_P.IfActionSubsystem2_jg.u_Value;
  p_1_rti1401_program_nova_real_T_33 =
    &rti1401_program_nova_P.IfActionSubsystem_e.u_Value;
  p_1_rti1401_program_nova_real_T_34 =
    &rti1401_program_nova_P.IfActionSubsystem2_e.u_Value;
  p_1_rti1401_program_nova_real_T_35 =
    &rti1401_program_nova_P.IfActionSubsystem_bo.u_Value;
  p_1_rti1401_program_nova_real_T_36 =
    &rti1401_program_nova_P.IfActionSubsystem2_c.u_Value;
  p_1_rti1401_program_nova_real_T_37 =
    &rti1401_program_nova_P.IfActionSubsystem_n.u_Value;
  p_1_rti1401_program_nova_real_T_38 =
    &rti1401_program_nova_P.IfActionSubsystem2_k.u_Value;
  p_1_rti1401_program_nova_real_T_39 =
    &rti1401_program_nova_P.IfActionSubsystem_i.u_Value;
  p_1_rti1401_program_nova_real_T_40 =
    &rti1401_program_nova_P.IfActionSubsystem2_a.u_Value;
  p_1_rti1401_program_nova_real_T_41 =
    &rti1401_program_nova_P.IfActionSubsystem_m.u_Value;
  p_1_rti1401_program_nova_real_T_42 =
    &rti1401_program_nova_P.IfActionSubsystem2_i.u_Value;
  p_1_rti1401_program_nova_real_T_43 =
    &rti1401_program_nova_P.IfActionSubsystem_j.u_Value;
  p_1_rti1401_program_nova_real_T_44 =
    &rti1401_program_nova_P.IfActionSubsystem2_jk.u_Value;
  p_1_rti1401_program_nova_real_T_45 =
    &rti1401_program_nova_P.IfActionSubsystem_a.u_Value;
  p_1_rti1401_program_nova_real_T_46 =
    &rti1401_program_nova_P.IfActionSubsystem2.u_Value;
  p_1_rti1401_program_nova_real_T_47 =
    &rti1401_program_nova_P.IfActionSubsystem.u_Value;
  p_1_rti1401_program_nova_real_T_48 =
    &rti1401_program_nova_P.IfActionSubsystem2_p.u_Value;
  p_1_rti1401_program_nova_real_T_49 =
    &rti1401_program_nova_P.IfActionSubsystem_g.u_Value;
  p_1_rti1401_program_nova_real_T_50 =
    &rti1401_program_nova_P.IfActionSubsystem2_m.u_Value;
  p_1_rti1401_program_nova_real_T_51 =
    &rti1401_program_nova_P.IfActionSubsystem_o.u_Value;
  p_1_rti1401_program_nova_real_T_52 =
    &rti1401_program_nova_P.ActionOne_j.One_Value;
  p_1_rti1401_program_nova_real_T_53 =
    &rti1401_program_nova_P.ActionOne_e.One_Value;
  p_1_rti1401_program_nova_real_T_54 =
    &rti1401_program_nova_P.ActionOne_l.One_Value;
  p_1_rti1401_program_nova_real_T_55 =
    &rti1401_program_nova_P.ActionOne_m.One_Value;
  p_1_rti1401_program_nova_real_T_56 =
    &rti1401_program_nova_P.ActionOne.One_Value;
  p_2_rti1401_program_nova_real_T_0 = &rti1401_program_nova_DW.Delay_DSTATE;
  p_2_rti1401_program_nova_int_T_1 = &rti1401_program_nova_DW.SFunction1_IWORK[0];
  p_2_rti1401_program_nova_uint8_T_2 =
    &rti1401_program_nova_DW.is_active_c19_rti1401_program_n;
  p_2_rti1401_program_nova_boolean_T_3 =
    &rti1401_program_nova_DW.yawRatePrev_not_empty;
}

void rti1401_program_nova_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
