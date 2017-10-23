%optPar.TireInertiaKp = (counter-1)*0.1*10^-7;
countMAX = 20;

for i = 1:countMAX
    CM_Data(i).Car_FxFL.data(1291)=[];
    CMFxFL(:,i) = CM_Data(i).Car_FxFL.data';
    CM_Data(i).Car_FxFR.data(1291)=[];
    CMFxFR(:,i) = CM_Data(i).Car_FxFR.data';
    CM_Data(i).Car_FxRL.data(1291)=[];
    CMFxRL(:,i) = CM_Data(i).Car_FxRL.data';
    CM_Data(i).Car_FxRR.data(1291)=[];
    CMFxRR(:,i) = CM_Data(i).Car_FxRR.data';
    CMFx(:,:,i) = [CMFxFL(:,i) CMFxFR(:,i) CMFxRL(:,i) CMFxRR(:,i)];
    estimParFx(:,:,i) = estimPar_Data_Resize(i).Fxi.data;
end


for i =1:countMAX
    error(:,:,i) = abs(CMFx(:,:,i) - estimParFx(:,:,i));
    meanError(:,:,i) = mean(error(:,:,i));
    meanErrorCar(i) = mean(meanError(:,:,i));
end

[minErrorFxFL,posMinErrorFxFL] = min(meanError(1,1,:));
[minErrorFxFR,posMinErrorFxFR] = min(meanError(1,2,:));
[minErrorFxRL,posMinErrorFxRL] = min(meanError(1,3,:));
[minErrorFxRR,posMinErrorFxRR] = min(meanError(1,4,:));
[minErrorFxCar,posMinErrorFxCar] = min(meanErrorCar(:,:))

posMinErrorFx = [posMinErrorFxFL, posMinErrorFxFR,posMinErrorFxRL,posMinErrorFxRR]
