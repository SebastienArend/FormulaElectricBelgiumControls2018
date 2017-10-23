clear elems;

for i = 1:11   
elems(i) = Simulink.BusElement;
elems(i).Dimensions = 1;
elems(i).DimensionsMode = 'Fixed';
elems(i).DataType = 'double';
elems(i).SampleTime = -1;
elems(i).Complexity = 'real';
end

elems(1).Name = 'velocityEstimation';
elems(2).Name = 'torqueMode';
elems(3).Name = 'YRC';
elems(4).Name = 'YRCMode';
elems(5).Name = 'distributorMode';
elems(6).Name = 'Fsens';
elems(7).Name = 'Fxsens';
elems(8).Name = 'TC';
elems(9).Name = 'unlimitedFx';
elems(10).Name = 'TV_bypass';
elems(11).Name = 'effEstimation';

settingBus = Simulink.Bus;
settingBus.Elements = elems;