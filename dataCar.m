%% General Parameters
car.g = 9.81;           %[m/s^2]  %gravitational acceleration
car.rhoAir = 1.225;     %[kg/m^3] %air density
car.Pmax = 80000;          %[W]     %maximal power %constraint by FS %NAKIJKEN
car.Pmin = 0;          %[kW]     %minimal power                   %NAKIJKEN

%% Vehicle Parameters
car.riderMass = 70;                    %[kg]
car.vehicleMass = 215.22;              %[kg] wheels included
car.mass = ...
    car.riderMass + car.vehicleMass;   %[kg] 
car.h = 0.25342;                       %[m]  %height center of gravity %ground is reference
car.tw = 1.188;                        %[m]  %trackwidth
car.wb = 1.54;                         %[m]  %wheelbase
car.lr = 0.66162;                      %[m]  %distance COG to rear axle
car.lf = car.wb-car.lr;                %[m]  %distance COG to front axle
car.yawInertia = 48.82984982;          %[kgm^2] %yawInertia of the car
car.gearRatio = 15.12;                 %[-] % gear ratio for the wheels


%% Road Parameters
car.mu = 1;            

%% Tire Parameters
%Continental C17 Formula Student Competition Tyre
car.tireRadius = 0.2467;     %[m] CONTINENTAL FS 205 510 R13 80kPa
car.tireMass = 8.71;         %[kg] CONTINENTAL FS 205 510 R13 80kPa
car.tireInertia = 0.5*car.tireMass*car.tireRadius^2;      %[kg*m^2]
%car.inertia.Kp = 1.5*10^-7; %[-]
car.tireResist = 0.005;      %[-]      roll resistance
car.Cyf = 31512;             %[N/rad]  Cornering stiffness front wheel
car.Cyr = 31512;             %[N/rad]  Cornering stiffness rear wheel
car.Cx = 31512;             %[N/rad]  Longitudinal stiffness rear wheel

%% Aerodynamics
%To edit when known values
%Currently values according to IPG model
car.Cl = 0.1;       %[-]   %Lift coefficient
car.Cd = 0.2;       %[-]   %Drag coefficient
car.AFront = 1;     %[m^2] %Frontal area
%CHECK VALUES aero.lever_FD and aero.lever_FL in estimated par > aero
%% Electronics
%IMPORTANT: CHANGE fECU when we know actual value
%IMPORTANT: CHANGE operating speed in Simulink
car.fECU = 1000;     %[Hz]   %Operating frequency of the ECU
car.dt = 1/car.fECU; %[s]    %Sample time of the ECU

%% Yaw Rate Control
car.YRC.minV = 5/3.6; %[m/s] % Minimum speed for starting the Yaw Rate Control

car.YRC.Kp = 10;
car.YRC.Ki = 0;
car.YRC.Kd = 0;
car.YRC.Ks = 0;
car.YRC.Kr = 0;

car.YRC.intLimit = 1.0;      %Yaw rate control integral limit
car.YRC.changeVelocity = 15; %[m/s] %velocity at which the speedGain starts to decrease
car.YRC.slope = 0.05; %[-] % slope at which the speedGain decreases
car.YRC.maxValue = 800; %max value of Mz

%% Motor
car.motor.Tmax = [21;21;21;21]; %[Nm] % Max Torque for each motor in CM Model
car.motor.Inertia = 0.002; %[kgm^2] %Inertia of the motor % value of the IPG motor
                                   % value of FS AMK motor = 2.74e-4 kgm^2
car.motor.rpmMax = [20000;20000;20000;20000]; %[rpm] %max rpm of the motor
%car.motor.mass = 3.55; %[kg]

%% Torque Distributor
%variables.TD.percentage %[-] % limiting the maximum torque
car.MzMax = 350; %[Nm] limit max possible moment 
%opmerking: gebruiken we dit al in de torque distributor of pas later bij
%de power limiter?

motorSpeed = [0 16000 20000]; %this Torque-wheelspeed has to be finetuned during tests
motorTorque = [21 21 15];
xResolution = 0:20000; %resolution = 1
TorqueifvWheelspeed = interp1(motorSpeed,motorTorque,xResolution);
car.FxmaxMax = car.gearRatio.*TorqueifvWheelspeed./car.tireRadius;

%% Traction Control
car.TC.slipSetAcc = 0.1;     %[-] %Slip setpoints with acceleration
car.TC.slipSetBrake = -0.1;   %[-] %Slip setpoints with braking
car.TC_mu = car.mu;           %[-] %Edit when finetuning TC

%% Kalman Velocity Estimation
%car.kalmanVelocity.R = diag([1, 10]); % Measurement covariance R (v2 , v4)
%car.kalmanVelocity.Q = .1; % Process noice covariance Q (accelerometer)
%car.kalmanVelocity.accTreshold = 99;% [m/s²] Acceleration at which the kalman does not update with the wheels
%car.kalmanVelocity.velTreshold = 0.4;% [m/s] Speed at which kalman will use measurements

%% Bypass

car.Pmax_bypass = 70 * 1000; %[W] %maximum power during bypass

%% Fuzzy Estimator
fuzzyVelocityEstimatorConstant = readfis('fuzzyVelocityEstimatorConstant');

%% Power Checker

car.PC.safetyMargin = 1000; %[W] %Margin to max power (80kW) to which will be controlled
car.PC.Kp = 0.1;
car.PC.Ki = 0;
car.PC.maxEff = 0.9;
car.PC.minEff = 0.6;

%% Velocity Estimation
car.VelEst.Breakpoint = 5; %[m/s] % startpoint of the reducing of the velocity gain
car.VelEst.Slope = 0.01; % slope at wich the reducement of the velocity gain takes place

%% Safety
car.velMin = 0; %[m/s] %min possible estimated velocity
car.velMax = 40; %[m/s] %max possible estimated velocity
