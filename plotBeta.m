%% sideslip angle
%CarMakerData = cmread
close all

figure
plot(CarMakerData.Time.data,CarMakerData.Car_SideSlipAngle.data)

title('Side slip angle')
ylabel('Side slip angle')
xlabel('time')


Ax_beta =    sin(CarMakerData.Car_SideSlipAngle.data) .* CarMakerData.Car_ay.data;
figure
plot(CarMakerData.Time.data,Ax_beta)
title('Axbeta')
ylabel('deltaAxbeta')
xlabel('time')

figure
subplot(211)
plot(CarMakerData.Time.data,sin(CarMakerData.Car_SideSlipAngle.data))
title('sin(beta)')
subplot(212)
plot(CarMakerData.Time.data,CarMakerData.Car_ay.data)
title('ay')

figure
plot(CarMakerData.Time.data,CarMakerData.Car_ax.data)
title('ax')