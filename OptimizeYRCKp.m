%countMAX = 2
%car.YRC.Kp is optimal at 115 when only varying car.YRC.Kp on SkidPad

for i = 1:counterTotal    
    sizeE = size(estimPar_Data_Resize(i).rref.data);
    sizeEstimPar=sizeE(1);
    sizeC = size(CM_Data(i).Car_YawRate.data);
    sizeCM = sizeC(2);
    minSize = min(min(sizeEstimPar),min(sizeCM));
    
    CMYawRate = CM_Data(i).Car_YawRate.data';
    error = abs(CMYawRate(1:minSize) - estimPar_Data_Resize(i).rref.data(1:minSize));
    meanError(i) = mean(error);
    maxError(i) = max(error);
    minError(i) = min(error);
end

[minErrorYawRate,posMinErrorYawRate] = min(meanError)
[minminErrorYawRate,posMinminErrorYawRate] = min(minError)
[maxmaxErrorYawRate,posMaxmaxErrorYawRate] = max(maxError)

for i = 1:counterTotal
    %timeE = size(estimPar_Data(i).rref.data);
    %time(i) = timeE(1);
    dist(i) = max(CM_Data(i).Vhcl_Distance.data);
end

[minTime,posMinTime] = min(time);
[maxDist,posMaxDist]= max(dist)
