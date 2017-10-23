clear elems;

for i = [1,5,8]
elems(i) = Simulink.BusElement;
elems(i).Dimensions = 1;
elems(i).DimensionsMode = 'Fixed';
elems(i).DataType = 'double';
elems(i).SampleTime = -1;
elems(i).Complexity = 'real';
end

for i = [2,3,4,6,7]
elems(i) = Simulink.BusElement;
elems(i).Dimensions = 4;
elems(i).DimensionsMode = 'Fixed';
elems(i).DataType = 'double';
elems(i).SampleTime = -1;
elems(i).Complexity = 'real';
end

elems(1).Name = 'v';
elems(2).Name = 'Fzi';
elems(3).Name = 'Fxi';
elems(4).Name = 'Fyi';
elems(5).Name = 'rref';
elems(6).Name = 'mu';
elems(7).Name = 'slip';
elems(8).Name = 'eff';


estimParBus = Simulink.Bus;
estimParBus.Elements = elems;