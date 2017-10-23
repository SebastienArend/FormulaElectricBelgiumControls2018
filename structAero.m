clear elems;


for i = 1:4   
elems(i) = Simulink.BusElement;
elems(i).Dimensions = 1;
elems(i).DimensionsMode = 'Fixed';
elems(i).DataType = 'double';
elems(i).SampleTime = -1;
elems(i).Complexity = 'real';
end

elems(1).Name = 'FD';
elems(2).Name = 'FL';
elems(3).Name = 'lever_FD';
elems(3).Dimensions = 2;
elems(4).Name = 'lever_FL';
elems(4).Dimensions = 2;

aeroBus = Simulink.Bus;
aeroBus.Elements = elems;