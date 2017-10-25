function [p0] = tire_est(States_matrix_front,States_matrix_rear)
%Estimation of tire-force model for use in individual tire force
%calculations
%States_matrix = [alpha,F_normal,F_lateral]
k = 0;
p0.front = [10, 1.9, 1, 0.97];
p0.rear = [10, 1.9, 1, 0.97];

f_tire.front(k) = States_matrix_front(2)*p0.front(3)*sin(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    atan(p0.front(1)*States_matrix_front(1))));
f_tire.rear(k) = States_matrix_rear(2)*p0.rear(3)*sin(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    atan(p0.rear(1)*States_matrix_rear(1))));

tol = E-3;

%% Front wheel tyre-model estimation %%
J_p(1) = (States_matrix_front(2)*p0.front(3))*cos(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1))))*p0.front(2)/(1+(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1)))^2)*((1-p0.front(4))*States_matrix_front(1)+p0.front(4)/(1 + ...
    (p0.front(1)*States_matrix_front(1))^2)*States_matrix_front(1));
J_p(2) = (States_matrix_front(2)*p0.front(3))*cos(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1))))*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1)));
J_p(3) = States_matrix_front(2)*sin(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1))));
J_p(4) = (States_matrix_front(2)*p0.front(3))*cos(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1))))*p0.front(2)/(1+(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1)))^2)*(-p0.front(1)*States_matrix_front(1)+atan(p0.front(1)*States_matrix_front(1)));
del = -(transpose(J_p)*J_p)^(-1)*transpose(J_p)*(f_tire.front(k)-States_matrix_front(3));
a = 0.5;
k = k+1;
p0.front = p0.front + del;
f_tire.front(k) = States_matrix_front(2)*p0.front(3)*sin(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    atan(p0.front(1)*States_matrix_front(1))));

while abs(f_tire_front(k-1)-States_matrix_front(3))-abs(f_tire_front(k)-States_matrix_front(3)) >= tol
    J_p(1) = (States_matrix_front(2)*p0.front(3))*cos(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1))))*p0.front(2)/(1+(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1)))^2)*((1-p0.front(4))*States_matrix_front(1)+p0.front(4)/(1 + ...
    (p0.front(1)*States_matrix_front(1))^2)*States_matrix_front(1));
J_p(2) = (States_matrix_front(2)*p0.front(3))*cos(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1))))*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1)));
J_p(3) = States_matrix_front(2)*sin(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1))));
J_p(4) = (States_matrix_front(2)*p0.front(3))*cos(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1))))*p0.front(2)/(1+(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    p0.front(4)*atan(p0.front(1)*States_matrix_front(1)))^2)*(-p0.front(1)*States_matrix_front(1)+atan(p0.front(1)*States_matrix_front(1)));    del = -(transpose(J_p)*J_p)^(-1)*transpose(J_p)*(f_tire.front(k)-States_matrix_front(3));
    k = k+1;
    p0.front = p0.front + del;
    f_tire.front(k) = States_matrix_front(2)*p0.front(3)*sin(p0(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
    atan(p0.front(1)*States_matrix_front(1))));
    while abs(f_tire_front(k-1)-States_matrix_front(3)) <= abs(f_tire_front(k)-States_matrix_front(3))
        del = a*del;
        p0.front = p0.front + del;
        f_tire.front(k) = States_matrix_front(2)*p0.front(3)*sin(p0.front(2)*atan(p0.front(1)*(1-p0.front(4))*States_matrix_front(1) + ...
        atan(p0.front(1)*States_matrix_front(1))));
    end
end

k = 0;
%% Rear wheel tyre-model estimation %%
J_p(1) = (States_matrix_rear(2)*p0.rear(3))*cos(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1))))*p0.rear(2)/(1+(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1)))^2)*((1-p0.rear(4))*States_matrix_rear(1)+p0.rear(4)/(1 + ...
    (p0.rear(1)*States_matrix_rear(1))^2)*States_matrix_rear(1));
J_p(2) = (States_matrix_rear(2)*p0.rear(3))*cos(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1))))*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1)));
J_p(3) = States_matrix_rear(2)*sin(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1))));
J_p(4) = (States_matrix_rear(2)*p0.rear(3))*cos(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1))))*p0.rear(2)/(1+(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1)))^2)*(-p0.rear(1)*States_matrix_rear(1)+atan(p0.rear(1)*States_matrix_rear(1)));
del = -(transpose(J_p)*J_p)^(-1)*transpose(J_p)*(f_tire.rear(k)-States_matrix_rear(3));
a = 0.5;
k = k+1;
p0.rear = p0.rear + del;
f_tire.rear(k) = States_matrix_rear(2)*p0.rear(3)*sin(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    atan(p0.rear(1)*States_matrix_rear(1))));

while abs(f_tire_rear(k-1)-States_matrix_rear(3))-abs(f_tire_rear(k)-States_matrix_rear(3)) >= tol
    J_p(1) = (States_matrix_rear(2)*p0.rear(3))*cos(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1))))*p0.rear(2)/(1+(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1)))^2)*((1-p0.rear(4))*States_matrix_rear(1)+p0.rear(4)/(1 + ...
    (p0.rear(1)*States_matrix_rear(1))^2)*States_matrix_rear(1));
J_p(2) = (States_matrix_rear(2)*p0.rear(3))*cos(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1))))*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1)));
J_p(3) = States_matrix_rear(2)*sin(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1))));
J_p(4) = (States_matrix_rear(2)*p0.rear(3))*cos(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1))))*p0.rear(2)/(1+(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    p0.rear(4)*atan(p0.rear(1)*States_matrix_rear(1)))^2)*(-p0.rear(1)*States_matrix_rear(1)+atan(p0.rear(1)*States_matrix_rear(1)));
    del = -(transpose(J_p)*J_p)^(-1)*transpose(J_p)*(f_tire.rear(k)-States_matrix_rear(3));
    k = k+1;
    p0.rear = p0.rear + del;
    f_tire.rear(k) = States_matrix_rear(2)*p0.rear(3)*sin(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
    atan(p0.rear(1)*States_matrix_rear(1))));
    while abs(f_tire_rear(k-1)-States_matrix_rear(3)) <= abs(f_tire_rear(k)-States_matrix_rear(3))
        del = a*del;
        p0.rear = p0.rear + del;
        f_tire.rear(k) = States_matrix_rear(2)*p0.rear(3)*sin(p0.rear(2)*atan(p0.rear(1)*(1-p0.rear(4))*States_matrix_rear(1) + ...
        atan(p0.rear(1)*States_matrix_rear(1))));
    end
end

end

