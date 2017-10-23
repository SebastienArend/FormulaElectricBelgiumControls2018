function [ Fx ] = Distributor(settings, estimPar, car, variables, Mz, Fdes, Fxmax, Fxmin)
%DISTRIBUTOR Solves the KKT conditions
%   Based on sensitivity paramterers, KKT conditions
%   are worked out to find an optimal balance between
%   the desired Fx and the desired Mz
%   Mz = desired yaw moment [1x1]
%   Fdes = desired traction force [1x1]
%   Fxmax = available grip per wheel [4x1]
%   Fxmin = available neg grip per wheel [4x1]

%   TODO: variables or settings?
Fsens = settings.Fsens;
Msens = settings.Msens;
Fxsens = settings.Fxsens;
Mdes = Mz;

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
A2 = [-car.lf car.lf -car.lr car.lr];
A3 = [1/Fxmax(1) 0 0 0;
    0 1/Fxmax(2) 0 0;
    0 0 1/Fxmax(3) 0;
    0 0 0 1/Fxmax(4)];


Fx = inv(A1'*A1*Fsens+A2'*A2*Msens+A3*Fxsens)*(A1'*Fdes*Fsens+A2'*Mdes*Msens);

sumFx=sum(Fx);
moment = sum([-car.lf ;car.lf ;-car.lr ;car.lr].*Fx);


% Iteratie 1
%iteration=100;
tolerance = 0.5;
condition = 0==1; %nodig om problemen tijdens compilen te voorkomen (logic ~= double type)
counter = 0;
pos1=0;
MdesIt=0;
FdesIt=0; 
iteration = 5;
for k= 1:iteration
%while condition == 0
    
    Fxcheckmax1 = 0;
    Fxcheckmin1 = 0;
    for i = 1:4
        if Fx(i)>Fxmax(i)
            Fxcheckmax1 =1;
        elseif Fx(i)<Fxmin(i)
            Fxcheckmin1 = 1;
        end
    end
    
    if  (Fxcheckmax1==1|Fxcheckmin1==1) %Check if one value of Former Fx surpasses the maximum value
        
        if Fxcheckmax1 ==1
            [value1,pos1]=max(Fx);
            Fxdiff=Fx(pos1)-Fxmax(pos1);
            Fx(pos1)=Fxmax(pos1);
            Mcorr=A2(pos1);
            FdesIt = (Fdes-Fxmax(pos1)-Fxdiff);
            Fdes=FdesIt+Fxmax(pos1);
            MdesIt = Mdes-Mcorr*Fxmax(pos1);
        elseif Fxcheckmin1 ==1
            [value1,pos1]=min(Fx);
            Fxdiff=Fx(pos1)-Fxmin(pos1); %negative value
            Fx(pos1)=Fxmin(pos1);
            Mcorr=A2(pos1);
            FdesIt = (Fdes-Fxmin(pos1)-Fxdiff);
            Fdes=FdesIt+Fxmax(pos1);
            MdesIt = Mdes+Mcorr*Fxmax(pos1);
            
        end
        
        A1_1 = [1 1 1];
        coder.varsize('A2_1');
        A2_1=A2;
        A2_1(pos1)= [];
        coder.varsize('A3_1');
        A3_1=A3;
        A3_1(pos1,:)=[];
        A3_1(:,pos1)=[];
        
        
        
        
        
        if pos1 ==1
            Fx(2:4) = inv(A1_1'*A1_1*Fsens+A2_1'*A2_1*Msens+A3_1*Fxsens)*(A1_1'*FdesIt*Fsens+A2_1'*MdesIt*Msens);
        elseif pos1 ==2
            Fxinterm = inv(A1_1'*A1_1*Fsens+A2_1'*A2_1*Msens+A3_1*Fxsens)*(A1_1'*FdesIt*Fsens+A2_1'*MdesIt*Msens);
            Fx(1)=Fxinterm(1);
            Fx(3:4)=Fxinterm(2:3);
        elseif pos1 ==3
            Fxinterm = inv(A1_1'*A1_1*Fsens+A2_1'*A2_1*Msens+A3_1*Fxsens)*(A1_1'*FdesIt*Fsens+A2_1'*MdesIt*Msens);
            Fx(4)=Fxinterm(3);
            Fx(1:2)=Fxinterm(1:2);
        else
            Fx(1:3)= inv(A1_1'*A1_1*Fsens+A2_1'*A2_1*Msens+A3_1*Fxsens)*(A1_1'*FdesIt*Fsens+A2_1'*MdesIt*Msens);
        end
        Fx;
        
        sumFx=sum(Fx);
        
        moment = sum([-car.lf ;car.lf ;-car.lr ;car.lr].*Fx);
    end
    
%     if Fxcheckmax1 ==1
%         condition = Fx(1) < (Fxmax(1)+tolerance) && Fx(2) < (Fxmax(2)+tolerance) && Fx(3) < (Fxmax(3)+tolerance) && Fx(4) < (Fxmax(4)+tolerance);
%     elseif Fxcheckmin1 ==1
%         condition = Fx(1) > (Fxmin(1)-tolerance) && Fx(2) > (Fxmin(2)-tolerance) && Fx(3) > (Fxmin(3)-tolerance) && Fx(4) > (Fxmin(4)-tolerance);
%     end
    counter = counter +1;
    
end


    

end


% A1 = [1 1 1 1];
% A2 = [-car.lf car.lf -car.lr car.lr];
% A3 = [1/Fxmax(1) 0 0 0;
%     0 1/Fxmax(2) 0 0;
%     0 0 1/Fxmax(3) 0;
%     0 0 0 1/Fxmax(4)];
% 
% Fx= inv(A1'*A1*Fsens+A2'*A2*Msens+A3*Fxsens)*(A1'*Fdes*Fsens+A2'*Mdes*Msens);
% for i=1:4
%     if Fx(i)<0
%         Fxvalue=Fx(i);
%         Fx(i)=Fx(i)/3.95; 
%         Fxdiff = Fxvalue-Fx(i);
%         if i < 3
%             Fx(i+2)=Fx(i+2)+Fxdiff/3;
%         else
%             Fx(i-2)=Fx(i-2)+Fxdiff/3;
%         end
%     else
%         Fx(i)=Fx(i)*1.38;
%     
%     end

% equalDistribution = (Fdes/sum(Fxmax))*Fxmax;
% initialGuess = equalDistribution + [0.25;-0.25;0.25;-0.25]/t*Mdes;
% Fx = initialGuess;

% y = 0;
% coder.extrinsic('myFunc')
% y = myFunc();
% end
% Where myFunc.m is:
% 
% function a = myFunc()
% a =fminbnd(@(x) x.^2+100-650, 0, 100);
% end
% 
% coder.extrinsic('Fmincon');
% Fx = Fmincon(initialGuess,H,c,c0,A,b);
%moment = -sum(t * [-1;1;-1;1].*Fx);
%ForceX = sum(Fx);
% switch distributorMode
%     case 1
% 
%     otherwise
%         Fx = initialGuess;
% end

% % TODO: moment equations accounting FyEst
% H = 2*[Fsens+t^2*Msens+Fxsens/Fxmax(1)  Fsens-t^2*Msens                 Fsens+t^2*Msens                 Fsens-t^2*Msens                 ;
%        Fsens-t^2*Msens                  Fsens+t^2*Msens+Fxsens/Fxmax(2) Fsens-t^2*Msens                 Fsens+t^2*Msens                 ;
%        Fsens+t^2*Msens                  Fsens-t^2*Msens                 Fsens+t^2*Msens+Fxsens/Fxmax(3) Fsens-t^2*Msens                 ;
%        Fsens-t^2*Msens                  Fsens+t^2*Msens                 Fsens-t^2*Msens                 Fsens+t^2*Msens+Fxsens/Fxmax(4) ];
% 
% c = [-2*Fdes*Fsens+2*t*Mdes*Msens;
%      -2*Fdes*Fsens-2*t*Mdes*Msens;
%      -2*Fdes*Fsens+2*t*Mdes*Msens;
%      -2*Fdes*Fsens-2*t*Mdes*Msens];
%  
% c0 = [Fdes^2*Fsens + Mdes^2*Msens];
% 
% A = [1 0   0   0;
%     0   1  0   0;
%     0   0   1  0;
%     0   0   0   1;
%     -1   0   0   0;
%     0   -1   0   0;
%     0   0   -1   0;
%     0   0   0   -1];
% 
% b = [Fxmax(1);
%     Fxmax(2);
%     Fxmax(3);
%     Fxmax(4);
%     -Fxmin(1);
%     -Fxmin(2);
%     -Fxmin(3);
%     -Fxmin(4)];

%distributorMode = settings.distributorMode;


