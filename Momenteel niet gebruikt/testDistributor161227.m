clear all
close all
clc
dataCar
FsensMax=100;
MsensMax = 100;
FxsensMax = 1;
%TO DO
%Rekening houden met situaties waarbij 3 waarden de maxima overstijgen
%dit gebeurt enkel indien 3 van de maxima extreem laag zijn.

%Ervoor zorgen dat indien op het einde van de berekeningen het moment
%groter is dan het gewenste moment dat er een veiligheid in werking treed
%om dit tegen te gaan.


Fsens = 20; %value between 0 and 100
% 100 --> Fdes is really important
% 0 --> Mdes is really important

% Msens = 50; %value between 0 and 100
% % 100 --> Mdes is really important
% % 0 --> Mdes is less important

Fxsens = 1; %value between 0 and 100


Fxmax = [200;300;150;300]
Fxmin=-Fxmax;
Mz = -200;
Mdes = Mz;
Fdes =500;
if Fdes > sum(Fxmax)
    Fdes = sum(Fxmax)
elseif Fdes<sum(Fxmin)
    Fdes = sum(Fxmin)
end

A1 = [1 1 1 1];
A2 = [-car.lf car.lf -car.lr car.lr];
A3 = [1/Fxmax(1) 0 0 0;
    0 1/Fxmax(2) 0 0;
    0 0 1/Fxmax(3) 0;
    0 0 0 1/Fxmax(4)];
disp('before iteration')
Fdes
%Fx = inv(A1'*A1*(Fsens/FsensMax)+A2'*A2*(Msens/MsensMax)+A3*(Fxsens/FxsensMax))*(A1'*Fdes*(Fsens/FsensMax)+A2'*Mdes*(Msens/MsensMax))
Fx = inv(A1'*A1+A2'*A2+A3*(Fxsens/FxsensMax))*(A1'*Fdes+A2'*Mdes)
sumFx=sum(Fx)
moment = sum([-car.lf ;car.lf ;-car.lr ;car.lr].*Fx)


%% Iteratie

Fxcheckmax1 = 0;
Fxcheckmin1 = 0;
diffValue1 = 0;
diffValue2 = 0;
pos1 = 0;
pos2 = 0;


for i = 1:4
    if Fx(i)>Fxmax(i)
        Fxcheckmax1 =1;
    elseif Fx(i)<Fxmin(i)
        Fxcheckmin1 = 1;
    end
end

if Fxcheckmax1 == 1 %Check if there is too much traction
    diffAray = (Fx - Fxmax); %positive value if Fx > Fxmax
    diffAray = diffAray.*(diffAray > 0) %Filter values bigger than Fxmax
    [diffValue1,pos1]=max(diffAray);
    [diffValue2,pos2]= max(diffAray.*(diffAray<max(diffAray)));
    nonZero=length(find(diffAray));
    Fx = Fx - max(diffAray)*[1;1;1;1]
    diffFxFxmax = Fxmax-Fx
    
    moment = sum([-car.lf ;car.lf ;-car.lr ;car.lr].*Fx);
    fprintf('moment  before correction is %f.\n',moment)
    FxTotal = sum(Fx);
    fprintf('FxTotal before correction is %f.\n',FxTotal)
    diffFx = Fdes - FxTotal;
    fprintf('diffFx  before correction is %f.\n',diffFx)
    diffMz = Mdes - moment;
    fprintf('diffMz  before correction is %f.\n',diffMz)
    
    if pos1 == 3 | pos1 == 4
        [minDiffFxFxmax,posMinDiff] = min(diffFxFxmax(1:2))
        Fx(1:2) = Fx(1:2) + minDiffFxFxmax
    else
        [minDiffFxFxmax,posMinDiff] = min(diffFxFxmax(3:4));
        posMinDiff= posMinDiff+2;
        Fx(3:4) = Fx(3:4) + minDiffFxFxmax
    end
    
    diffFxFxmax = Fxmax - Fx
    
    moment = sum([-car.lf ;car.lf ;-car.lr ;car.lr].*Fx);
    fprintf('moment  after correction is %f.\n',moment)
    FxTotal = sum(Fx);
    fprintf('FxTotal after correction is %f.\n',FxTotal)
    diffFx = Fdes - FxTotal;
    fprintf('diffFx  after correction is %f.\n',diffFx)
    diffMz = Mdes - moment;
    fprintf('diffMz  after correction is %f.\n',diffMz)
    Fx
    
    MzCorr = moment;
    
    if pos1 >2 %pos1==3 or pos1==4
        %         diffFLFR = Fx(posMinDiff)-Fx(3-posMinDiff)
        %         diffRLRR = Fx(pos1)-Fx(7-pos1)
        %         Fx(3-posMinDiff)=Fx(3-posMinDiff)+diffFLFR*(Fsens/FsensMax);
        %         Fx(7-pos1)=Fx(7-pos1)+diffRLRR*(Fsens/FsensMax);
        if diffFxFxmax(7-pos1) == 0
            diffFxFxmax(7-pos1) = 0.1
        end
        
        fracDiff=(diffFxFxmax(3-posMinDiff)/diffFxFxmax(7-pos1))
        distrRLRR = -MzCorr/(fracDiff*A2(3-posMinDiff)+A2(7-pos1))
        distrFLFR = (-MzCorr - distrRLRR*A2(7-pos1))/A2(3-posMinDiff)
        
        if (distrRLRR + distrFLFR) > 0
            if distrFLFR > diffFxFxmax(3-posMinDiff)
                distrFLFR = diffFxFxmax(7-pos1);
                distrRLRR = diffFxFxmax(3-posMinDiff);
            end
            
            Fx(3-posMinDiff)=Fx(3-posMinDiff)+distrFLFR*(Fsens/FsensMax);
            Fx(7-pos1)=Fx(7-pos1)+distrRLRR*(Fsens/FsensMax);
        end
        
        
    else %pos1==1 or pos1==2
        %         diffFLFR = Fx(pos1)-Fx(3-pos1)
        %         diffRLRR =  Fx(posMinDiff)-Fx(7-posMinDiff)
        %         Fx(7-posMinDiff)=Fx(7-posMinDiff)+diffFLFR*(Fsens/FsensMax);
        %         Fx(3-pos1)=Fx(3-pos1)+diffRLRR*(Fsens/FsensMax);
        
        if diffFxFxmax(7-posMinDiff) == 0
            diffFxFxmax(7-posMinDiff) = 0.1
        end
        fracDiff=(diffFxFxmax(3-pos1)/diffFxFxmax(7-posMinDiff))
        distrRLRR = -MzCorr/(fracDiff*A2(3-pos1)+A2(7-posMinDiff))
        distrFLFR = (-MzCorr - distrRLRR*A2(7-posMinDiff))/A2(3-pos1)
        
        if (distrRLRR + distrFLFR) > 0
            if distrFLFR > diffFxFxmax(3-pos1)
                distrFLFR = diffFxFxmax(7-posMinDiff)
                distrRLRR = diffFxFxmax(3-pos1)
            end
            Fx(7-posMinDiff)=Fx(7-posMinDiff)+distrFLFR*(Fsens/FsensMax);
            Fx(3-pos1)=Fx(3-pos1)+distrRLRR*(Fsens/FsensMax);
        end
    end
    
    moment = sum([-car.lf ;car.lf ;-car.lr ;car.lr].*Fx);
    fprintf('moment  after correctionfactor is %f.\n',moment)
    FxTotal = sum(Fx);
    fprintf('FxTotal after correctionfactor is %f.\n',FxTotal)
    diffFx = Fdes - FxTotal;
    fprintf('diffFx  after correctionfactor is %f.\n',diffFx)
    diffMz = Mdes - moment;
    fprintf('diffMz  after correctionfactor is %f.\n',diffMz)
    Fx
    
    
    
    %-------------------------------------------------------------------------
elseif Fxcheckmin1==1
    diffAray = Fx - Fxmin; %negative value if Fx < Fxmin
    diffAray = diffAray.*(diffAray < 0) %Filter values smaller than Fxmin
    [diffValue1,pos1]=min(diffAray);
    %[diffValue2,pos2]= max(diffAray.*(diffAray<max(diffAray)));
    nonZero=length(find(diffAray));
    Fx = Fx - min(diffAray)*[1;1;1;1]
    diffFxFxmin = Fxmin-Fx
    
    
    moment = sum([-car.lf ;car.lf ;-car.lr ;car.lr].*Fx);
    fprintf('moment  before correction is %f.\n',moment)
    FxTotal = sum(Fx);
    fprintf('FxTotal before correction is %f.\n',FxTotal)
    diffFx = Fdes - FxTotal;
    fprintf('diffFx  before correction is %f.\n',diffFx)
    diffMz = Mdes - moment;
    fprintf('diffMz  before correction is %f.\n',diffMz)
    
    if pos1 == 3 | pos1 == 4
        [minDiffFxFxmin,posMinDiff] = max(diffFxFxmin(1:2))
        Fx(1:2) = Fx(1:2) + minDiffFxFxmax
    else
        [minDiffFxFxmin,posMinDiff] = max(diffFxFxmin(3:4));
        posMinDiff= posMinDiff+2;
        Fx(3:4) = Fx(3:4) + minDiffFxFxmin
    end
    
    diffFxFxmin = Fxmin-Fx
    
    moment = sum([-car.lf ;car.lf ;-car.lr ;car.lr].*Fx);
    fprintf('moment  after correction is %f.\n',moment)
    FxTotal = sum(Fx);
    fprintf('FxTotal after correction is %f.\n',FxTotal)
    diffFx = Fdes - FxTotal;
    fprintf('diffFx  after correction is %f.\n',diffFx)
    diffMz = Mdes - moment;
    fprintf('diffMz  after correction is %f.\n',diffMz)
    Fx
    
    MzCorr = moment;
    
    if pos1 >2
        %         diffFLFR = Fx(posMinDiff)-Fx(3-posMinDiff)
        %         diffRLRR = Fx(pos1)-Fx(7-pos1)
        %         Fx(3-posMinDiff)=Fx(3-posMinDiff)+diffFLFR*(Fsens/FsensMax);
        %         Fx(7-pos1)=Fx(7-pos1)+diffRLRR*(Fsens/FsensMax);
        
        if diffFxFxmin(7-pos1) == 0
            diffFxFxmin(7-pos1) = -0.1
        end
        fracDiff=(diffFxFxmin(3-posMinDiff)/diffFxFxmin(7-pos1))
        distrRLRR = -MzCorr/(fracDiff*A2(3-posMinDiff)+A2(7-pos1))
        distrFLFR = (-MzCorr - distrRLRR*A2(7-pos1))/A2(3-posMinDiff)
        
        if (distrRLRR + distrFLFR) < 0
            if distrFLFR < diffFxFxmax(3-posMinDiff)
                distrFLFR = diffFxFxmax(7-pos1);
                distrRLRR = diffFxFxmax(3-posMinDiff);
            end
            
            
            
            Fx(3-posMinDiff)=Fx(3-posMinDiff)+distrFLFR*(Fsens/FsensMax);
            Fx(7-pos1)=Fx(7-pos1)+distrRLRR*(Fsens/FsensMax);
        end
        
        
    else
        %         diffFLFR = Fx(pos1)-Fx(3-pos1)
        %         diffRLRR =  Fx(posMinDiff)-Fx(7-posMinDiff)
        %         Fx(7-posMinDiff)=Fx(7-posMinDiff)+diffFLFR*(Fsens/FsensMax);
        %         Fx(3-pos1)=Fx(3-pos1)+diffRLRR*(Fsens/FsensMax);
        
        if diffFxFxmin(7-posMinDiff) == 0
            diffFxFxmin(7-posMinDiff) = -0.1
        end
        fracDiff=(diffFxFxmin(3-pos1)/diffFxFxmin(7-posMinDiff))
        distrRLRR = -MzCorr/(fracDiff*A2(3-pos1)+A2(7-posMinDiff))
        distrFLFR = (-MzCorr - distrRLRR*A2(7-posMinDiff))/A2(3-pos1)
        
        if (distrRLRR + distrFLFR) < 0
            if distrFLFR < diffFxFxmax(3-pos1)
                distrFLFR = diffFxFxmax(7-posMinDiff);
                distrRLRR = diffFxFxmax(3-pos1);
            end
            Fx(7-posMinDiff)=Fx(7-posMinDiff)+distrFLFR*(Fsens/FsensMax);
            Fx(3-pos1)=Fx(3-pos1)+distrRLRR*(Fsens/FsensMax);
        end
    end
    
    moment = sum([-car.lf ;car.lf ;-car.lr ;car.lr].*Fx);
    fprintf('moment  after correctionfactor is %f.\n',moment)
    FxTotal = sum(Fx);
    fprintf('FxTotal after correctionfactor is %f.\n',FxTotal)
    diffFx = Fdes - FxTotal;
    fprintf('diffFx  after correctionfactor is %f.\n',diffFx)
    diffMz = Mdes - moment;
    fprintf('diffMz  after correctionfactor is %f.\n',diffMz)
    Fx
    
    
    
end

































