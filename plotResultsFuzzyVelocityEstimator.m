close all
clc


CarMakerData = cmread;

%vFuzzy = cmread;
%v2 = cmread

plotki = 1;
plotv2vFuzzy = 1;

if plotki == 1
    
    %% ki in one plot
    figure
    plot(ki.time,ki.data(:,1),ki.time,ki.data(:,2),ki.time,ki.data(:,3),...
        ki.time,ki.data(:,4),ki.time,ki.data(:,5))
    ylabel('ki')
    xlabel('time')
    legend('k1','k2','k3','k4','k5')
    
    %% ki
    figure
    subplot(2,3,1)
    plot(ki.time,ki.data(:,1))
    title('k1')
    ylabel('k1')
    xlabel('time')
    subplot(2,3,2)
    plot(ki.time,ki.data(:,2))
    title('k2')
    ylabel('k2')
    xlabel('time')
    subplot(2,3,3)
    plot(ki.time,ki.data(:,3))
    title('k3')
    ylabel('k3')
    xlabel('time')
    subplot(2,3,4)
    plot(ki.time,ki.data(:,4))
    title('k4')
    ylabel('k4')
    xlabel('time')
    subplot(2,3,5)
    plot(ki.time,ki.data(:,5))
    title('k5')
    ylabel('k5')
    xlabel('time')
    subplot(2,3,6)
    plot(ki.time,ki.data(:,1),ki.time,ki.data(:,2),ki.time,ki.data(:,3),...
        ki.time,ki.data(:,4),ki.time,ki.data(:,5))
    ylabel('ki')
    xlabel('time')
    legend('k1','k2','k3','k4')
    
    
    %% Velocity plot
    figure
    plot(estimParOut.v.time,estimParOut.v.data,CarMakerData.Time.data, CarMakerData.Car_v.data)
    title('Car Velocity')
    ylabel('Car velocity')
    xlabel('time')
    legend('estimated velocity','velocity')
    
    %% Velocity, acceleration, ki
    sizeData = size(CarMakerData.Time.data);
    dt = CarMakerData.Time.data(2)-CarMakerData.Time.data(1);
    for i = 2:sizeData(2)
        axDer(i-1) = (CarMakerData.Car_ax.data(i)-CarMakerData.Car_ax.data(i-1)) / dt;
    end
    axDer(sizeData(2))=0;
    
    figure
    subplot(4,1,1)
    plot(ki.time,ki.data(:,1),ki.time,ki.data(:,2),ki.time,ki.data(:,3),...
        ki.time,ki.data(:,4),ki.time,ki.data(:,5))
    title('ki')
    ylabel('ki')
    xlabel('time')
    legend('k1','k2','k3','k4','k5')
    subplot(4,1,2)
    plot(estimParOut.v.time,estimParOut.v.data,CarMakerData.Time.data, CarMakerData.Car_v.data)
    title('Car Velocity')
    ylabel('Car velocity')
    xlabel('time')
    legend('estimated velocity','velocity')
    subplot(4,1,3)
    plot(CarMakerData.Time.data, CarMakerData.Car_ax.data)
    title('Car ax')
    ylabel('Car ax')
    xlabel('time')
    
    subplot(4,1,4)
    plot(CarMakerData.Time.data, axDer)
    title('ax derivative')
    ylabel('axDer')
    xlabel('time')
    
    %% maxDeltaV, deltaVi & slip
    figure
    subplot(3,1,1)
    plot(maxDeltaV.time,maxDeltaV.data(:,1))
    title('maxDeltaV')
    ylabel('maxDeltaV')
    xlabel('time')
    subplot(3,1,2)
    plot(deltaV.time,deltaV.data(:,1),deltaV.time,deltaV.data(:,2),...
        deltaV.time,deltaV.data(:,3),deltaV.time,deltaV.data(:,4))
    title('deltaVi')
    ylabel('deltaVi')
    xlabel('time')
    legend('deltaVFL','deltaVFR','deltaVRL','deltaVRR')
    subplot(3,1,3)
    plot(CarMakerData.Time.data, CarMakerData.Car_LongSlipFL.data,...
        CarMakerData.Time.data, CarMakerData.Car_LongSlipFR.data,...
        CarMakerData.Time.data, CarMakerData.Car_LongSlipRL.data,...
        CarMakerData.Time.data, CarMakerData.Car_LongSlipRR.data)
    title('Longitudinal slip')
    ylabel('slip')
    xlabel('time')
    legend('slip FL','slip FR','slip RL', 'slip RR')
    
    %% ki, maxDeltaV & deltaVi
    figure
    subplot(3,1,1)
    plot(maxDeltaV.time,maxDeltaV.data(:,1))
    title('maxDeltaV')
    ylabel('maxDeltaV')
    xlabel('time')
    subplot(3,1,2)
    plot(deltaV.time,deltaV.data(:,1),deltaV.time,deltaV.data(:,2),...
        deltaV.time,deltaV.data(:,3),deltaV.time,deltaV.data(:,4))
    title('deltaVi')
    ylabel('deltaVi')
    xlabel('time')
    legend('deltaVFL','deltaVFR','deltaVRL','deltaVRR')
    subplot(3,1,3)
    plot(ki.time,ki.data(:,1),ki.time,ki.data(:,2),ki.time,ki.data(:,3),...
        ki.time,ki.data(:,4),ki.time,ki.data(:,5))
    title('ki')
    ylabel('ki')
    xlabel('time')
    legend('k1','k2','k3','k4','k5')
    
end

%% Comparison vFuzzy en v2

if plotv2vFuzzy == 1
    
    % .mat file can be found in map "Informatie velocity estimator v2 vs vFuzzy"
    sizev2IPG = size(v2.Car_v.data)
    sizev2IPG = sizev2IPG(2)
    sizevFuzzyIPG = size(vFuzzy.Car_v.data)
    sizevFuzzyIPG = sizevFuzzyIPG(2)
    
    sizev2Simulink = size(v2Simulink)
    sizev2Simulink = sizev2Simulink(1)
    sizevFuzzySimulink = size(vFuzzySimulink)
    sizevFuzzySimulink = sizevFuzzySimulink(1)
    
    
    if sizev2IPG > sizevFuzzyIPG
        v2_IPG = v2.Car_v.data(1:sizevFuzzyIPG);
        vFuzzy_IPG = vFuzzy.Car_v.data;
        v2Simulink = v2Simulink(1:sizevFuzzySimulink);
        time = estimParOut.v.time(1:sizevFuzzySimulink);
        IPGtime = vFuzzy.Time.data;
        
    else
        vFuzzy_IPG = vFuzzy.Car_v.data(1:sizev2IPG);
        v2_IPG = v2.Car_v.data;
        vFuzzySimulink = vFuzzySimulink(1:sizev2imulink)
        time = estimParOut.v.time(1:sizev2Simulink);
        IPGtime = v2.Time.data;
    end
    
    figure
    plot(time,v2Simulink,time,vFuzzySimulink,IPGtime, v2_IPG,IPGtime,vFuzzy_IPG)
    title('Velocity comparison')
    ylabel('Car velocity')
    xlabel('time')
    legend('v2 Estimated','vFuzzy Estimated','v2 Real', 'vFuzzy Real')
    
    
end

if plotv2vFuzzy == 1 & plotki == 1
    figure
    subplot(2,1,1)
    plot(time,v2Simulink,time,vFuzzySimulink,IPGtime, v2_IPG,IPGtime,vFuzzy_IPG)
    title('Velocity comparison')
    ylabel('Car velocity')
    xlabel('time')
    legend('v2 Estimated','vFuzzy Estimated','v2 Real', 'vFuzzy Real')
    subplot(2,1,2)
    plot(ki.time,ki.data(:,1),ki.time,ki.data(:,2),ki.time,ki.data(:,3),...
        ki.time,ki.data(:,4),ki.time,ki.data(:,5))
    title('ki')
    ylabel('ki')
    xlabel('time')
    legend('k1','k2','k3','k4','k5')
end
    

