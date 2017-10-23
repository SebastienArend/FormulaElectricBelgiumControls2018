function [mu] = frictionfrank(K_x,K_y,F_x,F_y,F_z,alpha,tau)
%This function calculates an estimate for the maximum friction coefficient
%by comparing the estimated forces with the forces calculated using the
%Dugoff tire model for a certain side slip angle and slip ratio. The forces
%are calculated for a range of mu values, and the mu for which the forces
%deviate the least (rms) is chosen as the instantaneous mu value.
mu = [0.05;0.05;0.05;0.05];
rms1 = [0;0;0;0];
rms2 = [0;0;0;0];
for i=1:1:4
    [F_xd,F_yd] = tyre_model_Dugoff(F_z(i),alpha(i),tau(i),mu(i),K_x,K_y, sign(tau(i)));
    rms1(i) = sqrt((F_x(i)-F_xd)^2+(F_y(i)-F_yd)^2);
end
for i=1:1:4
    for mu1=0.1:0.05:1
        [F_xd1,F_yd1] = tyre_model_Dugoff(F_z(i),alpha(i),tau(i),mu(i),K_x,K_y, sign(tau(i)));
        rms2(i) = sqrt((F_x(i)-F_xd1)^2+(F_y(i)-F_yd1)^2);
        if rms2(i) < rms1(i)
            mu(i) = mu1;
            rms1(i) = rms2(i);
        end
    end
end
end

