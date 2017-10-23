/*
 * Torque_Vectoring_Controller_dSpace_RTI1401_types.h
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

#ifndef RTW_HEADER_Torque_Vectoring_Controller_dSpace_RTI1401_types_h_
#define RTW_HEADER_Torque_Vectoring_Controller_dSpace_RTI1401_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_settingBus_
#define DEFINED_TYPEDEF_FOR_settingBus_

typedef struct {
  real_T velocityEstimation;
  real_T torqueMode;
  real_T YRC;
  real_T YRCMode;
  real_T distributorMode;
  real_T Fsens;
  real_T Fxsens;
  real_T TC;
  real_T unlimitedFx;
  real_T TV_bypass;
  real_T effEstimation;
} settingBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_variableBus_
#define DEFINED_TYPEDEF_FOR_variableBus_

typedef struct {
  real_T TD_percentage;
} variableBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_aeroBus_
#define DEFINED_TYPEDEF_FOR_aeroBus_

typedef struct {
  real_T FD;
  real_T FL;
  real_T lever_FD[2];
  real_T lever_FL[2];
} aeroBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_estimParBus_
#define DEFINED_TYPEDEF_FOR_estimParBus_

typedef struct {
  real_T v;
  real_T Fzi[4];
  real_T Fxi[4];
  real_T Fyi[4];
  real_T rref;
  real_T mu[4];
  real_T slip[4];
  real_T eff;
} estimParBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_sensorBus_
#define DEFINED_TYPEDEF_FOR_sensorBus_

typedef struct {
  real_T ax;
  real_T ay;
  real_T wheelspeed[4];
  real_T yawRate;
  real_T steerAngle;
  real_T wheelAngles[4];
  real_T throttle;
  real_T brake;
  real_T torque[4];
  real_T ax_error;
  real_T ay_error;
  real_T yawRate_error;
  real_T knob1;
  real_T knob2;
  real_T P_elec;
} sensorBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_5c66W48nDdAJoq2yy1HutG_
#define DEFINED_TYPEDEF_FOR_struct_5c66W48nDdAJoq2yy1HutG_

typedef struct {
  real_T minV;
  real_T Kp;
  real_T Ki;
  real_T Kd;
  real_T Ks;
  real_T intLimit;
  real_T changeVelocity;
  real_T slope;
  real_T maxValue;
  real_T Kr;
} struct_5c66W48nDdAJoq2yy1HutG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_cWG5y6wKg8Ai7O0hv2EfQD_
#define DEFINED_TYPEDEF_FOR_struct_cWG5y6wKg8Ai7O0hv2EfQD_

typedef struct {
  real_T Tmax[4];
  real_T Inertia;
  real_T rpmMax[4];
} struct_cWG5y6wKg8Ai7O0hv2EfQD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_mZYSMNnYSHxP9gu8lDob5D_
#define DEFINED_TYPEDEF_FOR_struct_mZYSMNnYSHxP9gu8lDob5D_

typedef struct {
  real_T slipSetAcc;
  real_T slipSetBrake;
} struct_mZYSMNnYSHxP9gu8lDob5D;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_a6ICb3nu3ulcoTWeQ38NBH_
#define DEFINED_TYPEDEF_FOR_struct_a6ICb3nu3ulcoTWeQ38NBH_

typedef struct {
  real_T safetyMargin;
  real_T Kp;
  real_T Ki;
  real_T maxEff;
  real_T minEff;
} struct_a6ICb3nu3ulcoTWeQ38NBH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_NZF8CyDbFf22HYyIBv7HBG_
#define DEFINED_TYPEDEF_FOR_struct_NZF8CyDbFf22HYyIBv7HBG_

typedef struct {
  real_T g;
  real_T rhoAir;
  real_T Pmax;
  real_T Pmin;
  real_T riderMass;
  real_T vehicleMass;
  real_T mass;
  real_T h;
  real_T tw;
  real_T wb;
  real_T lr;
  real_T lf;
  real_T yawInertia;
  real_T gearRatio;
  real_T mu;
  real_T tireRadius;
  real_T tireMass;
  real_T tireInertia;
  real_T tireResist;
  real_T Cl;
  real_T Cd;
  real_T AFront;
  real_T fECU;
  real_T dt;
  struct_5c66W48nDdAJoq2yy1HutG YRC;
  struct_cWG5y6wKg8Ai7O0hv2EfQD motor;
  real_T MzMax;
  struct_mZYSMNnYSHxP9gu8lDob5D TC;
  real_T TC_mu;
  real_T Pmax_bypass;
  struct_a6ICb3nu3ulcoTWeQ38NBH PC;
} struct_NZF8CyDbFf22HYyIBv7HBG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_87V4bcTafp6scUX7wj9nvD_
#define DEFINED_TYPEDEF_FOR_struct_87V4bcTafp6scUX7wj9nvD_

typedef struct {
  real_T scaleFactorFy;
} struct_87V4bcTafp6scUX7wj9nvD;

#endif

/* Parameters for system: '<S43>/Action: One' */
typedef struct P_ActionOne_Torque_Vectoring__T_ P_ActionOne_Torque_Vectoring__T;

/* Parameters for system: '<S108>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_Torque_Ve_T_ P_IfActionSubsystem_Torque_Ve_T;

/* Parameters (auto storage) */
typedef struct P_Torque_Vectoring_Controller_T_ P_Torque_Vectoring_Controller_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Torque_Vectoring_Cont_T RT_MODEL_Torque_Vectoring_Con_T;

#endif                                 /* RTW_HEADER_Torque_Vectoring_Controller_dSpace_RTI1401_types_h_ */
