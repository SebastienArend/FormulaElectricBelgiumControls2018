close all
clear all
car.gearRatio=15;
car.tireRadius=0.5;

motorSpeed = [0 16000 20000]; 
motorTorque = [21 21 15];

xq = 0:20000;

figure
vq1 = interp1(motorSpeed,motorTorque,xq);
plot(motorSpeed,motorTorque,'o',xq,vq1,':.');

title('(Default) Linear Interpolation');

FxmaxMax = car.gearRatio.*vq1./car.tireRadius;
figure
plot(FxmaxMax)

% YRCBreakVelocity= 20;
% YRCSlope = 0.001;
% for vtotal = 1:100
%     speedGain(vtotal) = min(max(1 - (vtotal - YRCBreakVelocity)*YRCSlope,0),1);
% end
% figure
% plot(speedGain)
% 
% FxmaMmaxBreak= 16000;
% FxmaxMaxSlope = 6/(20000 - 16000);
% for FxmaxMax = 1:20000
%     speedGain(vtotal) = min(max(1 - (vtotal - YRCBreakVelocity)*YRCSlope,0),1);
% end
% figure
% plot(FxmaxMax)
