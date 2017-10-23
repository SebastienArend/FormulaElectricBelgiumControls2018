close all
clc
CarMakerData = cmread;

%NOTE: difference between car and vhcl

FxPlot = 0;   velocityPlot = 0;
FyPlot = 0;   slipPlot = 0;
FzPlot = 0;   yawRatePlot = 1;
torquePlot = 1;

PlotAll = 0;

if PlotAll == 1
    FxPlot = 1;   velocityPlot = 1;
    FyPlot = 1;   slipPlot = 1;
    FzPlot = 1;   yawRatePlot = 1;
    torquePlot =1;
end

TorqueComparison = 0;




%% Fx plot
if FxPlot ==1
    figure
    subplot(2,2,1)
    plot(estimParOut.Fxi.time,estimParOut.Fxi.data(:,1),CarMakerData.Time.data, CarMakerData.Car_FxFL.data)%,Fxmax.Time,Fxmax.data(:,1))
    title('FxFL')
    ylabel('FxFL')
    xlabel('time')
    axis([0 30 -500 1200])
    legend('estimated FxFL','FxFL','Fxmax')
    subplot(2,2,2)
    plot(estimParOut.Fxi.time,estimParOut.Fxi.data(:,2),CarMakerData.Time.data, CarMakerData.Car_FxFR.data)%,Fxmax.Time,Fxmax.data(:,2))
    title('FxFR')
    ylabel('FxFR')
    xlabel('time')
    axis([0 30 -500 1200])
    %legend('estimated FxFR','FxFR')
    subplot(2,2,3)
    plot(estimParOut.Fxi.time,estimParOut.Fxi.data(:,3),CarMakerData.Time.data, CarMakerData.Car_FxRL.data)%,Fxmax.Time,Fxmax.data(:,3))
    title('FxRL')
    ylabel('FxRL')
    xlabel('time')
    axis([0 30 -500 1200])
    %legend('estimated FxRL','FxRL')
    subplot(2,2,4)
    plot(estimParOut.Fxi.time,estimParOut.Fxi.data(:,4),CarMakerData.Time.data, CarMakerData.Car_FxRR.data)%,Fxmax.Time,Fxmax.data(:,4))
    title('FxRR')
    ylabel('FxRR')
    xlabel('time')
    axis([0 30 -500 1200])
    %legend('estimated FxRR','FxRR')
    
%--------
 figure
    subplot(2,2,1)
    plot(estimParOut.Fxi.time,estimParOut.Fxi.data(:,1),CarMakerData.Time.data, CarMakerData.Vhcl_FL_Fx.data)%,Fxmax.Time,Fxmax.data(:,1))
    title('FxFL')
    ylabel('FxFL')
    xlabel('time')
    axis([0 30 -500 1200])
    legend('estimated FxFL','FxFL','Fxmax')
    subplot(2,2,2)
    plot(estimParOut.Fxi.time,estimParOut.Fxi.data(:,2),CarMakerData.Time.data, CarMakerData.Vhcl_FR_Fx.data)%,Fxmax.Time,Fxmax.data(:,2))
    title('FxFR')
    ylabel('FxFR')
    xlabel('time')
    axis([0 30 -500 1200])
    %legend('estimated FxFR','FxFR')
    subplot(2,2,3)
    plot(estimParOut.Fxi.time,estimParOut.Fxi.data(:,3),CarMakerData.Time.data, CarMakerData.Vhcl_RL_Fx.data)%,Fxmax.Time,Fxmax.data(:,3))
    title('FxRL')
    ylabel('FxRL')
    xlabel('time')
    axis([0 30 -500 1200])
    %legend('estimated FxRL','FxRL')
    subplot(2,2,4)
    plot(estimParOut.Fxi.time,estimParOut.Fxi.data(:,4),CarMakerData.Time.data, CarMakerData.Vhcl_RR_Fx.data)%,Fxmax.Time,Fxmax.data(:,4))
    title('FxRR')
    ylabel('FxRR')
    xlabel('time')
    axis([0 30 -500 1200])
    %legend('estimated FxRR','FxRR')
end

%% Fy plot
if FyPlot == 1
    figure
    subplot(2,2,1)
    plot(estimParOut.Fyi.time,estimParOut.Fyi.data(:,1),CarMakerData.Time.data, CarMakerData.Car_FyFL.data)
    title('FyFL')
    ylabel('FyFL')
    xlabel('time')
    legend('estimated FyFL','FyFL')
    subplot(2,2,2)
    plot(estimParOut.Fyi.time,estimParOut.Fyi.data(:,2),CarMakerData.Time.data, CarMakerData.Car_FyFR.data)
    title('FyFR')
    ylabel('FyFR')
    xlabel('time')
    %legend('estimated FyFR','FyFR')
    subplot(2,2,3)
    plot(estimParOut.Fyi.time,estimParOut.Fyi.data(:,3),CarMakerData.Time.data, CarMakerData.Car_FyRL.data)
    title('FyRL')
    ylabel('FyRL')
    xlabel('time')
    %legend('estimated FyRL','FyRL')
    subplot(2,2,4)
    plot(estimParOut.Fyi.time,estimParOut.Fyi.data(:,4),CarMakerData.Time.data, CarMakerData.Car_FyRR.data)
    title('FyRR')
    ylabel('FyRR')
    xlabel('time')
    %legend('estimated FyRR','FyRR')
end
%% Fz plot
if FzPlot == 1
    figure
    subplot(2,2,1)
    plot(estimParOut.Fzi.time,estimParOut.Fzi.data(:,1),CarMakerData.Time.data, CarMakerData.Car_FzFL.data)
    title('FzFL')
    ylabel('FzFL')
    xlabel('time')
    legend('estimated FzFL','FzFL')
    subplot(2,2,2)
    plot(estimParOut.Fzi.time,estimParOut.Fzi.data(:,2),CarMakerData.Time.data, CarMakerData.Car_FzFR.data)
    title('FzFR')
    ylabel('FzFR')
    xlabel('time')
    %legend('estimated FzFR','FzFR')
    subplot(2,2,3)
    plot(estimParOut.Fzi.time,estimParOut.Fzi.data(:,3),CarMakerData.Time.data, CarMakerData.Car_FzRL.data)
    title('FzRL')
    ylabel('FzRL')
    xlabel('time')
    %legend('estimated FzRL','FzRL')
    subplot(2,2,4)
    plot(estimParOut.Fzi.time,estimParOut.Fzi.data(:,4),CarMakerData.Time.data, CarMakerData.Car_FzRR.data)
    title('FzRR')
    ylabel('FzRR')
    xlabel('time')
    %legend('estimated FzRR','FzRR')
end
% %% vx plot
% if xvelocityPlot == 1
%     figure
%     plot(estimParOut.v.time,estimParOut.v.data,SkidPad.Time.data, SkidPad.Car_vx.data)
%     title('Car Velocity x')
%     ylabel('Car vx')
%     xlabel('time')
%     legend('estimated x velocity','x velocity')
% end

%% Veloxicy plot
if velocityPlot == 1
    figure
    plot(estimParOut.v.time,estimParOut.v.data,CarMakerData.Time.data, CarMakerData.Car_v.data)
    title('Car Velocity')
    ylabel('Car velocity')
    xlabel('time')
    legend('estimated velocity','velocity')
end
%% Longitudinal Slip plot
if slipPlot == 1
    figure
    subplot(2,2,1)
    plot(estimParOut.slip.time,estimParOut.slip.data(:,1),CarMakerData.Time.data, CarMakerData.Car_LongSlipFL.data)
    title('Longitudinal SlipFL')
    ylabel('SlipFL')
    xlabel('time')
    legend('estimated Slip','Slip')
    subplot(2,2,2)
    plot(estimParOut.slip.time,estimParOut.slip.data(:,2),CarMakerData.Time.data, CarMakerData.Car_LongSlipFR.data)
    title('Longitudinal SlipFR')
    ylabel('SlipFR')
    xlabel('time')
    %legend('estimated Slip','Slip')
    subplot(2,2,3)
    plot(estimParOut.slip.time,estimParOut.slip.data(:,3),CarMakerData.Time.data, CarMakerData.Car_LongSlipRL.data)
    title('Longitudinal SlipRL')
    ylabel('SlipRL')
    xlabel('time')
    %legend('estimated Slip','Slip')
    subplot(2,2,4)
    plot(estimParOut.slip.time,estimParOut.slip.data(:,4),CarMakerData.Time.data, CarMakerData.Car_LongSlipRR.data)
    title('Longitudinal SlipRR')
    ylabel('SlipRR')
    xlabel('time')
    %legend('estimated Slip','Slip')
end
%% Yaw Rate
if yawRatePlot == 1
    figure
    plot(estimParOut.rref.time,estimParOut.rref.data,CarMakerData.Time.data, CarMakerData.Car_YawRate.data)
    title('Yaw Rate')
    ylabel('Yaw Rate')
    xlabel('time')
    legend('Yaw Rate Reference','Yaw Rate','Location','NorthWest')
end
%% Torque Plot
if torquePlot == 1
    figure
    plot(CarMakerData.Time.data, CarMakerData.PT_WFL_Trq_Drive.data,...
        CarMakerData.Time.data, CarMakerData.PT_WFR_Trq_Drive.data,...
        CarMakerData.Time.data, CarMakerData.PT_WRL_Trq_Drive.data,...
        CarMakerData.Time.data, CarMakerData.PT_WRR_Trq_Drive.data)
    title('Torque')
    ylabel('Torque')
    xlabel('time')
    legend('Torque FL','Torque FR','Torque RL','Torque RR')
    
    figure
    TorqueIPGLines = plot(CarMakerData.Time.data, CarMakerData.PT_WFL_Trq_Drive.data,'g',...
        CarMakerData.Time.data, CarMakerData.PT_WFR_Trq_Drive.data,'g',...
        CarMakerData.Time.data, CarMakerData.PT_WRL_Trq_Drive.data,'g',...
        CarMakerData.Time.data, CarMakerData.PT_WRR_Trq_Drive.data,'g'); hold on
    TorqueSentOutLines = plot(torques.time,torques.data,'r');
    MaxTorqueLines = plot([0,torques.time(end)],[car.motor.Tmax(1)*car.gearRatio,car.motor.Tmax(1)*car.gearRatio],'b')
    
    TorqueIPGGroup = hggroup;
    TorqueSentOutGroup = hggroup;
    MaxTorqueGroup = hggroup;
    
    set(TorqueIPGLines,'Parent',TorqueIPGGroup)
    set(TorqueSentOutLines,'Parent',TorqueSentOutGroup)
    set(MaxTorqueLines,'Parent',MaxTorqueGroup)
    
    set(get(get(TorqueIPGGroup,'Annotation'),'LegendInformation'),...
        'IconDisplayStyle','on');
    set(get(get(TorqueSentOutGroup,'Annotation'),'LegendInformation'),...
        'IconDisplayStyle','on');
    set(get(get(MaxTorqueGroup,'Annotation'),'LegendInformation'),...
        'IconDisplayStyle','on');
    legend('Torque IPG','Torque Sent out','max Torque')
    title('Torque IPG and sent out')
    ylabel('Torque')
    xlabel('time')
end

%% Torque Comparison
if TorqueComparison == 1
    figure
    
    Torque1Lines= plot(time, TorqueDistr1,'g');hold on
    Torque2Lines= plot(time, TorqueDistr2,'r');   
    Torque3Lines= plot(time, TorqueIPG,'b');       

Torque1Group = hggroup;
Torque2Group = hggroup;
Torque3Group = hggroup;
set(Torque1Lines,'Parent',Torque1Group)
set(Torque2Lines,'Parent',Torque2Group)
set(Torque3Lines,'Parent',Torque3Group)
% Include these hggroups in the legend:
set(get(get(Torque1Group,'Annotation'),'LegendInformation'),...
    'IconDisplayStyle','on'); 
set(get(get(Torque2Group,'Annotation'),'LegendInformation'),...
    'IconDisplayStyle','on'); 
set(get(get(Torque3Group,'Annotation'),'LegendInformation'),...
    'IconDisplayStyle','on'); 
legend('Distr1','Distr2','IPG')
%     title('Torque Comparison')
%     ylabel('Torque')
%     xlabel('time')
%         
end