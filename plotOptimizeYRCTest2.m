close all

lengthx = [1:1:length(meanError)];


figure
subplot(211)
plot(meanError)
title('meanError')
ylabel('meanError')
xlabel('different gain combinations')
axis([ 0 512 0.0195 0.023 ])
subplot(212)
plot(dist)
title('dist')
ylabel('dist')
xlabel('different gain combinations')
axis([ 0 512 343.4 343.9 ])

figure
plot(meanError)
title('meanError')
ylabel('meanError')
xlabel('different gain combinations')
axis([ 0 512 0.0195 0.023 ])

figure
subplot(211)
plot(lengthx, 40 + (countLog(:,1)'-1).*3,lengthx, (countLog(:,2)'-1).*5)
title('Gains Kp & Ki')
legend('Kp','Ki')
axis([0 512 0 65])
subplot(212)
plot(lengthx, (countLog(:,3)'-1).*0.25,'m',lengthx, (countLog(:,4)'-1),'g')
title('Gains Ks & Kr')
legend('Ks','Kr')
axis([0 65 0 4])


distWork = dist;
errorWork = meanError;
countLogWorkDist = [];
countLogWorkError = [];
maxDistList= [];
minErrorList =[];
list = [];

for i = 1:100
    [maxDist,posDist] = max(distWork);
    distWork(posDist) = [];
    maxDistList(1,i)= maxDist;
    maxDistList(2,i) = posDist;
    countLogWorkDist(i,:) = countLog(posDist,:);
    [minError,posError] = min(errorWork);
    errorWork(posError) = [];
    minErrorList(1,i)= minError;
    minErrorList(2,i) = posError;
    countLogWorkError(i,:) = countLog(posError,:);
    list(i,1)=i;
    
     
end


figure
subplot(321)
plot(maxDistList(1,:))
title('maxDist')

subplot(322)
plot(minErrorList(1,:))
title('minMeanError')

subplot(323)
plot(list,40+(countLogWorkDist(:,1)-1).*3)
title('dist Kp')
legend('Kp','Ki')
%axis([1 10 0 22])

subplot(324)
plot(list,40+(countLogWorkError(:,1)-1).*3)
title('error Kp')
legend('Kp','Ki')
%axis([1 10 0 11])

subplot(325)
plot(list, (countLogWorkDist(:,2)-1).*0.25, list,0.5+(countLogWorkDist(:,3)-1).*0.25,list,(countLogWorkDist(:,4)-1).*0.25)
title('dist Ki, Ks, Kr')
legend('Ki','Ks','Kr')
axis([1 10 0 1.5])

subplot(326)
plot(list, (countLogWorkError(:,2)-1).*0.25, list,0.5+(countLogWorkError(:,3)-1).*0.25,list,(countLogWorkError(:,4)-1).*0.25)
title('error Ki, Ks, Kr')
legend('Ki','Ks','Kr')
axis([1 10 0 1.5])
%-----
figure

subplot(311)
plot(minErrorList(1,:))
title('minMeanError')



subplot(312)
plot(list,40+(countLogWorkError(:,1)-1).*3)
title('error Kp')
legend('Kp')
axis([1 100 60 63])



subplot(313)
plot(list,(countLogWorkError(:,2)-1).*0.25,'r',list,0.5+(countLogWorkError(:,3)-1).*0.25,'m',list,(countLogWorkError(:,4)-1).*0.25,'g')
title('error Ki, Ks, Kr')
legend('Ki','Ks','Kr')
axis([1 100 0 1.5])