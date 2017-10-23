close all


%x = cmread

figure
subplot(211)
plot(x.Time.data, x.PT_Motor_Trq.data)
subplot(212)
plot(x.Time.data, x.PT_WFL_Trq_Drive.data)

figure
plot(x.Time.data, x.PT_Motor_Trq.data.*car.gearRatio, x.Time.data, x.PT_WFL_Trq_Drive.data)
legend('motor','trq drive')

figure
subplot(211)
plot(x.PT_Motor_PwrElec.data)
subplot(212)
plot(x.PT_WFL_Trq_Drive.data.*x.Vhcl_FL_rotv.data)

figure
plot(x.Time.data,x.PT_Motor_PwrElec.data ,x.Time.data,x.PT_WFL_Trq_Drive.data.*x.Vhcl_FL_rotv.data)
legend('P_{elec}','P_{mech}')

figure
plot(x.Time.data,x.PT_Motor_PwrElec.data ,x.Time.data,x.PT_Motor_Trq.data.*x.PT_Motor_rotv.data)

figure
plot(x.Time.data, (x.PT_WFL_Trq_Drive.data.*x.Vhcl_FL_rotv.data)./(x.PT_Motor_PwrElec.data))
title('eff')

figure
subplot(211)
plot(x.Time.data,x.PT_WFL_Trq_Drive.data)
subplot(212)
plot(x.Time.data,x.PT_Motor_Trq.data)