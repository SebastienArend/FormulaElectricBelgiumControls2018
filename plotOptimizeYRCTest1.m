close all

lengthx = [1:1:length(meanError)];


figure
subplot(211)
plot(meanError)
title('meanError')
ylabel('meanError')
xlabel('different gain combinations')
subplot(212)
plot(dist)
title('dist')
ylabel('dist')
xlabel('different gain combinations')

figure
plot(meanError)
title('meanError')
ylabel('meanError')
xlabel('different gain combinations')

figure
subplot(211)
plot(lengthx, 1+ (countLog(:,1)'-1).*5,lengthx, (countLog(:,2)'-1).*5)
title('Gains Kp & Ki')
legend('Kp','Ki')
subplot(212)
plot(lengthx, (countLog(:,3)'-1),'m',lengthx, (countLog(:,4)'-1),'g')
title('Gains Ks & Kr')
legend('Ks','Kr')
axis([0 45 0.5 2.2])


distWork = dist;
errorWork = meanError;
countLogWorkDist = [];
countLogWorkError = [];
maxDistList= [];
minErrorList =[];
list = [];

for i = 1:10
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
plot(list,1+(countLogWorkDist(:,1)-1).*5,list,(countLogWorkDist(:,2)-1).*5)
title('dist Kp, Ki')
legend('Kp','Ki')
axis([1 10 0 22])

subplot(324)
plot(list,1+(countLogWorkError(:,1)-1).*5,list,(countLogWorkError(:,2)-1).*5)
title('error Kp, Ki')
legend('Kp','Ki')
%axis([1 10 0 11])

subplot(325)
plot(list,countLogWorkDist(:,3)-1,list,countLogWorkDist(:,4)-1)
title('dist Ks, Kr')
legend('Ks','Kr')
axis([1 10 0 2.5])

subplot(326)
plot(list,countLogWorkError(:,3)-1,list,countLogWorkError(:,4)-1)
title('error Ks, Kr')
legend('Ks','Kr')
axis([1 10 0 2.5])
%-----
figure

subplot(311)
plot(minErrorList(1,:))
title('minMeanError')



subplot(312)
plot(list,1+(countLogWorkError(:,1)-1).*5,list,(countLogWorkError(:,2)-1).*5)
title('error Kp, Ki')
legend('Kp','Ki')
%axis([1 10 0 11])



subplot(313)
plot(list,countLogWorkError(:,3)-1,'m',list,countLogWorkError(:,4)-1,'g')
title('error Ks, Kr')
legend('Ks','Kr')
axis([1 10 0 2.5])