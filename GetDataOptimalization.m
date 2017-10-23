%READ ME

%PATH src_cm4sl/%t
%NOTE: Comment out clear_close.m
%NOTE: Manually clear before starting
%NOTE: CHECK WHICH VERSION YOU ARE SIMULATING WITH!!!!!!!

countPMAX = 10;
countPList = [1;2;5;10;20;30;40;50;60;70];
countIMAX = 4;
countDMAX = 4;
countSMAX = 4;
counterTotal = 0;
countLog = [0,0,0,0];

for counterP = 1:countPMAX
    counterP
    %optPar.scaleFactorFy = 0.2+(counter-1)*0.05;
    %optPar.TireInertiaKp = (counter-1)*0.1*10^-7;
    car.YRC.Kp = countPList(counterP);
    
    for counterI = 1:countIMAX
        counterI
        car.YRC.Ki = (counterI-1)*0.5;
        
        for counterD = 1:countDMAX
            counterD
            car.YRC.Kd = (counterD-1)*0.5;
            
            for counterS = 1:countSMAX
                counterS
                car.YRC.Ks = (counterS-1)*0.5;
                
                counterTotal = counterTotal +1
                countLog(counterTotal,:)=[counterP,counterI,counterD,counterS];
                sim('Torque_Vectoring_Controller_Pieter');
                CM_Data(counterTotal,1) = cmread('Examples_FS_FS_Competition_Germany_2006.erg');
                estimPar_Data(counterTotal,1) = estimParOut;
                pause(3) %Necessary for not letting CarMaker crash
            end
        end
        
    end
    
    
end

%Adapt estimPar_Data to same sampling freq as CM_Data

% for k = 1:counterTotal
%     k
%     [m,n]= size(CM_Data(k).Car_YawRate.data);
%     for j = 1:4
%         estimPar_Data_Resize(k,1).Fxi.data(1,j) = estimPar_Data(k,1).Fxi.data(1,j);
%         estimPar_Data_Resize(k,1).Fyi.data(1,j) = estimPar_Data(k,1).Fyi.data(1,j);
%         estimPar_Data_Resize(k,1).Fzi.data(1,j) = estimPar_Data(k,1).Fzi.data(1,j);
%         estimPar_Data_Resize(k,1).mu.data(1,j) = estimPar_Data(k,1).mu.data(1,j);
%         estimPar_Data_Resize(k,1).slip.data(1,j) = estimPar_Data(k,1).slip.data(1,j);
%         
%         for i = 2:n-1
%             estimPar_Data_Resize(k,1).Fxi.data(i,j) = estimPar_Data(k,1).Fxi.data(i*10+(i-2)*10+1,j);
%             estimPar_Data_Resize(k,1).Fyi.data(i,j) = estimPar_Data(k,1).Fyi.data(i*10+(i-2)*10+1,j);
%             estimPar_Data_Resize(k,1).Fzi.data(i,j) = estimPar_Data(k,1).Fzi.data(i*10+(i-2)*10+1,j);
%             estimPar_Data_Resize(k,1).mu.data(i,j) = estimPar_Data(k,1).mu.data(i*10+(i-2)*10+1,j);
%             estimPar_Data_Resize(k,1).slip.data(i,j) = estimPar_Data(k,1).slip.data(i*10+(i-2)*10+1,j);
%         end
%     end
% end


for k = 1:counterTotal
    k
    [m,n]= size(CM_Data(k).Car_YawRate.data);
    estimPar_Data_Resize(k,1).v.data(1,1) = estimPar_Data(k,1).v.data(1,1);
    estimPar_Data_Resize(k,1).rref.data(1,1) = estimPar_Data(k,1).rref.data(1,1);
    for i = 2:n-1
        estimPar_Data_Resize(k,1).v.data(i,1) = estimPar_Data(k,1).v.data(i*10+(i-2)*10+1,1);
        estimPar_Data_Resize(k,1).rref.data(i,1) = estimPar_Data(k,1).rref.data(i*10+(i-2)*10+1,1);
    end
end

OptimizeYRCKp