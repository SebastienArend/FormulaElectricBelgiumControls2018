clear elems;


for i = 1:1   
elems(i) = Simulink.BusElement;
elems(i).Dimensions = 1;
elems(i).DimensionsMode = 'Fixed';
elems(i).DataType = 'double';
elems(i).SampleTime = -1;
elems(i).Complexity = 'real';
end

elems(1).Name = 'TD_percentage';


variableBus = Simulink.Bus;
variableBus.Elements = elems;


