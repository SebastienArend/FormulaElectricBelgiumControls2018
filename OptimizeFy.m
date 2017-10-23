
for i = 1:countMAX
    CM_Data(i).Car_FyFL.data(1291)=[];
    CMFyFL(:,i) = CM_Data(i).Car_FyFL.data';
    CM_Data(i).Car_FyFR.data(1291)=[];
    CMFyFR(:,i) = CM_Data(i).Car_FyFR.data';
    CM_Data(i).Car_FyRL.data(1291)=[];
    CMFyRL(:,i) = CM_Data(i).Car_FyRL.data';
    CM_Data(i).Car_FyRR.data(1291)=[];
    CMFyRR(:,i) = CM_Data(i).Car_FyRR.data';
    CMFy(:,:,i) = [CMFyFL(:,i) CMFyFR(:,i) CMFyRL(:,i) CMFyRR(:,i)];
    estimParFy(:,:,i) = estimPar_Data_Resize(i).Fyi.data;
end


for i =1:countMAX
    error(:,:,i) = abs(CMFy(:,:,i) - estimParFy(:,:,i));
    meanError(:,:,i) = mean(error(:,:,i));
    meanErrorCar(i) = mean(meanError(:,:,i));
end

[minErrorFyFL,posMinErrorFyFL] = min(meanError(1,1,:));
[minErrorFyFR,posMinErrorFyFR] = min(meanError(1,2,:));
[minErrorFyRL,posMinErrorFyRL] = min(meanError(1,3,:));
[minErrorFyRR,posMinErrorFyRR] = min(meanError(1,4,:));
[minErrorFyCar,posMinErrorFyCar] = min(meanErrorCar(:,:))

posMinErrorFy = [posMinErrorFyFL, posMinErrorFyFR,posMinErrorFyRL,posMinErrorFyRR];
