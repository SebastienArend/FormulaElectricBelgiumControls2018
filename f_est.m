function [ x_next ] = f_est( x, u, car )
% Discrete differential equation of system: x(k+1) = f(x(k), u(k))
%   x:      state at index k
%   u:      input at index k
%   Ts:     sample time
%   x_next: state at index k+1

x_next = zeros(5,1);

x_next(1) = x(1) + ((-2*(x(4)+x(5))/(car.mass*x(3)))*(x(1)) -...
    (2*((x(4)*car.lf-x(5)*car.lr)/(car.mass*x(3)))+ x(1))*x(2) + ...
    ((2*x(4))/(car.mass))*u(1))*car.dt; 

x_next(2) = x(2) + ((-2*(x(4)*car.lf-x(5)*car.lr)/(car.yawInertia*x(3)))*(x(1)) -...
    (2*((x(4)*car.lf^2+x(5)*car.lr^2)/(car.yawInertia*x(3))))*x(2) + ...
    ((2*x(4)*car.lf)/(car.yawInertia))*u(1))*car.dt; 

x_next(3) = x(3) + (u(2)+x(1)*x(2))*car.dt;  

x_next(4) = 0; 

x_next(5) = 0; 

end