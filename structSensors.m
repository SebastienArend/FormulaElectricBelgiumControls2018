clear elems;


for i = 1:15    
elems(i) = Simulink.BusElement;
elems(i).Dimensions = 1;
elems(i).DimensionsMode = 'Fixed';
elems(i).DataType = 'double';
elems(i).SampleTime = -1;
elems(i).Complexity = 'real';
end

elems(1).Name = 'ax';
elems(2).Name = 'ay';
elems(3).Name = 'wheelspeed';
elems(3).Dimensions = 4;
elems(4).Name = 'yawRate';
elems(5).Name = 'steerAngle';
elems(6).Name = 'wheelAngles';
elems(6).Dimensions = 4;
elems(7).Name = 'throttle';
elems(8).Name = 'brake';
elems(9).Name = 'torque';
elems(9).Dimensions = 4;
elems(10).Name = 'ax_error';
elems(11).Name = 'ay_error';
elems(12).Name = 'yawRate_error';
elems(13).Name = 'knob1';
elems(14).Name = 'knob2';
elems(15).Name = 'P_elec';

sensorBus = Simulink.Bus;
sensorBus.Elements = elems;


