function [ Fx ] = Distributor(settings,car, Mz, Fdes, Fxmax, Fxmin)

%VERSION: testDistributor_170118

%DISTRIBUTOR 
%   Sensitivity parameters
%   are worked out to find an optimal balance between
%   the desired Fx and the desired Mz
%   Mz = desired yaw moment [1x1]
%   Fdes = desired traction force [1x1]
%   Fxmax = available grip per wheel [4x1]
%   Fxmin = available neg grip per wheel [4x1]

%   TODO: variables or settings?
%TO DO
%Rekening houden met situaties waarbij 3 waarden de maxima overstijgen
%dit gebeurt enkel indien 3 van de maxima extreem laag zijn.


Mdes = Mz;

FsensMax=100;
FxsensMax = 100;

Fsens = settings.Fsens; %value between 0 and 100
% 100 --> Fdes is really important
% 0 --> Mdes is really important

Fxsens = settings.Fxsens; %value between 0 and 100

%Avoid dividing by 0
for i = 1:4
    if Fxmax(i) == 0
        Fxmax(i)=1;
    end
end
for i = 1:4
    if Fxmin(i) == 0
        Fxmin(i)=-1;
    end
end

if Fdes > sum(Fxmax)
    Fdes = sum(Fxmax);
elseif Fdes<sum(Fxmin)
    Fdes = sum(Fxmin);
end


A1 = [1 1 1 1];
A2 = [-car.tw/2 car.tw/2 -car.tw/2 car.tw/2];
A3 = [1/Fxmax(1) 0 0 0;
    0 1/Fxmax(2) 0 0;
    0 0 1/Fxmax(3) 0;
    0 0 0 1/Fxmax(4)];
Fx = (A1'*A1+A2'*A2+A3*(Fxsens/FxsensMax))\(A1'*Fdes+A2'*Mdes);

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

if  (Fxcheckmax1==1||Fxcheckmin1==1) %Check if one value of Former Fx surpasses the maximum value
    %Mdes = Mz*(Msens/MsensMax);
    
    if Fxcheckmax1 == 1
        diffAray = (Fx - Fxmax); %positive value if Fx > Fxmax
        diffAray = diffAray.*(diffAray > 0); %Filter values bigger than Fxmax
        [~,pos1]=max(diffAray);
        [~,~]= max(diffAray.*(diffAray<max(diffAray)));
        nonZero=length(find(diffAray));
        Fx = Fx - max(diffAray)*[1;1;1;1];
        minsurpass = find((Fx<Fxmin)==1);
        Fx(minsurpass)=Fxmin(minsurpass);
        diffFxFxmax = Fxmax-Fx;
        
        %moment = sum([-car.tw/2; car.tw/2; -car.tw/2; car.tw/2].*Fx);

        
        if pos1 == 3 || pos1 == 4
            [minDiffFxFxmax,posMinDiff] = min(diffFxFxmax(1:2));
            Fx(1:2) = Fx(1:2) + minDiffFxFxmax;
        else
            [minDiffFxFxmax,posMinDiff] = min(diffFxFxmax(3:4));
            posMinDiff= posMinDiff+2;
            Fx(3:4) = Fx(3:4) + minDiffFxFxmax;
        end
        
        diffFxFxmax = Fxmax - Fx;
        
        moment = sum([-car.tw/2; car.tw/2; -car.tw/2; car.tw/2].*Fx);

        MzCorr = moment;
        DiffsumFxFdes = Fdes-sum(Fx);
        if pos1 >2
            if diffFxFxmax(7-pos1) == 0
                diffFxFxmax(7-pos1) = 0.1;
            end
            
            fracDiff=(diffFxFxmax(3-posMinDiff)/diffFxFxmax(7-pos1));
            distrRLRR = -MzCorr/(fracDiff*A2(3-posMinDiff)+A2(7-pos1));
            distrFLFR = (-MzCorr - distrRLRR*A2(7-pos1))/A2(3-posMinDiff);
            
            if (distrRLRR + distrFLFR) > 0
                if distrFLFR +distrRLRR > DiffsumFxFdes 
                    distrFLFR = DiffsumFxFdes/(1+fracDiff);
                    distrRLRR = distrFLFR*fracDiff;
                end
                
                Fx(3-posMinDiff)=Fx(3-posMinDiff)+distrFLFR*(Fsens/FsensMax);
                Fx(7-pos1)=Fx(7-pos1)+distrRLRR*(Fsens/FsensMax);
            end
            
            
        else
            if diffFxFxmax(7-posMinDiff) == 0
                diffFxFxmax(7-posMinDiff) = 0.1;
            end
            fracDiff=(diffFxFxmax(3-pos1)/diffFxFxmax(7-posMinDiff));
            distrRLRR = -MzCorr/(fracDiff*A2(3-pos1)+A2(7-posMinDiff));
            distrFLFR = (-MzCorr - distrRLRR*A2(7-posMinDiff))/A2(3-pos1);
            
            if (distrRLRR + distrFLFR) > 0
                if distrFLFR + distrRLRR > DiffsumFxFdes
                    distrFLFR = DiffsumFxFdes/(1+fracDiff);
                    distrRLRR = distrFLFR*fracDiff;
                end
                Fx(7-posMinDiff)=Fx(7-posMinDiff)+distrFLFR*(Fsens/FsensMax);
                Fx(3-pos1)=Fx(3-pos1)+distrRLRR*(Fsens/FsensMax);
            end
        end
        
        
       
        
        %-------------------------------------------------------------------------
    else
        diffAray = Fx - Fxmin; %negative value if Fx < Fxmin
        diffAray = diffAray.*(diffAray < 0); %Filter values smaller than Fxmin
        [~,pos1]=min(diffAray);
        %[diffValue2,pos2]= max(diffAray.*(diffAray<max(diffAray)));
        %nonZero=length(find(diffAray));
        Fx = Fx - min(diffAray)*[1;1;1;1];
        maxsurpass = find((Fx>Fxmax)==1);
        Fx(maxsurpass)=Fxmax(maxsurpass);
        diffFxFxmin = Fxmin-Fx;
        
        
        

        if pos1 == 3 || pos1 == 4
            [minDiffFxFxmin,posMinDiff] = max(diffFxFxmin(1:2));
            Fx(1:2) = Fx(1:2) + minDiffFxFxmin;
        else
            [minDiffFxFxmin,posMinDiff] = max(diffFxFxmin(3:4));
            posMinDiff= posMinDiff+2;
            Fx(3:4) = Fx(3:4) + minDiffFxFxmin;
        end
        
        diffFxFxmin = Fxmin-Fx;
        
        moment = sum([-car.tw/2; car.tw/2; -car.tw/2; car.tw/2].*Fx);

        
        MzCorr = moment;
        DiffsumFxFdes = Fdes-sum(Fx);
        if pos1 >2
            %         diffFLFR = Fx(posMinDiff)-Fx(3-posMinDiff)
            %         diffRLRR = Fx(pos1)-Fx(7-pos1)
            %         Fx(3-posMinDiff)=Fx(3-posMinDiff)+diffFLFR*(Fsens/FsensMax);
            %         Fx(7-pos1)=Fx(7-pos1)+diffRLRR*(Fsens/FsensMax);
            
            if diffFxFxmin(7-pos1) == 0
                diffFxFxmin(7-pos1) = -0.1;
            end
            fracDiff=(diffFxFxmin(3-posMinDiff)/diffFxFxmin(7-pos1));
            distrRLRR = -MzCorr/(fracDiff*A2(3-posMinDiff)+A2(7-pos1));
            distrFLFR = (-MzCorr - distrRLRR*A2(7-pos1))/A2(3-posMinDiff);
            
            if (distrRLRR + distrFLFR) < 0
                if distrFLFR + distrRLRR < DiffsumFxFdes
                    distrFLFR = DiffsumFxFdes/(1+fracDiff);
                    distrRLRR = distrFLFR*fracDiff;
                end
                Fx(3-posMinDiff)=Fx(3-posMinDiff)+distrFLFR*(Fsens/FsensMax);
                Fx(7-pos1)=Fx(7-pos1)+distrRLRR*(Fsens/FsensMax);
            end
            
            
        else
          
            if diffFxFxmin(7-posMinDiff) == 0
                diffFxFxmin(7-posMinDiff) = -0.1;
            end
            fracDiff=(diffFxFxmin(3-pos1)/diffFxFxmin(7-posMinDiff));
            distrRLRR = -MzCorr/(fracDiff*A2(3-pos1)+A2(7-posMinDiff));
            distrFLFR = (-MzCorr - distrRLRR*A2(7-posMinDiff))/A2(3-pos1);
            
            if (distrRLRR + distrFLFR) < 0
                if distrFLFR + distrRLRR < DiffsumFxFdes
                    distrFLFR = DiffsumFxFdes/(1+fracDiff);
                    distrRLRR = distrFLFR*fracDiff;
                end
                Fx(7-posMinDiff)=Fx(7-posMinDiff)+distrFLFR*(Fsens/FsensMax);
                Fx(3-pos1)=Fx(3-pos1)+distrRLRR*(Fsens/FsensMax);
            end
        end                 
    end
    
end

Fx = Fx/car.gearRatio;


% tolerance = 1;
% 
% maxvaluecheck =  Fxmin - tolerance <Fx & Fx<Fxmax + tolerance;
% A = find(maxvaluecheck==0);
% FxminA=0;
% 
% if isempty(A) == 0
%     A1=A(1);
%     if Fdes > 0
%         if Fx(A1) > Fxmax(A1)
%             diff=Fx(A1)-Fxmax(A1);
%             Fx(A1)=Fxmax(A1);
%             if A1 == 3 || A1 == 4
%                 if (Fxmax(A1-2) - Fx(A1-2))>=diff;
%                     Fx(A1-2)=Fx(A1-2)+diff;
%                 else
%                     diff2=Fxmax(A1-2)-Fx(A1-2);
%                     Fx(A1-2)=Fxmax(A1-2);
%                     Fx(7-A1)=Fx(7-A1)-(diff-diff2);
%                     %Fx(7-A1)=Fx(7-A1)-(diff-diff2)/2;
%                     %Fx(5-A1)=Fx(5-A1)-(diff-diff2)/2;
%                 end
%             else
%                 if (Fxmax(A1+2) - Fx(A1+2))>=diff
%                     Fx(A1+2)=Fx(A1+2)+diff;
%                 else
%                     diff2=Fxmax(A1+2)-Fx(A1+2);
%                     Fx(A1+2)=Fxmax(A1+2);
%                     Fx(3-A1)=Fx(3-A1)-(diff-diff2);
%                     %Fx(3-A1)=Fx(3-A1)-(diff-diff2)/2;
%                     %Fx(5-A1)=Fx(5-A1)-(diff-diff2)/2;
%                 end
%             end
%         else %Fx(A1) < Fxmin(A1)
%             diff=Fxmin(A1)-Fx(A1); %positive value
%             Fx(A1)=FxminA(A1);
%             if A1 == 1 || A1 == 2
%                 if Fx(A1+2) < 0
%                     diff2=Fx(A1+2)-Fxmin(A1+2); %positive value
%                     if diff2>diff
%                         Fx(A1+2)=Fx(A1+2)-diff;
%                     else
%                         Fx(A1+2)=Fxmin(A1+2);
%                     end
%                 else %Fx(A1+2) > 0
%                     Fx(A1+2) = Fx(A1+2)-diff;
%                 end
%             else
%                 if Fx(A1-2) < 0
%                     diff2=Fx(A1-2)-Fxmin(A1-2); %positive value
%                     if diff2>diff
%                         Fx(A1-2)=Fx(A1-2)-diff;
%                     else
%                         Fx(A1-2)=Fxmin(A1-2);
%                     end
%                 else %Fx(A1-2) > 0
%                     Fx(A1-2) = Fx(A1-2)-diff;
%                 end
%             end
%         end
%         
%         
%     else %if Fdes <= 0
%         if Fx(A1) < Fxmin(A1)
%             diff=Fxmin(A1)-Fx(A1); %postive value
%             Fx(A1)=Fxmin(A1);
%             if A1 == 3 || A1 == 4
%                 if (Fx(A1-2) - Fxmin(A1-2))>=diff
%                     Fx(A1-2)=Fx(A1-2)-diff;
%                 else
%                     diff2=Fx(A1-2)-Fxmin(A1-2);
%                     Fx(A1-2)=Fxmin(A1-2);
%                     Fx(7-A1)=Fx(7-A1)+(diff-diff2);
%                     %Fx(7-A1)=Fx(7-A1)+(diff-diff2)/2;
%                     %Fx(5-A1)=Fx(5-A1)+(diff-diff2)/2;
%                 end
%             else %A1 == 1 | A1 == 2
%                 if (Fx(A1+2)-Fxmin(A1+2))>=diff
%                     Fx(A1+2)=Fx(A1+2)-diff;
%                 else
%                     diff2=Fx(A1+2)-Fxmin(A1+2);
%                     Fx(A1+2)=Fxmin(A1+2);
%                     Fx(3-A1)=Fx(3-A1)+(diff-diff2);
%                     %Fx(3-A1)=Fx(3-A1)+(diff-diff2)/2;
%                     %Fx(5-A1)=Fx(5-A1)+(diff-diff2)/2;
%                 end
%             end
%         else %Fx(A1) > Fxmax(A1)
%             diff=Fx(A1)-Fxmax(A1); %positive value
%             Fx(A1)=Fxmax(A1);
%             if A1 == 1 || A1 == 2
%                 if Fx(A1+2) > 0
%                     diff2=Fxmax(A1+2)-Fx(A1+2); %positive value
%                     if diff2>diff
%                         Fx(A1+2)=Fx(A1+2)+diff;
%                     else
%                         Fx(A1+2)=Fxmax(A1+2);
%                     end
%                 else %Fx(A1+2) < 0
%                     Fx(A1+2) = Fx(A1+2)+diff;
%                 end
%             else %A1 == 3 | A1 == 4
%                 if Fx(A1-2) > 0
%                     diff2=Fxmax(A1-2)-Fx(A1-2); %positive value
%                     if diff2>diff
%                         Fx(A1-2)=Fx(A1-2)-diff;
%                     else
%                         Fx(A1-2)=Fxmax(A1-2);
%                     end
%                 else %Fx(A1-2) > 0
%                     Fx(A1-2) = Fx(A1-2)+diff;
%                 end
%             end
%         end
%     end 
% end



end